# Chapter 5 Device Management

This chapter lists the request URLs for getting device information, managing network cameras,
getting the capabilities of network cameras, and so on.
• Get device capability
  Request URL: GET /ISAPI/System/deviceInfo/capabilities
• Get device information
  Request URL: GET /ISAPI/System/deviceInfo

5.1 Device Activation

5.1.1 Directly Activate Device
For the connected devices, you must activate them to make sure the device password is
reconfigured and the password string conforms to the security rule.

Steps

                          Figure 5-1 Direct Activation Sequence Diagram
1. Client software generates public and private key.

       Note
  The size of public key is 1024 bits (128 bytes). When transforming to the hexadecimal string,
  each byte corresponds to two characters (e.g., 127 → FF ), so the public key is transformed to a
  256-byte string finally.
2. Client software encodes the public key (a 256-byte string) by Base64 method and sends it to
   device.
3. Device decodes the encoded public key by Base64 method and generates random strings.
4. Device encrypts the random strings based on RSA algorithm and encodes the encrypted strings
   by Base64 method.
5. Client software gets the encrypted and encoded random strings via the URL: POST /ISAPI/
   Security/challenge .
6. Client software decodes the obtained random strings by Base64 method and decrypts the
   random strings by using private key.

7. Client software encrypts the activation password with the random strings in AES128 CBC mode
   and encodes the password by Base64 method.
8. Client software sends the activation password strings to device via the URL: PUT /ISAPI/System/
   activate .

       Note
  The sent activation password strings consist of first 16 characters of random strings and actual
  password.
   Example
   If the first 16 characters of random strings is "aaaabbbbccccdddd", and the actual password is
   "Abc12345", the encrypted activation password strings is "aaaabbbbccccddddAbc12345".
9. Device decodes the activation password by Base64 method and decrypts the password with the
   random string in AES128 CBC mode for verification.
10. Device starts activating and sends the activation result to client software.

5.1.2 Activate Network Camera via NVR
For network devices, except directly activating them, you can also activate them via NVR if they can
be searched on the same network domain of NVR.
Steps
1. Call /ISAPI/ContentMgmt/InputProxy/search by GET method to search for the online network
   devices in the same network domain with the NVR.
2. Optional: Call /ISAPI/ContentMgmt/InputProxy/channels/activate/capabilities by GET
   method to get the activation capability of network devices for reference.
3. Call /ISAPI/ContentMgmt/InputProxy/channels/activate by PUT method to activate the
   searched online devices via NVR.

5.2 Reset Password by Setting Recovery Email
A recovery email is added or configured for resetting the password as required. The admin user can
set a recovery email after activating the device, and then receive the verification code from the
manufacturer via the recovery email to reset the device password.
Before You Start
Make sure you have activated the device.

Steps

         Figure 5-2 Programming Flow of Resetting Password by Setting Recovery Email

      Note
You can reset password by other methods, such as answering security question, importing GUID
files, and so on. But all methods should be supported by device, so you should call the request
URL: GET /ISAPI/Security/extern/capabilities to get the other security capability
( XML_externSecurityCap ) before choosing method to reset password.
1. Check if the device supports setting recovery email by the request URL: GET /ISAPI/Security/
   capabilities .
   The security capability is returned in the message XML_SecurityCap .
   If the node <isSupportSecurityEmail> exits in the returned message and its value is "true", it
   indicates that setting recovery email is supported by the device, and you can continue to
   perform the following steps; otherwise, end this task.
2. Optional: Get recovery email configuration capability by the request URL: GET /ISAPI/Security/
   email/parameter/capabilities?format=json .

   The recovery email configuration capability is returned in the message JSON_SecurityEmailCap
   by the output parameter pointer (lpOutputParam).
3. Optional: Get the existing or configured recovery email parameters for reference by the request
   URL: GET /ISAPI/Security/email/parameter?format=json .
4. Set the recovery email for the device by the request URL: PUT /ISAPI/Security/email/
   parameter?format=json .
5. Get the QR code of the recovery email by the request URL: GET /ISAPI/Security/email/qrCode?
   format=json .
6. Send the QR code to manufacturer service email address by any other emails for verification.
7. Receive the verification code in the configured recovery email.
8. Enter the received verification code for resetting the device password by the request URL: PUT /
   ISAPI/Security/emailCertification?format=json .

5.3 Online Upgrade Device
For the devices that can connect to Guarding Vision Server, you can online upgrade their firmware
via Guarding Vision Client, and get the upgrade progress. Besides, in the condition of bad network,
you can also enable automatic download of upgrade package in the background to improve the
upgrade speed.
Before You Start
Make sure you have activated the device.

