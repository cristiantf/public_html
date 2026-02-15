import os
import io
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

# --- CONFIGURACIÓN DE BASE DE DATOS (HESTIACP / MYSQL) ---
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

class Log(db.Model):
    __tablename__ = 'logs'
    id = db.Column(db.Integer, primary_key=True)
    fecha = db.Column(db.String(30)) 
    usuario_id = db.Column(db.String(20))
    tipo_evento = db.Column(db.String(50))
    origen = db.Column(db.String(50))

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
    
    f_rec = data.get('fecha_dispositivo') or datetime.now(pytz.timezone('America/Guayaquil')).strftime("%Y-%m-%d %H:%M:%S")
    
    nuevo_log = Log(
        fecha=f_rec.replace('T', ' '),
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

# --- RUTAS DE NAVEGACIÓN ---

@app.route('/')
@login_required
def index():
    return redirect(url_for('admin_dashboard' if current_user.rol == 'admin' else 'docente_dashboard'))

@app.route('/admin/dashboard')
@login_required
def admin_dashboard():
    if current_user.rol != 'admin': return redirect(url_for('docente_dashboard'))
    docentes = User.query.filter_by(rol='docente').all()
    return render_template('admin.html', docentes=docentes)

@app.route('/docente/dashboard')
@login_required
def docente_dashboard():
    logs = Log.query.filter_by(usuario_id=current_user.biometric_id).order_by(Log.id.desc()).limit(10).all()
    return render_template('docente.html', logs=logs)

@app.route('/perfil')
@login_required
def perfil():
    return render_template('perfil.html')

# --- ACCIONES DE CONTROL ---

@app.route('/admin/abrir')
@login_required
def admin_abrir():
    db.session.add(Comando(instruccion='ABRIR'))
    db.session.add(Log(
        fecha=datetime.now(pytz.timezone('America/Guayaquil')).strftime("%Y-%m-%d %H:%M:%S"),
        usuario_id=current_user.biometric_id,
        tipo_evento="Apertura Remota",
        origen="Panel Control"
    ))
    db.session.commit()
    flash('Comando de apertura enviado a la puerta.', 'danger')
    return redirect(url_for('admin_dashboard'))

@app.route('/docente/abrir_puerta')
@login_required
def docente_abrir():
    if current_user.acceso_puerta == 1:
        db.session.add(Comando(instruccion='ABRIR'))
        db.session.add(Log(
            fecha=datetime.now(pytz.timezone('America/Guayaquil')).strftime("%Y-%m-%d %H:%M:%S"),
            usuario_id=current_user.biometric_id,
            tipo_evento="Apertura Remota",
            origen="Asistencia remota"
        ))
        db.session.commit()
        flash('Puerta abierta exitosamente.', 'success')
    else:
        flash('No tienes permiso para apertura remota.', 'warning')
    return redirect(url_for('docente_dashboard'))

@app.route('/docente/marcar_web')
@login_required
def docente_marcar():
    db.session.add(Log(
        fecha=datetime.now(pytz.timezone('America/Guayaquil')).strftime("%Y-%m-%d %H:%M:%S"),
        usuario_id=current_user.biometric_id,
        tipo_evento="Asistencia",
        origen="Asistencia remota"
    ))
    db.session.commit()
    flash('Asistencia web registrada.', 'success')
    return redirect(url_for('docente_dashboard'))

# --- GESTIÓN DE DOCENTES ---

@app.route('/crear_docente', methods=['POST'])
@login_required
def crear_docente():
    if current_user.rol != 'admin': return redirect(url_for('index'))
    bio_id = request.form.get('bio_id')
    user_n = request.form.get('username')
    
    if User.query.filter((User.biometric_id == bio_id) | (User.username == user_n)).first():
        flash('Error: El ID Biométrico o Usuario ya existe.', 'warning')
    else:
        hashed = generate_password_hash(request.form['password'], method='pbkdf2:sha256')
        new_u = User(
            biometric_id=bio_id,
            nombre=request.form['nombre'],
            username=user_n,
            password=hashed,
            acceso_puerta=1 if request.form.get('acceso_puerta') else 0
        )
        db.session.add(new_u)
        db.session.commit()
        flash('Docente creado correctamente.', 'success')
    return redirect(url_for('admin_dashboard'))

@app.route('/actualizar_docente', methods=['POST'])
@login_required
def actualizar_docente():
    if current_user.rol != 'admin': return redirect(url_for('index'))
    u = db.session.get(User, request.form.get('user_id'))
    u.nombre = request.form['nombre']
    u.biometric_id = request.form['bio_id']
    u.username = request.form['username']
    u.acceso_puerta = 1 if request.form.get('acceso_puerta') else 0
    
    if request.form.get('password'):
        u.password = generate_password_hash(request.form['password'], method='pbkdf2:sha256')
    
    db.session.commit()
    flash('Datos del docente actualizados.', 'success')
    return redirect(url_for('admin_dashboard'))

@app.route('/eliminar_docente/<int:id>')
@login_required
def eliminar_docente(id):
    if current_user.rol != 'admin': return redirect(url_for('index'))
    u = db.session.get(User, id)
    if u and u.username != 'admin':
        db.session.delete(u)
        db.session.commit()
        flash('Registro eliminado.', 'success')
    return redirect(url_for('admin_dashboard'))

@app.route('/editar_docente/<int:id>')
@login_required
def editar_docente(id):
    if current_user.rol != 'admin': return redirect(url_for('index'))
    u = db.session.get(User, id)
    return render_template('editar_docente.html', docente=u)

# --- REPORTES MATRICIALES (Openpyxl) ---

@app.route('/descargar_reporte_matricial')
@login_required
def descargar_reporte_matricial():
    if current_user.rol != 'admin': return redirect(url_for('index'))
    
    # 1. Configuración de fechas
    fecha_ini_str = request.args.get('fecha_inicio')
    fecha_fin_str = request.args.get('fecha_fin')
    docente_filtro = request.args.get('docente_id')
    
    if fecha_ini_str and fecha_fin_str:
        start_dt = datetime.strptime(fecha_ini_str, '%Y-%m-%d')
        end_dt = datetime.strptime(fecha_fin_str, '%Y-%m-%d')
    else:
        end_dt = datetime.now()
        start_dt = end_dt - timedelta(days=6)

    # 2. Obtener lista de días para las columnas
    dias_reporte = []
    curr = start_dt
    while curr <= end_dt:
        dias_reporte.append(curr.strftime('%Y-%m-%d'))
        curr += timedelta(days=1)

    # 3. Obtener Datos
    if docente_filtro and docente_filtro != 'todos':
        docentes = User.query.filter_by(biometric_id=docente_filtro).all()
    else:
        docentes = User.query.filter_by(rol='docente').all()

    all_logs = Log.query.filter(
        Log.fecha >= start_dt.strftime('%Y-%m-%d 00:00:00'),
        Log.fecha <= end_dt.strftime('%Y-%m-%d 23:59:59'),
        Log.tipo_evento.like('%Asistencia%')
    ).all()

    # 4. Crear Libro de Excel
    wb = Workbook()
    ws = wb.active
    ws.title = "Reporte Matricial"

    fill_header_green = PatternFill(start_color="92D050", end_color="92D050", fill_type="solid")
    fill_header_yellow = PatternFill(start_color="FFC000", end_color="FFC000", fill_type="solid")
    border_thin = Border(left=Side(style='thin'), right=Side(style='thin'), top=Side(style='thin'), bottom=Side(style='thin'))
    align_center = Alignment(horizontal='center', vertical='center', wrap_text=True)

    # Cabecera General
    ws.merge_cells(start_row=1, start_column=1, end_row=1, end_column=3 + len(dias_reporte))
    cell_title = ws.cell(row=1, column=1)
    cell_title.value = f"Reporte de Asistencia ({start_dt.strftime('%d/%m/%Y')} al {end_dt.strftime('%d/%m/%Y')})"
    cell_title.alignment = Alignment(horizontal='right')
    cell_title.font = Font(bold=True)

    # Cabeceras de Columnas
    headers = ["ID Biométrico", "Nombre Completo", "Departamento"]
    for i, h in enumerate(headers, 1):
        cell = ws.cell(row=2, column=i, value=h)
        cell.fill = fill_header_green
        cell.border = border_thin
        cell.alignment = align_center
        cell.font = Font(bold=True)

    # Cabeceras de Fechas
    for i, dia in enumerate(dias_reporte, 4):
        display_date = datetime.strptime(dia, '%Y-%m-%d').strftime('%d/%m')
        cell = ws.cell(row=2, column=i, value=display_date)
        cell.fill = fill_header_yellow
        cell.border = border_thin
        cell.alignment = align_center
        cell.font = Font(bold=True)

    # 5. Llenado de Filas (Docentes)
    row_idx = 3
    for doc in docentes:
        c1 = ws.cell(row=row_idx, column=1, value=doc.biometric_id)
        c2 = ws.cell(row=row_idx, column=2, value=doc.nombre)
        c3 = ws.cell(row=row_idx, column=3, value="Docencia")
        for c in [c1, c2, c3]: c.border = border_thin

        for col_idx, dia in enumerate(dias_reporte, 4):
            # Solución híbrida para evitar el error de startswith en objetos datetime
            day_logs = []
            for l in all_logs:
                if l.usuario_id == doc.biometric_id:
                    # Convertimos a string si es datetime para poder comparar el inicio
                    fecha_str = l.fecha if isinstance(l.fecha, str) else l.fecha.strftime('%Y-%m-%d %H:%M:%S')
                    if fecha_str.startswith(dia):
                        day_logs.append(l)
            
            manana_txt = "--:--"
            tarde_txt = "--:--"

            if day_logs:
                logs_m = []
                logs_t = []
                for l in day_logs:
                    try:
                        # Manejo seguro de la fecha sea string u objeto
                        if isinstance(l.fecha, str):
                            hora_str = l.fecha.split(' ')[1]
                            h_val = int(hora_str.split(':')[0])
                        else:
                            hora_str = l.fecha.strftime('%H:%M:%S')
                            h_val = l.fecha.hour
                            
                        prefix = "(H) " if l.origen == "Huella" else "(W) "
                        item = {"hora": hora_str[:5], "prefix": prefix}
                        if h_val < 13: logs_m.append(item)
                        else: logs_t.append(item)
                    except: continue

                if logs_m:
                    logs_m.sort(key=lambda x: x['hora'])
                    start = logs_m[0]
                    end = logs_m[-1]
                    manana_txt = f"{start['prefix']}{start['hora']}-{end['hora']}" if len(logs_m) > 1 else f"{start['prefix']}{start['hora']}"

                if logs_t:
                    logs_t.sort(key=lambda x: x['hora'])
                    start = logs_t[0]
                    end = logs_t[-1]
                    tarde_txt = f"{start['prefix']}{start['hora']}-{end['hora']}" if len(logs_t) > 1 else f"{start['prefix']}{start['hora']}"

            cell_val = f"Mañana: {manana_txt}\nTarde: {tarde_txt}"
            cell = ws.cell(row=row_idx, column=col_idx, value=cell_val)
            cell.border = border_thin
            cell.alignment = align_center

        row_idx += 1

    # Ajuste de anchos
    ws.column_dimensions['B'].width = 30
    ws.column_dimensions['C'].width = 15
    for i in range(4, 4 + len(dias_reporte)):
        ws.column_dimensions[ws.cell(row=2, column=i).column_letter].width = 22

    output = io.BytesIO()
    wb.save(output)
    output.seek(0)
    
    return send_file(output, download_name="Reporte_Asistencia_ISTAE.xlsx", as_attachment=True)

# --- SEGURIDAD Y OTROS ---

@app.route('/api/logs')
def get_logs_json():
    logs_data = db.session.query(Log, User).outerjoin(User, Log.usuario_id == User.biometric_id).order_by(Log.id.desc()).limit(15).all()
    res = [{"fecha": l.fecha, "nombre": u.nombre if u else "ID: " + l.usuario_id, "tipo_evento": l.tipo_evento, "origen": l.origen} for l, u in logs_data]
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
    curr_pw = request.form['current_password']
    new_pw = request.form['new_password']
    if check_password_hash(current_user.password, curr_pw):
        current_user.password = generate_password_hash(new_pw, method='pbkdf2:sha256')
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