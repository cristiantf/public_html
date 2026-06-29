# Chapter 15 Request URL

The intelligent security API in request URL format for realizing the functions in this manual are
listed here for reference. You can search for the URLs and view their definitions.

15.1 /ISAPI/AUXInfo

15.1.1 /ISAPI/AUXInfo/attributes/Channels
Get the attributes of channels.

Request URL Definition
                        Table 15-1 GET /ISAPI/AUXInfo/attributes/Channels
Method                            GET
Description                       Get the attributes of channels.
Query                             None.
Request                           None.
Response                          XML_ChannelInfoList

15.1.2 /ISAPI/AUXInfo/attributes/Channels/<ID>
Get the attributes of a specific channel according to channel ID.

Request URL Definition
                     Table 15-2 GET /ISAPI/AUXInfo/attributes/Channels/<ID>
Method                        GET
Description                   Get the attributes of a specific channel according to channel ID.
Query                         None.
Request                       None.
Response                      XML_ChannelInfo

Remarks
The <ID> in the request URL is the channel ID.

15.2 /ISAPI/ContentMgmt

15.2.1 /ISAPI/ContentMgmt/capabilities
Get storage capability.

GET /ISAPI/ContentMgmt/capabilities

Method                       GET
Description                  Get storage capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_RacmCap
                             Failed: XML_ResponseStatus

15.2.2 /ISAPI/ContentMgmt/download
Download the file via plug-in.

Request URL Definition
                          Table 15-3 GET /ISAPI/ContentMgmt/download
Method                       GET
Description                  Download the file.
Query                        security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      XML_downloadRequest
Response                     File

15.2.3 /ISAPI/ContentMgmt/download/capabilities
Get the downloading capability sets.

Request URL Definition
                   Table 15-4 GET /ISAPI/ContentMgmt/download/capabilities
Method                        GET
Description                   Get the downloading capability sets.
Query                         None.
Request                       None.
Response                      Succeeded: XML_DownloadAbility
                              Failed: XML_ResponseStatus

15.2.4 /ISAPI/ContentMgmt/download/toUSB/<taskId>/progress?format=json
Get the progress of exporting files to devices via USB.

Request URL Definition
     Table 15-5 GET /ISAPI/ContentMgmt/download/toUSB/<taskId>/progress?format=json
Method                        GET
Description                   Get the progress of exporting files to devices via USB.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_ProgressInfo
                              Failed: JSON_ResponseStatus

Remarks
The <taskId> in the request URL refers to the task ID, and it is returned in the message
JSON_ExporttoUSB_TaskInfo after calling the request URL: POST /ISAPI/ContentMgmt/download/
toUSB?format=json .

15.2.5 /ISAPI/ContentMgmt/download/toUSB/capabilities?format=json
Get the capability of exporting files to devices via USB.

Request URL Definition
        Table 15-6 GET /ISAPI/ContentMgmt/download/toUSB/capabilities?format=json
Method                        GET
Description                   Get the capability of exporting files to devices via USB.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_Cap_ExportInfo
                              Failed: JSON_ResponseStatus

15.2.6 /ISAPI/ContentMgmt/download/toUSB?format=json
Export files to devices via USB.

Request URL Definition
              Table 15-7 POST /ISAPI/ContentMgmt/download/toUSB?format=json
Method                        POST
Description                   Export files to devices via USB.
Query                         format: determine the format of request or response message.
Request                       JSON_ExportInfo
Response                      Succeeded: JSON_ExporttoUSB_TaskInfo
                              Failed: JSON_ResponseStatus

15.2.7 /ISAPI/ContentMgmt/InputProxy/channels
Operations about management of all digital channels.

Request URL Definition
                    Table 15-8 GET /ISAPI/ContentMgmt/InputProxy/channels
Method                        GET
Description                   Get parameters of all digital channels.
Query                         None.

Request                     None.
Response                    XML_InputProxyChannelList
                   Table 15-9 PUT /ISAPI/ContentMgmt/InputProxy/channels
Method                      PUT
Description                 Set parameters of all digital channels.
Query                       None.
Request                     XML_InputProxyChannelList
Response                    XML_ResponseStatus
                 Table 15-10 POST /ISAPI/ContentMgmt/InputProxy/channels
Method                      POST
Description                 Add a digital channel.
Query                       None.
Request                     XML_InputProxyChannel
Response                    XML_ResponseStatus

15.2.8 /ISAPI/ContentMgmt/InputProxy/channels/<ID>
Operations about management of a specific digital channel.

Request URL Definition
               Table 15-11 GET /ISAPI/ContentMgmt/InputProxy/channels/<ID>
Method                      GET
Description                 Get parameter of a specific digital channel.
Query                       None.
Request                     None.
Response                    Succeeded: XML_InputProxyChannel
                            Failed: XML_ResponseStatus
               Table 15-12 PUT /ISAPI/ContentMgmt/InputProxy/channels/<ID>
Method                      PUT
Description                 Set parameters of a specific digital channel.
Query                       None.

Request                      XML_InputProxyChannel
Response                     XML_ResponseStatus
              Table 15-13 DELETE /ISAPI/ContentMgmt/InputProxy/channels/<ID>
Method                       DELETE
Description                  Delete a specific digital channel.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the digital channel ID.

15.2.9 /ISAPI/ContentMgmt/InputProxy/channels/<ID>/capabilities
Get management capability of a specific digital channel.

Request URL Definition
          Table 15-14 GET /ISAPI/ContentMgmt/InputProxy/channels/<ID>/capabilities
Method                       GET
Description                  Get management capability of a specific digital channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_InputProxyChannel
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the digital channel ID.

15.2.10 /ISAPI/ContentMgmt/InputProxy/channels/<ID>/chanCtrl
Get or set control parameters of a specific channel.

Request URL Definition
           Table 15-15 GET /ISAPI/ContentMgmt/InputProxy/channels/<ID>/chanCtrl
Method                       GET
Description                  Get control parameters of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_ChanCtrl
                             Failed: XML_ResponseStatus
           Table 15-16 PUT /ISAPI/ContentMgmt/InputProxy/channels/<ID>/chanCtrl
Method                       PUT
Description                  Set control parameters of a specific channel.
Query                        None.
Request                      XML_ChanCtrl
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.2.11 /ISAPI/ContentMgmt/InputProxy/channels/<ID>/portMapParam
Check if port mapping is required for connecting to camera.

Request URL Definition
        Table 15-17 POST /ISAPI/ContentMgmt/InputProxy/channels/<ID>/portMapParam
Method                       POST
Description                  Check if port mapping is required for connecting to camera according
                             to the IP address of terminal.
Query                        None.
Request                      XML_PortMapParam
Response                     Succeeded: XML_PortMapParamRet
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.2.12 /ISAPI/ContentMgmt/InputProxy/channels/<ID>/reboot
Reboot a specific channel.

Request URL Definition
             Table 15-18 GET /ISAPI/ContentMgmt/InputProxy/channels/<ID>/reboot
Method                         GET
Description                    Reboot a specific channel.
Query                          None.
Request                        None.
Response                       XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.2.13 /ISAPI/ContentMgmt/InputProxy/channels/<ID>/status
Get status of a specific digital channel.

Request URL Definition
              Table 15-19 GET /ISAPI/ContentMgmt/InputProxy/channels/<ID>/status
Method                         GET
Description                    Get status of a specific digital channel.
Query                          None.
Request                        None.
Response                       XML_InputProxyChannelStatus

Remarks
The <ID> in the request URL refers to the digital channel ID.

15.2.14 /ISAPI/ContentMgmt/InputProxy/channels/activate
Activate the network devices.

Request URL Definition
               Table 15-20 PUT /ISAPI/ContentMgmt/InputProxy/channels/activate
Method                       PUT
Description                  Activate the network devices.
Query                        None
Request                      XML_VideoSourceActivation
Response                     XML_ResponseStatus

15.2.15 /ISAPI/ContentMgmt/InputProxy/channels/activate/capabilities
Get capability of activating network devices.

Request URL Definition
        Table 15-21 GET /ISAPI/ContentMgmt/InputProxy/channels/activate/capabilities
Method                       GET
Description                  Get capability of activating network devices.
Query                        None
Request                      None.
Response                     Succeeded: XML_VideoSourceActivationCapability
                             Failed: XML_ResponseStatus

15.2.16 /ISAPI/ContentMgmt/InputProxy/channels/capabilities
Get management capability of all digital channels.

Request URL Definition
              Table 15-22 GET /ISAPI/ContentMgmt/InputProxy/channels/capabilities
Method                       GET
Description                  Get management capability of all digital channels.
Query                        None.

Request                        None.
Response

15.2.17 /ISAPI/ContentMgmt/InputProxy/channels/status
Get status of all digital channels.

Request URL Definition
                Table 15-23 GET /ISAPI/ContentMgmt/InputProxy/channels/status
Method                         GET
Description                    Get status of all digital channels.
Query                          None.
Request                        None.
Response                       XML_InputProxyChannelStatusList

15.2.18 /ISAPI/ContentMgmt/InputProxy/search
Search for network cameras in the LAN (Local Area Network) that can be connected.

Request URL Definition
                      Table 15-24 GET /ISAPI/ContentMgmt/InputProxy/search
Method                         GET
Description                    Search for network cameras in the LAN (Local Area Network) that can
                               be connected.
Query                          None.
Request                        None.
Response                       Succeeded: XML_VideoSourceList
                               Failed: XML_ResponseStatus

15.2.19 /ISAPI/ContentMgmt/InputProxy/sourceCapability
Get supported number of digital channels.

Request URL Definition
              Table 15-25 POST /ISAPI/ContentMgmt/InputProxy/sourceCapability
Method                       POST
Description                  Get supported number of digital channels.
Query                        None.
Request                      XML_sourceDescriptor
Response                     XML_sourceCapability

15.2.20 /ISAPI/ContentMgmt/IOProxy/inputs
Operations about the alarm input configuration of all digital channels.

Request URL Definition
                      Table 15-26 GET /ISAPI/ContentMgmt/IOProxy/inputs
Method                       GET
Description                  Get the alarm input parameters of all digital channels.
Query                        None.
Request                      None.
Response                     Succeeded: XML_IOProxyInputPortList
                             Failed: XML_ResponseStatus
                      Table 15-27 PUT /ISAPI/ContentMgmt/IOProxy/inputs
Method                       PUT
Description                  Set the alarm input parameters of all digital channels.
Query                        None.
Request                      XML_IOProxyInputPortList
Response                     XML_ResponseStatus
                     Table 15-28 POST /ISAPI/ContentMgmt/IOProxy/inputs
Method                       POST
Description                  Add the alarm input configuration of a specific digital channel.
Query                        None.

Request                      XML_IOProxyInputPort
Response                     XML_ResponseStatus

15.2.21 /ISAPI/ContentMgmt/IOProxy/inputs/<ID>
Operations about the alarm input configuration of a specific digital channel.

Request URL Definition
                   Table 15-29 GET /ISAPI/ContentMgmt/IOProxy/inputs/<ID>
Method                       GET
Description                  Get the alarm input parameters of a specific digital channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_IOProxyInputPort
                             Failed: XML_ResponseStatus
                   Table 15-30 PUT /ISAPI/ContentMgmt/IOProxy/inputs/<ID>
Method                       PUT
Description                  Set the alarm input parameters of a specific digital channel.
Query                        None.
Request                      XML_IOProxyInputPort
Response                     XML_ResponseStatus
                 Table 15-31 DELETE /ISAPI/ContentMgmt/IOProxy/inputs/<ID>
Method                       DELETE
Description                  Delete the alarm input configuration of a specific digital channel.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the digital channel No.

15.2.22 /ISAPI/ContentMgmt/IOProxy/inputs/<ID>/status
Get the alarm input status of a specific digital channel.

Request URL Definition
                Table 15-32 GET /ISAPI/ContentMgmt/IOProxy/inputs/<ID>/status
Method                        GET
Description                   Get the alarm input status of a specific digital channel.
Query                         None.
Request                       None.
Response                      Succeeded: XML_IOPortStatus
                              Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the digital channel No.

15.2.23 /ISAPI/ContentMgmt/IOProxy/outputs
Operations about the alarm output configuration of all digital channels.

Request URL Definition
                      Table 15-33 GET /ISAPI/ContentMgmt/IOProxy/outputs
Method                        GET
Description                   Get the alarm output parameters of all digital channels.
Query                         None.
Request                       None.
Response                      Succeeded: XML_IOProxyOutputPortList
                              Failed: XML_ResponseStatus
                      Table 15-34 PUT /ISAPI/ContentMgmt/IOProxy/outputs
Method                        PUT
Description                   Set the alarm output parameters of all digital channels.
Query                         None.

Request                      XML_IOProxyOutputPortList
Response                     XML_ResponseStatus
                    Table 15-35 POST /ISAPI/ContentMgmt/IOProxy/outputs
Method                       POST
Description                  Add the alarm output configuration of a specific digital channel.
Query                        None.
Request                      XML_IOProxyOutputPort
Response                     XML_ResponseStatus

15.2.24 /ISAPI/ContentMgmt/IOProxy/outputs/<ID>
Operations about the alarm output configuration of a specific digital channel.

Request URL Definition
                  Table 15-36 GET /ISAPI/ContentMgmt/IOProxy/outputs/<ID>
Method                       GET
Description                  Get the alarm output parameters of a specific digital channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_IOProxyOutputPort
                             Failed: XML_ResponseStatus
                  Table 15-37 PUT /ISAPI/ContentMgmt/IOProxy/outputs/<ID>
Method                       PUT
Description                  Set the alarm output parameters of a specific digital channel.
Query                        None.
Request                      XML_IOProxyOutputPort
Response                     XML_ResponseStatus
                Table 15-38 DELETE /ISAPI/ContentMgmt/IOProxy/outputs/<ID>
Method                       DELETE
Description                  Delete the alarm output configuration of a specific digital channel.
Query                        None.

Request                       None.
Response                      XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the digital channel No.

15.2.25 /ISAPI/ContentMgmt/IOProxy/outputs/<ID>/status
Get the alarm output status of a specific digital channel.

Request URL Definition
               Table 15-39 GET /ISAPI/ContentMgmt/IOProxy/outputs/<ID>/status
Method                        GET
Description                   Get the alarm output status of a specific digital channel.
Query                         None.
Request                       None.
Response                      Succeeded: XML_IOPortStatus
                              Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the digital channel No.

15.2.26 /ISAPI/ContentMgmt/IOProxy/outputs/<ID>/trigger
Trigger alarm output of a specific digital channel.

Request URL Definition
               Table 15-40 PUT /ISAPI/ContentMgmt/IOProxy/outputs/<ID>/trigger
Method                        PUT
Description                   Trigger alarm output of a specific digital channel.
Query                         None.
Request                       XML_IOPortData
Response                      XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the digital channel No.

15.2.27 /ISAPI/ContentMgmt/logConfig
Get or set log parameters.

Request URL Definition
                          Table 15-41 GET /ISAPI/ContentMgmt/logConfig
Method                        GET
Description                   Get log parameters.
Query                         None.
Request                       None.
Response                      Succeeded: XML_LogConfig
                              Failed: XML_ResponseStatus
                         Table 15-42 PUT /ISAPI/ContentMgmt/logConfig
Method                        PUT
Description                   Set log parameters.
Query                         None.
Request                       XML_LogConfig
Response                      XML_ResponseStatus

15.2.28 /ISAPI/ContentMgmt/logConfig/capabilities
Get log configuration capability.

Request URL Definition
                   Table 15-43 GET /ISAPI/ContentMgmt/logConfig/capabilities
Method                        GET
Description                   Get log configuration capability.
Query                         None.
Request                       None.
Response                      Succeeded: XML_Cap_LogConfig
                              Failed: XML_ResponseStatus

15.2.29 /ISAPI/ContentMgmt/logSearch
Search for log files.

Request URL Definition
                           Table 15-44 POST /ISAPI/ContentMgmt/logSearch
Method                         POST
Description                    Search for log files.
Query                          None.
Request                        XML_CMSearchDescription
Response                       Succeeded: XML_CMSearchResult
                               Failed: XML_ResponseStatus

15.2.30 /ISAPI/ContentMgmt/logSearch/dataPackage
Export device log files.

Request URL Definition
                   Table 15-45 POST /ISAPI/ContentMgmt/logSearch/dataPackage
Method                         POST
Description                    Export device log files.
Query                          None.
Request                        XML_CMSearchDataPackage
Response                       Succeeded: XML_CMSearchDataPackageResult
                               Failed: XML_ResponseStatus

15.2.31 /ISAPI/ContentMgmt/record/control/manualRefresh/channels/<ID>
Refresh the video mode manually before playback.

Request URL Definition
      Table 15-46 PUT /ISAPI/ContentMgmt/record/control/manualRefresh/channels/<ID>
Method                         PUT
Description                    Refresh the video mode manually before playback.

Query                        None.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.2.32 /ISAPI/ContentMgmt/record/control/manual/start/tracks/<ID>
Start manual recording.

Request URL Definition
        Table 15-47 POST /ISAPI/ContentMgmt/record/control/manual/start/tracks/<ID>
Method                       POST
Description                  Start manual recording.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the recording channel ID.

15.2.33 /ISAPI/ContentMgmt/record/control/manual/stop/tracks/<ID>
Stop manual recording of a specific channel.

Request URL Definition
        Table 15-48 POST /ISAPI/ContentMgmt/record/control/manual/stop/tracks/<ID>
Method                       POST
Description                  Stop manual recording of a specific channel.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the recording channel ID.

15.2.34 /ISAPI/ContentMgmt/record/profile
Get video track type.

Request URL Definition
                        Table 15-49 GET /ISAPI/ContentMgmt/record/profile
Method                       GET
Description                  Get video track type.
Query                        None.
Request                      None.
Response                     Succeeded: XML_CMSRecordProfile
                             Failed: XML_ResponseStatus

15.2.35 /ISAPI/ContentMgmt/record/storageMounts
Set recording storage parameters.

Request URL Definition
                  Table 15-50 PUT /ISAPI/ContentMgmt/record/storageMounts
Method                       PUT
Description                  Set recording storage parameters, including root directory, size, and
                             so on.
Query                        None.
Request                      XML_MountList
Response                     XML_ResponseStatus

15.2.36 /ISAPI/ContentMgmt/record/tracks
Operations about recording schedule configuration.

Request URL Definition
                        Table 15-51 GET /ISAPI/ContentMgmt/record/tracks
Method                       GET
Description                  Get all recording schedules.

Query                      None.
Request                    None.
Response                   Succeeded: XML_TrackList
                           Failed: XML_ResponseStatus
                     Table 15-52 PUT /ISAPI/ContentMgmt/record/tracks
Method                     PUT
Description                Set all recording schedules.
Query                      None.
Request                    XML_TrackList
Response                   XML_ResponseStatus
                     Table 15-53 POST /ISAPI/ContentMgmt/record/tracks
Method                     POST
Description                Add a recording schedule.
Query                      None.
Request                    XML_Track
Response                   XML_ResponseStatus

15.2.37 /ISAPI/ContentMgmt/record/tracks/<ID>
Operations about a recording schedule.

Request URL Definition
                   Table 15-54 GET /ISAPI/ContentMgmt/record/tracks/<ID>
Method                     GET
Description                Get a recording schedule.
Query                      None.
Request                    None.
Response                   Succeeded: XML_Track
                           Failed: XML_ResponseStatus

                    Table 15-55 PUT /ISAPI/ContentMgmt/record/tracks/<ID>
Method                       PUT
Description                  Set a recording schedule.
Query                        None.
Request                      XML_Track
Response                     XML_ResponseStatus
                  Table 15-56 DELETE /ISAPI/ContentMgmt/record/tracks/<ID>
Method                       DELETE
Description                  Delete a recording schedule.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the recording schedule ID.

15.2.38 /ISAPI/ContentMgmt/record/tracks/<ID>/capabilities
Get the configuration capability of the recording schedule.

Request URL Definition
              Table 15-57 GET /ISAPI/ContentMgmt/record/tracks/<ID>/capabilities
Method                       GET
Description                  Get the configuration capability of the recording schedule.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_Track
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the recording schedule ID.

15.2.39 /ISAPI/ContentMgmt/record/tracks/<ID>/dailyDistribution
Search recorded video files by date.

Request URL Definition
          Table 15-58 POST /ISAPI/ContentMgmt/record/tracks/<ID>/dailyDistribution
Method                       POST
Description                  Search recorded video files by date.
Query                        None.
Request                      XML_trackDailyParam
Response                     XML_trackDailyDistribution

Remarks
The <ID> in the request URL refers to the recording channel ID.

15.2.40 /ISAPI/ContentMgmt/search
Search for specified resources.

Request URL Definition
                      Table 15-59 GET or POST /ISAPI/ContentMgmt/search
Method                       GET or POST
Description                  Search for specific resources.
Query                        None.
Request                      XML_CMSearchDescription
Response                     Succeeded: XML_CMSearchResult
                             Failed: XML_ResponseStatus

Example
Sample Code for Searching Video Files Stored in Device
POST /ISAPI/ContentMgmt/search HTTP/1.1
Host: 10.17.132.49
Content-Length: 493
Connection: Keep-Alive
Authorization: Digest username="admin",
realm="DS-2CD2F12FWD-IWS",
nonce="4e7a46474e305a454d5445365a4445314e6a51345a54413d",
uri="/ISAPI/ContentMgmt/search",

cnonce="ce22590094d2f2bb352fc3c4cd2a1ca3",
nc=00000019,
response="ad6f2c23636f25c6db5911a113375ea9",
qop="auth"

<?xml version="1.0" encoding="utf-8"?>
<CMSearchDescription>
 <searchID>C77384AD-66A0-0001-E7C2-1151F04F90B0</searchID>
 <trackIDList>
  <trackID>101</trackID>
 </trackIDList>
 <timeSpanList>
  <timeSpan>
   <startTime>2017-03-13T16:00:00Z</startTime>
   <endTime>2017-03-16T15:59:59Z</endTime>
  </timeSpan>
 </timeSpanList>
 <maxResults>40</maxResults>
 <searchResultPostion>0</searchResultPostion>
 <metadataList>
  <metadataDescriptor>//recordType.meta.std-cgi.com</metadataDescriptor>
 </metadataList>
</CMSearchDescription>

HTTP/1.1 200 OK
Date: Wed, 15 Mar 2017 09:40:02 GMT
Connection: close
Content-Length: 1649
Content-Type: application/xml

<?xml version="1.0" encoding="UTF-8"?>
<CMSearchResult version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <searchID>{C77384AD-66A0-0001-E7C2-1151F04F90B0}</searchID>
 <responseStatus>true</responseStatus>
 <responseStatusStrg>OK</responseStatusStrg>
 <numOfMatches>29</numOfMatches>
 <matchList>
  <searchMatchItem>
   <sourceID>{0000000000-0000-0000-0000-000000000000}</sourceID>
   <trackID>101</trackID>
   <timeSpan>
     <startTime>2017-03-14T10:32:01Z</startTime>
     <endTime>2017-03-14T10:40:42Z</endTime>
   </timeSpan>
   <mediaSegmentDescriptor>
     <contentType>video</contentType>
     <codecType>H.264-BP</codecType>
     <playbackURI>rtsp://10.17.132.49/Streaming/tracks/101/?
starttime=20170314T103201Z&amp;endtime=20170314T104042Z&amp;name=ch01_08000000016000000&amp;size
=260358144</playbackURI>
    </mediaSegmentDescriptor>
    <metadataMatches>

     <metadataDescriptor>recordType.meta.isapi.com/timing</metadataDescriptor>
   </metadataMatches>
  </searchMatchItem>
  <searchMatchItem>
   <sourceID>{0000000000-0000-0000-0000-000000000000}</sourceID>
   <trackID>101</trackID>
   <timeSpan>
     <startTime>2017-03-14T10:40:42Z</startTime>
     <endTime>2017-03-14T10:53:14Z</endTime>
    </timeSpan>
    <mediaSegmentDescriptor>
     <contentType>video</contentType>
     <codecType>H.264-BP</codecType>
     <playbackURI>rtsp://10.17.132.49/Streaming/tracks/101/?
starttime=20170314T104042Z&amp;endtime=20170314T105314Z&amp;name=ch01_08000000017000000&amp;size
=260603904</playbackURI>
   </mediaSegmentDescriptor>
   <metadataMatches>
     <metadataDescriptor>recordType.meta.isapi.com/timing</metadataDescriptor>
   </metadataMatches>
  </searchMatchItem>
 </matchList>
</CMSearchResult>

15.2.41 /ISAPI/ContentMgmt/search/profile
Get video search conditions.

Request URL Definition
                       Table 15-60 GET /ISAPI/ContentMgmt/search/profile
Method                         GET
Description                    Get video search conditions.
Query                          None.
Request                        None.
Response                       Succeeded: XML_CMSearchProfile
                               Failed: XML_ResponseStatus

15.2.42 /ISAPI/ContentMgmt/security/logSearch
Search for security logs.

Request URL Definition
                    Table 15-61 POST /ISAPI/ContentMgmt/security/logSearch
Method                       POST
Description                  Search for security logs.
Query                        None.
Request                      XML_CMSearchDescription
Response                     Succeeded: XML_CMSearchResult
                             Failed: XML_ResponseStatus

15.2.43 /ISAPI/ContentMgmt/SmartSearch
Search for video files by VCA event.

Request URL Definition
                       Table 15-62 POST /ISAPI/ContentMgmt/SmartSearch
Method                       POST
Description                  Search for video files by VCA event.
Query                        None.
Request                      XML_SmartSearchDescription
Response                     XML_SmartSearchResult

15.2.44 /ISAPI/ContentMgmt/SmartSearch/capabilities
Get capability of searching videos by VCA event.

Request URL Definition
                 Table 15-63 GET /ISAPI/ContentMgmt/SmartSearch/capabilities
Method                       GET
Description                  Get capability of searching videos by VCA event.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_SmartSearchDescription

                             Failed: XML_ResponseStatus

15.2.45 /ISAPI/ContentMgmt/Storage/ExtraInfo
Operations about the configuration for storing additional information.

Request URL Definition
                     Table 15-64 GET /ISAPI/ContentMgmt/Storage/ExtraInfo
Method                       GET
Description                  Get the parameters for storing additional information.
Query                        None.
Request                      None.
Response                     Succeeded: XML_ExtraInfo
                             Failed: XML_ResponseStatus
                     Table 15-65 PUT /ISAPI/ContentMgmt/Storage/ExtraInfo
Method                       PUT
Description                  Set the parameters for storing additional information.
Query                        None.
Request                      XML_ExtraInfo
Response                     XML_ResponseStatus

15.2.46 /ISAPI/ContentMgmt/Storage/ExtraInfo/capabilities
Get the capability of storing additional information.

Request URL Definition
              Table 15-66 GET /ISAPI/ContentMgmt/Storage/ExtraInfo/capabilities
Method                       GET
Description                  Get the capability of storing additional information.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_ExtraInfo
                             Failed: XML_ResponseStatus

15.2.47 /ISAPI/ContentMgmt/Storage/hdd
Get configuration parameters of all HDDs.

Request URL Definition
                       Table 15-67 GET /ISAPI/ContentMgmt/Storage/hdd
Method                      GET
Description                 Get configuration parameters of all HDDs.
Query                       None.
Request                     None.
Response                    Succeeded: XML_hddList
                            Failed: XML_ResponseStatus

15.2.48 /ISAPI/ContentMgmt/Storage/hdd/<ID>
Get and set parameters for a specific HDD.

Request URL Definition
                    Table 15-68 GET /ISAPI/ContentMgmt/Storage/hdd/<ID>
Method                      GET
Description                 Get parameters for a specific HDD.
Query                       None.
Request                     None.
Response                    Succeeded: XML_hdd
                            Failed: XML_ResponseStatus
                    Table 15-69 PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>
Method                      PUT
Description                 Set parameters for a specific HDD.
Query                       None.
Request                     XML_hdd
Response                    XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the HDD ID.

15.2.49 /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/pause
Pause checking bad sectors of a HDD.

Request URL Definition
        Table 15-70 PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/pause
Method                      PUT
Description                 Pause checking bad sectors of a HDD.
Query                       None.
Request                     None.
Response                    XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the HDD No.

15.2.50 /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/resume
Resume checking dad sectors of a HDD.

Request URL Definition
        Table 15-71 PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/resume
Method                      PUT
Description                 Resume checking dad sectors of a HDD.
Query                       None.
Request                     None.
Response                    XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the HDD No.

15.2.51 /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/start
Start checking bad sectors of a HDD.

Request URL Definition
          Table 15-72 PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/start
Method                      PUT
Description                 Start checking bad sectors of a HDD.
Query                       None.
Request                     XML_BadSectorsTest
Response                    XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the HDD No.

15.2.52 /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/status
Get bad sector checking status of a HDD.

Request URL Definition
        Table 15-73 GET /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/status
Method                      GET
Description                 Get bad sector checking status of a HDD.
Query                       None.
Request                     None.
Response                    Succeeded: XML_BadSectorsTestStatus
                            Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the HDD No.

15.2.53 /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/stop
Stop checking bad sectors of a HDD.

Request URL Definition
          Table 15-74 PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/stop
Method                      PUT
Description                 Stop checking bad sectors of a HDD.
Query                       None.
Request                     None.
Response                    XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the HDD No.

15.2.54 /ISAPI/ContentMgmt/Storage/hdd/<ID>/encryptFormat?format=json
Format an encrypted HDD.

Request URL Definition
     Table 15-75 PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/encryptFormat?format=json
Method                      PUT
Description                 Format an encrypted HDD.
Query                       security: the version No. of encryption scheme. When security does
                            not exist, it indicates that the data is not encrypted; when security is
                            1, it indicates that the nodes of sensitive information in the message
                            are encrypted in AES128 CBC mode; when security is 2, it indicates
                            that the nodes of sensitive information in the message are encrypted
                            in AES256 CBC mode.
                            iv: the initialization vector, and it is required when security is 1 or 2.
                            format: determine the format of request or response message.
Request                     JSON_EncryptFormat
Response                    JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the HDD ID.

15.2.55 /ISAPI/ContentMgmt/Storage/hdd/<ID>/encryptVerfy?format=json
Verify the HDD encryption password.

Request URL Definition
      Table 15-76 PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/encryptVerfy?format=json
Method                       PUT
Description                  Verify the HDD encryption password.
Query                        security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
                             format: determine the format of request or response message.
Request                      JSON_EncryptVerfy
Response                     JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the HDD ID.

15.2.56 /ISAPI/ContentMgmt/Storage/hdd/<ID>/formatStatus
Get the formatting status of a specific HDD.

Request URL Definition
              Table 15-77 GET /ISAPI/ContentMgmt/Storage/hdd/<ID>/formatStatus
Method                       GET
Description                  Get the formatting status of a specific HDD.
Query                        None.
Request                      None.
Response                     Succeeded: XML_formatStatus
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the HDD ID.

15.2.57 /ISAPI/ContentMgmt/Storage/hdd/<ID>/format?formatType=
Format a specific HDD according to the specified formatting type. This URL is only available for SD
card.

Request URL Definition
          Table 15-78 PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/format?formatType=
Method                       PUT
Description                  Format a specific HDD according to the specified formatting type.
Query                        formatType: formatting type, the available values are "EXT4" and
                             "FAT32". But if you adopt the default formatting type "FAT32", this
                             query parameter is not required in the URL.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the HDD ID.

15.2.58 /ISAPI/ContentMgmt/Storage/hdd/SMARTTest/config
Operations about the configuration of HDD SMART status detection.

Request URL Definition
              Table 15-79 GET /ISAPI/ContentMgmt/Storage/hdd/SMARTTest/config
Method                       GET
Description                  Get the parameters of HDD SMART status detection.
Query                        None.
Request                      None.
Response                     Succeeded: XML_SMARTTestConfig
                             Failed: XML_ResponseStatus

              Table 15-80 PUT /ISAPI/ContentMgmt/Storage/hdd/SMARTTest/config
Method                       PUT
Description                  Set the parameters of HDD SMART status detection.
Query                        None.
Request                      XML_SMARTTestConfig
Response                     XML_ResponseStatus

15.2.59 /ISAPI/ContentMgmt/Storage/hdd/<ID>/SMARTTest/start
Start checking HDD status.

Request URL Definition
           Table 15-81 PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/SMARTTest/start
Method                       PUT
Description                  Start checking HDD status.
Query                        None.
Request                      XML_HDDSMARTTest
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the HDD No.

15.2.60 /ISAPI/ContentMgmt/Storage/hdd/<ID>/SMARTTest/status
Get HDD checking status.

Request URL Definition
           Table 15-82 GET /ISAPI/ContentMgmt/Storage/hdd/<ID>/SMARTTest/status
Method                       GET
Description                  Get HDD checking status.
Query                        None.
Request                      None.
Response                     Succeeded: XML_SMARTTestStatus
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the HDD No.

15.2.61 /ISAPI/ContentMgmt/Storage/hdd/capabilities
Get HDD management capability.

Request URL Definition
                   Table 15-83 GET /ISAPI/ContentMgmt/Storage/hdd/capabilities
Method                       GET
Description                  Get HDD management capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_hddList
                             Failed: XML_ResponseStatus

15.2.62 /ISAPI/ContentMgmt/Storage/hdd/format
Format all HDDs.

Request URL Definition
                    Table 15-84 PUT /ISAPI/ContentMgmt/Storage/hdd/format
Method                       PUT
Description                  Format all HDDs.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

15.2.63 /ISAPI/ContentMgmt/Storage/hdd/specifyHddFormat?format=json
Specify multiple HDDs to be formatted.

Request URL Definition
      Table 15-85 PUT /ISAPI/ContentMgmt/Storage/hdd/specifyHddFormat?format=json
Method                       PUT
Description                  Specify multiple HDDs to format.
Query                        format: determine the format of request or response message.
Request                      JSON_HddFormatList
Response                     JSON_ResponseStatus

15.2.64 /ISAPI/ContentMgmt/Storage/quota
Get parameters of all HDD quotas.

Request URL Definition
                      Table 15-86 GET /ISAPI/ContentMgmt/Storage/quota
Method                       GET
Description                  Get parameters of all HDD quotas.
Query                        None.
Request                      None.
Response                     Succeeded: XML_diskQuota
                             Failed: XML_ResponseStatus

15.3 /ISAPI/Event

15.3.1 /ISAPI/Event/capabilities
Get the device event capability set.

Request URL Definition
                             Table 15-87 GET /ISAPI/Event/capabilities
Method                       GET
Description                  Get the device event capability set.
Query                        None.

Request                      None.
Response                     Succeeded: XML_EventCap
                             Failed: XML_ResponseStatus

15.3.2 /ISAPI/Event/channels/<ID>/capabilities
Get event capabilities supported by the channel.

Request URL Definition
                    Table 15-88 GET /ISAPI/Event/channels/<ID>/capabilities
Method                       GET
Description                  Get event capabilities supported by the channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_ChannelEventCap
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the URL refers to the channel ID.

15.3.3 /ISAPI/Event/IOT/channels/<ID>/capabilities?format=json
Get the event capabilities supported by IoT device channel.

Request URL Definition
           Table 15-89 GET /ISAPI/Event/IOT/channels/<ID>/capabilities?format=json
Method                       GET
Description                  Get the event capabilities supported by IoT device channel.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_IOTChannelEventCap
                             Filed: JSON_ResponseStatus

15.3.4 /ISAPI/Event/notification/alertStream
Get the uploaded heartbeat or alarm/event information.

Request URL Definition
                       Table 15-90 GET /ISAPI/Event/notification/alertStream
Method                         GET
Description                    Get the heartbeat or uploaded alarm/event information.
Query                          None.
Request                        None.
Response                       Option 1: XML_EventNotificationAlert_AlarmEventInfo or
                               XML_EventNotificationAlert_HeartbeatInfo
                               Option 2: JSON_EventNotificationAlert_Alarm/EventInfo

                                    Note
                               The messages here only show the format of alarm/event
                               information to be uploaded. For details, refer to the corresponding
                               alarm/event configuration chapters.

Remarks
• After calling this URL, a persistent connection is set up between the device and the platform, and
  the alarm or event information will be uploaded from device continuously once the alarm is
  triggered or event occurred.
• You can check if the XML response message is the heartbeat information according to the nodes
  <eventType> and <eventState>. If the values of these two node are "videoloss" and "inactive",
  respectively, the returned message is the heartbeat information.

15.3.5 /ISAPI/Event/notification/httpHosts
Get or set parameters of all listening servers, add a listening server, and delete all listening servers.

Request URL Definition
                        Table 15-91 GET /ISAPI/Event/notification/httpHosts
Method                        GET
Description                   Get parameters of all listening servers.

Query                     security: the version No. of encryption scheme. When security does
                          not exist, it indicates that the data is not encrypted; when security is
                          1, it indicates that the nodes of sensitive information in the message
                          are encrypted in AES128 CBC mode; when security is 2, it indicates
                          that the nodes of sensitive information in the message are encrypted
                          in AES256 CBC mode.
