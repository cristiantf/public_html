# Chapter 8 Video and Audio

This part provides the request URLs to implement the video and audio related functions, such as
video search, live view, playback, two-way audio, control video in live view (e.g., focus and iris
adjustment), and so on.

8.1 Video Search and Downloading
The continuously recorded video files, or videos stored in the local storage of devices, or videos
recorded based on event/alarm or command, can be searched for playback as required. You can
also download the video files.

Search Video
• Get search conditions
  Request URL: GET /ISAPI/ContentMgmt/search/profile
• Search video files
  Request URL: POST /ISAPI/ContentMgmt/search

       Note
  This URL is not only used to search video files, it can also be used to search any resources stored
  in the device.
• Search video files by time
  Request URL: POST /ISAPI/ContentMgmt/record/tracks/<ID>/dailyDistribution
• Search VCA Event
  • Get capability of searching video files by VCA event
    Request URL: GET /ISAPI/ContentMgmt/SmartSearch/capabilities
  • Search video files by VCA event
    Request URL: POST /ISAPI/ContentMgmt/SmartSearch

Download Video
• Get downloading capability
  Request URL: GET /ISAPI/ContentMgmt/download/capabilities
• Download video files
  Request URL: POST /ISAPI/ContentMgmt/download
• Get capability of exporting video or picture files to devices via USB
  Request URL: GET /ISAPI/ContentMgmt/download/toUSB/capabilities?format=json
• Export video or picture files to devices via USB
  Request URL: POST /ISAPI/ContentMgmt/download/toUSB?format=json
• Get progress of exporting video or picture files to devices via USB
  Request URL: GET /ISAPI/ContentMgmt/download/toUSB/<taskId>/progress?format=json

      Note
To check if exporting video or picture files to devices via USB is supported by the device, you can
call the request URL: GET /ISAPI/ContentMgmt/download/capabilities to get the downloading
capability ( XML_DownloadAbility ). If this function is supported, the node
<isSupportDownloadToUSB> will be returned and its value is "true".

8.1.1 VCA Search
After enabling dual-VCA on the camera, you can search video files for behavior analysis (such as
line crossing detection, intrusion detection, loitering detection, fast movement, and so on.) and
feature object (such as people, vehicles, human face, license plates, and so on), which is helpful for
searching quickly and locating alarm event.
Before You Start
Make sure you have activated the device.
Steps

                            Figure 8-1 Programming Flow of VCA Search

1. Optional: Get the VCA management capability to check whether the VCA search function is
   supported by request URL: GET /ISAPI/SDT/Management/capabilities?format=json .
   The VCA management capability is returned in JSON_Cap_IntelliManagement .
   If the node isSuportIntelligentSearch exits in the returned message and its value is "true", it
   indicates that VCA search is supported by the device, and you can continue to perform the
   following steps; otherwise, end this task.
2. Get the VCA search capability by the request URL: GET /ISAPI/SDT/Management/
   IntelligentSearch/capabilities?format=json
   The VCA capability is returned in JSON_IntelligentSearchCap .
3. Start VCA search by the request URL: POST /ISAPI/SDT/Management/IntelligentSearch?
   format=json .

        Note
   You should repeatedly call this URL until the node "progress" in returned message
   JSON_IntelligentSearchResult values "100". It indicates the VCA search is completed.
   The searched result will be returned in JSON_IntelligentSearchResult .
4. Export the searched result the request URL: POST /ISAPI/SDT/Management/IntelligentSearch/
   export?format=json .
   The exporting task information is returned in JSON_VCASearchExportTaskInfo .
5. Get the progress of exporting VCA search result by the request URL: GET /ISAPI/SDT/
   Management/IntelligentSearch/export/progress?format=json&taskID= .

        Note
   Only when the node "progress" in returned message values "100", it indicates exporting is
   completed.
   The progress information is returned in JSON_VCASearchExportProgress .
6. Optional: Stop exporting the VCA search result by the request URL: PUT /ISAPI/SDT/
   Management/IntelligentSearch/export/stop?format=json .

8.2 Live View and Playback
Live view helps to remotely get the real-time video or audio of monitoring area and know the
status of human, vehicle, object, and so on. During live view, you can record and store the
remarkable videos for remotely playback.

Live View
• Start or stop live view
  Request URL: PLAY or TEARDOW
• Auto-Switch in Live View

  • Get configuration capability of live view auto-switch
    Request URL: GET /ISAPI/System/Video/outputs/PreviewSwitch/capabilities
  • Get configuration capability of live view auto-switch by video output
    Request URL: GET /ISAPI/System/Video/outputs/PreviewSwitch/capabilities?videoOutType=
  • Get or set parameters of live view auto-switch
    Request URL: GET or PUT /ISAPI/System/Video/outputs/PreviewSwitch?
    groupID=&videoOutType=
    Request URL: GET /ISAPI/System/Video/outputs/PreviewSwitch?
    groupID=&videoOutType=&previewFrameNo=
