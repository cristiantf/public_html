"""
Configuración del sistema ISTAE.

Los secretos NO se guardan en este archivo: se leen de variables de entorno
o del archivo instance/.env (formato CLAVE=valor, excluido de git).
"""
import os
from urllib.parse import quote_plus

_BASE_DIR = os.path.dirname(os.path.abspath(__file__))
ENV_FILE = os.path.join(_BASE_DIR, 'instance', '.env')


def _cargar_env(ruta):
    """Carga CLAVE=valor desde un archivo .env sin pisar variables ya definidas."""
    if not os.path.exists(ruta):
        return
    with open(ruta, encoding='utf-8') as f:
        for linea in f:
            linea = linea.strip()
            if not linea or linea.startswith('#') or '=' not in linea:
                continue
            clave, valor = linea.split('=', 1)
            os.environ.setdefault(clave.strip(), valor.strip())


def _requerida(clave):
    valor = os.environ.get(clave)
    if not valor:
        raise RuntimeError(
            f"Falta la variable de configuración {clave}. "
            f"Defínala en {ENV_FILE} o como variable de entorno."
        )
    return valor


_cargar_env(ENV_FILE)

# --- SEGURIDAD DE SESIÓN ---
# Cifra las cookies de sesión y protege los mensajes flash
SECRET_KEY = _requerida('SECRET_KEY')

# --- CONFIGURACIÓN DE BASE DE DATOS (MySQL) ---
_db_pass = quote_plus(_requerida('DB_PASS'))
SQLALCHEMY_DATABASE_URI = (
    f"mysql+pymysql://{_requerida('DB_USER')}:{_db_pass}"
    f"@{os.environ.get('DB_HOST', 'localhost')}/{_requerida('DB_NAME')}"
)

# --- PROTOCOLO DE SEGURIDAD IOT ---
# Token obligatorio en las peticiones del NodeMCU
TOKEN_NODE = _requerida('TOKEN_NODE')

# Exigir token (cabecera X-Token) en /api/sincronizar y /api/check_comando.
# Cambiar a true SOLO después de flashear el firmware que envía X-Token.
EXIGIR_TOKEN_HARDWARE = os.environ.get('EXIGIR_TOKEN_HARDWARE', 'false').lower() in ('1', 'true', 'si', 'yes')

# Contraseña del admin inicial (solo si no existe el usuario admin)
ADMIN_INITIAL_PASSWORD = os.environ.get('ADMIN_INITIAL_PASSWORD', '')

# --- Documentos legales (Términos, Política de Uso, Protección de Datos) ---
# Nombre del responsable del tratamiento y canal para ejercer derechos (LOPDP).
LEGAL_INSTITUCION = os.environ.get('LEGAL_INSTITUCION', 'Instituto Superior Tecnológico Alberto Enríquez')
LEGAL_CONTACTO = os.environ.get('LEGAL_CONTACTO', '')
