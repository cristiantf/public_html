"""
SISTEMA DE CONFIGURACIÓN ISAPI PARA DS-K1T8003EF
Este script habilita el envío de eventos en formato XML (ISAPI)
hacia el NodeMCU, saltándose las limitaciones del menú EHome.
"""

import requests
from requests.auth import HTTPDigestAuth

# --- DATOS DEL BIOMÉTRICO ---
IP_BIO = "192.168.1.22"
USER = "admin"
PASS = "istae1804A" # <--- PON TU CONTRASEÑA REAL AQUÍ

# --- DATOS DEL DESTINO (NodeMCU) ---
IP_NODE = "192.168.1.8"
PUERTO_NODE = 80

def habilitar_envio_xml():
    # 1. Definimos la URL de configuración de Hosts de Notificación
    url = f"http://{IP_BIO}/ISAPI/Event/notification/httpHosts"
    
    # 2. Creamos el XML que el biométrico SÍ entiende internamente
    xml_config = f"""<?xml version="1.0" encoding="UTF-8"?>
    <HttpHostList>
        <HttpHost>
            <id>1</id>
            <addressingFormatType>ipAddress</addressingFormatType>
            <hostName>{IP_NODE}</hostName>
            <ipAddress>{IP_NODE}</ipAddress>
            <portNo>{PUERTO_NODE}</portNo>
            <protocolType>http</protocolType>
            <parameterFormatType>xml</parameterFormatType>
            <url>/</url>
        </HttpHost>
    </HttpHostList>"""

    print(f"[*] Intentando forzar modo XML hacia {IP_NODE}...")
    
    try:
        # Enviamos la configuración usando PUT y autenticación Digest
        response = requests.put(
            url, 
            data=xml_config, 
            auth=HTTPDigestAuth(USER, PASS),
            headers={'Content-Type': 'application/xml'},
            timeout=10
        )
        
        if response.status_code == 200:
            print("[+] ÉXITO: El biométrico ha aceptado el NodeMCU como servidor de eventos XML.")
        else:
            print(f"[-] ERROR {response.status_code}: El equipo no aceptó la configuración.")
            print("Respuesta:", response.text)
            
    except Exception as e:
        print(f"[-] ERROR DE RED: {e}")

if __name__ == "__main__":
    habilitar_envio_xml()