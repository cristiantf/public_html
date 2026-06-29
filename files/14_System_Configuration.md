# Chapter 14 System Configuration


14.1 Network Settings
This chapter lists the request URLs for communication and network configurations of devices,
including network interface settings, wireless network settings, network access settings, email
settings, and so on.
• Get network capability
  Request URL: GET /ISAPI/System/Network/capabilities
• Import network certificate
  Request URL: GET /ISAPI/Security/deviceCertificate
• Remotely get connection socket IP
  Request URL: GET /ISAPI/System/Network/socketIP

       Note
  To check if getting socket IP is supported by device, you can call the request URL: GET /ISAPI/
  System/Network/capabilities to get the device capability ( XML_DeviceCap ). If supports, the
  node <isSupportGetLinkSocketIP> will be returned.
• Network Self-Adaptive
  • Get self-adaptive configuration capability
    Request URL: GET /ISAPI/System/Network/adaption/capabilities?format=json
  • Get self-adaptive parameters
    Request URL: GET /ISAPI/System/Network/adaption?format=json&streamType=
  • Set self-adaptive parameters
    Request URL: PUT /ISAPI/System/Network/adaption?format=json&streamType=

         Note
    To check if network self-adaptive configuration is supported, you can get the network
    capability XML_NetworkCap by the request URL: /ISAPI/System/Network/capabilities . If
    supports, the node <Adaption> will be returned in the capability message.

14.1.1 Email
• Get email configuration capability
  Request URL: GET /ISAPI/System/Network/mailing/capabilities
• Get or set parameters of multiple emails
  Request URL: GET or PUT /ISAPI/System/Network/mailing
• Get or set parameters of one email

  Request URL: GET or PUT /ISAPI/System/Network/mailing/<ID>
• Execute email test
  Request URL: POST /ISAPI/System/Network/mailing/test

14.1.2 Network Access

Protocol Access
• Get configuration capability of protocol access
  Request URL: /ISAPI/Security/adminAccesses/capabilities
• Get or set access parameters of multiple protocols
  Request URL: GET or PUT /ISAPI/Security/adminAccesses
• Get or set access parameters of one protocol
  Request URL: GET or PUT /ISAPI/Security/adminAccesses/<ID>
• 802.1 Protocol Access
  • Get 802.1 protocol access capability
    Request URL: GET /ISAPI/System/Network/interfaces/<ID>/ieee802.1x/capabilities
  • Get or set access parameters of 802.1 protocol
    Request URL: GET or PUT /ISAPI/System/Network/interfaces/<ID>/ieee802.1x

Hik-Connect Access
• Get or set access parameters of Hik-Connect
  Request URL: GET or PUT /ISAPI/System/Network/EZVIZ

       Note
  To check if the device supports accessing to Hik-Connect, you can call the request URL: GET /
  ISAPI/System/Network/capabilities to get the network capability ( XML_NetworkCap ). If
  supports, the node <isSupportEhome> will be returned in the capability and its value is "true".
• Edit verification code for Hik-Connect
  Request URL: PUT /ISAPI/System/Network/EZVIZ/secretKey?format=json

       Note
  To check if the device supports editing verification code for Hik-Connect, you can call the request
  URL: GET /ISAPI/System/Network/capabilities to get the network capability sets
  XML_NetworkCap . If supports, the node <secretKey> will be returned.

EHome Server Access
• Get configuration capability of EHome server access
  Request URL: GET /ISAPI/System/Network/Ehome/capabilities
• Get or set access parameters of EHome server
  Request URL: GET or PUT /ISAPI/System/Network/Ehome

• Get or set access parameters of EHome server according to the center ID
  Request URL: GET or PUT /ISAPI/System/Network/Ehome?centerID=
• Get configuration capability of report uploading method
  Request URL: GET /ISAPI/SecurityCP/ReportCenterCfg/capabilities?format=json
• Get or set parameters of report uploading method
  Request URL: GET or PUT /ISAPI/SecurityCP/ReportCenterCfg/<ID>?format=json

     Note
To check if the device supports accessing to EHome server, you can call the request URL: GET /
ISAPI/System/Network/capabilities to get the network capability ( XML_NetworkCap ). If
supports, the node <isSupportEZVIZ> will be returned in the capability and its value is "true".

SSH Server Access
Get or set access parameters of SSH server
Request URL: GET or PUT /ISAPI/System/Network/ssh

     Note
To check if the device supports accessing to SSH server, you can call the request URL: GET /ISAPI/
System/Network/capabilities to get the network capability ( XML_NetworkCap ). If supports, the
node <isSupportSSH> will be returned in the capability and its value is "true".

14.1.3 Network Interface

Network Interface
• Get configuration capability of one network interface
  Request URL: GET /ISAPI/System/Network/interfaces/<ID>/capabilities
• Get information of multiple network interfaces
  Request URL: GET /ISAPI/System/Network/interfaces
