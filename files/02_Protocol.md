# Chapter 2 Protocol

The design of ISAPI protocol adopts RESTful style, so this part introduces the predefined resource
operation methods, protocol API (URL) format, interaction message format, time format,
namespace, and error processing method.

2.1 Operation Method
The resource operation methods of ISAPI protocol are same as those of HTTP (Hyper Text Transport
Protocol) and RTSP (Real Time Streaming Protocol), see details in the following table.

     Note
The RTSP operation methods are mainly used to get the real-time stream for live view, two-way
audio, and playback in this manual. For details about HTTP and RTSP, please refer to https://
tools.ietf.org/html/rfc2612 and https://tools.ietf.org/html/rfc2326 .

                                Table 2-1 HTTP Operation Method
      Method                                             Description
POST                Create resources. This method is only available for adding resource that does
                    not exist before.
GET                 Retrieve resources. This method cannot change the system status, only return
                    data as the response to the requester.
PUT                 Update resources. This method is usually for update the resource that already
                    exists, but it can also be used to create the resource if the specific resource
                    does not exist.
DELETE              Delete resources.
                                 Table 2-2 RTSP Operation Method
      Method                                             Description
OPTIONS             Get the supported RTSP operation methods. See the request and response
                    message format below when interacting between client software and server.
                    OPTIONS %s RTSP/1.0\r\n //Request URL
                    CSeq:%u\r\n             //Command No.
                    User-Agent:%s\r\n          //Client software name
                    \r\n

                    /*Succeeded*/
                    RTSP/1.0 200 OK\r\n    //Succeeded
                    CSeq: %u\r\n        //Command No.

    Method                                               Description
                  Public: %s\r\n         //Supported operation methods
                  Date:%s\r\n            //Date and time
                  \r\n

                  /*Failed*/
                  RTSP/1.0 4XX/5XX %s\r\n //Failed
                  CSeq: %u\r\n         //Command No.
                  Date:%s\r\n         //Date and time
                  \r\n

DESCRIBE          Transfer basic information by SDP (Session Description Protocol, see https://
                  tools.ietf.org/html/rfc2327 ) files, such as URL with SETUP command and so
                  on. See the request and response message format below when interacting
                  between client software and server.
                  DESCRIBE %s RTSP/1.0\r\n //URL
                  CSeq:%u\r\n                 //Command No.
                  Accept: application/sdp\r\n        //The SDP description is accepted
                  Authorization:%s\r\n            //Authentication information
                  User-Agent:%s\r\n              //Client software name
                  \r\n

                  /*Succeeded*/
                  RTSP/1.0 200 OK\r\n           //Succeeded or failed
                  CSeq: %u\r\n               //Command No.
                  Content-Type: application/sdp\r\n //The SDP description exists behind the command
                  Content-Base:%s\r\n           //URL
                  Content-Length: %d\r\n          //The length of contents behind the command
                  \r\n
                  [content]               //SDP description

                  /*Failed*/
                  RTSP/1.0 4XX/5XX %s\r\n      //Failed
                  CSeq: %u\r\n            //Command No.
                  \r\n

SETUP             Interact the session information, such as transmission mode, port number,
                  and so on. See the request and response message format below when
                  interacting between client software and server.
                  SETUP %s RTSP/1.0\r\n //URL
                  CSeq:%u\r\n            //Command No.
                  Authorization:%s\r\n       //Authentication information
                  Session:%s\r\n          //Session ID is only returned at the even number of times
                  Transport: %s\r\n        //Transmission protocol
                  User-Agent:%s\r\nv         //Client software name
                  \r\n

                  /*Succeeded*/
                  RTSP/1.0 200 OK \r\n        //Succeeded

       Method                                           Description
                 CSeq: %u\r\n
                 Session:%s\r\n            //Session ID
                 Transport: s%            //Transmission method
                 Date: s%               //Date and time

                 /*Failed*/
                 RTSP/1.0 4XX/5XX %s\r\n     //Failed
                 CSeq: %u\r\n           //Command No.
                 \r\n

PLAY             Start the stream transmission. See the request and response message format
                 below when interacting between client software and server.
                 PLAY %s RTSP/1.0\r\n     //URL
                 CSeq:%u\r\n                //Command No.
                 Authorization:%s\r\n           //Authentication information
                 Session:%s\r\n              //Session ID
                 Range: npt=%f-%f\r\n            //Determine the play range
                 User-Agent:%s\r\n             //Client software name
                 \r\n

                 /*Succeeded*/
                 RTSP/1.0 200 OK \r\n        //Succeeded
                 CSeq: %u\r\n
                 Session:%s\r\n
                 RTP-Info:%s
                 Date: %s

                 /*Failed*/
                 RTSP/1.0 4XX/5XX %s\r\n     //Failed
                 CSeq: %u\r\n           //Command No.
                 Session:%s\r\n
                 \r\n

PAUSE            Pause the stream transmission.
TEARDOWN         Stop the stream transmission. See the request and response message format
                 below when interacting between client software and server.
                 TEARDOWN %s RTSP/1.0\r\n //URL
                 CSeq: %u\r\n           //Command No.
                 Authorization:%s\r\n       //Authentication information
                 Session:%s\r\n          //Session ID
                 User-Agent:%s\r\n         //Client software name
                 \r\n

                 /*Succeeded*/
                 RTSP/1.0 200 OK \r\n        //Succeeded
                 CSeq: %u\r\n
                 Session:%s\r\n

       Method                                           Description
                     Date:%s\r\n
                     \r\n

                     /*Failed*/
                     RTSP/1.0 4XX/5XX %s\r\n      //Failed
                     CSeq: %u\r\n            //Command No.
                     Session:%s\r\n
                     \r\n

