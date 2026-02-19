import os
import io
import uuid
import base64
from flask import Flask, render_template, request, redirect, url_for, flash, jsonify, send_file
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager, UserMixin, login_user, login_required, logout_user, current_user
from werkzeug.security import generate_password_hash, check_password_hash
from datetime import datetime, timedelta, time
import pytz
from openpyxl import Workbook
from openpyxl.styles import PatternFill, Alignment, Border, Side, Font
import config
from urllib.parse import quote_plus

app = Flask(__name__)
app.config['SECRET_KEY'] = config.SECRET_KEY

# --- CONFIGURACIÓN DE CARPETAS ---
UPLOAD_FOLDER = 'static/uploads/evidencias'
os.makedirs(UPLOAD_FOLDER, exist_ok=True)

# --- CONFIGURACIÓN DE BASE DE DATOS (MYSQL) ---
encoded_password = quote_plus('avril18wen04@@A1')
app.config['SQLALCHEMY_DATABASE_URI'] = f'mysql+pymysql://user1_istae:{encoded_password}@localhost/user1_biom'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.config['SQLALCHEMY_ENGINE_OPTIONS'] = {'pool_pre_ping': True, 'pool_recycle': 280}

db = SQLAlchemy(app)
login_manager = LoginManager(app)
login_manager.login_view = 'login'

# --- MODELOS DE DATOS ---

class User(UserMixin, db.Model):
    __tablename__ = 'usuarios'
    id = db.Column(db.Integer, primary_key=True)
    biometric_id = db.Column(db.String(20), unique=True)
    nombre = db.Column(db.String(100))
    username = db.Column(db.String(50), unique=True)
    password = db.Column(db.String(255))
    rol = db.Column(db.String(20), default='docente')
    acceso_puerta = db.Column(db.Integer, default=0)

class Evento(db.Model):
    __tablename__ = 'eventos'
    id = db.Column(db.Integer, primary_key=True)
    nombre = db.Column(db.String(100), nullable=False)
    fecha_creacion = db.Column(db.DateTime, default=datetime.now)
    activo = db.Column(db.Boolean, default=True)

class Log(db.Model):
    __tablename__ = 'logs'
    id = db.Column(db.Integer, primary_key=True)
    fecha = db.Column(db.DateTime, nullable=False)
    usuario_id = db.Column(db.String(20))
    tipo_evento = db.Column(db.String(100))
    origen = db.Column(db.String(50))
    # Evidencias para modo Eventos
    latitud = db.Column(db.String(30), nullable=True)
    longitud = db.Column(db.String(30), nullable=True)
    foto_path = db.Column(db.String(200), nullable=True)
    evento_id = db.Column(db.Integer, db.ForeignKey('eventos.id'), nullable=True)

class Comando(db.Model):
    __tablename__ = 'comandos'
    id = db.Column(db.Integer, primary_key=True)
    instruccion = db.Column(db.String(20))
    estado = db.Column(db.String(20), default='PENDIENTE')

# --- INICIALIZACIÓN ---

@login_manager.user_loader
def load_user(user_id):
    return db.session.get(User, int(user_id))

def init_db():
    with app.app_context():
        db.create_all()
        if not User.query.filter_by(username='admin').first():
            hashed_pw = generate_password_hash('istae123A*', method='pbkdf2:sha256')
            admin = User(biometric_id='999', nombre='Admin Principal', username='admin', password=hashed_pw, rol='admin', acceso_puerta=1)
            db.session.add(admin)
            db.session.commit()

init_db()

# --- API PARA HARDWARE (IOT) ---

@app.route('/api/sincronizar')
def api_sincronizar():
    usuarios = User.query.filter_by(acceso_puerta=1).all()
    return ",".join([str(u.biometric_id) for u in usuarios])

@app.route('/api/recibir_log', methods=['POST'])
def api_recibir_log():
    data = request.json
    if not data or data.get('token') != config.TOKEN_NODE:
        return jsonify({"status": "error", "message": "Token inválido"}), 403

    tz_ecu = pytz.timezone('America/Guayaquil')
    fecha_str = data.get('fecha_dispositivo')
    fecha_log = None

    if fecha_str:
        try:
            # Soporte para formato ISAPI: 2026-02-19T12:00:00
            fecha_limpia = fecha_str.replace('T', ' ')
            fecha_log = datetime.strptime(fecha_limpia[:19], "%Y-%m-%d %H:%M:%S")
        except:
            fecha_log = None

    if fecha_log is None:
        fecha_log = datetime.now(tz_ecu)

    nuevo_log = Log(
        fecha=fecha_log,
        usuario_id=data.get('id'),
        tipo_evento="Asistencia + puerta",
        origen="Huella"
    )
    db.session.add(nuevo_log)
    db.session.commit()
    return jsonify({"status": "success"})

