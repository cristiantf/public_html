# Chapter 6 Device Maintenance


6.1 Basic

Shut Down, Reboot and Restore to Default Settings
• Shut down device
  Request URL: PUT /ISAPI/System/shutdown?format=json
• Reboot device
  Request URL: PUT /ISAPI/System/reboot
• Restore device to default settings
  Request URL: PUT /ISAPI/System/factoryReset?mode=

Upgrade
• Get upgrade capability of peripherals' firmwares
  Request URL: GET /ISAPI/System/AcsUpdate/capabilities
• Upgrade device's firmware
  Request URL: PUT or POST /ISAPI/System/updateFirmware
• Upgrade slave device's firmware
  Request URL: PUT or POST /ISAPI/System/updateFirmware?type=&id=
• Upgrade peripheral module's firmware
  Request URL: PUT or POST /ISAPI/System/updateFirmware?type=&moduleAddress=
• Get device upgrading status
  Request URL: GET /ISAPI/System/upgradeStatus

Configuration File
• Get capability of exporting files from device
  Request URL: GET /ISAPI/System/fileExport/capabilities?format=json
• Securely export files from device
  Request URL: POST /ISAPI/System/fileExport?format=json

       Note
  To check if exporting files from device is supported by the device, you can call GET /ISAPI/
  System/capabilities to get the device capability ( XML_DeviceCap ). If supports, the node
  <isSptFileExport> will be returned.

Algorithm Version
Get algorithm version information of device
Request URL: GET /ISAPI/System/algorithmsVersion

6.1.1 Securely Export and Import Configuration Files
You can export configuration files of devices to back up basic device parameters (such as network
parameters, stream parameters, etc.) timely, and the configuration files will be encrypted with the
encryption key when being exported. If several devices adopt the same configuration, you can
import configuration files to configure multiple devices in a batch. The devices will decrypt the
encrypted configuration file using the encryption key which ensures that the configuration file
cannot be used by unauthorized devices.
Steps

        Figure 6-1 Programming Flow of Securely Exporting and Importing Configuration Files
1. Call GET /ISAPI/Security/capabilities to get the device security capability for checking whether
   the device supports securely exporting configuration files.
   The device security capability is returned in the message XML_SecurityCap .
   If this function is supported by the device, the node <isSupportConfigFileExport> will be
   returned and its value is "true", then you can perform the following steps.
   Otherwise, please end this task.
2. Call GET /ISAPI/System/configurationData?secretkey= to export the configuration file from the
   device securely.

        Note
   The query parameter secretKey is the sensitive information that should be encrypted for
   transmission, and the parameter range to be encrypted is determined by the attributes "min"
   and "max" of the node <cfgFileSecretKeyLenLimit> in message XML_SecurityCap . For details
   about encrypting sensitive information, refer to Encrypt Sensitive Information .
3. Call GET /ISAPI/Security/capabilities to get the device security capability for checking whether
   the device supports securely importing configuration files.
   The device security capability is returned in the message XML_SecurityCap .
   If this function is supported by the device, the node <isSupportConfigFileImport> will be
   returned and its value is "true", then you can perform the following steps.
   Otherwise, please end this task.
4. Call PUT /ISAPI/System/configurationData?secretkey= to import the configuration file to the
   device securely.

        Note
   • The query parameter secretKey is the sensitive information that should be encrypted for
     transmission, and the parameter range to be encrypted is determined by the attributes "min"
     and "max" of the field <cfgFileSecretKeyLenLimit> in the message XML_SecurityCap . For
     details about encrypting sensitive information, refer to Encrypt Sensitive Information .
   • The value of secretKey for importing the configuration file should be the same as that for
     exporting the file. Otherwise, importing will fail.

6.2 Log

Log Search
• Search for logs
  Request URL: POST /ISAPI/ContentMgmt/logSearch
• Export log files
  Request URL: POST /ISAPI/ContentMgmt/logSearch/dataPackage

Serial Port Log Redirection
• Get configuration capability of serial port log redirection
  Request URL: GET /ISAPI/System/serialLogCfg/capabilities?format=json
• Get or set parameters of serial port log redirection
  Request URL: GET or PUT /ISAPI/System/serialLogCfg?format=json

     Note
To check if configuring serial port log redirection is supported by the device, you can call GET /
ISAPI/System/capabilities to get the device capability ( XML_DeviceCap ). If supports, the node
<isSptSerialLogCfg> will be returned.

Log Configuration
• Get log configuration capability
  Request URL: GET /ISAPI/ContentMgmt/logConfig/capabilities
• Get or set log parameters
  Request URL: GET or PUT /ISAPI/ContentMgmt/logConfig

