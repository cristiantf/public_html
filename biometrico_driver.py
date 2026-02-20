"""
Módulo de utilidades para interactuar con la base de datos a través de los modelos
SQLAlchemy de la aplicación Flask principal.
Optimizado para manejar objetos DateTime y evitar errores de tipo.
"""

from datetime import datetime
import pytz
import urllib.request
import urllib.error
import json
# Importamos la instancia de la aplicación para el contexto de ejecución
from app import app

def guardar_log_remoto(uid, evento, origen="Huella", fecha_dispositivo=None):
    """
    Guarda un registro de log en la base de datos MySQL.
    Convierte las cadenas de fecha del hardware a objetos datetime de Python.
    """
    from app import db, Log  # Importación local para prevenir ciclos de importación
    
    with app.app_context():
        try:
            tz_ecuador = pytz.timezone('America/Guayaquil')
            
            if not fecha_dispositivo:
                # Si no hay fecha del dispositivo, capturamos la hora actual del servidor
                fecha_final = datetime.now(tz_ecuador)
            else:
                # Procesamos la fecha recibida (ej. 2026-02-15T08:30:00)
                try:
                    # Limpiamos el formato ISAPI de Hikvision
                    fecha_limpia = fecha_dispositivo.replace('T', ' ')[:19]
                    # Convertimos la cadena a un objeto datetime real para SQLAlchemy
                    fecha_final = datetime.strptime(fecha_limpia, "%Y-%m-%d %H:%M:%S")
                except ValueError:
                    # Fallback si el formato de fecha es irreconocible
                    fecha_final = datetime.now(tz_ecuador)

            nuevo_log = Log(
                fecha=fecha_final,
                usuario_id=str(uid),
                tipo_evento=evento,
                origen=origen
            )
            
            db.session.add(nuevo_log)
            db.session.commit()
            print(f"INFO: Log persistido exitosamente para ID {uid} | {fecha_final}")
            return True
        except Exception as e:
            db.session.rollback()
            print(f"ERROR: Fallo al guardar el log remoto. Detalle: {e}")
            return False

def obtener_lista_blanca():
    """
    Retorna una cadena de texto con los IDs autorizados (acceso_puerta=1).
    Formato compatible con la memoria local del microcontrolador.
    """
    from app import User
    with app.app_context():
        try:
            # Consultamos solo los usuarios que tienen permiso físico de apertura
            usuarios_autorizados = User.query.filter_by(acceso_puerta=1).all()
            lista_ids = ",".join([str(u.biometric_id) for u in usuarios_autorizados])
            return lista_ids
        except Exception as e:
            print(f"ERROR: No se pudo obtener la sincronización de IDs. {e}")
            return ""

def verificar_usuario_existente(biometric_id):
    """Verifica si un ID existe en el sistema antes de registrar un evento."""
    from app import User
    with app.app_context():
        try:
            usuario = User.query.filter_by(biometric_id=str(biometric_id)).first()
            return usuario is not None
        except Exception as e:
            print(f"ERROR: Error de consulta para ID {biometric_id}. {e}")
            return False

# --- UTILIDADES DE PRUEBA Y EMULACIÓN HTTP (SOPORTE PRODUCCIÓN) ---

def simular_post_hardware(uid, base_url="https://acceso.istae.edu.ec"):
    """
    Emula la petición JSON que enviaría el NodeMCU al servidor Flask.
    Útil para pruebas de conectividad y validación de tokens.
    """
    print(f"\n[SISTEMA] Emulando registro para ID: {uid}...")
    
    # Este payload debe coincidir con la lógica de node.ino
    payload = {
        "id": str(uid),
        "estado": "EXITO",
        "fecha_dispositivo": datetime.now().strftime("%Y-%m-%dT%H:%M:%S"),
        "token": "istae1805A" # Debe coincidir con config.py para ser aceptado
    }
    
    try:
        url_api = f"{base_url}/api/recibir_log"
        data_json = json.dumps(payload).encode('utf-8')
        
        req = urllib.request.Request(
            url_api, 
            data=data_json, 
            headers={'Content-Type': 'application/json'}
        )
        
        with urllib.request.urlopen(req) as response:
            res_body = response.read().decode('utf-8')
            print(f"   -> Servidor Responde: {res_body} (Código {response.getcode()})")
            return True
    except urllib.error.HTTPError as e:
        print(f"   -> ❌ Error del Servidor: {e.code} {e.reason}")
        return False
    except Exception as e:
        print(f"   -> ❌ Error de Red: {e}")
        return False

if __name__ == '__main__':
    print("==============================================")
    print("   DRIVER DE PRUEBAS BIOMÉTRICAS - ISTAE      ")
    print("==============================================")
    print("1. Consultar Lista Blanca (Acceso Directo DB)")
    print("2. Simular Marca de Huella (Vía API HTTPS)")
    print("3. Verificar Existencia de ID")
    
    try:
        opcion = input("\nSeleccione una opción: ")
        
        if opcion == "1":
            print(f"IDs Autorizados: {obtener_lista_blanca()}")
        elif opcion == "2":
            id_test = input("Ingrese el ID del docente para la prueba: ")
            simular_post_hardware(id_test)
        elif opcion == "3":
            id_check = input("Ingrese el ID a verificar: ")
            existe = verificar_usuario_existente(id_check)
            print(f"Resultado: {'Usuario ENCONTRADO' if existe else 'Usuario NO REGISTRADO'}")
        else:
            print("Opción no válida.")
            
    except KeyboardInterrupt:
        print("\nPrueba cancelada.")