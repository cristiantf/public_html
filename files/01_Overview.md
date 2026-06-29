# Chapter 1 Overview

This manual mainly introduces the protocol architecture, interaction or security specifications,
general integrations (e.g., devie management and maintenance, alarm or event receiving,
parameter configuration, etc.), and so on.

1.1 Introduction
The OPEN Intelligent Security Application Programming Interface (ISAPI) is a text protocol in
RESTful style based on HTTP for communicating between security devices/servers (e.g., cameras,
DVR, NVR, etc.) and client software/system. It defines the communication standard between
device/server and client software/system via the Internet Protocol (IP), see the network topology
and communication protocol layer framework in the figures below.

     Note
REST (REpresentational State Transfer) is a protocol design method which abstracts all information
as the resources. The abstracted resources are marked by the uniform identifies, i.e., URI (Uniform
Resource Identifiers) for simple and extendable management.

                                   Figure 1-1 Network Topology

                      Figure 1-2 Communication Protocol Layer Framework

1.2 Update History

Summary of Changes in Version 2.0_Sept., 2019
Related Product: DS-2CD50 Series and DS-2CD70 Series Box Camera with Software Version 5.6.10;
DS-2CD51 Series, DS-2CD55 Series, DS-2CD71 Series, and DS-2CD75 Series Dome Camera with
Software Version 5.6.10; DS-2CD7A Series and DS-2CD5A Series Bullet Camera with Software
Version 5.6.10
1. Extended device capability message XML_DeviceCap (related URL: /ISAPI/System/capabilities ):
   added a sub node <supportSmartOverlapChannles> (whether it supports stream configuration
   of smart events) to the node <SysCap>;
   added a node <streamEncryptionType> (stream encryption type).
2. Added URLs of configuring stream for displaying VCA rules of smart events:
   Get the capability: GET /ISAPI/Streaming/channels/<ID>/smartOverlap/capabilities?
   format=json ;
   Get or set stream parameters: GET or PUT /ISAPI/Streaming/channels/<ID>/smartOverlap?
   format=json .
3. Extended configuration capability message of IP address filter XML_Cap_IPFilter (related URL: /
   ISAPI/System/Network/ipFilter/capabilities ):
   added a sub node <bitMaskIPV6> (IPv6 prefix length) to the node <AddressMask> of
   <IPFilterAddressList>.
4. Extended e-PTZ parameter message XML_EPTZ (related URL: /ISAPI/Image/channels/<ID>/
   EPTZ ):
   added a node <streamType> (stream type).
5. Extended parameter message of a privacy mask region XML_PrivacyMaskRegion (related URL: /
   ISAPI/System/Video/inputs/channels/<ID>/privacyMask/regions/<ID> ):
   added a mask type "black" to the node <maskType>.
6. Added URLs of switching e-PTZ mode:
   Get capability: GET /ISAPI/Image/channels/<ID>/EPTZ/mode/capabilities?format=json ;
   Get or set parameters: GET or PUT /ISAPI/Image/channels/<ID>/EPTZ/mode?format=json .
7. Extended configuration capability message XML_LogServerCap and parameter message
   XML_LogServer of log server (related URLs: /ISAPI/System/logServer/capabilities and /ISAPI/
   System/logServer ):
   added a node <transmissionEncryption> (whether to enable transmission encryption).

8. Extended parameter message of security log server test XML_LogServerTestDescription (related
   URL: /ISAPI/System/logServer/test ):
   added a node <transmissionEncryption> (whether to enable transmission encryption).
9. Extended FTP capability message XML_Cap_FTPNotificationList (related URL: /ISAPI/System/
   Network/ftp/capabilities ):
   added a sub node <BrokenNetHttp> (whether it supports ANR (automatic network
   replenishment)) to the node <FTPNotification>.
10. Extended parameter message of a specific FTP server XML_FTPNotification (related URL: /
    ISAPI/System/Network/ftp/<ID> ):
    added a node <brokenNetHttp> (whether to enable ANR (automatic network replenishment)).
11. Extended configuration capability message XML_Cap_Track and parameter message
    XML_Track of a specific recording schedule (related URLs: /ISAPI/ContentMgmt/record/
    tracks/<ID>/capabilities and /ISAPI/ContentMgmt/record/tracks/<ID> ):
    added a node <durationEnabled> (whether to enable video expiry time).
12. Extended parameter message of all recording schedules XML_TrackList (related URL: /ISAPI/
    ContentMgmt/record/tracks ):
    added a sub node <durationEnabled> (whether to enable video expiry time) to the node
    <Track>.
13. Extended HDD management capability message XML_Cap_hddList (related URL: /ISAPI/
    ContentMgmt/Storage/hdd/capabilities ):
    added a sub node <Encryption> (encryption configuration) to the node <hdd>.
14. Extended parameter message of a specific HDD XML_hdd (related URL: /ISAPI/ContentMgmt/
    Storage/hdd/<ID> ):
    added a node <encryptionStatus> (encryption status).
15. Added a URL of formatting an encrypted HDD: PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/
    encryptFormat?format=json .
16. Added a URL of verifying HDD encryption password: PUT /ISAPI/ContentMgmt/Storage/hdd/
    <ID>/encryptVerfy?format=json .
17. Extended message of event capability supported by channel XML_ChannelEventCap (related
    URL: /ISAPI/Event/channels/<ID>/capabilities ):
    added an event type "certificateRevocation" (certificate is expired) to the node <eventType>.
18. Extended device event capability message XML_EventCap (related URL: /ISAPI/Event/
    capabilities ):
    added a node <isSupportCertificateRevocation> (whether it supports certificate expiry alarm).
19. Added the function of configuring certificate expiry alarm, refer to Configure Certificate Expiry
    Alarm .
20. Extended device protocol capability message XML_Cap_AdminAccessProtocolList and
    parameter message of all protocols supported by the device XML_AdminAccessProtocolList
    (related URLs: /ISAPI/Security/adminAccesses/capabilities and /ISAPI/Security/
    adminAccesses ):
    added a protocol type "SRTP" (Secure Real-Time Transport Protocol) to the sub node
    <protocol> of the node <AdminAccessProtocol>.

21. Extended parameter message of a specific protocol supported by the device
    XML_AdminAccessProtocol (related URL: /ISAPI/Security/adminAccesses/<ID> ):
    added a protocol type "SRTP" (Secure Real-Time Transport Protocol) to the node <protocol>.
22. Extended parameter message of a specific UPnP port XML_port and mapping status message
    of a specific UPnP port XML_portStatus (related URLs: /ISAPI/System/Network/UPnP/ports/
    <ID> and /ISAPI/System/Network/UPnP/ports/<ID>/status ):
    added a protocol type "SRTP" to the node <internalPort>.
23. Extended encoding capability message XML_Cap_StreamingChannel and encoding parameter
    message XML_StreamingChannel of a specific channel (related URLs: /ISAPI/Streaming/
    channels/<ID>/capabilities and /ISAPI/Streaming/channels/<ID> ):
    added a protocol type "SRTP" to the sub node <streamingTransport> of the node
    <ControlProtocol> of <ControlProtocolList> of <Transport>;
    added a sub node <SRTPMulticast> (SRTP multicast configuration) to the node <Transport>.
24. Extended storage capability message XML_RacmCap (related URL: /ISAPI/ContentMgmt/
    capabilities ):
    added two picture search conditions: "personQueueCounting" (people queuing-up detection)
    and "personQueueTime" (waiting time detection) to the node <pictureSearchType>.
25. Extended device security capability message XML_SecurityCap (related URL: /ISAPI/Security/
    capabilities ):
    added a node <isSupportCertificateCustomID> (whether it supports certificate configuration
    with custom ID).
26. Added a URL of getting CA (Certificate Authority) certificate capability: GET /ISAPI/Security/
    deviceCertificate/capabilities?format=json .
27. Added a URL of importing CA (Certificate Authority) certificate to device: PUT /ISAPI/Security/
    deviceCertificate?customID= .
28. Extended information message of multiple device certificates JSON_DeviceCertificates (related
    URL: /ISAPI/Security/deviceCertificate/certificates?format=json ):
    added two sub nodes: status (certificate status) and customID (custom certificate ID) to the
    node CertificateInfo of CertificateInfoList.
29. Added a URL of getting or deleting information of a specific device certificate: GET or DELETE /
    ISAPI/Security/deviceCertificate/certificates/<customID>?format=json .