Request                   None.
Response                  Succeeded: XML_HttpHostNotificationList
                          Failed: XML_ResponseStatus
                    Table 15-92 PUT /ISAPI/Event/notification/httpHosts
Method                    PUT
Description               Set parameters of all listening servers.
Query                     security: the version No. of encryption scheme. When security does
                          not exist, it indicates that the data is not encrypted; when security is
                          1, it indicates that the nodes of sensitive information in the message
                          are encrypted in AES128 CBC mode; when security is 2, it indicates
                          that the nodes of sensitive information in the message are encrypted
                          in AES256 CBC mode.
Request                   XML_HttpHostNotificationList
Response                  XML_ResponseStatus
                   Table 15-93 POST /ISAPI/Event/notification/httpHosts
Method                    POST
Description               Add a listening server.
Query                     security: the version No. of encryption scheme. When security does
                          not exist, it indicates that the data is not encrypted; when security is
                          1, it indicates that the nodes of sensitive information in the message
                          are encrypted in AES128 CBC mode; when security is 2, it indicates
                          that the nodes of sensitive information in the message are encrypted
                          in AES256 CBC mode.
Request                   XML_HttpHostNotification
Response                  XML_ResponseStatus
                   Table 15-94 DELETE /ISAPI/Event/notification/httpHosts
Method                    DELETE
Description               Delete all listening servers.

Query                          None.
Request                        None.
Response                       XML_ResponseStatus

15.3.6 /ISAPI/Event/notification/httpHosts/<ID>/test
Check if the listening server is working normally.

Request URL Definition
                 Table 15-95 POST /ISAPI/Event/notification/httpHosts/<ID>/test
Method                         POST
Description                    Check if the listening server is working normally.
Query                          None.
Request                        XML_HttpHostNotification
Response                       Succeeded: XML_HttpHostTestResult
                               Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the listening server ID.

15.3.7 /ISAPI/Event/notification/httpHosts/capabilities
Get the configuration capabilities of all listening servers.

Request URL Definition
                 Table 15-96 GET /ISAPI/Event/notification/httpHosts/capabilities
Method                         GET
Description                    Get the configuration capabilities of all listening servers.
Query                          None.
Request                        None.
Response                       Succeeded: XML_HttpHostNotificationCap
                               Failed: XML_ResponseStatus

15.3.8 /ISAPI/Event/notification/subscribeEvent
Subscribe events/alarms in arming mode.

Request URL Definition
                   Table 15-97 POST /ISAPI/Event/notification/subscribeEvent
Method                       POST
Description                  Subscribe events/alarms in arming mode.
Query                        None.
Request                      XML_SubscribeEvent
Response                     Succeeded: XML_SubscribeEventResponse or
                             XML_EventNotificationAlert_SubscriptionHeartbeat or Alarm/
                             Event Details Message
                             Failed: XML_ResponseStatus

Remarks
The XML_EventNotificationAlert_SubscriptionHeartbeat and Alarm/Event Details Message is
uploaded repeatedly, and the default time interval of uploading heartbeat information is 30s.

15.3.9 /ISAPI/Event/notification/subscribeEvent/<ID>
Operations about configuring alarm/event subscription parameters.

Request URL Definition
                 Table 15-98 GET /ISAPI/Event/notification/subscribeEvent/<ID>
Method                      GET
Description                 Get alarm/event subscription parameters.
Query                       None.
Request                     None.
Response                    Succeeded: XML_SubscribeEvent
                            Failed: XML_ResponseStatus
                 Table 15-99 PUT /ISAPI/Event/notification/subscribeEvent/<ID>
Method                      PUT
Description                 Set alarm/event subscription parameters.

Query                        None.
Request                      XML_SubscribeEvent
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the subscription No. which is returned by the device. After
the persistent connection for receiving events or alarms in arming mode is closed, the device will
release the resource used by the <ID>.

15.3.10 /ISAPI/Event/notification/subscribeEventCap
Get event/alarm subscription capability.

Request URL Definition
                 Table 15-100 GET /ISAPI/Event/notification/subscribeEventCap
Method                       GET
Description                  Get event/alarm subscription capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_SubscribeEventCap
                             Failed: XML_ResponseStatus

15.3.11 /ISAPI/Event/notification/unSubscribeEvent
Cancel subscribing alarm/event.

Request URL Definition
                  Table 15-101 PUT /ISAPI/Event/notification/unSubscribeEvent
Method                       PUT
Description                  Cancel subscribing alarm/event.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

15.3.12 /ISAPI/Event/schedules/<EventType>/<ID>
Operations about arming schedule of specified event type.

Request URL Definition
                  Table 15-102 GET /ISAPI/Event/schedules/<EventType>/<ID>
Method                       GET
Description                  Get the arming schedule of specified event type.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Schedule
                             Failed: XML_ResponseStatus
                  Table 15-103 PUT /ISAPI/Event/schedules/<EventType>/<ID>
Method                       PUT
Description                  Set the arming schedule of specified event type.
Query                        None.
Request                      XML_Schedule
Response                     XML_ResponseStatus

Remarks
The <EventType> in the URL is defined as the specified event type.
The <ID> in the URL is defined as the ID of channel, which is triggered by alarm.

15.3.13 /ISAPI/Event/triggers/hdBadBlock
Operations about the linkage configuration of the HDD bad sector detection.

Request URL Definition
                       Table 15-104 GET /ISAPI/Event/triggers/hdBadBlock
Method                       GET
Description                  Get the linkage parameters of the HDD bad sector detection.
Query                        None.

Request                     None.
Response                    Succeeded: XML_EventTrigger
                            Failed: XML_ResponseStatus
                      Table 15-105 PUT /ISAPI/Event/triggers/hdBadBlock
Method                      PUT
Description                 Set the linkage parameters of the HDD bad sector detection.
Query                       None.
Request                     XML_EventTrigger
Response                    XML_ResponseStatus

15.3.14 /ISAPI/Event/triggers/hdImpact
Operations about the linkage configuration of the HDD impact detection.

Request URL Definition
                       Table 15-106 GET /ISAPI/Event/triggers/hdImpact
Method                      GET
Description                 Get the linkage parameters of the HDD impact detection.
Query                       None.
Request                     None.
Response                    Succeeded: XML_EventTrigger
                            Failed: XML_ResponseStatus
                       Table 15-107 PUT /ISAPI/Event/triggers/hdImpact
Method                      PUT
Description                 Set the linkage parameters of the HDD impact detection.
Query                       None.
Request                     XML_EventTrigger
Response                    XML_ResponseStatus

15.3.15 /ISAPI/Event/triggers/highHDTemperature
Operations about the linkage configuration of the HDD high temperature detection.

Request URL Definition
                  Table 15-108 GET /ISAPI/Event/triggers/highHDTemperature
Method                      GET
Description                 Get the linkage parameters of the HDD high temperature detection.
Query                       None.
Request                     None.
Response                    Succeeded: XML_EventTrigger
                            Failed: XML_ResponseStatus
                  Table 15-109 PUT /ISAPI/Event/triggers/highHDTemperature
Method                      PUT
Description                 Set the linkage parameters of the HDD high temperature detection.
Query                       None.
Request                     XML_EventTrigger
Response                    XML_ResponseStatus

15.3.16 /ISAPI/Event/triggers/lowHDTemperature
Operations about the linkage configuration of the HDD low temperature detection.

Request URL Definition
                  Table 15-110 GET /ISAPI/Event/triggers/lowHDTemperature
Method                      GET
Description                 Get the linkage parameters of the HDD low temperature detection.
Query                       None.
Request                     None.
Response                    Succeeded: XML_EventTrigger
                            Failed: XML_ResponseStatus
                  Table 15-111 PUT /ISAPI/Event/triggers/lowHDTemperature
Method                      PUT
Description                 Set the linkage parameters of the HDD low temperature detection.
Query                       None.

Request                     XML_EventTrigger
Response                    XML_ResponseStatus

15.3.17 /ISAPI/Event/triggers/severeHDFailure
Operations about the linkage configuration of the HDD severe fault detection.

Request URL Definition
                    Table 15-112 GET /ISAPI/Event/triggers/severeHDFailure
Method                      GET
Description                 Get the linkage parameters of the HDD severe fault detection.
Query                       None.
Request                     None.
Response                    Succeeded: XML_EventTrigger
                            Failed: XML_ResponseStatus
                    Table 15-113 PUT /ISAPI/Event/triggers/severeHDFailure
Method                      PUT
Description                 Set the linkage parameters of the HDD severe fault detection.
Query                       None.
Request                     XML_EventTrigger
Response                    XML_ResponseStatus

15.3.18 /ISAPI/Event/triggers/<ID>
Operations about linkage action configuration of an alarm.

Request URL Definition
                          Table 15-114 GET /ISAPI/Event/triggers/<ID>
Method                      GET
Description                 Get the linkage actions of an alarm.
Query                       None.
Request                     None.
Response                    Succeeded: XML_EventTrigger

                             Failed: XML_ResponseStatus
                           Table 15-115 PUT /ISAPI/Event/triggers/<ID>
Method                       PUT
Description                  Set the linkage actions for an alarm.
Query                        None.
Request                      XML_EventTrigger
Response                     XML_ResponseStatus
                         Table 15-116 DELETE /ISAPI/Event/triggers/<ID>
Method                       DELETE
Description                  Delete the linkage actions of an alarm.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL is defined as the No. of the alarm triggered channel. For example, if
the No. of the video input channel triggered by face capture alarm is 1, the <ID> is "faceSnap-1".

15.3.19 /ISAPI/Event/triggers/<ID>/notifications
Operations about configurations of alarm/event linkage actions.

Request URL Definition
                    Table 15-117 GET /ISAPI/Event/triggers/<ID>/notifications
Method                       GET
Description                  Get the configuration parameters of alarm/event linkage actions.
Query                        None.
Request                      None.
Response                     Succeeded: XML_EventTriggerNotificationList
                             Failed: XML_ResponseStatus

                    Table 15-118 PUT /ISAPI/Event/triggers/<ID>/notifications
Method                       PUT
Description                  Set the configuration parameters for alarm/event linkage actions.
Query                        None.
Request                      XML_EventTriggerNotificationList
Response                     XML_ResponseStatus
                  Table 15-119 DELETE /ISAPI/Event/triggers/<ID>/notifications
Method                       DELETE
Description                  Delete the configuration parameters of alarm/event linkage actions.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to No. of alarm triggered channel.

15.3.20 /ISAPI/Event/triggersCap/IOT
Get the alarm linkage configuration capability of IoT device.

Request URL Definition
                          Table 15-120 GET /ISAPI/Event/triggersCap/IOT
Method                       GET
Description                  Get the alarm linkage configuration capability of IoT device.
Query                        None.
Request                      None.
Response                     XML_IOTTriggersCap

15.3.21 /ISAPI/Event/triggers/notifications/AudioAlarm?format=json
Operations about audible warning configuration.

Request URL Definition
          Table 15-121 GET /ISAPI/Event/triggers/notifications/AudioAlarm?format=json
Method                       GET
Description                  Get parameters of audible warning.
Query                        format: determine the format of request or response message.
                             alarmType: alarm type, including "behavior"-behavior analysis,
                             "thermometry"-thermometry, "dynamicFire"-​fire detection,
                             "smokingMode"-smoke detection.
Request                      None.
Response                     JSON_AudioAlarm

      Note
For example, if you want to get the audible warning parameters of thermometry, the request URL
is: GET /ISAPI/Event/triggers/notifications/AudioAlarm?format=json&alarmType=thermometry

          Table 15-122 PUT /ISAPI/Event/triggers/notifications/AudioAlarm?format=json
Method                       PUT
Description                  Set parameters of audible warning.
Query                        format: determine the format of request or response message.
Request                      JSON_AudioAlarm
Response                     JSON_ResponseStatus

15.3.22 /ISAPI/Event/triggers/notifications/AudioAlarm/capabilities?format=json
Get audible warning configuration capability.

Request URL Definition
  Table 15-123 GET /ISAPI/Event/triggers/notifications/AudioAlarm/capabilities?format=json
Method                       GET
Description                  Get audible warning configuration capability.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_AudioAlarmCap

15.3.23 /ISAPI/Event/triggers/notifications/whiteLightAlarm?format=json
Operations about configuration of supplement light alarm linkage.

Request URL Definition
      Table 15-124 GET /ISAPI/Event/triggers/notifications/whiteLightAlarm?format=json
Method                       GET
Description                  Get parameters of supplement light alarm linkage.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_WhiteLightAlarm
      Table 15-125 PUT /ISAPI/Event/triggers/notifications/whiteLightAlarm?format=json
Method                       PUT
Description                  Set parameters of supplement light alarm linkage.
Query                        format: determine the format of request or response message.
Request                      JSON_WhiteLightAlarm
Response

15.3.24 /ISAPI/Event/triggers/notifications/whiteLightAlarm/capabilities?
format=json
Get the configuration capability of supplement light alarm linkage.

Request URL Definition
Table 15-126 GET /ISAPI/Event/triggers/notifications/whiteLightAlarm/capabilities?format=json
Method                       GET
Description                  Get the configuration capability of supplement light alarm linkage.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_WhiteLightAlarmCap

15.3.25 /ISAPI/Event/triggersCap
Get configuration capability of alarm linkage actions.

Request URL Definition
                            Table 15-127 GET /ISAPI/Event/triggersCap
Method                       GET
Description                  Get configuration capability of alarm linkage actions.
Query                        None.
Request                      None.
Response                     Succeeded: XML_EventTriggersCap
                             Failed: XML_ResponseStatus

15.3.26 http://ipAddress:portNo/url
Listening sever sends alarm information to alarm center.

Request URL Definition
                          Table 15-128 POST http://ipAddress:portNo/url
Method                         POST
Description                    Listening sever sends alarm information to alarm center.
Query                          None.
Request                        None.
Response                       Succeeded: XML_EventNotificationAlert_AlarmEventInfo or
                               JSON_EventNotificationAlert_Alarm/EventInfo
                               Failed: XML_ResponseStatus

Remarks
The default port number in the URL is 80, so the URL without port No. is also valid.

15.4 /ISAPI/Image

15.4.1 /ISAPI/Image/channels
Operations about image configuration of all channels.

Request URL Definition
                            Table 15-129 GET /ISAPI/Image/channels
Method                      GET
Description                 Get image parameters of all channels.
Query                       None.
Request                     None.
Response                    Succeeded: XML_ImageChannellist
                            Failed: XML_ResponseStatus
                            Table 15-130 PUT /ISAPI/Image/channels
Method                      GET
Description                 Set image parameters of all channels.
Query                       None.
Request                     XML_ImageChannellist
Response                    XML_ResponseStatus

15.4.2 /ISAPI/Image/channels/<ID>
Operations about image configuration of a specific channel.

Request URL Definition
                         Table 15-131 GET /ISAPI/Image/channels/<ID>
Method                      GET
Description                 Get image parameters of a specific channel.
Query                       None.
Request                     None.
Response                    Succeeded: XML_ImageChannel

                             Failed: XML_ResponseStatus
                         Table 15-132 PUT /ISAPI/Image/channels/<ID>
Method                       PUT
Description                  Set image parameters of a specific channel.
Query                        None.
Request                      XML_ImageChannel
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.3 /ISAPI/Image/channels/<ID>/BLC
Operations about BLC (Blacklist Compensation) configuration of a specific channel.

Request URL Definition
                       Table 15-133 GET /ISAPI/Image/channels/<ID>/BLC
Method                       GET
Description                  Get BLC (Blacklist Compensation) parameters of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_BLC
                             Failed: XML_ResponseStatus
                       Table 15-134 PUT /ISAPI/Image/channels/<ID>/BLC
Method                       PUT
Description                  Set BLC (Blacklist Compensation) parameters of a specific channel.
Query                        None.
Request                      XML_BLC
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.4 /ISAPI/Image/channels/<ID>/capabilities
Get image configuration capability of a specific channel.

Request URL Definition
                   Table 15-135 GET /ISAPI/Image/channels/<ID>/capabilities
Method                             GET
Description                        Get image configuration capability of a specific channel.
Query                              None.
Request                            None.
Response                           XML_Cap_ImageChannel

Remarks
The <ID> in the request URL refers to the channel No.

15.4.5 /ISAPI/Image/channels/<ID>/capturemode
Operations about video input mode configuration of a specific channel.

Request URL Definition
                  Table 15-136 GET /ISAPI/Image/channels/<ID>/capturemode
Method                       GET
Description                  Get video input modes of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_CaptureMode
                             Failed: XML_ResponseStatus
                  Table 15-137 PUT /ISAPI/Image/channels/<ID>/capturemode
Method                       PUT
Description                  Set video input mode of a specific channel.
Query                        None.
Request                      XML_CaptureMode
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.6 /ISAPI/Image/channels/<ID>/color
Operations about the image adjustment parameters of a specific channel.

Request URL Definition
                      Table 15-138 GET /ISAPI/Image/channels/<ID>/color
Method                       GET
Description                  Get the image adjustment parameters of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Color
                             Failed: XML_ResponseStatus
                      Table 15-139 PUT /ISAPI/Image/channels/<ID>/color
Method                       PUT
Description                  Set the image adjustment parameters of a specific channel.
Query                        None.
Request                      XML_Color
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.4.7 /ISAPI/Image/channels/<ID>/color/capabilities
Get the image adjustment capability of a specified channel.

Request URL Definition
                Table 15-140 GET /ISAPI/Image/channels/<ID>/color/capabilities
Method                       GET
Description                  Get the image adjustment capability of a specified channel.
Query                        None.

Request                      None.
Response                     XML_Cap_Color

Remarks
The <ID> in the request URL refers to the channel No.

15.4.8 /ISAPI/Image/channels/<ID>/corridor
Operations about image rotate mode configuration of a specific channel.

Request URL Definition
                     Table 15-141 GET /ISAPI/Image/channels/<ID>/corridor
Method                       GET
Description                  Get image rotate mode of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_corridor
                             Failed: XML_ResponseStatus
                     Table 15-142 PUT /ISAPI/Image/channels/<ID>/corridor
Method                       PUT
Description                  Get image rotate mode of a specific channel.
Query                        None.
Request                      XML_corridor
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.9 /ISAPI/Image/channels/<ID>/dehaze
Operations about defog mode configuration of a specific channel.

Request URL Definition
                     Table 15-143 GET /ISAPI/Image/channels/<ID>/dehaze
Method                       GET
Description                  Get defog mode parameters of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Dehaze
                             Failed: XML_ResponseStatus
                     Table 15-144 PUT /ISAPI/Image/channels/<ID>/dehaze
Method                       PUT
Description                  Set defog mode parameters of a specific channel.
Query                        None.
Request                      XML_Dehaze
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.10 /ISAPI/Image/channels/<ID>/EPTZ
Get or set the e-PTZ configuration.

Request URL Definition
                       Table 15-145 GET /ISAPI/Image/channels/<ID>/EPTZ
Method                       GET
Description                  Get the e-PTZ parameters.
Query                        None.
Request                      None.
Response                     Succeeded: XML_EPTZ
                             Failed: XML_ResponseStatus

                      Table 15-146 PUT /ISAPI/Image/channels/<ID>/EPTZ
Method                      PUT
Description                 Set the e-PTZ parameters.
Query                       None.
Request                     XML_EPTZ
Response                    XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.4.11 /ISAPI/Image/channels/<ID>/EPTZ/mode/capabilities?format=json
Get the capability of switching e-PTZ mode.

Request URL Definition
      Table 15-147 GET /ISAPI/Image/channels/<ID>/EPTZ/mode/capabilities?format=json
Method                      GET
Description                 Get the capability of switching e-PTZ mode.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    Succeeded: JSON_EPTZModeCap
                            Failed: JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.4.12 /ISAPI/Image/channels/<ID>/EPTZ/mode?format=json
Get or set the configuration for switching e-PTZ mode.

Request URL Definition
              Table 15-148 GET /ISAPI/Image/channels/<ID>/EPTZ/mode?format=json
Method                      GET
Description                 Get the parameters of switching e-PTZ mode.
Query                       format: determine the format of request or response message.

Request                     None.
Response                    Succeeded: JSON_EPTZMode
                            Failed: JSON_ResponseStatus
              Table 15-149 PUT /ISAPI/Image/channels/<ID>/EPTZ/mode?format=json
Method                      PUT
Description                 Set the parameters for switching e-PTZ mode.
Query                       format: determine the format of request or response message.
Request                     JSON_EPTZMode
Response                    JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.4.13 /ISAPI/Image/channels/<ID>/exposure
Operations about exposure mode configuration of a specific channel.

Request URL Definition
                     Table 15-150 GET /ISAPI/Image/channels/<ID>/exposure
Method                      GET
Description                 Get the exposure mode of a specific channel.
Query                       None.
Request                     None.
Response                    Succeeded: XML_Exposure
                            Failed: XML_ResponseStatus
                     Table 15-151 PUT /ISAPI/Image/channels/<ID>/exposure
Method                      PUT
Description                 Set the exposure mode of a specific channel.
Query                       None.
Request                     XML_Exposure
Response                    XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.14 /ISAPI/Image/channels/<ID>/focusConfiguration
Get or set the focus parameters of a specified channel.

Request URL Definition
                Table 15-152 GET /ISAPI/Image/channels/<ID>/focusConfiguration
Method                       GET
Description                  Get the focus parameters of a specified channel.
Query                        None.
Request                      None.
Response                     XML_FocusConfiguration
               Table 15-153 PUT /ISAPI/Image/channels/<ID>/focusConfiguration
Method                       PUT
Description                  Set the focus parameters of a specified channel.
Query                        None.
Request                      XML_FocusConfiguration
Response                     XML_ResponseStatus

15.4.15 /ISAPI/Image/channels/<ID>/focusConfiguration/capabilities
Get the focus configuration capability.

Request URL Definition
          Table 15-154 GET /ISAPI/Image/channels/<ID>/focusConfiguration/capabilities
Method                       GET
Description                  Get the focus configuration capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_FocusConfiguration
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.4.16 /ISAPI/Image/channels/<ID>/gain
Operations about gain configuration in exposure of a specific channel.

Request URL Definition
                       Table 15-155 GET /ISAPI/Image/channels/<ID>/gain
Method                       GET
Description                  Get gain parameters in exposure of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Gain
                             Failed: XML_ResponseStatus
                       Table 15-156 PUT /ISAPI/Image/channels/<ID>/gain
Method                       PUT
Description                  Set gain parameters in exposure of a specific channel.
Query                        None.
Request                      XML_Gain
Response                     XML_ResponseStatus

Remarks
• The <ID> in the request URL refers to the channel ID.
• PUT method is only valid when the node <ExposureType> in the message XML_Exposure is set
  to "GainFirst".

15.4.17 /ISAPI/Image/channels/<ID>/imageCap
Get the image capability of a specific channel.

Request URL Definition
                    Table 15-157 GET /ISAPI/Image/channels/<ID>/imageCap
Method                             GET
Description                        Get the image capability of a specific channel.
Query                              None.
Request                            NULL.
Response                           XML_ImageCap

15.4.18 /ISAPI/Image/channels/<ID>/ImageFlip
Operations about the image flipping status of a specific channel.

Request URL Definition
                    Table 15-158 GET /ISAPI/Image/channels/<ID>/ImageFlip
Method                       GET
Description                  Get the image flipping status of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_ImageFlip
                             Failed: XML_ResponseStatus
                    Table 15-159 PUT /ISAPI/Image/channels/<ID>/ImageFlip
Method                       PUT
Description                  Update the image flipping status of a specific channel.
Query                        None.
Request                      XML_ImageFlip
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.4.19 /ISAPI/Image/channels/<ID>/imageMode/<ID>
Get the default configuration parameters of a specific image mode of a specific channel.

Request URL Definition
                Table 15-160 GET /ISAPI/Image/channels/<ID>/imageMode/<ID>
Method                       GET
Description                  Get the default configuration parameters of a specific image mode of
                             a specific channel.
Query                        None.
Request                      None.
Response                     XML_ImageMode

Remarks
This function is not supported by the traffic camera.

15.4.20 /ISAPI/Image/channels/<ID>/imageModes
Get the default image mode parameters of a specific channel.

Request URL Definition
                   Table 15-161 GET /ISAPI/Image/channels/<ID>/imageModes
Method                       GET
Description                  Get the default image mode parameters of a specific channel.
Query                        None.
Request                      None.
Response                     XML_ImageModeList

Remarks
• This API is used to get default image mode configuration parameters. For different scenes, you
  are recommended to set different image mode parameters for the device.
• The image mode is not supported by the traffic camera.

15.4.21 /ISAPI/Image/channels/<ID>/IrcutFilter
Operations about day/night auto switch configuration of a specific channel.

Request URL Definition
                    Table 15-162 GET /ISAPI/Image/channels/<ID>/IrcutFilter
Method                       GET
Description                  Get day/night auto switch parameters of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_IrcutFilter
                             Failed: XML_ResponseStatus
                    Table 15-163 PUT /ISAPI/Image/channels/<ID>/IrcutFilter
Method                       PUT
Description                  Set day/night auto switch parameters of a specific channel.
Query                        None.
Request                      XML_IrcutFilter
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.22 /ISAPI/Image/channels/<ID>/ISPMode
Operations about the day/night mode configuration of a specific channel.

Request URL Definition
                    Table 15-164 GET /ISAPI/Image/channels/<ID>/ISPMode
Method                       GET
Description                  Get the day/night mode parameters of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_ISPMode
                             Failed: XML_ResponseStatus

                     Table 15-165 PUT /ISAPI/Image/channels/<ID>/ISPMode
Method                       PUT
Description                  Set the day/night mode parameters of a specific channel.
Query                        None.
Request                      XML_ISPMode
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.4.23 /ISAPI/Image/channels/<ID>/lensDistortionCorrection
Get or set parameters of image distortion correction.

Request URL Definition
              Table 15-166 GET /ISAPI/Image/channels/<ID>/lensDistortionCorrection
Method                       GET
Description                  Get parameters of image distortion correction.
Query                        None.
Request                      None.
Response                     Succeeded: XML_LensDistortionCorrection
                             Failed: XML_ResponseStatus
              Table 15-167 PUT /ISAPI/Image/channels/<ID>/lensDistortionCorrection
Method                       PUT
Description                  Set parameters of image distortion correction.
Query                        None.
Request                      XML_LensDistortionCorrection
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the video input channel ID.

15.4.24 /ISAPI/Image/channels/<ID>/lensDistortionCorrection/capabilities
Get capability of image distortion correction.

Request URL Definition
      Table 15-168 GET /ISAPI/Image/channels/<ID>/lensDistortionCorrection/capabilities
Method                       GET
Description                  Get capability of image distortion correction.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_LensDistortionCorrection
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the video input channel ID.

15.4.25 /ISAPI/Image/channels/<ID>/noiseReduce
Operations about 3D DNR (Digital Noise Reduction) configuration in auto mode of a specific
channel.

Request URL Definition
                   Table 15-169 GET /ISAPI/Image/channels/<ID>/noiseReduce
Method                       GET
Description                  Get 3D DNR (Digital Noise Reduction) parameters in auto mode of a
                             specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_NoiseReduce
                             Failed: XML_ResponseStatus
                   Table 15-170 PUT /ISAPI/Image/channels/<ID>/noiseReduce
Method                       PUT
Description                  Set 3D DNR (Digital Noise Reduction) parameters in auto mode of a
                             specific channel.

Query                        None.
Request                      XML_NoiseReduce
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.26 /ISAPI/Image/channels/<ID>/Palettes
Get or set the palettes parameters.

Request URL Definition
                     Table 15-171 GET /ISAPI/Image/channels/<ID>/Palettes
Method                       GET
Description                  Get the palettes configuration parameters.
Query                        None.
Request                      None.
Response                     XML_Palettes
                     Table 15-172 PUT /ISAPI/Image/channels/<ID>/Palettes
Method                       PUT
Description                  Set the palettes parameters.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

15.4.27 /ISAPI/Image/channels/<ID>/powerLineFrequency
Operations about image standard configuration of a specific channel.

Request URL Definition
              Table 15-173 GET /ISAPI/Image/channels/<ID>/powerLineFrequency
Method                       GET
Description                  Get image standard parameters of a specific channel.

Query                         None.
Request                       None.
Response                      Succeeded: XML_powerLineFrequency
                              Failed: XML_ResponseStatus
               Table 15-174 PUT /ISAPI/Image/channels/<ID>/powerLineFrequency
Method                        PUT
Description                   Set image standard parameters of a specific channel.
Query                         None.
Request                       XML_powerLineFrequency
Response                      XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.28 /ISAPI/Image/channels/<ID>/regionalFocus
Focus on a specific region during live view.

Request URL Definition
                  Table 15-175 GET /ISAPI/Image/channels/<ID>/regionalFocus
Method                        PUT
Description                   Focus on a specific region during live view.
Query                         None.
Request                       XML_RegionalFocus
Response                      XML_ResponseStatus

Remarks
The <ID> in the URL is the channel ID.

15.4.29 /ISAPI/Image/channels/<ID>/reset
Reset the image parameters of a specific channel.

Request URL Definition
                      Table 15-176 PUT /ISAPI/Image/channels/<ID>/reset
Method                       PUT
Description                  Reset the image parameters of a specific channel.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.30 /ISAPI/Image/channels/<ID>/restore
Restore the image parameters of a specific channel to default settings.

Request URL Definition
                     Table 15-177 PUT /ISAPI/Image/channels/<ID>/restore
Method                       PUT
Description                  Restore the image parameters of a specific channel to default
                             settings.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.31 /ISAPI/Image/channels/<ID>/sharpness
Operations about the sharpness parameters of s specific channel.

Request URL Definition
                    Table 15-178 GET /ISAPI/Image/channels/<ID>/sharpness
Method                       GET
Description                  Get the sharpness parameters of s specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Sharpness
                             Failed: XML_ResponseStatus
                    Table 15-179 PUT /ISAPI/Image/channels/<ID>/sharpness
Method                       PUT
Description                  Set the sharpness parameters of s specific channel.
Query                        None.
Request                      XML_Sharpness
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.32 /ISAPI/Image/channels/<ID>/shutter
Operations about shutter configuration in exposure of a specific channel.

Request URL Definition
                     Table 15-180 GET /ISAPI/Image/channels/<ID>/shutter
Method                       GET
Description                  Get shutter parameters in exposure of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Shutter
                             Failed: XML_ResponseStatus

                     Table 15-181 PUT /ISAPI/Image/channels/<ID>/shutter
Method                       PUT
Description                  Set shutter parameters in exposure of a specific channel.
Query                        None.
Request                      XML_Shutter
Response                     XML_ResponseStatus

Remarks
• The <ID> in the request URL refers to the channel ID.
• PUT method is only valid when the node <ExposureType> in the message XML_Exposure is set
  to "ShutterFirst".

15.4.33 /ISAPI/Image/channels/<ID>/SupplementLight
Get or set supplement light parameters by channel.

Request URL Definition
                Table 15-182 GET /ISAPI/Image/channels/<ID>/SupplementLight
Method                       GET
Description                  Get supplement light parameters by channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_SupplementLight
                             Failed: XML_ResponseStatus
                Table 15-183 PUT /ISAPI/Image/channels/<ID>/SupplementLight
Method                       PUT
Description                  Set supplement light parameters by channel.
Query                        None.
Request                      XML_SupplementLight
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.34 /ISAPI/Image/channels/<ID>/SupplementLight/capabilities
Get supplement light configuration capability by channel.

Request URL Definition
          Table 15-184 GET /ISAPI/Image/channels/<ID>/SupplementLight/capabilities
Method                       GET
Description                  Get supplement light configuration capability by channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_SupplementLight
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.35 /ISAPI/Image/channels/<ID>/targetEnhancement
Get or set the target enhancement parameters.

Request URL Definition
               Table 15-185 GET /ISAPI/Image/channels/<ID>/targetEnhancement
Method                       GET
Description                  Get the target enhancement parameters.
Query                        None.
Request                      None.
Response                     Succeeded: XML_TargetEnhancement
                             Failed: XML_ResponseStatus
               Table 15-186 PUT /ISAPI/Image/channels/<ID>/targetEnhancement
Method                       PUT
Description                  Set the target enhancement parameters.
Query                        None.

Request                     XML_TargetEnhancement
Response                    XML_ResponseStatus

Remarks
• This URL is used in combination with URL /ISAPI/Image/channels/<ID> .
• The <ID> in the request URL refers to the channel No.

15.4.36 /ISAPI/Image/channels/<ID>/targetEnhancement/capabilities
Get the target enhancement capability.

Request URL Definition
         Table 15-187 GET /ISAPI/Image/channels/<ID>/targetEnhancement/capabilities
Method                      GET
Description                 Get the target enhancement capability.
Query                       None.
Request                     None.
Response                    Succeeded: XML_TargetEnhancementCap
                            Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.4.37 /ISAPI/Image/channels/<ID>/tempRange
Operation about temperature range parameters of the specified channel.

Request URL Definition
                   Table 15-188 GET /ISAPI/Image/channels/<ID>/tempRange
Method                      GET
Description                 Get the temperature range parameters.
Query                       None.
Request                     None.
Response                    Succeeded: XML_tempRange
                            Failed: XML_ResponseStatus

                   Table 15-189 PUT /ISAPI/Image/channels/<ID>/tempRange
Method                       PUT
Description                  Set the temperature range parameters.
Query                        None.
Request                      None.
Response                     Succeeded: XML_tempRange
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.4.38 /ISAPI/Image/channels/<ID>/tempRange/capabilities
Get the temperature range configuration capability of a specified channel.

Request URL Definition
                                        Table 15-190 GET
Method                       GET
Description                  Get the temperature range configuration capability of a specified
                             channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_tempRange
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.4.39 /ISAPI/Image/channels/<ID>/WDR
Operations about the WRD (Wide Dynamic Range) configuration of a specific channel.

Request URL Definition
                      Table 15-191 GET /ISAPI/Image/channels/<ID>/WDR
Method                       GET
Description                  Get WRD (Wide Dynamic Range) parameters of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_WDR
                             Failed: XML_ResponseStatus
                      Table 15-192 PUT /ISAPI/Image/channels/<ID>/WDR
Method                       GET
Description                  Set WRD (Wide Dynamic Range) parameters of a specific channel.
Query                        None.
Request                      XML_WDR
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.4.40 /ISAPI/Image/channels/<ID>/whiteBalance
Operations about the white balance parameters of s specific channel.

Request URL Definition
                  Table 15-193 GET /ISAPI/Image/channels/<ID>/whiteBalance
Method                       GET
Description                  Get the white balance parameters of s specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_WhiteBalance
                             Failed: XML_ResponseStatus

                    Table 15-194 PUT /ISAPI/Image/channels/<ID>/whiteBalance
Method                       PUT
Description                  Set the white balance parameters of s specific channel.
Query                        None.
Request                      XML_WhiteBalance
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.5 /ISAPI/SDT

15.5.1 /ISAPI/SDT/Management/capabilities?format=json
Get the intelligent management capability of the device.

Request URL Definition
               Table 15-195 GET /ISAPI/SDT/Management/capabilities?format=json
Method                       GET
Description                  Get the intelligent management capability of the device to check the
                             intelligent functions supported by the device.
Query                        None.
Request                      None.
Response                     JSON_Cap_IntelliManagement

15.5.2 /ISAPI/SDT/Management/EventSearch?format=json
Search for event.

Request URL Definition
              Table 15-196 POST /ISAPI/SDT/Management/EventSearch?format=json
Method                       POST
Description                  Search for event.
Query                        format: determine the format of request or response message.

Request                      JSON_EventSearchCond
Response                     Succeeded: JSON_EventSearchResult
                             Failed: JSON_ResponseStatus

15.5.3 /ISAPI/SDT/Management/EventSearch/capabilities?format=json
Get the event search capability.

Request URL Definition
        Table 15-197 GET /ISAPI/SDT/Management/EventSearch/capabilities?format=json
Method                       GET
Description                  Get the event search capability.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_EventSearchCap

15.5.4 /ISAPI/SDT/Management/IntelligentSearch/export/stop?format=json
Stop exporting the VCA search result.

Request URL Definition
     Table 15-198 PUT /ISAPI/SDT/Management/IntelligentSearch/export/stop?format=json
Method                       PUT
Description                  Stop exporting the VCA search result.
Query                        format: determine the format of request or response message.
Request                      JSON_StopTaskCond
Response                     JSON_ResponseStatus

15.5.5 /ISAPI/SDT/Management/IntelligentSearch/export?format=json
Export the VCA search result.

Request URL Definition
        Table 15-199 POST /ISAPI/SDT/Management/IntelligentSearch/export?format=json
Method                       POST
Description                  Export the VCA search result.
Query                        format: determine the format of request or response message.
Request                      JSON_VCASearchExportCond
Response                     JSON_VCASearchExportTaskInfo

15.5.6 /ISAPI/SDT/Management/IntelligentSearch/export/progress?
format=json&taskID=
Get the progress of exporting VCA search result.