@app.route('/api/check_comando')
def api_check_comando():
    cmd = Comando.query.filter_by(estado='PENDIENTE').first()
    if cmd:
        cmd.estado = 'LISTO'
        db.session.commit()
        return "ABRIR"
    return "NADA"

# --- GESTIÓN DE EVENTOS ---

@app.route('/crear_evento', methods=['POST'])
@login_required
def crear_evento():
    if current_user.rol != 'admin': return redirect(url_for('index'))
    nombre = request.form.get('nombre')
    if nombre:
        nuevo = Evento(nombre=nombre)
        db.session.add(nuevo)
        db.session.commit()
        flash(f'Evento "{nombre}" activado.', 'success')
    return redirect(url_for('admin_dashboard'))

@app.route('/toggle_evento/<int:id>')
@login_required
def toggle_evento(id):
    ev = db.session.get(Evento, id)
    if ev:
        ev.activo = not ev.activo
        db.session.commit()
    return redirect(url_for('admin_dashboard'))

# --- ASISTENCIA REMOTA SEGURA (GPS + FOTO) ---

@app.route('/docente/marcar_evento', methods=['POST'])
@login_required
def marcar_evento():
    data = request.json
    tz_ecu = pytz.timezone('America/Guayaquil')
    
    foto_nombre = None
    if data.get('foto'):
        try:
            header, encoded = data.get('foto').split(",", 1)
            data_decoded = base64.b64decode(encoded)
            foto_nombre = f"{current_user.biometric_id}_{uuid.uuid4().hex[:8]}.jpg"
            with open(os.path.join(UPLOAD_FOLDER, foto_nombre), "wb") as f:
                f.write(data_decoded)
        except Exception as e:
            print(f"Error evidencia: {e}")

    nuevo_log = Log(
        fecha=datetime.now(tz_ecu),
        usuario_id=current_user.biometric_id,
        tipo_evento=f"Asistencia Evento: {data.get('evento_nombre')}",
        origen="Web App (GPS+Foto)",
        latitud=data.get('lat'),
        longitud=data.get('lng'),
        foto_path=foto_nombre,
        evento_id=data.get('evento_id')
    )
    
    db.session.add(nuevo_log)
    db.session.commit()
    return jsonify({"status": "success", "message": "Asistencia registrada con éxito."})

# --- VISTAS Y DASHBOARDS ---

@app.route('/')
@login_required
def index():
    return redirect(url_for('admin_dashboard' if current_user.rol == 'admin' else 'docente_dashboard'))

@app.route('/admin/dashboard')
@login_required
def admin_dashboard():
    if current_user.rol != 'admin': return redirect(url_for('docente_dashboard'))
    docentes = User.query.filter_by(rol='docente').all()
    eventos = Evento.query.order_by(Evento.id.desc()).all()
    return render_template('admin.html', docentes=docentes, eventos=eventos)

@app.route('/docente/dashboard')
@login_required
def docente_dashboard():
    logs = Log.query.filter_by(usuario_id=current_user.biometric_id).order_by(Log.id.desc()).limit(10).all()
    evento_activo = Evento.query.filter_by(activo=True).first()
    return render_template('docente.html', logs=logs, evento_activo=evento_activo)

@app.route('/perfil')
@login_required
def perfil():
    return render_template('perfil.html')

# --- ACCIONES ---

@app.route('/admin/abrir')
@login_required
def admin_abrir():
    db.session.add(Comando(instruccion='ABRIR'))
    db.session.add(Log(
        fecha=datetime.now(pytz.timezone('America/Guayaquil')),
        usuario_id=current_user.biometric_id,
        tipo_evento="Apertura Remota",
        origen="Panel Control"
    ))
    db.session.commit()
    flash('Comando de apertura enviado.', 'danger')
    return redirect(url_for('admin_dashboard'))