30. Added URLs of configuring and managing client/server certificate:
    Get client/server certificate capability: GET /ISAPI/Security/serverCertificate/capabilities?
    format=json ;
    Get or generate PKCS#10 signature request of client/server self-signed certificate: GET or PUT /
    ISAPI/Security/serverCertificate/selfSignCert?customID= ;
    Generate PKCS#10 signature request: POST /ISAPI/Security/serverCertificate/certSignReq?
    customID= ;
    Get information of multiple client/server certificates in a batch: GET /ISAPI/Security/
    serverCertificate/certificates?format=json ;
    Get or delete information of a specific client/server certificate: GET or DELETE /ISAPI/Security/
    serverCertificate/certificates/<customID>?format=json ;

    Import client/server certificate to device: POST /ISAPI/Security/serverCertificate/certificate?
    customID= ;
    Export client/server certificate: GET /ISAPI/Security/serverCertificate/downloadCertSignReq?
    customID= .
31. Added URLs of selecting certificate:
    Get capability: GET /ISAPI/Security/certificate/select/capabilities?format=json ;
    Get or set parameters: GET or PUT /ISAPI/Security/certificate/select/<functinName>?
    format=json .
32. Added an alarm type "certificateRevocation" (certificate expiry alarm) in Supported Alarm/
    Event Types .

Summary of Changes in Version 2.0_Sept., 2019
Related Product: PanoVu PT Series Target Capture Camera in Version 5.5.23
1. Extended the rapid focus capability XML_Cap_EagleFocusing (related URL: GET /ISAPI/PTZCtrl/
   channels/<ID>/EagleFocusing/capabilities ):
   added one node <isSupportAuto> (whether device supports automatic calibration of rapid
   focus)
2. Added the function of automatically calibrating for rapid focus:
   Get capability: GET /ISAPI/PTZCtrl/channels/<ID>/EagleFocusing/auto/capabilities?
   format=json ;
   Automatically calibrate for rapid focus: GET /ISAPI/PTZCtrl/channels/<ID>/EagleFocusing/
   auto?format=json .
3. Extended the device capability message XML_DeviceCap (related URL: GET /ISAPI/System/
   capabilities ):
   added two nodes <guideEventSupport> (events which support quick setup by instruction) and
   <isSupportDevStatus> (whether device supports getting device status).
4. Added the function of configuring quick setup instruction for specified event:
   Get capability: GET /ISAPI/System/guideConfig/<guideEvent>/capabilities?format=json ;
   Get parameters: GET /ISAPI/System/guideConfig/<guideEvent>?format=json .
5. Extended the device status message XML_DeviceStatus (related URL: GET /ISAPI/System/
   status ):
   added one node <AlertStreamServerList> (user of arming device).

Summary of Changes in Version 2.0_Sept., 2019
Related Product: iDS-TDI300-A and iDS-TDI900-A Portable Speed Detector with Software Version
4.3.0
1. Extended device capability message XML_DeviceCap (related URL: /ISAPI/System/capabilities ):
   added a node <isSupportGuardAgainstTheft> (whether it supports device anti-theft
   configuration);
   added a sub node <isSupportShutdown> (whether it supports shutdown configuration) to the
   node <SysCap>.
2. Extended downloading capability message XML_DownloadAbility (related URL: /ISAPI/
   ContentMgmt/download/capabilities ):

   added a node <isSupportDownloadToUSB> (whether it supports exporting files to devices via
   USB).
3. Added URLs of exporting files to devices via USB:
   Get capability: GET /ISAPI/ContentMgmt/download/toUSB/capabilities?format=json ;
   Export files: POST /ISAPI/ContentMgmt/download/toUSB?format=json ;
   Get exporting progress: GET /ISAPI/ContentMgmt/download/toUSB/<taskId>/progress?
   format=json .
4. Added URLs of configuring device anti-theft parameters:
   Get configuration capability: GET /ISAPI/System/guardAgainstTheft/capabilities ;
   Get or set parameters: GET or PUT /ISAPI/System/guardAgainstTheft .
5. Extended device status parameter message XML_DeviceStatus (related URL: /ISAPI/System/
   status ):
   added three nodes: <dialSignalStrength> (4G signal strength), <USBStatusList> (USB status list),
   and <WifiStatusList> (Wi-Fi status list).
6. Added a URL of shutting down the device: PUT /ISAPI/System/shutdown?format=json .
7. Extended configuration capability message XML_Cap_DeviceInfo and parameter message
   XML_DeviceInfo of device information (related URLs: /ISAPI/System/deviceInfo/capabilities
   and /ISAPI/System/deviceInfo ):
   added a node <powerOnMode> (device startup mode).
8. Added an event type "radarMeasurement" (radar measurement data) in Supported Alarm/
   Event Types .
9. Added a sub status code "0x40000010"-USBNotExist (USB device is not connected) to status
   code 4 (Invalid Operation) in Error Codes in ResponseStatus .

Summary of Changes in Version 2.0_Aug., 2019
Related Product: DS-K1T640 Series, DS-K1T671 Series, and DS-K5671 Series Face Recognition
Terminal with Software Version 2.1.1
1. Added URLs of configuring audio input or output parameters of a specific channel:
   Get audio input capability: GET /ISAPI/System/Audio/AudioIn/channels/<ID>/capabilities ;
   Get or set audio input parameters: GET or PUT /ISAPI/System/Audio/AudioIn/channels/<ID> ;
   Get audio output capability: GET /ISAPI/System/Audio/AudioOut/channels/<ID>/capabilities ;
   Get or set audio output parameters: GET or PUT /ISAPI/System/Audio/AudioOut/channels/
   <ID> .
2. Extended device capability message XML_DeviceCap (related URL: /ISAPI/System/capabilities ):
   added a node <isSupportIDCardInfoEvent> (whether it supports ID card swiping event).

Summary of Changes in Version 2.0_Aug., 2019
Related Product Type: DS-76XXNI-I Series, DS-77XXNI-I Series, DS-86XXNI-I Series, and DS-96XXNI-I
Series NVR in Version 4.22.000
1. Extended device capability message XML_DeviceCap (related URL: /ISAPI/System/capabilities ):
   added a node <SHMCap> (SHM (SkyHawk Health Management) capability).
2. Extended configuration capability message of alarm linkage actions XML_EventTriggersCap
   (related URL: /ISAPI/Event/triggersCap ):

   added five nodes: <HighHDTemperatureTriggerCap> (HDD high temperature detection),
   <LowHDTemperatureTriggerCap> (HDD low temperature detection), <HDImpactTriggerCap>
   (HDD impact detection), <HDBadBlockTriggerCap> (HDD bad sector detection), and
   <SevereHDFailureTriggerCap> (HDD severe fault detection).
3. Extended alarm linkage capability type ( XML_EventTriggerCapType ):
   added a node <isNotSupportCenterModify> (whether editing configuration parameters of the
   surveillance center is not supported).
4. Added the function of configuring SHM (SkyHawk Health Management) alarm linkage:
   Get or set linkage parameters of HDD high temperature detection: GET or PUT /ISAPI/Event/
   triggers/highHDTemperature ;
   Get or set linkage parameters of HDD low temperature detection: GET or PUT /ISAPI/Event/
   triggers/lowHDTemperature ;
   Get or set linkage parameters of HDD impact detection: GET or PUT /ISAPI/Event/triggers/
   hdImpact ;
   Get or set linkage parameters of HDD bad sector detection: GET or PUT /ISAPI/Event/triggers/
   hdBadBlock ;
   Get or set linkage parameters of HDD severe fault detection: GET or PUT /ISAPI/Event/triggers/
   severeHDFailure .
5. Extended VCA search capability message JSON_IntelligentSearchCap (related URL: /ISAPI/SDT/
   Management/IntelligentSearch/capabilities?format=json ):
   added a value "unknown" to the node vehicleType (vehicle type).
6. Extended VCA search condition message JSON_IntelligentSearchCondition and VCA search
   result message JSON_IntelligentSearchResult (related URL: /ISAPI/SDT/Management/
   IntelligentSearch?format=json ):
   added a value "unknown" to the sub node vehicleType (vehicle type) of the node vehicleInfo.
7. Extended condition message of exporting VCA search results JSON_VCASearchExportCond
   (related URL: /ISAPI/SDT/Management/IntelligentSearch/export?format=json ):
   added a value "unknown" to the sub node vehicleType (vehicle type) of the node vehicleInfo of
   targetInfo.