Request URL Definition
          Table 15-200 GET /ISAPI/SDT/Management/IntelligentSearch/export/progress?
                                     format=json&taskID=
Method                       GET
Description                  Get the progress of exporting VCA search result.
Query                        format: determine the format of request or response message.
                             taskID: the task ID of exporting intelligent search result, it is returned
                             in JSON_VCASearchExportTaskInfo .
Request                      None.
Response                     JSON_VCASearchExportProgress

15.5.7 /ISAPI/SDT/Management/IntelligentSearch/capabilities?format=json
Get the VCA search capabilities.

Request URL Definition
     Table 15-201 GET /ISAPI/SDT/Management/IntelligentSearch/capabilities?format=json
Method                       GET
Description                  Get VCA search capabilities.
Query                        format: determine the format of request or response message.

Request                      None.
Response                     Succeeded: JSON_IntelligentSearchCap
                             Failed: JSON_ResponseStatus

15.5.8 /ISAPI/SDT/Management/IntelligentSearch?format=json
Start VCA search.

Request URL Definition
           Table 15-202 POST /ISAPI/SDT/Management/IntelligentSearch?format=json
Method                       POST
Description                  Start VCA search.
Query                        format: determine the format of request or response message.
Request                      JSON_IntelligentSearchCondition
Response                     Succeeded: JSON_IntelligentSearchResult
                             Failed: JSON_ResponseStatus

15.6 /ISAPI/PTZCtrl

15.6.1 /ISAPI/PTZCtrl/channels/<ID>
Get or set the single PTZ control parameters.

Request URL Definition
                         Table 15-203 GET /ISAPI/PTZCtrl/channels/<ID>
Method                       GET
Description                  Get the single PTZ control parameters.
Query                        None
Request                      None
Response                     Succeeded: XML_PTZChannel
                             Failed: XML_ResponseStatus

                           Table 15-204 PUT /ISAPI/PTZCtrl/channels/<ID>
Method                         PUT
Description                    Set the single PTZ control parameters.
Query                          None
Request                        XML_PTZChannel
Response                       XML_ResponseStatus

Remarks
The <ID> in the URL refers to the channel No.

15.6.2 /ISAPI/PTZCtrl/channels/<ID>/auxcontrols
Get or set all PTZ auxiliaries status.

Request URL Definition
                    Table 15-205 GET /ISAPI/PTZCtrl/channels/<ID>/auxcontrols
Method                         GET
Description                    Get all PTZ auxiliaries status.
Query                          None.
Request                        None.
Response                       Succeeded: XML_PTZAuxList
                               Failed: XML_ResponseStatus
                    Table 15-206 PUT /ISAPI/PTZCtrl/channels/<ID>/auxcontrols
Method                         PUT
Description                    Set all PTZ auxiliaries status.
Query                          None.
Request                        XML_PTZAuxList
Response                       XML_ResponseStatus

Remarks
The <ID> in the URL refers to the channel No.

15.6.3 /ISAPI/PTZCtrl/channels/<ID>/auxcontrols/<ID>
Get or set the specified PTZ auxiliary status.

Request URL Definition
                Table 15-207 GET /ISAPI/PTZCtrl/channels/<ID>/auxcontrols/<ID>
Method                        GET
Description                   Get the specified PTZ auxiliary status.
Query                         None.
Request                       None.
Response                      Succeeded: XML_PTZAux
                              Failed: XML_ResponseStatus
                Table 15-208 PUT /ISAPI/PTZCtrl/channels/<ID>/auxcontrols/<ID>
Method                        PUT
Description                   Set the specified PTZ auxiliary status.
Query                         None.
Request                       XML_PTZAux
Response                      XML_ResponseStatus

Remarks
• The first <ID> in the URL refers to the channel number.
• The second <ID> in refers to the auxiliary number, e.g., when there is only one wiper, the second
  <ID> is "1", when there are multiple wipers, the second <ID> varies according to the
  requirement.

15.6.4 /ISAPI/PTZCtrl/channels/<ID>/capabilities
Get the PTZ control capabilities.

Request URL Definition
                     Table 15-209 GET /ISAPI/PTZCtrl/channels/ID/capabilities
Method                        GET
Description                   Get the PTZ control capabilities.
Query                         None

Request                       None.
Response                      Succeeded: XML_PTZChanelCap
                              Failed: XML_ResponseStatus

15.6.5 /ISAPI/PTZCtrl/channels/<ID>/EagleFocusing/auto/capabilities?format=json
Get the capability of rapid focus automatic calibration.

Request URL Definition
 Table 15-210 GET /ISAPI/PTZCtrl/channels/<ID>/EagleFocusing/auto/capabilities?format=json
Method                        GET
Description                   Get the capability of rapid focus automatic calibration.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_AutoEagleFocusingCap
                              Failed: JSON_ResponseStatus

Remarks
The <ID> in the URL refers to the channel ID.

15.6.6 /ISAPI/PTZCtrl/channels/<ID>/EagleFocusing/auto?format=json
Automatically calibrate for rapid focus.

Request URL Definition
        Table 15-211 GET /ISAPI/PTZCtrl/channels/<ID>/EagleFocusing/auto?format=json
Method                        GET
Description                   Automatically calibrate for rapid focus.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_AutoEagleFocusing
                              Failed: JSON_ResponseStatus

Remarks
The <ID> in the URL refers to the channel ID.

15.6.7 /ISAPI/PTZCtrl/channels/<ID>/EagleFocusing/capabilities
Get the rapid focus capability.

Request URL Definition
           Table 15-212 GET /ISAPI/PTZCtrl/channels/<ID>/EagleFocusing/capabilities
Method                        GET
Description                   Get the rapid focus capability.
Query                         None.
Request                       None.
Response                      Succeeded: XML_Cap_EagleFocusing
                              Failed: XML_ResponseStatus

Remarks
The <ID> in the URL refers to the channel ID.

15.6.8 /ISAPI/PTZCtrl/channels/<ID>/lensCorrection/capabilities?format=json
Get the lens correction capability.

Request URL Definition
    Table 15-213 GET /ISAPI/PTZCtrl/channels/<ID>/lensCorrection/capabilities?format=json
Method                        GET
Description                   Get the lens correction capability.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      JSON_LensCorrectionCap

15.6.9 /ISAPI/PTZCtrl/channels/<ID>/lensCorrection?format=json
Get or set the configuration parameters of lens correction.

Request URL Definition
           Table 15-214 GET /ISAPI/PTZCtrl/channels/<ID>/lensCorrection?format=json
Method                       GET
Description                  Get the configuration parameters of lens correction.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_LensCorrection
                             Failed: XML_ResponseStatus
          Table 15-215 PUT /ISAPI/PTZCtrl/channels/<ID>/lensCorrection?format=json
Method                       PUT
Description                  Set the lens correction parameters.
Query                        format: determine the format of request or response message.
Request                      JSON_LensCorrection
Response                     XML_ResponseStatus

15.6.10 /ISAPI/PTZCtrl/channels/<ID>/lockPTZ
Operations about locking PTZ of a specific channel.

Request URL Definition
                    Table 15-216 GET /ISAPI/PTZCtrl/channels/<ID>/lockPTZ
Method                       GET
Description                  Get the remaining time before unlocking PTZ of a specific channel.
Query                        None.
Request                      None.
Response                     XML_LockPTZ
                    Table 15-217 PUT /ISAPI/PTZCtrl/channels/<ID>/lockPTZ
Method                       PUT
Description                  Lock PTZ of a specific channel.
Query                        None.

Request                       XML_LockPTZ
Response                      XML_ResponseStatus

15.6.11 /ISAPI/PTZCtrl/channels/<ID>/maxelevation
Get or set the max. tilt-angle parameters.

Request URL Definition
                  Table 15-218 GET /ISAPI/PTZCtrl/channels/<ID>/maxelevation
Method                        GET
Description                   Get the max. tilt-​angle configuration parameters
Query                         None.
Request                       None.
Response                      XML_MaxElevation
                  Table 15-219 PUT /ISAPI/PTZCtrl/channels/<ID>/maxelevation
Method                        PUT
Description                   Set the max. tilt-​angle
Query                         None.
Request                       XML_MaxElevation
Response                      XML_ResponseStatus

Remarks
The <ID> in the URL indicates the channel ID.

15.6.12 /ISAPI/PTZCtrl/channels/<ID>/maxelevation/capabilities
Get the max. tilt-angle capability.

Request URL Definition
            Table 15-220 GET /ISAPI/PTZCtrl/channels/<ID>/maxelevation/capabilities
Method                        GET
Description                   Get the max. tilt-​angle capability.
Query                         None.

Request                      None.
Response                     XML_Cap_MaxElevation

Remarks
The <ID> in the URL indicates the channel ID.

15.6.13 /ISAPI/PTZCtrl/channels/<ID>/onepushfoucs/reset
Initialize the lens.

Request URL Definition
                Table 15-221 PUT /ISAPI/PTZCtrl/channels/<ID>/onepushfoucs/reset
Method                       PUT
Description                  Initialize the lens.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.6.14 /ISAPI/PTZCtrl/channels/<ID>/PTZOSDDisplay
Get or set the on-screen display parameters of the PTZ status.

Request URL Definition
                   Table 15-222 GET /ISAPI/PTZCtrl/channels/<ID>/PTZOSDDisplay
Method                       GET
Description                  Get the on-screen display parameters of the PTZ status.
Query                        None.
Request                      None.
Response                     Succeeded: XML_PTZOSDDisplay
                             Failed: XML_ResponseStatus

                Table 15-223 PUT /ISAPI/PTZCtrl/channels/<ID>/PTZOSDDisplay
Method                      PUT
Description                 Set the on-screen display parameters of the PTZ status.
Query                       None.
Request                     XML_PTZOSDDisplay
Response                    XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the PTZ channel No.

15.6.15 /ISAPI/PTZCtrl/channels/<ID>/save
Get and save the PTZ position information of the current channel.

Request URL Definition
                      Table 15-224 GET /ISAPI/PTZCtrl/channels/<ID>/save
Method                      GET
Description                 Get and save the PTZ position information (including panning, tilting,
                            and zooming parameters) of the current channel.
Query                       None.
Request                     None.
Response                    Succeeded: XML_PTZStatus
                            Failed: XML_ResponseStatus

15.6.16 /ISAPI/PTZCtrl/channels/<ID>/save?format=json
Save the PTZ position information of the current channel.

Request URL Definition
               Table 15-225 PUT /ISAPI/PTZCtrl/channels/<ID>/save?format=json
Method                      PUT
Description                 Save the PTZ position information, including panning, tilting, and
                            zooming parameters, of the current channel.
Query                       format: determine the format of request or response message.

Request                      None.
Response                     JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the PTZ channel No.

15.6.17 /ISAPI/PTZCtrl/channels/<ID>/status
Get the PTZ status of a specific channel of the device.

Request URL Definition
                      Table 15-226 GET /ISAPI/PTZCtrl/channels/<ID>/status
Method                       GET
Description                  Get the PTZ status of a specific channel of the device.
Query                        None.
Request                      None.
Response                     Succeeded: XML_PTZStatus
                             Failed: XML_ResponseStatus

15.6.18 /ISAPI/PTZCtrl/channels/<ID>/zoomFocus
Operations about zoom and focus coordinates configuration for zoom camera module.

Request URL Definition
                   Table 15-227 GET /ISAPI/PTZCtrl/channels/<ID>/zoomFocus
Method                       GET
Description                  Get parameters of zoom and focus coordinates of zoom camera
                             module.
Query                        None.
Request                      None.
Response                     XML_ZoomFocus

                   Table 15-228 PUT /ISAPI/PTZCtrl/channels/<ID>/zoomFocus
Method                       PUT
Description                  Set parameters of zoom and focus coordinates of zoom camera
                             module.
Query                        None.
Request                      XML_ZoomFocus
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel ID.

15.7 /ISAPI/Security

15.7.1 /ISAPI/Security/adminAccesses
Get or set parameters of all protocols supported by device.

Request URL Definition
                        Table 15-229 GET /ISAPI/Security/adminAccesses
Method                       GET
Description                  Get parameters of all protocols supported by device.
Query                        None.
Request                      None.
Response                     Succeeded: XML_AdminAccessProtocolList
                             Failed: XML_ResponseStatus
                        Table 15-230 PUT /ISAPI/Security/adminAccesses
Method                       PUT
Description                  Set parameters of all protocols supported by device.
Query                        None.
Request                      XML_AdminAccessProtocolList
Response                     XML_ResponseStatus

15.7.2 /ISAPI/Security/adminAccesses/<ID>
Get or set the parameters of a specific protocol that supported by device.

Request URL Definition
                      Table 15-231 GET /ISAPI/Security/adminAccesses/<ID>
Method                       GET
Description                  Get the parameters of a specific protocol that supported by device.
Query                        None.
Request                      None.
Response                     Succeeded: XML_AdminAccessProtocol
                             Failed: XML_ResponseStatus
                      Table 15-232 PUT /ISAPI/Security/adminAccesses/<ID>
Method                       PUT
Description                  Set the parameters of a specific protocol that supported by device.
Query                        None.
Request                      XML_AdminAccessProtocol
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the protocol ID.

15.7.3 /ISAPI/Security/adminAccesses/capabilities
Get device protocol capability.

Request URL Definition
                  Table 15-233 GET /ISAPI/Security/adminAccesses/capabilities
Method                       GET
Description                  Get device protocol capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_AdminAccessProtocolList

                              Failed: XML_ResponseStatus

15.7.4 /ISAPI/Security/advanced?format=json
Get or set advacned parameters of security.

Request URL Definition
                     Table 15-234 GET /ISAPI/Security/advanced?format=json
Method                        GET
Description                   Get advanced configuration parameters of security.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_SecurityAdvanced
                              Failed: JSON_ResponseStatus
                     Table 15-235 PUT /ISAPI/Security/advanced?format=json
Method                        PUT
Description                   Set advanced parameters of security.
Query                         format: determine the format of request or response message.
Request                       JSON_SecurityAdvanced
Response                      JSON_ResponseStatus

15.7.5 /ISAPI/Security/capabilities
Get the security capability of the device.

Request URL Definition
                           Table 15-236 GET /ISAPI/Security/capabilities
Method                        GET
Description                   Get the security capability of the device.
Query                         username: user name, string, it should be encrypted.
Request                       None.
Response                      Succeeded: XML_SecurityCap
                              Failed: XML_ResponseStatus

15.7.6 /ISAPI/Security/certificate/select/<functinName>?format=json
Get or set the parameters of selecting the certificate.

Request URL Definition
        Table 15-237 GET /ISAPI/Security/certificate/select/<functinName>?format=json
Method                         GET
Description                    Get the parameters of selecting the certificate.
Query                          format: determine the format of request or response message.
Request                        None.
Response                       Succeeded: JSON_CertificateSelect
                               Failed: JSON_ResponseStatus
        Table 15-238 PUT /ISAPI/Security/certificate/select/<functinName>?format=json
Method                         PUT
Description                    Set the parameters of selecting the certificate.
Query                          format: determine the format of request or response message.
Request                        JSON_CertificateSelect
Response                       JSON_ResponseStatus

Remarks
The <functinName> in the request URL refers to the function name.

15.7.7 /ISAPI/Security/certificate/select/capabilities?format=json
Get the capability of selecting the certificate.

Request URL Definition
           Table 15-239 GET /ISAPI/Security/certificate/select/capabilities?format=json
Method                         GET
Description                    Get the capability of selecting the certificate.
Query                          format: determine the format of request or response message.
Request                        None.
Response                       Succeeded: JSON_Cap_CertificateSelect

                             Failed: JSON_ResponseStatus

15.7.8 /ISAPI/Security/challenge
Get the random challenge strings.

Request URL Definition
                           Table 15-240 POST /ISAPI/Security/challenge
Method                       POST
Description                  Get the random challenge strings.
Query                        None.
Request                      XML_PublicKey
Response                     XML_Challenge

15.7.9 /ISAPI/Security/CommuMode/capabilities?format=json
Get the configuration capability of the security mode level of the private protocol.

Request URL Definition
            Table 15-241 GET /ISAPI/Security/CommuMode/capabilities?format=json
Method                       GET
Description                  Get the configuration capability of the security mode level of the
                             private protocol.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_Cap_CommuMode
                             Failed: JSON_ResponseStatus

15.7.10 /ISAPI/Security/CommuMode?format=json
Operations about the configuration of the security mode level of the private protocol.

Request URL Definition
                  Table 15-242 GET /ISAPI/Security/CommuMode?format=json
Method                       GET
Description                  Get the parameters of the security mode level of the private
                             protocol.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_CommuMode
                             Failed: JSON_ResponseStatus
                  Table 15-243 PUT /ISAPI/Security/CommuMode?format=json
Method                       PUT
Description                  Set the parameters of the security mode level of the private protocol.
Query                        format: determine the format of request or response message.
Request                      JSON_CommuMode
Response                     JSON_ResponseStatus

15.7.11 /ISAPI/Security/deviceCertificate
Import network certificate to device.

Request URL Definition
                       Table 15-244 PUT /ISAPI/Security/deviceCertificate
Method                       PUT
Description                  Import network certificate to device.
Query                        None.
Request                      Certificate data (in binary format)
Response                     XML_ResponseStatus

Remarks
• The imported certificate function is determined by "type" in binary certificate data, which
  contains "wpa" (default) and "ieee802.1x". If no value is assigned to this parameter, it indicates
  that the WPA certificate will be imported.
• The imported certificate type is determined by "Content-type" in binary certificate data, which
  contains "x-x509-ca-cert", "x-x509-client-cert", and "x-x509-client-key".

15.7.12 /ISAPI/Security/deviceCertificate/capabilities?format=json
Get the CA (Certificate Authority) certificate capability.

Request URL Definition
           Table 15-245 GET /ISAPI/Security/deviceCertificate/capabilities?format=json
Method                        GET
Description                   Get the CA (Certificate Authority) certificate capability.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_DeviceCertificateCap
                              Failed: JSON_ResponseStatus

15.7.13 /ISAPI/Security/deviceCertificate/certificateRevocation/capabilities?
format=json
Get the configuration capability of the certificate expiry alarm.

Request URL Definition
     Table 15-246 GET /ISAPI/Security/deviceCertificate/certificateRevocation/capabilities?
                                        format=json
Method                        GET
Description                   Get the configuration capability of the certificate expiry alarm.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_CertificateRevocationCap
                              Failed: JSON_ResponseStatus

15.7.14 /ISAPI/Security/deviceCertificate/certificateRevocation?format=json
Get or set the configuration of certificate expiry alarm.

Request URL Definition
     Table 15-247 GET /ISAPI/Security/deviceCertificate/certificateRevocation?format=json
Method                        GET
Description                   Get the parameters of certificate expiry alarm.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_CertificateRevocation
                              Failed: JSON_ResponseStatus
     Table 15-248 PUT /ISAPI/Security/deviceCertificate/certificateRevocation?format=json
Method                        PUT
Description                   Set the parameters of certificate expiry alarm.
Query                         format: determine the format of request or response message.
Request                       JSON_CertificateRevocation
Response                      JSON_ResponseStatus

15.7.15 /ISAPI/Security/deviceCertificate/certificates/<customID>?format=json
Get or delete the information of a specific device certificate.

Request URL Definition
    Table 15-249 GET /ISAPI/Security/deviceCertificate/certificates/<customID>?format=json
Method                        GET
Description                   Get the information of a specific device certificate.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_DeviceCertificate
                              Failed: JSON_ResponseStatus

  Table 15-250 DELETE /ISAPI/Security/deviceCertificate/certificates/<customID>?format=json
Method                         DELETE
Description                    Delete the information of a specific device certificate.
Query                          format: determine the format of request or response message.
Request                        None.
Response                       JSON_ResponseStatus

Remarks
The <customID> in the request URL refers to the custom certificate ID.

15.7.16 /ISAPI/Security/deviceCertificate/certificates/<ID>
Delete the certificate of a specific device.

Request URL Definition
              Table 15-251 DELETE /ISAPI/Security/deviceCertificate/certificates/<ID>
Method                         DELETE
Description                    Delete the certificate of a specific device.
Query                          None.
Request                        None.
Response                       XML_ResponseStatus

Remarks
The <ID> in the request URL is the device ID returned when searching certificate information.

15.7.17 /ISAPI/Security/deviceCertificate/certificates/<ID>/recreate?format=json
Regenerate a specific abnormal certificate.

Request URL Definition
   Table 15-252 PUT /ISAPI/Security/deviceCertificate/certificates/<ID>/recreate?format=json
Method                         PUT
Description                    Regenerate a specific certificate for authentication client.
Query                          format: determine the format of request or response message.

Request                        None.
Response                       JSON_ResponseStatus

Remarks
• The <ID> in the request URL refers to the certificate ID.
• This URL is only supported by HTTPS certificate, and it is available when the certificate exception
  is detected.

15.7.18 /ISAPI/Security/deviceCertificate/certificates/<ID>/status?format=json
Get the status of a specific certificate.

Request URL Definition
    Table 15-253 GET /ISAPI/Security/deviceCertificate/certificates/<ID>/status?format=json
Method                         GET
Description                    Get the status of a specific certificate.
Query                          format: determine the format of request or response message.
Request                        None.
Response                       Succeeded: JSON_DeviceCertificateStatus
                               Failed: JSON_ResponseStatus

Remarks
The <ID> in the request URL is the certificate ID, which is generated and returned by device.

15.7.19 /ISAPI/Security/deviceCertificate/certificates/capabilities?format=json
Get certificate search capability.

Request URL Definition
    Table 15-254 GET /ISAPI/Security/deviceCertificate/certificates/capabilities?format=json
Method                         GET
Description                    Get certificate search capability.
Query                          format: determine the format of request or response message.
Request                        None.
Response                       Succeeded: JSON_DeviceCertificatesCap

                                  Failed: JSON_ResponseStatus

15.7.20 /ISAPI/Security/deviceCertificate/certificates/recreate?format=json
Regenerate all abnormal certificates.

Request URL Definition
      Table 15-255 PUT /ISAPI/Security/deviceCertificate/certificates/recreate?format=json
Method                            PUT
Description                       Regenerate all abnormal certificates.
Query                             format: determine the format of request or response message.
Request                           None.
Response                          JSON_ResponseStatus

Remarks
This URL is only supported by HTTPS certificate, and it is available when the certificate exception is
detected.

15.7.21 /ISAPI/Security/deviceCertificate/certificates/status?format=json
Get status of all certificates.

Request URL Definition
        Table 15-256 GET /ISAPI/Security/deviceCertificate/certificates/status?format=json
Method                            GET
Description                       Get status of all certificates.
Query                             format: determine the format of request or response message.
Request                           None.
Response                          Succeeded: JSON_DeviceCertificateStatusList
                                  Failed: JSON_ResponseStatus

15.7.22 /ISAPI/Security/deviceCertificate/certificates?format=json
Get device certificate information in a batch.

Request URL Definition
           Table 15-257 GET /ISAPI/Security/deviceCertificate/certificates?format=json
Method                         GET
Description                    Get device certificate information in a batch.
Query                          format: determine the format of request or response message.
                               type: certificate type, it can be set to "wpa" (get all WPA certificates),
                               "ieee802.1x" (get all ieee802.1x certificates), and "securityLog" (get
                               all CA certificates of security logs); if no value is assigned to type, all
                               CA certificates will be searched and obtained.
Request                        None.
Response                       Succeeded: JSON_DeviceCertificates
                               Failed: JSON_ResponseStatus

15.7.23 /ISAPI/Security/deviceCertificate?customID=
Import a CA (Certificate Authority) certificate to the device.

Request URL Definition
                  Table 15-258 PUT /ISAPI/Security/deviceCertificate?customID=
Method                         PUT
Description                    Import a CA (Certificate Authority) certificate to the device. The CA
                               certificate is used for 802.1x (radius) with various authentication
                               mechanism.
Query                          customID: custom certificate ID, string, it consists of digits and
                               characters.
Request                        Certificate data (its format depends on the device).
Response                       XML_ResponseStatus

Remarks
• When importing CA certificate by calling this URL, the function of CA certificate will not be
  distinguished. The CA certificate and its function will be bound together afterward.
• The imported certificate type is determined by "Content-type" in the certificate data, which
  contains "x-x509-ca-cert" (CA certificate (root certificate)), "x-x509-client-cert" (client certificate),
  and "x-x509-client-key" (client password).

15.7.24 /ISAPI/Security/doubleVerification/users/<ID>?format=json
Operations about a specified double verification user.

Request URL Definition
          Table 15-259 GET /ISAPI/Security/doubleVerification/users/<ID>?format=json
Method                       GET
Description                  Get a double verification user.
Query                        format: determine the format of request or response message.
                             security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      None.
Response                     JSON_User
          Table 15-260 PUT /ISAPI/Security/doubleVerification/users/<ID>?format=json
Method                       PUT
Description                  Set a double verification user.
Query                        format: determine the format of request or response message.
                             security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      JSON_User
Response                     JSON_ResponseStatus
        Table 15-261 DELETE /ISAPI/Security/doubleVerification/users/<ID>?format=json
Method                       DELETE
Description                  Delete a double verification user.

Query                         format: determine the format of request or response message.
                              security: the version No. of encryption scheme. When security does
                              not exist, it indicates that the data is not encrypted; when security is
                              1, it indicates that the nodes of sensitive information in the message
                              are encrypted in AES128 CBC mode; when security is 2, it indicates
                              that the nodes of sensitive information in the message are encrypted
                              in AES256 CBC mode.
                              iv: the initialization vector, and it is required when security is 1 or 2.
Request                       None.
Response                      JSON_ResponseStatus

Remarks
The <ID> in the URL indicates the user ID.

15.7.25 /ISAPI/Security/doubleVerification/users/capabilities?format=json
Get the double verification configuration capability.

Request URL Definition
      Table 15-262 GET /ISAPI/Security/doubleVerification/users/capabilities?format=json
Method                        GET
Description                   Get the double verification configuration capability.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      JSON_UserCap

15.7.26 /ISAPI/Security/doubleVerification/users?format=json
Get all double verification users and add a double verification user.

Request URL Definition
              Table 15-263 GET /ISAPI/Security/doubleVerification/users?format=json
Method                        GET
Description                   Get all double verification users.
Query                         format: determine the format of request or response message.

                             security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      None.
Response                     JSON_UserList
            Table 15-264 POST /ISAPI/Security/doubleVerification/users?format=json
Method                       POST
Description                  Add a double verification user.
Query                        format: determine the format of request or response message.
                             security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      JSON_User
Response                     Succeeded: JSON_ResponseStatus and JSON_id
                             Failed: JSON_ResponseStatus

15.7.27 /ISAPI/Security/doubleVerification/UsersPermission/<ID>?format=json
Get and set the permission of double verification user.

Request URL Definition
    Table 15-265 GET /ISAPI/Security/doubleVerification/UsersPermission/<ID>?format=json
Method                       GET
Description                  Get the configuration parameters of double verification user
                             permission.
Query                        format: determine the format of request or response message.

Request                      None.
Response                     Succeeded: JSON_UserPermission
                             Failed: JSON_ResponseStatus
    Table 15-266 PUT /ISAPI/Security/doubleVerification/UsersPermission/<ID>?format=json
Method                       PUT
Description                  Set the double verification user permission.
Query                        format: determine the format of request or response message.
Request                      JSON_UserPermission
Response                     JSON_ResponseStatus

Remarks
The <ID> in the URL indicates the user ID.

15.7.28 /ISAPI/Security/doubleVerification/UsersPermission/capabilities?
format=json
Get the capability of permission configuration for double verification user.

Request URL Definition
Table 15-267 GET /ISAPI/Security/doubleVerification/UsersPermission/capabilities?format=json
Method                       GET
Description                  Get the capability of permission configuration for double verification
                             user.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_UserPermissionCap
                             Failed: JSON_ResponseStatus

15.7.29 /ISAPI/Security/doubleVerification?format=json
Get the capability of double verification enabling configuration.

Request URL Definition
                Table 15-268 GET /ISAPI/Security/doubleVerification?format=json
Method                       GET
Description                  Get the capability of double verification enabling configuration.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_DoubleVerification
                Table 15-269 PUT /ISAPI/Security/doubleVerification?format=json
Method                       PUT
Description                  Enable or disable the double verification.
Query                        format: determine the format of request or response message.
Request                      JSON_DoubleVerification
Response                     JSON_ResponseStatus

15.7.30 /ISAPI/Security/email/parameter/capabilities?format=json
Get recovery email configuration capability (only available in LAN and for admin user).

Request URL Definition
          Table 15-270 GET /ISAPI/Security/email/parameter/capabilities?format=json
Method                       GET
Description                  Get recovery email configuration capability.
Query                        format: determine the format of request or response message.
                             security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      None.
Response                     JSON_SecurityEmailCap

15.7.31 /ISAPI/Security/email/parameter?format=json
Operations about recovery email configuration (only available for LAN and for admin user).

Request URL Definition
                Table 15-271 GET /ISAPI/Security/email/parameter?format=json
Method                      GET
Description                 Get recovery email parameters.
Query                       format: determine the format of request or response message.
                            security: the version No. of encryption scheme. When security does
                            not exist, it indicates that the data is not encrypted; when security is
                            1, it indicates that the nodes of sensitive information in the message
                            are encrypted in AES128 CBC mode; when security is 2, it indicates
                            that the nodes of sensitive information in the message are encrypted
                            in AES256 CBC mode.
                            iv: the initialization vector, and it is required when security is 1 or 2.
Request                     None.
Response                    JSON_SecurityEmail
                Table 15-272 PUT /ISAPI/Security/email/parameter?format=json
Method                      PUT
Description                 Set recovery email parameters.
Query                       format: determine the format of request or response message.
                            security: the version No. of encryption scheme. When security does
                            not exist, it indicates that the data is not encrypted; when security is
                            1, it indicates that the nodes of sensitive information in the message
                            are encrypted in AES128 CBC mode; when security is 2, it indicates
                            that the nodes of sensitive information in the message are encrypted
                            in AES256 CBC mode.
                            iv: the initialization vector, and it is required when security is 1 or 2.
Request                     JSON_SecurityEmail
Response                    JSON_ResponseStatus

15.7.32 /ISAPI/Security/email/qrCode?format=json
Get the QR code of the configured recovery email (only available for LAN and for admin user).

Request URL Definition
                  Table 15-273 GET /ISAPI/Security/email/qrCode?format=json
Method                        GET
Description                   Get the QR code of the configured recovery email.
Query                         format: determine the format of request or response message.
                              security: the version No. of encryption scheme. When security does
                              not exist, it indicates that the data is not encrypted; when security is
                              1, it indicates that the nodes of sensitive information in the message
                              are encrypted in AES128 CBC mode; when security is 2, it indicates
                              that the nodes of sensitive information in the message are encrypted
                              in AES256 CBC mode.
                              iv: the initialization vector, and it is required when security is 1 or 2.
Request                       None.
Response                      JSON_SecurityEmailQrCode

15.7.33 /ISAPI/Security/emailCertification?format=json
Reset password by the verification code via recovery email (only available for LAN and for admin
user).

Request URL Definition
                Table 15-274 PUT /ISAPI/Security/emailCertification?format=json
Method                        PUT
Description                   Reset password by the verification code via recovery email.
Query                         format: determine the format of request or response message.
Request                       JSON_EmailCertification
Response                      JSON_ResponseStatus

Remarks
For the encryption of passwords and security answers, first transform them by UTF8, and then
transcode them by BASE64, finally, encrypt them by AES128CB.

15.7.34 /ISAPI/Security/extern/capabilities
Get capability of other security configuration.

Request URL Definition
                       Table 15-275 GET /ISAPI/Security/extern/capabilities
Method                        GET
Description                   Get capability of other security configuration.
Query                         None.
Request                       None.
Response                      XML_externSecurityCap

15.7.35 /ISAPI/Security/illegalLoginLock
Get or set locking parameters of illegal login.

Request URL Definition
                         Table 15-276 GET /ISAPI/Security/illegalLoginLock
Method                        GET
Description                   Get locking parameters of illegal login.
Query                         None.
Request                       None.
Response                      Succeeded: XML_IllegalLoginLock
                              Failed: XML_ResponseStatus
                         Table 15-277 PUT /ISAPI/Security/illegalLoginLock
Method                        PUT
Description                   Set locking parameters of illegal login.
Query                         None.
Request                       XML_IllegalLoginLock
Response                      XML_ResponseStatus

15.7.36 /ISAPI/Security/loginLinkNum?format=json
Get or set maximum number of logged in accounts.

Request URL Definition
                  Table 15-278 GET /ISAPI/Security/loginLinkNum?format=json
Method                       GET
Description                  Get maximum number of logged in accounts.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_LoginLinkNum
                             Failed: JSON_ResponseStatus
                  Table 15-279 PUT /ISAPI/Security/loginLinkNum?format=json
Method                       PUT
Description                  Set maximum number of logged in accounts.
Query                        format: determine the format of request or response message.
Request                      JSON_LoginLinkNum
Response                     JSON_ResponseStatus

15.7.37 /ISAPI/Security/questionConfiguration
Get or set device security questions.

Request URL Definition
                     Table 15-280 GET /ISAPI/Security/questionConfiguration
Method                       GET
Description                  Get device security questions.
Query                        None.
Request                      None.
Response                     Succeeded: XML_SecurityQuestion
                             Failed: XML_ResponseStatus
                     Table 15-281 PUT /ISAPI/Security/questionConfiguration
Method                       PUT
Description                  Set device security questions.

Query                          security: the version No. of encryption scheme. When security does
                               not exist, it indicates that the data is not encrypted; when security is
                               1, it indicates that the nodes of sensitive information in the message
                               are encrypted in AES128 CBC mode; when security is 2, it indicates
                               that the nodes of sensitive information in the message are encrypted
                               in AES256 CBC mode.
                               iv: the initialization vector, and it is required when security is 1 or 2.
Request                        XML_SecurityQuestion
Response                       XML_ResponseStatus

15.7.38 /ISAPI/Security/serverCertificate/capabilities?format=json
Get the client/server certificate capability.

Request URL Definition
           Table 15-282 GET /ISAPI/Security/serverCertificate/capabilities?format=json
Method                         GET
Description                    Get the client/server certificate capability.
Query                          format: determine the format of request or response message.
Request                        None.
Response                       Succeeded: JSON_ServerCertificateCap
                               Failed: JSON_ResponseStatus

15.7.39 /ISAPI/Security/serverCertificate/certificate
Get, upload, and delete device certificate information.

Request URL Definition
                   Table 15-283 GET /ISAPI/Security/serverCertificate/certificate
Method                         GET
Description                    Get device certificate information.
Query                          type: certificate type, it can be set to "CCClentCertificate" (client
                               certificate for CC authentication);​ if no value is assigned to type, it
                               represents the HTTPS certificate.

Request                       None.
Response                      Succeeded: XML_CertificateInfo
                              XML_ResponseStatus
                  Table 15-284 PUT /ISAPI/Security/serverCertificate/certificate
Method                        PUT
Description                   Upload certificate to device.
Query                         type: certificate type, it can be set to "CCClentCertificate" (client
                              certificate for CC authentication);​ if no value is assigned to type, it
                              represents the HTTPS certificate.
Request                       Certificate data (binary)
Response                      XML_ResponseStatus
                 Table 15-285 DELETE /ISAPI/Security/serverCertificate/certificate
Method                        DELETE
Description                   Delete the installed certificate of device.
Query                         type: certificate type, it can be set to "CCClentCertificate" (client
                              certificate for CC authentication);​ if no value is assigned to type, it
                              represents the HTTPS certificate.
Request                       None.
Response                      XML_ResponseStatus

15.7.40 /ISAPI/Security/serverCertificate/certificate?customID=
Import the client/server certificate to the device.

Request URL Definition
           Table 15-286 POST /ISAPI/Security/serverCertificate/certificate?customID=
Method                        POST
Description                   Import the client/server certificate to the device.
Query                         security: the version No. of encryption scheme. When security does
                              not exist, it indicates that the data is not encrypted; when security is
                              1, it indicates that the nodes of sensitive information in the message
                              are encrypted in AES128 CBC mode; when security is 2, it indicates
                              that the nodes of sensitive information in the message are encrypted
                              in AES256 CBC mode.

                              iv: the initialization vector, and it is required when security is 1 or 2.
                              customID: custom certificate ID, string, it consists of digits and
                              characters.
Request                       XML_CertificateReq_ImportCert +certificate data.
Response                      XML_ResponseStatus

Remarks
• When the node <certificateMode> in the request message XML_CertificateReq_ImportCert is
  set to "signingRequest", it means importing a self-signed certificate to the device.
• When the node <certificateMode> in the request message XML_CertificateReq_ImportCert is
  set to "privateKey", it means importing the certificate along with the private key by the following
  two steps.
  1. Import the message XML_CertificateReq_ImportCert and the certificate file.

          Note
     The node <dataType> in the message XML_CertificateReq_ImportCert should be set to
     "certificate".
  2. Import the message XML_CertificateReq_ImportCert and the private key.

         Note
     - The node <dataType> in the message XML_CertificateReq_ImportCert should be set to
       "privateKey".
     - This step depends on the first step. If exception occurs, the device will return error.