• Control in Live View
  • Perform manual focus
    Request URL: PUT /ISAPI/System/Video/inputs/channels/<ID>/focus
  • Manually adjust iris
    Request URL: PUT /ISAPI/System/Video/inputs/channels/<ID>/iris

Playback
• Start or stop playback
  Request URL: PLAY or TEARDOW rtsp://<host>[:port]/ISAPI/Streaming/tracks/<ID>?
  starttime=&endtime=
• Refresh video index before playback for instant playback
  Request URL: PUT /ISAPI/ContentMgmt/record/control/manualRefresh/channels/<ID>
Example
Sample Code for Starting and Stopping Live View
Start Live View:
DESCRIBE rtsp://10.17.133.46:554/ISAPI/streaming/channels/101 RTSP/1.0
CSeq: 0
Accept:application/sdp
User-Agent:NKPlayer-1.00.00.081112

RTSP/1.0 401 Unauthorized
CSeq: 0
WWW-Authenticate: Digest realm="4419b66d2485", nonce="47f172cffa4ce6e6942bbdcfa5931d0f", stale="FALSE"
Date: Tue, Mar 14 2017 10:42:35 GMT

DESCRIBE rtsp://10.17.133.46:554/ISAPI/streaming/channels/101 RTSP/1.0
CSeq:1
Accept:application/sdp
Authorization: Digest username="admin",
realm="4419b66d2485",
nonce="47f172cffa4ce6e6942bbdcfa5931d0f",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/channels/101",
response="da5deb4033515f74ed0483d2da3f7fe0"
User-Agent:NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 1

Content-Type: application/sdp
Content-Length: 604

v=0
o=- 1489488155469547 1489488155469547 IN IP4 10.17.133.46
s=Media Presentation
e=NONE
b=AS:5100
t=0 0
a=control:*
m=video 0 RTP/AVP 96
c=IN IP4 0.0.0.0
b=AS:5000
a=recvonly
a=x-dimensions:1280,720
a=control:trackID=1
a=rtpmap:96 H264/90000
a=fmtp:96 profile-level-id=420029;
packetization-mode=1;
sprop-parameter-sets=Z2QAH6wXKgFAFuhAAAHCAABX5CE=,
aP44sA==
m=audio 0 RTP/AVP 8
c=IN IP4 0.0.0.0
b=AS:50
a=recvonly
a=control:trackID=2
a=rtpmap:8 PCMA/8000
a=Media_header:MEDIAINFO=494D4B48010200000400000111710110401F000000FA00000000000000000000000000
0000000000;
a=appversion:1.0
SETUP rtsp://10.17.133.46:554/ISAPI/streaming/channels/101/trackID=1 RTSP/1.0
CSeq:2
Authorization: Digest username="admin", realm="4419b66d2485",
nonce="47f172cffa4ce6e6942bbdcfa5931d0f",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/channels/101",
response="db78bce6e6883ed2a7fb3adbd1631b1d"
Transport:RTP/AVP/UDP;unicast;client_port=20044-20045;ssrc=0
User-Agent:NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 2
Session: 846509115;timeout=60
Transport: RTP/AVP/UDP;unicast;client_port=20044-20045;ssrc=2933ec5a;server_port=8372-8373;mode="play"
Date: Tue, Mar 14 2017 10:42:35 GMT

SETUP rtsp://10.17.133.46:554/ISAPI/streaming/channels/101/trackID=2 RTSP/1.0
CSeq:3
Authorization: Digest username="admin", realm="4419b66d2485",
nonce="47f172cffa4ce6e6942bbdcfa5931d0f",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/channels/101",
response="db78bce6e6883ed2a7fb3adbd1631b1d"
Session:846509115;timeout=60

Transport:RTP/AVP/UDP;unicast;client_port=20046-20047;ssrc=0
User-Agent:NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 3
Session: 846509115;timeout=60
Transport: RTP/AVP/UDP;unicast;client_port=20046-20047;ssrc=439bd478;server_port=8374-8375;mode="play"
Date: Tue, Mar 14 2017 10:42:35 GMT