8. Extended capability message XML_Cap_ExtraInfo and parameter message XML_ExtraInfo of
   storing additional information (related URLs: /ISAPI/ContentMgmt/Storage/ExtraInfo/
   capabilities and /ISAPI/ContentMgmt/Storage/ExtraInfo ):
   added a disk mode "RAID" to the node <diskMode>.
9. Extended supported alarm and event types in Supported Alarm/Event Types :
   added five event types: "highHDTemperature" (HDD High Temperature), "lowHDTemperature"
   (HDD Low Temperature), "hdImpact" (HDD Impact), "hdBadBlock" (HDD Bad Sector), and
   "severeHDFailure" (HDD Severe Fault).
10. Extended the log types in Log Types for ISAPI :
     added five exception log types: "highHDTemperature" (HDD High Temperature),
     "lowHDTemperature" (HDD Low Temperature), "hdImpact" (HDD Impact), "hdBadBlock" (HDD
     Bad Sector), and "severeHDFailure" (HDD Severe Fault);
     added two additional log types: "hdFormatStart" (Formatting HDD Started) and
     "hdFormatStop" (Formatting HDD Stopped).

Summary of Changes in Version 2.0_Aug., 2019
Related Product Type: Thermal & Optical Bi-spectrum Positioning System in Version 5.5.21
1. Extended the device capability XML_DeviceCap (related URL: GET /ISAPI/System/capabilities ):
   added two nodes <isSupportInstallationAngleCalibration> (whether it supports installation
   angle calibration) and <isSupportZeroBiasCalibration> (whether it supports zero bias
   calibration).
2. Added the function of calibrating accelerometer zero bias: PUT /ISAPI/System/
   zeroBiasCalibration/channels/<ID>?format=json .
3. Added the function of installation angle calibration:
   Get the calibration capabilities: GET /ISAPI/System/installationAngleCalibration/channels/
   <ID>/capabilities?format=json ;
   Get the calibration status: GET /ISAPI/System/installationAngleCalibration/channels/<ID>?
   format=json ;
   Calibrate installation angle: PUT /ISAPI/System/installationAngleCalibration/channels/<ID>?
   format=json .
4. Extended the log types Log Types for ISAPI :
   added one log "scheduledAngleCalibration" (scheduled angle calibration) to operation log type;
   added two logs "overvoltage" (high supply voltage) and "undervoltage"(low supply voltage) to
   exception log type.
5. Extended the device event capability message XML_EventCap (related URL: GET /ISAPI/Event/
   capabilities ):
   added one node <isSupportVoltageInstable> (whether device supports supply voltage
   exception alarm).
6. Extended the configuration capability of alarm linkage actions XML_EventTriggersCap (related
   URL: GET /ISAPI/Event/triggersCap ):
   added one node <voltageInstableTriggerCap> (supply voltage exception).
7. Added one alarm/event type: "voltageinstable" (supply voltage exception), see details in
   Configure Exception Alarm .

Summary of Changes in Version 2.0_Aug., 2019
Related Product: Traffic Terminal Server in Version 5.0.0
1. Added a URL to configure control parameters of a digital channel: /ISAPI/ContentMgmt/
   InputProxy/channels/<ID>/chanCtrl
2. Added a URL to reboot digital channel: /ISAPI/ContentMgmt/InputProxy/channels/<ID>/
   reboot
3. Added a URL to check port mapping is required for connecting to a digital channel: /ISAPI/
   ContentMgmt/InputProxy/channels/<ID>/portMapParam
4. Added a URL to configure static routing parameters: /ISAPI/System/Network/StaticRoute .
5. Added URLs to configure log parameters:
   Get capability: GET /ISAPI/ContentMgmt/logConfig/capabilities

   Get or set parameters: GET or PUT /ISAPI/ContentMgmt/logConfig
6. Added a URL to export the device log files: POST /ISAPI/ContentMgmt/logSearch/
   dataPackage .

Summary of Changes in Version 2.0_July, 2019
Related Product: DeepinMind NVR in Version 4.1.70
1. Added one alarm type "LFPD" (low frequency person detection alarm) to Supported Alarm/
   Event Types .
2. Extended log types Log Types for ISAPI :
   added one minor log type "remoteLFPDconfig" (remote configuration of low frequency person
   detection) to operation logs;
   added two minor log types "LFPDAlarmStart" (low frequency person alarm started) and
   "LFPDAlarmStop" (low frequency person alarm stopped) to alarm logs.
3. Extended the error codes, see details in Error Codes in ResponseStatus :
   added two error codes "0x60001051"-noSupportDeleteStrangerLib (deleting stranger library is
   not supported) and "0x60001052"-noSupportCreateStrangerLib (creating stranger library is not
   supported) to status code 6 (Invalid Message Content);
   added two error code "0x30001013"-SSDFileSystemIsError (SSD file system error) and
   "0x30001014"-insufficientSSDCapacityForFPD (insufficient SSD space for person frequency
   detection) to status code 3 (Device Error).
4. Extended the network resource statistics message JSON_resourceStatistics (related URL: /
   ISAPI/System/Network/resourceStatistics?format=json ):
   added two nodes inputPictureBandwidth (picture input bandwidth) and
   outputPictureBandwidth (picture output bandwidth).
5. Extended the intelligent capability message XML_IntelliCap :
   added one node <isSupportFaceScore> (whether camera supports face grading configuration).

Summary of Changes in Version 2.0_July, 2019
Related Product Type: DS-2TA03-7AVI, DS-2TA03-15VI, DS-2TA03-15SVI, DS-2TA06-25SVI,
DS-2TA06-25VI, and DS-2TA03-25SVI Thermographic Automation Thermal Camera in Version 2.2
1. Added a request URL for getting image adjustment capability: GET /ISAPI/Image/channels/
   <ID>/color/capabilities .
2. Extended the image configuration capability of a specified channel XML_Cap_ImageChannel
   and the image configuration parameters message XML_ImageChannel (related URL: GET /
   ISAPI/Image/channels/<ID>/capabilities and /ISAPI/Image/channels/<ID> ):
   added one node <TempRange> (temperature range).
3. Added the function of configuring temperature range of a specified channel:
   Get capability: GET /ISAPI/Image/channels/<ID>/tempRange/capabilities ;
   Get temperature range parameters: GET /ISAPI/Image/channels/<ID>/tempRange ;
   Set temperature range: PUT /ISAPI/Image/channels/<ID>/tempRange .
4. Added a request URL for getting focus configuration capability:

   GET /ISAPI/Image/channels/<ID>/focusConfiguration/capabilities .
5. Extended the focus parameters message XML_FocusConfiguration (related URL: /ISAPI/Image/
   channels/<ID>/focusConfiguration ):
   added one node <highTemperaturePriority> (whether to enable high temperature priority
   mode).

Summary of Changes in Version 2.0_July, 2019
Related Product Type: DS-PRI120 Security Radar
1. Extended the device capability message XML_DeviceCap (related URL: /ISAPI/System/
   capabilities ):
   added a node <isSupportRadar> (whether to support security radar).
2. Added seven sub status codes to status code 4 (Invalid Operation) in Error Codes in
   ResponseStatus :
   "0x4000802c"-masterSlaveIsEnable (The master-slave relationship has taken effect, the slave
   radar does not support this operation), "0x4000802d"-forceTrackNotEnabled (Mandatory
   tracking is disabled), "0x4000802e"-isNotSupportZoneConfigByLocalArea (This area does not
   support the zone type), "0x4000802f"-alarmLineCross (Trigger lines are overlapped),
   "0x40008030"-zoneDrawingOutOfRange (The drawn zone is out of detection range),
   "0x40008031"-alarmLineDrawingOutOfRange (The drawn trigger line is out of detection range),
   and "0x40008032"-hasTargetInWarningArea (The warning zone already contains targets.
   Whether to enable mandatory arming?).
3. Extended the log types Log Types for ISAPI :
   added six operation log types: "addZone" (Added Zone), "modZone" (Edited Zone), "delZone"
   (Deleted Zone), "addAlarmLine" (Added Trigger Line), "modAlarmLine" (Edited Trigger Line), and
   "delAlarmLine" (Deleted Trigger Line).

Summary of Changes in Version 2.0_July, 2019
Related Product: Thermographic Cube Camera in Version 1.0
1. Extended the device hardware configuration capabilities XML_Cap_HardwareService and
   XML_HardwareService :
   added one node <captureWithSupplimentLightEnabled> (enable snapshot supplement light or
   not).
