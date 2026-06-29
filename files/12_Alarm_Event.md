# Chapter 12 Alarm/Event

When the alarm is triggered or the event occurred, if you have configured alarm/event uploading
parameters, you can receive and process the alarm/event information in the third-party platform
or system by calling the request URLs of ISAPI. Two modes are available for receiving alarms,
including arming mode and listening mode.
Arming Mode
 When the alarm is triggered or event occurred, the third-party platform or system can send the
 request URL to the device for getting the alarm/event stream, and then the device uploads the
 response message with alarm/event information.
Listening Mode
  When alarm is triggered or event occurred, the device uploads the alarm information
  automatically, and then the third-party platform or system can receives the alarm/event by
  configuring listening port of HTTP host server.

12.1 Receive Alarm/Event in Arming Mode
When alarm is triggered or event occurred, and the alarm/event linkage is configured, you can
send request message to device for getting the alarm/event stream, and then the device uploads
the corresponding response message, which contains alarm/event information.
Before You Start
Make sure you have configured alarm/event and triggered the alarm/event. For configuring alarm/
event parameters, refer to the some typical applications of alarm/event configuration.

Steps

              Figure 12-1 Programming Flow of Receiving Alarm/Event in Arming Mode
1. Call /ISAPI/Event/notification/alertStream by GET to get the alarm/event stream.
2. Check if the heartbeat receiving timed out or network disconnected.
   - If the heartbeat keeps alive and the network still connected, perform the following step to
      continue.
   - If the heartbeat receiving timed out or network disconnected, perform the above step
      repeatedly until reconnected.
3. Receive and process the alarm/event information.
Example
Sample Code of Receiving Alarm/Event in Arming Mode (without Binary Picture Data)
GET /ISAPI/Event/notification/alertStream HTTP/1.1
Host: data_gateway_ip
Connection: Keep-Alive

HTTP/1.1 401 Unauthorized
Date: Sun, 01 Apr 2018 18:58:53 GMT
Server:
Content-Length: 178
Content-Type: text/html
Connection: keep-alive
Keep-Alive: timeout=10, max=99
WWW-Authenticate: Digest qop="auth",
realm="IP Camera(C2183)",
nonce="4e5468694e7a42694e7a4d364f4449354d7a6b354d54513d",
stale="FALSE"

GET /ISAPI/Event/notification/alertStream HTTP/1.1
Authorization: Digest username="admin",

realm="IP Camera(C2183)",
nonce="4e5468694e7a42694e7a4d364f4449354d7a6b354d54513d",
uri="/ISAPI/Event/notification/alertStream",
cnonce="3d183a245b8729121ae4ca3d41b90f18",
nc=00000001,
qop="auth",
response="f2e0728991bb031f83df557a8f185178"
Host: 10.6.165.192

HTTP/1.1 200 OK
MIME-Version: 1.0
Connection: close
Content-Type: multipart/mixed; boundary=<frontier>

--<frontier>
Content-Type: application/xml; charset="UTF-8"
Content-Length: text_length

<EventNotificationAlert/>
--<frontier>

     Note
Some alarm data is in JSON format, so the Content-Type may be "application/xml" or "application/
json".

12.2 Receive Alarm/Event in Listening Mode
When alarm is triggered or event occurred, and the alarm/event linkage is configured, the device
uploads the alarm/event information automatically, you can receive the alarm/event by
configuring the listening port of HTTP host server.
Before You Start
Make sure you have configured alarm/event and triggered the alarm/event. For configuring alarm/
event parameters, refer to the some typical applications of alarm/event configuration.

Steps

           Figure 12-2 Programming Manual of Receiving Alarm/Event in Listening Mode
1. Optional: Call /ISAPI/Event/notification/httpHosts/capabilities by GET method to get the
   capability of HTTP listening server.
2. Call /ISAPI/Event/notification/httpHosts by PUT method to set the parameters (including
   listening address and listening port) of HTTP listening server.

      Note
  Before setting the listening server, you'd better perform GET operation on the above URL to get
  default or configured parameters for reference.