PLAY rtsp://10.17.133.46:554/ISAPI/streaming/channels/101 RTSP/1.0
CSeq:4
Authorization: Digest username="admin",
realm="4419b66d2485",
nonce="47f172cffa4ce6e6942bbdcfa5931d0f",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/channels/101",
response="66fcea1521a99fba336fd0c4e444a732"
Session:846509115;timeout=60
Rate-Control:yes
Scale:1.000
User-Agent:NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 4
Session: 846509115
Scale: 1.0
RTP-Info: url=trackID=1;seq=55143,url=trackID=2;seq=38217
Date: Tue, Mar 14 2017 10:42:35 GMT

Stop Live View
TEARDOWN rtsp://10.17.133.46:554/ISAPI/streaming/channels/101 RTSP/1.0
CSeq: 5
Authorization: Digest username="admin",
realm="4419b66d2485",
nonce="47f172cffa4ce6e6942bbdcfa5931d0f",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/channels/101",
response="31d5e172b87db528aa5b1dc07af3f530"
Session:846509115;timeout=60
User-Agent: NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 5
Session: 846509115
Date: Tue, Mar 14 2017 10:42:36 GMT

Example
Sample Code for Starting and Stopping Playback
Enable:
DESCRIBE rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z RTSP/1.0
CSeq:0
Accept:application/sdp

User-Agent:NKPlayer-1.00.00.081112

RTSP/1.0 401 Unauthorized
CSeq: 0
WWW-Authenticate: Digest realm="4419b66d2485",
nonce="a0ecd9b1586ff9461f02f910035d0486",
stale="FALSE"
Date: Tue, Mar 14 2017 10:57:23 GMT

DESCRIBE rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z RTSP/1.0
CSeq:1
Accept:application/sdp
Authorization: Digest username="admin",
realm="4419b66d2485",
nonce="a0ecd9b1586ff9461f02f910035d0486",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z",
response="1ebae505abbafd431fb433cec6e85189"
User-Agent:NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 1
Content-Type: application/sdp
Content-Length: 604

v=0
o=- 1489489043122939 1489489043122939 IN IP4 10.17.133.46
s=Media Presentation
e=NONE
b=AS:5100
t=0 0
a=control:*
m=video 0 RTP/AVP 96
c=IN IP4 0.0.0.0
b=AS:5000
a=recvonly
a=x-dimensions:1280,720
a=control:trackID=1
a=rtpmap:96 H264/90000
a=fmtp:96 profile-level-id=420029; packetization-mode=1; sprop-parameter-
sets=Z2QAH6wXKgFAFuhAAAHCAABX5CE=,aP44sA==
m=audio 0 RTP/AVP 8
c=IN IP4 0.0.0.0
b=AS:50
a=recvonly
a=control:trackID=2
a=rtpmap:8 PCMA/8000
a=Media_header:MEDIAINFO=494D4B48010200000400000111710110401F000000FA00000000000000000000000000
0000000000;
a=appversion:1.0

SETUP rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z/trackID=1 RTSP/1.0
CSeq:2
Authorization: Digest username="admin",
realm="4419b66d2485",
nonce="a0ecd9b1586ff9461f02f910035d0486",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z",
response="6a7a733b41908bd9549a4ac07c498509"
Transport:RTP/AVP/UDP;unicast;client_port=20056-20057;ssrc=0
User-Agent:NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 2
Session: 2049381566;timeout=60
Transport: RTP/AVP/UDP;unicast;client_port=20056-20057;ssrc=7d3c07bc;server_port=8220-8221;mode="play"
Date: Tue, Mar 14 2017 10:57:23 GMT

SETUP rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z/trackID=2 RTSP/1.0
CSeq:3
Authorization: Digest username="admin",
realm="4419b66d2485",
nonce="a0ecd9b1586ff9461f02f910035d0486",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z",
response="6a7a733b41908bd9549a4ac07c498509"
Session:2049381566;timeout=60
Transport:RTP/AVP/UDP;unicast;client_port=20058-20059;ssrc=0
User-Agent:NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 3
Session: 2049381566;timeout=60
Transport: RTP/AVP/UDP;unicast;client_port=20058-20059;ssrc=06557745;server_port=8226-8227;mode="play"
Date: Tue, Mar 14 2017 10:57:23 GMT

PLAY rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z RTSP/1.0
CSeq:4
Authorization: Digest username="admin",
realm="4419b66d2485",
nonce="a0ecd9b1586ff9461f02f910035d0486",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z",
response="fb986d385a7d839052ec4f0b2b70c631"
Session:2049381566;timeout=60
Range:clock=20170313T230652Z-20170314T025706Z
Rate-Control:yes
Scale:1.000
User-Agent:NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 4
Session: 2049381566
Scale: 1.000
RTP-Info: url=trackID=1;seq=1,url=trackID=2;seq=1
Date: Tue, Mar 14 2017 10:57:23 GMT