2. Extended the PTZ control capability XML_PTZChanelCap and the PTZ control parameters
   XML_PTZChannel (related URL: GET /ISAPI/PTZCtrl/channels/<ID>/capabilities and /ISAPI/
   PTZCtrl/channels/<ID> ):
   added two control protocols "modbus-RTU" and "modbus-ASCII" to node <controlProtocol>.
3. Extended the palettes parameters XML_Palettes (related URL: /ISAPI/Image/channels/<ID>/
   Palettes ):
   added one mode "Color3" to node <mode>.

Summary of Changes in Version 2.0_July, 2019
Related Products: DS-K1A802 Series, DS-K1A802A Series, and DS-K1A8503 Series Fingerprint Time
Attendance Terminal; DS-K1T804 Series, DS-K1T8003 Series, and DS-K1T8004 Series Fingerprint
Access Control Terminal.
1. Extended the query parameter of the URL for upgrading the slave device's firmware /ISAPI/
   System/updateFirmware?type=&id= :
   added a module type "uboot" to the query parameter type.
2. Extended the peripherals upgrade capability message XML_Cap_AcsUpdate (related URL: /
   ISAPI/System/AcsUpdate/capabilities ):
   added a upgrade type "uboot" to the node <type>.

Summary of Changes in Version 2.0_June, 2019
Related Products: DS-PHA Series Hybrid Security Control Panel, DS-PKG Series Wired Keypad, and
DS-PM-RSWR Series RS-485 Wireless Receiver
1. Added a URL to upgrade peripheral module's firmware: PUT or POST /ISAPI/System/
   updateFirmware?type=&moduleAddress= .
2. Extended peripherals upgrade capability message XML_Cap_AcsUpdate (related URL: /ISAPI/
   System/AcsUpdate/capabilities ):
   added three upgrading types to the node <type>: "keypad", "wirelessRecv" (wireless receiving
   module), and "wiredZone" (wired zone module);
   added three nodes: <keypadAddress> (range of keypad module address),
   <wirelessRecvAddress> (range of wireless receiving module address), and <wiredZoneAddress>
   (range of wired zone module address).
3. Extended device information message XML_DeviceInfo (related URL: /ISAPI/System/
   deviceInfo ):
   added a device type "PHA" (Axiom hybrid security control panel) to the node <deviceType>.
4. Extended the log types Log Types for ISAPI :
   added four alarm log types: "RS-485AlarmInputModuleEvident" (RS-485 Zone Module
   Tampered), "RS-485AlarmInputModuleTamperReset" (RS-485 Zone Module Tampering Reset),
   "RS-485WirelessReceiverTamperEvident" (RS-485 Wireless Receiver Module Tampered), and
   "RS-485WirelessReceiverTamperEvidentReset" (RS-485 Wireless Receiver Module Tampering
   Reset);
   added six exception log types: "RS-485AlarmInputModuleDisconnected" (RS-485 Zone Module
   Offline), "RS-485AlarmInputModuleConnected" (RS-485 Zone Module Online),
   "RS-485WirelessReceiverDisconnected" (RS-485 Wireless Receiver Module Offline),
   "RS-485WirelessReceiverConnected" (RS-485 Wireless Receiver Module Online),
   "keypadDisconnected" (Keypad Offline), and "keypadConnected" (Keypad Online);
   added 9 operation log types: "delRS-485InputModule" (RS-485 Zone Module Deleted),
   "delRS-485OutputModule" (RS-485 Output Module Deleted), "delRS-485WirelessReceiver"
   (RS-485 Wireless Receiver Module Deleted), "enrollRS-485InputModule" (RS-485 Zone Module
   Registered), "enrollRS-485OutputModule" (RS-485 Output Module Registered),
   "delRS-485OutputModule" (RS-485 Output Module Deleted), "enrollRS-485WirelessReceiver"

  (RS-485 Wireless Receiver Module Registered), "enrollKeypad" (Keypad Registered), and
  "delKeypad" (Keypad Deleted).

Summary of Changes in Version 2.0_June, 2019
Related Products: Thermal Network Bullet Camera; Thermal Bi-spectrum Network Bullet Camera;
Thermal & Optical Network Turret Camera; Thermal Box Camera; Thermal Network Turret Camera
in Version 5.5.20
1. Extended the capability of supplement light alarm linkage JSON_WhiteLightAlarmCap (related
   URL: GET /ISAPI/Event/triggers/notifications/whiteLightAlarm/capabilities?format=json ):
   added one node "whiteLightMode" (supplement light mode).
2. Extended the parameters of supplement light alarm linkage JSON_WhiteLightAlarm (related
   URL: /ISAPI/Event/triggers/notifications/whiteLightAlarm?format=json ):
   added one node "whiteLightMode" (supplement light mode).
3. Extended the encoding capability of a specific channel XML_Cap_StreamingChannel (related
   URL: GET /ISAPI/Streaming/channels/<ID>/capabilities ):
   added one node <minimumResolutionSupportedBySmartCode> (minimum resolution
   supported by smart coding).

Summary of Changes in Version 2.0_July, 2019
Related Product: Thermal & Optical Bi-spectrum Network Speed Dome; Thermal & Optical Bi-
spectrum Positioning System; Thermal & Optical Bi-spectrum Network Stable PTZ Camera in
Version 5.5.19
1. Added the function of target enhancement:
   Get the target enhancement capability: GET /ISAPI/Image/channels/<ID>/
   targetEnhancement/capabilities ;
   Get the target enhancement parameters: GET /ISAPI/Image/channels/<ID>/
   targetEnhancement ;
   Set the target enhancement parameters: PUT /ISAPI/Image/channels/<ID>/
   targetEnhancement .
2. Extended the on-screen display parameters of PTZ status XML_PTZOSDDisplay (related URL: /
   ISAPI/PTZCtrl/channels/<ID>/PTZOSDDisplay ):
   added one node: <actionStatusDisplayEnabled> (whether to display status or not).
3. Extended the configuration capability of alarm linkage actions XML_EventTriggersCap (related
   URL: /ISAPI/Event/triggersCap ):
   added two nodes: <ShipsFlowDetectionTriggerCap> (ship flow detection) and
   <dredgerDetectionTriggerCap> (dredger detection).
4. Added one sub type "dredgerDetectionAlarm" (dredger detection alarm) to alarm logs in Log
   Types for ISAPI .
5. Added one file search condition "dredgerDetection" to node <metadataDescriptor> in message
   XML_CMSearchDescription .

Summary of Changes in Version 2.0_June, 2019
Related Products: DS-2CD6845 Series and DS-2XM6825 Series Network Camera in Software Version
5.5.90
1. Extended wireless service capability message XML_Cap_WirelessServer and wireless service
   configuration message XML_WirelessServer (related URLs: /ISAPI/System/Network/interfaces/
   <ID>/wirelessServer/capabilities and /ISAPI/System/Network/interfaces/<ID>/
   wirelessServer ):
   added a node <wifiApModeType> (current wireless access point modes: "true, false, auto").
2. Extended device algorithm parameter message XML_AlgorithmsVersion (related URL: /ISAPI/
   System/algorithmsVersion ):
   added an algorithm name "depthMap" to the sub node <name>.
3. Extended capability message XML_Cap_VCAResource and configuration message
   XML_VCAResource of intelligent resource switching (related URLs: /ISAPI/System/Video/
   inputs/channels/<ID>/VCAResource/capabilities and /ISAPI/System/Video/inputs/channels/
   <ID>/VCAResource ):
   added an intelligent resource "verticalPeopleCounting" to the node <type>.
4. Extended video input mode message XML_CaptureMode (related URL: /ISAPI/Image/
   channels/<ID>/capturemode ):
   added two video input modes "26"-1944×1212@24fps and "27"-1944×1212@25fps to the node
   <mode>.
5. Extended two-way audio parameter message XML_TwoWayAudioChannel (related URL: /ISAPI/
   System/TwoWayAudio/channels/<ID> ):
   added two nodes <lineOutForbidden> (whether the audio output is not supported) and
   <micInForbidden> (whether the audio input is not supported).