15.7.41 /ISAPI/Security/serverCertificate/certificates?format=json
Get the information of multiple client/server certificates in a batch.

Request URL Definition
           Table 15-287 GET /ISAPI/Security/serverCertificate/certificates?format=json
Method                        GET
Description                   Get the information of multiple client/server certificates in a batch.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_ServerCertificates
                              Failed: JSON_ResponseStatus

15.7.42 /ISAPI/Security/serverCertificate/certificates/<customID>?format=json
Get or delete the information of a specific client/server certificate.

Request URL Definition
    Table 15-288 GET /ISAPI/Security/serverCertificate/certificates/<customID>?format=json
Method                        GET
Description                   Get the information of a specific client/server certificate.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_DeviceCertificate
                              Failed: JSON_ResponseStatus
  Table 15-289 DELETE /ISAPI/Security/serverCertificate/certificates/<customID>?format=json
Method                        DELETE
Description                   Delete the information of a specific client/server certificate.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      JSON_ResponseStatus

Remarks
The <customID> in the request URL refers to the custom certificate ID.

15.7.43 /ISAPI/Security/serverCertificate/certSignReq
Get signature request information, generate, and delete signature request of device certificate.

Request URL Definition
                  Table 15-290 GET /ISAPI/Security/serverCertificate/certSignReq
Method                        GET
Description                   Get signature request information of device certificate.
Query                         type: certificate type, it can be set to "CCClentCertificate" (client
                              certificate for CC authentication);​ if no value is assigned to type, it
                              represents the HTTPS certificate.

Request                      None.
Response                     Succeeded: XML_CertificateReqInfo
                             Failed: XML_ResponseStatus
                 Table 15-291 PUT /ISAPI/Security/serverCertificate/certSignReq
Method                       PUT
Description                  Generate signature request information of device certificate.
Query                        type: certificate type, it can be set to "CCClentCertificate" (client
                             certificate for CC authentication);​ if no value is assigned to type, it
                             represents the HTTPS certificate.
Request                      XML_CertificateReq
Response                     XML_ResponseStatus
               Table 15-292 DELETE /ISAPI/Security/serverCertificate/certSignReq
Method                       DELETE
Description                  Delete signature request of device certificate.
Query                        type: certificate type, it can be set to "CCClentCertificate" (client
                             certificate for CC authentication);​ if no value is assigned to type, it
                             represents the HTTPS certificate.
Request                      None.
Response                     XML_ResponseStatus

15.7.44 /ISAPI/Security/serverCertificate/certSignReq?customID=
Create a PKCS#10 signature request of the client/server certificate.

Request URL Defintion
           Table 15-293 POST /ISAPI/Security/serverCertificate/certSignReq?customID=
Method                       POST
Description                  Create a PKCS#10 signature request of the client/server certificate.
Query                        customID: custom certificate ID, string, it consists of digits and
                             characters.
Request                      XML_CertificateReq
Response                     Succeeded: XML_CertificateResult
                             Failed: XML_ResponseStatus

15.7.45 /ISAPI/Security/serverCertificate/downloadCertSignReq
Download the certificate of authentication client.

Request URL Definition
            Table 15-294 GET /ISAPI/Security/serverCertificate/downloadCertSignReq
Method                        GET
Description                   Download the certificate of authenticated client.
Query                         type: certificate type, it can be set to "CCClentCertificate" (client
                              certificate for CC authentication);​ if no value is assigned to type, it
                              represents the HTTPS certificate.
Request                       None.
Response                      Certificate data (binary)

15.7.46 /ISAPI/Security/serverCertificate/downloadCertSignReq?customID=
Export the client/server certificate.

Request URL Definition
      Table 15-295 GET /ISAPI/Security/serverCertificate/downloadCertSignReq?customID=
Method                        GET
Description                   Export the client/server certificate.
Query                         customID: custom certificate ID, string, it consists of digits and
                              characters.
Request                       None.
Response                      Certificate data.

Remarks
The returned certificate data should be either formatted exactly according to PKCS#10 standard or
a PKCS#10 file encoded in PEM format.

15.7.47 /ISAPI/Security/serverCertificate/selfSignCert?customID=
Get or generate the PKCS#10 signature request of the client/server self-signed certificate.

Request URL Definition
           Table 15-296 GET /ISAPI/Security/serverCertificate/selfSignCert?customID=
Method                        GET
Description                   Get the PKCS#10 signature request of the client/server self-signed
                              certificate.
Query                         customID: custom certificate ID, string, it consists of digits and
                              characters.
Request                       None.
Response                      Succeeded: XML_CertificateReq
                              Failed: XML_ResponseStatus
           Table 15-297 PUT /ISAPI/Security/serverCertificate/selfSignCert?customID=
Method                        PUT
Description                   Generate the PKCS#10 signature request of the client/server self-
                              signed certificate.
Query                         customID: custom certificate ID, string, it consists of digits and
                              characters.
Request                       XML_CertificateReq
Response                      XML_ResponseStatus

15.7.48 /ISAPI/Security/userCheck
Log in to the device by digest.

Request URL Definition
                            Table 15-298 GET /ISAPI/Security/userCheck
Method                        GET
Description                   Log in to the device by digest. This URL is used to check whether the
                              user name matches with the password.
Query                         None.
Request                       None.
Response                      Succeeded: XML_userCheck
                              Failed: XML_ResponseStatus

15.7.49 /ISAPI/Security/UserPermission
Operations about the user permission of the device.

Request URL Definition
                        Table 15-299 GET /ISAPI/Security/UserPermission
Method                       GET
Description                  Get the user permission of the device.
Query                        None.
Request                      None.
Response                     Succeeded: XML_UserPermissionList
                             Failed: XML_ResponseStatus
                        Table 15-300 PUT /ISAPI/Security/UserPermission
Method                       PUT
Description                  Set the user permission of the device.
Query                        None.
Request                      XML_UserPermissionList
Response                     XML_ResponseStatus

15.7.50 /ISAPI/Security/UserPermission/<ID>
Operations about a specific user's permission.

Request URL Definition
                     Table 15-301 GET /ISAPI/Security/UserPermission/<ID>
Method                       GET
Description                  Get a specific user's permission.
Query                        None.
Request                      None.
Response                     Succeeded: XML_UserPermission
                             Failed: XML_ResponseStatus

                     Table 15-302 PUT /ISAPI/Security/UserPermission/<ID>
Method                       PUT
Description                  Set a specific user's permission.
Query                        None.
Request                      XML_UserPermission
Response                     XML_ResponseStatus

15.7.51 /ISAPI/Security/UserPermission/<ID>/localPermission
Get and set the local permission of a specified user.

Request URL Definition
              Table 15-303 GET /ISAPI/Security/UserPermission/<ID>/localPermission
Method                       GET
Description                  Get the local permission of a specified user.
Query                        None.
Request                      None.
Response                     XML_localPermission
              Table 15-304 PUT /ISAPI/Security/UserPermission/<ID>/localPermission
Method                       PUT
Description                  Set the local permission of a specified user.
Query                        None.
Request                      XML_localPermission
Response                     XML_ResponseStatus

15.7.52 /ISAPI/Security/UserPermission/<ID>/remotePermission
Get and set the remote permission of a specified user.

Request URL Definition
           Table 15-305 GET /ISAPI/Security/UserPermission/<ID>/remotePermission
Method                       GET
Description                  Get the remote permission of a specified user.
Query                        None.
Request                      None.
Response                     XML_remotePermission
           Table 15-306 PUT /ISAPI/Security/UserPermission/<ID>/remotePermission
Method                       PUT
Description                  Set the remote permission of a specified user.
Query                        None.
Request                      XML_remotePermission
Response                     XML_ResponseStatus

15.7.53 /ISAPI/Security/UserPermission/adminCap
Get the user permission capability of the administrator.

Request URL Definiton
                  Table 15-307 GET /ISAPI/Security/UserPermission/adminCap
Method                       GET
Description                  Get the user permission capability of the administrator.
Query                        None.
Request                      None.
Response                     Succeeded: XML_UserPermissionCap
                             Failed: XML_ResponseStatus

Remarks
Only permissions that can be configured by the admin user should be returned.

15.7.54 /ISAPI/Security/UserPermission/operatorCap
Get the user permission capability of the operator.

Request URL Definition
                 Table 15-308 GET /ISAPI/Security/UserPermission/operatorCap
Method                       GET
Description                  Get the user permission capability of the operator.
Query                        None.
Request                      None.
Response                     Succeeded: XML_UserPermissionCap
                             Failed: XML_ResponseStatus

Remarks
Only permissions that can be configured by the operator should be returned.

15.7.55 /ISAPI/Security/UserPermission/viewerCap
Get the user permission capability of the viewer.

Request URL Definition
                  Table 15-309 GET /ISAPI/Security/UserPermission/viewerCap
Method                       GET
Description                  Get the user permission capability of the viewer.
Query                        None.
Request                      None.
Response                     XML_UserPermissionCap

15.7.56 /ISAPI/Security/users
Operations about the user list of the device.

Request URL Definition
                              Table 15-310 GET /ISAPI/Security/users
Method                       GET
Description                  Get the user list of the device.

Query                    security: the version No. of encryption scheme. When security does
                         not exist, it indicates that the data is not encrypted; when security is
                         1, it indicates that the nodes of sensitive information in the message
                         are encrypted in AES128 CBC mode; when security is 2, it indicates
                         that the nodes of sensitive information in the message are encrypted
                         in AES256 CBC mode.
                         iv: the initialization vector, and it is required when security is 1 or 2.
Request                  None.
Response                 Succeeded: XML_UserList
                         Failed: XML_ResponseStatus
                         Table 15-311 PUT /ISAPI/Security/users
Method                   PUT
Description              Update the user list of the device.
Query                    security: the version No. of encryption scheme. When security does
                         not exist, it indicates that the data is not encrypted; when security is
                         1, it indicates that the nodes of sensitive information in the message
                         are encrypted in AES128 CBC mode; when security is 2, it indicates
                         that the nodes of sensitive information in the message are encrypted
                         in AES256 CBC mode.
                         iv: the initialization vector, and it is required when security is 1 or 2.
Request                  XML_UserList
Response                 XML_ResponseStatus
                         Table 15-312 POST /ISAPI/Security/users
Method                   POST
Description              Add a user to the user list of the device.
Query                    security: the version No. of encryption scheme. When security does
                         not exist, it indicates that the data is not encrypted; when security is
                         1, it indicates that the nodes of sensitive information in the message
                         are encrypted in AES128 CBC mode; when security is 2, it indicates
                         that the nodes of sensitive information in the message are encrypted
                         in AES256 CBC mode.
                         iv: the initialization vector, and it is required when security is 1 or 2.
Request                  XML_User
Response                 XML_ResponseStatus

                              Table 15-313 DELETE /ISAPI/Security/users
Method                         DELETE
Description                    Delete the user list of the device.
Query                          security: the version No. of encryption scheme. When security does
                               not exist, it indicates that the data is not encrypted; when security is
                               1, it indicates that the nodes of sensitive information in the message
                               are encrypted in AES128 CBC mode; when security is 2, it indicates
                               that the nodes of sensitive information in the message are encrypted
                               in AES256 CBC mode.
                               iv: the initialization vector, and it is required when security is 1 or 2.
                               loginPassword: encrypted administrator password.
Request                        None.
Response                       XML_ResponseStatus

Remarks
• A default account "admin" must be provided with the administrator permission and it cannot be
  deleted.
• Passwords can only be uploaded and cannot be displayed when getting the user list of the
  device.
• The user ID should be returned when adding users to the user list.
Example
Sample Code for Adding User
POST /ISAPI/Security/users HTTP/1.1
Host: 10.17.132.49
Content-Length: 335
Connection: Keep-Alive
Authorization: Digest username="admin",
realm="DS-2CD2F12FWD-IWS",
nonce="4e6a4d774d6a63304f544936593255335a474d334f54673d",
uri="/ISAPI/Security/users",
cnonce="178e14d4977c835db891b5392b5d0a67",
nc=00000015,
response="d92518fb00cd2772cf212f5326b251be",
qop="auth"

<?xml version="1.0" encoding="UTF-8"?>
<User>
 <id>0</id>
 <userName>test</userName>
 <password>1qaz2wsx</password>
 <bondIpList>
  <bondIp>
   <id>1</id>

   <ipAddress>0.0.0.0</ipAddress>
   <ipv6Address>::</ipv6Address>
  </bondIp>
 </bondIpList>
 <macAddress></macAddress>
 <userLevel>Operator</userLevel>
 <attribute>
  <inherent>false</inherent>
 </attribute>
</User>

HTTP/1.1 200 OK
Date: Tue, 14 Mar 2017 20:24:31 GMT
Server: App-webs/
Connection: close
Content-Length: 288
Content-Type: application/xml

<?xml version="1.0" encoding="UTF-8"?>
<ResponseStatus version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <requestURL>/ISAPI/Security/users</requestURL>
 <statusCode>1</statusCode>
 <statusString>OK</statusString>
 <id>2</id>
 <subStatusCode>ok</subStatusCode>
</ResponseStatus>

Example
Sample Code for Setting User Permission
PUT /ISAPI/Security/UserPermission/2 HTTP/1.1
Host: 10.17.132.49
Content-Length: 891
Connection: Keep-Alive
Authorization: Digest username="admin",
realm="DS-2CD2F12FWD-IWS",
nonce="4e6a4d774d6a63304f544936593255335a474d334f54673d",
uri="/ISAPI/Security/UserPermission/2",
cnonce="178e14d4977c835db891b5392b5d0a67",
nc=00000016,
response="f69a20db00b36e9bb46c26c06e9bae80",
qop="auth"

<?xml version="1.0" encoding="utf-8"?>
<UserPermission>
 <id>2</id>
 <userID>2</userID>
 <userType>operator</userType>
 <remotePermission>
  <parameterConfig>false</parameterConfig>
  <logOrStateCheck>true</logOrStateCheck>
  <upgrade>false</upgrade>

  <voiceTalk>true</voiceTalk>
  <restartOrShutdown>false</restartOrShutdown>
  <alarmOutOrUpload>false</alarmOutOrUpload>
  <contorlLocalOut>false</contorlLocalOut>
  <transParentChannel>false</transParentChannel>
  <preview>true</preview>
  <record>true</record>
  <ptzControl>true</ptzControl>
  <playBack>true</playBack>
  <videoChannelPermissionList>
   <videoChannelPermission>
    <id>1</id>
    <preview>true</preview>
    <record>true</record>
    <playBack>true</playBack>
   </videoChannelPermission>
  </videoChannelPermissionList>
  <ptzChannelPermissionList>
   <ptzChannelPermission>
    <id>1</id>
    <ptzControl>true</ptzControl>
   </ptzChannelPermission>
  </ptzChannelPermissionList>
 </remotePermission>
</UserPermission>

HTTP/1.1 200 OK
Date: Tue, 14 Mar 2017 20:24:31 GMT
Server: App-webs/
Connection: close
Content-Length: 288
Content-Type: application/xml

<?xml version="1.0" encoding="UTF-8"?>
<ResponseStatus version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <requestURL>/ISAPI/Security/UserPermission/2</requestURL>
 <statusCode>1</statusCode>
 <statusString>OK</statusString>
 <subStatusCode>ok</subStatusCode>
</ResponseStatus>

15.7.57 /ISAPI/Security/users/<ID>
Operations about the user's configuration of the device.

Request URL Definition
                         Table 15-314 GET /ISAPI/Security/users/<ID>
Method                     GET
Description                Get a specific user's configuration of the device.
Query                      security: the version No. of encryption scheme. When security does
                           not exist, it indicates that the data is not encrypted; when security is
                           1, it indicates that the nodes of sensitive information in the message
                           are encrypted in AES128 CBC mode; when security is 2, it indicates
                           that the nodes of sensitive information in the message are encrypted
                           in AES256 CBC mode.
                           iv: the initialization vector, and it is required when security is 1 or 2.
Request                    None.
Response                   Succeeded: XML_User
                           Failed: XML_ResponseStatus
                         Table 15-315 PUT /ISAPI/Security/users/<ID>
Method                     PUT
Description                Set a specific user's configuration of the device.
Query                      security: the version No. of encryption scheme. When security does
                           not exist, it indicates that the data is not encrypted; when security is
                           1, it indicates that the nodes of sensitive information in the message
                           are encrypted in AES128 CBC mode; when security is 2, it indicates
                           that the nodes of sensitive information in the message are encrypted
                           in AES256 CBC mode.
                           iv: the initialization vector, and it is required when security is 1 or 2.
Request                    XML_User
Response                   XML_ResponseStatus
                      Table 15-316 DELETE /ISAPI/Security/users/<ID>
Method                     DELETE
Description                Delete a specific user's configuration of the device.
Query                      security: the version No. of encryption scheme. When security does
                           not exist, it indicates that the data is not encrypted; when security is
                           1, it indicates that the nodes of sensitive information in the message
                           are encrypted in AES128 CBC mode; when security is 2, it indicates

                            that the nodes of sensitive information in the message are encrypted
                            in AES256 CBC mode.
                            iv: the initialization vector, and it is required when security is 1 or 2.
                            loginPassword: encrypted administrator password.
Request                     None.
Response                    XML_ResponseStatus

Remarks
The administrator account cannot be deleted.

15.7.58 /ISAPI/SecurityCP/ReportCenterCfg/capabilities?format=json
Get the configuration capability of the report uploading method.

Request URL Definition
          Table 15-317 GET /ISAPI/SecurityCP/ReportCenterCfg/capabilities?format=json
Method                      GET
Description                 Get the configuration capability of the report uploading method.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    Succeeded: JSON_Cap_ReportCenterCfg
                            Failed: JSON_ResponseStatus

15.7.59 /ISAPI/SecurityCP/ReportCenterCfg/<ID>?format=json
Operations about the configuration of the report uploading method.

Request URL Definition
              Table 15-318 GET /ISAPI/SecurityCP/ReportCenterCfg/<ID>?format=json
Method                      GET
Description                 Get the parameters of the report uploading method.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    Succeeded: JSON_ReportCenterCfg

                              Failed: JSON_ResponseStatus
              Table 15-319 PUT /ISAPI/SecurityCP/ReportCenterCfg/<ID>?format=json
Method                        PUT
Description                   Set the parameters of the report uploading method.
Query                         format: determine the format of request or response message.
Request                       JSON_ReportCenterCfg
Response                      JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the center group No.

15.8 /ISAPI/Smart

15.8.1 /ISAPI/Smart/capabilities
Get the capability set of intelligent devices.

Request URL Definition
                             Table 15-320 GET /ISAPI/Smart/capabilities
Method                        GET
Description                   Get the capability set of intelligent devices.
Query                         None.
Request                       None.
Response                      Succeeded: XML_SmartCap
                              Failed: XML_ResponseStatus

15.9 /ISAPI/Streaming

15.9.1 /ISAPI/Streaming/channels
Operations about the encoding configuration of multiple channels.

Request URL Definition
                          Table 15-321 GET /ISAPI/Streaming/channels
Method                      GET
Description                 Get the encoding parameters of multiple channels.
Query                       None.
Request                     None.
Response                    XML_StreamingChannelList
                          Table 15-322 PUT /ISAPI/Streaming/channels
Method                      PUT
Description                 Set the encoding parameters of multiple channels.
Query                       None.
Request                     XML_StreamingChannelList
Response                    XML_ResponseStatus

15.9.2 /ISAPI/Streaming/channels/<ID>
Operations about the encoding configurations of a specific channel.

Request URL Definition
                       Table 15-323 GET /ISAPI/Streaming/channels/<ID>
Method                      GET
Description                 Get the encoding parameters of a specific channel.
Query                       None.
Request                     None.
Response                    Succeeded: XML_StreamingChannel
                            Failed: XML_ResponseStatus
                       Table 15-324 PUT /ISAPI/Streaming/channels/<ID>
Method                      PUT
Description                 Set the encoding parameters of a specific channel.
Query                       None.

Request                          XML_StreamingChannel
Response                         XML_ResponseStatus
                         Table 15-325 DELETE /ISAPI/Streaming/channels/<ID>
Method                           DELETE
Description                      Delete the encoding parameters of a specific channel.
Query                            None
Request                          None.
Response                         XML_ResponseStatus

Remarks
The <ID> in the URL refers to the channel ID.
Example
Interaction Example of Getting Encoding Parameters of A Specific Channel
GET /ISAPI/Streaming/channels/444 HTTP/1.1
…
HTTP/1.1 200 OK
Content-Type: application/xml; charset=“UTF-8”
Content-Length: ISAPI

<?xml version="1.0" encoding="UTF-8"?>
<StreamingChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id>444</id>
 <channelName>Input 1 MPEG-4 ASP</channelName>
 <enabled>true</enabled>
 <Transport>
  <rtspPortNo>554</rtspPortNo>
  <maxPacketSize>1446</maxPacketSize>
  <ControlProtocolList>
   <ControlProtocol>
    <streamingTransport>RTSP</streamingTransport>
   </ControlProtocol>
   <ControlProtocol>
    <streamingTransport>HTTP</streamingTransport>
   </ControlProtocol>
  </ControlProtocolList>
 </Transport>
 <Video>
  <enabled>true</enabled>
  <videoInputChannelID>2</videoInputChannelID>
  <videoCodecType>MPEG4</videoCodecType>
  <videoScanType>progressive</videoScanType>
  <videoResolutionWidth> 640</videoResolutionWidth>
  <videoResolutionHeight>480</videoResolutionHeight>
  <videoPositionX>0</videoPositionX>

  <videoPositionY>0</videoPositionY>
  <videoQualityControlType>CBR</videoQualityControlType>
  <constantBitRate>2000</constantBitRate>
  <maxFrameRate>2500</maxFrameRate>
  <keyFrameInterval>1000</keyFrameInterval>
  <rotationDegree>0</rotationDegree>
  <mirrorEnabled>false</mirrorEnabled>
  <snapShotImageType>JPEG</snapShotImageType>
 </Video>
 <Audio>
  <enabled>false</enabled>
  <audioInputChannelID>2</audioInputChannelID>
  <audioCompressionType> G.726</audioCompressionType>
  <audioBitRate>24</audioBitRate>
  <audioSamplingRate>8</audioSamplingRate>
 </Audio>
</StreamingChannel>

15.9.3 /ISAPI/Streaming/channels/<ID>/capabilities
Get encoding capability of a specific channel.

Request URL Definition
                   Table 15-326 GET /ISAPI/Streaming/channels/<ID>/capabilities
Method                          GET
Description                     Get the encoding capability of a specific channel.
Query                           None.
Request                         None.
Response                        Succeeded: XML_Cap_StreamingChannel
                                Failed: XML_ResponseStatus

Remarks
The <ID> in the URL refers to the channel ID.
Example
Interaction Example of Getting Encoding Capability of A Specific Channel
GET /ISAPI/Streaming/channels/444/capabilities HTTP/1.1
…
HTTP/1.1 200 OK
Content-Type: application/xml; charset="UTF-8"
Content-Length: ISAPI

<?xml version="1.0" encoding="UTF-8"?>
<StreamingChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">

<id opt="111,222,333,444">444</id>
<channelName min="0" max="64">Input 1 MPEG-4 ASP</channelName>
<enabled opt="true,false" def="true">true</enabled>
<Transport>
 <rtspPortNo min="0" max="65535" def="554">554</rtspPortNo>
 <maxPacketSize min="0" max="1500">1446</maxPacketSize>
 <audioPacketLength min="0" max="5000"/>
 <audioInboundPacketLength min="0" max="5000"/>
 <audioInboundPortNo min="0" max="65535"/>
 <videoSourcePortNo min="0" max="65535"/>
 <audioSourcePortNo min="0" max="65535"/>
 <ControlProtocolList>
  <ControlProtocol>
   <streamingTransport opt="RTSP/RTP,HTTP">RTSP</streamingTransport>
  </ControlProtocol>
  <ControlProtocol>
   <streamingTransport opt="RTSP/RTP,HTTP">HTTP</streamingTransport>
  </ControlProtocol>
 </ControlProtocolList>
 <Unicast>
  <enabled opt="true,false" def="false"/>
  <rtpTransportType opt="RTP/UDP,RTP/TCP"/>
 </Unicast>
 <Multicast>
  <enabled opt="true,false" def="false"/>
  <userTriggerThreshold/>
  <videoDestPortNo min="0" max="65535"/>
  <audioDestPortNo min="0" max="65535"/>
  <destIPAddress min="8" max="16"/>
  <destIPv6Address min="15" max="39"/>
  <ttl min="0" max="127" def="1"/>
 </Multicast>
 <Security>
  <enabled opt="true,false" def="false"/>
 </Security>
</Transport>
<Video>
 <enabled opt="true,false">true</enabled>
 <videoInputChannelID opt="1,2,3,4">2</videoInputChannelID>
 <videoCodecType opt="MJPEG,MPEG4">MPEG4</videoCodecType>
 <videoScanType opt="interlaced,progressive">progressive</videoScanType>
 <videoResolutionWidth min="0" max="640">640</videoResolutionWidth>
 <videoResolutionHeight min="0" max="480">480</videoResolutionHeight>
 <videoPositionX min="0" max="640">0</videoPositionX>
 <videoPositionY min="0" max="480">0</videoPositionY>
 <videoQualityControlType opt="CBR,VBR">CBR</videoQualityControlType>
 <constantBitRate min="50" max="4000" dynamic="true">2000</constantBitRate>
 <maxFrameRate opt="2500,1250,625,312,156,78，830" dynamic="true">2500</maxFrameRate>
 <keyFrameInterval min="0", max="10000">1000</keyFrameInterval>
 <rotationDegree opt="0,90,180,270" def="0">0</rotationDegree>
 <mirrorEnabled opt="true,false" def="false">false</mirrorEnabled>
 <snapShotImageType opt="JPEG" def="JPEG">JPEG</snapShotImageType>

 </Video>
 <Audio>
  <enabled opt="true,false" def="false">false</enabled>
  <audioInputChannelID opt="1,2,3,4">2</audioInputChannelID>
  <audioCompressionType opt="G.726,G.711ulaw" def="G.726">G.726</audioCompressionType>
  <audioBitRate opt="16,24,32,40" def="32" dynamic="true">24</audioBitRate>
  <audioSamplingRate opt="8" dynamic="true">8</audioSamplingRate>
  <audioResolution opt="3,4,5,6" dynamic="true"/>
 </Audio>
</StreamingChannel>

15.9.4 /ISAPI/Streaming/channels/<ID>/dynamicCap
Get the dynamic encoding capability of a specific channel.

Request URL Definition
                 Table 15-327 GET /ISAPI/Streaming/channels/<ID>/dynamicCap
Method                        GET
Description                   Get the dynamic encoding capability of a specific channel.
Query                         None.
Request                       None.
Response                      XML_DynamicCap

Remarks
The <ID> in the URL refers to the channel ID.

15.9.5 /ISAPI/Streaming/channels/<ID>/picture
Manually capture picture in the video stream of a specific channel.

Request URL Definition
                    Table 15-328 GET /ISAPI/Streaming/channels/<ID>/picture
Method                        GET
Description                   Manually capture picture in the video stream of a specific channel.
Query                         (Optional) videoResolutionWidth: width of captured picture
                              resolution.
                              (Optional) videoResolutionHeight: height of captured picture
                              resolution.

                                        (Optional) snapShotImageType: captured picture format, only the
                                        JPEG format is supported.
Request                                 None.
Response                                Picture data, which is transmitted on HTTP.

Remarks
• The <ID> in the request URL refers to the streaming channel ID, which is equal to (channel No. ×
  100 + 1). For example, if a camera only has one channel, its ID is 101.
• This URL only supports capturing picture in main stream, and only JPEG format is supported.
Example
Sample Code for Manually Capturing Picture
GET /ISAPI/Streaming/channels/1/picture HTTP/1.1
Host: 10.17.132.49
Connection: Keep-Alive
Authorization: Digest username="admin",
realm="DS-2CD2F12FWD-IWS",
nonce="4d305134517a55344d6a55365a4445324f544130597a453d",
uri="/ISAPI/Streaming/channels/1/picture",
cnonce="481bb1afa48b24e512778b084bfe4977",
nc=00000001,
response="e5670d5d9d40c522afabb11b5fa35268",
qop="auth"

HTTP/1.1 200 OK
Content-Type: image/jpeg; charset="UTF-8"
Content-Length:19991

......JFIF.............C.
.
...
.. .....'... .)10.)-,3:J>36F7,- (Binary picture data)

15.9.6 /ISAPI/Streaming/channels/<ID>/regionClip
Get or set target cropping parameters by streaming channel.

Request URL Definition
                         Table 15-329 GET /ISAPI/Streaming/channels/<ID>/regionClip
Method                                  GET
Description                             Get target cropping parameters by streaming channel.
Query                                   None.

Request                      None.
Response                     Succeeded: XML_RegionClip
                             Failed: XML_ResponseStatus
                  Table 15-330 PUT /ISAPI/Streaming/channels/<ID>/regionClip
Method                       PUT
Description                  Set target cropping parameters by streaming channel.
Query                        None.
Request                      XML_RegionClip
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to streaming channel ID.

15.9.7 /ISAPI/Streaming/channels/<ID>/regionClip/capabilities
Get configuration capability of target cropping by streaming channel.

Request URL Definition
           Table 15-331 GET /ISAPI/Streaming/channels/<ID>/regionClip/capabilities
Method                       GET
Description                  Get configuration capability of target cropping by streaming channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_RegionClip
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to streaming channel ID.

15.9.8 /ISAPI/Streaming/channels/<ID>/smartOverlap/capabilities?format=json
Get the capability of configuring the stream for displaying VCA rules of smart events.

Request URL Definition
   Table 15-332 GET /ISAPI/Streaming/channels/<ID>/smartOverlap/capabilities?format=json
Method                      GET
Description                 Get the capability of configuring the stream for displaying VCA rules
                            of smart events.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    Succeeded: JSON_SmartOverlapCap
                            Failed: JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.9.9 /ISAPI/Streaming/channels/<ID>/smartOverlap?format=json
Get or set the stream parameters for displaying VCA rules of smart events.

Request URL Definition
          Table 15-333 GET /ISAPI/Streaming/channels/<ID>/smartOverlap?format=json
Method                      GET
Description                 Get the stream parameters for displaying VCA rules of smart events.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    Succeeded: JSON_SmartOverlap
                            Failed: JSON_ResponseStatus
          Table 15-334 PUT /ISAPI/Streaming/channels/<ID>/smartOverlap?format=json
Method                      PUT
Description                 Set the stream parameters for displaying VCA rules of smart events.
Query                       format: determine the format of request or response message.
Request                     JSON_SmartOverlap
Response                    JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.9.10 /ISAPI/Streaming/channels/<ID>/status
Get the streaming or encoding status of a specific channel.

Request URL Definition
                     Table 15-335 GET /ISAPI/Streaming/channels/<ID>/status
Method                       GET
Description                  Get the streaming or encoding status of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_StreamingSessionStatusList
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the streaming channel ID.

15.9.11 /ISAPI/Streaming/encryption/capabilities?format=json
Get stream encryption capability.

Request URL Definition
              Table 15-336 GET /ISAPI/Streaming/encryption/capabilities?format=json
Method                       GET
Description                  Get stream encryption capability.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_EncryptionCap

15.9.12 /ISAPI/Streaming/encryption/secretKey?format=json
Operations about the configuration of stream encryption key.

Request URL Definition
              Table 15-337 GET /ISAPI/Streaming/encryption/secretKey?format=json
Method                      GET
Description                 Get the configuration parameters of stream encryption key.
Query                       format: determine the format of request or response message.
                            security: the version No. of encryption scheme. When security does
                            not exist, it indicates that the data is not encrypted; when security is
                            1, it indicates that the nodes of sensitive information in the message
                            are encrypted in AES128 CBC mode; when security is 2, it indicates
                            that the nodes of sensitive information in the message are encrypted
                            in AES256 CBC mode.
                            iv: the initialization vector, and it is required when security is 1 or 2.
Request                     None.
Response                    JSON_secretKey
              Table 15-338 PUT /ISAPI/Streaming/encryption/secretKey?format=json
Method                      GET
Description                 Set stream encryption key.
Query                       format: determine the format of request or response message.
                            security: the version No. of encryption scheme. When security does
                            not exist, it indicates that the data is not encrypted; when security is
                            1, it indicates that the nodes of sensitive information in the message
                            are encrypted in AES128 CBC mode; when security is 2, it indicates
                            that the nodes of sensitive information in the message are encrypted
                            in AES256 CBC mode.
                            iv: the initialization vector, and it is required when security is 1 or 2.
Request                     JSON_secretKey
Response                    JSON_ResponseStatus

15.9.13 /ISAPI/Streaming/encryption?format=json
Operations about the configuration of stream encryption.

Request URL Definition
                   Table 15-339 GET /ISAPI/Streaming/encryption?format=json
Method                       GET
Description                  Get the configuration parameters of stream encryption.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_EnableEncryption
                  Table 15-340 PUT /ISAPI/Streaming/encryption?format=json
Method                       GET
Description                  Enable stream encryption.
Query                        format: determine the format of request or response message.
Request                      JSON_EnableEncryption
Response                     JSON_ResponseStatus

15.9.14 /ISAPI/Streaming/status
Get the streaming or encoding status of all channels.

Request URL Definition
                            Table 15-341 GET /ISAPI/Streaming/status
Method                       GET
Description                  Get the streaming or encoding status of all channels.
Query                        None.
Request                      None.
Response                     Succeeded: XML_StreamingStatus
                             Failed: XML_ResponseStatus

15.9.15 rtsp://<host>[:port]/ISAPI/Streaming/channels/<ID>
Operations about live view of a specific channel.

Request URL Definition
           Table 15-342 DESCRIBE rtsp://<host>[:port]/ISAPI/Streaming/channels/<ID>
Method                      DESCRIBE
Description                 Get basic parameters for live view.
Query                       None.
Request                     None.
Response                    None.
            Table 15-343 SETUP rtsp://<host>[:port]/ISAPI/Streaming/channels/<ID>
Method                      SETUP
Description                 Get session information for live view.
Query                       None.
Request                     None.
Response                    None.
              Table 15-344 PLAY rtsp://<host>[:port]/ISAPI/Streaming/channels/<ID>
Method                      PLAY
Description                 Start live view.
Query                       None.
Request                     None.
Response                    None.
          Table 15-345 TEARDOW rtsp://<host>[:port]/ISAPI/Streaming/channels/<ID>
Method                      TEARDOW
Description                 Stop live view.
Query                       None.
Request                     None.
Response                    None.

Remarks
The <ID> in the URL is defined as (channel No.)*100+(stream type value).
channel No.

   For analog channel, the No. starts from 1, and for digital channel, the No. starts from the last
   analog channel No.
   E.g., if the device has 16 analog channels and 16 digital channels, the analog channel No. is
   between 1 and 16, and the digital channel No. is between 17 and 32.
stream type value
   The stream type values contain 1, 2, and 3. 1-main stream, 2-sub-stream, 3-third stream.
E.g., if ID is 101, it indicates the main stream of channel No.1; if ID is 102, it indicates the sub-
stream of channel No. 2; if ID is 1601, it indicates the main stream of channel 16;...

15.9.16 rtsp://<host>[:port]/ISAPI/Streaming/channels/<ID>?npq=
Operations about multicast based on network protocol quality (NPQ).

Request URL Definition
        Table 15-346 DESCRIBE rtsp://<host>[:port]/ISAPI/Streaming/channels/<ID>?npq=
Method                        DESCRIBE
Description                   Request for getting basic parameters for multicast based on NPQ.
Query                         npq: Network Protocol Quality (NPQ), this query parameter is used
                              to enable streaming according to NPQ and by FEC (Forward Error
                              Correction) method if its value is set to "fec".
Request                       None.
Response                      None.
          Table 15-347 SETUP rtsp://<host>[:port]/ISAPI/Streaming/channels/<ID>?npq=
Method                        SETUP
Description                   Request for getting session information for multicast based on NPQ.
Query                         npq: Network Protocol Quality (NPQ), this query parameter is used
                              to enable streaming according to NPQ and by FEC (Forward Error
                              Correction) method if its value is set to "fec".
Request                       None.
Response                      None.
          Table 15-348 PLAY rtsp://<host>[:port]/ISAPI/Streaming/channels/<ID>?npq=
Method                        PLAY
Description                   Start multicast based on NPQ.

Query                        npq: Network Protocol Quality (NPQ), this query parameter is used
                             to enable streaming according to NPQ and by FEC (Forward Error
                             Correction) method if its value is set to "fec".
Request                      None.
Response                     None.
       Table 15-349 TEARDOW rtsp://<host>[:port]/ISAPI/Streaming/channels/<ID>?npq=
Method                       TEARDOW
Description                  Stop multicast based on NPQ.
Query                        npq: Network Protocol Quality (NPQ), this query parameter is used
                             to enable streaming according to NPQ and by FEC (Forward Error
                             Correction) method if its value is set to "fec".