6.3 Status
• Get device status capability
  Request URL: GET /ISAPI/System/workingstatus/capabilities?format=json
• Get all statuses of device
  Request URL: GET /ISAPI/System/workingstatus?format=json
• Channel Status
  • Get status(es) of all channels or one channel
    Request URL: GET or POST /ISAPI/System/workingstatus/chanStatus?format=json
  • Get statuses of all channels by condition
    Request URL: POST /ISAPI/System/Video/inputs/channels?format=json
  • Get status of one channel by condition
    Request URL: POST /ISAPI/System/Video/inputs/channels/<ID>?format=json

         Note
    To check if getting channel status by condition is supported by device, you can call GET /ISAPI/
    System/capabilities to get the device capability ( XML_DeviceCap ). If supports, the node
    <isSupportFlexible> will be returned.

• Get status(es) of all HDDs or one HDD
  Request URL: GET or POST /ISAPI/System/workingstatus/hdStatus?format=json
• Get triggered I/O status
  Request URL: GET /ISAPI/System/workingstatus/IOStatus?format=json
• Get CPU and memory status
  Request URL: GET /ISAPI/System/status
• Upload status changes
  Refer to Subscribe Alarm/Event in Arming Mode for integration process of uploading device
  status changes, and the node <type> in the request message XML_SubscribeEvent for the URLs
  (POST /ISAPI/Event/notification/subscribeEvent and PUT /ISAPI/Event/notification/
  subscribeEvent/<ID> ) should be set to "statusChanged".

  The changes details can be obtained by calling the URL GET /ISAPI/Event/notification/
  alertStream .

        Note
  To check if getting device status and uploading status changes are supported by device, you can
  call GET /ISAPI/System/capabilities to get the device capability ( XML_DeviceCap ). If supports,
  the nodes <isSupportSimpleDevStatus>, <isSupportSimpleDevStatus>, and
  <isSupportChangedUpload> will be returned and their values are "true".

6.4 Calibration

Accelerometer Zero Bias Calibration
• Get device capability to check if device supports accelerometer zero bias calibration
  Request URL: GET /ISAPI/System/capabilities ; the device capability is returned in the message
  XML_DeviceCap .
  If supports, the node <isSupportZeroBiasCalibration> is returned in the message
  XML_DeviceCap and its value is "true".
• Calibrate accelerometer zero bias
  Request URL: PUT /ISAPI/System/zeroBiasCalibration/channels/<ID>?format=json

Installation Angle Calibration
• Get the device capability to check if device supports installation angle calibration
  Request URL: GET /ISAPI/System/capabilities ; the device capability is returned in the message
  XML_DeviceCap .
  If supports, the node <isSupportInstallationAngleCalibration> is returned in the message
  XML_DeviceCap and its value is "true".
• Get capability of installation angle calibration
  Request URL: GET /ISAPI/System/installationAngleCalibration/channels/<ID>/capabilities?
  format=json
• Get installation angle calibration status or calibrate installation angle
  Request URL: GET or PUT /ISAPI/System/installationAngleCalibration/channels/<ID>?
  format=json

6.5 Advanced

Automatic Maintenance
• Get configuration capability of automatic maintenance
  Request URL: GET /ISAPI/System/autoMaintenance/capabilities?format=json
• Get or set parameters of automatic maintenance
  Request URL: GET or PUT /ISAPI/System/autoMaintenance?format=json

     Note
To check if the device supports automatic maintenance, you can call the request URL: GET /ISAPI/
System/capabilities to get the device capability ( XML_DeviceCap ). If supports, the node
<isSupportAutoMaintenance> will be returned.

Device Diagnosis
• Get device diagnosis capability
  Request URL: GET /ISAPI/System/diagnosis/capabilities?format=json
• Diagnose device
  Request URL: POST /ISAPI/System/diagnosis?format=json

     Note
To check if configuring device diagnosis is supported by the device, you can call GET /ISAPI/
System/capabilities to get the device capability ( XML_DeviceCap ). If supports, the node
<isSptDiagnosis> will be returned.

Device Anti-Theft
• Get device anti-theft configuration capaiblity
  Request URL: GET /ISAPI/System/guardAgainstTheft/capabilities
• Get or set device anti-theft parameters
  Request URL: GET or PUT /ISAPI/System/guardAgainstTheft

     Note
To check if the anti-theft configuration is supported by the device, you can call GET /ISAPI/System/
capabilities to get the device capability ( XML_DeviceCap ). If this function is supported, the node
<isSupportGuardAgainstTheft> will be returned and its value is "true".