6. Added six error codes, refer to Error Codes in ResponseStatus for details: 0x60000085
   (DetectionLineOutofDetectionRegion), 0x60000086 (DetectionRegionError), 0x60000087
   (DetectionRegionOutOfCountingRegion), 0x60000088 (PedalAreaError), 0x60000089
   (DetectionAreaABError), and 0x6000008a (ABRegionCannotIntersect).

Summary of Changes in Version 2.0_June, 2019
Related Products: DS-PWA32 Series Wireless Security Control Panel
1. Extended the parameter message of a specific wireless hotspot XML_accessPoint (related
   URL: /ISAPI/System/Network/interfaces/<ID>/wireless/accessPointList/<ID> ):
   added a node <connecting> (whether the device is connecting to the Wi-Fi).
2. Extended the device capability message XML_DeviceCap (related URL: /ISAPI/System/
   capabilities ):
   added a node <isSupportModuleLock> (whether to support locking the module).
3. Extended the log types Log Types for ISAPI :
   added four alarm log types: "wirelessKeypadTamperEvident" (Wireless Keypad Tampered),
   "wirelessKeypadTamperEvidentReset" (Wireless Keypad Tamper Restored),
   "wirelessCardReaderTamperEvident" (Wireless Card Reader Tampered), and
   "wirelessCardReaderTamperEvidentReset" (Wireless Card Reader Tamper Restored);

  added 12 exception logs: "wirelessKeypadOffline" (Wireless Keypad Disconnected),
  "wirelessKeypadOnline" (Wireless Keypad Connected), "wirelessCardReaderOffline" (Wireless
  Card Reader Disconnected), "wirelessCardReaderOnline" (Wireless Card Reader Connected),
  "keypadLowPower" (Low Keypad Battery), "keypadLowPowerRecovery" (Low Keypad Battery
  Recovered), "cardReaderLowPower" (Low Card Reader Battery),
  "cardReaderLowPowerRecovery" (Low Card Reader Battery Recovered), "wKeypadOvertime"
  (Wireless Keypad Heartbeat Timed Out), "wKeypadOvertimeRecovery" (Wireless Keypad
  Heartbeat Timeout Recovered), "wCardReaderOvertime" (Wireless Card Reader Heartbeat
  Timed Out), and "wCardReaderOvertimeRecovery" (Wireless Card Reader Heartbeat Timeout
  Recovered).

Summary of Changes in Version 2.0_May, 2019
Related Products: DS-K2600 Series Access Controller in Version 2.1.0
1. Extended device information message XML_DeviceInfo (related URL: /ISAPI/System/
   deviceInfo ):
   added a device type "ACS" to the node <deviceType>;
   added three nodes <relayNum> (number of local relays), <electroLockNum> (number of local
   electronic locks), and <RS485Num> (number of local RS-485).
2. Added two URLs for upgrading peripherals firmware:
   Get capability: GET /ISAPI/System/AcsUpdate/capabilities .
   Upgrade firmware: PUT or POST /ISAPI/System/updateFirmware?type=&id= .
3. Extended the remote permission message XML_remotePermission (related URL: /ISAPI/
   Security/UserPermission/<ID> ):
   added four nodes <factoryReset> (restore default parameters), <arm> (arm), <disarm>
   (disarm), and <accessControl> (access control).
4. Added the URLs to configure security mode level of the private protocol:
   Get the configuration capability: GET /ISAPI/Security/CommuMode/capabilities?format=json ;
   Get the parameters: GET /ISAPI/Security/CommuMode?format=json ;
   Set the parameters: PUT /ISAPI/Security/CommuMode?format=json .
5. Extended configuration capability message of EHome server access XML_Cap_EHome (related
   URL: /ISAPI/System/Network/Ehome/capabilities ):
   added two nodes: <id> (center ID) and <GPRSAddressingFormatType> (GPRS address type);
   added a protocol version "v2.6" to the node <protocolVersion>.
6. Extended the EHome server access configuration URL:
   added centerID query parameter to the EHome server access configuration URL: /ISAPI/
   System/Network/Ehome?centerID= .
7. Extended EHome server access parameter message XML_Ehome (related URLs: /ISAPI/System/
   Network/Ehome?centerID= and /ISAPI/System/Network/Ehome ):
   added a protocol version "v2.6" to the node <protocolVersion>.
8. Add the URLs to configure the report uploading method:
   Get the configuration capability of the report uploading method: GET /ISAPI/SecurityCP/
   ReportCenterCfg/capabilities?format=json ;

   Get the parameters of the report uploading method: GET /ISAPI/SecurityCP/ReportCenterCfg/
   <ID>?format=json ;
   Set the report uploading method: PUT /ISAPI/SecurityCP/ReportCenterCfg/<ID>?format=json .
9. Extended device capability message XML_DeviceCap (related URL: /ISAPI/System/capabilities ):
   added two nodes <isSupportAcsUpdate> (whether to support upgrading slave access control
   device) and <isSupportAccessControlCap> (whether to support access control capability).
10. Extended event/alarm subscription capability message XML_SubscribeEventCap and
    subscription parameter message XML_SubscribeEvent (related URLs: /ISAPI/Event/
    notification/subscribeEventCap and /ISAPI/Event/notification/subscribeEvent ):
    added four nodes <minorAlarm> (minor alarm type), <minorException> (minor exception
    type), <minorOperation> (minor operation type), and <minorEvent> (minor event type) to the
    node <EventList>.
11. Extended subscription response message XML_SubscribeEventResponse (related URL: /ISAPI/
    Event/notification/subscribeEvent ):
    added four nodes <minorAlarm> (minor alarm type), <minorException> (minor exception
    type), <minorOperation> (minor operation type), and <minorEvent> (minor event type) to the
    node <FailedEventList>.
12. Added a sub status code 0x60001024-"eventNotSupport" (event subscription is not supported)
    to status code 6 (Invalid Message Content) in Error Codes in ResponseStatus .

Summary of Changes in Version 2.0_May, 2019
Related Products: DS-2CD50 Series and DS-2CD70 Series Box Camera with Software Version 5.6.0;
DS-2CD51 Series, DS-2CD55 Series, DS-2CD71 Series, and DS-2CD75 Series Dome Camera with
Software Version 5.6.0; DS-2CD7A Series and DS-2CD5A Series Bullet Camera with Software Version
5.6.0
1. Added the URL to search for security logs: POST /ISAPI/ContentMgmt/security/logSearch .
2. Added the URLs to configure log server:
   Get capability: GET /ISAPI/System/logServer/capabilities ;
   Get parameter: GET /ISAPI/System/logServer ;
   Set parameter: PUT /ISAPI/System/logServer .
3. Added the URL to perform log server test: POST /ISAPI/System/logServer/test .
4. Extended security capability message XML_SecurityCap (related URL: /ISAPI/Security/
   capabilities ): added a node <isSupportDeviceCertificatesManagement> (whether supports
   device certificate management).
5. Added the URL to get the capability of searching device certificates in batch: GET /ISAPI/
   Security/deviceCertificate/certificates?format=json .
6. Added the URL to get the status of a device certificate or all certificates:
   For a certificate: GET /ISAPI/Security/deviceCertificate/certificates/<ID>/status?format=json ;
   For all certificates: GET /ISAPI/Security/deviceCertificate/certificates/status?format=json .
7. Added the URLs to regenerate an abnormal certificate or all abnormal certificates:
   For an abnormal certificate: PUT /ISAPI/Security/deviceCertificate/certificates/<ID>/recreate?
   format=json ;

   For all abnormal certificates: PUT /ISAPI/Security/deviceCertificate/certificates/recreate?
   format=json .
8. Added the following certificate related and HDD formatting related error codes to the major
   error type of invalid operation, refer to Error Codes in ResponseStatus for details: 0x40002036
   (noClientCertificate), 0x40002037 (noCACertificate), 0x40002038 (authenticationFailed),
   0x40002039 (clientCertificateExpired), 0x4000203A (clientCertificateRevocation), 0x4000203B
   (CACertificateExpired), 0x4000203C (CACertificateRevocation), 0x4000203D (connectFail),
   0x4000203F (loginNumExceedLimit), and hdFormatFail.
9. Extended steaming channel capability message ( XML_Cap_StreamingChannel ) and streaming
   channel parameter message ( XML_StreamingChannel ) (related URLs: /ISAPI/Streaming/
   channels/<ID>/capabilities and /ISAPI/Streaming/channels/<ID> ):
   added a sub node <FecInfo> (FEC information) to the node <Multicast>.