Request                      None.
Response                     None.

Remarks
The <ID> in the request URL is the value of (channel No. × 100 + stream type value), e.g., if the
channel No. is 1, and the stream type value is 1, the ID equals to 101.
• For channel No., if the device contains analog and digital channels, the analog channel No. starts
  from 1, and the digital channel No. starts from the next No. of the end analog channel. For
  example, if the device contains 16 analog channels and 16 digital channels, the analog channel
  No. is between 1 and 16, while the digital channel No. is between 17 and 32.
• For stream type, only two values are available, that is, 1 (main stream) and 2 (sub-stream).

15.9.17 rtsp://<host>[:port]/ISAPI/Streaming/tracks/<ID>?starttime=&endtime=
Operations about playback of a specific channel.

Request URL Definition
Table 15-350 DESCRIBE rtsp://<host>[:port]/ISAPI/Streaming/tracks/<ID>?starttime=&endtime=
Method                       DESCRIBE
Description                  Request for getting basic parameters for playback.
Query                        starttime: start time of the target stream, whose format is based on
                             the ISO 8601 standard.
                             (Optional) endtime: end time of the target stream, whose format is
                             based on the ISO 8601 standard. If this field is empty, the stream will

                           be continuously obtained until the session is terminated or paused
                           manually.
Request                    None.
Response                   None.
 Table 15-351 SETUP rtsp://<host>[:port]/ISAPI/Streaming/tracks/<ID>?starttime=&endtime=
Method                     SETUP
Description                Request for getting session information for playback.
Query                      starttime: start time of the target stream, whose format is based on
                           the ISO 8601 standard.
                           (Optional) endtime: end time of the target stream, whose format is
                           based on the ISO 8601 standard. If this field is empty, the stream will
                           be continuously obtained until the session is terminated or paused
                           manually.
Request                    None.
Response                   None.
  Table 15-352 PLAY rtsp://<host>[:port]/ISAPI/Streaming/tracks/<ID>?starttime=&endtime=
Method                     PLAY
Description                Start playback.
Query                      starttime: start time of the target stream, whose format is based on
                           the ISO 8601 standard.
                           (Optional) endtime: end time of the target stream, whose format is
                           based on the ISO 8601 standard. If this field is empty, the stream will
                           be continuously obtained until the session is terminated or paused
                           manually.
Request                    None.
Response                   None.
           Table 15-353 TEARDOW rtsp://<host>[:port]/ISAPI/Streaming/tracks/<ID>?
                                   starttime=&endtime=
Method                     TEARDOW
Description                Stop playback.
Query                      starttime: start time of the target stream, whose format is based on
                           the ISO 8601 standard.
                           (Optional) endtime: end time of the target stream, whose format is
                           based on the ISO 8601 standard. If this field is empty, the stream will

                              be continuously obtained until the session is terminated or paused
                              manually.
Request                       None.
Response                      None.

Remarks
The <ID> in the URL is defined as (channel No.)*100+(stream type value).
channel No.
   For analog channel, the No. starts from 1, and for digital channel, the No. starts from the last
   analog channel No.
   E.g., if the device has 16 analog channels and 16 digital channels, the analog channel No. is
   between 1 and 16, and the digital channel No. is between 17 and 32.
stream type value
   The stream type values contain 1, 2, and 3. 1-main stream, 2-sub-stream, 3-third stream.
E.g., if ID is 101, it indicates the main stream of channel No.1; if ID is 102, it indicates the sub-
stream of channel No. 2; if ID is 1601, it indicates the main stream of channel 16;...

15.10 /ISAPI/System

15.10.1 /ISAPI/System/accessDevice/associatedChannel?format=json
Get the linked channel informaiton of added IoT device.

Request URL Definition
          Table 15-354 GET /ISAPI/System/accessDevice/associatedChannel?format=json
Method                        GET
Description                   Get the linked channel informaiton of added IoT device.
Query                         format: determine the format of request or response message.
Request                       JSON_IOT_ChannelInfoList
Response                      JSON_AssociatedChannelList

15.10.2 /ISAPI/System/AcsUpdate/capabilities
Get the capability of upgrading device (slave access control device, peripheral module, etc.).

Request URL Definition
                     Table 15-355 GET /ISAPI/System/AcsUpdate/capabilities
Method                       GET
Description                  Get the capability of upgrading device (slave access control device,
                             peripheral module, etc.).
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_AcsUpdate
                             Failed: XML_ResponseStatus

15.10.3 /ISAPI/System/activate
Device activation.

Request URL Definition
                             Table 15-356 PUT /ISAPI/System/activate
Method                       PUT
Description                  Send activation password to activate the device.
Query                        None.
Request                      XML_ActivateInfo
Response                     XML_ResponseStatus

15.10.4 /ISAPI/System/algorithmsVersion
Get the version information of algorithm library.

Request URL Definition
                       Table 15-357 GET /ISAPI/System/algorithmsVersion
Method                       GET
Description                  Get the version information of algorithm library.
Query                        None.
Request                      None.
Response                     XML_AlgorithmsVersion

15.10.5 /ISAPI/System/Audio/AudioIn/channels/<ID>
Get or set audio input parameters of a specific channel.

Request URL Definition
                 Table 15-358 GET /ISAPI/System/Audio/AudioIn/channels/<ID>
Method                        GET
Description                   Get audio input parameters of a specific channel.
Query                         None.
Request                       None.
Response                      Succeeded: XML_AudioIn
                              Failed: XML_ResponseStatus
                 Table 15-359 PUT /ISAPI/System/Audio/AudioIn/channels/<ID>
Method                        PUT
Description                   Set audio input parameters of a specific channel.
Query                         None.
Request                       XML_AudioIn
Response                      XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.10.6 /ISAPI/System/Audio/AudioIn/channels/<ID>/capabilities
Get the audio input capability of a specific channel.

Request URL Definition
           Table 15-360 GET /ISAPI/System/Audio/AudioIn/channels/<ID>/capabilities
Method                        GET
Description                   Get the audio input capability of a specific channel.
Query                         None.
Request                       None.
Response                      Succeeded: XML_AudioInCap

                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.10.7 /ISAPI/System/Audio/AudioOut/channels/<ID>
Get or set audio output parameters of a specific channel.

Request URL Definition
                Table 15-361 GET /ISAPI/System/Audio/AudioOut/channels/<ID>
Method                       GET
Description                  Get audio output parameters of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_AudioOut
                             Failed: XML_ResponseStatus
                Table 15-362 PUT /ISAPI/System/Audio/AudioOut/channels/<ID>
Method                       PUT
Description                  Set audio output parameters of a specific channel.
Query                        None.
Request                      XML_AudioOut
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.10.8 /ISAPI/System/Audio/AudioOut/channels/<ID>/capabilities
Get the audio output capability of a specific channel.

Request URL Definition
          Table 15-363 GET /ISAPI/System/Audio/AudioOut/channels/<ID>/capabilities
Method                       GET
Description                  Get the audio output capability of a specific channel.

Query                          None.
Request                        None.
Response                       Succeeded: XML_AudioOutCap
                               Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.10.9 /ISAPI/System/Audio/capabilities
Get the audio capability.

Request URL Definition
                        Table 15-364 GET /ISAPI/System/Audio/capabilities
Method                         GET
Description                    Get the audio capability.
Query                          None.
Request                        None.
Response                       Succeeded: XML_AudioCap
                               Failed: XML_ResponseStatus

15.10.10 /ISAPI/System/Audio/channels
Get the configuration of all audio channels of the device.

Request URL Definition
                            Table 15-365 GET /ISAPI/System/Audio/channels
Method                         GET
Description                    Get the configuration of all audio channels of the device.
Query                          None.
Request                        None.
Response                       Succeeded: XML_AudioChannelList
                               Failed: XML_ResponseStatus

15.10.11 /ISAPI/System/Audio/channels/<ID>
Get the configuration of a specific audio channel of the device.

Request URL Definition
                      Table 15-366 GET /ISAPI/System/Audio/channels/<ID>
Method                       GET
Description                  Get the configuration of a specific audio channel of the device.
Query                        None.
Request                      None.
Response                     Succeeded: XML_AudioChannel
                             Failed: XML_ResponseStatus

15.10.12 /ISAPI/System/Audio/channels/<ID>/dynamicCap
Get dynamic audio capability by channel.

Request URL Definition
               Table 15-367 GET /ISAPI/System/Audio/channels/<ID>/dynamicCap
Method                       GET
Description                  Get dynamic audio capability by channel.
Query                        None.
Request                      XML_AudioDscriptor
Response                     Succeeded: XML_DynamicCap
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the audio input channel ID.

15.10.13 /ISAPI/System/autoMaintenance/capabilities?format=json
Get the capability of automatic maintenance configuration.

Request URL Definition
           Table 15-368 GET /ISAPI/System/autoMaintenance/capabilities?format=json
Method                       GET
Description                  Get the capability of automatic maintenance configuration.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_AutoMaintenanceCap

15.10.14 /ISAPI/System/autoMaintenance?format=json
Get automatic maintenance configuration parameters.

Request URL Definition
                Table 15-369 GET /ISAPI/System/autoMaintenance?format=json
Method                       GET
Description                  Get automatic maintenance configuration parameters.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_AutoMaintenance
                Table 15-370 PUT /ISAPI/System/autoMaintenance?format=json
Method                       PUT
Description                  Set automatic maintenance parameters.
Query                        format: determine the format of request or response message.
Request                      JSON_AutoMaintenance
Response                     JSON_ResponseStatus

15.10.15 /ISAPI/System/Bluetooth/capabilities
Get the bluetooth configuration capability.

Request URL Definition
                     Table 15-371 GET /ISAPI/System/Bluetooth/capabilities
Method                       GET
Description                  Get the bluetooth configuration capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_BluetoothCap
                             Failed: XML_ResponseStatus

15.10.16 /ISAPI/System/Bluetooth/ibeaconParam
Operations about the ibeacon bluetooth configuration.

Request URL Definition
                   Table 15-372 GET /ISAPI/System/Bluetooth/ibeaconParam
Method                       GET
Description                  Get the ibeacon bluetooth parameters.
Query                        None.
Request                      None.
Response                     Succeeded: XML_IbeaconParam
                             Failed: XML_ResponseStatus
                   Table 15-373 PUT /ISAPI/System/Bluetooth/ibeaconParam
Method                       PUT
Description                  Set the ibeacon bluetooth parameters.
Query                        None.
Request                      XML_IbeaconParam
Response                     XML_ResponseStatus

15.10.17 /ISAPI/System/Bluetooth/ibeaconParam/capabilities
Get the ibeacon bluetooth configuration capability.

Request URL Definition
              Table 15-374 GET /ISAPI/System/Bluetooth/ibeaconParam/capabilities
Method                       GET
Description                  Get the ibeacon bluetooth configuration capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_IbeaconParam
                             Failed: XML_ResponseStatus

15.10.18 /ISAPI/System/capabilities
Get device capability.

Request URL Definition
                           Table 15-375 GET /ISAPI/System/capabilities
Method                       GET
Description                  Get device capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_DeviceCap
                             Failed: XML_ResponseStatus

15.10.19 /ISAPI/System/configurationData?secretkey=
Import or export configuration files securely.

Request URL Definition
                  Table 15-376 GET /ISAPI/System/configurationData?secretkey=
Method                       GET
Description                  Export the configuration files securely.
Query                        security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message

                              are encrypted in AES128 CBC mode; when security is 2, it indicates
                              that the nodes of sensitive information in the message are encrypted
                              in AES256 CBC mode.
                              iv: the initialization vector, and it is required when security is 1 or 2.
                              secretkey: the verification key, it is provided by the upper-layer and
                              should be encrypted for exporting.
Request                       None.
Response                      Opaque data (binary data).
              Table 15-377 PUT or POST /ISAPI/System/configurationData?secretkey=
Method                        PUT, POST
Description                   Import the configuration files securely.
Query                         security: the version No. of encryption scheme. When security does
                              not exist, it indicates that the data is not encrypted; when security is
                              1, it indicates that the nodes of sensitive information in the message
                              are encrypted in AES128 CBC mode; when security is 2, it indicates
                              that the nodes of sensitive information in the message are encrypted
                              in AES256 CBC mode.
                              iv: the initialization vector, and it is required when security is 1 or 2.
                              secretkey: the verification key, it is provided by the upper-layer and
                              should be encrypted for importing.
Request                       Opaque data (binary data for PUT method, data in form format for
                              POST method).
Response                      XML_ResponseStatus

Remarks
The device may reboot after importing the configuration file.

15.10.20 /ISAPI/System/configurationData?type=
Import or export device configuration files safely.

Request URL Definition
                    Table 15-378 GET /ISAPI/System/configurationData?type=
Method                        GET
Description                   Export device configuration files safely.

Query                     security: the version No. of encryption scheme. When security does
                          not exist, it indicates that the data is not encrypted; when security is
                          1, it indicates that the nodes of sensitive information in the message
                          are encrypted in AES128 CBC mode; when security is 2, it indicates
                          that the nodes of sensitive information in the message are encrypted
                          in AES256 CBC mode.
                          iv: the initialization vector, and it is required when security is 1 or 2.
                          secretkey: the verification key, which is provided by the upper-layer
                          and should be encrypted for importing.
                          type: the type of configuration parameters to be exported or
                          imported, which contains "OSD", "MODE", "IMAGE" and "IOOUT"
                          types. For "OSD" type, the OSD (On Screen Display) parameters will
                          be imported or exported; for "MODE" type, the application mode
                          parameters will be imported or exported; for "IMAGE" type, the
                          image parameters will be imported or exported; for "IOOUT" type,
                          the IO output parameters will be imported or exported. Multiple
                          types can be selected and they should be separated by commas,
                          e.g., /​ISAPI/​System/​configurationData?
                          type=OSD,MODE,IMAGE,IOOUT. If no type is selected, it is
                          recommended to return failure response message or set type to
                          NULL.
Request                   None.
Response                  Succeeded: Opaque data.
                          Failed: XML_ResponseStatus
              Table 15-379 PUT or POST /ISAPI/System/configurationData?type=
Method                    PUT, POST
Description               Import device configuration files safely.
Query                     security: the version No. of encryption scheme. When security does
                          not exist, it indicates that the data is not encrypted; when security is
                          1, it indicates that the nodes of sensitive information in the message
                          are encrypted in AES128 CBC mode; when security is 2, it indicates
                          that the nodes of sensitive information in the message are encrypted
                          in AES256 CBC mode.
                          iv: the initialization vector, and it is required when security is 1 or 2.
                          secretkey: the verification key, which is provided by the upper-layer
                          and should be encrypted for importing.
                          type: the type of configuration parameters to be exported or
                          imported, which contains "OSD", "MODE", "IMAGE" and "IOOUT"

                            types. For "OSD" type, the OSD (On Screen Display) parameters will
                            be imported or exported; for "MODE" type, the application mode
                            parameters will be imported or exported; for "IMAGE" type, the
                            image parameters will be imported or exported; for "IOOUT" type,
                            the IO output parameters will be imported or exported. Multiple
                            types can be selected and they should be separated by commas,
                            e.g., /​ISAPI/​System/​configurationData?
                            type=OSD,MODE,IMAGE,IOOUT. If no type is selected, it is
                            recommended to return failure response message or set type to
                            NULL.
Request                     Opaque data.
Response                    XML_ResponseStatus

Remarks
• This URL will import or export all configuration parameters by default.
• The device needs to reboot for the imported parameters to take effect.

15.10.21 /ISAPI/System/deviceInfo
Operations about the device information.

Request URL Definition
                           Table 15-380 GET /ISAPI/System/deviceInfo
Method                      GET
Description                 Get the device information.
Query                       None
Request                     None.
Response                    Succeeded: XML_DeviceInfo
                            Failed: XML_ResponseStatus
                           Table 15-381 PUT /ISAPI/System/deviceInfo
Method                      PUT
Description                 Set the device information.
Query                       None
Request                     XML_DeviceInfo
Response                    XML_ResponseStatus

15.10.22 /ISAPI/System/deviceInfo/capabilities
Get the device information configuration capability.

Request URL Definition
                     Table 15-382 GET /ISAPI/System/deviceInfo/capabilities
Method                       GET
Description                  Get the device information configuration capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_DeviceInfo
                             Failed: XML_ResponseStatus

15.10.23 /ISAPI/System/diagnosedData
Get device diagnosis information.

Request URL Definition
                         Table 15-383 GET /ISAPI/System/diagnosedData
Method                       GET
Description                  Get device diagnosis information.
Query                        None.
Request                      None.
Response                     Non-transparent data

Remarks
Before getting the device diagnosis information, you should get the information export status via
URL GET /ISAPI/System/diagnosedData/exportStatus , only when the node <status> in
XML_ExportStatus is "unexport", you can call this URL to get the device diagnosis information.

15.10.24 /ISAPI/System/diagnosedData/exportStatus
Get the export status of device diagnosis information.

Request URL Definition
                  Table 15-384 GET /ISAPI/System/diagnosedData/exportStatus
Method                       GET
Description                  Get the export status of device diagnosis information.
Query                        None.
Request                      None.
Response                     XML_ExportStatus

15.10.25 /ISAPI/System/diagnosis/capabilities?format=json
Get the device diagnosis capability.

Request URL Definition
               Table 15-385 GET /ISAPI/System/diagnosis/capabilities?format=json
Method                       GET
Description                  Get the device diagnosis capability.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_DiagnosisCondCap
                             Failed: JSON_ResponseStatus

15.10.26 /ISAPI/System/diagnosis?format=json
Diagnose the device.

Request URL Definition
                    Table 15-386 POST /ISAPI/System/diagnosis?format=json
Method                       POST
Description                  Diagnose the device.
Query                        format: determine the format of request or response message.
Request                      JSON_DiagnosisCond
Response                     JSON_DiagnosisResult

15.10.27 /ISAPI/System/doubleLensParking/capabilities
Get the capability of dual-lens parking space camera.

Request URL Definition
                 Table 15-387 GET /ISAPI/System/doubleLensParking/capabilities
Method                       GET
Description                  Get the capability of dual-lens parking space camera.
Query                        None.
Request                      None.
Response                     Succeeded: XML_DoubleLensParkingCap
                             Failed: XML_ResponseStatus

15.10.28 /ISAPI/System/dumpData
Get the dump file data of the device.

Request URL Definition
                            Table 15-388 GET /ISAPI/System/dumpData
Method                       GET
Description                  Get the dump file data of the device.
Query                        None.
Request                      None.
Response                     Opaque data.

Remarks
The dump file data of the device may be in binary format or other format.

15.10.29 /ISAPI/System/factoryReset?mode=
Restore the device to default settings.

Request URL Definition
                      Table 15-389 PUT /ISAPI/System/factoryReset?mode=
Method                        PUT
Description                   Restore the device to default settings.
Query                         mode: The recovery mode, which contains "full", "basic", and "part"
                              mode. The default mode is "full", and all the device parameters will
                              be restored to default settings;​ for "basic" mode, the device
                              parameters, except network and user parameters, will be restored to
                              default settings;​ for "part" mode, only a part of default settings will
                              be restored.
Request                       None.
Response                      XML_ResponseStatus

Remarks
• For access control devices, this URL is only supported by facial recognition terminal, and the
  "full" and "basic" recovery modes are not supported by passthrough method.
• For facial recognition terminal, if the recovery mode is set to "part", i.e., /ISAPI/System/
  factoryReset?mode=part, the settings of card, face, event, fingerprint, schedule template,
  network, user name, and password will be reserved without being restored.

15.10.30 /ISAPI/System/fileExport/capabilities?format=json
Get the capability of exporting files from the device.

Request URL Definition
               Table 15-390 GET /ISAPI/System/fileExport/capabilities?format=json
Method                        GET
Description                   Get the capability of exporting files from the device.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_FileExportCap
                              Failed: JSON_ResponseStatus

15.10.31 /ISAPI/System/fileExport?format=json
Export files from the device.

Request URL Definition
                    Table 15-391 POST /ISAPI/System/fileExport?format=json
Method                          POST
Description                     Export files from the device.
Query                           format: determine the format of request or response message.
Request                         JSON_FileExport
Response                        JSON_FileExportResult

15.10.32 /ISAPI/System/guardAgainstTheft
Get or set device anti-theft parameters.

Request URL Definition
                       Table 15-392 GET /ISAPI/System/guardAgainstTheft
Method                          GET
Description                     Get the device anti-​theft parameters.
Query                           None.
Request                         None.
Response                        Succeeded: XML_GuardAgainstTheft
                                Failed: XML_ResponseStatus
                       Table 15-393 PUT /ISAPI/System/guardAgainstTheft
Method                          PUT
Description                     Set the device anti-​theft parameters.
Query                           None.
Request                         XML_GuardAgainstTheft
Response                        XML_ResponseStatus

15.10.33 /ISAPI/System/guardAgainstTheft/capabilities
Get the device anti-theft configuration capability.

Request URL Definition
                 Table 15-394 GET /ISAPI/System/guardAgainstTheft/capabilities
Method                        GET
Description                   Get the device anti-​theft configuration capability.
Query                         None.
Request                       None.
Response                      Succeeded: XML_Cap_GuardAgainstTheft
                              Failed: XML_ResponseStatus

15.10.34 /ISAPI/System/guideConfig/<guideEvent>/capabilities?format=json
Get the capability of quick setup instruction for specified event.

Request URL Definition
      Table 15-395 GET /ISAPI/System/guideConfig/<guideEvent>/capabilities?format=json
Method                        GET
Description                   Get the capability of quick setup instruction for specified event.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_GuideConfigCap
                              Failed: JSON_ResponseStatus

Remarks
The <guideEvent> in the URL refers to the event, which supports quick setup, and now only
"linkageCapture" (capture by linkage) is supported, i.e., the URL is: /ISAPI/System/guideConfig/
linkageCapture/capabilities?format=json

15.10.35 /ISAPI/System/guideConfig/<guideEvent>?format=json
Get the parameters of quick setup instruction for specified event.

Request URL Definition
            Table 15-396 GET /ISAPI/System/guideConfig/<guideEvent>?format=json
Method                       GET
Description                  Get the parameters of quick setup instruction for specified event.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_GuideConfig
                             Failed: JSON_ResponseStatus

Remarks
The <guideEvent> in the URL refers to the event, which supports quick setup, and now only
"linkageCapture" (capture by linkage) is supported, i.e., the URL is: /ISAPI/System/guideConfig/
linkageCapture?format=json

15.10.36 /ISAPI/System/Hardware
Operations about the device hardware configuration.

Request URL Definition
                           Table 15-397 GET /ISAPI/System/Hardware
Method                       GET
Description                  Get the device hardware configuration parameters.
Query                        None.
Request                      None.
Response                     Succeeded: XML_HardwareService
                             Failed: XML_ResponseStatus
                           Table 15-398 PUT /ISAPI/System/Hardware
Method                       PUT
Description                  Set the device hardware parameters.
Query                        None.
Request                      XML_HardwareService
Response                     XML_ResponseStatus

15.10.37 /ISAPI/System/Hardware/defog
Operations about the defogging control configuration.

Request URL Definition
                         Table 15-399 GET /ISAPI/System/Hardware/defog
Method                        GET
Description                   Get the defogging control configuration parameters.
Query                         None.
Request                       None.
Response                      Succeeded: XML_Defog
                              Failed: XML_ResponseStatus
                         Table 15-400 PUT /ISAPI/System/Hardware/defog
Method                        PUT
Description                   Set the defogging control parameters.
Query                         None.
Request                       XML_Defog
Response                      XML_ResponseStatus

15.10.38 /ISAPI/System/installationAngleCalibration/channels/<ID>/capabilities?
format=json
Get the capability of installation angle calibration.

Request URL Definition
   Table 15-401 GET /ISAPI/System/installationAngleCalibration/channels/<ID>/capabilities?
                                        format=json
Method                        GET
Description                   Get the capability of installation angle calibration.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_Cap_CalibrationStatus
                              Failed: JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.10.39 /ISAPI/System/installationAngleCalibration/channels/<ID>?format=json
Get the installation angle calibration status or calibrate the installation angle.

Request URL Definition
   Table 15-402 GET /ISAPI/System/installationAngleCalibration/channels/<ID>?format=json
Method                        GET
Description                   Get the installation angle calibration status.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_CalibrationStatus
                              Failed: JSON_ResponseStatus
   Table 15-403 PUT /ISAPI/System/installationAngleCalibration/channels/<ID>?format=json
Method                        PUT
Description                   Calibrate the installation angle.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.10.40 /ISAPI/System/IO/capabilities
Get alarm input and output configuration capability.

Request URL Definition
                          Table 15-404 GET /ISAPI/System/IO/capabilities
Method                         GET
Description                    Get alarm input and output configuration capability.
Query                          None.

Request                       None.
Response                      XML_IOCap

15.10.41 /ISAPI/System/IO/inputs
Get the information of all alarm input ports.

Request URL Definition
                    Table 15-405 Get the information of all alarm input ports.
Method                       GET
Description                  Get the information of all alarm input ports.
Query                        None.
Request                      None.
Response                     XML_IOInputPortList

15.10.42 /ISAPI/System/IO/inputs/<ID>
Get or set an alarm input port.

Request URL Definition
                         Table 15-406 GET /ISAPI/System/IO/inputs/<ID>
Method                       GET
Description                  Get an alarm input's information.
Query                        None.
Request                      None.
Response                     XML_IOInputPort
                         Table 15-407 PUT /ISAPI/System/IO/inputs/<ID>
Method                       PUT
Description                  Set an alarm input's information.
Query                        None.
Request                      XML_IOInputPort
Response                     XML_ResponseStatus

15.10.43 /ISAPI/System/IO/inputs/<ID>/status
Get the status of a specific alarm input.

Request URL Definition
                      Table 15-408 GET /ISAPI/System/IO/inputs/<ID>/status
Method                        GET
Description                   Get the status of a specific alarm input.
Query                         None.
Request                       None.
Response                      Succeeded: XML_IOPortStatus
                              Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the alarm input ID.

15.10.44 /ISAPI/System/IO/inputs/capabilities
Get alarm input configuration capability.

Request URL Definition
                      Table 15-409 GET /ISAPI/System/IO/inputs/capabilities
Method                        GET
Description                   Get the alarm input configuration capability.
Query                         None.
Request                       None.
Response                      XML_Cap_IOInputPortList

15.10.45 /ISAPI/System/IO/outputs
Get the information of all I/O output ports.

Request URL Definition
                           Table 15-410 GET /ISAPI/System/IO/outputs
Method                       GET
Description                  Get the information of all I/O output ports.
Query                        None.
Request                      None.
Response                     XML_IOOutputPortList

15.10.46 /ISAPI/System/IO/outputs/capabilities
Get the I/O output capability.

Request URL Definition
                     Table 15-411 GET /ISAPI/System/IO/outputs/capabilities
Method                       GET
Description                  Get the I/O output capability.
Query                        None.
Request                      None.
Response                     XML_Cap_IOOutputPortList

15.10.47 /ISAPI/System/IO/outputs/<ID>
Get or set the information of specified I/O output port.
                        Table 15-412 GET /ISAPI/System/IO/outputs/<ID>
Method                       GET
Description                  Get the information of specified I/O output port.
Query                        None.
Request                      None.
Response                     XML_IOOutputPort

                        Table 15-413 PUT /ISAPI/System/IO/outputs/<ID>
Method                       PUT
Description                  Set the information of specified alarm output port.
Query                        XML_IOOutputPort
Request                      None.
Response                     XML_ResponseStatus

15.10.48 /ISAPI/System/IO/outputs/<ID>/status
Get status of a specific alarm output.

Request URL Definition
                     Table 15-414 GET /ISAPI/System/IO/outputs/<ID>/status
Method                       GET
Description                  Get status of a specific alarm output.
Query                        None.
Request                      None.
Response                     Succeeded: XML_IOPortStatus
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the alarm output ID.

15.10.49 /ISAPI/System/IO/outputs/<ID>/trigger
Manually trigger a specific alarm output.

Request URL Definition
                    Table 15-415 PUT /ISAPI/System/IO/outputs/<ID>/trigger
Method                       PUT
Description                  Manually trigger a specific alarm output.
Query                        none.
Request                      XML_IOPortData
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the alarm output ID.

15.10.50 /ISAPI/System/IO/status
Get alarm input and output status.

Request URL Definition
                            Table 15-416 GET /ISAPI/System/IO/status
Method                       GET
Description                  Get alarm input and output status.
Query                        None.
Request                      None.
Response                     Succeeded: XML_IOPortStatusList
                             Failed: XML_ResponseStatus

15.10.51 /ISAPI/System/IOT/channelConfig?format=json
Import or export the list of added IoT devices.

Request URL Definition
                Table 15-417 GET /ISAPI/System/IOT/channelConfig?format=json
Method                       GET
Description                  Export the list of added IoT devices.
Query                        format: determine the format of request or response message.
                             security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      None.
Response                     Succeeded: Opaque Data
                             Failed: JSON_ResponseStatus

                Table 15-418 PUT /ISAPI/System/IOT/channelConfig?format=json
Method                       PUT
Description                  Import the list of added IoT devices.
Query                        format: determine the format of request or response message.
                             security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      Opaque Data
Response                     JSON_ResponseStatus
                             JSON_IOT_ErrorList

Remarks
The Opaque Data should be encrypted.

15.10.52 /ISAPI/System/IOT/channels/<ID>/<EventType>/capabilities?format=json
Get the event configuration capability of IoT device.

Request URL Definition
   Table 15-419 GET /ISAPI/System/IOT/channels/<ID>/<EventType>/capabilities?format=json
Method                       GET
Description                  Get the event configuration capability of IoT device.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_XXCap
                             Failed: JSON_ResponseStatus

15.10.53 /ISAPI/System/IOT/channels/<ID>/<EventType>?format=json
Get or set the event/alarm parameters.

Request URL Definition
          Table 15-420 GET /ISAPI/System/IOT/channels/<ID>/<EventType>?format=json
Method                       GET
Description                  Get the event/alarm parameters.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_XX
                             Failed: JSON_ResponseStatus
          Table 15-421 PUT /ISAPI/System/IOT/channels/<ID>/<EventType>?format=json
Method                       PUT
Description                  Set the event/alarm parameters.
Query                        format: determine the format of request or response message.
Request                      JSON_XX
Response                     JSON_ResponseStatus

15.10.54 /ISAPI/System/IOT/channels/<ID>/alarmStatistics?format=json
Get the alarm statistics of added IoT device according to channel ID.

Request URL Definition
        Table 15-422 GET /ISAPI/System/IOT/channels/<ID>/alarmStatistics?format=json
Method                       GET
Description                  Get the alarm statistics of added IoT device according to channel ID.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_AlarmStatistics
                             Failed: JSON_ResponseStatus

15.10.55 /ISAPI/System/IOT/channels/<ID>/all?format=json
Delete all channels (video channel and IoT channel) of added IoT device

Request URL Definition
              Table 15-423 DELETE /ISAPI/System/IOT/channels/<ID>/all?format=json
Method                       DELETE
Description                  Delete all channels (video channel and IoT channel) of added IoT
                             device
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_ResponseStatus

15.10.56 /ISAPI/System/IOT/channels/<ID>/basicParam?format=json
Set the basic parameters of added IoT device according to channel ID.

Request URL Definition
          Table 15-424 PUT /ISAPI/System/IOT/channels/<ID>/basicParam?format=json
Method                       PUT
Description                  Set the basic parameters of added IoT device according to channel
                             ID.
Query                        format: determine the format of request or response message.
Request                      JSON_BasicParam
Response                     JSON_ResponseStatus

15.10.57 /ISAPI/System/IOT/channels/<ID>/OSD/capabilities?format=json
Get the OSD configuration capability of specified IoT device channel.

Request URL Definition
        Table 15-425 GET /ISAPI/System/IOT/channels/<ID>/OSD/capabilities?format=json
Method                       GET
Description                  Get the OSD configuration capability of specified IoT device channel.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_OSDCap

                             Failed: JSON_ResponseStatus

15.10.58 /ISAPI/System/IOT/channels/<ID>/OSD?format=json
Get or set the OSD parameters.

Request URL Definition
              Table 15-426 GET /ISAPI/System/IOT/channels/<ID>/OSD?format=json
Method                       GET
Description                  Get the OSD parameters.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_OSD
                             Failed: JSON_ResponseStatus
              Table 15-427 PUT /ISAPI/System/IOT/channels/<ID>/OSD?format=json
Method                       PUT
Description                  Set the OSD parameters.
Query                        format: determine the format of request or response message.
Request                      JSON_OSD
Response                     JSON_ResponseStatus

Remarks
The <ID> in the URL is defied as the channel ID.

15.10.59 /ISAPI/System/IOT/channels/<ID>/status?format=json
Get the status of specified channel of added IoT device.

Request URL Definition
              Table 15-428 GET /ISAPI/System/IOT/channels/<ID>/status?format=json
Method                       GET
Description                  Get the status of specified channel of added IoT device.
Query                        format: determine the format of request or response message.

                             security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      None.
Response                     JSON_IOTChannelStatus

Remarks
The <ID> in the URL is defined as channel ID.

15.10.60 /ISAPI/System/IOT/channels/<ID>?format=json
Operations about specified added IoT device.

Request URL Definition
                Table 15-429 GET /ISAPI/System/IOT/channels/<ID>?format=json
Method                       GET
Description                  Get the information of added IoT device according to channel ID.
Query                        format: determine the format of request or response message.
                             security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      None.
Response                     Succeeded: JSON_IOTChannel
                             Failed: JSON_ResponseStatus
                Table 15-430 PUT /ISAPI/System/IOT/channels/<ID>?format=json
Method                       PUT
Description                  Set the added IoT device according to channel ID.
Query                        format: determine the format of request or response message.

                             security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      JSON_IOTChannel
Response                     JSON_ResponseStatus
              Table 15-431 DELETE /ISAPI/System/IOT/channels/<ID>?format=json
Method                       DELETE
Description                  Delete the specified IoT device according to channel ID.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_ResponseStatus

Remarks
The <ID> in the URL is defined as channel ID.

15.10.61 /ISAPI/System/IOT/channels/status?format=json
Get the status of added IoT device.

Request URL Definition
               Table 15-432 GET /ISAPI/System/IOT/channels/status?format=json
Method                       GET
Description                  Get the status of added IoT device.
Query                        format: determine the format of request or response message.
                             security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.

Request                      None.
Response                     Succeeded: JSON_IOTChannelStatusList
                             Failed: JSON_ResponseStatus

15.10.62 /ISAPI/System/IOT/channels/status?format=json&deviceInductiveType=
Get the status of added IoT device according to inductive type.

Request URL Definition
   Table 15-433 GET /ISAPI/System/IOT/channels/status?format=json&deviceInductiveType=
Method                       GET
Description                  Get the status of added IoT device according to inductive type.
Query                        format: determine the format of request or response message.
                             security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
                             deviceInductiveType: device inductive type, its value can be
                             obtained by URL: GET /ISAPI/System/IOT/sourceSupport/
                             capabilities?format=json , now there are two available values:
                             "inductiveType1" and "inductiveType2"
Request                      None.
Response                     JSON_IOTChannelStatusList

15.10.63 /ISAPI/System/IOT/channels?format=json
Operations about IoT devices.

Request URL Definition
                   Table 15-434 GET /ISAPI/System/IOT/channels?format=json
Method                       GET
Description                  Get the information of added IoT devices.
Query                        format: determine the format of request or response message.

                            security: the version No. of encryption scheme. When security does
                            not exist, it indicates that the data is not encrypted; when security is
                            1, it indicates that the nodes of sensitive information in the message
                            are encrypted in AES128 CBC mode; when security is 2, it indicates
                            that the nodes of sensitive information in the message are encrypted
                            in AES256 CBC mode.
                            iv: the initialization vector, and it is required when security is 1 or 2.
Request                     None.
Response                    JSON_IOTChannelList
                  Table 15-435 POST /ISAPI/System/IOT/channels?format=json
Method                      POST
Description                 Add the IoT devices to NVR/DVR.
Query                       format: determine the format of request or response message.
                            security: the version No. of encryption scheme. When security does
                            not exist, it indicates that the data is not encrypted; when security is
                            1, it indicates that the nodes of sensitive information in the message
                            are encrypted in AES128 CBC mode; when security is 2, it indicates
                            that the nodes of sensitive information in the message are encrypted
                            in AES256 CBC mode.
                            iv: the initialization vector, and it is required when security is 1 or 2.
Request                     JSON_IOTChannel
Response                    Succeeded: JSON_IOT_ChannelInfo
                            Failed: JSON_ResponseStatus

15.10.64 /ISAPI/System/IOT/channels?format=json&deviceInductiveType=
Get the informaiton of added IoT devices according to device inductive type.

Request URL Definition
        Table 15-436 GET /ISAPI/System/IOT/channels?format=json&deviceInductiveType=