Steps

                    Figure 5-3 Programming Flow of Online Upgrade Device
1. Check if the device support online upgrade via the URL: GET /ISAPI/System/onlineUpgrade/
   capabilities .
   The online upgrade capability set is returned in XML_OnlineUpgradeCap .
2. Get the connection status of online upgrade server via the URL: GET /ISAPI/System/
   onlineUpgrade/server .

       Note
  Only when the node <connectStatus> is returned and values "true", you can go on for next step.
  Otherwise, you should end this task.
   The upgrade server connection status is returned in XML_OnlineUpgradeServer .
3. Optional: Set the device online upgrade parameters via the URL: PUT /ISAPI/System/
   onlineUpgrade/deviceParameter?format=json .

      Note
  Before setting the device online upgrade parameters, you can get these parameters via the URL:
  GET /ISAPI/System/onlineUpgrade/deviceParameter?format=json .
4. Get the new upgrade package information via the URL: GET /ISAPI/System/onlineUpgrade/
   version .
5. Download the upgrade package via the URL: PUT /ISAPI/System/onlineUpgrade/
   downloadPackage?format=json .
6. Optional: During downloading the upgrade package, you can perform the following operations.
     Pause Download         URL: PUT /ISAPI/System/onlineUpgrade/downloadPackage/pause?
                            format=json
     Resume Download        URL: PUT /ISAPI/System/onlineUpgrade/downloadPackage/resume?
                            format=json
     Cancel Download        URL: DELETE /ISAPI/System/onlineUpgrade/downloadPackage?
                            format=json
7. Get the upgrade package download progress via the URL: GET /ISAPI/System/onlineUpgrade/
   downloadPackage/status?format=json .
8. Start upgrade when the upgrade package is downloaded via the URL: PUT /ISAPI/System/
   onlineUpgrade/upgradeWithoutDownload?format=json .
9. Get the upgrade status via the URL: GET /ISAPI/System/onlineUpgrade/status .

5.4 IoT Devices Access
The IoT devices here include access control terminal, security control panel, video intercom, analog
camera RF, etc. The NVR/DVR supports accessing IoT devices for device management, status
search, event/alarm linkage, and alarm receiving. When the IoT devices are added to NVR/DVR, the
NVR/DVR can receive the alarm of IoT device, link the channel for recording, and receive the real-
time stream when alarm is triggered.
This chapter mainly introduces the methods of adding IoT devices, and configuring event/alarm of
IoT devices.

Application Scenario

5.4.1 Add IoT Devices to NVR/DVR
For convenient management of IoT device, such as status searching, event/alarm linkage, alarm
receiving, and so on, you should add the IoT device to NVR/DVR first.
Before You Start
Make sure you have logged in to the device.
Steps

                 Figure 5-4 Programming Flow of Adding IoT Device to NVR/DVR
1. Get the device capability by the URL: GET /ISAPI/System/capabilities to check if the IoT device
   access function is supported via the node <IOTCap>.
   The device capability XML_DeviceCap is returned.
2. Configure listening port before adding the OPTEX and Luminite IoT devices by the URL: PUT /
   ISAPI/Security/adminAccesses/<ID> , and set the value of <protocol> in
   XML_AdminAccessProtocol to "IOT".
3. Get the supported IoT devices types of device by the URL: GET /ISAPI/System/IOT/
   sourceSupport/capabilities?format=json .
   The supported IoT devices types are returned in JSON_IOTSourceSupport .

4. Get information of IoT devices which can be added by the URL: GET /ISAPI/System/IOT/search?
   format=json .
   The IoT devices which can be added is returned in JSON_IOTSourceList .
5. Get the number of IoT device channels which can be added by the URL: POST /ISAPI/
   System/IOT/sourceCapabilities?format=json .
   The supported source capability is returned in JSON_SourceCapabilities .
6. Optional: Get the information of added IoT devices.
   - Get the information of added IoT devices by the URL: GET /ISAPI/System/IOT/channels?
      format=json .
   - Get the information of added IoT devices according to inductive type by the URL: GET /ISAPI/
      System/IOT/channels?format=json&deviceInductiveType= .
7. Add the IoT device to NVR/DVR by the URL: POST /ISAPI/System/IOT/channels?format=json .
8. Set the basic parameters of added IoT device according to channel ID by the URL: PUT /ISAPI/
   System/IOT/channels/<ID>/basicParam?format=json .
9. Optional: Set the specified added IoT device according to channel ID by the URL: PUT /ISAPI/
   System/IOT/channels/<ID>?format=json .

       Note
  Before setting the specified IoT device, you can get the IoT device by the URL: GET /ISAPI/
  System/IOT/channels/<ID>?format=json .