Pause:
PAUSE rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z RTSP/1.0
CSeq: 5
Authorization: Digest username="admin",
realm="4419b66d2485",
nonce="a0ecd9b1586ff9461f02f910035d0486",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z",
response="d229c4d2419df553212bc7d74bbfd432"
Session:2049381566;timeout=60
User-Agent: NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 5
Session: 2049381566
Date: Tue, Mar 14 2017 10:57:24 GMT

Play in 2× Speed:
PLAY rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z RTSP/1.0
CSeq:6
Authorization: Digest username="admin",
realm="4419b66d2485",
nonce="a0ecd9b1586ff9461f02f910035d0486",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z",
response="fb986d385a7d839052ec4f0b2b70c631"
Session:2049381566;timeout=60
Scale:2.000
User-Agent:NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 6
Session: 2049381566
Scale: 2.000
RTP-Info: url=trackID=1;seq=1,url=trackID=2;seq=1
Date: Tue, Mar 14 2017 10:57:24 GMT

Pause:
PAUSE rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z RTSP/1.0
CSeq: 7
Authorization: Digest username="admin",
realm="4419b66d2485",

nonce="a0ecd9b1586ff9461f02f910035d0486",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z",
response="d229c4d2419df553212bc7d74bbfd432"
Session:2049381566;timeout=60
User-Agent: NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 7
Session: 2049381566
Date: Tue, Mar 14 2017 10:57:25 GMT

Play in 4× Speed:
PLAY rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z RTSP/1.0
CSeq:8
Authorization: Digest username="admin",
realm="4419b66d2485",
nonce="a0ecd9b1586ff9461f02f910035d0486",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z",
response="fb986d385a7d839052ec4f0b2b70c631"
Session:2049381566;timeout=60
Scale:4.000
User-Agent:NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 8
Session: 2049381566
Scale: 4.000
RTP-Info: url=trackID=1;seq=1,url=trackID=2;seq=1
Date: Tue, Mar 14 2017 10:57:25 GMT

Disable:
TEARDOWN rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z RTSP/1.0
CSeq: 9
Authorization: Digest username="admin",
realm="4419b66d2485",
nonce="a0ecd9b1586ff9461f02f910035d0486",
uri="rtsp://10.17.133.46:554/ISAPI/streaming/tracks/101?
starttime=20170313T230652Z&endtime=20170314T025706Z",
response="50c86f44780a497ee07622b70c050bcd"
Session:2049381566;timeout=60
User-Agent: NKPlayer-1.00.00.081112

RTSP/1.0 200 OK
CSeq: 9
Session: 2049381566
Date: Tue, Mar 14 2017 10:57:28 GMT

8.3 Start Two-Way Audio
Two-way audio function enables the voice talk of the camera. You can get not only the live video
but also the real-time audio from the camera. If the device has multiple two-way audio channels,
you can select the channel to start two-way audio.
Steps

                     Figure 8-2 Programming Flow of Starting Two-Way Audio
1. Optional: Get parameters, including channel No., encoding mode, and so on, of all two-way
   audio channels by the request URL: GET /ISAPI/System/TwoWayAudio/channels .
2. Specify a channel of device to start the two-way audio by the request URL: PUT /ISAPI/System/
   TwoWayAudio/channels/<ID>/open
3. Perform the following operations to transmit the audio data between platform and device.
        Send Audio Data to Device     Request URL: PUT /ISAPI/System/TwoWayAudio/channels/
                                      <ID>/audioData
      Receive Audio Data from          Request URL: GET /ISAPI/System/TwoWayAudio/channels/
      Device                           <ID>/audioData
4. Stop two-way audio of the specific channel by the request URL: PUT /ISAPI/System/
   TwoWayAudio/channels/<ID>/close .

8.4 Stream Encoding
The following request URLs are used for configuring encoding parameters of video and audio
stream by one channel or multiple channels.

Encode Stream of Multiple Channels
• Get or set encoding parameters of multiple channels
  Request URL: GET or PUT /ISAPI/Streaming/channels
• Get encoding status of multiple channels
  Request URL: GET /ISAPI/Streaming/status

Encode Stream of One Channel
• Get encoding capability of one channel
  Request URL: GET /ISAPI/Streaming/channels/<ID>/capabilities
• Get dynamic encoding capability of one channel
  Request URL: GET /ISAPI/Streaming/channels/<ID>/dynamicCap .
• Get or set encoding parameters of one channel
  Request URL: GET or PUT /ISAPI/Streaming/channels/<ID>
• Get encoding status of one channel
  Request URL: GET /ISAPI/Streaming/channels/<ID>/status