• Get or set parameters of one network interface
  Request URL: GET or PUT /ISAPI/System/Network/interfaces/<ID>
• Get IP address of one network interface
  Request URL: GET or PUT /ISAPI/System/Network/interfaces/<ID>/ipAddress

PoE
• Get configuration capability of PoE port
  Request URL: GET /ISAPI/System/Network/POE/capabilities?format=json
• Get or set PoE port parameters
  Request URL: GET or PUT /ISAPI/System/Network/POE?format=json

UPnP
• Get or set UPnP parameters

  Request URL: GET or PUT /ISAPI/System/Network/UPnP
• Get or set parameters of all UPnP ports
  Request URL: GET or PUT /ISAPI/System/Network/UPnP/ports
• Get or set parameters of one UPnP port
  Request URL: GET or PUT /ISAPI/System/Network/UPnP/ports/<ID>
• Get mapping statuses of all UPnP ports
  Request URL: GET /ISAPI/System/Network/UPnP/ports/status
• Get mapping status of one UPnP port
  Request URL: GET /ISAPI/System/Network/UPnP/ports/<ID>/status

14.1.4 Wireless Network

Wi-Fi
• Get Wi-Fi configuration capability
  Request URL: GET /ISAPI/System/Network/interfaces/<ID>/wireless/capabilities
• Get or set Wi-Fi parameters of one network interface
  Request URL: GET or PUT /ISAPI/System/Network/interfaces/<ID>/wireless

Wireless Hotspot
• Get configuration capability of wireless hotspot
  Request URL: GET /ISAPI/System/Network/interfaces/<ID>/wirelessServer/capabilities
• Get or set wireless hotspot parameters
  Request URL: GET or PUT /ISAPI/System/Network/interfaces/<ID>/wirelessServer
• Get list of devices connected to hotspot
  Request URL: GET
• Get information of a device connected to hotspot
  Request URL: GET /ISAPI/System/Network/interfaces/<ID>/wireless/accessDeviceList/<ID>
• Get capability of devices connected to hotspot
  Request URL: GET /ISAPI/System/Network/interfaces/<ID>/wireless/accessDeviceList/
  capabilities
• Get hotspot list
  Request URL: GET /ISAPI/System/Network/interfaces/<ID>/wireless/accessPointList
• Get one hotspot information
  Request URL: GET /ISAPI/System/Network/interfaces/<ID>/wireless/accessPointList/<ID>

Wireless Dial
• Get configuration capability of wireless dial
  Request URL: GET /ISAPI/System/Network/WirelessDial/Interfaces/<ID>/dial/capabilities
• Get or set wireless dial parameters
  Request URL: GET or PUT /ISAPI/System/Network/WirelessDial/Interfaces/<ID>/dial

14.1.5 Network Service

Software Service
• Get configuration capability of software service
  Request URL: GET /ISAPI/System/Software/channels/<ID>/capabilities
• Get or set parameters of software service
  Request URL: GET or PUT /ISAPI/System/Software/channels/<ID>

Session Initialization Protocol (SIP) Server
• Get SIP server capability
  Request URL: GET /ISAPI/System/Network/SIP/<ID>/capabilities
• Get or set parameters of all SIP servers
  Request URL: GET or PUT /ISAPI/System/Network/SIP
• Get or set parameters of one SIP server
  Request URL: GET or PUT /ISAPI/System/Network/SIP/<ID>
• Get configuration capability of SIP server
  Request URL: GET /ISAPI/System/Network/SIP/<ID>/SIPInfo/capabilities
• Get or set information of one SIP server
  Request URL: GET or PUT /ISAPI/System/Network/SIP/<ID>/SIPInfo
• Get or set information of all SIP servers
  Request URL: GET or PUT /ISAPI/System/Network/SIP/<ID>/SIPInfo/multiInfo

File Transfer Protocol (FTP) Server
• Get configuration capability of FTP server
  Request URL: GET /ISAPI/System/Network/ftp/capabilities
• Get or set parameters of one FTP server
  Request URL: GET or PUT /ISAPI/System/Network/ftp/<ID>
• Get or set parameters of all FTP servers
  Request URL: GET or PUT /ISAPI/System/Network/ftp
• Perform FTP server test
  Request URL: POST /ISAPI/System/Network/ftp/test

Dynamic Domain Name Server (DDNS)
• Get DDNS configuration capability
  Request URL: GET /ISAPI/System/Network/DDNS/capabilities
• Get or set parameters of all DDNSs
  Request URL: GET or PUT /ISAPI/System/Network/DDNS
• Get or set parameters of one DDNS
  Request URL: GET or PUT /ISAPI/System/Network/DDNS/<ID>
• Get configuration capability of dynamic domain name

  Request URL: GET /ISAPI/System/Network/interfaces/<ID>/dynamicHostName/capabilities?
  format=json