3. Call /ISAPI/Event/notification/httpHosts/<ID>/test by POST method to check if the listening
   server is working normally.
4. Call http://ipAddress:portNo/url by POST method to receive the alarm/event information from
   the listening server.
Example
Sample Code of Receiving Alarm/Event in Listening Mode
• with Binary Picture Data
  //Request
  POST requestUrl HTTP/1.1
  Host: data_gateway_ip:port
  Accept-Language: en-US
  Date: YourDate
  Content-Type: multipart/form-data;boundary=<frontier>
  Content-Length: body_length
  Connection: keep-alive

  --<frontier>

  Content-Disposition: form-data; name="Event_Type"
  Content-Type: text/xml
  Content-Length: xml_length

  <EventNotificationAlert/>
  --<frontier>
  Content-Disposition: form-data; name="Picture_Name"
  Content-Length: image_length
  Content-Type: image/pjpeg

  [binary picture data]
  --<frontier>--

  //Response
  HTTP/1.1 HTTP statusCode
  Date: YourDate
  Connection: close
• without Binary Picture Data
  //Request
  POST requestUrl HTTP/1.1
  Host: data_gateway_ip:port
  Accept-Language: en-US
  Date: YourDate
  Content-Type: text/xml;
  Content-Length: text_length
  Connection: Close

  <EventNotificationAlert/>

  //Response
  HTTP/1.1 HTTP statusCode
  Date: YourDate
  Connection: close

    Note
• The Host is the HTTP server domain name or IP address and port No.
• Some alarm data is in JSON format, so the Content-Type may be "text/xml" or "text/json".

12.3 Subscribe Alarm/Event in Arming Mode
For arming mode, the platform will connect to the devices automatically and send commands to
the devices for uploading alarm/event information when the alarm is triggered or event occurred.
To reduce the CPU and bandwidth usage of platform, and improve the device processing
performance, the platform can subscribe alarm/event types to receive alarm/event information as
required.

Before You Start
Configure alarm/event and trigger the alarm/event. For configuring alarm/event parameters, refer
to the some typical applications of alarm/event configuration.
Steps

           Figure 12-3 Programming Flow of Subscribing Alarm/Event in Arming Mode
1. Get device capability to check if alarm/event subscription is supported by the request URL:
   GET /ISAPI/System/capabilities .
   The device capability is returned in the message XML_DeviceCap .
   If the node <isSupportSubscribeEvent> is also returned in the message and its value is "true", it
   indicates that alarm/event subscription is supported by device, and you can continue to
   perform the following steps;
   Otherwise, alarm/event subscription is not supported, please end the task.
2. Get subscription capability to get supported alarm/event types by the request URL: GET /ISAPI/
   Event/notification/subscribeEventCap .
   The alarm/event subscription capability is returned in the message XML_SubscribeEventCap .
3. Enable alarm/event uploading by the request URL: POST /ISAPI/Event/notification/
   subscribeEvent .

        Note
  The sub node <type> of event type list (EventList) in the request message XML_SubscribeEvent
  for the URL can be set to different values (refer to Supported Alarm/Event Types for details) to
  subscribe different types of alarm/event information.
4. Optional: Get subscribed alarm/event types for reference by the request URL: GET /ISAPI/
   Event/notification/subscribeEvent/<ID> .
5. Set alarm/event type to subscribe by the request URL: PUT /ISAPI/Event/notification/
   subscribeEvent/<ID> .

        Note
  The sub node <type> of event type list (EventList) in the request message XML_SubscribeEvent
  for the URL can be set to different values (refer to Supported Alarm/Event Types for details) to
  subscribe different types of alarm/event information.
6. Receive the alarm/event information by the request URL: GET /ISAPI/Event/notification/
   alertStream .
7. Check if the heartbeat receiving timed out or network disconnected.
   - If the heartbeat keeps alive and the network still connected, perform the following step to
      continue.
   - If the heartbeat receiving timed out or network disconnected, perform the above step
      repeatedly until reconnected.