10. Added a URL of RTSP to start and stop multicast based on NPQ (Network Protocol Quality):
    Request for getting basic parameters: DESCRIBE rtsp://<host>[:port]/ISAPI/Streaming/
    channels/<ID>?npq= ;
    Request for getting session information: SETUP rtsp://<host>[:port]/ISAPI/Streaming/
    channels/<ID>?npq= ;
    Start multicast: PLAY rtsp://<host>[:port]/ISAPI/Streaming/channels/<ID>?npq= ;
    Stop multicast: TEARDOW rtsp://<host>[:port]/ISAPI/Streaming/channels/<ID>?npq= .
11. Extended HDD management capability message ( XML_Cap_hddList ) and HDD parameter
    message ( XML_hdd ) (related URLs: /ISAPI/ContentMgmt/Storage/hdd/capabilities and /
    ISAPI/ContentMgmt/Storage/hdd/<ID> ):
    added a node <formatType> (HDD formatting type).
12. Extended the HDD formatting URL /ISAPI/ContentMgmt/Storage/hdd/<ID> :
    added a query parameter to the URL for specifying formatting type to format HDD: PUT /
    ISAPI/ContentMgmt/Storage/hdd/<ID>/format?formatType= .
13. Added an URL to format multiple specified HDDs in batch: PUT /ISAPI/ContentMgmt/
    Storage/hdd/specifyHddFormat?format=json .
14. Extended exposure parameter message XML_Exposure (related URL: /ISAPI/Image/channels/
    <ID>/exposure ):
    added an exposure type "pIris-General" to the node <ExposureType>;
    added a node <PIrisGeneral> (general iris configuration).
15. Extended event/alarm subscription capability message ( XML_SubscribeEventCap ) and
    subscription parameter message ( XML_SubscribeEvent ) (related URLs: /ISAPI/Event/
    notification/subscribeEventCap and /ISAPI/Event/notification/subscribeEvent ):
    added a node <identityKey> (subscription interaction command).

Summary of Changes in Version 2.0_May., 2019
Related Product Type: Thermal Network Bullet Camera; Thermal Bi-spectrum Network Bullet
Camera; Thermal & Optical Network Turret Camera; Thermal Box Camera V5.5.18
1. Extended the device capability XML_DeviceCap (request URL: GET /ISAPI/System/capabilities ):
   added four nodes <isSupportDisplayTrajectory> (whether supports displaying trajectory),
   <maximumSuperPositionTime> (the maximum time of trajectory displaying),

   <isSupportCalibrationFile> (whether supports importing calibration file), and
   <isSupportUnitConfig> (whether supports unit configuration).
2. Extended the audible warning configuration capability JSON_AudioAlarmCap (request URL:
   GET /ISAPI/Event/triggers/notifications/AudioAlarm/capabilities?format=json ):
   added one node <alarmType>; added three audible warning types to node <audioDescription>:
   13-"Temperature abnormality, please deal with it as soon as possible", 14-"Smoking is
   prohibited in this area", 15-"Fire detected, please deal with it as soon as possible".
3. Extended the audible warning parameters JSON_AudioAlarm (request URL: /ISAPI/Event/
   triggers/notifications/AudioAlarm?format=json ):
   added one node <alarmType>; added three audible warning types to node <audioID>:
   13-"Temperature abnormality, please deal with it as soon as possible", 14 -"Smoking is
   prohibited in this area", 15-"Fire detected, please deal with it as soon as possible".
4. Added one sub error code "unitConfigurationNotInEffect" (unit configuration is invalid) to 6-
   status code (invalid message content).
5. Added the function of unit unified configuration:
   Get the capability of unit unified configuration: GET /ISAPI/System/unitConfig/capabilities?
   format=json ;
   Get the unit unified configuration: GET /ISAPI/System/unitConfig?format=json ;
   Set the unit unified parameters: PUT /ISAPI/System/unitConfig?format=json .

Summary of Changes in Version 2.0_Mar., 2019
Related Product Type: DS-PWA32 Series Wireless Security Control Panel
1. Added the function of device diagnosis.
   Get the device diagnosis capability: GET /ISAPI/System/diagnosis/capabilities?format=json ;
   Diagnose the device: POST /ISAPI/System/diagnosis?format=json
2. Added the function of serial port log redirection.
   Get the configuration capability of serial port log redirection: GET /ISAPI/System/serialLogCfg/
   capabilities?format=json ;
   Get the redirection parameters of serial port log: GET /ISAPI/System/serialLogCfg?
   format=json ;
   Set the redirection parameters of serial port log: PUT /ISAPI/System/serialLogCfg?format=json
3. Added the function of exporting files from the device.
   Get the capability of exporting files from the device: GET /ISAPI/System/fileExport/
   capabilities?format=json ;
   Export files from the device: POST /ISAPI/System/fileExport?format=json
4. Extended the security capability XML_SecurityCap (related URL: GET /ISAPI/Security/
   capabilities ):
   added two nodes: <isSptUserEnabled> (whether to support configuration of enabling user) and
   <isSptAdminCap> (whether to support getting administrator permission capability).
5. Extended the user parameters XML_User (related URL: GET or PUT /ISAPI/Security/users/
   <ID> ):
   added one node: <enabled> (whether to enable the user); added a value "manufacturer" to the
   node <userLevel> (user level).

6. Extended the user permission capability XML_UserPermissionCap (related URL: GET /ISAPI/
   Security/UserPermission/operatorCap ) and user permission parameters XML_UserPermission
   (related URL: GET or PUT /ISAPI/Security/UserPermission/<ID> ):
   added two values "installer" and "manufacturer" to the node <userType> (user type);
   added five sub nodes <subSysOrZoneArm> (partition or zone arming permission),
   <subSysOrZoneDisarm> (partition or zone disarming permission), <subSysOrZoneClearArm>
   (permission to clear partition or zone alarms), <zoneBypass> (permission to bypass zone), and
   <zoneBypassRecover> (permission to recover bypassing zone) to the node
   <remotePermission>.
7. Added a URL to get administrator's permission capability: GET /ISAPI/Security/UserPermission/
   adminCap .
8. Extended the EHome server access configuration capability XML_Cap_EHome (related URL:
   GET /ISAPI/System/Network/Ehome/capabilities ) and EHome server access configuration
   parameters XML_Ehome (related URL: GET or PUT /ISAPI/System/Network/Ehome ):
   added one node <netWork> (network type).
9. Extended the configuration capability message of listening host servers
   XML_HttpHostNotificationCap (related URL: GET /ISAPI/Event/notification/httpHosts/
   capabilities ) and parameter message of a listening server XML_HttpHostNotification (related
   URL: POST /ISAPI/Event/notification/httpHosts ):
   added a value "EHome" to the node <protocolType> (protocol type).
10. Extended the device capability XML_DeviceCap (related URL: GET /ISAPI/System/
    capabilities ):
     added five nodes <isSptDiagnosis> (whether to support device diagnosis), <isSptSerialLogCfg>
     (whether to support configuring serial port log redirection), <isSptFileExport> (whether to
     support exporting files from the device), <isSptCertificationStandard> (whether to support
     configuring authentication standard for security control panel), and <isSptKeypadLock>
     (whether to support locking keypad).
11. Extended the response message XML_ResponseStatus :
     added one node <AdditionalErr> (additional error status information);
     added a value "9-Additional Error" to the node <statusCode> (status code);
     added a value "Additional Error" to the node <statusString> (status description).
12. Extended the response message JSON_ResponseStatus :
     added one node <AdditionalErr> (additional error status information)
13. Extended error codes (see details in Error Codes in ResponseStatus ):
     added a sub status code 0x10000005-"armProcess" (arming process) to status code 1 (OK);
     added two sub status codes: 0x4000801C-"inPaceTest" (pacing mode) and
     0x4000801D-"arming" (armed) to status code 4 (Invalid Operation).