2.2 URL Format
URL (Uniform Resource Locator) is a further class of URIs, it can identify a resource and locate the
resource by describing its primary access mechanism.
The format of URL is defined as the follows: <protocol>://<host>[:port][abs_path [?query]].
protocol
   Protocol types, i.e., HTTP (version 1.1) and RTSP (version 1.0).
host
   Host name, IP address, or the FQDN (Fully Qualified Domain Name) of network devices.
port
   Port number of host service for listening the connection status of TCP (Transmission Control
   Protocol, see https://tools.ietf.org/html/rfc793 ) or UDP (User Datagram Protocol, see https://
   tools.ietf.org/html/rfc768 ). If this field is not configured, the default port number will be
   adopted. For HTTP, the default port number is 80, and for RTSP, the default port number is 554.
abs_path
   Resource URI: /ServiceName/ResourceType/resource. Here, the ServiceName is ISAPI; the
   ResourceType is predefined with upper camel case according to different functions , see details
   in the following table; the resource is defined with lower camel case and can be extended in
   actual applications. E.g., /ISAPI/System/Network/interfaces.

   Predefined URI Model                                      Description
   /ISAPI/System/...        System related resources
   /ISAPI/Security/...      Security related resources
   /ISAPI/Streaming/...     Video streaming and management related resources
   /ISAPI/Event...          Event/alarm related resources
   /ISAPI/PTZCtrl/...       PTZ control related resources

   Predefined URI Model                                   Description
   /ISAPI/Image/...            Video encoding and image related resources
   /ISAPI/ContentMgmt/ Storage management related resources
   ...
query
  Strings for describing resources information, including related parameters. The parameter
  names and values must be listed as the following format in this field: ?p1=v1&p2=v2&…&pn=vn.

       Note
  • To locate the connected device, when operating lower-level device via the URL, the query
    field should be filled as ?devIndex=uuid&p1=v1&p2=v2&…&pn=vn. The uuid (or guid) is a 32-
    byte (128 bits) random number, which is unique and generated by operating system when
    adding device, and its format is "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx".
  • For message in JSON format, the query field should be filled as ?
    format=json&p1=v1&p2=v2&…&pn=vn. For details about message format, refer to the next
    section below. E.g.,http://10.17.132.22/ISAPI/System/time?
    foramt=json&devIndex=550e8400e29b41d4a716446655440000.

2.3 Message Format
For ISAPI protocol, the request and response messages generated among the interaction between
devices and platform are data in XML format or JSON format.

    Note
The message format here is only available for URLs based on HTTP.

XML Format
• For the previous integration, XML is a common format which may only cause a little changes in
  the later integration.
• Generally, for configuration information, the Content-Type in the XML format message is
  "application/xml; charset='UTF-8'", see details below.
  //Request Message
  GET /ISAPI/System/status HTTP/1.1
  …

  //Response Message
  HTTP/1.1 200 OK
  …
  Content-Type: application/xml; charset="UTF-8"
  …
  <?xml version="1.0" encoding="UTF-8"?>

  <DeviceStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  …
  </DeviceStatus>
  For data (e.g., firmware, configuration files), the Content-Type in the XML format message is
  "application/octet-stream", see details below.
  //Request Message
  PUT /ISAPI/System/configurationData HTTP/1.1
  …
  Content-Type: application/octet-stream
  …
  [proprietary configuration file data content]

  //Response Message
  HTTP/1.1 200 OK
  …

  Content-Type: application/xml; charset="UTF-8"
  …
  <?xml version="1.0" encoding="UTF-8"?>
  <ResponseStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  …
  </ResponseStatus>

JSON Format Message
• The leaf node (without any sub node) in the message is named by lower camel case, while the
  non-leaf node in the message in named by upper camel case.
• To communicate by the messages in JSON format, the devices must support the public
  specifications in http://www.ecma-international.org/publications/files/ECMA-ST/
  ECMA-404.pdf and HTTP with version 1.1.

       Note
  JSON is a lightweight data format which is a subset of JavaScript language and is small, fast, and
  easy to be parsed.
• Generally, for configuration information, the Content-Type of message is "application/json", see
  the example below:
  //Request message
  GET /ISAPI/System/status HTTP/1.1
  …

  //Response message
  HTTP/1.1 200 OK
  …
  Content-Type: application/json
  …
  "DeviceStatus":""
  …

  For data (e.g., firmware, configuration files), the Content-Type of message is "application/octet-
  stream", see the example below:
  //Request message
  PUT /ISAPI/System/configurationData HTTP/1.1
  …
  Content-Type: application/octet-stream
  …
  [proprietary configuration file data content]

  //Response message
  HTTP/1.1 200 OK
  …
  Content-Type: application/json
  …
  "ResponseStatus":""
  …

2.4 Others

Time Format
The time format in the ISAPI protocol adopts ISO8601 standard (see details in http://
www.w3.org/TR/NOTE-datetime-970915 ), that is, YYY-MM-DDThh:mm:ss.sTZD (e.g.,
2017-08-16T20:17:06+08:00).
Namespace
For message in XML format, namespace is required. The following namespaces are available:
• xmlns=http://www.isapi.org/ver20/XMLSchema
• xmlns:xs="http://www.w3.org/2001/XMLSchema"
• xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
• xmlns:xlink="http://www.w3.org/1999/xlink"

Error Processing
During the integration applications of ISAPI protocol, when the error of URL based on HTTP
occurred, the ResponseStatus message (in XML or JSON format) which contains error code will be
returned. If the error of URL based on RTSP occurs, the corresponding status code will directly be
returned, for details, refer to https://tools.ietf.org/html/rfc2326 .