8. Cancel subscribing alarm/event by the request URL: PUT /ISAPI/Event/notification/
   unSubscribeEvent .

12.4 Configure Exception Alarm
To monitor the device status, you can configure the exception alarm, such as supply voltage
exception, PoE power exception, and so on. When the exception occurs, the configured linkage
action will be triggered and the alarm information will be uploaded automatically.

Supply Voltage Exception
• Get configuration capability of alarm linkage action
  Request URL: GET /ISAPI/Event/triggersCap
• Get or set the linkage action of supply voltage exception alarm
  Request URL: GET or PUT /ISAPI/Event/triggers/<ID> , and the <ID> in the URL is
  "voltageinstable"
• Receive supply voltage exception alarm in listening mode
  Refer to Receive Alarm/Event in Listening Mode for details, the event type is "voltageinstable",
  and the alarm information is returned in message JSON_EventNotificationAlert_voltageinstable

     Note
To check if the device supports supply voltage exception alarm, you can call the request URL: GET /
ISAPI/Event/capabilities to get the device event capability ( XML_EventCap ). If supports, the node
<isSupportVoltageInstable> will be returned.

12.5 Configure Certificate Expiry Alarm
Generally, the device certificate is only valid in a specific period of time. You can configure the
certificate expiry alarm to remind the user a few days in advance. When the certificate is expired,
the alarm will be triggered and uploaded automatically.

Steps

          Figure 12-4 Programming Flow of Configuring Certificate Expiry Alarm

1. Get the event capability of the device by the request URL: GET /ISAPI/Event/capabilities to
   check whether the device supports certificate expiry alarm.
   The event capability of the device is returned in the message XML_EventCap . If the certificate
   expiry alarm is supported, the node <isSupportCertificateRevocation> will be returned and its
   value is "true", then you can perform the following steps. Otherwise, please end this task.
2. Get the event capability of the channel by the request URL: GET /ISAPI/Event/channels/<ID>/
   capabilities to check whether the certificate expiry alarm is supported by the channel.
   The event capability supported by the channel is returned in the message
   XML_ChannelEventCap . If the certificate expiry alarm is supported, the node <eventType> will
   be returned and it contains "certificateRevocation".
3. Get the configuration capability of certificate expiry alarm by the request URL: GET /ISAPI/
   Security/deviceCertificate/certificateRevocation/capabilities?format=json to know the
   supported parameters of certificate expiry alarm that can be configured.
4. Optional: Get the parameters of certificate expiry alarm by the request URL: GET /ISAPI/
   Security/deviceCertificate/certificateRevocation?format=json to get the existing or configured
   parameters for reference.
5. Set the parameters of certificate expiry alarm by the request URL: PUT /ISAPI/Security/
   deviceCertificate/certificateRevocation?format=json .
6. Optional: Get the linkage parameters of certificate expiry alarm by the request URL: GET /ISAPI/
   Event/triggers/<ID> or /ISAPI/Event/triggers/<ID>/notifications to get the existing or
   configured parameters for reference.

       Note
  The <ID> in the request URL refers to the channel No., and it should be set to the format
  "certificateRevocation-<channelID>".
7. Set the linkage parameters of certificate expiry alarm by the request URL: PUT /ISAPI/Event/
   triggers/<ID> or /ISAPI/Event/triggers/<ID>/notifications .

       Note
  The <ID> in the request URL refers to the channel No., and it should be set to the format
  "certificateRevocation-<channelID>".
8. Optional: Receive the uploaded certificate expiry alarm in arming mode (see details in Receive
   Alarm/Event in Arming Mode ) or in listening mode (see details in Receive Alarm/Event in
   Listening Mode ) when the certificate is expired.
   The certificate expiry alarm details are returned in the message
   JSON_EventNotificationAlert_CertificateExpiryAlarmMsg , and the corresponding alarm type
   (eventType) is "certificateRevocation".