@app.route('/docente/abrir_puerta')
@login_required
def docente_abrir():
    if current_user.acceso_puerta == 1:
        db.session.add(Comando(instruccion='ABRIR'))
        db.session.add(Log(
            fecha=datetime.now(pytz.timezone('America/Guayaquil')),
            usuario_id=current_user.biometric_id,
            tipo_evento="Apertura Remota",
            origen="Asistencia remota"
        ))
        db.session.commit()
        flash('Puerta abierta.', 'success')
    return redirect(url_for('docente_dashboard'))

@app.route('/docente/marcar_web')
@login_required
def docente_marcar():
    db.session.add(Log(
        fecha=datetime.now(pytz.timezone('America/Guayaquil')),
        usuario_id=current_user.biometric_id,
        tipo_evento="Asistencia Web",
        origen="Plataforma Web"
    ))
    db.session.commit()
    flash('Asistencia registrada correctamente.', 'success')
    return redirect(url_for('docente_dashboard'))

# --- GESTIÓN DOCENTES ---

@app.route('/crear_docente', methods=['POST'])
@login_required
def crear_docente():
    hashed = generate_password_hash(request.form['password'], method='pbkdf2:sha256')
    db.session.add(User(
        biometric_id=request.form['bio_id'],
        nombre=request.form['nombre'],
        username=request.form['username'],
        password=hashed,
        acceso_puerta=1 if request.form.get('acceso_puerta') else 0
    ))
    db.session.commit()
    flash('Docente registrado.', 'success')
    return redirect(url_for('admin_dashboard'))

@app.route('/actualizar_docente', methods=['POST'])
@login_required
def actualizar_docente():
    u = db.session.get(User, request.form.get('user_id'))
    u.nombre = request.form['nombre']
    u.biometric_id = request.form['bio_id']
    u.username = request.form['username']
    u.acceso_puerta = 1 if request.form.get('acceso_puerta') else 0
    if request.form.get('password'):
        u.password = generate_password_hash(request.form['password'], method='pbkdf2:sha256')
    db.session.commit()
    flash('Datos actualizados.', 'success')
    return redirect(url_for('admin_dashboard'))

@app.route('/eliminar_docente/<int:id>')
@login_required
def eliminar_docente(id):
    u = db.session.get(User, id)
    if u and u.username != 'admin':
        db.session.delete(u)
        db.session.commit()
        flash('Registro eliminado.', 'warning')
    return redirect(url_for('admin_dashboard'))

@app.route('/editar_docente/<int:id>')
@login_required
def editar_docente(id):
    u = db.session.get(User, id)
    return render_template('editar_docente.html', docente=u)

# --- REPORTE MATRICIAL ---