• Get or set dynamic domain name
  Request URL: GET or PUT /ISAPI/System/Network/interfaces/<ID>/dynamicHostName?
  format=json

       Note
  To check if setting dynamic domain name is supported, you can call the request URL: GET /ISAPI/
  System/Network/capabilities to get the network capability ( XML_NetworkCap ). If supports,
  the node <isSupportDynamicHostName> is returned and its value is "true".

Log Server
• Get log server configuration capability
  Request URL: GET /ISAPI/System/logServer/capabilities
• Get or set log server parameters
  Request URL: GET or PUT /ISAPI/System/logServer
• Perform log server text
  Request URL: POST /ISAPI/System/logServer/test

Static Routing
Get, set, or delete static routing parameters
Request URL: GET, PUT, or DELETE /ISAPI/System/Network/StaticRoute

14.2 Time Settings
This chapter lists the request URLs for device time configuration, including setting time, setting
time zone, and so on.
• Get time configuration capability
  Request URL: GET /ISAPI/System/time/capabilities

       Note
  To check if time configuration is supported, you can call the request URL: GET /ISAPI/System/
  capabilities to get the device capability ( XML_DeviceCap ). If supports, the node
  <isSupportTimeCap> will be returned.
• Get or set time type
  Request URL: GET or PUT /ISAPI/System/time/timeType?format=json
• Get or set time parameters
  Request URL: GET or PUT /ISAPI/System/time
• Get or set time zone
  Request URL: GET or PUT /ISAPI/System/time/timeZone
• Get or set local time parameters

  Request URL: GET or PUT /ISAPI/System/time/localTime
• NTP Server
  • Get NTP server capability
    Request URL: GET /ISAPI/System/time/ntpServers/capabilities
  • Get, set, or delete multiple NTP servers
    Request URL: GET, PUT, or DELETE /ISAPI/System/time/ntpServers
  • Get set, or delete one NTP server
    Request URL: GET, PUT, or DELETE /ISAPI/System/time/ntpServers/<ID>
  • Add one NTP server
    Request URL: POST /ISAPI/System/time/ntpServers
  • Execute NTP server test
    Request URL: POST /ISAPI/System/time/ntpServers/test

14.3 System Diagnose
This chapter lists the request URLs for getting system diagnose information and the exporting
status.
• Get diagnose information
  Request URL: GET /ISAPI/System/diagnosedData
• Get process of exporting diagnose information
  URL: GET /ISAPI/System/diagnosedData/exportStatus

       Note
  To check if getting disgnose information is supported, you can call the request URL: GET /ISAPI/
  System/capabilities to get the device capability ( XML_DeviceCap >. If supports, the node
  <isSupportDiagnosedData> will be returned.

14.4 Data Replenishment
In the condition of disconnection between platform and NVR, the NVR saves the data of people
counting, heat map, temperature, and vehicle. When the connection is resumed, the platform can
get the specified data from NVR during disconnection period.

People Counting Data Replenishment
• Get data replenishment capability of people counting
  Request URL: GET /ISAPI/System/Video/inputs/channels/counting/collection/capabilities?
  format=json

       Note
  Before getting people counting data replenishment capability, you should check whether this
  function is supported by the device via the node <isSupportCountingCollection> in
  XML_VideoCap , URL: GET /ISAPI/System/Video/capabilities .
• Perform data replenishment of people counting
  Request URL: POST /ISAPI/System/Video/inputs/channels/counting/collection?format=json

Heat Map Data Replenishment
• Get data replenishment capability of heat map
  Request URL: GET /ISAPI/System/Video/inputs/channels/heatMap/collection/capabilities?
  format=json

       Note
  Before getting people counting data replenishment capability, you should check whether this
  function is supported by the device via the node <isSupportHeatmapCollection> in
  XML_VideoCap , URL: GET /ISAPI/System/Video/capabilities .
• Perform data replenishment of heat map
  Request URL: POST /ISAPI/System/Video/inputs/channels/heatMap/collection?format=json

Temperature Data Replenishment
• Get data replenishment capability of temperature
  Request URL: GET /ISAPI/Thermal/temperature/collection/capabilities?format=json

       Note
  Before getting temperature data replenishment capability, you should check whether this
  function is supported by the device via the node <isSupportTemperatureCollection> in
  XML_ThermalCap , URL: GET /ISAPI/Thermal/capabilities .
• Perform temperature data replenishment
  Request URL: POST /ISAPI/Thermal/temperature/collection?format=json

Vehicle Detection Data Replenishment
• Get VCA search capability
  Request URL: GET /ISAPI/SDT/Management/IntelligentSearch/capabilities?format=json
• Search for vehicle detection data
  Request URL: POST /ISAPI/SDT/Management/IntelligentSearch?format=json

       Note
  Before searching for vehicle detection data, you should check whether the device supports this
  function. When the node <isSupportIntelligentSearch> is returned in device capability sets
  XML_DeviceCap , and values "true".