Method                      GET
Description                 Get the added IoT devices according to device inductive type.
Query                       format: determine the format of request or response message.
                            deviceInductiveType: device inductive type, its value can be
                            obtained by URL: GET /ISAPI/System/IOT/sourceSupport/

                            capabilities?format=json , now there are two available values:
                            "inductiveType1" and "inductiveType2"
                            security: the version No. of encryption scheme. When security does
                            not exist, it indicates that the data is not encrypted; when security is
                            1, it indicates that the nodes of sensitive information in the message
                            are encrypted in AES128 CBC mode; when security is 2, it indicates
                            that the nodes of sensitive information in the message are encrypted
                            in AES256 CBC mode.
                            iv: the initialization vector, and it is required when security is 1 or 2.
Request                     None.
Response                    JSON_IOTChannelList

15.10.65 /ISAPI/System/IOT/linkageChannels?format=json
Get the linked channel of searched event.

Request URL Definition
              Table 15-437 POST /ISAPI/System/IOT/linkageChannels?format=json
Method                      POST
Description                 Get the linked channel of searched event.
Query                       format: determine the format of request or response message.
Request                     JSON_LinkageChansCond
Response                    Succeeded: JSON_Result
                            Failed: JSON_ResponseStatus

15.10.66 /ISAPI/System/IOT/search?format=json
Get the IoT devices which can be added.

Request URL Definition
                    Table 15-438 GET /ISAPI/System/IOT/search?format=json
Method                      GET
Description                 Get the IoT devices which can be added.
Query                       format: determine the format of request or response message.

                            security: the version No. of encryption scheme. When security does
                            not exist, it indicates that the data is not encrypted; when security is
                            1, it indicates that the nodes of sensitive information in the message
                            are encrypted in AES128 CBC mode; when security is 2, it indicates
                            that the nodes of sensitive information in the message are encrypted
                            in AES256 CBC mode.
                            iv: the initialization vector, and it is required when security is 1 or 2.
Request                     None.
Response                    JSON_IOTSourceList

15.10.67 /ISAPI/System/IOT/sourceCapabilities?format=json
Get the number of IoT device channels.

Request URL Definition
              Table 15-439 GET /ISAPI/System/IOT/sourceCapabilities?format=json
Method                      GET
Description                 Get the number of IoT device channels.
Query                       format: determine the format of request or response message.
                            security: the version No. of encryption scheme. When security does
                            not exist, it indicates that the data is not encrypted; when security is
                            1, it indicates that the nodes of sensitive information in the message
                            are encrypted in AES128 CBC mode; when security is 2, it indicates
                            that the nodes of sensitive information in the message are encrypted
                            in AES256 CBC mode.
                            iv: the initialization vector, and it is required when security is 1 or 2.
Request                     JSON_IOTSourceDescription
Response                    JSON_SourceCapabilities

15.10.68 /ISAPI/System/IOT/sourceSupport/capabilities?format=json
Get supported protocol type of IoT devices.

Request URL Definition
          Table 15-440 GET /ISAPI/System/IOT/sourceSupport/capabilities?format=json
Method                        GET
Description                   Get supported protocol type of IoT devices.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      JSON_IOTSourceSupport

15.10.69 /ISAPI/System/logServer
Get or set log server parameters.

Request URL Definition
                            Table 15-441 GET /ISAPI/System/logServer
Method                        GET
Description                   Get log server parameters.
Query                         None.
Request                       None.
Response                      Succeeded: XML_LogServer
                              Failed: XML_ResponseStatus
                            Table 15-442 PUT /ISAPI/System/logServer
Method                        PUT
Description                   Set log server parameters.
Query                         None.
Request                       XML_LogServer
Response                      XML_ResponseStatus

15.10.70 /ISAPI/System/logServer/capabilities
Get log server configuration capability.

Request URL Definition
                      Table 15-443 GET /ISAPI/System/logServer/capabilities
Method                       GET
Description                  Get log server configuration capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_LogServerCap
                             Failed: XML_ResponseStatus

15.10.71 /ISAPI/System/logServer/test
Perform security log server test.

Request URL Definition
                         Table 15-444 POST /ISAPI/System/logServer/test
Method                       POST
Description                  Perform security log server test.
Query                        None.
Request                      XML_LogServerTestDescription
Response                     XML_ResponseStatus

15.10.72 /ISAPI/System/Network/adaption/capabilities?format=json
Get network self-adaptive configuration capability.

Request URL Definition
          Table 15-445 GET /ISAPI/System/Network/adaption/capabilities?format=json
Method                       GET
Description                  Get network self-​adaptive configuration capability.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_AdaptionCap

                            Failed: JSON_ResponseStatus

15.10.73 /ISAPI/System/Network/adaption?format=json&streamType=
Operations about network self-adaptive configuration.

Request URL Definition
        Table 15-446 GET /ISAPI/System/Network/adaption?format=json&streamType=
Method                      GET
Description                 Get network self-​adaptive parameters.
Query                       format: determine the format of request or response message.
                            streamType: stream types, integer, the following values are available:
                            0-main stream, 1-sub-stream, 2-third stream, 3-virtual stream, 4-
                            stream 5, 5-stream 6, 7-stream 7, 8-stream 8, …, and so on.
Request                     None.
Response                    Succeeded: JSON_Adaption
                            Failed: JSON_ResponseStatus
        Table 15-447 PUT /ISAPI/System/Network/adaption?format=json&streamType=
Method                      GET
Description                 Set network self-​adaptive parameters.
Query                       format: determine the format of request or response message.
                            streamType: stream types, integer, the following values are available:
                            0-main stream, 1-sub-stream, 2-third stream, 3-virtual stream, 4-
                            stream 5, 5-stream 6, 7-stream 7, 8-stream 8, …, and so on.
Request                     JSON_Adaption
Response                    XML_ResponseStatus

15.10.74 /ISAPI/System/Network/Bond
Get all network bonding configuration parameters.

Request URL Definition
                        Table 15-448 GET /ISAPI/System/Network/Bond
Method                        GET
Description                   Get all network bonding configuration parameters.
Query                         None.
Request                       None.
Response                      Succeeded: XML_BondList
                              Failed: XML_ResponseStatus

15.10.75 /ISAPI/System/Network/Bond/<ID>
Operations about the bonding configuration of a specific network interface.

Request URL Definition
                      Table 15-449 GET /ISAPI/System/Network/Bond/<ID>
Method                        GET
Description                   Get the bonding parameters of a specific network interface.
Query                         None.
Request                       None.
Response                      Succeeded: XML_Bond
                              Failed: XML_ResponseStatus
                      Table 15-450 PUT /ISAPI/System/Network/Bond/<ID>
Method                        PUT
Description                   Set the bonding parameters of a specific network interface.
Query                         None.
Request                       XML_Bond
Response                      XML_ResponseStatus

15.10.76 /ISAPI/System/Network/capabilities
Get the network capability.

Request URL Definition
                     Table 15-451 GET /ISAPI/System/Network/capabilities
Method                       GET
Description                  Get the network capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_NetworkCap
                             Failed: XML_ResponseStatus

15.10.77 /ISAPI/System/Network/channels/<ID>/buletooth/status
Operations about the bluetooth status configuration of a specific channel.

Request URL Definition
           Table 15-452 GET /ISAPI/System/Network/channels/<ID>/buletooth/status
Method                       GET
Description                  Get the bluetooth status parameters of a specific channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_BluetoothStatus
                             Failed: XML_ResponseStatus
           Table 15-453 PUT /ISAPI/System/Network/channels/<ID>/buletooth/status
Method                       PUT
Description                  Set the bluetooth status parameters of a specific channel.
Query                        None.
Request                      XML_BluetoothStatus
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.10.78 /ISAPI/System/Network/DDNS
Operations about all DDNS configuration parameters.

Request URL Definition
                       Table 15-454 GET /ISAPI/System/Network/DDNS
Method                     GET
Description                Get all DDNS configuration parameters.
Query                      None.
Request                    None.
Response                   Succeeded: XML_DDNSList
                           Failed: XML_ResponseStatus
                       Table 15-455 PUT /ISAPI/System/Network/DDNS
Method                     PUT
Description                Set all DDNS configuration parameters.
Query                      None.
Request                    XML_DDNSList
Response                   XML_ResponseStatus

15.10.79 /ISAPI/System/Network/DDNS/capabilities
Get DDNS (Dynamic Domain Name Server) configuration capability.

Request URL Definition
                 Table 15-456 GET /ISAPI/System/Network/DDNS/capabilities
Method                     GET
Description                Get DDNS (Dynamic Domain Name Server) configuration capability.
Query                      None.
Request                    None.
Response                   Succeeded: XML_DDNSList
                           Failed: XML_ResponseStatus

15.10.80 /ISAPI/System/Network/DDNS/<ID>
Operations about the configuration of a specific DDNS.

Request URL Definition
                      Table 15-457 GET /ISAPI/System/Network/DDNS/<ID>
Method                       GET
Description                  Get the configuration parameters of a specific DDNS.
Query                        None.
Request                      None.
Response                     Succeeded: XML_DDNS
                             Failed: XML_ResponseStatus
                      Table 15-458 PUT /ISAPI/System/Network/DDNS/<ID>
Method                       PUT
Description                  Set the parameters of a specific DDNS.
Query                        None.
Request                      XML_DDNS
Response                     XML_ResponseStatus

15.10.81 /ISAPI/System/Network/DDNS/<ID>/capabilities
Get the configuration capability of a specific DDNS.

Request URL Definition
               Table 15-459 GET /ISAPI/System/Network/DDNS/<ID>/capabilities
Method                       GET
Description                  Get the configuration capability of a specific DDNS.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_DDNS
                             Failed: XML_ResponseStatus

15.10.82 /ISAPI/System/Network/Ehome
Operations about the EHome server access configuration.

Request URL Definition
                       Table 15-460 GET /ISAPI/System/Network/Ehome
Method                      GET
Description                 Get the EHome server access parameters.
Query                       None.
Request                     None.
Response                    Succeeded: XML_Ehome
                            Failed: XML_ResponseStatus
                       Table 15-461 PUT /ISAPI/System/Network/Ehome
Method                      PUT
Description                 Set the EHome server access parameters.
Query                       None.
Request                     XML_Ehome
Response                    XML_ResponseStatus

15.10.83 /ISAPI/System/Network/Ehome/capabilities
Get the configuration capability of EHome server access.

Request URL Definition
                 Table 15-462 GET /ISAPI/System/Network/Ehome/capabilities
Method                      GET
Description                 Get the configuration capability of EHome server access.
Query                       None.
Request                     None.
Response                    Succeeded: XML_Cap_EHome
                            Failed: XML_ResponseStatus

15.10.84 /ISAPI/System/Network/Ehome?centerID=
Operations about the EHome server access configuration.

Request URL Definition
                 Table 15-463 GET /ISAPI/System/Network/Ehome?centerID=
Method                      GET
Description                 Get the EHome server access parameters.
Query                       centerID: EHome center ID, and if there is only one center, centerID
                            is 1.
Request                     None.
Response                    Succeeded: XML_Ehome
                            Failed: XML_ResponseStatus
                 Table 15-464 PUT /ISAPI/System/Network/Ehome?centerID=
Method                      PUT
Description                 Set the EHome server access parameters.
Query                       centerID: EHome center ID, and if there is only one center, centerID
                            is 1.
Request                     XML_Ehome
Response                    XML_ResponseStatus

15.10.85 /ISAPI/System/Network/EZVIZ
Operations about Hik-Connect access configurations.

Request URL Definition
                        Table 15-465 GET /ISAPI/System/Network/EZVIZ
Method                      GET
Description                 Get Hik-Connect parameters.
Query                       security: the version No. of encryption scheme. When security does
                            not exist, it indicates that the data is not encrypted; when security is
                            1, it indicates that the nodes of sensitive information in the message
                            are encrypted in AES128 CBC mode; when security is 2, it indicates

                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      None.
Response                     XML_EZVIZ

PUT /ISAPI/System/Network/EZVIZ

Method                       PUT
Description                  Set Hik-Connect parameters.
Query                        security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      XML_EZVIZ
Response                     XML_ResponseStatus

15.10.86 /ISAPI/System/Network/EZVIZ/secretKey?format=json
Edit the verification code for Hik-Connect.

Request URL Definition
              Table 15-466 PUT /ISAPI/System/Network/EZVIZ/secretKey?format=json
Method                       PUT
Description                  Edit the verification code for Hik-Connect.
Query                        security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
                             format: determine the format of request or response message.

Request                      JSON_EZVIZSecretKey
Response                     JSON_ResponseStatus

15.10.87 /ISAPI/System/Network/ftp
Operations about all FTP configurations.

Request URL Definition
                          Table 15-467 GET /ISAPI/System/Network/ftp
Method                       GET
Description                  Get all FTP parameters.
Query                        None.
Request                      None.
Response                     Succeeded: XML_FTPNotificationList
                             Failed: XML_ResponseStatus
                          Table 15-468 PUT /ISAPI/System/Network/ftp
Method                       PUT
Description                  Set all FTP parameters.
Query                        None.
Request                      XML_FTPNotificationList
Response                     XML_ResponseStatus

15.10.88 /ISAPI/System/Network/ftp/<ID>
Operations about the configuration of a specific FTP.

Request URL Definition
                       Table 15-469 GET /ISAPI/System/Network/ftp/<ID>
Method                       GET
Description                  Get the parameters of a specific FTP.
Query                        None.
Request                      None.
Response                     Succeeded: XML_FTPNotification

                               Failed: XML_ResponseStatus
                          Table 15-470 PUT /ISAPI/System/Network/ftp/<ID>
Method                         PUT
Description                    Set the parameters of a specific FTP.
Query                          None.
Request                        XML_FTPNotification
Response                       XML_ResponseStatus

15.10.89 /ISAPI/System/Network/ftp/capabilities
Get the FTP capability.

Request URL Definition
                     Table 15-471 GET /ISAPI/System/Network/ftp/capabilities
Method                         GET
Description                    Get the FTP capability.
Query                          None.
Request                        None.
Response                       Succeeded: XML_Cap_FTPNotificationList
                               Failed: XML_ResponseStatus

15.10.90 /ISAPI/System/Network/ftp/test
Perform test to check if the FTP server is available.

Request URL Definition
                          Table 15-472 POST /ISAPI/System/Network/ftp/test
Method                         POST
Description                    Perform test to check if the FTP server is available.
Query                          None.
Request                        XML_FTPTestDescription
Response                       Succeeded: XML_FTPTestResult
                               Failed: XML_ResponseStatus

15.10.91 /ISAPI/System/Network/interfaces
Get the information of multiple network interfaces.

Request URL Definition
                         Table 15-473 GET /ISAPI/System/Network/interfaces
Method                          GET
Description                     Get the information of multiple network interfaces.
Query                           None.
Request                         None.
Response                        Succeeded: XML_NetworkInterfaceList
                                Failed: XML_ResponseStatus

Example
Sample Code of Getting Information of Multiple Network Interfaces
GET /ISAPI/System/Network/interfaces HTTP/1.1
…
HTTP/1.1 200 OK
Content-Type: application/xml; charset="UTF-8"
Content-Length: xxx

<?xml version="1.0" encoding="UTF-8"?>
<NetworkInterfaceList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <NetworkInterface>
  <id>1</id>
  <IPAddress>
   <ipVersion>v4</ipVersion>
   <addressingType>static</addressingType>
   <ipAddress>172.6.64.7</ipAddress>
   <subnetMask>255.255.255.0</subnetMask>
   <DefaultGateway>
    <ipAddress>172.6.64.1</ipAddress>
   </DefaultGateway>
   <PrimaryDNS>
    <ipAddress>192.0.0.200</ipAddress>
   </PrimaryDNS>
  </IPAddress>
  <Discovery>
   <UPnP>
    <enabled>true</enabled>
   </UPnP>
   <Zeroconf>
    <enabled>true</enabled>
   </Zeroconf>
  </Discovery>

  <Link>
   <MACAddress> 00:40:48:4C:7F:F2</MACAddress>
   <autoNegotiation>true</autoNegotiation>
   <speed>1000<speed>
   <duplex>full</duplex>
   <MTU>1500</MTU>
  </Link>
 </NetworkInterface>
</NetworkInterfaceList>

15.10.92 /ISAPI/System/Network/interfaces/<ID>
Operations about the configuration of a specific network interface.

Request URL Definitions
                    Table 15-474 GET /ISAPI/System/Network/interfaces/<ID>
Method                        GET
Description                   Get the information of a specific network interface.
Query                         None.
Request                       None.
Response                      Succeeded: XML_NetworkInterface
                              Failed: XML_ResponseStatus

PUT /ISAPI/System/Network/interfaces/<ID>

Method                        PUT
Description                   Set a specific network interface.
Query                         None.
Request                       XML_NetworkInterface
Response                      XML_ResponseStatus

15.10.93 /ISAPI/System/Network/interfaces/<ID>/capabilities
Get the capability of a specific network interface.

Request URL Definition
              Table 15-475 GET /ISAPI/System/Network/interfaces/<ID>/capabilities
Method                       GET
Description                  Get the capability of a specific network interface.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_NetworkInterface
                             Failed: XML_ResponseStatus

15.10.94 /ISAPI/System/Network/interfaces/<ID>/discovery
Operations about the network discovery configuration.

Request URL Definition
              Table 15-476 GET /ISAPI/System/Network/interfaces/<ID>/discovery
Method                       GET
Description                  Get the network discovery configuration parameters.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Discovery
                             Failed: XML_ResponseStatus
              Table 15-477 PUT /ISAPI/System/Network/interfaces/<ID>/discovery
Method                       PUT
Description                  Set the network discovery configuration parameters.
Query                        None.
Request                      XML_Discovery
Response                     XML_ResponseStatus

15.10.95 /ISAPI/System/Network/interfaces/<ID>/discovery/capabilities
Get the configuration capability of network discovery.

Request URL Definition
        Table 15-478 GET /ISAPI/System/Network/interfaces/<ID>/discovery/capabilities
Method                       GET
Description                  Get the configuration capability of network discovery.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_Discovery
                             Failed: XML_ResponseStatus

15.10.96 /ISAPI/System/Network/interfaces/<ID>/dynamicHostName?
format=json
Get or set dynamic domain name.

Request URL Definition
  Table 15-479 GET /ISAPI/System/Network/interfaces/<ID>/dynamicHostName?format=json
Method                       GET
Description                  Get dynamic domain name.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_DynamicHostName
                             Failed: JSON_ResponseStatus
  Table 15-480 PUT /ISAPI/System/Network/interfaces/<ID>/dynamicHostName?format=json
Method                       PUT
Description                  Set dynamic domain name.
Query                        format: determine the format of request or response message.
Request                      JSON_DynamicHostName
Response                     JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the network interface ID.

15.10.97 /ISAPI/System/Network/interfaces/<ID>/dynamicHostName/
capabilities?format=json
Get configuration capability of dynamic domain name.

Request URL Definition
  Table 15-481 GET /ISAPI/System/Network/interfaces/<ID>/dynamicHostName/capabilities?
                                      format=json
Method                       GET
Description                  Get configuration capability of dynamic domain name.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_DynamicHostNameCap
                             Failed: JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the network interface ID.

15.10.98 /ISAPI/System/Network/interfaces/<ID>/ieee802.1x
Operations about configuration of IEEE 802.1x protocol access.

Request URL Definition
              Table 15-482 GET /ISAPI/System/Network/interfaces/<ID>/ieee802.1x
Method                       GET
Description                  Get parameters of IEEE 802.1x protocol access.
Query                        None.
Request                      None.
Response                     Succeeded: XML_IEEE802_1x
                             Failed: XML_ResponseStatus
              Table 15-483 PUT /ISAPI/System/Network/interfaces/<ID>/ieee802.1x
Method                       PUT
Description                  Set parameters of IEEE 802.1x protocol access.
Query                        None.

Request                      XML_IEEE802_1x
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the network interface ID.

15.10.99 /ISAPI/System/Network/interfaces/<ID>/ieee802.1x/capabilities
Get configuration capability of IEEE802.1x protocol access.

Request URL Definition
        Table 15-484 GET /ISAPI/System/Network/interfaces/<ID>/ieee802.1x/capabilities
Method                       GET
Description                  Get configuration capability of IEEE802.1x protocol access.
Query                        None.
Request                      None.
Response                     XML_Cap_IEEE802_1x

15.10.100 /ISAPI/System/Network/interfaces/<ID>/ipAddress
Operations about IP address configuration of a specific network interface.

Request URL Definition
              Table 15-485 GET /ISAPI/System/Network/interfaces/<ID>/ipAddress
Method                       GET
Description                  Get the IP address of a specific network interface.
Query                        None.
Request                      None.
Response                     Succeeded: XML_IPAddress
                             Failed: XML_ResponseStatus
              Table 15-486 PUT /ISAPI/System/Network/interfaces/<ID>/ipAddress
Method                       PUT
Description                  Set IP address of a specific network interface.
Query                        None.

Request                          XML_IPAddress
Response                         XML_ResponseStatus

Example
Sample Code of Setting IP Address of A Specific Network Interface
PUT /ISAPI/System/Network/interfaces/1/ipAddress HTTP/1.1
…
Content-Type: application/xml; charset="UTF-8"
Content-Length: xxx

<?xml version="1.0" encoding="UTF-8"?>
<IPAddress version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ipVersion>v4</ipVersion>
 <addressingType>static</addressingType>
 <ipAddress>172.6.64.16</ipAddress>
 <subnetMask>255.255.255.0</subnetMask>
 <DefaultGateway>
  <ipAddress>172.6.64.1</ipAddress>
 </DefaultGateway>
 <PrimaryDNS>
  <ipAddress>192.0.0.200</ipAddress>
 </PrimaryDNS>
</IPAddress>

HTTP/1.1 200 OK
…
Content-Type: application/xml; charset="UTF-8"
Content-Length:xxx

<?xml version="1.0" encoding="UTF-8"?>
<ResponseStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <requestURL>/Network/interfaces/1/ipAddress</requestURL>
 <statusCode>1</statusCode>
 <statusString>OK</statusString>
</ResponseStatus>

15.10.101 /ISAPI/System/Network/interfaces/<ID>/ipAddress/capabilities
Get the IP address configuration capability of a specific network interface.

Request URL Definition
         Table 15-487 GET /ISAPI/System/Network/interfaces/<ID>/ipAddress/capabilities
Method                           GET
Description                      Get the IP address configuration capability of a specific network
                                 interface.

Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_IpAddress
                             Failed: XML_ResponseStatus

15.10.102 /ISAPI/System/Network/interfaces/<ID>/link
Operations about the connection configuration of a specific network interface.

Request URL Definition
                 Table 15-488 GET /ISAPI/System/Network/interfaces/<ID>/link
Method                       GET
Description                  Get the connection parameters of a specific network interface.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Link
                             Failed: XML_ResponseStatus
                 Table 15-489 PUT /ISAPI/System/Network/interfaces/<ID>/link
Method                       PUT
Description                  Set the connection parameters of a specific network interface.
Query                        None.
Request                      XML_Link
Response                     XML_ResponseStatus

15.10.103 /ISAPI/System/Network/interfaces/<ID>/link/capabilities
Get the connection configuration capability of a specific network interface.

Request URL Definition
           Table 15-490 GET /ISAPI/System/Network/interfaces/<ID>/link/capabilities
Method                       GET
Description                  Get the connection configuration capability of a specific network
                             interface.

Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_Link
                             Failed: XML_ResponseStatus

15.10.104 /ISAPI/System/Network/interfaces/<ID>/NetworkMode
Operations about the working mode configuration of the network connection.

Request URL Definition
           Table 15-491 GET /ISAPI/System/Network/interfaces/<ID>/NetworkMode
Method                       GET
Description                  Get the working mode parameters of the network connection.
Query                        None.
Request                      None.
Response                     Succeeded: XML_NetWorkMode
                             Failed: XML_ResponseStatus
           Table 15-492 PUT /ISAPI/System/Network/interfaces/<ID>/NetworkMode
Method                       PUT
Description                  Set the working mode parameters of the network connection.
Query                        None.
Request                      XML_NetWorkMode
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the network interface ID.

15.10.105 /ISAPI/System/Network/interfaces/<ID>/wireless
Operations about Wi-Fi configuration of a specific network interface.

Request URL Definition
               Table 15-493 GET /ISAPI/System/Network/interfaces/<ID>/wireless
Method                       GET
Description                  Get the Wi-Fi parameters of a specific network interface.
Query                        security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      None.
Response                     Succeeded: XML_Wireless
                             Failed: XML_ResponseStatus
               Table 15-494 PUT /ISAPI/System/Network/interfaces/<ID>/wireless
Method                       PUT
Description                  Set Wi-Fi parameters of a specific network interface.
Query                        security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      XML_Wireless
Response                     XML_ResponseStatus

15.10.106 /ISAPI/System/Network/interfaces/<ID>/wireless/accessDeviceList/
<ID>
Get the information of a specific device connected to the hotspot.

Request URL Definition
   Table 15-495 GET /ISAPI/System/Network/interfaces/<ID>/wireless/accessDeviceList/<ID>
Method                       GET
Description                  Get the information of a specific device connected to the hotspot.
Query                        None.
Request                      None.
Response                     Succeeded: XML_accessDevice
                             Failed: XML_ResponseStatus

Remarks
The first <ID> in the URL refers to the network interface ID, and the second <ID> refers to the
device ID.

15.10.107 /ISAPI/System/Network/interfaces/<ID>/wireless/accessDeviceList/
capabilities
Get the capability set of the device connected to the hotspot.

Request URL Definition
     Table 15-496 GET /ISAPI/System/Network/interfaces/<ID>/wireless/accessDeviceList/
                                       capabilities
Method                       GET
Description                  Get the capability set of the device connected to the hotspot.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_accessDeviceList
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the URL refers to the network interface ID.

15.10.108 /ISAPI/System/Network/interfaces/<ID>/wireless/accessPointList
Get Wi-Fi hotspot list.

Request URL Definition
       Table 15-497 GET /ISAPI/System/Network/interfaces/<ID>/wireless/accessPointList
Method                          GET
Description                     Get Wi-Fi hotspot list.
Query                           None.
Request                         None.
Response                        Succeeded: XML_accessPointList
                                Failed: XML_ResponseStatus

15.10.109 /ISAPI/System/Network/interfaces/<ID>/wireless/accessPointList/<ID>
Get a specific Wi-Fi hotspot.

Request URL Definition
    Table 15-498 GET /ISAPI/System/Network/interfaces/<ID>/wireless/accessPointList/<ID>
Method                          GET
Description                     Get a specific Wi-Fi hotspot.
Query                           None.
Request                         None.
Response                        Succeeded: XML_accessPoint
                                Failed: XML_ResponseStatus

15.10.110 /ISAPI/System/Network/interfaces/<ID>/wireless/capabilities
Get the Wi-Fi configuration capability.

Request URL Definition

Method                          GET
Description                     Get the Wi-Fi configuration capability.
Query                           security: the version No. of encryption scheme. When security does
                                not exist, it indicates that the data is not encrypted; when security is
                                1, it indicates that the nodes of sensitive information in the message
                                are encrypted in AES128 CBC mode; when security is 2, it indicates

                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      None.
Response                     Succeeded: XML_Cap_Wireless
                             Failed: XML_ResponseStatus

15.10.111 /ISAPI/System/Network/interfaces/<ID>/wirelessServer
Operations about wireless hotspot configuration.

Request URL Definitions
            Table 15-499 GET /ISAPI/System/Network/interfaces/<ID>/wirelessServer
Method                       GET
Description                  Get wireless hotspot parameters.
Query                        None.
Request                      None.
Response                     XML_WirelessServer
           Table 15-500 PUT /ISAPI/System/Network/interfaces/<ID>/wirelessServer
Method                       PUT
Description                  Set wireless hotspot parameters.
Query                        None.
Request                      XML_WirelessServer
Response                     XML_ResponseStatus

Remarks
The <ID> in the URL refers to the network interface ID.

15.10.112 /ISAPI/System/Network/interfaces/ID/wirelessServer/accessDeviceList
Get list of devices that are connected to the hotspot.

Request URL Definition
  Table 15-501 GET /ISAPI/System/Network/interfaces/<ID>/wirelessServer/accessDeviceList
Method                       GET
Description                  Get list of devices that are connected to the hotspot.
Query                        None.
Request                      None.
Response                     Succeeded: XML_accessDeviceList
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the URL refers to the network interface ID.

15.10.113 /ISAPI/System/Network/interfaces/<ID>/wirelessServer/capabilities
Get configuration capability of wireless hotspot.

Request URL Definition
     Table 15-502 GET /ISAPI/System/Network/interfaces/<ID>/wirelessServer/capabilities
Method                       GET
Description                  Get configuration capability of wireless hotspot.
Query                        None.
Request                      None.
Response                     XML_Cap_WirelessServer

15.10.114 /ISAPI/System/Network/interfaces/<ID>/wirelessServerStatus
Operations about the wireless hotspot status configuration.

Request URL Definition
        Table 15-503 GET /ISAPI/System/Network/interfaces/<ID>/wirelessServerStatus
Method                       GET
Description                  Get the wireless hotspot status parameters.
Query                        None.

Request                      None.
Response                     Succeeded: XML_WirelessServerStatus
                             Failed: XML_ResponseStatus
        Table 15-504 PUT /ISAPI/System/Network/interfaces/<ID>/wirelessServerStatus
Method                       PUT
Description                  Set the wireless hotspot status parameters.
Query                        None.
Request                      XML_WirelessServerStatus
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the network interface ID.

15.10.115 /ISAPI/System/Network/interfaces/<ID>/wirelessServerStatus/
capabilities
Get the wireless hotspot status capability.

Request URL Definition
  Table 15-505 GET /ISAPI/System/Network/interfaces/<ID>/wirelessServerStatus/capabilities
Method                       GET
Description                  Get the wireless hotspot status capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_WirelessServerStatus
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the network interface ID.

15.10.116 /ISAPI/System/Network/interfaces/<ID>/wirelessStatus
Operations about the configuration of wireless network connection status.

Request URL Definition
           Table 15-506 GET /ISAPI/System/Network/interfaces/<ID>/wirelessStatus
Method                       GET
Description                  Get the parameters of wireless network connection status.
Query                        None.
Request                      None.
Response                     Succeeded: XML_WirelessStatus
                             Failed: XML_ResponseStatus
           Table 15-507 PUT /ISAPI/System/Network/interfaces/<ID>/wirelessStatus
Method                       PUT
Description                  Set the parameters of wireless network connection status.
Query                        None.
Request                      XML_WirelessStatus
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the network interface ID.

15.10.117 /ISAPI/System/Network/interfaces/<ID>/wirelessStatus/capabilities
Get the configuration capability of wireless network connection status.

Request URL Definition
     Table 15-508 GET /ISAPI/System/Network/interfaces/<ID>/wirelessStatus/capabilities
Method                       GET
Description                  Get the configuration capability of wireless network connection
                             status.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_WirelessStatus
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the network interface ID.

15.10.118 /ISAPI/System/Network/ipFilter
Operations about IP address filter configuration.

Request URL Definition
                         Table 15-509 GET /ISAPI/System/Network/ipFilter
Method                        GET
Description                   Get the IP filter configuration parameters.
Query                         None.
Request                       None.
Response                      Succeeded: XML_IPFilter
                              Failed: XML_ResponseStatus
                         Table 15-510 PUT /ISAPI/System/Network/ipFilter
Method                        PUT
Description                   Set the IP address filter.
Query                         None.
Request                       XML_IPFilter
Response                      XML_ResponseStatus

15.10.119 /ISAPI/System/Network/ipFilter/capabilities
Get IP address filter configuration capability.

Request URL Definition
                  Table 15-511 GET /ISAPI/System/Network/ipFilter/capabilities
Method                        GET
Description                   Get the IP address configuration capability.
Query                         None.
Request                       None.
Response                      Succeeded: XML_Cap_IPFilter

                             Failed: XML_ResponseStatus

15.10.120 /ISAPI/System/Network/MACFilter
Operations about MAC address filter configuration.

Request URL Definition
                      Table 15-512 GET /ISAPI/System/Network/MACFilter
Method                       GET
Description                  Get the MAC address filter configuration parameters.
Query                        None.
Request                      None.
Response                     XML_MACFilter
                      Table 15-513 PUT /ISAPI/System/Network/MACFilter
Method                       PUT
Description                  Set the MAC address filter.
Query                        None.
Request                      XML_MACFilter
Response                     XML_ResponseStatus

15.10.121 /ISAPI/System/Network/MACFilter/capabilities
Get the MAC address filter configuration capability.

Request URL Definition
                Table 15-514 GET /ISAPI/System/Network/MACFilter/capabilities
Method                       GET
Description                  Get the MAC address filter configuration capability.
Query                        None.
Request                      None.
Response                     XML_Cap_MACFilter

15.10.122 /ISAPI/System/Network/mailing
Operations about email configuration.

Request URL Definition
                        Table 15-515 GET /ISAPI/System/Network/mailing
Method                       GET
Description                  Get email configuration parameters.
Query                        None.
Request                      None.
Response                     XML_mailingList
                        Table 15-516 PUT /ISAPI/System/Network/mailing
Method                       PUT
Description                  Set email parameters.
Query                        None.
Request                      XML_mailingList
Response                     XML_ResponseStatus

15.10.123 /ISAPI/System/Network/mailing/<ID>
Operations about the configuration of a specific email.

Request URL Definition
                     Table 15-517 GET /ISAPI/System/Network/mailing/<ID>
Method                       GET
Description                  Get the configuration parameters of a specific email.
Query                        None.
Request                      None.
Response                     XML_mailing
                     Table 15-518 PUT /ISAPI/System/Network/mailing/<ID>
Method                       PUT
Description                  Set the parameters of a specific email.

Query                        None.
Request                      XML_mailing
Response                     XML_ResponseStatus

Remarks
The <ID> in the URL refers to the email ID.

15.10.124 /ISAPI/System/Network/mailing/capabilities
Get email configuration capability.

Request URL Definition
                  Table 15-519 GET /ISAPI/System/Network/mailing/capabilities
Method                       GET
Description                  Get email configuration capability.
Query                        None.
Request                      None.
Response                     XML_Cap_mailingList

15.10.125 /ISAPI/System/Network/mailing/test
Execute the email test to check if the email server and address are available.

Request URL Definition
                     Table 15-520 POST /ISAPI/System/Network/mailing/test
Method                       POST
Description                  Execute the email test to check if the email server and address are
                             available.
Query                        None.
Request                      XML_mailingTestDescription
Response                     XML_mailingTestResult

15.10.126 /ISAPI/System/Network/POE/capabilities?format=json
Get capability of PoE port parameters configuration.

Request URL Definition
              Table 15-521 GET /ISAPI/System/Network/POE/capabilities?format=json
Method                       GET
Description                  Get the capability of PoE port parameters configuration.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_Cap_POE

15.10.127 /ISAPI/System/Network/POE?format=json
Get or set the PoE port configuration parameters.

Request URL Definition
                   Table 15-522 GET /ISAPI/System/Network/POE?format=json
Method                       GET
Description                  Get PoE port configuration parameters.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_POE
                   Table 15-523 PUT /ISAPI/System/Network/POE?format=json
Method                       PUT
Description                  Set PoE port configuration parameters.
Query                        format: determine the format of request or response message.
Request                      JSON_POE
Response                     JSON_ResponseStatus

15.10.128 /ISAPI/System/Network/resourceStatistics?format=json
Get the information of network resource statistics.

Request URL Definition
            Table 15-524 GET /ISAPI/System/Network/resourceStatistics?format=json
Method                        GET
Description                   Get the information of network resource statistics.
Query                         None.
Request                       None.
Response                      Succeeded: JSON_resourceStatistics
                              Failed: JSON_ResponseStatus

15.10.129 /ISAPI/System/Network/SIP
Operations about the configuration of a specific SIP (Session Initiation Protocol) server.

Request URL Definition
                           Table 15-525 GET /ISAPI/System/Network/SIP
Method                        GET
Description                   Get the parameters of a specific SIP (Session Initiation Protocol)
                              server.
Query                         None.
Request                       None.
Response                      Succeeded: XML_SIPServerList
                              Failed: XML_ResponseStatus
                           Table 15-526 PUT /ISAPI/System/Network/SIP
Method                        PUT
Description                   Set the parameters of a specific SIP (Session Initiation Protocol)
                              server.
Query                         None.
Request                       XML_SIPServerList
Response                      XML_ResponseStatus

15.10.130 /ISAPI/System/Network/SIP/<ID>
Operations about the configuration of a specific SIP (Session Initiation Protocol) server.

Request URL Definition
                        Table 15-527 GET /ISAPI/System/Network/SIP/<ID>
Method                        GET
Description                   Get the parameters of a specific SIP (Session Initiation Protocol)
                              server.
Query                         None.
Request                       None.
Response                      Succeeded: XML_SIPServer
                              Failed: XML_ResponseStatus
                        Table 15-528 PUT /ISAPI/System/Network/SIP/<ID>
Method                        PUT
Description                   Set the parameters of a specific SIP (Session Initiation Protocol)
                              server.