@app.route('/descargar_reporte_matricial')
@login_required
def descargar_reporte_matricial():
    if current_user.rol != 'admin': return redirect(url_for('index'))
    
    fecha_ini_str = request.args.get('fecha_inicio')
    fecha_fin_str = request.args.get('fecha_fin')
    docente_filtro = request.args.get('docente_id')
    
    if fecha_ini_str and fecha_fin_str:
        start_dt = datetime.strptime(fecha_ini_str, '%Y-%m-%d')
        end_dt = datetime.strptime(fecha_fin_str, '%Y-%m-%d')
    else:
        end_dt = datetime.now()
        start_dt = end_dt - timedelta(days=6)

    dias_reporte = [ (start_dt + timedelta(days=x)).strftime('%Y-%m-%d') for x in range((end_dt-start_dt).days + 1) ]
    docentes = User.query.filter_by(biometric_id=docente_filtro).all() if docente_filtro and docente_filtro != 'todos' else User.query.filter_by(rol='docente').all()

    all_logs = Log.query.filter(
        Log.fecha >= start_dt,
        Log.fecha <= end_dt + timedelta(days=1),
        Log.tipo_evento.like('%Asistencia%')
    ).all()

    wb = Workbook()
    ws = wb.active
    ws.title = "Reporte ISTAE"

    # Estilos
    fill_green = PatternFill(start_color="92D050", end_color="92D050", fill_type="solid")
    fill_yellow = PatternFill(start_color="FFC000", end_color="FFC000", fill_type="solid")
    border_thin = Border(left=Side(style='thin'), right=Side(style='thin'), top=Side(style='thin'), bottom=Side(style='thin'))
    align_center = Alignment(horizontal='center', vertical='center', wrap_text=True)

    ws.merge_cells(start_row=1, start_column=1, end_row=1, end_column=3 + len(dias_reporte))
    ws.cell(row=1, column=1, value=f"Reporte de Asistencia Multimodal ({start_dt.strftime('%d/%m/%Y')} al {end_dt.strftime('%d/%m/%Y')})").font = Font(bold=True, size=14)

    headers = ["ID BIO", "Nombre Docente", "Unidad"]
    for i, h in enumerate(headers, 1):
        c = ws.cell(row=2, column=i, value=h)
        c.fill, c.border, c.alignment, c.font = fill_green, border_thin, align_center, Font(bold=True)

    for i, dia in enumerate(dias_reporte, 4):
        c = ws.cell(row=2, column=i, value=dia[8:10]+"/"+dia[5:7])
        c.fill, c.border, c.alignment, c.font = fill_yellow, border_thin, align_center, Font(bold=True)

    row_idx = 3
    for doc in docentes:
        ws.cell(row=row_idx, column=1, value=doc.biometric_id).border = border_thin
        ws.cell(row=row_idx, column=2, value=doc.nombre).border = border_thin
        ws.cell(row=row_idx, column=3, value="Docencia").border = border_thin

        for col_idx, dia in enumerate(dias_reporte, 4):
            day_logs = [l for l in all_logs if l.usuario_id == doc.biometric_id and l.fecha.strftime('%Y-%m-%d') == dia]
            
            m_logs = sorted([l for l in day_logs if l.fecha.hour < 13], key=lambda x: x.fecha)
            t_logs = sorted([l for l in day_logs if l.fecha.hour >= 13], key=lambda x: x.fecha)

            def fmt(logs_list):
                if not logs_list: return "--:--"
                prefix = "(H) " if logs_list[0].origen == "Huella" else "(W) "
                if len(logs_list) > 1:
                    return f"{prefix}{logs_list[0].fecha.strftime('%H:%M')}-{logs_list[-1].fecha.strftime('%H:%M')}"
                return f"{prefix}{logs_list[0].fecha.strftime('%H:%M')}"

            cell = ws.cell(row=row_idx, column=col_idx, value=f"M: {fmt(m_logs)}\nT: {fmt(t_logs)}")
            cell.border, cell.alignment = border_thin, align_center

        row_idx += 1

    ws.column_dimensions['B'].width = 35
    for i in range(4, 4 + len(dias_reporte)):
        ws.column_dimensions[ws.cell(row=2, column=i).column_letter].width = 22

    output = io.BytesIO()
    wb.save(output)
    output.seek(0)
    return send_file(output, download_name="Reporte_Asistencia_ISTAE.xlsx", as_attachment=True)

# --- AJAX Y SEGURIDAD ---

@app.route('/api/logs')
def get_logs_json():
    logs_data = db.session.query(Log, User).outerjoin(User, Log.usuario_id == User.biometric_id).order_by(Log.id.desc()).limit(15).all()
    res = []
    for l, u in logs_data:
        res.append({
            "fecha": l.fecha.strftime('%Y-%m-%d %H:%M:%S'),
            "nombre": u.nombre if u else "ID: " + l.usuario_id,
            "tipo_evento": l.tipo_evento,
            "origen": l.origen,
            "evidencia": True if l.foto_path else False
        })
    return jsonify(res)

@app.route('/toggle_permiso/<int:id>', methods=['POST'])
@login_required
def toggle_permiso(id):
    u = db.session.get(User, id)
    if u:
        u.acceso_puerta = 1 if request.json.get('estado') else 0
        db.session.commit()
        return jsonify({"success": True})
    return jsonify({"success": False}), 404

@app.route('/actualizar_password', methods=['POST'])
@login_required
def actualizar_password():
    curr, new = request.form['current_password'], request.form['new_password']
    if check_password_hash(current_user.password, curr):
        current_user.password = generate_password_hash(new, method='pbkdf2:sha256')
        db.session.commit()
        flash('Contraseña actualizada con éxito.', 'success')
        return redirect(url_for('index'))
    flash('La contraseña actual es incorrecta.', 'danger')
    return redirect(url_for('perfil'))

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        u = User.query.filter_by(username=request.form['username']).first()
        if u and check_password_hash(u.password, request.form['password']):
            login_user(u)
            return redirect(url_for('index'))
        flash('Credenciales incorrectas.', 'danger')
    return render_template('login.html')

@app.route('/logout')
def logout():
    logout_user()
    return redirect(url_for('login'))

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)