10. Optional: Delete the added IoT device.
    - Delete the specified IoT channel by the URL: DELETE /ISAPI/System/IOT/channels/<ID>?
      format=json .
    - Delete all channels (video channel and IoT channel) of added IoT device by the URL: DELETE /
      ISAPI/System/IOT/channels/<ID>/all?format=json .
11. Get the status of added IoT device.
    - Get the status of added IoT device by the URL: GET /ISAPI/System/IOT/channels/status?
      format=json .
    - Get the status of added IoT device according to inductive type by the URL: GET /ISAPI/
      System/IOT/channels/status?format=json&deviceInductiveType= .
    - Get the status of specified channel of added IoT device by the URL: GET /ISAPI/System/IOT/
      channels/<ID>/status?format=json
12. Get the alarm statistics of added IoT device according to channel ID by the URL: GET /ISAPI/
    System/IOT/channels/<ID>/alarmStatistics?format=json
13. Optional: Get the linked channel informaiton of added IoT device by the URL: POST /ISAPI/
    System/accessDevice/associatedChannel?format=json
14. Optional: Import or export the list of added IoT devices.
       Import     Import the list of added IoT devices by the URL: PUT /ISAPI/System/IOT/
                  channelConfig?format=json
       Export     Export the list of added IoT devices by the URL: GET /ISAPI/System/IOT/
                  channelConfig?format=json

   Example
   PUT /ISAPI/System/IOT/channelConfig?format=json
   Accept: text/html, application/xhtml+xml,
   Accept-Language: us-EN
   Content-Type: File/ Opaque Data
   User-Agent: Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; WOW64; Trident/5.0)
   Accept-Encoding: gzip, deflate
   Host: 10.10.36.29:8080
   Content-Length: 9907
   Connection: Keep-Alive
   Cache-Control: no-cache
   Content-Disposition: form-data; name="XX";
   Content-Length: 9907

   ......JFIF.....`.`.....C........... .
   ..
   ................. $.’ “,#..(7),01444.’9=82<.342...C.   ....

5.4.2 Configure Alarm of IoT Device
When the IoT device is added to NVR/DVR, you can configure the alarm parameters such as arming
schedule, linkage method, OSD, and so on for receiving the alarm of IoT device.
Before You Start
• Make sure you have logged in to the device.
• Make sure the IoT device is added to NVR/DVR.

Steps

                Figure 5-5 Programming Flow of Configuring Alarm of IoT Device
1. Get the IoT device channel capability by the URL: GET /ISAPI/Event/IOT/channels/<ID>/
   capabilities?format=json .
   The event capability supported by IoT device channel is returned in
   JSON_IOTChannelEventCap .
2. Get the event/alarm linkage configuration capability of IoT device by the URL: GET /ISAPI/
   Event/triggersCap/IOT .
   The capability is returned in XML_IOTTriggersCap .
3. Get the event configuration capability by the URL: GET /ISAPI/System/IOT/channels/<ID>/
   <EventType>/capabilities?format=json .
   The event configuration capability is returned in JSON_XXCap .
4. Set the event/alarm parameters by the URL: PUT /ISAPI/System/IOT/channels/<ID>/
   <EventType>?format=json .
5. Set the arming schedule by the URL: PUT /ISAPI/Event/schedules/<EventType>/<ID>
6. Set the event/alarm linkage parameters by the URL: PUT /ISAPI/Event/triggers/<ID> .
7. Configure OSD.

   1) Get the OSD configuration capability by the URL: GET /ISAPI/System/IOT/channels/
      <ID>/OSD/capabilities?format=json .
   2) Get the OSD parameters by the URL: GET /ISAPI/System/IOT/channels/<ID>/OSD?
      format=json .
   3) Set the OSD parameters by the URL: PUT /ISAPI/System/IOT/channels/<ID>/OSD?
      format=json .
8. Receive event/alarm information.
   - Receive event/alarm in arming mode, see details in Receive Alarm/Event in Arming Mode .
   - Receive event/alarm in listening mode, see details in Receive Alarm/Event in Listening
      Mode .
9. Search for the picture of linked event/alarm by the URL: POST /ISAPI/SDT/Management/
   EventSearch?format=json .

      Note
  Before searching for event, you can get the event search capability by the URL: GET /ISAPI/SDT/
  Management/EventSearch/capabilities?format=json .
10. Optional: Get linked channel of searched event by the URL: POST /ISAPI/System/IOT/
    linkageChannels?format=json .