Query                         None.
Request                       XML_SIPServer
Response                      XML_ResponseStatus

15.10.131 /ISAPI/System/Network/SIP/<ID>/capabilities
Get the configuration capability of a specific SIP (Session Initiation Protocol) server.

Request URL Definition
                  Table 15-529 GET /ISAPI/System/Network/SIP/<ID>/capabilities
Method                        GET
Description                   Get the configuration capability of a specific SIP (Session Initiation
                              Protocol) server.
Query                         None.
Request                       None.
Response                      Succeeded: XML_Cap_SIPServer

                              Failed: XML_ResponseStatus

15.10.132 /ISAPI/System/Network/SIP/<ID>/SIPInfo
Operations about the configuration of a piece of SIP (Session Initiation Protocol) information.

Request URL Definition
                    Table 15-530 GET /ISAPI/System/Network/SIP/<ID>/SIPInfo
Method                        GET
Description                   Get the parameters of a piece of SIP (Session Initiation Protocol)
                              information.
Query                         None.
Request                       None.
Response                      Succeeded: XML_SIPInfo
                              Failed: XML_ResponseStatus
                    Table 15-531 PUT /ISAPI/System/Network/SIP/<ID>/SIPInfo
Method                        PUT
Description                   Set the parameters of a piece of SIP (Session Initiation Protocol)
                              information.
Query                         None.
Request                       XML_SIPInfo
Response                      XML_ResponseStatus

15.10.133 /ISAPI/System/Network/SIP/<ID>/SIPInfo/capabilities
Get the configuration capability of a specific piece of SIP (Session Initiation Protocol) information.

Request URL Definition
              Table 15-532 GET /ISAPI/System/Network/SIP/<ID>/SIPInfo/capabilities
Method                        GET
Description                   Get the configuration capability of a specific piece of SIP (Session
                              Initiation Protocol) information.
Query                         None.

Request                       None.
Response                      Succeeded: XML_Cap_SIPInfo
                              Failed: XML_ResponseStatus

15.10.134 /ISAPI/System/Network/SIP/<ID>/SIPInfo/multiInfo
Get or set the information list of SIP servers.

Request URL Definition
              Table 15-533 GET /ISAPI/System/Network/SIP/<ID>/SIPInfo/multiInfo
Method                        GET
Description                   Get the information list of SIP servers.
Query                         None.
Request                       None.
Response                      Succeeded: XML_SIPInfoList
                              Failed: XML_ResponseStatus
              Table 15-534 PUT /ISAPI/System/Network/SIP/<ID>/SIPInfo/multiInfo
Method                        PUT
Description                   Set the information list of SIP servers.
Query                         None.
Request                       XML_SIPInfoList
Response                      XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the SIP server ID.

15.10.135 /ISAPI/System/Network/socketIP
Get the socket IP of current connection.

Request URL Definition
                        Table 15-535 GET /ISAPI/System/Network/socketIP
Method                        GET
Description                   Get the socket IP of current connection.

Query                         None.
Request                       None.
Response                      XML_SocketIP

15.10.136 /ISAPI/System/Network/ssh
Operations about SSH server configurations.

Request URL Definition
                           Table 15-536 GET /ISAPI/System/Network/ssh
Method                        GET
Description                   Get SSH server parameters.
Query                         None.
Request                       None.
Response                      XML_SSH
                           Table 15-537 PUT /ISAPI/System/Network/ssh
Method                        PUT
Description                   Set SSH server parameters.
Query                         None.
Request                       XML_SSH
Response                      XML_ResponseStatus

15.10.137 /ISAPI/System/Network/StaticRoute
Get, set, or delete the parameters of static route.

Request URL Definition
                      Table 15-538 GET /ISAPI/System/Network/StaticRoute
Method                        GET
Description                   Get the parameters of static route.
Query                         None.

Request                     None.
Response                    Succeeded: XML_staticRouteList
                            Failed: XML_ResponseStatus
                     Table 15-539 PUT /ISAPI/System/Network/StaticRoute
Method                      PUT
Description                 Set the parameters of static route.
Query                       None.
Request                     XML_staticRouteList
Response                    XML_ResponseStatus
                   Table 15-540 DELETE /ISAPI/System/Network/StaticRoute
Method                      DELETE
Description                 Delete the parameters of static route.
Query                       None.
Request                     None.
Response                    XML_ResponseStatus

15.10.138 /ISAPI/System/Network/telnetd
Operations about the telnetd service configuration.

Request URL Definition
                       Table 15-541 GET /ISAPI/System/Network/telnetd
Method                      GET
Description                 Get the telnetd service parameters.
Query                       None.
Request                     None.
Response                    Succeeded: XML_Telnetd
                            Failed: XML_ResponseStatus
                       Table 15-542 PUT /ISAPI/System/Network/telnetd
Method                      PUT
Description                 Set the telnetd service parameters.

Query                         None.
Request                       XML_Telnetd
Response                      XML_ResponseStatus

15.10.139 /ISAPI/System/Network/telnetd/capabilities
Get the telnetd service capability.

Request URL Definition
                  Table 15-543 GET /ISAPI/System/Network/telnetd/capabilities
Method                        GET
Description                   Get the telnetd service capability.
Query                         None.
Request                       None.
Response                      Succeeded: XML_Cap_Telnetd
                              Failed: XML_ResponseStatus

15.10.140 /ISAPI/System/Network/UPnP
Operations about UPnP configuration.

Request URL Definition
                          Table 15-544 GET /ISAPI/System/Network/UPnP
Method                        GET
Description                   Get UPnP parameters.
Query                         None.
Request                       None.
Response                      XML_UPnP
                         Table 15-545 PUT /ISAPI/System/Network/UPnP
Method                        PUT
Description                   Set UPnP parameters.
Query                         None.

Request                     XML_UPnP
Response                    XML_ResponseStatus

15.10.141 /ISAPI/System/Network/UPnP/ports
Operations about configuration of all UPnP ports.

Request URL Definition
                     Table 15-546 GET /ISAPI/System/Network/UPnP/ports
Method                      GET
Description                 Get the parameters of all UPnP ports.
Query                       None.
Request                     None.
Response                    XML_ports
                     Table 15-547 PUT /ISAPI/System/Network/UPnP/ports
Method                      PUT
Description                 Set the parameters of all UPnP ports.
Query                       None.
Request                     XML_ports
Response                    XML_ResponseStatus

15.10.142 /ISAPI/System/Network/UPnP/ports/status
Get the mapping statuses of all UPnP ports.

Request URL Definition
                  Table 15-548 GET /ISAPI/System/Network/UPnP/ports/status
Method                      GET
Description                 Get the mapping statuses of all UPnP ports.
Query                       None.
Request                     None.
Response                    XML_portsStatus

15.10.143 /ISAPI/System/Network/UPnP/ports/<ID>
Operations about configuration of a specific UPnP port.

Request URL Definition
                  Table 15-549 GET /ISAPI/System/Network/UPnP/ports/<ID>
Method                      GET
Description                 Get the parameters of a specific UPnP port.
Query                       None.
Request                     None.
Response                    Succeeded: XML_port
                            Failed: XML_ResponseStatus
                  Table 15-550 PUT /ISAPI/System/Network/UPnP/ports/<ID>
Method                      PUT
Description                 Set the parameters of a specific UPnP port.
Query                       None.
Request                     XML_port
Response                    XML_ResponseStatus

Remarks
The <ID> in the request URL refers to UPnP port ID.

15.10.144 /ISAPI/System/Network/UPnP/ports/<ID>/status
Get mapping status of a specific UPnP port.

Request URL Definition
               Table 15-551 GET /ISAPI/System/Network/UPnP/ports/<ID>/status
Method                      GET
Description                 Get mapping status of a specific UPnP port.
Query                       None.
Request                     None.
Response                    Succeeded: XML_portStatus

                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to UPnP port ID.

15.10.145 /ISAPI/System/Network/verificationCodeCheck
Verify the encryption key or verification code.

Request URL Definition
                Table 15-552 POST /ISAPI/System/Network/verificationCodeCheck
Method                       POST
Description                  Verify the encryption key or verification code.
Query                        None.
Request                      XML_CheckInfo
Response                     XML_ResponseStatus

15.10.146 /ISAPI/System/Network/WirelessDial/Interfaces/<ID>/dial
Operations about the wireless dial-up configuration.

Request URL Definition
          Table 15-553 GET /ISAPI/System/Network/WirelessDial/Interfaces/<ID>/dial
Method                       GET
Description                  Get the configuration parameters of wireless dial-up.
Query                        security: the version No. of encryption scheme. When security does
                             not exist, it indicates that the data is not encrypted; when security is
                             1, it indicates that the nodes of sensitive information in the message
                             are encrypted in AES128 CBC mode; when security is 2, it indicates
                             that the nodes of sensitive information in the message are encrypted
                             in AES256 CBC mode.
                             iv: the initialization vector, and it is required when security is 1 or 2.
Request                      None.
Response                     Succeeded: XML_Dial
                             Failed: XML_ResponseStatus

          Table 15-554 PUT /ISAPI/System/Network/WirelessDial/Interfaces/<ID>/dial
Method                        PUT
Description                   Set the wireless dial-up parameters.
Query                         security: the version No. of encryption scheme. When security does
                              not exist, it indicates that the data is not encrypted; when security is
                              1, it indicates that the nodes of sensitive information in the message
                              are encrypted in AES128 CBC mode; when security is 2, it indicates
                              that the nodes of sensitive information in the message are encrypted
                              in AES256 CBC mode.
                              iv: the initialization vector, and it is required when security is 1 or 2.
Request                       XML_Dial
Response                      XML_ResponseStatus

15.10.147 /ISAPI/System/Network/WirelessDial/Interfaces/<ID>/dial/capabilities
Get the wireless dial-up capability.

Request URL Definition
    Table 15-555 GET /ISAPI/System/Network/WirelessDial/Interfaces/<ID>/dial/capabilities
Method                        GET
Description                   Get the wireless dial-up capability.
Query                         security: the version No. of encryption scheme. When security does
                              not exist, it indicates that the data is not encrypted; when security is
                              1, it indicates that the nodes of sensitive information in the message
                              are encrypted in AES128 CBC mode; when security is 2, it indicates
                              that the nodes of sensitive information in the message are encrypted
                              in AES256 CBC mode.
                              iv: the initialization vector, and it is required when security is 1 or 2.
Request                       None.
Response                      Succeeded: XML_Cap_Dial
                              Failed: XML_ResponseStatus

15.10.148 /ISAPI/System/Network/WirelessDial/Interfaces/<ID>/dialstatus
Operations about the configuration of wireless dial-up connection status.

Request URL Definition
        Table 15-556 GET /ISAPI/System/Network/WirelessDial/Interfaces/<ID>/dialstatus
Method                       GET
Description                  Get the parameters of wireless dial-up connection status.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Dialstatus
                             Failed: XML_ResponseStatus
        Table 15-557 PUT /ISAPI/System/Network/WirelessDial/Interfaces/<ID>/dialstatus
Method                       PUT
Description                  Set the parameters of wireless dial-up connection status.
Query                        None.
Request                      XML_Dialstatus
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the network interface ID.

15.10.149 /ISAPI/System/onlineUpgrade/capabilities
Get the device online upgrade capability.

Request URL Definition
                  Table 15-558 GET /ISAPI/System/onlineUpgrade/capabilities
Method                       GET
Description                  Get the device online upgrade capability.
Query                        None.
Request                      None.
Response                     XML_OnlineUpgradeCap

15.10.150 /ISAPI/System/onlineUpgrade/deviceParameter?format=json
Get and set the device online upgrade parameters.

Request URL Definition
          Table 15-559 GET /ISAPI/System/onlineUpgrade/deviceParameter?format=json
Method                     GET
Description                Get the device online upgrade parameters.
Query                      format: determine the format of request or response message.
Request                    None.
Response                   Succeeded: JSON_OnlineUpgradeParameter
                           Failed: JSON_ResponseStatus
          Table 15-560 PUT /ISAPI/System/onlineUpgrade/deviceParameter?format=json
Method                     PUT
Description                Set the device online upgrade parameters.
Query                      format: determine the format of request or response message.
Request                    JSON_OnlineUpgradeParameter
Response                   JSON_ResponseStatus

15.10.151 /ISAPI/System/onlineUpgrade/downloadPackage/pause?format=json
Pause the upgrade package download.

Request URL Definition
    Table 15-561 PUT /ISAPI/System/onlineUpgrade/downloadPackage/pause?format=json
Method                     PUT
Description                Pause upgrade package download.
Query                      format: determine the format of request or response message.
Request                    None.
Response                   JSON_ResponseStatus

15.10.152 /ISAPI/System/onlineUpgrade/downloadPackage/resume?format=json
Resume the upgrade package download.

Request URL Definition
   Table 15-562 PUT /ISAPI/System/onlineUpgrade/downloadPackage/resume?format=json
Method                      PUT
Description                 Resume the upgrade package download.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    JSON_ResponseStatus

15.10.153 /ISAPI/System/onlineUpgrade/downloadPackage/status?format=json
Get the upgrade package download progress.

Request URL Definition
    Table 15-563 GET /ISAPI/System/onlineUpgrade/downloadPackage/status?format=json
Method                      GET
Description                 Get the upgrade package download progress.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    Succeeded: JSON_DownloadPackageStatus
                            Failed: JSON_ResponseStatus

15.10.154 /ISAPI/System/onlineUpgrade/downloadPackage?format=json
Start or cancel downloading upgrade package to device.

Request URL Definition
        Table 15-564 PUT /ISAPI/System/onlineUpgrade/downloadPackage?format=json
Method                      PUT
Description                 Start to download upgrade package to device.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    JSON_ResponseStatus

       Table 15-565 DELETE /ISAPI/System/onlineUpgrade/downloadPackage?format=json
Method                       DELETE
Description                  Cancel the upgrade package download.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_ResponseStatus

15.10.155 /ISAPI/System/onlineUpgrade/ignoreCurrentVersion?format=json
Ignore the current upgrade package version.

Request URL Definition
      Table 15-566 PUT /ISAPI/System/onlineUpgrade/ignoreCurrentVersion?format=json
Method                       PUT
Description                  Ignore the current upgrade package version.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_ResponseStatus

Remarks
If the current upgrade package version is ignored, it will not be found in further detection.

15.10.156 /ISAPI/System/onlineUpgrade/server
Get the online upgrade server status.

Request URL Definition
                      Table 15-567 GET /ISAPI/System/onlineUpgrade/server
Method                       GET
Description                  Get the online upgrade server status.
Query                        None.
Request                      None.
Response                     XML_OnlineUpgradeServer

15.10.157 /ISAPI/System/onlineUpgrade/status
Get the online upgrade progress of device.

Request URL Definition
                     Table 15-568 GET /ISAPI/System/onlineUpgrade/status
Method                      GET
Description                 Get the online upgrade progress of device.
Query                       None.
Request                     None.
Response                    XML_OnlineUpgradeStatus

15.10.158 /ISAPI/System/onlineUpgrade/upgradeWithoutDownload?format=json
Start device upgrade with existed upgrade package.

Request URL Definition
   Table 15-569 PUT /ISAPI/System/onlineUpgrade/upgradeWithoutDownload?format=json
Method                      PUT
Description                 Start upgrade with existed upgrade package.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    JSON_ResponseStatus

15.10.159 /ISAPI/System/onlineUpgrade/version
Get the information of new upgrade package.

Request URL Definition
                    Table 15-570 GET /ISAPI/System/onlineUpgrade/version
Method                      GET
Description
Query                       check

Request                       None.
Response                      XML_OnlineUpgradeVersion

15.10.160 /ISAPI/System/reboot
Reboot device.

Request URL Definition
                              Table 15-571 PUT /ISAPI/System/reboot
Method                        PUT
Description                   Reboot device.
Query                         None.
Request                       None.
Response                      XML_ResponseStatus

15.10.161 /ISAPI/System/Serial/capabilities
Get the serial port capability of the device.

Request URL Definition
                        Table 15-572 GET /ISAPI/System/Serial/capabilities
Method                        GET
Description                   Get the serial port capability of the device.
Query                         None.
Request                       None.
Response                      Succeeded: XML_SerialCap
                              Failed: XML_ResponseStatus

15.10.162 /ISAPI/System/Serial/ports
Get the list of serial ports supported by the device.

Request URL Definition
                            Table 15-573 GET /ISAPI/System/Serial/ports
Method                         GET
Description                    Get the list of serial ports supported by the device.
Query                          None.
Request                        None.
Response                       Succeeded: XML_SerialPorList
                               Failed: XML_ResponseStatus

15.10.163 /ISAPI/System/Serial/ports/<ID>
Operations about the configuration of a specific serial port supported by the device.

Request URL Definition
                         Table 15-574 GET /ISAPI/System/Serial/ports/<ID>
Method                         GET
Description                    Get the parameters of a specific port supported by the device.
Query                          None.
Request                        None.
Response                       Succeeded: XML_SerialPort
                               Failed: XML_ResponseStatus
                         Table 15-575 PUT /ISAPI/System/Serial/ports/<ID>
Method                         PUT
Description                    Set the parameters of a specific serial port supported by the device.
Query                          None.
Request                        XML_SerialPort
Response                       XML_ResponseStatus

15.10.164 /ISAPI/System/Serial/ports/<ID>/capabilities
Get the capability of a specific serial port.

Request URL Definition
                 Table 15-576 GET /ISAPI/System/Serial/ports/<ID>/capabilities
Method                       GET
Description                  Get the capability of a specific serial port.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_SerialPort
                             Failed: XML_ResponseStatus

15.10.165 /ISAPI/System/Serial/ports/command
Send a command to a serial port.

Request URL Definition
                     Table 15-577 PUT /ISAPI/System/Serial/ports/command
Method                       PUT
Description                  Send a command to a serial port.
Query                        None.
Request                      XML_SerialCommand or query string with raw command in binary
                             format
Response                     XML_ResponseStatus

Remarks
• If the device is an encoder that converts analog signals to digital signals and it is connected to
  analog cameras with PTZ enabled, the encoder will forward the command to the appropriate
  serial port according to the <chainNo> node of the XML message or the query string of the HTTP
  request.
• If the device is a digital camera with PTZ enabled, the camera will forward the PTZ command to
  the corresponding serial port.
• The serial port command can be encapsulated in the <command> node of the XML message,
  and the command should be encoded in hexadecimal notation; or the serial port command can
  be directly uploaded as payload of the HTTP request, and in this case the Content-Type should
  be set to "application/octet-stream", and the query string chainNo should be set.
Example
Sample Code of Command in XML Format

PUT /ISAPI/System/Serial/ports/999/command HTTP/1.1
Content-Type: application/xml; charset=”UTF-8”
Content-Length: xxx

<?xml version=“1.0” encoding=“UTF-8”?>
<SerialCommand>
 <chainNo>0</chainNo>
 <command>ab45be8778cd</command>
</SerialCommand>

Example
Sample Code of Command Using Query String
/ISAPI/System/Serial/ports/999/command?chainNo=1 HTTP/1.1
Content-Type: application/octet-stream
Content-Length: xxx
(...Raw data of the command should be inserted here...)

15.10.166 /ISAPI/System/Serial/ports/command/capabilities
Get the serial port command capability.

Request URL Definition
               Table 15-578 GET /ISAPI/System/Serial/ports/command/capabilities
Method                         GET
Description                    Get the serial port command capability.
Query                          None.
Request                        None.
Response                       Succeeded: XML_Cap_SerialCommand
                               Failed: XML_ResponseStatus

15.10.167 /ISAPI/System/serialLogCfg/capabilities?format=json
Get the configuration capability of serial port log redirection.

Request URL Definition
              Table 15-579 GET /ISAPI/System/serialLogCfg/capabilities?format=json
Method                         GET
Description                    Get the configuration capability of serial port log redirection.

Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_SerialLogCfgCap
                             Failed: JSON_ResponseStatus

15.10.168 /ISAPI/System/serialLogCfg?format=json
Operations about the redirection configuration of serial port log.

Request URL Definition
                    Table 15-580 GET /ISAPI/System/serialLogCfg?format=json
Method                       GET
Description                  Get the redirection parameters of serial port log.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_SerialLogCfg
                             Failed: JSON_ResponseStatus
                    Table 15-581 PUT /ISAPI/System/serialLogCfg?format=json
Method                       PUT
Description                  Set the redirection parameters of serial port log.
Query                        format: determine the format of request or response message.
Request                      JSON_SerialLogCfg
Response                     JSON_ResponseStatus

15.10.169 /ISAPI/System/shutdown?format=json
Shut down the device.

Request URL Definition
                     Table 15-582 PUT /ISAPI/System/shutdown?format=json
Method                       PUT
Description                  Shut down the device.
Query                        format: determine the format of request or response message.

Request                      None.
Response                     JSON_ResponseStatus

15.10.170 /ISAPI/System/Software/channels/<ID>
Operation about software service configuration.

Request URL Definition
                    Table 15-583 GET /ISAPI/System/Software/channels/<ID>
Method                       GET
Description                  Get software service parameters.
Query                        None.
Request                      None.
Response                     XML_SoftwareService
                    Table 15-584 PUT /ISAPI/System/Software/channels/<ID>
Method                       PUT
Description                  Set software service parameters.
Query                        None.
Request                      XML_SoftwareService
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.10.171 /ISAPI/System/Software/channels/<ID>/capabilities
Get the configuration capability of software service.

Request URL Definition
              Table 15-585 GET /ISAPI/System/Software/channels/<ID>/capabilities
Method                       GET
Description                  Get the configuration capability of software service.
Query                        None.

Request                     None.
Response                    XML_Cap_SoftwareService

Remarks
The <ID> in the request URL refers to the channel No.

15.10.172 /ISAPI/System/status
Get device status, e.g., CPU, memory, and so on.

Request URL Definition
                             Table 15-586 GET /ISAPI/System/status
Method                      GET
Description                 Get device status, e.g., CPU, memory, and so on.
Query                       None.
Request                     None.
Response                    Succeeded: XML_DeviceStatus
                            Failed: XML_ResponseStatus

15.10.173 /ISAPI/System/syncSignalOutput/<ID>
Operations about the configuration of synchronous signal output.

Request URL Definition
                    Table 15-587 GET /ISAPI/System/syncSignalOutput/<ID>
Method                      GET
Description                 Get the parameters of synchronous signal output.
Query                       None.
Request                     None.
Response                    Succeeded: XML_SyncSignalOutputList
                            Failed: XML_ResponseStatus
                    Table 15-588 PUT /ISAPI/System/syncSignalOutput/<ID>
Method                      PUT
Description                 Set the parameters of synchronous signal output.

Query                        None.
Request                      XML_SyncSignalOutputList
Response                     XML_ResponseStatus

15.10.174 /ISAPI/System/syncSignalOutput/<ID>/capabilities
Get the configuration capability of synchronous signal output.

Request URL Definition
              Table 15-589 GET /ISAPI/System/syncSignalOutput/<ID>/capabilities
Method                       GET
Description                  Get the configuration capability of synchronous signal output.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_SyncSignalOutputList
                             Failed: XML_ResponseStatus

15.10.175 /ISAPI/System/time
Operations about the device time configuration.

Request URL Definition
                              Table 15-590 GET /ISAPI/System/time
Method                       GET
Description                  Get the device time parameters.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Time
                             Failed: XML_ResponseStatus
                              Table 15-591 PUT /ISAPI/System/time
Method                       PUT
Description                  Set the device time parameters.
Query                        None.

Request                      XML_Time
Response                     XML_ResponseStatus

15.10.176 /ISAPI/System/time/capabilities
Get the time capability of the device.

Request URL Definition
                        Table 15-592 GET /ISAPI/System/time/capabilities
Method                       GET
Description                  Get the time capability of the device.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_Time
                             Failed: XML_ResponseStatus

15.10.177 /ISAPI/System/time/localTime
Operations about the configuration of device local time.

Request URL Definition
                         Table 15-593 GET /ISAPI/System/time/localTime
Method                       GET
Description                  Get the configuration parameters of device local time.
Query                        None.
Request                      None.
Response                     String with date and time information (ISO8601 format, e.g., 2018-
                             02-10T17:30:08)
                         Table 15-594 PUT /ISAPI/System/time/localTime
Method                       PUT
Description                  Set device local time.
Query                        None.

Request                     String with date and time information (ISO8601 format, e.g., 2018-
                            02-10T17:30:08)
Response                    XML_ResponseStatus

15.10.178 /ISAPI/System/time/ntpServers
Operations about the configurations of multiple NTP servers.

Request URL Definition
                       Table 15-595 GET /ISAPI/System/time/ntpServers
Method                      GET
Description                 Get the parameters of multiple NTP servers.
Query                       None.
Request                     None.
Response                    Succeeded: XML_NTPServerList
                            Failed: XML_ResponseStatus
                       Table 15-596 PUT /ISAPI/System/time/ntpServers
Method                      PUT
Description                 Set the parameters of multiple NTP servers.
Query                       None.
Request                     XML_NTPServerList
Response                    XML_ResponseStatus
                       Table 15-597 POST /ISAPI/System/time/ntpServers
Method                      POST
Description                 Add a NTP server.
Query                       None.
Request                     XML_NTPServer
Response                    XML_ResponseStatus
                      Table 15-598 DELETE /ISAPI/System/time/ntpServers
Method                      DELETE
Description                 Delete multiple NTP servers.

Query                         None.
Request                       None.
Response                      XML_ResponseStatus

15.10.179 /ISAPI/System/time/ntpServers/<ID>
Operations about the configurations of a NTP server.

Request URL Definition
                      Table 15-599 GET /ISAPI/System/time/ntpServers/<ID>
Method                        GET
Description                   Get the parameters of a NTP server.
Query                         None.
Request                       None.
Response                      Succeeded: XML_NTPServer
                              Failed: XML_ResponseStatus
                      Table 15-600 PUT /ISAPI/System/time/ntpServers/<ID>
Method                        PUT
Description                   Set the parameters of a NTP server.
Query                         None.
Request                       XML_NTPServer
Response                      XML_ResponseStatus
                    Table 15-601 DELETE /ISAPI/System/time/ntpServers/<ID>
Method                        DELETE
Description                   Delete the configuration parameters of a NTP server.
Query                         None.
Request                       None.
Response                      XML_ResponseStatus

15.10.180 /ISAPI/System/time/ntpServers/<ID>/capabilities
Get the configuration capability of a specific NTP server.

Request URL Definition
               Table 15-602 GET /ISAPI/System/time/ntpServers/<ID>/capabilities
Method                        GET
Description                   Get the configuration capability of a specific NTP server.
Query                         None.
Request                       None.
Response                      Succeeded: XML_Cap_NTPServer
                              Failed: XML_ResponseStatus

15.10.181 /ISAPI/System/time/ntpServers/capabilities
Get the NTP service capability.

Request URL Definition
                  Table 15-603 GET /ISAPI/System/time/ntpServers/capabilities
Method                        GET
Description                   Get the NTP service capability.
Query                         None.
Request                       None.
Response                      Succeeded:
                              Failed: XML_ResponseStatus

15.10.182 /ISAPI/System/time/ntpServers/test
Execute a test to check if the NTP server is available.

Request URL Definition
                      Table 15-604 POST /ISAPI/System/time/ntpServers/test
Method                        POST
Description                   Execute a test to check if the NTP server is available.
Query                         None.

Request                     XML_NTPTestDescription
Response                    XML_NTPTestResult

15.10.183 /ISAPI/System/time/timeType?format=json
Operations about device time type configuration.

Request URL Definition
                 Table 15-605 GET /ISAPI/System/time/timeType?format=json
Method                      GET
Description                 Get the device time type.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    JSON_TimeType
                 Table 15-606 PUT /ISAPI/System/time/timeType?format=json
Method                      PUT
Description                 Set the device time type.
Query                       format: determine the format of request or response message.
Request                     JSON_TimeType
Response                    JSON_ResponseStatus

15.10.184 /ISAPI/System/time/timeZone
Operations about the configuration of device time zone.

Request URL Definition
                        Table 15-607 GET /ISAPI/System/time/timeZone
Method                      GET
Description                 Get the device time zone parameters.
Query                       None.
Request                     None.
Response                    String containing time zone information

                          Table 15-608 PUT /ISAPI/System/time/timeZone
Method                        PUT
Description                   Set the device time zone parameters.
Query                         None.
Request                       String containing time zone information
Response                      XML_ResponseStatus

15.10.185 /ISAPI/System/TwoWayAudio/channels
Get audio parameters of all two-way audio channels.

Request URL Definition
                     Table 15-609 GET /ISAPI/System/TwoWayAudio/channels
Method                        GET
Description                   Get parameters of all two-way audio channels.
Query                         None.
Request                       None.
Response                      Succeeded: XML_TwoWayAudioChannelList
                              Failed: XML_ResponseStatus

Example
Sample Code for Getting Parameters of All Two-Way Audio Channels
GET /ISAPI/System/TwoWayAudio/channels HTTP/1.1
Host: 10.17.132.49
Connection: Keep-Alive
Authorization: Digest username="admin",
realm="DS-2CD2F12FWD-IWS",
nonce="4e4446464e6a6333516a63365a4445304f47526a4e32553d",
uri="/ISAPI/System/TwoWayAudio/channels",
cnonce="145ef1bc3ab456be09918d39b77e78ae",
nc=00000021,
response="d10bab23689c60e95241230fff3181b0",
qop="auth"

HTTP/1.1 200 OK
Date: Wed, 15 Mar 2017 09:25:29 GMT
Server: App-webs/
Connection: close
Content-Length: 467
Content-Type: application/xml

<?xml version="1.0" encoding="UTF-8"?>
<TwoWayAudioChannelList version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <TwoWayAudioChannel version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
  <id>1</id>
  <enabled>false</enabled>
  <audioCompressionType>G.711ulaw</audioCompressionType>
  <audioInputType>MicIn</audioInputType>
  <speakerVolume>50</speakerVolume>
  <noisereduce>false</noisereduce>
 </TwoWayAudioChannel>
</TwoWayAudioChannelList>

15.10.186 /ISAPI/System/TwoWayAudio/channels/<ID>
Operations about the configuration of a specific two-way audio channel.

Request URL Definition
                  Table 15-610 GET /ISAPI/System/TwoWayAudio/channels/<ID>
Method                        GET
Description                   Get the parameters of a specific two-way audio channel.
Query                         None.
Request                       None.
Response                      Succeeded: XML_TwoWayAudioChannel
                              Failed: XML_ResponseStatus
                  Table 15-611 PUT /ISAPI/System/TwoWayAudio/channels/<ID>
Method                        PUT
Description                   Set the parameters of a specific two-way audio channel.
Query                         None.
Request                       XML_TwoWayAudioChannel
Response                      XML_ResponseStatus

15.10.187 /ISAPI/System/TwoWayAudio/channels/<ID>/audioData
Receive or send audio data from or to a specific two-way audio channel.

Request URL Definition
                 Table 15-612 GET /ISAPI/System/TwoWayAudio/channels/<ID>/audioData
 Method                                    GET
 Description                               Receive audio data from a specific two-way audio channel.
 Query                                     sessionId: communication session ID, which is required when the
                                           two-way audio is started between multiple channels and a channel;
                                           otherwise, the session ID is not required.
 Request                                   None.
 Response                                  Succeeded: audio data
                                           Failed: XML_ResponseStatus
                 Table 15-613 PUT /ISAPI/System/TwoWayAudio/channels/<ID>/audioData
 Method                                    GET
 Description                               Send audio data to a specific two-way audio channel.
 Query                                     sessionId: communication session ID, which is required when the
                                           two-way audio is started between multiple channels and a channel;
                                           otherwise, the session ID is not required.
 Request                                   Audio data.
 Response                                  XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the two-way audio channel ID.
Example
Sample Code for Sending Audio Data to Device
PUT /ISAPI/System/TwoWayAudio/channels/1/audioData HTTP/1.1
HOST: 10.17.132.49
Authorization: Digest username="admin",
realm="DS-2CD2F12FWD-IWS",
nonce="4e3055314e6a64434e7a59365a4445304f545668596a6b3d",
uri="/ISAPI/System/TwoWayAudio/channels/1/audioData",
response="6a03c7e85c17a35bae9ee6f3cfcd254b"
Connection: keep-alive
Content-Length: 0
Content-Type: application/octet-stream

HTTP/1.1 200 OK

..U....U..............U...........U........ (Binary audio data)

Example
Sample Code for Receiving Audio Data from Device
GET /ISAPI/System/TwoWayAudio/channels/1/audioData HTTP/1.1
HOST: 10.17.132.49
Authorization: Digest username="admin",
realm="DS-2CD2F12FWD-IWS",
nonce="4e3055314e6a64434e7a59365a4445304f5456685a44673d",
uri="/ISAPI/System/TwoWayAudio/channels/1/audioData",
response="7ea0ec7bd102b3c4cb225cbf33adb8f8"
Connection: keep-alive

HTTP/1.1 200 OK
Content-Type: audio/basic