14. Extended the log type :
     added 16 exception logs: "keyfobLowPower" (low keyfob battery), "keyfobPowerRecovery"
     (normal keyfob battery), "detectorOvertime" (detector heartbeat timed out),
     "detectorOvertimeRecovery" (detector heartbeat timeout restored), "wSirenOvertime"
     (wireless siren heartbeat timed out), "wSirenOvertimeRecovery" (wireless siren heartbeat
     timeout restored), "wOutputOvertime" (wireless output module heartbeat timed out),

   "wOutputOvertimeRecovery" (wireless output module heartbeat timeout restored),
   "wRepeaterOvertime" (wireless repeater heartbeat timed out), "wRepeaterOvertimeRecovery"
   (wireless repeater heartbeat timeout restored), "rfJamming" (RF wireless communication
   blocked), "rfJammingRecovery" (RF wireless communication blocking restored), "batteryMiss"
   (storage battery loss), "batteryMissRecovery" (storage battery restored), "ARCUploadFailed"
   (ARC uploading failed), and "ARCUploadRecovery" (ARC uploading restored); added 18
   operation logs: "armWithFault" (armed with fault), "entryDelay" (entering and exiting delay),
   "modArmConfig" (edit arming parameters), "modCertificateStandard" (edit authentication
   standard), "entryPaceTest" (pacing mode entered), "exitPaceTest" (pacing mode exited),
   "addNetOperator" (add operator), "modNetOperator" (edit operator information),
   "delNetOperator" (delete operator), "addNetInstaller" (add installer), "modNetInstaller" (edit
   installer information), "delNetInstaller" (delete installer), "addManufacturer" (add
   manufacturer), "modManufacturer" (edit manufacturer information), "delManufacturer"
   (delete manufacturer), "upgradeSuccessed" (upgraded), "upgradeFailed" (upgrading failed),
   and "zoneDisabled" (zone shielded); added five event logs: "keyPADlocked" (keypad locked),
   "keyPADunlocked" (keypad unlocked), "timeSynchronization" (time synchronization),
   "armFailed" (arming failed), and "ARCStart" (ARC connected).

Summary of Changes in Version 2.0_Mar., 2019
Related Product Type: Turing Series NVR V4.2.10
1. Extended the device capability XML_DeviceCap (related URL: GET /ISAPI/System/capabilities ):
   added six node <isSupportAutoMaintenance> (whether supports automatic maintenance),
   <isSupportTimeCap> (whether supports time capability), <isSupportIntelligentSearch>
   (whether supports intelligent search), <IOTCap> (IoT device access capability),
   <isSupportChannelFullEventListCap> (whether supports getting event capabilities of all
   channels) and <isSupportAUXInfoCap> (whether supports getting attributes capabilities of all
   channels)
2. Extended the device capability set XML_RacmCap (related URL: GET /ISAPI/ContentMgmt/
   capabilities ):
   added three nodes <isSupportCountingSearchByUTC> (whether supports whether supports
   UTC for people counting statistics search), <isSupportPlaybackReverseByUTC> (whether
   supports UTC for playback by time), <recordSearchType> (video file search condition)
3. Extended the device video capability set XML_VideoCap (related URL: GET /ISAPI/System/
   Video/capabilities ):
   added four nodes <isSupportCounting>, <isSupportMultiChannelCounting> (whether supports
   people counting of multiple channels), <isSupportCountingCollection> (whether supports
   people counting data replenishment), and <isSupportHeatmapCollection> (whether supports
   heat map data replenishment).
4. Extended the network capability sets XML_NetworkCap (related URL: GET /ISAPI/System/
   Network/capabilities ) :
   added two nodes <isSupportPOEConfiguration> (whether supports PoE port configuration),
   <EZVIZSecretKey> (whether supports editing verification code for Hik-Connect).
5. Added the function of PoE configuration.

   Get PoE port configuration capability: GET /ISAPI/System/Network/POE/capabilities?
   format=json ;
   Get PoE port parameters: GET /ISAPI/System/Network/POE?format=json ;
   Set PoE port: PUT /ISAPI/System/Network/POE?format=json .
6. Extended the access protocol XML_AdminAccessProtocol (related URL: GET: /ISAPI/Security/
   adminAccesses/<ID> ):
   added three protocols to node <protocol>: "IoT", "TLS1_1Enable", "TLS1_2Enable".
7. Added the function of automatic maintenance.
   Get the capability of automatic maintenance configuration: GET /ISAPI/System/
   autoMaintenance/capabilities?format=json ;
   Get automatic maintenance configuration parameters: GET /ISAPI/System/autoMaintenance?
   format=json ;
   Set automatic maintenance: PUT /ISAPI/System/autoMaintenance?format=json .
8. Extended the time capability of device XML_Cap_Time (related URL: GET /ISAPI/System/time/
   capabilities ):
   added one node <timeType> (time type).
9. Added the function of IP address/MAC address filter configuration:
   Get IP address configuration capability: GET /ISAPI/System/Network/ipFilter/capabilities ;
   Get/Set the IP address filter configuration parameters: GET/PUT /ISAPI/System/Network/
   ipFilter ;
   Get MAC address configuration capability: GET /ISAPI/System/Network/MACFilter/
   capabilities ;
   Get/Set the MAC address filter configuration parameters: GET/PUT /ISAPI/System/Network/
   MACFilter .
10. Extended the log type Log Types for ISAPI :
    added two log types: "doubleVerificationPass" (doubel verification completed) and
    "eventUploadException" (uploading event failed or uploaded event lost); added one operation
    log: "localAddressFilterConfig/remoteAddressFilterConfig" (local/remote address filter
    configuration); added one minor alarm type: "securityControlPanelEvent" (security control
    panel event).
11. Extended the I/O capability XML_IOCap (related URL: GET /ISAPI/System/IO/capabilities ):
    added one node <isSupportCombinationAlarm> (whether supports composite alarm).
12. Extended the alarm input configuration capability XML_Cap_IOInputPortList (reltaed URL:
    GET /ISAPI/System/IO/inputs/capabilities ):
    added one node <CombinationAlarmCap> (composite alarm capability).
13. Extended the alarm input parameters XML_IOInputPort (related URL: GET /ISAPI/System/IO/
    inputs/<ID> ):
    added two nodes <IODescriptor> (I/O port description) and <CombinationAlarm> (composite
    alarm list).
14. Extended the device security capability XML_SecurityCap (related URL: GET /ISAPI/Security/
    capabilities ):
    added one node <DoubleVerificationCap> (double verification capability).
15. Added the function of double verification, see details in Configure Double Verification .

16. Extended the local permission XML_localPermission :
    added two nodes <playBackDoubleVerification> (whether supports double verification for
    playback) and <backupDoubleVerification> (whether supports double verification for backup).
17. Extended the remote permission XML_remotePermission :
    added one node <playBackDoubleVerification> (whether supports double verification for
    playback and download).
18. Extended the file download condition XML_downloadRequest :
    added two nodes <userName> (double verification user name), <password> (double
    verification password).
19. Extended error codes (see details in Error Codes in ResponseStatus ):
    added six sub status codes: 0x60001034-invalidEZVIZSecretKey (invalid verification code for
    Hik-Connect), 0x60001042- needDoubleVerification (double verification required),
    0x60001043-noDoubleVerificationUser (no double verification user), 0x60001044-
    timeSpanNumOverLimit (max. number of time buckets reached), 0x60001045-
    channelNumOverLimit (max. number of channels reached), and 0x60001046-
    noSearchIDResource(insufficient searchID resources) to status code 6 (Invalid Message
    Content).
20. Added the data replenishment function, including people counting, heat map, temperature,
    and vehicle detection. Refer to Data Replenishment for details.
21. Extended the network camera information XML_InputProxyChannel :
    added three nodes <deviceTypeName> (device type name), <serialNumber> (device serial
    No.), and <firmwareVersion> (firmware code).
22. Extended the event/alarm subscription capability XML_SubscribeEventCap and event/alarm
    subscription messsage XML_SubscribeEvent :
    added one node: <pictureURLType> (alarm picture format).
23. Extended the device online upgrade capability XML_OnlineUpgradeCap :
    added one node <isSupportTimingUpgrade> (whether supports scheduled upgrade).
24. Extended the online upgrade parameters JSON_OnlineUpgradeParameter :
    added two parameters "timingUpgrade" (enable scheduled upgrade or not) and
    "upgradeTime" (upgrade time).
25. Added the function of IoT device access, for details refer to IoT Devices Access .
26. Extended the Hik-Connect access configurations XML_EZVIZ :
    added one node <offlineStatus> (device offline status).
27. Added the function of editing verification code for Hik-Connect:
    Request URL: PUT /ISAPI/System/Network/EZVIZ/secretKey?format=json .

Summary of Changes in Version 2.0_Feb., 2019
Related Product Type: Security Radar with Model DS-PR1-60
1. Added URL to set SSH server for access: /ISAPI/System/Network/ssh , refer to Network Access
   for details.
2. Extended network capability ( XML_NetworkCap , related URL: GET /ISAPI/System/Network/
   capabilities ):
   added a node <isSupportEhome> (whether supports EHome protocol).

Summary of Changes in Version 2.0_Jan., 2019
Related Product Type: Speed Dome V5.6.0 (H3)
1. Extended PTZ channel capability ( XML_PTZChanelCap , related URL: GET /ISAPI/PTZCtrl/
   channels/<ID>/capabilities ):
   added two nodes <pqrsZoom> (zooming coordinates of Sony zoom camera module) and
   <mnstFocus>(focus coordinates of Sony zoom camera module).
2. Added URL to configure zoom and focus coordinates for Sony zoom camera module: /ISAPI/
   PTZCtrl/channels/<ID>/zoomFocus .
3. Added URL to configure OSD language: /ISAPI/System/Video/inputs/OSDLanguage
4. Extended wireless configuration capability ( XML_Cap_Wireless , related URL: GET /ISAPI/
   System/Network/interfaces/<ID>/wireless/capabilities ):
   added node <isSupportNullSsid> (whether supports setting SSID to null).
5. Extended streaming channel capability ( XML_Cap_StreamingChannel , related URL: /ISAPI/
   Streaming/channels/<ID>/capabilities ):
   edited the minimum values of sub nodes <videoDestPortNo> and <audioDestPortNo> to "1"
   and added default values (8860) for these two nodes;
   added two sub nodes <activeMulticastEnabled> (whether to enable active multicast) and
   <packagingFormat> (container format) to the node <Multicast>.
6. Extended streaming channel parameter message ( XML_StreamingChannel , related URL: /
   ISAPI/Streaming/channels/<ID> ): added two sub nodes <activeMulticastEnabled> (whether to
   enable active multicast) and <packagingFormat> (container format) to the node <Multicast>.
7. Extended network access protocol capability and configuration message( and
   XML_AdminAccessProtocol , related URLs: /ISAPI/Security/adminAccesses/capabilities and /
   ISAPI/Security/adminAccesses/<ID> ):
   added a value "SDK_OVER_TLS" to the node <protocol> (protocol type);
   added three nodes <TLS1_0Enable> (whether to enable TLS v1.0), <TLS1_1Enable> (whether to
   enable TLS v1.1), and <TLS1_2Enable> (whether to enable TLS v1.2).
8. Extended UDnP interface configuration message ( XML_port , related URL: /ISAPI/System/
   Network/UPnP/ports/<ID> ) and mapping status message ( XML_portStatus , related URL: /
   ISAPI/System/Network/UPnP/ports/<ID>/status ):
   added a value "SDK_OVER_TLS" to the node <internalPort> (internal interface).
9. Added URL to get the socket IP of current connection: GET /ISAPI/System/Network/socketIP .
10. Extended alarm linkage capability ( XML_EventTriggersCap , related URL: GET /ISAPI/Event/
    triggersCap ):
    added two nodes <isSupportWhiteLightAction> (whether supports supplement light alarm
    linkage) and <isSupportAudioAction> (whether supports audible warning linkage).
11. Extended alarm linkage capability type ( XML_EventTriggerCapType ):
    added two node <isSupportBeep> (whether supports audible warning linkage) and
    <isSupportWhiteLight> (whether supports supplement light alarm linkage).
12. Extended alarm linkage action message ( XML_EventTriggerNotification ):
    added two linkage actions to the node <notificationMethod>, i.e., "beep"-audible warning and
    "whiteLight"-supplement light.

13. Added URLs to get configuration capability and configure parameters of supplement light
    alarm output:
    Get Capability: GET /ISAPI/Event/triggers/notifications/whiteLightAlarm/capabilities?
    format=json ;
    Get Parameter: GET /ISAPI/Event/triggers/notifications/whiteLightAlarm?format=json ;
    Set Parameter: PUT /ISAPI/Event/triggers/notifications/whiteLightAlarm?format=json .
14. Added URLs to get configuration capability and configure parameters of audible warning alarm
    output:
    Get Capability: GET /ISAPI/Event/triggers/notifications/AudioAlarm/capabilities?
    format=json ;
    Get Parameter: GET ;
    Set Parameter: PUT .
15. Extended dynamic capability ( XML_DynamicCap , related URL: /ISAPI/Streaming/channels/
    <ID>/dynamicCap ):
    added a audible prompt type, i.e., "prompt25" to the nodes <smart264EnabledPrompt>
    (audible prompt for Smart264 enabled) and <smart265EnabledPrompt> (audible prompt for
    Smart265 enabled).
16. Extended video capability ( XML_VideoCap , related URL: GET /ISAPI/System/Video/
    capabilities ):
    added nodes <OSDLanguage> (OSD language), <channelFlexible> (capability of getting channel
    status by condition).
17. Extended device capability ( XML_DeviceCap , related URL: GET /ISAPI/System/capabilities ):
    added nodes <isSupportActiveMulticast> (whether supports active multicast),
    <isSupportGetLinkSocketIP> (whether supports getting the socketIP of current connection),
    <isSupportChangedUpload> (whether supports uploading status changes),
    <isSupportSimpleDevStatus> (whether supports getting device working status),
    <isSupportFlexible> (whether supports getting channel status by condition), and
    <isSupportTimeCap> (whether supports time configuration).
18. Extended time configuration capability ( XML_Cap_Time , related URL: GET ):
    added node <timeType> (time type, local or UTC time).
19. Added the function of alarm/event subscription, refer to Subscribe Alarm/Event in Arming
    Mode for details.

Summary of Changes in Version 2.0_Jan., 2019
Related Product Type: AX Panel
1. Extended the security capability XML_SecurityCap :
   added four nodes: <keypadPassword> (keypad password length), <installerKeypadPassword>
   (installer's keypad password length), <operatorKeypadPassword> (operator's keypad password
   length), and <userOperateType> (user operation type).
2. Extended the user parameters XML_User :
   added one node: <userOperateType> (user operation type).
3. Extended the search result parameters for log files XML_CMSearchResult :

   added three nodes: <object> (operation object), <params> (parameters), and <seq> (serial No.)
   to <logDescriptor>.
4. Added an error code to : 0x4000801B-"inProgramMode" (The keypad is in programming mode).
5. Added two minor log types to operation logs in Log Types for ISAPI : "enterProgramMode"-The
   keypad programming mode is enabled; "existProgramMode"-The keypad programming mode is
   disabled.

Summary of Changes in Version 2.0_Dec., 2018
Related Product Type: Thermal Network Bullet Camera; Thermal Bi-spectrum Network Bullet
Camera; Thermal & Optical Network Dome Camera V5.5.16
Related Product Model: DS-2TD21xx/V1 series, DS-2TD21xx/VP series, DS-2TD26xx series,
DS-2TD26xx/V1 series, DS-2TD28xx series, DS-2TD28xx/V1 series, DS-2TD12xx/V1 series
1. Extended the alarm output capability XML_IOOutputPortList and alarm output port parameters
   XML_IOOutputPort :
   added one node normalStatus (normal status).
2. Added one URL of getting I/O output capability: /ISAPI/System/IO/outputs/capabilities

Summary of Changes in Version 2.0_Oct., 2018
Related Product Type: Thermographic Automation Thermal Camera with Models DS-2TA03-15SVI
and DS2TA06-25SVI
1. Added the function of lens correction:
   Get capability of lens correction configuration: GET /ISAPI/PTZCtrl/channels/<ID>/
   lensCorrection/capabilities?format=json
   Get lens correction configuration parameters: GET /ISAPI/PTZCtrl/channels/<ID>/
   lensCorrection?format=json
   Set lens correction: PUT /ISAPI/PTZCtrl/channels/<ID>/lensCorrection?format=json
2. Extended the PTZ control capability XML_PTZChanelCap :
   added one node <isSupportLensCorrection> (whether supports lens correction).
3. Extended the attributes of specific channel XML_ChannelInfo :
   added two nodes: <PanoramaCamera>, <GlobalCamera>, added three sub nodes
   <LensCorrection> (lens correction), <BurningPrevention> (burning prevention) to <thermal> .

Summary of Changes in Version 2.0_Sept., 2018
Related Product Type: Network Thermographic Automation Camera DS-2TA03-4AUM
Extended the focus parameters configuration XML_FocusConfiguration : added two nodes
<focusStyle> (focus type) and <relativeFocusPos> (relative focus value).