Q......U..dzR..\.FfN...q[....z..q.......`. (Binary audio data)

15.10.188 /ISAPI/System/TwoWayAudio/channels/<ID>/capabilities
Get the capability of a specific two-way audio channel.

Request URL Definition
               Table 15-614 GET /ISAPI/System/TwoWayAudio/channels/<ID>/capabilities
Method                                  GET
Description                             Get the capability of a specific two-way audio channel.
Query                                   None.
Request                                 None.
Response                                Succeeded: XML_TwoWayAudioChannelCap
                                        Failed: XML_ResponseStatus

15.10.189 /ISAPI/System/TwoWayAudio/channels/<ID>/close
Stop two-way audio of a specific channel.

Request URL Definition
                   Table 15-615 PUT /ISAPI/System/TwoWayAudio/channels/<ID>/close
Method                                  PUT
Description                             Stop two-way audio of a specific channel.
Query                                   None.

Request                        None.
Response                       XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the two-way audio channel ID.
Example
Sample Code for Stopping Two-Way Audio
PUT /ISAPI/System/TwoWayAudio/channels/1/close HTTP/1.1
HOST: 10.17.132.49
Authorization: Digest username="admin",
realm="DS-2CD2F12FWD-IWS",
nonce="4e54457a4d7a67354d6a6b365a4445304f5463794d32553d",
uri="/ISAPI/System/TwoWayAudio/channels/1/close",
response="7d5acdc3ccf7c080400802800d7471e3"
Content-Length: 0

HTTP/1.1 200 OK
Date: Wed, 15 Mar 2017 09:25:35 GMT
Server: App-webs/
Connection: close
Content-Length: 298
Content-Type: application/xml

<?xml version="1.0" encoding="UTF-8"?>
<ResponseStatus version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <requestURL>/ISAPI/System/TwoWayAudio/channels/1/close</requestURL>
 <statusCode>1</statusCode>
 <statusString>OK</statusString>
 <subStatusCode>ok</subStatusCode>
</ResponseStatus>

15.10.190 /ISAPI/System/TwoWayAudio/channels/<ID>/open
Start two-way audio of a specific channel.

Request URL Definition
               Table 15-616 PUT /ISAPI/System/TwoWayAudio/channels/<ID>/open
Method                         PUT
Description                    Start two-way audio of a specific channel.
Query                          None.
Request                        None.
Response                       Succeeded: XML_TwoWayAudioSession

                              Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the two-way audio channel ID.
Example
Sample Code for Start Two-Way Audio
PUT /ISAPI/System/TwoWayAudio/channels/1/open HTTP/1.1
HOST: 10.17.132.49
Authorization: Digest username="admin",
realm="DS-2CD2F12FWD-IWS",
nonce="4e3055314e6a64434e7a59365a4445304f5456685957453d",
uri="/ISAPI/System/TwoWayAudio/channels/1/open",
response="368dda22535b9783bdccafc3b2ded29a"
Content-Length: 0

HTTP/1.1 200 OK
Date: Wed, 15 Mar 2017 09:25:29 GMT
Server: App-webs/
Connection: close
Content-Length: 183
Content-Type: application/xml

<?xml version="1.0" encoding="UTF-8"?>
<TwoWayAudioSession version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <sessionId>2093716360</sessionId>
</TwoWayAudioSession>

15.10.191 /ISAPI/System/unitConfig/capabilities?format=json
Get the capability of unit unified configuration.

Request URL Definition
               Table 15-617 GET /ISAPI/System/unitConfig/capabilities?format=json
Method                        GET
Description                   Get the capability of unit unified configuration.
Query                         format: determine the format of request or response message.
Request                       None.
Response                      Succeeded: JSON_unitConfigCap
                              Failed: JSON_ResponseStatus

15.10.192 /ISAPI/System/unitConfig?format=json
Get and set the unit unified configuration parameters.

Request URL Definition
                    Table 15-618 GET /ISAPI/System/unitConfig?format=json
Method                      GET
Description                 Get the unit unified configuration parameters.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    Succeeded: JSON_unitConfig
                            Failed: JSON_ResponseStatus
                    Table 15-619 PUT /ISAPI/System/unitConfig?format=json
Method                      PUT
Description                 Set the unit unified configuration parameters.
Query                       format: determine the format of request or response message.
Request                     JSON_unitConfig
Response                    JSON_ResponseStatus

15.10.193 /ISAPI/System/updateFirmware
Upgrade the device firmware.

Request URL Definition
                   Table 15-620 PUT or POST /ISAPI/System/updateFirmware
Method                      PUT, POST
Description                 Upgrade the device firmware.
Query                       None.
Request                     Opaque data (binary data for PUT method, data in form format for
                            POST method).
Response                    XML_ResponseStatus

Remarks
After upgrading the device firmware, the device will automatically reboot according to the
response message. If upgrading failed, the following reasons may be returned: "upgrading"-the
device is upgrading, "badFlash"-flash error, "badLanguage"-language mismatches.
Example
The URL Interaction in Form Format
/ISAPI/System/updateFirmware
Accept: text/html, application/xhtml+xml,
Accept-Language: zh-CN
Content-Type: multipart/form-data; boundary=---------------------------7e13971310878
User-Agent: Mozilla/5.0 (compatible; MSIE 9.0; Windows NT 6.1; WOW64; Trident/5.0)
Accept-Encoding: gzip, deflate
Host: 10.10.36.29:8080
Content-Length: 9907
Connection: Keep-Alive
Cache-Control: no-cache

-----------------------------7e13971310878
Content-Disposition: form-data; name="updateFile";
Content-Type: File/ Opaque Data
Content-Length: 9907

..........`.`.....C........... .
..
................. $.' ",#..(7),01444.'9=82<.342...C.   ....
-----------------------------7e13971310878--

15.10.194 /ISAPI/System/updateFirmware?type=&id=
Upgrade the slave device's firmware.

Request URL Definition
                   Table 15-621 PUT or POST /ISAPI/System/updateFirmware?type=&id=
Method                                   PUT, POST
Description                              Upgrade the slave device's firmware.
Query                                    type: device or module type, string type, it can be set to one of the
                                         following values: "cardReader"-card reader, "FPModule"-​fingerprint
                                         module, "securityModule"-secure door control unit,
                                         "extendModule"- (IO) extension module, "channelController"-lane
                                         controller, "IRModule"-IR module, "lampModule"-indicator module,
                                         "elevatorController"-slave elevator controller, and

                             "FPAlgorithmProgram"-​fingerprint algorithm program of the card
                             reader, "uboot".
                             id: slave device No., e.g., /ISAPI/System/updateFirmware?
                             type=cardReader&id=1 refers to upgrading firmware of card reader 1.
Request                      Opaque data (binary data for PUT method, data in form format for
                             POST method).
Response                     XML_ResponseStatus

Remarks
After upgrading the slave device's firmware, the device will automatically reboot according to the
response message. If upgrading failed, the following reasons may be returned: "upgrading"-the
device is upgrading, "badFlash"-flash error, "badLanguage"-language mismatches.

15.10.195 /ISAPI/System/updateFirmware?type=&moduleAddress=
Upgrade the peripheral module's firmware.

Request URL Definition
      Table 15-622 PUT or POST /ISAPI/System/updateFirmware?type=&moduleAddress=
Method                       PUT, POST
Description                  Upgrade the peripheral module's firmware.
Query                        type: device or module type, string type, it can be set to one of the
                             following values: "keypad", "wirelessRecv"-wireless receiving
                             module, "wiredZone"-wired zone module.
                             moduleAddress: module address, e.g., /ISAPI/System/
                             updateFirmware?type=wirelessRecv&moduleAddress=1 refers to
                             upgrading firmware of the wireless receiving module with the
                             module address 1.
Request                      Opaque data (binary data for PUT method, data in form format for
                             POST method).
Response                     XML_ResponseStatus

Remarks
After upgrading the peripheral module's firmware, the device will automatically reboot according
to the response message. If upgrading failed, the following reasons may be returned: "upgrading"-
the device is upgrading, "badFlash"-flash error, "badLanguage"-language mismatches.

15.10.196 /ISAPI/System/upgradeStatus
Get the device upgrading status and progress.

Request URL Definition
                          Table 15-623 GET /ISAPI/System/upgradeStatus
Method                       GET
Description                  Get the device upgrading status and progress.
Query                        None.
Request                      None.
Response                     Succeeded: XML_upgradeStatus
                             Failed: XML_ResponseStatus

15.10.197 /ISAPI/System/userLock/config/capabilities?format=json
Get the configuration capability of locking IP address.

Request URL Definition
           Table 15-624 GET /ISAPI/System/userLock/config/capabilities?format=json
Method                       GET
Description                  Get the configuration capability of locking IP address.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_LockCfgCap
                             Failed: JSON_ResponseStatus

15.10.198 /ISAPI/System/userLock/config?format=json
Operations about IP address locking configuration.

Request URL Definition
                  Table 15-625 GET /ISAPI/System/userLock/config?format=json
Method                       GET
Description                  Get the parameters of IP address locking.

Query                          format: determine the format of request or response message.
Request                        None.
Response                       Succeeded: JSON_LockCfg
                               Failed: JSON_ResponseStatus

PUT /ISAPI/System/userLock/config?format=json

Method                         PUT
Description                    Set the parameters of IP address locking.
Query                          format: determine the format of request or response message.
Request                        JSON_LockCfg
Response                       JSON_ResponseStatus

15.10.199 /ISAPI/System/userLock/lockedUsers?format=json
Get all locked IP addresses.

Request URL Definition
               Table 15-626 GET /ISAPI/System/userLock/lockedUsers?format=json
Method                         GET
Description                    Get all locked IP addresses.
Query                          format: determine the format of request or response message.
Request                        None.
Response                       Succeeded: JSON_List_IPAddress
                               Failed: JSON_ResponseStatus

15.10.200 /ISAPI/System/userLock/unlockUser?format=json
Unlock the IP address.

Request URL Definition
               Table 15-627 PUT /ISAPI/System/userLock/unlockUser?format=json
Method                         PUT
Description                    Unlock the IP address.

Query                           format: determine the format of request or response message.
Request                         JSON_operType
Response                        JSON_ResponseStatus

15.10.201 /ISAPI/System/Video/capabilities
Get video channel capability.

Request URL Definition
                        Table 15-628 GET /ISAPI/System/Video/capabilities
Method                          GET
Description                     Get video channel capability.
Query                           None.
Request                         None.
Response                        Succeeded: XML_VideoCap
                                Failed: XML_ResponseStatus

15.10.202 /ISAPI/System/Video/inputs
Get the video input configuration of the device.

Request URL Definition
                          Table 15-629 GET /ISAPI/System/Video/inputs
Method                          GET
Description                     Get the video input configuration parameters of the device.
Query                           None.
Request                         None.
Response                        Succeeded: XML_VideoInput
                                Failed: XML_ResponseStatus

15.10.203 /ISAPI/System/Video/inputs/channels
Get the configuration of all video input channels of the device.

Request URL Definition
                     Table 15-630 GET /ISAPI/System/Video/inputs/channels
Method                       GET
Description                  Get the configuration parameters of all video input channels of the
                             device.
Query                        None.
Request                      None.
Response                     Succeeded: XML_VideoInputChannelList
                             Failed: XML_ResponseStatus

15.10.204 /ISAPI/System/Video/inputs/channels/<ID>
Operations about the configuration of a specific video input channel of the device.

Request URL Definition
                  Table 15-631 GET /ISAPI/System/Video/inputs/channels/<ID>
Method                       GET
Description                  Get the parameters of a specific video input channel of the device.
Query                        None.
Request                      None.
Response                     Succeeded: XML_VideoInputChannel
                             Failed: XML_ResponseStatus
                  Table 15-632 PUT /ISAPI/System/Video/inputs/channels/<ID>
Method                       PUT
Description                  Set the parameters of a specific video input channel of the device.
Query                        None.
Request                      XML_VideoInputChannel
Response                     XML_ResponseStatus

See Also
The <ID> in the request URL refers to the channel No.

15.10.205 /ISAPI/System/Video/inputs/channels?format=json
Get the information of all channels according to the request message.

Request URL Definition
              Table 15-633 POST /ISAPI/System/Video/inputs/channels?format=json
Method                       POST
Description                  Get the information of all channels according to the request
                             message.
Query                        format: determine the format of request or response message.
Request                      JSON_InputParam
Response                     Succeeded: JSON_ChannelInfoList
                             Failed: JSON_ResponseStatus

15.10.206 /ISAPI/System/Video/inputs/channels/<ID>/focus
Perform manual focus on a specific channel.

Request URL Definition
               Table 15-634 PUT /ISAPI/System/Video/inputs/channels/<ID>/focus
Method                       PUT
Description                  Perform manual focus on a specific channel.
Query                        None.
Request                      XML_FocusData
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to video input channel ID.

15.10.207 /ISAPI/System/Video/inputs/channels/<ID>?format=json
Get the information of a channel according to the request message.

Request URL Definition
           Table 15-635 POST /ISAPI/System/Video/inputs/channels/<ID>?format=json
Method                        POST
Description                   Get the information of a channel according to the request message.
Query                         format: determine the format of request or response message.
Request                       JSON_InputParam
Response                      Succeeded: JSON_ChannelInfo
                              Failed: JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.10.208 /ISAPI/System/Video/inputs/channels/<ID>/capabilities
Get the configuration capability of a video input channel.

Request URL Definition
            Table 15-636 GET /ISAPI/System/Video/inputs/channels/<ID>/capabilities
Method                        GET
Description                   Get the configuration capability of a video input channel.
Query                         None.
Request                       None.
Response                      Succeeded: XML_Cap_VideoInputChannel
                              Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to video input channel ID.

15.10.209 /ISAPI/System/Video/inputs/channels/<ID>/iris
Manually adjust the iris of a specific video input channel.

Request URL Definition
                Table 15-637 PUT /ISAPI/System/Video/inputs/channels/<ID>/iris
Method                       PUT
Description                  Manually adjust the iris of a specific video input channel.
Query                        None.
Request                      XML_IrisData
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to video input channel ID.

15.10.210 /ISAPI/System/Video/inputs/channels/<ID>/overlays
Operations about OSD configuration of a specific video input channel.

Request URL Definition
              Table 15-638 GET /ISAPI/System/Video/inputs/channels/<ID>/overlays
Method                       GET
Description                  Get OSD configuration parameters of a specific video input channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_VideoOverlay
                             Failed: XML_ResponseStatus
              Table 15-639 PUT /ISAPI/System/Video/inputs/channels/<ID>/overlays
Method                       PUT
Description                  Set OSD parameters of a specific video input channel.
Query                        None.
Request                      XML_VideoOverlay
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the video input channel ID.

Example
Sample Code for Getting OSD Parameters
GET /ISAPI/System/Video/inputs/channels/1/overlays HTTP/1.1
Host: 10.17.132.49
Connection: Keep-Alive
Authorization: Digest username="admin",
realm="DS-2CD2F12FWD-IWS",
nonce="4d3046464f454e425254633659325534595749784f546b3d",
uri="/ISAPI/System/Video/inputs/channels/1/overlays",
cnonce="03e455047789a833deaae75e44381653",
nc=00000017,
response="ae141a01b415c1b9ab50ddea7ff467c3",
qop="auth"

HTTP/1.1 200 OK
Date: Tue, 14 Mar 2017 20:38:40 GMT
Server: App-webs/
Connection: close
Content-Length: 1087
Content-Type: application/xml

<?xml version="1.0" encoding="UTF-8"?>
<VideoOverlay version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <normalizedScreenSize>
  <normalizedScreenWidth>704</normalizedScreenWidth>
  <normalizedScreenHeight>576</normalizedScreenHeight>
 </normalizedScreenSize>
 <attribute>
  <transparent>false</transparent>
  <flashing>false</flashing>
 </attribute>
 <fontSize>64*64</fontSize>
 <TextOverlayList size="1">
  <TextOverlay>
   <id>1</id>
   <enabled>true</enabled>
   <positionX>0</positionX>
   <positionY>576</positionY>
   <displayText>222</displayText>
  </TextOverlay>
 </TextOverlayList>
 <DateTimeOverlay>
  <enabled>true</enabled>
  <positionX>0</positionX>
  <positionY>544</positionY>
  <dateStyle>MM-DD-YYYY</dateStyle>
  <timeStyle>24hour</timeStyle>
  <displayWeek>true</displayWeek>
 </DateTimeOverlay>
 <channelNameOverlay version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
  <enabled>true</enabled>

  <positionX>512</positionX>
  <positionY>64</positionY>
 </channelNameOverlay>
 <frontColorMode>auto</frontColorMode>
 <frontColor>000000</frontColor>
</VideoOverlay>

15.10.211 /ISAPI/System/Video/inputs/channels/<ID>/overlays/
BatteryPowerOverlay
Operations about the battery overlay configuration of a specific video input channel.

Request URL Definition
 Table 15-640 GET /ISAPI/System/Video/inputs/channels/<ID>/overlays/BatteryPowerOverlay
Method                        GET
Description                   Get the battery overlay parameters of a specific video input channel.
Query                         None.
Request                       None.
Response                      Succeeded: XML_BatteryPowerOverlay
                              Failed: XML_ResponseStatus
 Table 15-641 PUT /ISAPI/System/Video/inputs/channels/<ID>/overlays/BatteryPowerOverlay
Method                        PUT
Description                   Set the battery overlay parameters of a specific video input channel.
Query                         None.
Request                       XML_BatteryPowerOverlay
Response                      XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the video input channel No.

15.10.212 /ISAPI/System/Video/inputs/channels/<ID>/overlays/
BatteryPowerOverlay/capabilities
Get the configuration capability of battery overlay of a specific video input channel.

Request URL Definition
 Table 15-642 GET /ISAPI/System/Video/inputs/channels/<ID>/overlays/BatteryPowerOverlay/
                                        capabilities
Method                       GET
Description                  Get the configuration capability of battery overlay of a specific video
                             input channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_BatteryPowerOverlay
                             Failed: XML_ResponseStatus

15.10.213 /ISAPI/System/Video/inputs/channels/<ID>/overlays/capabilities
Get the OSD capability of a specific video input channel.

Request URL Definition
        Table 15-643 GET /ISAPI/System/Video/inputs/channels/<ID>/overlays/capabilities
Method                       GET
Description                  Get the OSD capability of a specific video input channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_VideoOverlay
                             Failed: XML_ResponseStatus

15.10.214 /ISAPI/System/Video/inputs/channels/<ID>/overlays/
channelNameOverlay
Operations about the configuration of channel name overlay of a specific video input channel.

Request URL Definition
 Table 15-644 GET /ISAPI/System/Video/inputs/channels/<ID>/overlays/channelNameOverlay
Method                       GET
Description                  Get the parameters of channel name overlay of a specific video input
                             channel.

Query                        None.
Request                      None.
Response                     Succeeded: XML_channelNameOverlay
                             Failed: XML_ResponseStatus
 Table 15-645 PUT /ISAPI/System/Video/inputs/channels/<ID>/overlays/channelNameOverlay
Method                       PUT
Description                  Set the parameters of channel name overlay of a specific video input
                             channel.
Query                        None.
Request                      XML_channelNameOverlay
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the video input channel No.

15.10.215 /ISAPI/System/Video/inputs/channels/<ID>/overlays/dateTimeOverlay
Operations about the configuration of date and time information overlay of a specific video input
channel.

Request URL Definition
    Table 15-646 GET /ISAPI/System/Video/inputs/channels/<ID>/overlays/dateTimeOverlay
Method                       GET
Description                  Get the parameters of date and time information overlay of a specific
                             video input channel.
Query                        None.
Request                      None.
Response                     Succeeded:
                             Failed: XML_ResponseStatus
   Table 15-647 PUT /ISAPI/System/Video/inputs/channels/<ID>/overlays/dateTimeOverlay
Method                       PUT
Description                  Set the parameters of date and time information overlay of a specific
                             video input channel.
Query                        None.

Request
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the video input channel No.

15.10.216 /ISAPI/System/Video/inputs/channels/<ID>/overlays/dateTimeOverlay/
capabilities
Get the capability of date and time information overlay of a specific video input channel.

Request URL Definition
   Table 15-648 GET /ISAPI/System/Video/inputs/channels/<ID>/overlays/dateTimeOverlay/
                                       capabilities
Method                       GET
Description                  Get the capability of date and time information overlay of a specific
                             video input channel.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_DatetimeOverlay
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the video input channel No.

15.10.217 /ISAPI/System/Video/inputs/channels/<ID>/overlays/text
Operations about the text overlay configuration of a specific video input channel.

Request URL Definition
           Table 15-649 GET /ISAPI/System/Video/inputs/channels/<ID>/overlays/text
Method                       GET
Description                  Get the text overlay parameters of a specific video input channel.
Query                        None.

Request                      None.
Response                     Succeeded: XML_TextOverlayList
                             Failed: XML_ResponseStatus
           Table 15-650 PUT /ISAPI/System/Video/inputs/channels/<ID>/overlays/text
Method                       PUT
Description                  Set the text overlay parameters of a specific video input channel.
Query                        None.
Request                      XML_TextOverlayList
Response                     XML_ResponseStatus
          Table 15-651 POST /ISAPI/System/Video/inputs/channels/<ID>/overlays/text
Method                       POST
Description                  Add a text to overlay on the video for a specific video input channel.
Query                        None.
Request                      XML_TextOverlay
Response                     XML_ResponseStatus
          Table 15-652 DELETE /ISAPI/System/Video/inputs/channels/<ID>/overlays/text
Method                       DELETE
Description                  Delete the text overlay parameters of a specific video input channel.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

15.10.218 /ISAPI/System/Video/inputs/channels/<ID>/overlays/text/<ID>
Operations about the configuration of a specific piece of text overlay information of a specific
video input channel.

Request URL Definition
        Table 15-653 GET /ISAPI/System/Video/inputs/channels/<ID>/overlays/text/<ID>
Method                       GET
Description                  Get the parameters of a specific piece of text overlay information of a
                             specific video input channel.

Query                       None.
Request                     None.
Response                    Succeeded: XML_TextOverlay
                            Failed: XML_ResponseStatus
        Table 15-654 PUT /ISAPI/System/Video/inputs/channels/<ID>/overlays/text/<ID>
Method                      PUT
Description                 Set the parameters of a specific piece of text overlay information of a
                            specific video input channel.
Query                       None.
Request                     XML_TextOverlay
Response                    XML_ResponseStatus
      Table 15-655 DELETE /ISAPI/System/Video/inputs/channels/<ID>/overlays/text/<ID>
Method                      DELETE
Description                 Delete the parameters of a specific piece of text overlay information
                            of a specific video input channel.
Query                       None.
Request                     None.
Response                    XML_ResponseStatus

15.10.219 /ISAPI/System/Video/inputs/channels/<ID>/privacyMask
Get or set privacy mask parameters.

Request URL Definition
           Table 15-656 GET /ISAPI/System/Video/inputs/channels/<ID>/privacyMask
Method                      GET
Description                 Get or set privacy mask parameters.
Query                       None.
Request                     None.
Response                    Succeeded: XML_PrivacyMask
                            Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the video input channel ID.

15.10.220 /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/
privacyMaskCap
Get configuration capability of privacy mask.

Request URL Definition
  Table 15-657 GET /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/privacyMaskCap
Method                       GET
Description                  Get configuration capability of privacy mask.
Query                        None.
Request                      None.
Response                     Succeeded: XML_PrivacyMaskCap
                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the video input channel ID.

15.10.221 /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/regions
Get, set, or delete parameters of privacy mask regions, and add a region.

Request URL Definition
      Table 15-658 GET /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/regions
Method                       GET
Description                  Get parameters of privacy mask regions.
Query                        None.
Request                      None.
Response                     Succeeded: XML_PrivacyMaskRegionList
                             Failed: XML_ResponseStatus

      Table 15-659 PUT /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/regions
Method                       PUT
Description                  Set parameters of privacy mask regions.
Query                        None.
Request                      XML_PrivacyMaskRegionList
Response                     XML_ResponseStatus
     Table 15-660 DELETE /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/regions
Method                       DELETE
Description                  Delete parameters of privacy mask regions.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus
      Table 15-661 POST /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/regions
Method                       POST
Description                  Add a privacy mask region.
Query                        None.
Request                      XML_PrivacyMaskRegion
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the video input channel ID.

15.10.222 /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/regions/<ID>
Get, set, or delete parameters of a privacy mask region.

Request URL Definition
   Table 15-662 GET /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/regions/<ID>
Method                       GET
Description                  Get parameters of a privacy mask region.
Query                        None.

Request                      None.
Response                     Succeeded: XML_PrivacyMaskRegion
                             Failed: XML_ResponseStatus
   Table 15-663 PUT /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/regions/<ID>
Method                       PUT
Description                  Set parameters of a privacy mask region.
Query                        None.
Request                      XML_PrivacyMaskRegion
Response                     XML_ResponseStatus
  Table 15-664 DELETE /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/regions/<ID>
Method                       DELETE
Description                  Delete parameters of a privacy mask region.
Query                        None.
Request                      None.
Response                     XML_ResponseStatus

Remarks
The first <ID> in the request URL refers to the video input channel ID; and second <ID> is the
privacy mask region ID.

15.10.223 /ISAPI/System/Video/inputs/channels/<ID>/VCAResource
Operation about configuration of intelligent resources switch.

Request URL Definition
           Table 15-665 GET /ISAPI/System/Video/inputs/channels/<ID>/VCAResource
Method                       GET
Description                  Get parameters of intelligent resources switch.
Query                        None.
Request                      None.
Response                     Succeeded: XML_VCAResource
                             Failed: XML_ResponseStatus

           Table 15-666 PUT /ISAPI/System/Video/inputs/channels/<ID>/VCAResource
Method                        PUT
Description                   Set parameters of intelligent resources switch.
Query                         None.
Request                       XML_VCAResource
Response                      XML_ResponseStatus

Remarks
• The <ID> in the request URL refers to the video input channel ID.
• The intelligent resources switch supports three capture mode, i.e., target capture, face capture,
  and perimeter capture.
  • For target capture mode, the panoramic camera captures the human body and vehicle
    pictures, the speed dome tracks and capture the human body for human body or face
    recognition and comparison. If matched, the thumbnails and original pictures of human body
    and face will be uploaded; otherwise, only the thumbnail and original picture of face will be
    uploaded.
  • For face capture mode, the panoramic camera transmits the videos without any intelligent
    analysis, the speed dome captures face picture in up to 4 scenes.
  • For perimeter capture, the panoramic camera captures vehicle pictures and performs HMS
    +DGS detection, and it supports detecting and tracking the small target within 40 m; while the
    speed dome tracks and captures the detected target, and outputs thumbnails and original
    pictures of human body and face.

15.10.224 /ISAPI/System/Video/inputs/channels/<ID>/VCAResource/capabilities
Get capability of intelligent resources switch.

Request URL Definition
    Table 15-667 GET /ISAPI/System/Video/inputs/channels/<ID>/VCAResource/capabilities
Method                        GET
Description                   Get capability of intelligent resources switch.
Query                         None.
Request                       None.
Response                      Succeeded: XML_Cap_VCAResource
                              Failed: XML_ResponseStatus

15.10.225 /ISAPI/System/Video/inputs/channels/counting/collection/capabilities?
format=json
Get the capability of people counting data replenishment.

Request URL Definition
   Table 15-668 GET /ISAPI/System/Video/inputs/channels/counting/collection/capabilities?
                                       format=json
Method                      GET
Description                 Get the capability of people counting data replenishment.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    JSON_PeopleCounting_CollectionDescriptionCap

15.10.226 /ISAPI/System/Video/inputs/channels/counting/collection?format=json
Perform people counting replenishment.

Request URL Definition
  Table 15-669 POST /ISAPI/System/Video/inputs/channels/counting/collection?format=json
Method                      POST
Description                 Perform people counting replenishment.
Query                       format: determine the format of request or response message.
Request                     JSON_PeopleCounting_CollectionDescription
Response                    JSON_PeopleCounting_CollectionResult

15.10.227 /ISAPI/System/Video/inputs/channels/heatMap/collection/capabilities?
format=json
Get the capability of heat map data replenishment.

Request URL Definition
   Table 15-670 GET /ISAPI/System/Video/inputs/channels/heatMap/collection/capabilities?
                                       format=json
Method                     GET
Description                Get the capability of heat map data replenishment.
Query                      format: determine the format of request or response message.
Request                    None.
Response                   JSON_HeatMap_CollectionDescriptionCap

15.10.228 /ISAPI/System/Video/inputs/channels/heatMap/collection?format=json
Perform heat map data replenishment.

Request URL Definition
  Table 15-671 POST /ISAPI/System/Video/inputs/channels/heatMap/collection?format=json
Method                     POST
Description                Perform heat map data replenishment.
Query                      format: determine the format of request or response message.
Request                    JSON_HeatMap_CollectionDescription
Response                   JSON_HeatMap_CollectionResult

15.10.229 /ISAPI/System/Video/inputs/OSDLanguage
Operations about OSD language configuration.

Request URL Definition
                 Table 15-672 GET /ISAPI/System/Video/inputs/OSDLanguag
Method                     GET
Description                Get OSD language parameters.
Query                      None.
Request                    None.
Response                   XML_Language

                  Table 15-673 PUT /ISAPI/System/Video/inputs/OSDLanguag
Method                      PUT
Description                 Set OSD language parameters.
Query                       None.
Request                     XML_Language
Response                    XML_ResponseStatus

15.10.230 /ISAPI/System/Video/outputs
Get configuration parameters of video outputs.

Request URL Definition
                        Table 15-674 GET /ISAPI/System/Video/outputs
Method                      GET
Description                 Get configuration parameters of all video outputs.
Query                       None.
Request                     None.
Response                    Succeeded: XML_VideoOutput
                            Failed: XML_ResponseStatus

15.10.231 /ISAPI/System/Video/outputs/channels
Get configuration parameters of multiple video outputs.

Request URL Definition
                   Table 15-675 GET /ISAPI/System/Video/outputs/channels
Method                      GET
Description                 Get configuration parameters of multiple video outputs.
Query                       None.
Request                     None.
Response                    Succeeded: XML_VideoOutputChannelList
                            Failed: XML_ResponseStatus

15.10.232 /ISAPI/System/Video/outputs/channels/<ID>
Get or set parameters of a video output.

Request URL Definition
                 Table 15-676 GET /ISAPI/System/Video/outputs/channels/<ID>
Method                       GET
Description                  Get parameters of a video output.
Query                        None.
Request                      None.
Response                     Succeeded: XML_VideoOutputChannel
                             Failed: XML_ResponseStatus
                 Table 15-677 PUT /ISAPI/System/Video/outputs/channels/<ID>
Method                       PUT
Description                  Set parameters of a video output.
Query                        None.
Request                      XML_VideoOutputChannel
Response                     XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the video output ID.

15.10.233 /ISAPI/System/Video/outputs/channels/<ID>/capabilities
Get video output configuration capability.

Request URL Definition
           Table 15-678 GET /ISAPI/System/Video/outputs/channels/<ID>/capabilities
Method                       GET
Description                  Get video output configuration capability.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_VideoOutputChannel

                             Failed: XML_ResponseStatus

Remarks
The <ID> in the request URL refers to the video output ID.

15.10.234 /ISAPI/System/Video/outputs/PreviewSwitch/capabilities
Get capability of auto-switch configuration during live view.

Request URL Definition
           Table 15-679 GET /ISAPI/System/Video/outputs/PreviewSwitch/capabilities
Method                       GET
Description                  Get capability of auto-switch configuration during live view.
Query                        None.
Request                      None.
Response                     Succeeded: XML_Cap_PreviewSwitch
                             Failed: XML_ResponseStatus

15.10.235 /ISAPI/System/Video/outputs/PreviewSwitch/capabilities?
videoOutType=
Get capability of auto-switch configuration during live view by video output.

Request URL Definition
  Table 15-680 GET /ISAPI/System/Video/outputs/PreviewSwitch/capabilities?videoOutType=
Method                       GET
Description                  Get capability of auto-switch configuration during live view by video
                             output.
Query                        videoOutType: video output type, string type, it can be the following
                             values: CVBS, HDMI, VGA, AUXOutput1, AUXOutput2, AUXOutput3,
                             AUXOutput4, extendHDMI1, extendHDMI2, extendHDMI3,
                             extendHDMI4, noSameSourceVGA1, noSameSourceVGA2,
                             noSameSourceVGA3, noSameSourceVGA4, sameSourceVGA,
                             mainLCD, AUX-VGA, AUX-LCD, and zeroChannel. If there are more
                             than two outputs are homologous, you can combine these outputs
                             by "/", e.g., if HDM1 and VGA1 are homologous outputs, the value of
                             videoOutType equals to HDM1/VGA1.

Request                      None.
Response                     Succeeded: XML_PreviewSwitchVideoOutCap
                             Failed: XML_ResponseStatus

15.10.236 /ISAPI/System/Video/outputs/PreviewSwitch?
groupID=&videoOutType=
Operations about auto-switch configuration in live view.

Request URL Definition
   Table 15-681 GET /ISAPI/System/Video/outputs/PreviewSwitch?groupID=&videoOutType=
Method                       GET
Description                  Get configuration parameters of auto-switch in live view.
Query                        groupNo: group No., integer type, which is used to group the
                             windows for configuration, and up to 64 windows can be added to a
                             group.
                             videoOutType: video output type, string type, it can be the following
                             values: CVBS, HDMI, VGA, AUXOutput1, AUXOutput2, AUXOutput3,
                             AUXOutput4, extendHDMI1, extendHDMI2, extendHDMI3,
                             extendHDMI4, noSameSourceVGA1, noSameSourceVGA2,
                             noSameSourceVGA3, noSameSourceVGA4, sameSourceVGA,
                             mainLCD, AUX-VGA, AUX-LCD, and zeroChannel. If there are more
                             than two outputs are homologous, you can combine these outputs
                             by "/", e.g., if HDM1 and VGA1 are homologous outputs, the value of
                             videoOutType equals to HDM1/VGA1.
Request                      None.
Response                     Succeeded: XML_PreviewSwitch
                             Failed: XML_ResponseStatus
   Table 15-682 PUT /ISAPI/System/Video/outputs/PreviewSwitch?groupID=&videoOutType=
Method                       PUT
Description                  Set parameters for auto-switch in live view.
Query                        groupNo: group No., integer type, which is used to group the
                             windows for configuration, and up to 64 windows can be added to a
                             group.
                             videoOutType: video output type, string type, it can be the following
                             values: CVBS, HDMI, VGA, AUXOutput1, AUXOutput2, AUXOutput3,

                             AUXOutput4, extendHDMI1, extendHDMI2, extendHDMI3,
                             extendHDMI4, noSameSourceVGA1, noSameSourceVGA2,
                             noSameSourceVGA3, noSameSourceVGA4, sameSourceVGA,
                             mainLCD, AUX-VGA, AUX-LCD, and zeroChannel. If there are more
                             than two outputs are homologous, you can combine these outputs
                             by "/", e.g., if HDM1 and VGA1 are homologous outputs, the value of
                             videoOutType equals to HDM1/VGA1.
Request                      XML_PreviewSwitch
Response                     XML_ResponseStatus

15.10.237 /ISAPI/System/Video/outputs/PreviewSwitch?
groupID=&videoOutType=&previewFrameNo=
Get configuration parameters of auto-switch in live view.

Request URL Definition
                Table 15-683 GET /ISAPI/System/Video/outputs/PreviewSwitch?
                         groupID=&videoOutType=&previewFrameNo=
Method                       GET
Description                  Get configuration parameters of auto-switch in live view.
Query                        groupNo: group No., integer type, which is used to group the
                             windows for configuration, and up to 64 windows can be added to a
                             group.
                             videoOutType: video output type, string type, it can be the following
                             values: CVBS, HDMI, VGA, AUXOutput1, AUXOutput2, AUXOutput3,
                             AUXOutput4, extendHDMI1, extendHDMI2, extendHDMI3,
                             extendHDMI4, noSameSourceVGA1, noSameSourceVGA2,
                             noSameSourceVGA3, noSameSourceVGA4, sameSourceVGA,
                             mainLCD, AUX-VGA, AUX-LCD, and zeroChannel. If there are more
                             than two outputs are homologous, you can combine these outputs
                             by "/", e.g., if HDM1 and VGA1 are homologous outputs, the value of
                             videoOutType equals to HDM1/VGA1.
                             (Optional) previewFrameNo: number of live view windows, integer
                             string type, and it can be the following values: 1, 4, 6, 8, 9, 25, 32, 36,
                             auto1 (custom window division 1), auto2 (custom window division 2),
                             auto3 (custom window division 3), and auto4 (custom window
                             division 4).

Request                     None.
Response                    Succeeded: XML_PreviewSwitch
                            Failed: XML_ResponseStatus

15.10.238 /ISAPI/System/workingstatus/hdStatus?format=json
Get HDD status.

Request URL Definition
              Table 15-684 GET /ISAPI/System/workingstatus/hdStatus?format=json
Method                      GET
Description                 Get all HDDs' status.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    Succeeded: JSON_HDStatus
                            Failed: JSON_ResponseStatus
              Table 15-685 POST /ISAPI/System/workingstatus/hdStatus?format=json
Method                      POST
Description                 Get a specified HDD's status.
Query                       format: determine the format of request or response message.
Request                     JSON_HDCond
Response                    Succeeded: JSON_HDStatus
                            Failed: JSON_ResponseStatus

15.10.239 /ISAPI/System/workingstatus/chanStatus?format=json
Get channel status.

Request URL Definition
              Table 15-686 GET /ISAPI/System/workingstatus/chanStatus?format=json
Method                      GET
Description                 Get all channels' status.
Query                       format: determine the format of request or response message.

Request                        None.
Response                       Succeeded: JSON_ChanStatus
                               Failed: JSON_ResponseStatus
            Table 15-687 POST /ISAPI/System/workingstatus/chanStatus?format=json
Method                         POST
Description                    Get a specified channel's status.
Query                          format: determine the format of request or response message.
Request                        JSON_ChanCond
Response                       Succeeded: JSON_ChanStatus
                               Failed: JSON_ResponseStatus

15.10.240 /ISAPI/System/workingstatus/capabilities?format=json
Get capability of getting all statuses of device.

Request URL Definition
             Table 15-688 GET /ISAPI/System/workingstatus/capabilities?format=json
Method                         GET
Description                    Get capability of getting all statuses of device.
Query                          format: determine the format of request or response message.
Request                        None.
Response                       Succeeded: JSON_Cap_WorkingStatus
                               Failed: JSON_ResponseStatus

15.10.241 /ISAPI/System/workingstatus?format=json
Get device working status.

Request URL Definition
                   Table 15-689 GET /ISAPI/System/workingstatus?format=json
Method                         GET
Description                    Get device working status.
Query                          format: determine the format of request or response message.

Request                      None.
Response                     Succeeded: JSON_WorkingStatus
                             Failed: JSON_ResponseStatus

Remarks
Up to 20 bytes are allowed for a device's working status; up to 100 bytes are allowed for a
channel's status, a HDD's status, and an IO's status; up to 30 bytes are allowed for a two-way audio
channel's status.

15.10.242 /ISAPI/System/workingstatus/IOStatus?format=json
Get device IO status.

Request URL Definition
              Table 15-690 GET /ISAPI/System/workingstatus/IOStatus?format=json
Method                       GET
Description                  Get device IO status.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     Succeeded: JSON_IOStatus
                             Failed: JSON_ResponseStatus

15.10.243 /ISAPI/System/zeroBiasCalibration/channels/<ID>?format=json
Calibrate the accelerometer bias.

Request URL Definition
        Table 15-691 PUT /ISAPI/System/zeroBiasCalibration/channels/<ID>?format=json
Method                       PUT
Description                  Calibrate the accelerometer bias.
Query                        format: determine the format of request or response message.
Request                      None.
Response                     JSON_ResponseStatus

Remarks
The <ID> in the request URL refers to the channel No.

15.11 /ISAPI/Thermal

15.11.1 /ISAPI/Thermal/capabilities
Get thermal capability.

Request URL Definition
                          Table 15-692 GET /ISAPI/Thermal/capabilities
Method                            GET
Description                       Get the thermal capability.
Query                             None.
Request                           None.
Response                          XML_ThermalCap

15.11.2 /ISAPI/Thermal/temperature/collection/capabilities?format=json
Get the capability of temperature data replenishment.

Request URL Definition
        Table 15-693 GET /ISAPI/Thermal/temperature/collection/capabilities?format=json
Method                      GET
Description                 Get the capability of temperature data replenishment.
Query                       format: determine the format of request or response message.
Request                     None.
Response                    JSON_Temperature_CollectionDescriptionCap

15.11.3 /ISAPI/Thermal/temperature/collection?format=json
Perform the temperature data replenishment.

Request URL Definition
              Table 15-694 GET /ISAPI/Thermal/temperature/collection?format=json
Method                      POST
Description                 Perform the temperature data replenishment.
Query                       format: determine the format of request or response message.
Request                     JSON_CollectionDescription
Response                    JSON_CollectionResult
