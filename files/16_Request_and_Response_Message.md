# Chapter 16 Request and Response Message

The request and response messages in XML or JSON format of each request URL are listed here for
reference. You can search for the parameters by the message name.

16.1 JSON Messages

16.1.1 JSON_Adaption
Adaption message in JSON format
{
  "Adaption": {
    "enable": ,
/*required, boolean type, whether to enable network self-adaptive function: true-no, false-yes; this function is bound
with IntraRefresh encoding strategy*/
    "policy": ,
/*required,self-adaptive strategy, 0-self-adaptive (adjust the resolution and bit rate, the resolution value should be
smaller than or equal to the configured value, but the frame rate is constant), 1-resolution in priority (adjust bit rate,
resolution and frame rate are constant), 2-error correction and retransmission (resolution and frame rate are
constant)*/
    "percentage":
/*this node is required when policy is "2", error correction percentage, unit: %, which is between 0 and 100; lager
percentage represents more corrected data, more higher requirement for bandwidth, and better effect*/
  }
}

16.1.2 JSON_AdaptionCap
AdaptionCap message in JSON format
{
 "AdaptionCap": {
  "enable": "true,false",
/*required, boolean type, whether to enable network self-adaptive function: true-no, false-yes; this function is bound
with IntraRefresh encoding strategy*/
  "policy": {
/*required,self-adaptive strategy, 0-self-adaptive (adjust the resolution and bit rate, the resolution value should be
smaller than or equal to the configured value, but the frame rate is constant), 1-resolution in priority (adjust bit rate,
resolution and frame rate are constant), 2-error correction and retransmission (resolution and frame rate are
constant)*/
    "@opt": "0,1,2"
  },
  "percentage": {
/*this node is required when policy is "2", error correction percentage, unit: %, which is between 0 and 100; lager

percentage represents more corrected data, more higher requirement for bandwidth, and better effect*/
      "@min": 0,
      "@max": 100,
    }
  }
}

16.1.3 JSON_AlarmStatistics
AlarmStatistics message in JSON format
{
  "AlarmStatistics":{
/*optional, alarm statistics of added IoT devices*/
    "totalNumber": "",
/*required, the total number of alarms, integer*/
    "time": "",
/*required, statistic time, integer, unit: second*/
  }
}

16.1.4 JSON_AssociatedChannelList
AssociatedChannelList message in JSON format
{
  "AssociatedChannelList": [{
/*optional, list of linked channels*/
   "channel": "",
/*required, channel No., integer*/
   "type": "",
/*required, channel type: "video"-video channel, "IOT"-IoT channel, string*/
   "associatedVideoChannels": "",
/*optional, linked video channel No., array, and the unit is integer*/
   "associatedIOTChannels": ""
/*optional, linked IoT channel No., array, and the unit is integer*/
  }]
}

16.1.5 JSON_AudioAlarm
AudioAlarm message in JSON format
{
 "AudioAlarm":{
  "audioID": ,
/*required, alarm sound types, 1-siren, 2-"Warning, this is a restricted area", 3-"Waring, this is a restricted area，

please keep away", 4-"Warning, this is a no-parking zone", 5-"Warning, this is a no-parking zone, please keep away",
6-"Attention please. The area is under surveillance", 7-"Welcome，Please notice that the area is under surveillance",
8-"Welcome", 9-"Danger! Please keep away", 10-siren + "Danger, please keep away", 11-Audio Warning, 12-Beep
Sound, 13-"Temperature abnormality, please deal with it as soon as possible", 14-"Smoking is prohibited in this area",
15-"Fire detected, please deal with it as soon as possible"*/
    "audioVolume": ,
/*required, integer type, volume, which is between 1 ad 100*/
    "alarmTimes": ,
/*required, integer type, times of alarm, which is between 1 and 50*/
    "TimeRangeList":[{
/*optional, alarm output schedule list*/
     "week": ,
     "TimeRange":[{
       "id": ,
/*required, integer type, ID of time period for each day*/
       "beginTime":"",
/*required, string type, start time in ISO8601 format*/
       "endTime":""
/*required, string type, end time in ISO8601 format*/
     }]
    }]
    "alarmType": "",
/*optional, string type, alarm type: "behavior"-behavior analysis, "thermometry"-thermometry, "dynamicFire"-fire
detection, "smokingMode"-smoke detection*/
  }
}

16.1.6 JSON_AudioAlarmCap
AudioAlarmCap message in JSON format
{
 "AudioAlarmCap":{
  "audioTypeListCap":[{
/*required, alarm sound types, 1-siren, 2-"Warning, this is a restricted area", 3-"Waring, this is a restricted area，
please keep away", 4-"Warning, this is a no-parking zone", 5-"Warning, this is a no-parking zone, please keep away",
6-"Attention please. The area is under surveillance", 7-"Welcome，Please notice that the area is under surveillance",
8-"Welcome", 9-"Danger! Please keep away", 10-siren + "Danger, please keep away", 11-Audio Warning, 12-Beep
Sound, 13-"Temperature abnormality, please deal with it as soon as possible", 14-"Smoking is prohibited in this area",
15-"Fire detected, please deal with it as soon as possible"*/
    "audioID": ,
    "audioDescription":""
  },
  {
    "audioID": ,
    "audioDescription":""
  },
  {
    "audioID": ,
    "audioDescription":""
  }],

  "audioVolume":{
/*required, integer type, volume, which is between 1 ad 100*/
    "@min": ,
    "@max": ,
    "@def":
  },
  "alarmTimes":{
/*required, integer type, times of alarm, which is between 1 and 50*/
    "@min": ,
    "@max": ,
    "@def":
  },
  "TimeRangeCap":{
/*optional, alarm output schedule list capability*/
    "week":{
/*required, integer type, days of the week: 1-Monday, 2-Tuesday, 3-Wednesday, 4-Thursday, 5-Friday,6-Saturday, 7-
Sunday*/
      "@opt":""
    },
    "id":{
/*required, integer type, ID of time period for each day*/
      "@maxSize":
    },
    "beginTime":{
/*required, string type, start time in ISO8601 format*/
      "@min":"",
      "@max":""
    },
    "endTime":{
/*required, string type, end time in ISO8601 format*/
      "@min":"",
      "@max":""
    }
  }
  "alarmType":{
/*optional, string type, alarm type: "behavior"-behavior analysis, "thermometry"-thermometry, "dynamicFire"-fire
detection, "smokingMode"-smoke detection*/
    "@opt":"behavior,thermometry,dynamicFire,smokingMode",
    "@def":"thermometry"
  }
  "AlarmBindAudioList":[{
/*optional, alarm type and the list of audio related to alarm type*/
    "alarmType":"behavior",
/*optional, string, alarm type: "behavior"-behavior analysis, "thermometry"-thermometry, "dynamicFire"-fire
detection, "smokingMode"-smoke detection*/
    "audioID":{
/*optional, string, the audible warning type ID corresponding to alarm type, behavior analysis corresponds to 1-12,
thermometry corresponds to 13，fire detection corresponds to 14，smoke detection corresponds to 15*/
      "@opt":"1,2,3,4,5,6,7,8,9,10,11,12,13,14,15"
    }
  }]

    }
}

16.1.7 JSON_AutoEagleFocusing
AutoEagleFocusing message in JSON format
{
  "AutoEagleFocusing": {
/*required, auto calibration of rapid focus*/
    "EagleFocusingRegion": [{
/*optional, string, rapid focus region*/
     "sid": "",
/*optional, string, scene ID*/
     "spotNum": ,
/*optional, integer, the number of calibration points*/
     "type": "",
/*optional, string, region type now only supports "line"*/
     "Region": [{
/*optional, region list*/
       "x": ,
       "y":
     }],
     "AbsoluteHigh": {
/*optional, PTZ position*/
       "elevation": ,
/*optional, xs:integer, tilt angle, range: [-900,2700]*/
       "azimuth": ,
/*optional, xs:integer, azimuth, range: [0,3600]*/
       "absoluteZoom": 33
/*optional, xs:integer, zoom, range: [1,1000]*/
     }
    }]
  }
}

16.1.8 JSON_AutoEagleFocusingCap
AutoEagleFocusingCap message in JSON format
{
 "AutoEagleFocusingCap": {
/*required, auto calibration capability of rapid focus*/
  "EagleFocusingRegion": {
   "sid": {
/*optional, string, scene ID*/
     "@min": 1,
     "@max": 2
   },

      "spotNum": {
/*optional, integer, the number of calibration points*/
        "@min": 1,
        "@max": 64
      },
      "type": {
/*optional, string, region type now only supports "line"*/
        "@opt": "line"
      },
      "RegionCap": {
        "minSize": 3,
/*required, integer, the minimum number of region edges*/
        "maxSize": 10,
/*required, integer, the maximum number of region edges*/
        "x": {
/*required, float, X-coordinate, value range: 0.000 to 1*/
          "@min": 0.000,
          "@max": 1.000,
          "#text": 0.120
        },
        "y": {
/*required, float, Y-coordinate, value range: 0.000 to 1*/
          "@min": 0.000,
          "@max": 1.000,
          "#text": 0.120
        }
      },
      "AbsoluteHighCap": {
        "elevation": {
/*optional, xs:integer, tilt angle, range: [-900,2700]*/
          "@min": -900,
          "@max": 2700
        },
        "azimuth": {
/*optional, xs:integer, azimuth, range: [0,3600]*/
          "@min": 0,
          "@max": 3600
        },
        "absoluteZoom": {
/*optional, xs:integer, zoom, range: [1,1000]*/
          "@min": 1,
          "@max": 1000
        }
      }
    }
  }
}

16.1.9 JSON_AutoGotoCfg
AutoGotoCfg message in JSON format
{
  "AutoGotoCfg":{
    "enable": ,
/*optional, boolean type, whether to enable*/
    "autoRecoveryTime":
/*optional, integer type, automatically restored time after the PTZ control is disabled, unit: second*/
  }
}

16.1.10 JSON_AutoGotoCfgCap
AutoGotoCfgCap message in JSON format
{
  "AutoGotoCfgCap":{
    "enable":"true,false",
/*optional, whether to enable*/
    "autoRecoveryTime":{
/*optional, automatically restored time after the PTZ control is disabled, unit: second*/
      "@min": ,
      "@max":
    }
  }
}

16.1.11 JSON_AutoMaintenance
AutoMaintenance message in JSON format
{
  "AutoMaintenance":{
   "enabled": true,
/*required, boolean, enable or not*/
   "dayOfWeek": "",
/*required, integer, day of the week, ranges from 1 to 7, 1-Monday, 2-Tuesday, and so on*/
   "rebootTime": "",
/*required, reboot time, corrects to minute, it is 0 by default, ISO8601 format, string*/
   }
}

16.1.12 JSON_AutoMaintenanceCap
AutoMaintenanceCap message in JSON format
{
  "AutoMaintenanceCap":{
    "enabled": "true,false",
/*required, boolean, enable or not*/
    "dayOfWeek":{
/*required, integer, day of the week, ranges from 1 to 7, 1-Monday, 2-Tuesday, and so on*/
      "@min": 1,
      "@max": 7,
      "#text": 1
    },
  }
}

16.1.13 JSON_BasicParam
BasicParam message in JSON format
{
  "BasicParam":{
/*required, basic parameters of added IoT device*/
    "channelName": ""
/*required, channel name, string, the max. length is 32*/
  }
}

16.1.14 JSON_CalibrationStatus
CalibrationStatus message in JSON format
{
  "CalibrationStatus":{
/*required, string type, installation angle calibration status: "Calibrated"-calibrated, "Uncalibrated"-uncalibrated*/
  }
}

16.1.15 JSON_Cap_CalibrationStatus
CalibrationStatus message in JSON format
{
 "CalibrationStatus":{
/*required, string type, installation angle calibration status: "Calibrated"-calibrated, "Uncalibrated"-uncalibrated*/

        "@opt":"Calibrated,Uncalibrated"
    }
}

16.1.16 JSON_Cap_CertificateSelect
CertificateSelect capability message in JSON format
{
  "CertificateSelect":{
    "Function":[{
/*required, function list*/
      "functionName":"HTTPS",
/*required, function name, it should be set to one of the following values:
"HTTPS","WebSocketS","SDK_OVER_TLS","SRTP","securityLog","ieee802.1x"*/
      "certificateType":["client", "server", "CA"]
/*required, certificate type required by this function, it should be set to one or multiple values of the following
options: "client","server","CA"*/
    }],
    "clientCertificate":{
/*optional, optional client certificate types*/
      "@opt":["name1"]
    },
    "serverCertificate":{
/*optional, optional server certificate types*/
      "@opt":["name2"]
    },
    "CACertificate":{
/*optional, optional CA certificate types*/
      "@opt":["name3"]
    },
    "SRTPSecurityAlgorithm":{
/*optional, string, optional encryption algorithms*/
      "@opt":["AES128", "AES256"]
    }
  }
}

16.1.17 JSON_Cap_CommuMode
CommuMode capability message in JSON format
{
 "CommuMode":{
  "mode":{
/*required, string type, security mode level of the private protocol: "compatibilityMode"-compatibility mode,
"safeMode"-security mode*/
    "@opt":"compatibilityMode,safeMode"
  }

    }
}

16.1.18 JSON_Cap_ExportInfo
ExportInfo capability message in JSON format
{
  "ExportInfo":{
    "mediaType":{
/*required, string, exported data type: "video", "audio", "metadata", "text", "mixed", "other". It should be the same
as the search type. For pictures, this node should be set to "metadata"*/
      "@opt":["video", "audio", "metadata", "text", "mixed", "other"]
    },
    "playbackURIList":{
/*required, array, file path*/
      "@size":1
/*supported list size to be exported*/
    }
  }
}

16.1.19 JSON_Cap_IntelliManagement
IntelliManagement capability message in JSON format
{
 "requestURL":"",
 "statusCode": ,
 "statusString":"",
 "subStatusCode":"",
 "errorCode": ,
 "errorMsg":"",
/*see the description of this node and the above nodes in the message of JSON_ResponseStatus*/
 "isSuportTask": ,
/*optional, boolean type, whether to support task: "true"-yes, "false"-no*/
 "isSupportCtrlCenter": ,
/*optional, boolean type, whether to support control center: "true"-yes, "false"-no*/
 "isSuportIntelligentSearch": ,
/*optional, boolean type, whether to support intelligent search: "true"-yes, "false"-no*/
 "isSuportExecuteControl": ,
/*optional, boolean type, whether to support arming: "true"-yes, "false"-no*/
 "isSuportDataStatistics": ,
/*optional, boolean type, whether to support statistics: "true"-yes, "false"-no*/
 "isSupportIntelligentStorage": ,
/*optional, boolean type, whether to support intelligent storage: "true"-yes, "false"-no*/
 "isSupportServer": ,
/*optional, boolean type, whether to support service configuration: "true"-yes, "false"-no*/
 "isSuportAlgorithmModel": ,

/*optional, boolean type, whether to support algorithm model configuration: "true"-yes, "false"-no*/
  "isSupportCluster": ,
/*optional, boolean type, whether to support cluster: "true"-yes, "false"-no*/
  "isSupportSearchResultDisplay": ,
/*optional, boolean type, whether to support display configuration: "true"-yes, "false"-no*/
  "isSuportTranscodeAnalysisUnit": ,
/*optional, boolean type, whether to support transcoding analysis unit: "true"-yes, "false"-no*/
  "isSuportFactoryReset": ,
/*optional, boolean type, whether to support restoring to factory settings: "true"-yes, "false"-no*/
  "isSupportUPS": ,
/*optional, boolean type, whether to support UPS: "true"-yes, "false"-no*/
  "isSuportCity": ,
/*optional, boolean type, whether to support city: "true"-yes, "false"-no*/
  "isSuportClusterEnableStatus": ,
/*optional, boolean type, whether to support enabling cluster status: "true"-yes, "false"-no*/
  "isSupportSensitivity": ,
/*optional, boolean type, whether to support sensitivity configuration: "true"-yes, "false"-no*/
  "isSupportConfidence": ,
/*optional, boolean type, whether to support confidence configuration: "true"-yes, "false"-no*/
  "isSupportAudioFileUpload": ,
/*optional, boolean type, whether to support importing audio file: "true"-yes, "false"-no*/
  "isSupportIntelligentMode":
/*optional, boolean type, whether to support intelligent mode configuration: "true"-yes, "false"-no*/
}

See Also
JSON_ResponseStatus

16.1.20 JSON_Cap_POE
POE capability message in JSON format
{
  "POE": {
    "ipVersion": {
/*optional, supported IP address type, string type*/
      "@opt": "ipV4,ipV6",
      "#text": "ipV4"
    }
  }
}

16.1.21 JSON_Cap_ReportCenterCfg
ReportCenterCfg capability message in JSON format
{
    "ReportCenterCfg":{
     "CenterID":{

/*center group No.*/
      "@min": ,
      "@max":
    },
    "enable":"true,false",
/*optional, boolean type, whether to enable uploading report*/
    "ChanAlarmMode":{
/*alarm channel of the center group*/
      "maxSize":1,
      "id":{
/*optional, integer type, channel ID: 1-main channel, 2-backup channel 1, 3-backup channel 2, 4-backup channel 3*/
        "@min":1,
        "@max":2
      },
      "chanAlarmMode":{
/*optional, string type, alarm channel mode: "T1"-T1 channel, "T2"-T2 channel, "N1"-N1 channel, "N2"-N2 channel,
"G1"-G1 channel, "G2"-G2 channel, "N3"-N3 channel, "N4"-N4 channel*/
        "@opt":"T1,T2,N1,N2,G1,G2,N3,N4"
      }
    }
  }
}

16.1.22 JSON_Cap_WorkingStatus
WorkingStatus capability message in JSON format
{
 "WorkingStatusCap":{
  "devStatus":{
    "@opt": "0,1,2"
/*required, integer type, value of device status: 0-normal, 1-CPU usage, higher than 85%, 2-hardware error (e.g., serial
port exception)*/
  },
  "ChanStatus":{
    "chanNo": "",
/*required, integer type, channel No., which starts from 1*/
    "enable": "",
/*integer type, it is valid for analog channel only, 0-disable, 1-enable*/
    "online": "",
/*required, integer type, online status: 0-offline, 1-online*/
    "record":{
      "@opt": "0,1,2",
/*integer type, recording status: 0-recording, 1-recording exception (HDD exception), 2-recording exception (network
camera offline), 3-recording exception (other reason)*/
    },
    "signal": "",
/*required, integer type, signal status: 0-normal, 1-signal loss*/
    "linkNum": "",
/*required, integer type, number of software clients connected to this channel*/
    "bitRate": ""

/*required, integer type, channel bit rate, unit: Kpbs*/
    },
    "HDStatus":{
      "hdNo": "",
/*required, integer type, HDD No., which starts from 1*/
      "enable": "",
      "status":{
        "@opt": "0,1,2",
/*required, integer type, HDD status: 0-activate, 1-sleep, 2-exception, 3-sleepy HDD error, 4-unformated, 5-
disconnected (for network HDD), 6-formatting*/
      },
      "volume": "",
/*required, integer type, HDD capacity, unit: MB*/
      "linkNum": "",
/*integer type, *number of connections*/
      "freeSpace": "1"
/*required, integer type, free space, unit: MD*/
    }
  }
}

16.1.23 JSON_CertificateRevocation
CertificateRevocation message in JSON format
{
  "CertificateRevocation":{
    "enabled": ,
/*required, boolean, whether to enable certificate expiry alarm*/
    "expireAlarmTime": ,
/*required, integer, number of days to prompt in advance before the certificate is expired*/
    "detecteTime":"",
/*required, time, detection time of certificate expiry alarm*/
    "intervalTime":
/*required, integer, alarm interval, unit: day*/
  }
}

16.1.24 JSON_CertificateRevocationCap
CertificateRevocationCap capability message in JSON format
{
 "CertificateRevocationCap":{
  "enabled":{
/*required, boolean, whether to enable certificate expiry alarm*/
    "@opt":[true, false]
  },
  "expireAlarmTime":{

/*required, integer, number of days to prompt in advance before the certificate is expired*/
      "@min":1,
      "@max":30,
      "@def":7
    },
    "detecteTime":{
/*required, time, detection time of certificate expiry alarm*/
      "@min":"00:00",
      "@max":"24:00",
      "@def":"10:00"
    },
    "intervalTime":{
/*required, integer, alarm interval, unit: day*/
      "@min":1,
      "@max":30,
      "@def":1
    }
  }
}

16.1.25 JSON_CertificateSelect
CertificateSelect message in JSON format
{
  "CertificateSelect":{
/*you can choose one field among clientCertificate, serverCertificate, and CACertificate to configure as needed*/
    "clientCertificate":"",
/*optional, string, client certificate type*/
    "serverCertificate":"",
/*optional, string, server certificate type*/
    "CACertificate":"",
/*optional, string, CA certificate type*/
    "SRTPSecurityAlgorithm":""
/*optional, string, encryption algorithm*/
  }
}

16.1.26 JSON_ChanCond
ChanCond message in JSON format
{
  "ChanCond":{
    "chanNo": […,…]
/*specify channel No. to get the status*/
  }
}

16.1.27 JSON_ChanStatus
ChanStatus message in JSON format
{
  "ChanStatus":[{
    "chanNo": ,
/*required, integer type, channel No., which starts from 1*/
    "enable": ,
/*integer type, it is valid for analog channel only, 0-disable, 1-enable*/
    "online": ,
/*required, integer type, online status: 0-offline, 1-online*/
    "record": ,
/*required, whether the device is recording, 0-no, 1-yes*/
    "recordStatus ": ,
/*integer type, recording status: 0-recording, 1-recording exception (HDD exception), 2-recording exception (network
camera offline), 3-recording exception (other reason)*/
    "signal": ,
/*required, integer type, signal status: 0-normal, 1-signal loss*/
    "linkNum": ,
/*required, integer type, number of software clients connected to this channel*/
    "bitRate":
/*required, integer type, channel bit rate, unit: Kpbs*/
  },
  {
    "chanNo": ,
/*required, integer type, channel No., which starts from 1*/
    "enable": ,
/*integer type, it is valid for analog channel only, 0-disable, 1-enable*/
    "online": ,
/*required, integer type, online status: 0-offline, 1-online*/
    "record": ,
/*required, whether the device is recording, 0-no, 1-yes*/
    "recordStatus ": ,
/*integer type, recording status: 0-recording, 1-recording exception (HDD exception), 2-recording exception (network
camera offline), 3-recording exception (other reason)*/
    "signal": ,
/*required, integer type, signal status: 0-normal, 1-signal loss*/
    "linkNum": ,
/*required, integer type, number of software clients connected to this channel*/
    "bitRate":
/*required, integer type, channel bit rate, unit: Kpbs*/
  }]
}

16.1.28 JSON_ChannelInfoList
ChannelInfoList message in JSON format

{
  "ChannelInfoList":{
    "ChannelInfo":[{
     "chanNo": ,
/*required, integer type, channel No.*/
     "enable": ,
/*integer type, it is valid for analog channel only, 0-disable, 1-enable*/
     "name":"",
/*string type, channel name*/
     "online": ,
/*integer type, online status: 0-offline, 1-online*/
     "linknum":
    }]
  }
}

16.1.29 JSON_ChannelInfo
ChannelInfo message in JSON format
{
  "ChannelInfo": [{
   "chanNo": ,
/*required, integer type, channel No.*/
   "enable": ,
/*integer type, it is valid for analog channel only, 0-disable, 1-enable*/
   "name": "",
/*string type, channel name*/
   "online": ,
/*integer type, online status: 0-offline, 1-online*/
   "linknum": ,
/*number of live view channels*/
  }]
}

16.1.30 JSON_ChangedStatus
ChangedStatus message in JSON format
{
 ChangedStatus: {
  "seq": ,
/*32-byte integer type, alarm No., for alarm acknowladge*/
  "devStatus": ,
/*integer type, value of device status: 0-normal, 1-CPU usage, higher than 85%, 2-hardware error (e.g., serial port
exception)*/
  "devCapHash": "";
/*global Hash value of device capability, which is generated by MD5, and encrypted by Base64; for NVR, the Hash

value of network camera should be the calculation source*
    "zeroChanEnable": ,
/*boolean type, whether the channel-zero is enabled: true-yes, false-no*/
    "cycleRecordEnable": true,
/*boolean type, whether to enable recoridng, true-yes, false-no*/
    "chanChanged": […,…,…]
/*integer type, channel status changes, e.g., delete, edit, add, the Hash value of this channel changed*/
    "hdChanged": […,…,…]
/*integer type, HDD status changes, e.g., delete, edit, add*/
    "ChanStatus": [{
      "chanNo": ,
/*integer type, channel No., read-only*/
      "enable": 1,
/*integer type, it is valid for analog channel only, 0-disable, 1-enable*/
      "online": ,
/*required, integer type, online status: 0-offline, 1-online*/
      "recordStatus ": ,
/*integer type, recording status: 0-recording, 1-recording exception (HDD exception), 2-recording exception (network
camera offline), 3-recording exception (other reason)*/
      "signal": ,
/*required, integer type, signal status: 0-normal, 1-signal loss*/
      "arming": ,
/*integer type, network camera arming status: 0-armed, 1-arming failed*/
    }],
    "HDStatus":[{
      "hdNo": ,
/*required, integer type, HDD No., which starts from 1*/
      "status": ,
/*required, integer type, HDD status: 0-activate, 1-sleep, 2-exception, 3-sleepy HDD error, 4-unformated, 5-
disconnected (for network HDD), 6-formatting*/
    }],
    "CapChanged": [{
      "name": "",
/*required, root node of changed capability set*/
      "chan": ,
/*channel No., it is required when transmitting channel capability; it is optional when transmitting device capability*/
      "url": "/ISAPI/Thermal/channels/1/fireDetection/capabilities",
/*capability set URL, it is required for capability set based on ISAPI protocol*/
    },
    {
       "name": "",
/*required, capability set name, which is usually the root node*/
       "chan": 1,
/*channel No., it is required when transmitting channel capability; it is optional when transmitting device capability*/
       "abilityType": 0x700,
/*capability type, it is required if the capability is not based on ISAPI protocol*/
    }]
  }
}

16.1.31 JSON_CommuMode
CommuMode message in JSON format
{
  "CommuMode":{
    "mode":""
/*required, string type, security mode level of the private protocol: "compatibilityMode"-compatibility mode,
"safeMode"-security mode*/
  }
}

16.1.32 JSON_DeviceCertificate
DeviceCertificate message in JSON format
{
  "DeviceCertificate":{
    "CertificateInfo":{
      "issuerDN":"",
/*required, string, read-only, name of the authority that issued the certificate*/
      "subjectDN":"",
/*required, string, read-only, certificate holder name*/
      "startDate":"",
/*required, date, read-only, start date of the certificate validity period, it is accurate to day*/
      "endDate":"",
/*required, date, read-only, end date of the certificate validity period, it is accurate to day*/
      "type":"",
/*optional, string, read-only, certificate type: "https", "websockets", "SDKoverTLS", "SRTP", "securityLog",
"ieee802.1x". Multiple types should be separated by commas*/
      "status":"",
/*optional, string, read-only, certificate status: "normal", "expired", "exceptional"*/
      "customID":""
/*optional, string, read-only, custom certificate ID, it is created when the user imports the certificate and it consists of
digits and characters*/
    }
  }
}

16.1.33 JSON_DeviceCertificateCap
DeviceCertificateCap capability message in JSON format
{
 "DeviceCertificateCap":{
  "customID":{
/*required, string, custom certificate ID, it is created when the user imports the certificate and it consists of digits and
characters*/

      "@min":1,
      "@max":64,
      "status":{
/*optional, string, certificate status: "normal", "expired", "exceptional"*/
        "@opt":["normal", "expired", "exceptional"]
      }
    }
  }
}

16.1.34 JSON_DeviceCertificates
DeviceCertificates message in JSON format
{
  "DeviceCertificates":{
    "CertificateInfoList":{
      "CertificateInfo": [{
    "id": ,
/*required, integer32, read-only, certificate ID, which starts from 1*/
       "issuerDN": "",
/*required, string, read-only, name of the authority that issued the certificate*/
    "subjectDN": "",
/*required, string, read-only, certificate holder name*/
    "startDate": "",
/*required, read-only, start date of certificate expiry period, it is accurate to day*/
    "endDate": "",
/*required, read-only, end date of certificate expiry period, it is accurate to day*/
       "type": "",
/*optional, read-only, certificate type: "wpa", "securityLog", "ieee802.1x", "HTTPS", "WebSocketS", "SDK_OVER_TLS",
"SRTP". Multiple types can be separated by commas*/
       "status": "",
/*optional, string, read-only, certificate status: "normal", "expired", "exceptional"*/
       "customID": ""
/*optional, string, read-only, custom certificate ID, it is created when the user imports the certificate and it consists of
digits and characters*/
      }]
    }
  }
}

16.1.35 JSON_DeviceCertificatesCap
DeviceCertificatesCap message in JSON format
{
    "DeviceCertificatesCap":{
     "CertificateInfoList":{
      "@size": 64,

/*required, integer32 type, read-only*/
      "CertificateInfo": [{
       "id": {
/*required, integer32 type, read-only, certificate ID, which starts from 1*/
      "@min":1,
      "@max":64,
      "#text":
       }
       "issuerDN": "",
/*required, string type, read-only, certificate issue*/
       "subjectDN": "",
/*required, string type, read-only, certificate holder name*/
       "startDate": "",
/*required, read-only, start date of certificate expiry period, it accurate to day*/
       "endDate": ""
/*required, read-only, end date of certificate expiry period, it accurate to day*/
       "type": {
/*optional, read-only, certificate type*/
         "@opt":"wpa, securityLog, ieee802.1x"
       }
      }]
    }
  }
}

16.1.36 JSON_DeviceCertificateStatus
DeviceCertificateStatus message in JSON format
{
  "DeviceCertificateStatus": {
/*required, status of device certificate*/
    "id": "",
/*required, read-only, string type, certificate ID, which is generated and returned by device*/
    "status": ""
/*required, string type, certificate status: normal, abnormal*/
  }
}

16.1.37 JSON_DeviceCertificateStatusList
DeviceCertificateStatusList message in JSON format
{
 "DeviceCertificateStatusList": [{
  "DeviceCertificateStatus": {
/*required, status of device certificate*/
   "id": "",
/*required, read-only, string type, certificate ID, which is generated and returned by device*/

     "status": ""
/*required, string type, certificate status: normal, abnormal*/
   }
  }]
}

16.1.38 JSON_DiagnosisCond
DiagnosisCond message in JSON format
{
  "DiagnosisCond":{
    "command":"",
/*required, string type, diagnosis command*/
    "selfdefineCmd":""
/*string type, custom diagnosis command, it is valid when command is set to "selfdefine"*/
  }
}

16.1.39 JSON_DiagnosisCondCap
DiagnosisCondCap capability message in JSON format
{
 "DiagnosisCondCap":{
/*diagnosis condition capability*/
  "command":{
/*required, supported diagnosis command*/
    "@opt":[
      "system",
/*diagnose system*/
      "alarm",
/*diagnose alarm*/
      "peripheral",
/*diagnose peripheral*/
      "wifi",
/*diagnose Wi-Fi network*/
      "cloud",
/*diagnose cloud*/
      "GPRS/3G/4G",
/*diagnose mobile network*/
      "IPC",
/*diagnose network camera*/
      "ARC",
/*diagnose alarm center*/
      "selfdefine"
/*custom diagnosis command*/
    ]
  },

    "selfdefineCmd":{
/*length range of the custom diagnosis command, it is valid when "selfdefine" is included in command*/
      "@min": ,
/*required, integer type, the minimum length of the custom diagnosis command*/
      "@max":
/*required, integer type, the maximum length of the custom diagnosis command*/
    }
  }
}

16.1.40 JSON_DiagnosisResult
DiagnosisResult message in JSON format
{
  "DiagnosisResult":{
    "result":""
/*required, string type, diagnosis result*/
  }
}

16.1.41 JSON_DoubleVerification
DoubleVerification message in JSON format
{
  "DoubleVerification":{
    "enable": ""
/*optional, whether enables double verification, boolean*/
  }
}

16.1.42 JSON_DownloadPackageStatus
DownloadPackageStatus message in JSON format
{
 "DownloadPackageStatus":{
/*required, upgrade package download status*/
   "status": "notDownload,downloading,pause,finish,incorrectPackage,hdOperationFailed",
/*required, string, download status: "notDownload"-not download, "downloading"-downloading, "pause"-paused,
"finish"-completed, "incorrectPackage"-incorrect upgrade package format, "hdOperationFailed"-HD operation failed*/
   "total": "",
/*optional, float, upgrade package total size, unit: MB, corrects to one decimal place*/
   "remain": "",
/*optional, float, remaining space, unit: MB, corrects to one decimal place*/
   "speed": ""

/*optional, float, download speed, unit: KB/s, corrects to two decimal places*/
    "remainTime": "",
/*optional, integer, estimated remaining time, unit: s*/
    "progress": 0,
/*required, integer, progress, ranges from 0 to 100*/
  }
}

16.1.43 JSON_DynamicHostName
DynamicHostName message in JSON format
{
  "DynamicHostName": {
/*required, configuration parameters of dynamic domain name*/
    "enabled": ,
/*required, boolean type, whether to enable dynamic domain name*/
    "hostName": ""
/*required, string type, domain name*/
  }
}

16.1.44 JSON_DynamicHostNameCap
DynamicHostNameCap message in JSON format
{
  "DynamicHostNameCap": {
/*required, configuration capability of dynamic domain name*/
    "enabled": "true,false",
/*required, boolean type, whether to enable dynamic domain name*/
    "hostName": {
/*required, string type, domain name*/
      "@min": 0,
      "@max": 64
    }
  }
}

16.1.45 JSON_EmailCertification
Enter a short description of your reference here (optional).
Enter the syntax information of your reference here (optional).
Enter the actual information in this section (optional).

Example
Enter an example to illustrate your reference here (optional).

16.1.46 JSON_EnableEncryption
EnableEncryption message in JSON format
{
  "enable": true,
/*required, boolean type, whether to enable stream encryption, true-yes, false-no*/
}

16.1.47 JSON_EncryptFormat
EncryptFormat message in JSON format
{
  "EncryptFormat":{
    "password":"",
/*required, string, password, it will be encrypted according to the encryption vector*/
    "encryptFormatType":""
/*optional, string, HDD formatting type: "FAT32", "EXT4"*/
  }
}

16.1.48 JSON_EncryptionCap
Stream encryption capability in JSON format.
{
  "enable": "true,false",
/*required, boolean type, whether to enable stream encryption, true-yes, false-no*/*/
  "secretKey":{
/*required, string type, encryption key*/
    "@min": 6,
    "@max": 12,
    "#text": "user"
  }
}

16.1.49 JSON_EncryptVerfy
EncryptVerfy message in JSON format
{
    "EncryptVerfy":{

    "password":""
/*required, string, password, it will be encrypted according to the encryption vector*/
  }
}

16.1.50 JSON_EPTZMode
EPTZMode message in JSON format
{
 "EPTZMode":{
  "mode":"",
/*required, modes supported by e-PTZ: "cruise"-patrol (PTZ supports preset, patrol, zoom, and eight directions),
"autoTrack"-automatic tracking*/
  "AutoTrack":{
/*dependency, auto-tracking mode configuration*/
   "sensitivity": ,
/*optional, integer, sensitivity*/
   "detectionTarget":["human", "vehicle"],
/*detection target*/
   "ReginonList":[{
    "id": ,
/*required, rule ID*/
    "Region":[{
/*required, rule area, the number of edges is between 3 and 10*/
       "x": ,
/*required, float, X-coordinate, range: [0.000,1]*/
       "y":
/*required, float, Y-coordinate, range: [0.000,1]*/
    }]
   }],
   "FilterSize":{
/*optional, size filter of rectangle*/
    "MaxTargetRect":{
       "height": ,
/*required, float, height, range: [0.000,1.000], the value is accurate to three decimal places*/
       "width": ,
/*required, float, width, range: [0.000,1.000], the value is accurate to three decimal places*/
       "x": ,
/*required, float, X-coordinate, range: [0.000,1.000], the value is accurate to three decimal places. The upper-left
corner is the origin*/
       "y":
/*required, float, Y-coordinate, range: [0.000,1.000], the value is accurate to three decimal places. The upper-left
corner is the origin*/
    },
    "MinTargetRect":{
       "height": ,
/*required, float, height, range: [0.000,1.000], the value is accurate to three decimal places*/
       "width": ,
/*required, float, width, range: [0.000,1.000], the value is accurate to three decimal places*/
       "x": ,

/*required, float, X-coordinate, range: [0.000,1.000], the value is accurate to three decimal places. The upper-left
corner is the origin*/
          "y":
/*required, float, Y-coordinate, range: [0.000,1.000], the value is accurate to three decimal places. The upper-left
corner is the origin*/
        }
      }
    }
  }
}

16.1.51 JSON_EPTZModeCap
EPTZModeCap capability message in JSON format
{
 "EPTZModeCap":{
  "mode":{
/*required, modes supported by e-PTZ: "cruise"-patrol (PTZ supports preset, patrol, zoom, and eight directions),
"autoTrack"-automatic tracking*/
    "@opt":["cruise", "autoTrack"]
  },
  "AutoTrackCap":{
/*optional, this node is returned when mode contains "autoTrack"*/
    "sensitivity":{
/*optional, integer, sensitivity*/
      "@min":0,
      "@max":100
    },
    "detectionTarget":{
/*detection target*/
      "@opt":["human", "vehicle", "all"]
    },
    "ReginonList":{
      "id":{
/*required, rule ID*/
        "@min":1,
        "@max":4
      },
      "Region":{
/*required, rule area, the number of edges is between 3 and 10*/
        "number":{
/*required, supported number of edges*/
          "@min":3,
          "@max":10
        },
        "x":{
/*required, float, X-coordinate, range: [0.000,1]*/
          "@min":0,
          "@max":1
        },

       "y":{
/*required, float, Y-coordinate, range: [0.000,1]*/
         "@min":0,
         "@max":1
       }
     }
   },
   "FilterSize":{
/*optional, size filter of rectangle*/
     "MaxTargetRect":{
       "height":{
/*required, float, height, range: [0.000,1.000], the value is accurate to three decimal places*/
         "@min":0,
         "@max":1
       },
       "width":{
/*required, float, width, range: [0.000,1.000], the value is accurate to three decimal places*/
         "@min":0,
         "@max":1
       },
       "x":{
/*required, float, X-coordinate, range: [0.000,1.000], the value is accurate to three decimal places. The upper-left
corner is the origin*/
         "@min":0,
         "@max":1
       },
       "y":{
/*required, float, Y-coordinate, range: [0.000,1.000], the value is accurate to three decimal places. The upper-left
corner is the origin*/
         "@min":0,
         "@max":1
       }
     },
     "MinTargetRect":{
       "height":{
/*required, float, height, range: [0.000,1.000], the value is accurate to three decimal places*/
         "@min":0,
         "@max":1
       },
       "width":{
/*required, float, width, range: [0.000,1.000], the value is accurate to three decimal places*/
         "@min":0,
         "@max":1
       },
       "x":{
/*required, float, X-coordinate, range: [0.000,1.000], the value is accurate to three decimal places. The upper-left
corner is the origin*/
         "@min":0,
         "@max":1
       },
       "y":{
/*required, float, Y-coordinate, range: [0.000,1.000], the value is accurate to three decimal places. The upper-left

corner is the origin*/
            "@min":0,
            "@max":1
          }
        }
      }
    }
  }
}

16.1.52 JSON_EventNotificationAlert_Alarm/EventInfo
EventNotificationAlert message with alarm or event information in JSON format.
{
  "ipAddress": "",
/*required, device IPv4 address , string, the maximum size is 32 bytes*/
  "ipv6Address": "",
/*optional, device IPv6 address, string, the maximum size is 128 bytes*/
  "portNo": ,
/*optional, device port No., integer32*/
  "protocol": "",
/*optional, protocol type, "HTTP, HTTPS", string, the maximum size is 32 bytes*/
  "macAddress": "",
/*optional, MAC address, string, the maximum size is 32 bytes, e.g., 01:17:24:45:D9:F4*/
  "channelID": "",
/*optional, device channel No., integer32*/
  "dateTime": "",
/*optional, string, alarm/event triggered or occurred time based on ISO8601, the maximum size is 32 bytes, e.g.,
2009-11-14T15:27Z*/
  "activePostCount": "",
/*required, alarm/event frequency, integer32*/
  "eventType": "",
/*required, alarm/event type, "captureResult, faceCapture,...", string, the maximum size is 128 bytes*/
  "eventState": "",
/*required, string, the maximum size is 32 bytes, durative alarm/event status: "active"-valid, "inactive"-invalid*/
  "eventDescription": "",
/*required, event description, string, the maximum size is 128 bytes*/
  "deviceID":"",
/*string type, device ID*/
  "uuid":"",
/*string type, event UUID, which is used to uniquely identify an event, the standard UUID format is xxxxxxxx-xxxx-xxxx-
xxxx-xxxxxxxxxxxx*/
  ...
/*optional, for different alarm/event types, the nodes are different, see the message examples in different
applications*/
}

16.1.53 JSON_EventNotificationAlert_CertificateExpiryAlarmMsg
The certificate expiry alarm details are uploaded in JSON format of EventNotificationAlert message,
here shows an example.
Content-Type: multipart/form-data; boundary=MIME_boundary
--MIME_boundary
Content-Type: application/json
Content-Length:

{
  "ipAddress":172.6.64.7,
  "ipv6Address":"",
  "portNo":80,
  "protocol":"HTTP",
  "macAddress":"01:17:24:45:D9:F4",
  "channelID":1,
  "dateTime":"2018-11-29T15:32:55+08:00",
  "activePostCount":1,
  "eventType":"certificateRevocation",
  "eventState":"active",
  "eventDescription":"Certificate Revocation Detection",
/*refer to the message JSON_EventNotificationAlert_Alarm/EventInfo for description details of the above nodes*/
  "channelName":"ABC",
/*required, channel name (camera name)*/
  "deviceID":"test0123",
/*optional, device ID, it is also the PUID and it must be returned when passing through ISAPI event by ISUP*/
  "Result":[{
   "customID":"",
/*required, string, custom certificate ID*/
   "certificateType":"CA",
/*required, string, certificate type: "CA"-CA certificate, "client/server"-client or server certificate*/
   "type":["securityLog"],
/*optional, function type: "HTTPS", "WebSocketS", "SDK_OVER_TLS", "SRTP", "securityLog", "ieee802.1x"*/
   "status":"expiring",
/*optional, certificate status: "expiring"-expiring, "expired"-expired, "exceptional"-exceptional*/
   "startDate":"2010-04-17",
/*required, date, start date of the certificate expiry date, it is accurate to day*/
   "endDate":"2010-04-17"
/*required, date, end date of the certificate expiry date, it is accurate to day*/
  }]
}
--MIME_boundary--

See Also
JSON_EventNotificationAlert_Alarm/EventInfo

16.1.54 JSON_EventNotificationAlert_HDDBadSectorEventMsg
The event details of the HDD bad sector detection are uploaded in JSON format of
EventNotificationAlert message, here shows an example.
{
  "ipAddress":"",
/*required, string type, IPv4 address of the alarm device, the maximum length is 32 bytes*/
  "ipv6Address":"",
/*optional, string type, IPv6 address of the alarm device, the maximum length is 128 bytes*/
  "portNo": ,
/*optional, integer32 type, port No. of the alarm device*/
  "protocolType":"",
/*optional, string type, protocol type: "HTTP", "HTTPS", the maximum length is 32 bytes*/
  "macAddress":"",
/*optional, string type, MAC address, the maximum length is 32 bytes*/
  "channelID": ,
/*optional, integer32 type, device channel No. that triggers alarms*/
  "dateTime":"",
/*required, string type, alarm triggering time in ISO8601 time format, e.g., 2018-03-13T19:42:27+08:00, the maximum
length is 32 bytes*/
  "activePostCount": ,
/*required, integer32 type, times that the same alarm has been uploaded*/
  "eventType":"",
/*required, triggered event type: "hdBadBlock"-HDD bad sector detection event*/
  "eventState":"",
/*required, string type, event triggering status: "active"-triggered, "inactive"-not triggered (heartbeat data), the
maximum length is 32 bytes*/
  "eventDescription":"",
/*required, string type, event description: "HDD bad sector detection event", the maximum length is 128 bytes*/
  "deviceID":"",
/*optional, device ID, which is the PUID and should be returned for ISUP alarms, e.g., "test0123"*/
  "HDBadBlock":{
    "diskNo":
/*required, integer32 type, HDD No.*/
  }
}

16.1.55 JSON_EventNotificationAlert_HDDHighTemperatureEventMsg
The event details of the HDD high temperature detection are uploaded in JSON format of
EventNotificationAlert message, here shows an example.
{
 "ipAddress":"",
/*required, string type, IPv4 address of the alarm device, the maximum length is 32 bytes*/
 "ipv6Address":"",
/*optional, string type, IPv6 address of the alarm device, the maximum length is 128 bytes*/
 "portNo": ,

/*optional, integer32 type, port No. of the alarm device*/
  "protocolType":"",
/*optional, string type, protocol type: "HTTP", "HTTPS", the maximum length is 32 bytes*/
  "macAddress":"",
/*optional, string type, MAC address, the maximum length is 32 bytes*/
  "channelID": ,
/*optional, integer32 type, device channel No. that triggers alarms*/
  "dateTime":"",
/*required, string type, alarm triggering time in ISO8601 time format, e.g., 2018-03-13T19:42:27+08:00, the maximum
length is 32 bytes*/
  "activePostCount": ,
/*required, integer32 type, times that the same alarm has been uploaded*/
  "eventType":"",
/*required, triggered event type: "highHDTemperature"-HDD high temperature detection event*/
  "eventState":"",
/*required, string type, event triggering status: "active"-triggered, "inactive"-not triggered (heartbeat data), the
maximum length is 32 bytes*/
  "eventDescription":"",
/*required, string type, event description: "HDD high temperature detection event", the maximum length is 128
bytes*/
  "deviceID":"",
/*optional, device ID, which is the PUID and should be returned for ISUP alarms, e.g., "test0123"*/
  "HighHDTemperature":{
    "diskNo":
/*required, integer32 type, HDD No.*/
  }
}

16.1.56 JSON_EventNotificationAlert_HDDImpactEventMsg
The event details of the HDD impact detection are uploaded in JSON format of
EventNotificationAlert message, here shows an example.
{
 "ipAddress":"",
/*required, string type, IPv4 address of the alarm device, the maximum length is 32 bytes*/
 "ipv6Address":"",
/*optional, string type, IPv6 address of the alarm device, the maximum length is 128 bytes*/
 "portNo": ,
/*optional, integer32 type, port No. of the alarm device*/
 "protocolType":"",
/*optional, string type, protocol type: "HTTP", "HTTPS", the maximum length is 32 bytes*/
 "macAddress":"",
/*optional, string type, MAC address, the maximum length is 32 bytes*/
 "channelID": ,
/*optional, integer32 type, device channel No. that triggers alarms*/
 "dateTime":"",
/*required, string type, alarm triggering time in ISO8601 time format, e.g., 2018-03-13T19:42:27+08:00, the maximum
length is 32 bytes*/
 "activePostCount": ,

/*required, integer32 type, times that the same alarm has been uploaded*/
  "eventType":"",
/*required, triggered event type: "hdImpact"-HDD impact detection event*/
  "eventState":"",
/*required, string type, event triggering status: "active"-triggered, "inactive"-not triggered (heartbeat data), the
maximum length is 32 bytes*/
  "eventDescription":"",
/*required, string type, event description: "HDD impact detection event", the maximum length is 128 bytes*/
  "deviceID":"",
/*optional, device ID, which is the PUID and should be returned for ISUP alarms, e.g., "test0123"*/
  "HDImpact":{
    "diskNo":
/*required, integer32 type, HDD No.*/
  }
}

16.1.57 JSON_EventNotificationAlert_HDDLowTemperatureEventMsg
The event details of the HDD low temperature detection are uploaded in JSON format of
EventNotificationAlert message, here shows an example.
{
 "ipAddress":"",
/*required, string type, IPv4 address of the alarm device, the maximum length is 32 bytes*/
 "ipv6Address":"",
/*optional, string type, IPv6 address of the alarm device, the maximum length is 128 bytes*/
 "portNo": ,
/*optional, integer32 type, port No. of the alarm device*/
 "protocolType":"",
/*optional, string type, protocol type: "HTTP", "HTTPS", the maximum length is 32 bytes*/
 "macAddress":"",
/*optional, string type, MAC address, the maximum length is 32 bytes*/
 "channelID": ,
/*optional, integer32 type, device channel No. that triggers alarms*/
 "dateTime":"",
/*required, string type, alarm triggering time in ISO8601 time format, e.g., 2018-03-13T19:42:27+08:00, the maximum
length is 32 bytes*/
 "activePostCount": ,
/*required, integer32 type, times that the same alarm has been uploaded*/
 "eventType":"",
/*required, triggered event type: "lowHDTemperature"-HDD low temperature detection event*/
 "eventState":"",
/*required, string type, event triggering status: "active"-triggered, "inactive"-not triggered (heartbeat data), the
maximum length is 32 bytes*/
 "eventDescription":"",
/*required, string type, event description: "HDD low temperature detection event", the maximum length is 128
bytes*/
 "deviceID":"",
/*optional, device ID, which is the PUID and should be returned for ISUP alarms, e.g., "test0123"*/
 "LowHDTemperature":{

    "diskNo":
/*required, integer32 type, HDD No.*/
  }
}

16.1.58 JSON_EventNotificationAlert_HDDSevereFaultEventMsg
The event details of the HDD severe fault detection are uploaded in JSON format of
EventNotificationAlert message, here shows an example.
{
  "ipAddress":"",
/*required, string type, IPv4 address of the alarm device, the maximum length is 32 bytes*/
  "ipv6Address":"",
/*optional, string type, IPv6 address of the alarm device, the maximum length is 128 bytes*/
  "portNo": ,
/*optional, integer32 type, port No. of the alarm device*/
  "protocolType":"",
/*optional, string type, protocol type: "HTTP", "HTTPS", the maximum length is 32 bytes*/
  "macAddress":"",
/*optional, string type, MAC address, the maximum length is 32 bytes*/
  "channelID": ,
/*optional, integer32 type, device channel No. that triggers alarms*/
  "dateTime":"",
/*required, string type, alarm triggering time in ISO8601 time format, e.g., 2018-03-13T19:42:27+08:00, the maximum
length is 32 bytes*/
  "activePostCount": ,
/*required, integer32 type, times that the same alarm has been uploaded*/
  "eventType":"",
/*required, triggered event type: "severeHDFailure"-HDD severe fault detection event*/
  "eventState":"",
/*required, string type, event triggering status: "active"-triggered, "inactive"-not triggered (heartbeat data), the
maximum length is 32 bytes*/
  "eventDescription":"",
/*required, string type, event description: "HDD severe fault detection event", the maximum length is 128 bytes*/
  "deviceID":"",
/*optional, device ID, which is the PUID and should be returned for ISUP alarms, e.g., "test0123"*/
  "SevereHDFailure":{
    "diskNo":
/*required, integer32 type, HDD No.*/
  }
}

16.1.59 JSON_EventNotificationAlert_voltageinstable
The supply voltage exception alarm is uploaded in the JSON format of EventNotificationAlert
message.

{
  "ipAddress": "",
/*required, device IPv4 address , string, the maximum size is 32 bytes*/
  "ipv6Address": "",
/*optional, device IPv6 address, string, the maximum size is 128 bytes*/
  "portNo":,
/*optional, device port No., integer32*/
  "protocol": "",
/*optional, protocol type, "HTTP, HTTPS", string, the maximum size is 32 bytes*/
  "macAddress": "",
/*optional, MAC address, string, the maximum size is 32 bytes, e.g., 01:17:24:45:D9:F4*/
  "channelID": "",
/*optional, device channel No., integer32*/
  "dateTime": "",
/optional, string, alarm/event triggered or occurred time based on ISO8601, the maximum size is 32 bytes, e.g.,
2009-11-14T15:27Z*/
  "activePostCount":,
/*required, alarm/event frequency, integer32*/
  "eventType": "voltageinstable",
/*required, alarm/event type, string, the maximum size is 128 bytes*/
  "eventState": "",
/*required, string, the maximum size is 32 bytes, durative alarm/event status: "active"-valid, "inactive"-invalid*/
  "eventDescription": "",
/*required, event description, string, the maximum size is 128 bytes, "overvoltage"-high supply voltage,
"undervoltage"-low supply voltage*/
  "voltageValue": ""
/*optional, supply voltage value, float type, unit: V, corrects to one decimal place*/
}

16.1.60 JSON_EventSearchCap
EventSearchCap message in JSON format
{
 "startTime": "2004-05-03T17:30:08Z",
/*required, start time, ISO8601_time, string*/
 "endTime": "2004-05-03T17:30:08Z",
/*required, end time, ISO8601_time, string*/
 "resultMaxNum": 100,
/*required, supported maximum number of searching, int*/
 "channelIDLen":{
/*optional, channel ID length*/
   "@min": ,
   "@max":
 },
 "eventType":{
/*event type: studentStoodUp-student stands up, accessController-access controller, videoIntercom-video intercom,
OPTEX-OPTEX security control panel, Luminite-Luminite security control panel, GJD-GJD security control panel,
cameraDetector-detector, securityControlPanel-security control panel, multiple selections are separated by comma，
string*/

   "@opt": "studentStoodUp, accessController,videoIntercom, OPTEX,Luminite,GJD, cameraDetector,
securityControlPanel",
   "#text": "studentStoodUp"
 },
 "type":{
/*optional, channel type: video-video channel, IOT-IOT channel, if this node does not exist, it indicates video channel,
string*/
   "@opt": "video,IOT",
   "#text": "video"
 },
 "AccessController":{
/*optional*/
   "eventType":{
/*optional, event type, if this node does not exist, it indicates searching all supported events, string*/
     "@opt": "",
     "#text": ""
   },
   "nameLen":{
/*optional, name length*/
     "@min": ,
     "@max":
   },
   "cardNoLen":{
/*optional, card No. length*/
     "@min": ,
     "@max":
   },
 },
 "VideoIntercom":{
/*optional*/
   "eventType":{
/*optional, optional, event type, if this node does not exist, it indicates searching all supported events, string*/
     "@opt": "",
     "#text": ""
   },
   "nameLen":{
/*optional, name length*/
     "@min": ,
     "@max":
   },
   "cardNoLen":{
/*optional, card No. length*/
     "@min": ,
     "@max":
   },
 },
 "OPTEX":{
/*optional*/
   "eventType":{
/*optional, optional, event type, if this node does not exist, it indicates searching all supported events, string*/
     "@opt": "",
     "#text": ""

    },
  },
  "Luminite":{
/*optional*/
    "eventType":{
/*optional, optional, event type, if this node does not exist, it indicates searching all supported events, string*/
      "@opt": "",
      "#text": ""
    },
  },
  "GJD":{
/*optional*/
    "eventType":{
/*optional, optional, event type, if this node does not exist, it indicates searching all supported events, string*/
      "@opt": "",
      "#text": ""
    },
  },
  "CameraDetector":{
/*optional*/
    "eventType":{
/*optional, optional, event type, if this node does not exist, it indicates searching all supported events, string*/
      "@opt": "",
      "#text": ""
    },
  },
  "SecurityControlPanel":{
/*optional, security control panel event*/
    "eventType":{
/*optional, optional, event type, if this node does not exist, it indicates searching all supported events, string*/
      "@opt": ""
    },
    "zoneNo":{
/*required, zone No., integer*/
      "size": 1,
/*required, the maximum number of items, integer*/
      "@min": 1,
      "@max": 16,
      "#text": 1
    },
  }
}

16.1.61 JSON_EventSearchCond
EventSearchCond message in JSON format
{
 "searchID": "",
/*required, string, unique record search ID.*/
 "searchResultPosition": "",

/*required, initial position of search result in the list, integer, When there are multiple records, and cannot get all
records in one time searching, you can search the records followed specified position for next search*/
 "maxResults": "",
/*required, the max. number of results for current search, int*/
 "startTime": "",
/*required, start time, ISO8601_time, string*/
 "endTime": "",
/*required, end time, ISO8601_time, string*/
 "choiceChannel": [{
/*optional*/
   "channelID": "",
/*optional, channel ID,string*/
 }],
 "eventType": "",
/*required, event type: studentStoodUp-student stands up, accessController-access controller, videoIntercom-video
intercom, OPTEX-OPTEX security control panel, Luminite-Luminite security control panel, GJD-GJD security control
panel, cameraDetector-detector, securityControlPanel-security control panel, multiple selections are separated by
comma，string*/
 "type": "video,IOT",
/*optional, channel type: video-video channel, IOT-IOT channel, if this node does not exist, it indicates video channel,
string*/
 "AccessController":{
   "eventType": "",
/*optional, IoT event type, if this node does not exist, it indicates searching all supported events, string*/
   "name": "",
/*optional, name*/
   "cardNo": "",
/*optional, card No.*/
 },
 "VideoIntercom":{
   "eventType": "",
/*optional, IoT event type, if this node does not exist, it indicates searching all supported events, string*/
   "name": "",
/*optional, name*/
   "cardNo": "",
/*optional, card No.*/
 },
 "OPTEX":{
   "eventType": "",
/*optional, IoT event type, if this node does not exist, it indicates searching all supported events, string*/
 },
 "Luminite":{
   "eventType": "",
/*optional, IoT event type, if this node does not exist, it indicates searching all supported events, string*/
 },
 "GJD":{
   "eventType": "",
/*optional, IoT event type, if this node does not exist, it indicates searching all supported events, string*/
 },
 "CameraDetector":{
   "eventType": "",
/*optional, IoT event type, if this node does not exist, it indicates searching all supported events, string*/

  }
  "SecurityControlPanel":{
    "eventType": "",
/*optional, IoT event type, if this node does not exist, it indicates searching all supported events, string*/
    "zoneNo": [1,2]
/*optional, zone No., it is valid when eventType values "zone", array, the sub type is integer*/
  }
}

16.1.62 JSON_EventSearchResult
EventSearchResult message in JSON format
{
 "responseStatusStrg": "",
/*optional, searching status: OK- Searching ended, NO MATCHES-No matched data found, MORE-Search again for
more results, string, the max. length is 32, {dep if errcode == 1 && errMsg == ok}*/
 "numOfMatches": "",
/*optional, returned number of results for current search, integer32, {dep if errcode == 1 && errMsg == ok}*/
 "totalMatches": "",
/*optional, total number of matched results, integer32, {dep if errcode == 1 && errMsg == ok}*/
 "eventInfo": [{
  "captureTime": "",
/*required, capture time, ISO8601_time, string*/
  "channelID": "",
/*optional, camera ID, string*/
  "channelName": "",
/*optional, camera name*/
  "picUrl": "",
/*optional, picture URL, string*/
  "subPicUrl": "",
/*optional, thumbnail URL, string */
  "eventType": "",
/*required, event type: studentStoodU-student stands up, videoIntercom-video intercom, string*/
  "studentStoodUp":{
/*optional, student stand up event information*/
    "studentsStoodUp_number": ""
/* optional, xs:integer, the number of students, who are standing up*/
  },
  "AccessController":{
    "eventType ": "",
/*required, event type, string*/
    "name": "",
/*optional, name*/
    "cardNo": "",
/*optional, card No.*/
    "cardType": "",
/*optional, card type: invalid-invalid, ordinary-normal card, disabled-card for the disabled,blacklist-card in blacklist,
patrol-patrol card, super-super card, guest-visitor card, remove-removed card*/
    "videoChannelInfo": [{
/*optional, video channel information*/

     "videoChannel": "",
/*required, video channel No., integer*/
     "picUrl": "",
/*optional, picture URL, string*/
    }]
  },
  "VideoIntercom":{
    "eventType ": "",
/*required, event type, string*/
    "name": "",
/*optional, name*/
    "cardNo": "",
/*optional, card No.*/
    "cardType": "invalid,ordinary,disabled,blacklist,patrol,super,guest,remove",
/*optional, card type: invalid-invalid, ordinary-normal card, disabled-card for the disabled,blacklist-card in blacklist,
patrol-patrol card, super-super card, guest-visitor card, remove-removed card*/
    "videoChannelInfo": [{
/*optional, video channel information*/
     "videoChannel": "",
/*required, video channel No., integer*/
     "picUrl": "",
/*optional, picture URL, string*/
    }]
  },
  "OPTEX":{
    "eventType ": "",
/*required, event type, string*/
    "videoChannelInfo": [{
/*optional, video channel information*/
     "videoChannel": "",
/*required, video channel No., integer*/
     "picUrl": "",
/*optional, picture URL, string*/
    }]
  },
  "Luminite":{
    "eventType ": "",
/*required, event type, string*/
    "videoChannelInfo": [{
/*optional, video channel information*/
     "videoChannel": "",
/*required, video channel No., integer*/
     "picUrl": "",
/*optional, picture URL, string*/
    }]
  },
  "GJD":{
    "eventType ": "",
/*required, event type, string*/
    "videoChannelInfo": [{
/*optional, video channel information*/
     "videoChannel": "",

/*required, video channel No., integer*/
      "picUrl": "",
/*optional, picture URL, string*/
     }]
   },
   "CameraDetector":{
     "eventType ": "",
/*required, event type, string*/
     "videoChannelInfo": [{
/*optional, video channel information*/
      "videoChannel": "",
/*required, video channel No., integer*/
      "picUrl": "",
/*optional, picture URL, string*/
     }]
   },
   "SecurityControlPanel":{
     "eventType ": "",
/*required, event type, string*/
     "videoChannelInfo": [{
/*optional, video channel information*/
      "videoChannel": "",
/*required, video channel No., integer*/
      "picUrl": "",
/*optional, picture URL, string*/
     }]
     "zoneNo": "",
/*optional, zone No., it is valid when eventType values "zone", integer*/
     "code":1103,
/*optional, CID event No., it is valid when eventType values "zone", integer*/
     "zoneName": ""
/*optional, zone name, string*/
   }
  }]
}

16.1.63 JSON_ExportInfo
ExportInfo message in JSON format
{
  "ExportInfo":{
    "mediaType":"",
/*required, string, exported data type: "video", "audio", "metadata", "text", "mixed", "other". It should be the same
as the search type. For pictures, this node should be set to "metadata"*/
    "playbackURIList":
/*required, array, file path*/
  }
}

16.1.64 JSON_ExporttoUSB_TaskInfo
TaskInfo message in JSON format
{
  "TaskInfo":{
    "taskId":""
/*required, string, task ID*/
  }
}

16.1.65 JSON_EZVIZSecretKey
EZVIZSecretKey message in JSON format
{
  "EZVIZSecretKey":{
/*required, verificaiton code for Hik-Connect, string, sensitive information should be encrypted, the string length
ranges from 0 to 64. E.g., 34020000002000000001*/
    "secretKey": ""
  }
}

16.1.66 JSON_FileExport
FileExport message in JSON format
{
  "FileExport":{
    "fileType":"",
/*required, string type, file type*/
    "selfDefineCmd":""
/*string type, custom file type to be exported, it is valid when fileType is set to "selfDefine"*/
  }
}

16.1.67 JSON_FileExportCap
FileExportCap capability message in JSON format
{
 "FileExportCap":{
  "fileType":{
   "@opt":["serialLog","coreDump","debug","selfDefine"]
/*required, string type, file type: "serialLog"-serial port log, "coreDump"-core dump log, "debug"-debug log,
"selfDefine"-custom file type to be exported*/

    },
    "selfDefineCmd":{
/*string type, custom file type to be exported, it is valid when fileType is set to "selfDefine"*/
      "@min": ,
/*required, integer type, the minimum length of the custom file type to be exported*/
      "@max":
/*required, integer type, the maximum length of the custom file type to be exported*/
    }
  }
}

16.1.68 JSON_FileExportResult
FileExportResult message in JSON format
{
  "FileExportResult":{
    "url":""
/*required, string type, file URL, e.g., "http://ip:port//ISAPI/ContentMgmt/logSearch/dataPackage/data?identifier"*/
  }
}

16.1.69 JSON_GuideConfig
GuideConfig message in JSON format
{
 "GuideConfig": {
   "GuideStep": [{
/*required, configuration steps of quick setup instruction*/
    "stepIndex": ,
/*required, integer, the maximum supported index*/
    "StepFunction": {
/*required, string, instruction functions*/
       "channelID": ,
/*optional, integer, channel number*/
       "type": ""
/*required, "masterSlaveTracking" (linkage calibration, corresponding URL: /ISAPI/MasterSlaveTracking/channels/<ID>/
slaveCameraCalibrating/capabilities), "mixedTargetDetection" (multi-target type detection, corresponding URL：/ISAPI/
Intelligent/channels/<ID>/mixedTargetDetection/capabilities?format=json), eagleFocusing (rapid focus, corresponding
URL: /ISAPI/PTZCtrl/channels/<ID>/EagleFocusing/capabilities)*/
    },
    "status": "unfinished"
/*required, string, instruction status, whether the single configuration has completed*/
   }],
   "guideStatus": "unfinished"
/*required, string, instruction overall status, whether all configurations have completed*/

    }
}

16.1.70 JSON_GuideConfigCap
GuideConfigCap message in JSON format
{
 "GuideConfigCap": {
   "GuideStep": {
/*required, configuration steps of quick setup instruction*/
    "stepIndexNum": ,
/*required, integer, the maximum supported index*/
    "StepFunction": {
/*required, string, instruction functions*/
      "channels": ,
/*optional, integer, channel number*/
      "type": {
        "@opt": ["masterSlaveTracking", "mixedTargetDetection", "eagleFocusing"]
/*required, "masterSlaveTracking" (linkage calibration, corresponding URL: /ISAPI/MasterSlaveTracking/channels/<ID>/
slaveCameraCalibrating/capabilities), "mixedTargetDetection" (multi-target type detection, corresponding URL：/ISAPI/
Intelligent/channels/<ID>/mixedTargetDetection/capabilities?format=json), eagleFocusing (rapid focus, corresponding
URL: /ISAPI/PTZCtrl/channels/<ID>/EagleFocusing/capabilities)*/
      },
      "guideStatus": {
/*required, string, instruction status, whether the instruction configuration has completed*/
        "@opt": ["finished", "unfinished"]
      }
    },
    "MasterSlaveTrackingCap": {
/*optional, dep:StepFunction, linkage calibration capability*/
      "enabled": {
/*required, boolean, whether to enable, the default value is "true"*/
        "@opt": "true,false",
        "@def": "true"
      },
      "CalibratingMode": {
/*required, string, calibration mode*/
        "@opt": "auto",
        "@def": "auto"
      }
    },
    "MixedTargetDetectionCap": {
/*optional, dep:StepFunction, capability of multi-target type detection*/
      "enabled": {
/*required, boolean, whether to enable, the default value is "true"*/
        "@opt": "true,false",
        "@def": "true"
      },
      "RuleInfoCap": {
/*required, rule information*/

          "maxSize": 1,
/*required, integer, number of supported rules*/
          "ruleID": {
/*required, integer, rule ID*/
            "@min": 1,
            "@max": 1
          },
          "RegionCap": {
/*required, rule region capability*/
            "minSize": 3,
/*required, integer, the minimum region edges*/
            "maxSize": 10,
/*required, integer, the maximum region edges*/
            "x": {
/*required, float, X-coordinate, range: from 0.000 to 1*/
              "@min": 0.000,
              "@max": 1.000,
              "#text": 0.120
            },
            "y": {
/*required, float, Y-coordinate, range: from 0.000 to 1*/
              "@min": 0.000,
              "@max": 1.000,
              "#text": 0.120
            }
          }
        }
      },
      "EagleFocusingCap": {
/*optional, dep:StepFunction, rapid focus capability*/
        "focusMode": {
/*required, string, focus mode*/
          "@opt": "auto",
          "@def": "auto"
        },
        "controlEnabled": {
/*required, boolean, whether to enable rapid focus, corresponding URL: /ISAPI/PTZCtrl/channels/<ID>/EagleFocusing/
control/capabilities*/
          "@opt": "true,false",
          "@def": "true"
        }
      }
    }
  }
}

16.1.71 JSON_HeatMap_CollectionDescription
CollectionDescription message in JSON format

{
  "CollectionDescription":{
    "searchID": "",
/*required，string，unique search ID, the content of searchID remains unchanged when search condition remains
unchanged.*/
    "searchResultPosition": "",
/*required, initial position of search result list, integer type. When there are multiple records, and cannot get all
records in one time searching, you can search the records followed specified position for next search*/
    "maxResults": "",
/*required, number of matched records per search, integer type*/
    "timeSpanList": [{
/*required, time interval list*/
     "startTime": "",
/*required, start time, ISO8601_time, string*/
     "endTime": "",
/*required, end time, ISO8601_time, string*/
    }],
    "channels": "",
/*optional, sub type, array, integer32, related channel No., array. If the channel information is not specified, it
indicates searching all channels*/
    "statisticsType": "PDC",
/*required, string, statistic type: OLD-heat map, PDC-people counting, DURATION-people dwell time, INTERSECTION-
people counting of intersection*/
  }
}

16.1.72 JSON_HeatMap_CollectionDescriptionCap
CollectionDescriptionCap message in JSON format
{
  "CollectionDescriptionCap":{
    "timeRange": "",
/*required, supported time range for replenishment, unit: day, integer*/
    "timeSpanMaxNum": "",
/*required, the maximum number of time buckets supported for one time searching, integer*/
    "resultMaxNum": "",
/*required, the maximum number of items can be searched, integer*/
    "channelMaxNum": "",
/*required, the maximum number of channels supported for one time search, integer*/
    "statisticsType":{
/*required, string，statistics type: OLD-heat map, PDC-people counting statistics, DURATION-people staying time
duration, INTERSECTION-people counting of intersection*/
      "@opt": "OLD,PDC,DURATION,INTERSECTION"
    }
  }
}

16.1.73 JSON_HeatMap_CollectionResult
CollectionResult message in JSON format
{
"CollectionResult":{
  "responseStatusStrg": "",
/*required, searching status: OK- Searching ended, NO MATCHES-No matched data found, MORE-Search again for
more results, string, the max. length is 32, {dep if errcode == 1 && errMsg == ok}*/
  "numOfMatches": "",
/*required, returned number of results for current search, integer32, {dep if errcode == 1 && errMsg == ok}*/
  "totalMatches": "",
/*required, total number of matched results, integer32, {dep if errcode == 1 && errMsg == ok}*/
  "targets": [{
/*optional, people gathering result*/
   "startTime": "",
/*required, start time*/
   "endTime": "",
/*required, end time*/
   "channel": "",
/*required, integer, channel No.*/
   "statisticsType": "",
/*required, string, statistic type: OLD-heat map, PDC-people counting, DURATION-people staying time, INTERSECTION-
people counting of intersection*/
   "HeatMapValue": [{
    "heatmapDataType": "",
/*optional, string，heat map data type, it is valid only when statisticsType values "PDC". "PDC_stayNum"-the number
of people dwell in the image, "PDC_leaveNum"-the number of exiting people in the image*/
    "maxHeatMapValue": ,
/*required, integer, the max. heat value, 4-byte*/
    "minHeatMapValue": ,
/*required, integer，the min. heat value, 4-byte*/
    "timeHeatMapValue": ,
/*required, integer，the average heat value, 4-byte*/
    "lineValue": ,
/*required, integer，row value, 4-byte*/
    "columnValue": ,
/*required, integer，column value, 4-byte*/
    "curNumber": ,
/*optional, integer，the number of current people, it is valid only when statisticsType values "PDC"*/
    "leaveNumber": ,
/*optional, integer，the number of exiting people, it is valid only when statisticsType values "PDC"*/
    "totalTime": ,
/*optional, integer，total dwell time, it is valid only when statisticsType values "DURATION"*/
    }],
    "heatmapURL": "",
/*optional, string，URL of pixel data for heat map image, it is valid when statisticsType values "OLD", "DURATION" or
"INTERSECTION"*/
    "PDC_stayURL": "",
/*optional, string，URL of pixel data for dwell people in heat map image, it is valid when statisticsType values "PDC"*/
    "PDC_leaveURL": "",

/*optional, string，URL of pixel data for exiting people, it is valid when statisticsType values "PDC"*/
     "arrayUnitType": ""
/*optional, string，matrix unit data type (each pixel data type of matrix information): "byte"-a byte, "short"-2 bytes,
"int"–four bytes*/
    }]
  }
}

16.1.74 JSON_HDCond
HDCond message in JSON format
{
  "HDCond":{
    "hdNo": […,…]
/*specify the channel No. to get the corresponding HDD status*/
  }
}

16.1.75 JSON_HddFormatList
HddFormatList message in JSON format
{
  "HddFormatList": [{
/*required, HDD list to be formatted*/
   "HddFormat": {
/*required, initialization parameter of a HDD*/
     "id": ,
/*required, string type, ID of HDDs that specified to be formatted*/
     "formatType": ""
/*optional, string type, formatting type: FAT32, EXT4; this node is only available for SD card; if this node does not exist,
the formatting type is the default type "FAT32"*/
   }
  }]
}

16.1.76 JSON_HDStatus
HDStatus message in JSON format
{
 "HDStatus": [{
  "hdNo": ,
/*required, integer type, HDD No., which starts from 1*/
  "status": ,
/*required, integer type, HDD status: 0-activate, 1-sleep, 2-exception, 3-sleepy HDD error, 4-unformated, 5-

disconnected (for network HDD), 6-formatting*/
   "volume": ,
/*required, integer type, HDD capacity, unit: MB*/
   "freeSpace":
/*required, integer type, free space, unit: MD*/
  }]
}

16.1.77 JSON_id
id message in JSON format
{
  "id": "",
/*optional, integer, user ID, it returns when double verification user is added*/
}

16.1.78 JSON_InputParam
InputParam message in JSON format
{
  "InputParam":{
    "condType": ["name", "enable", "online", "linknum"]
/*enter channel name, enable or disable channel, online status, and number of connections*/
  }
}

16.1.79 JSON_IntelligentSearchCondition
IntelligentSearchCondition message in JSON format
{
 "searchID":"",
/*required, string type, search ID. The content of searchID remains unchanged if the search conditions remain
unchanged. This node is used to check the same search. When the device performance is limited, you can search
asynchronously by applying conditions with the same searchID several times and getting the search progress*/
 "searchResultPosition": ,
/*required, int type, the start position of the search result in the result list. When there are multiple records and you
cannot get all search results at a time, you can search for the records after the specified position next time*/
 "maxResults": ,
/*required, int type, maximum number of search results obtained this time*/
 "startTime":"",
/*required, string type, start time in ISO8601 time format*/
 "endTime":"",
/*required, string type, end time in ISO8601 time format*/
 "choiceChannel":[{

/*optional*/
   "channelID":"",
/*optional, string type, camera No.*/
   "plateRecogRegionID":
/*optional, integer type, license plate recognition area No. If this node is not configured, it refers to all areas*/
  }],
  "targetType":"",
/*optional, string type, search object type. If this node is not returned, it indicates no limit*/
  "vehicleInfo ":{
/*this node is valid when targetType is "vehicle"*/
   "license":"",
/*optional, string type, license plate number*/
   "plateType":"",
/*optional, string type, license plate type: license plate type: "unknown", "92TypeCivil"-92-style civil vehicle, "arm"-
police vehicle, "upDownMilitay"-military vehicle (top-bottom type), "92TypeArm"-92-style police vehicle,
"leftRightMilitay"-military vehicle (left-right type), "02TypePersonalized"-02-style customized vehicle, "yellowTwoLine"-
yellow two-line rear license plate, "04NewMilitay"-04-style new military vehicle, "embassy"-embassy vehicle,
"oneLineArm"-new armed police vehicle (one-line), "twoLineArm"-new armed police vehicle (two-line),
"yellow1225FarmVehicle"-yellow agricultural vehicle with 1225 structure, "green1325FarmVehicle"-green agricultural
vehicle with 1325 structure, "yellow1325FarmVehicle"-yellow agricultural vehicle with 1325 structure, "motorola"-
motorcycle, "coach"-driver-training vehicle, "tempTravl"-vehicle with temporary license plate, "trailer"-trailer,
"consulate"-consular vehicle, "hongKongMacao"-vehicle entering and leaving Hong Kong/Macao, "tempEntry"-
temporary entry vehicle, "civilAviation"-civil aviation license plate, "newEnergy"-new energy license plate. If this node
is not returned, it indicates no limit*/
   "vehicleColor":"",
/*optional, string type, vehicle color: "unknown", "white", "silver"-silvery, "gray", "black", "red", "deepBlue"-dark
blue, "blue", "yellow", "green", "brown", "pink", "purple", "deepGray"-dark gray, "cyan", "orange". Multiple colors
should be separated by commas. If this node is not returned, it indicates no limit*/
   "vehicleType":"",
/*optional, string type, vehicle type: "largeBus"-large-sized bus, "truck"-truck, "vehicle"-salon car, "van"-minivan,
"buggy"-light truck, "pedestrian", "twoWheelVehicle"-two wheeler, "threeWheelVehicle"-tricycle, "SUVMPV"-SUV/
MPV, "mediumBus"-middle-sized bus, "unknown". If this node is not returned, it indicates no limit*/
   "vehicleLogo": ,
/*optional, int type, vehicle parent brand. If this node is not returned, it indicates no limit*/
   "vehicleSubLogo": ,
/*optional, int type, vehicle sub brand. If this node is not returned, it indicates no limit*/
   "vehicleModel": ,
/*optional, int type, vehicle model year. If this node is not returned, it indicates no limit*/
   "plateColor":"",
/*optional, string type, license plate color: "white", "yellow", "blue", "black", "green", "civilAviationBlack"-civil
aviation black, "civilAviationGreen"-civil aviation green, "0xff" or "other"-other color. If this node is not returned, it
indicates no limit*/
   "pilotSafebelt":"",
/*optional, string type, whether the driver buckled up. If this node is not returned, it indicates no limit*/
   "pilotSunvisor":"",
/*optional, string type, whether the driver's sun visor is pulled down. If this node is not returned, it indicates no limit*/
   "vicePilotSafebelt":"",
/*optional, string type, whether the front passenger buckled up*/
   "vicePilotSunvisor":"",
/*optional, string type, whether the front passenger's sun visor is pulled down*/
   "uphone":""
/*optional, string type, whether the person is making a call*/

    }
}

16.1.80 JSON_IOStatus
IOStatus message in JSON format
{
  "IOStatus": {
    "IOInTrig": […,…,…,…],
/*integer type, triggered alarm input No., two places and below: analog alarm input No., two places and above: digital
alarm input No.; and the low 2-bit is the alarm input No., the 3-bit or above is the digital channel No., e.g., 3201-alarm
input No.1 of digital channel No.32*/
      "IOOutTrig": […,…,…,…]
/*integer type, triggered alarm output No., two places and below: analog alarm output No., two places and above:
digital alarm output No.; and the lower 2 bits are the alarm output No., the 3-bit or above is the digital channel No.,
e.g., 3201-alarm output No.1 of digital channel No.32*/
  }
}

16.1.81 JSON_IOT_ChannelInfo
ChannelInfo message in JSON format
{
  "ChannelInfo":{
    "channel": "",
/*required, channel No., it should be returned when the channel is added, integer*/
  }
}

16.1.82 JSON_IOT_ChannelInfoList
ChannelInfoList message in JSON format
{
  "ChannelInfoList": [{
/*optional, channel information, if this node does not exist, it indicates all channels, array*/
   "channel": "",
/*required, channel No., integer*/
   "type": ""
/*required, channel type: "video"-video channel, "IOT"-IoT channel, string*/
  }]
}

16.1.83 JSON_IOT_ErrorList
ErrorList message in JSON format
{
  "ErrorList": [{
/*dep, detailed error information, it is valid when subStatusCode values "badParameters"*/
   "errorRowNo": "",
/*required, error row No., integer*/
   "errorType": "",
/*required, error type, string, channelNoInvalid-invalid channel No., channelNoConflict-conflicted channel No.,
channel IP/Domain invalid-invalid channel IP or domain name, channel IP/Domain conflict-conflicted channel IP or
domain name, "channel IP conflict with local IP"-channel IP is conflicted with local IP, protocolError-incorrect protocol,
adminPortError-incorrect admin port, channelError-incorrect channel No., UserNameInvalid-invalid user name,
passwordInvalid-invalid password, transProtocalError-incorrect transmission protocol, inductiveTypeInvalid-invalid
inductive type*/
  }]
}

16.1.84 JSON_IOTChannel
IOTChannel message in JSON format
{
  "IOTChannel":{
/*optional, added IoT devices information*/
   "channel": "",
/*optional, channel No., if this node does not exist, it indicates any free channel, integer*/
   "IOTProtocolType": "",
/*required, IOT protocol type: "HIKVISION"-Hikvision device, "OPTEX"-OPTEX security control panel, "Luminite"-
Luminite security control panel, "GJD"-GJD security control panel, "SIA-CID"-SIA-CID protocol, string, the max. length is
32*/
   "addressingFormatType": "",
/*optional, address type, "ipaddress"-ip address, "hostname"-host name, string, the max. length is 32*/
   "hostName": "",
/*optional, host name, it is required when addressingFormatType values "hostname", string, the max. length is 64*/
   "ipAddress": "",
/*optional, device IPV4 address, it is required when addressingFormatType values "ipaddress", string, the max. length
is 32*/
   "ipv6Address": "",
/*optional, device IPV6 address, it is required when addressingFormatType values "ipaddress", string, the max. length
is 128*/
   "protocol": "",
/*optional, ptotocol type: "tcp"-TCP protocol, "ud"-UDP protocol, "muticast"-Multicast protocol, string, the max.
length is 32*/
   "portNo": "",
/*optional, device port No., integer*/
   "userName": "",
/*optional, user name, string, the sensitive information is encrypted, the max. length is 32*/

    "password": "",
/*read-only，password, string, the sensitive information is encrypted, the max. length is 16. It will be applied only
when configuring, and it is not returned when getting information*/
    "deviceChannel": "",
/*required, added IoT channel No., integer*/
    "videoChannels": [1, 2],
/*optional, added video channel No., including the cameras and IoT devices, array, and the array unit is integer*/
    "addAll": "",
/*optional, whether adds all channels (including video and IoT channel) of device, boolean*/
    "inductiveDeviceType": "",
/*optional, inductive device type，"inductiveType1"-inductive type 1, "inductiveType2"-inductive type 2. When getting
 added channel information according inductive type, if this node does not exist, all added device channels will be
returned, string*/
    "zoneNum": ""
/*optional, the number of added zones, it is valid when IOTProtocolType values "SIA-CID", integer*/
  }
}

Remarks

     Note
For different IoT devices, the inputted parameters in IOTChannel message are different.
Example
IOTChannel Message of IoT Devices via Private Protocol
"IOTChannel":{
  "IOTProtocolType": "HIKVISION",
  "addressingFormatType": "ipaddress",
  "ipAddress": "10.11.12.13",
  "protocol": "tcp",
  "portNo": 80,
  "userName": "admin",
  "password": "12345",
  "deviceChannel": 1,
  "videoChannels": [1, 2]
}

Example
IOTChannel Message of IoT Devices via SIA-CID Protocol
"IOTChannel":{
 "IOTProtocolType": "HIKVISION",
 "addressingFormatType": "ipaddress",
 "ipAddress": "10.11.12.13",
 "protocol": "tcp",
 "portNo": 80,
 "userName": "admin",
 "password": "12345",
 "deviceChannel": 1,
 "videoChannels": [1, 2],

    "zoneNum": 1
}

Example
IOTChannel Message of OPTEX IoT Devices
"IOTChannel":{
  "IOTProtocolType": "OPTEX",
  "addressingFormatType": "ipaddress",
  "ipAddress": "10.11.12.13",
  "protocol": "tcp",
  "deviceChannel": 1
}

Example
IOTChannel Message of Luminite IoT Devices
"IOTChannel":{
  "IOTProtocolType": "Luminite",
  "addressingFormatType": "ipaddress",
  "ipAddress": "10.11.12.13",
  "protocol": "tcp",
  "portNo": 80,
  "password": "12345",
  "deviceChannel": 1
}

Example
IOTChannel Message of GJD IoT Devices
"IOTChannel":{
  "IOTProtocolType": "GJD",
  "addressingFormatType": "ipaddress",
  "ipAddress": "10.11.12.13",
  "deviceChannel": 1
}

16.1.85 JSON_IOTChannelEventCap
IOTChannelEventCap message in JSON format
{
 "IOTChannelEventCap":{
/*required, event capability*/
 "AccessController":{
/*optional, access controller event*/
   "eventType":{
/*required, event type, array，the sub type is string*/
     "@opt": ["authenticated", "openingDoor"]
   },
 },

  "VideoIntercom":{
/*optional, video intercom event*/
    "eventType":{
/*required, event type, string*/
      "@opt": ["tampering", "duressAlarm"]
    },
  },
  "GJD":{
/*optional, GJD security control panel event*/
    "eventType":{
/*required, event type, string*/
      "@opt": ["pirDetection", "tampering"]
    },
  },
  "Luminite":{
/*optional, Luminite security control panel*/
    "eventType":{
/*required, event type, string*/
      "@opt": ["pirDetection", "pirTamper"]
    },
  },
  "OPTEX":{
/*optional, OPTEX security control panel*/
    "eventType":{
/*required, event type, string*/
      "@opt": ["pcFn", "pcFr"]
    },
  },
  "cameraDetector":{
/*optional, detector evnet*/
    "eventType":{
/*required, event type, string*/
      "@opt": ["wirelessTemperature", "wirelessPIR"]
    },
  },
  "SecurityControlPanel":{
/*optional, security control panel*/
    "eventType":{
/*required, event type, string*/
      "@opt": ["zone","host"]
    },
    "zoneNum":{
/*required, the number of zones, integer*/
      "@min": 1,
      "@max": 16,
      "#text": 1
    },
  }
}

16.1.86 JSON_IOTChannelList
IOTChannelList message in JSON format
{
  "IOTChannelList": [{
   "IOTChannel"
/*optional, added IoT devices information, see details in
                        JSON_IOTChannel
                       */
  }]
}

See Also
JSON_IOTChannel

16.1.87 JSON_IOTChannelStatus
IOTChannelStatus message in JSON format
{
 "IOTChannelStatus":{
/*optional, added IoT device status*/
  "IOTChannel":{
/*optional, added IoT device information, see details in
                         JSON_IOTChannel
                       */
  },
  "channelName": "",
/*required, channel name, string, type, the max. length is 32*/
  "onlineStatus": "",
/*required, online stauts, boolean*/
  "channelDetectResult": "connecting,networkUnreachable,accessAbnormal,normal,guardFailed",
/*optional, channel detection status: "connecting"-connecting, "networkUnreachable"-unreachable network,
"accessAbnormal"-abnormal access, "normal"-normal, "guardFailed"-arming failed, string*/
  "SecurityStatus":{
/*optional, security status*/
    "passwordStatus": ""
/*optional, password status: notActivated-device is inactivated, risk-risky password, weak-weak password, medium-
medium password, strong-strong password, invalid-invalid status, string*/
  },
  "DeviceInfo":{
/*optional, device information*/
    "deviceName": "",
/*optional, device name, string, the max. length is 32*/
    "deviceType": "",
/*required, device type: "accessController"-access controller, "videoIntercom"-video intercom, "OPTEX"-OPTEX
security control panel, Luminite-Luminite security control panel, GJD-GJD security control panel, securityControlPanel-
security control panel，string*/

      "model": "",
/*optional, device model, string, the max. length is 128*/
      "firmwareVersion": "",
/*optional, firmware version, string, the max. length is 128*/
      "firmwareReleasedDate": ""
/*optional, firmware compiled date, string, the max. length is 128*/
    }
  }
}

16.1.88 JSON_IOTChannelStatusList
IOTChannelStatusList message in JSON format
{
  "IOTChannelStatusList": [{
   "IOTChannelStatus":
/*optional, added IoT device status, see details in JSON_IOTChannelStatus*/
  }]
}

See Also
JSON_IOTChannelStatus

16.1.89 JSON_IOTSourceDescription
IOTSourceDescription message in JSON format
{
  "IOTSourceDescription":{
/*optional, protocol information*/
   "IOTProtocolType": "",
/*required, IOT protocol type: "HIKVISION"-Hikvision device, "OPTEX"-OPTEX security control panel, "Luminite"-
Luminite security control panel, "GJD"-GJD security control panel, "SIA-CID"-SIA-CID protocol, string, the max. length is
32*/
   "addressingFormatType": "",
/*optional, address type, "ipaddress"-ip address, "hostname"-host name, string, the max. length is 32*/
   "hostName": "",
/*optional, host name, it is required when addressingFormatType values "hostname", string, the max. length is 64*/
   "ipAddress": "",
/*optional, device IPV4 address, it is required when addressingFormatType values "ipaddress", string, the max. length
is 32*/
   "ipv6Address": "",
/*optional, device IPV6 address, it is required when addressingFormatType values "ipaddress", string, the max. length
is 128*/
   "protocol": "",
/*optional, ptotocol type: "tcp"-TCP protocol, "ud"-UDP protocol, "muticast"-Multicast protocol, string, the max.
length is 32*/
   "portNo": "",

/*optional, device port No., integer*/
    "userName": "",
/*optional, user name, string, the sensitive information is encrypted, the max. length is 32*/
    "password": ""
/*optional, password, string, the sensitive information is encrypted, the max. length is 16*/
  }
}

16.1.90 JSON_IOTSourceList
IOTSourceList message in JSON format
{
  "IOTSourceList": [{
/*optional, source informaiton, array*/
   "IOTProtocolType": "",
/*required, IOT protocol type: "HIKVISION"-Hikvision device, "OPTEX"-OPTEX security control panel, "Luminite"-
Luminite security control panel, "GJD"-GJD security control panel, "SIA-CID"-SIA-CID protocol, string, the max. length is
32*/
   "addressingFormatType": "",
/*optional, address type, "ipaddress"-ip address, "hostname"-host name, string, the max. length is 32*/
   "hostName": "",
/*optional, host name, it is required when addressingFormatType values "hostname", string, the max. length is 64*/
   "ipAddress": "",
/*optional, device IPV4 address, it is required when addressingFormatType values "ipaddress", string, the max. length
is 32*/
   "ipv6Address": "",
/*optional, device IPV6 address, it is required when addressingFormatType values "ipaddress", string, the max. length
is 128*/
   "portNo": "",
/*optional, device port No., integer*/
   "userName": "",
/*optional, user name, string, sensitive information will be encrypted, the max. length is 32*/
   "password": "",
/*optional, password, string, sensitive information will be encrypted, the max. length is 16*/
   "activeStatus": "",
/*required, active or not, boolean*/
   "deviceType": "",
/*optional, string, devive type: accessController-access controller, videoIntercom-video intercom, OPTEX-OPTEX
security control panel, Luminite-Luminite security control panel, GJD-GJD security control panel, securityControlPanel-
security control panel*/
   "macAddress": "",
/*optional, device MAC address, string, the max. length is 48*/
   "serialNumber": "",
/*optional, device serial No., string, the max. length is 48*/
   "firmwareVersion": "",
/*optional, firmware version (including compiled date), string, the max. length is 128*/
  }]
}

16.1.91 JSON_IOTSourceSupport
IOTSourceSupport message in JSON format
{
 "IOTSourceSupport":{
/*required, supported source information*/
  "sourceNum": "",
/*required, the number of protocols, integer*/
  "IOTSourceDescriptions": [{
/*optional, protocol informaiton, array*/
   "IOTProtocolType": "",
/*required, IOT protocol type: "HIKVISION"-Hikvision device, "OPTEX"-OPTEX security control panel, "Luminite"-
Luminite security control panel, "GJD"-GJD security control panel, "SIA-CID"-SIA-CID protocol, string, the max. length is
32*/
   "addressingFormatType":{
/*optional, address type, "ipaddress"-ip address, "hostname"-host name, string, the max. length is 32*/
     "@opt": "ipaddress,hostname",
     "#text": "ipaddress"
   },
   "protocol":{
/*optional, protocol type, "tcp, udp, muticast", string, the max. length is 32*/
     "@opt": "tcp,udp,muticast",
     "#text": "tcp"
   },
   "portNo":{
/*optional, device port No., integer*/
     "@min": 0,
     "@max": 65535,
     "#text": 80
   },
   "userName ":{
/*optional, user name, string, the max. length is 32*/
     "@min": 0,
     "@max": 32,
     "#text": "admin"
   },
   "password":{
/*optional, password, string, the max. length is 16*/
     "@min": 0,
     "@max": 16,
     "#text": "12345"
   },
   "maxVideoChannelNum": "",
/*optional, the max. number of supported video channel, integer*/
   "zoneNum":{
/*optional, number of connected zones, integer, it is valid when the IOTProtocolType values "SIA-CID"*/
     "@min": 1,
     "@max": 256,
     "#text": 1
   },

    }],
    "DeviceInductiveType":{
/*optional, device inductive type*/
      "inductiveType1": ["accessController", "videoIntercom"],
/*optional, array, inductive type 1: accessController-access controller, videoIntercom-video intercom, OPTEX-OPTEX
security control panel, Luminite-Luminite security control panel, GJD-GJD security control panel, securityControlPanel-
security control panel, the sub type is string*/
      "inductiveType2": ["OPTEX", "Luminite", "GJD", "securityControlPanel"]
/*optional, array, inductive type 2: accessController-access controller, videoIntercom-video intercom, OPTEX-OPTEX
security control panel, Luminite-Luminite security control panel, GJD-GJD security control panel,securityControlPanel-
security control panel, the sub type is string*/
    }
  }
}

16.1.92 JSON_LensCorrection
LensCorrection in JSON format
{
  "LensCorrection":{
    "enabled": "",
/*required, enable or not*/
    "TimeTaskList": [{
     "TimeTaskBlock":{
       "dayOfWeek": "",
/*required, integer32，ISO8601 weekday number, 1=Monday*/
       "TimeTaskRange": [{
        "taskID": "",
/*required, integer32, task ID, starts from 1*/
        "beginTime": "",
/*required, begin time, accurate to second, string type*/
        "endTime": ""
/*required, end time, accurate to second, string type*/
       }]
     }
    }]
  }
}

16.1.93 JSON_LensCorrectionCap
LensCorrectionCap message in JSON format
{
 "LensCorrectionCap":{
  "enabled": "true,false",
/*required, enable or not*/
  "TimeTaskList":{

      "maxSize": ,
      "TimeTaskBlock":{
        "dayOfWeek": {
/*required, integer32，ISO8601 weekday number, 1=Monday*/
          "@min": "",
          "@max": "",
        },
        "TimeTaskRange": {
          "maxSize": ,
          "taskID": {
/*required, integer32，task ID, starts from 1*/
            "@min": ,
            "@max": ,
          },
          "beginTime": "01:00:00",
/*required, begin time, corrects to second, string*/
          "endTime": "02:00:00"
/*required, end time, corrects to second, string*/
        }
      }
    }
  }
}

16.1.94 JSON_LinkageChansCond
LinkageChansCond message in JSON format
{
  "LinkageChansCond":{
  "eventType": "",
/*required, string, for access controller or video intercom, the EventType == AcsEvent_major_minor, for security
control panel, the EventType == AlarmHost_zoneNo*/
  "monitorId": "",
/*dep, string，camera ID, strlen=[32,64]. For access controller or video intercom, the format is: device serial
No._DOOR_door No., for security control panel, the format is: device serial No._ALARM_security control panel No.*/
  "unlockType": ""
/optional, unlock type, string，password-unlock by password, hijcking-hijacking unlock, card-unlock by swiping card,
householder-unlock by householder, centerplatform-unlock by center platform, bluetooth-bluetooth unlock, qrcode-
unlock by QR code, face-unlock by face, fingerprint-unlock by fingerprint*/
  }
}

16.1.95 JSON_List_IPAddress
List_IPAddress message in JSON format
{
    "List":[{

   "IPAddress":{
     "ipVersion":"",
/*required, string type, version information of IP address: "v4"-IPv4, "v6"-IPv6*/
     "ipAddress":""
/*required, string type, IP address*/
   }
  }]
}

16.1.96 JSON_LockCfg
LockCfg message in JSON format
{
  "LockCfg":{
    "maxTryTimes": ,
/*optional, integer, the maximum attempts of logging in by the IP address*/
    "lockedTime":
/*optional, integer, time range of locking the IP address, unit: second*/
  }
}

16.1.97 JSON_LockCfgCap
LockCfgCap capability message in JSON format
{
"LockCfgCap":{
    "maxTryTimes":{
/*optional, the maximum attempts of logging in by the IP address*/
      "@opt":"5,..."
    },
    "lockedTime":{
/*optional, time range of locking the IP address, unit: second*/
      "@min": ,
      "@max":
    }
  }
}

16.1.98 JSON_LoginLinkNum
LoginLinkNum message in JSON format
{
    "LoginLinkNum": {
    "maxLinkNum": ,

/*required, integer type, maximum number of logged in accounts*/
  "adminPassword":""
/*required, string type, confirm the password of admin user, this node is valid only when setting maximum number
(PUT), otherwise, this node does not exits*/
   }
}

16.1.99 JSON_OnlineUpgradeParameter
OnlineUpgradeParameter message in JSON format
{
  "OnlineUpgradeParameter":{
/*required, online upgrade parameters*/
    "autoDownloadPackage": "",
/*required, whether enables automatic download of upgrade package, boolean, it values "false" by default*/
    "timingUpgrade": "",
/*optional, whether enable scheduled upgrade, boolean, it values "false" by default*/
    "upgradeTime": "",
/*optional, upgrade time, corrects to minute, and second is 0 by default, ISO8601 format, string type, it is valid when
timingUpgrade values "true"*/
  }
}

16.1.100 JSON_operType
operType message in JSON format
{
  "operType":"",
/*required, string type, operation type: "unlock"-unlock one or multiple IP addresses, "unlockAll"-unlock all IP
addresses*/
  "List":[{
   "IPAddress":{
     "ipVersion":"",
/*required, string, IP address version information: "v4"-IPv4, "v6"-IPv6. This node is valid only when openType is
"unlock"*/
     "ipAddress":""
/*required, string, IP address, this node is valid only when openType is "unlock"*/
   }
  }]
}

16.1.101 JSON_OSD
OSD message in JSON format

{
  "OSD":{
/*required, OSD information*/
    "overlayItem": "",
/*required, string, overlaid item, supports multiple items, each item is separated by comma; deviceName-device
name, cardNo-card number, eventName-event name, name-name, identityCard-ID card, privacyInfo-private
information*/
    "characterEncoding":"",
/*required, character encoding, string*/
    "fontSize": "",
/*required, string, font size: big-large, medium-medium, small-small*/
    "fontColor": "",
/*required, font color, hexBinary*/
    "overlayType": "",
/*required, overlay type: "flip, scroll", string*/
    "displayTime": "",
/*required, display time, unit; second, integer*/
    "PrivacyInfo": [{
/*optional, private information list, it is required when the value of overlayItem contains "privacyInfo", array*/
      "content": "",
 /*required, private information, string, the max. length is 16*/
    }],
    "normalizedScreenSize":{
 /*required, read-only, normalized coordinates*/
      "normalizedScreenWidth": "",
/*required, normalized width, integer*/
      "normalizedScreenHeight": ""
/*required, normalized height, integer*/
    },
    "Rect":{
/*required, OSD position*/
      "height": "",
/*required, height, float*/
      "width": "",
/*required, width, float*/
      "x": "",
/*required, X-coordinate, float*/
      "y": "",
/*required, Y-coordinate, float*/
    }
  }
}

16.1.102 JSON_OSDCap
OSDCap message in JSON format
{
 "OSDCap":{
/*required, OSD information*/

   "overlayItem":{
/*required, string, overlaid item, supports multiple items, each item is separated by comma; deviceName-device
name, cardNo-card number, eventName-event name, name-name, identityCard-ID card, privacyInfo-private
information*/
     "@opt": "deviceName,cardNo,eventName,name,identityCard,privacyInfo",
     "#text": "deviceName"
   },
   "characterEncoding":{
/*required, character encoding, string*/
     "@opt": "GB2312,Latin-1",
     "#text": "GB2312"
   },
   "fontSize":{
/*required, string, font size: big-large, medium-medium, small-small*/
     "@opt": "big,medium,small",
     "#text": "big"
   },
   "fontColor":{
/*required, font color, hexBinary*/
     "@opt": "FFFFFF",
   },
   "overlayType":{
/*required, overlay type: "flip, scroll", string*/
     "@opt": "flip,scroll",
     "#text": "flip"
   },
   "displayTime":{
/*required, display time, unit; second, integer*/
     "@min": 1,
     "@max": 120,
     "#text": 15
   },
   "PrivacyInfo": [{
/*optional, private information list, it is required when the value of overlayItem contains "privacyInfo", array*/
     "size": 3,
/*required, the max. number of items, integer*/
     "content":{
 /*required, private information, string, the max. length is 16*/
       "@min": 1,
       "@max": 16,
       "#text": "12345"
     },
   }],
   "Rect":{
/*required, OSD position*/
     "height":{
/*required, height, float*/
       "@min": 0.000,
       "@max": 1.000,
       "#text": 0.311
     },
     "width":{

/*required, width, float*/
        "@min": 0.000,
        "@max": 1.000,
        "#text": 0.311
      },
      "x":{
/*required, X-coordinate, float*/
        "@min": 0.000,
        "@max": 1.000,
        "#text": 0.311
      },
      "y":{
/*required, Y-coordinate, float*/
        "@min": 0.000,
        "@max": 1.000,
        "#text": 0.311
      },
    }
  }
}

16.1.103 JSON_PeopleCounting_CollectionDescription
CollectionDescription message in JSON format
{
  "CollectionDescription":{
    "searchID": "",
/*required，string，unique search ID, the content of searchID remains unchanged when search condition remains
unchanged.*/
    "searchResultPosition": "",
/*required, initial position of search result list, integer type. When there are multiple records, and cannot get all
records in one time searching, you can search the records followed specified position for next search*/
    "maxResults": "",
/*required, number of matched records per search, integer type*/
    "timeSpanList": [{
/*required, time interval list*/
     "startTime": "",
/*required, start time, ISO8601_time, string*/
     "endTime": "",
/*required, end time, ISO8601_time, string*/
    }],
    "channels": "",
/*optional, sub type, array, integer32, related channel No., array. If the channel information is not specified, it
indicates searching all channels*/
  }
}

16.1.104 JSON_PeopleCounting_CollectionDescriptionCap
CollectionDescriptionCap message in JSON format.
{
  "CollectionDescriptionCap":{
    "timeRange": "",
/*required, supported time range for people counting replenishment, unit: day, integer*/
    "timeSpanMaxNum": "",
/*required, the maximum number of time buckets supported for one time search integer*/
    "resultMaxNum": "",
/*required, the maximum number of items can be searched, integer*/
    "channelMaxNum": ""
/*required, the maximum number of channels supported for one time search, integer*/
  }
}

16.1.105 JSON_PeopleCounting_CollectionResult
CollectionResult message in JSON format
{
  "CollectionResult":{
    "responseStatusStrg": "",
/*required, searching status: OK- Searching ended, NO MATCHES-No matched data found, MORE-Search again for
more results, string, the max. length is 32, {dep if errcode == 1 && errMsg == ok}*/
    "numOfMatches": "",
/*required, returned number of results for current search, integer32, {dep if errcode == 1 && errMsg == ok}*/
    "totalMatches": "",
/*required, total number of matched results, integer32, {dep if errcode == 1 && errMsg == ok}*/
    "targets": [{
/*optional, people gathering result*/
     "startTime": "",
/*required, start time of people gathering*/
     "endTime": "",
/*required, end time of people gathering*/
     "channel": "",
/*required, integer, channel No.*/
     "enter": "",
/*required, integer，the number of people entered*/
     "exit": "",
/*required, integer，the number of people exited*/
     "pass": "",
/*required, integer，the number of people passed by*/
    }]
  }
}

16.1.106 JSON_POE
POE message in JSON format
{
  "POE": {
      "@opt": "ipV4,ipV6",
/*optional, IPv4 address, string type, the max. length is 32 bytes*/
      "#text": "ipV4"
/*optional, IPv6 address, string type, the max. length is 128*/
    }
  }
}

16.1.107 JSON_ProgressInfo
ProgressInfo message in JSON format
{
  "ProgressInfo":{
/*required, progress information*/
    "status":"",
/*required, string, exporting status: "exporting", "failed", "success"*/
    "progress":""
/*required, string, exporting progress, format example: 2/101 (there are 101 files in total to be exported, and 2 files
have been exported)*/
  }
}

16.1.108 JSON_ReportCenterCfg
ReportCenterCfg message in JSON format
{
  "ReportCenterCfg":{
    "enable": ,
/*optional, boolean type, whether to enable uploading report*/
    "ChanAlarmMode":[{
/*alarm channel of the center group*/
     "id": ,
/*optional, integer type, channel ID: 1-main channel, 2-backup channel 1, 3-backup channel 2, 4-backup channel 3*/
     "chanAlarmMode":""
/*optional, string type, alarm channel mode: "T1"-T1 channel, "T2"-T2 channel, "N1"-N1 channel, "N2"-N2 channel,
"G1"-G1 channel, "G2"-G2 channel, "N3"-N3 channel, "N4"-N4 channel*/
    }]
  }
}

16.1.109 JSON_ResponseStatus
ResponseStatus message in JSON format.
{
  "requestURL":"",
/*optional, string type, request URL*/
  "statusCode": ,
/*required, integer type, status code*/
  "statusString":"",
/*required, string type, status description*/
  "subStatusCode":"",
/*required, string type, sub status code*/
  "errorCode": ,
/*optional, integer type, error code, which corresponds to subStatusCode, this field is required when statusCode is
not 1. The returned value is the transformed decimal number*/
  "errorMsg":"",
/*optional, string type, error details, this field is required when statusCode is not 1*/
  "id": ,
/*optional, integer type, unique device ID generally returned when adding the device*/
  "AdditionalErr":{
/*additional error status, which is valid when statusCode is set to 9 (Additional Error). When setting or deleting in a
batch failed, if the error status of a specific device needs to be returned, statusCode should be set to 9 (Additional
Error) and the node <AdditionalError> should be returned*/
    "StatusList":[{
/*required, status information list*/
     "Status":{
       "id": ,
/*optional, integer type, unique device ID*/
       "statusCode": ,
/*optional, integer type, status code*/
       "statusString":"",
/*optional, string type, status description*/
       "subStatusCode":"",
/*optional, string type, sub status code*/
       "errorCode": ,
/*required, integer type, error code, which corresponds to subStatusCode, this field is required when statusCode is
not 1*/
       "errorMsg":"",
/*required, string type, error details, this field is required when statusCode is not 1*/
     }
    }]
  }
}

     Note
See Error Codes in ResponseStatus for details about the status codes, sub status codes, error
codes, and error descriptions.

16.1.110 JSON_resourceStatistics
resourceStatistics message in JSON format
{
  "inputBandwidth": ,
/*required, input bandwidth, unit: kbps, float type, corrects to one decimal*/
  "outputBandwidth": ,
/*required, output bandwidth, unit: kbps, float type, corrects to one decimal*/
  "StreamingInformation": [{
/*optional, stream information, array*/
   "moduleType": "",
/*required, module type: "remoteStreaming"-remote streaming, "remotePlayBack"-remote playback, string type, the
maximum length is 32 bits*/
   "ipAddress": "",
/*required, device IPv4 address, string type, the maximum length is 32 bits*/
   "ipv6Address": "",
/*optional, device IPv6 address, string type, the maximum length is 128 bits*/
   "bandwidth":
/*required, bandwidth, unit: kbps, float type, corrects to one decimal*/
  }],
  "inputPictureBandwidth": ,
/*optional, picture input bandwidth (including all interfaces of inputting binary picture data), unit: kbps, float type,
corrects to one decimal*/
  "outputPictureBandwidth": ,
/*optional, picture output bandwidth (including all interfaces of returning binary picture data), unit: kbps, float type,
corrects to one decimal*/
}

16.1.111 JSON_Result
Result message in JSON format
{
  "Result":{
    "channels": [1, 2],
/*optional, integer, linked video channel No.*/
    "IoTChannels": [1, 2]
/*optional, integer, linked IoT channel NO.*/
  }
}

16.1.112 JSON_secretKey
secretKey message in JSON format
{
    "secretKey":"",

/*required, string type, encryption key*/
}

16.1.113 JSON_SecurityAdvanced
SecurityAdvanced message in JSON format
{
  "SecurityAdvanced ": {
    "securityEnhanced": ,
/*optional, boolean type, whether to enable security reinforcement: true*/
    "noOperationEnabled": ,
/*optional, boolean type, whether to enable control timeout: true*/
    "noOperationTime": ,
/*optional, integer type, control timeout, value range: [1,60], default value: 15, unit: minute*/
    "digestStatus":"SHA256"
/*read-only, string type, digest algorithm: SHA256, MD5*/
  }
}

16.1.114 JSON_SecurityEmail
SecurityEmail message in JSON format
{
  "SecurityEmail":{
    "SecurityInformation": [{
/*required, recovery email information*/
     "emailAddress": "",
/*required, string type, email address, the sensitive information should be encrypted*/
    }],
  },
}

16.1.115 JSON_SecurityEmailCap
SecurityEmailCap message in JSON format
{
 "SecurityEmailCap":
/*required, recovery email configuration capability*/
 {
   "emailAddressNum": ,
/*required, number of recovery emails*/
   "emailAddress":
/*required, string type, recovery email information*/
   {

          "@min": 1,
          "@max": 128,
        },
    }
}

16.1.116 JSON_SecurityEmailQrCode
SecurityEmailQrCode message in JSON format
{
  "SecurityEmailQrCode":
/*optional, QR code of recovery email*/
  {
    "SecurityInformation": [{
/*required, security information, the sensitive information should be encrypted*/
     "emailAddress": "",
/*required, string type, email address, the sensitive information should be encrypted*/
     "qrCode": "",
/*required, string type, QR code, the maximum size is 1024 bytes, the sensitive information should be encrypted*/
    }],
    "serverEmailAddress": "",
/*optional, string type, manufacturer service email address, the sensitive information should be encrypted*
    "isDisclaimerDisplay":
/*optional, boolean type, whether to display disclaimer*/
  },
}

16.1.117 JSON_SerialLogCfg
SerialLogCfg message in JSON format
{
  "SerialLogCfg":{
    "enabled":
/*required, boolean type, whether to enable serial port log redirection: "true"-yes, "false"-no*/
  }
}

16.1.118 JSON_SerialLogCfgCap
SerialLogCfgCap capability message in JSON format
{
 "SerialLogCfgCap":{
  "enabled":"true, false"
/*required, boolean type, whether to enable serial port log redirection: "true"-yes, "false"-no*/

    }
}

16.1.119 JSON_ServerCertificateCap
ServerCertificateCap capability message in JSON format
{
 "ServerCertificateCap":{
  "customID":{
/*required, string, custom certificate ID, it is created when the user imports the certificate and it consists of digits and
characters*/
    "@min":1,
    "@max":64
  },
  "status":{
/*optional, string, certificate status: "normal", "expired", "exceptional"*/
    "@opt":["normal", "expired", "exceptional"]
  },
  "RSAKeyLength":{
/*optional, integer, RSA key length*/
    "@opt":[1024, 2048]
  },
  "countryName":{
/*optional, string, country*/
    "@min":1,
    "@max":32
  },
  "commonName":{
/*optional, string, domain name or IP address*/
    "@min":1,
    "@max":32
  },
  "validity":{
/*optional, integer, valid days*/
    "@min":1
  },
  "passwd":{
/*optional, string, password*/
    "@min":1,
    "@max":64
  },
  "stateOrProvinceName":{
/*optional, string, province or state*/
    "@min":1,
    "@max":32
  },
  "localityName":{
/*optional, string, region*/
    "@min":1,
    "@max":32

    },
    "organizationName":{
/*optional, string, organization*/
      "@min":1,
      "@max":32
    },
    "organizationUnitName":{
/*optional, string, organization unit*/
      "@min":1,
      "@max":32
    },
    "email":{
/*optional, string, email*/
      "@min":1,
      "@max":32
    }
  }
}

16.1.120 JSON_ServerCertificates
ServerCertificates message in JSON format
{
  "ServerCertificates":{
    "CertificateInfo":[{
     "issuerDN":"",
/*required, string, read-only, name of the authority that issued the certificate*/
     "subjectDN":"",
/*required, string, read-only, certificate holder name*/
     "startDate":"",
/*required, date, read-only, start date of the certificate validity period, it is accurate to day*/
     "endDate":"",
/*required, date, read-only, end date of the certificate validity period, it is accurate to day*/
     "type":"",
/*optional, string, read-only, certificate type: "HTTPS", "WebSocketS", "SDK_OVER_TLS", "SRTP", "securityLog",
"ieee802.1x". Multiple types should be separated by commas*/
     "status":"",
/*optional, string, read-only, certificate status: "normal", "expired", "exceptional"*/
     "customID":""
/*optional, string, read-only, custom certificate ID, it is created when the user imports the certificate and it consists of
digits and characters*/
    }]
  }
}

16.1.121 JSON_SmartOverlap
SmartOverlap message in JSON format
{
  "SmartOverlap":{
    "enabled": ,
/*required, boolean, whether to enable the stream*/
    "streamType": ,
/*required, integer, stream type: 1-main stream, 2-sub-stream, 3-third stream*/
    "bkgImageOverlapEnabled":
/*required, boolean, whether to overlay rule frame and target frame on the background picture*/
  }
}

16.1.122 JSON_SmartOverlapCap
SmartOverlapCap capability message in JSON format
{
  "SmartOverlapCap":{
    "enabled":{
/*required, boolean, whether to enable the stream*/
      "@opt":[ true, false]
    },
    "streamType":{
/*required, integer, stream type: 0-disable, 1-main stream, 2-sub-stream, 3-third stream*/
      "@opt":[2]
    },
    "bkgImageOverlapEnabled":{
/*required, boolean, whether to overlay rule frame and target frame on the background picture*/
      "@opt":[true, false]
    },
    "supportEventType":{
/*required, string, supported event type: "fieldDetection"-intrusion, "attendedBaggage"-object removal,
"unattendedBaggage"-unattended baggage, "regionExiting"-region exiting, "regionEntrance"-region entrance,
"lineDetection"-line crossing*/
      "@opt":["fieldDetection", "attendedBaggage", "unattendedBaggage", "regionExiting", "regionEntrance",
"lineDetection"]
    }
  }
}

16.1.123 JSON_SourceCapabilities
SourceCapabilities message in JSON format

{
  "SourceCapabilities":{
/*required, the supported source capabilities*/
    "IOTChannelNum": "",
/*required, the number of IoT channels,integer*/
    "videoChannelNum": """,
/*optional, the number of video channels, integer*/
    "accessChannels": [{
/*optional, array, added channel No.*/
     "channel": "",
/*required, channel No., integer*/
     "type": "",
/*required, channel type: "video"-video channel, "IOT"-IoT channel, string*/
    }]
  }
}

16.1.124 JSON_StopTaskCond
StopTaskCond message in JSON format
{
  "taskID":
/*required, task ID, string*/
}

16.1.125 JSON_CollectionDescription
CollectionDescription message in JSON format
{
 "CollectionDescription":{
  "searchID": "",
/*required，string，unique search ID, the content of searchID remains unchanged when search condition remains
unchanged.*/
  "searchResultPosition": "",
/*required, initial position of search result list, integer type. When there are multiple records, and cannot get all
records in one time searching, you can search the records followed specified position for next search*/
  "maxResults": "",
/*required, number of matched records per search, integer type*/
  "timeSpanList": [{
/*required, time interval list*/
   "startTime": "",
/*required, start time, ISO8601_time, string*/
   "endTime": "",
/*required, end time, ISO8601_time, string*/
  }],
  "channels": "",

/*optional, sub type, array, integer32, related channel No., array. If the channel information is not specified, it
indicates searching all channels*/
  "alarmLevel": "TMA",
/*required, string, alarm level: TMA–thermometry alarm, TMPA-thermometry pre-alarm*/
  }
}

16.1.126 JSON_Temperature_CollectionDescriptionCap
CollectionDescriptionCap message in JSON format
{
  "CollectionDescriptionCap":{
    "timeRange": 15,
/*required, supported time range for replenishment, unit: day, integer */
    "timeSpanMaxNum": 1,
/*required, the maximum number of time buckets supported for one time search, integer*/
    "resultMaxNum": 100,
/*required, the maximum number of items can be searched, integer*/
    "channelMaxNum": 1,
/*required, the maximum number of channels supported for one time search, integer*/
    "alarmLevel":{
/*required, string, alarm level: TMA–thermometry alarm, TMPA-thermometry pre-alarm*/
      "@opt": "TMA,TMPA"
    }
  }
}

16.1.127 JSON_CollectionResult
CollectionResult message in JSON format
{
 "CollectionResult":{
  "responseStatusStrg": "",
/*required, searching status: OK- Searching ended, NO MATCHES-No matched data found, MORE-Search again for
more results, string, the max. length is 32, {dep if errcode == 1 && errMsg == ok}*/
  "numOfMatches": "",
/*required, returned number of results for current search, integer32, {dep if errcode == 1 && errMsg == ok}*/
  "totalMatches": "",
/*required, total number of matched results, integer32, {dep if errcode == 1 && errMsg == ok}*/
  "targets": [{
/*optional, statistics result*/
   "time": "2017-08-25T11:34:59+08:00",
/*required, statistic time*/
   "channel": "",
/*required, integer，channel No.*/
   "Region": [{
/*required, float, X-coordinate, ranges from 0.000 to 1*/

       "x": "",
/*required, float, Y-coordinate, ranges from 0.000 to 1*/
       "y": ""
     }],
     "thermometryUnit": "",
/*required, string, temperature unit: celsius, fahrenheit, kelvin*/
     "ruleTemperature": ,
/*required, float, themometry rule*/
     "currTemperature": ,
/*required, float, current temperature*/
     "ruleCalibType": "",
/*required, string, rule calibration type: point,line,region*/
     "ruleType": "",
/*required, string, rule: "highest temp is higher than"-the maximum temperature is higher than, "lowest temp is
higher than"-the minimum temperature is higher than, "average temp is higher than"-the average temperature is
higher than, "temp diff is higher than"-temperature difference is higher than, "highest temp is lower than"-the
maximum temperature is lower than, "lowest temp is lower than"-the minimum temperature is lower than, "average
temp is lower than"-the average temperature is lower than, "temp diff is lower than"-temperature difference is lower
than*/
     "MaximumTemperaturePoint":{
/*optional, the maximum temperature point*/
       "x": "",
/*required, float, X-coordinate, ranges from 0.000 to 1*/
       "y": ""
/*required, float, Y-coordinate, ranges from 0.000 to 1*/
     },
     "AbsoluteHigh":{
/*optional, absolute height*/
       "elevation": "",
/*required, float，elevation*/
       "azimuth": "",
/*required, float，azimuth*/
       "absoluteZoom": ""
/*required, float，absolute zoom*/
     },
     "ruleID": "",
/*required, integer，rule ID*/
     "presetNo": "",
/*required, integer，preset ID*/
     "visibleLightURL": "",
/*optional, string，visible light picture URL*/
     "thermalURL": "",
/*optional, string，thermal picture URL*/
     "thermalInfoURL": "",
/*optional, string，thermal additional information URL*/
    }]
  }
}

16.1.128 JSON_TimeType
TimeType message in JSON format
{
  "TimeType":{
    "type": ""
/*required, value: local, UTC*/
  }
}

16.1.129 JSON_unitConfig
unitConfig message in JSON format
{
  "enabled": "",
/*required, enable unit unifying configuration or not, boolean type*/
  "temperatureRange": "",
/*optional, string type, temperature unit: degreeCentigrade-Centigrade (°C), degreeFahrenheit-Fahrenheit (°F）,
degreeKelvin-Kelvin (K), the default value is "degreeCentigrade"*/
  "distanceUnit": ""
/*optional, string type, distance unit: centimeter, meter, feet，the default value is "centimeter"*/
}

Remarks
• When the enabled values "false", it indicates the unit unifying function is disabled, the unit can
  be configured in thermomery basic settings, and the configured unit has no influence on the unit
  in system settings.
• When the enabled values "false", the thermomery unit configuration in applied URL remains
  unchanged and takes effect; while when the enabled values "true" and the thermometry unit is
  different with the system unit, the thermometry unit configuration in applied URL takes no effect
  and the error code will be returned.

16.1.130 JSON_unitConfigCap
unitConfigCap message in JSON format
{
 "enabled":"true,false",
/*required, enable unit unified configuration or not, boolean type*/
 "temperatureRange":{
/*optional, string type, temperature unit: degreeCentigrade-Centigrade (°C), degreeFahrenheit-Fahrenheit (°F）,
degreeKelvin-Kelvin (K), the default value is "degreeCentigrade"*/
   "@opt":"degreeCentigrade,degreeFahrenheit,degreeKelvin"
 },

  "distanceUnit":{
/*optional, string type, distance unit: centimeter, meter, feet，the default value is "centimeter"*/
    "@opt":"centimeter,meter,feet"
  }
}

16.1.131 JSON_User
User message in JSON format
{
  "User":{
    "userName": "",
/*required, string, double verification user name*/
    "password": ""
/*required, string, double verification password*/
  }
}

16.1.132 JSON_UserCap
UserCap message in JSON format
{
  "UserCap":{
    "userMaxNumber": "",
/*required, the maximum number of supported double verification users*/
    "userNameLen":{
/*required, the length of double verification user name*/
      "@min": "",
      "@max": "",
       },
    "passwordLen":{
/*required, the length of double verification user password*/
      "@min": 5,
      "@max": 16,
    }
  }
}

16.1.133 JSON_UserList
UserList message in JSON format
{
    "UserList": [{
     "id": ,

/*required, integer, user ID*/
   "userName":"",
/*required, string, double verification user name*/
  }]
}

16.1.134 JSON_UserPermission
UserPermission message in JSON format
{
  "UserPermission":{
    "localPlayback":{
/*optional, local playback permission*/
      "enable": "",
/*required, enables permission or not, boolean*/
      "channelPermission": [{
/*optional, channel permission*/
       "channelID": ,
/*required, channel ID, integer*/
       "enable": ""
/*required, enables permission or not, boolean*/
      }]
    },
    "localBackup":{
/*optional, local backup permission*/
      "enable": "",
/*required, enables permission or not, boolean*/
      "channelPermission": [{
/*optional, channel permission*/
       "channelID": ,
/*required, channel ID, integer*/
       "enable": ""
/*required, enables permission or not, boolean*/
      }]
    },
    "remotePlayback":{
/*optional, remote playback and download permission*/
      "enable": "",
/*required, enables permission or not, boolean*/
      "channelPermission": [{
/*optional, channel permission*/
       "channelID": ,
/*required, channel ID, integer*/
       "enable": ""
/*required, enables permission or not, boolean*/
      }]
    }
  }
}

16.1.135 JSON_UserPermissionCap
UserPermissionCap message in JSON format
{
  "UserPermissionCap":{
    "localPlayback":{
/*required, local playback permission*/
      "channelID":{
/*required, the channel which supports configuring local playback permission*/
        "@min": "",
        "@max": ,
      },
      "enable": "true,false"
/*required, enables permission or not, boolean*/
    },
    "localBackup":{
/*required, local backup permission*/
      "channelID":{
/*required, the channel which supports configuring local backup permission*/
        "@min": "",
        "@max": ,
      },
      "enable": "true,false"
/*required, enables permission or not, boolean*/
    },
    "remotePlayback":{
/*required, remote playback permission*/
      "channelID":{
/*required, the channel which supports configuring remote playback permission*/
        "@min": "",
        "@max": "",
        "#text": ""
      },
      "enable": "true,false"
/*required, enables permission or not, boolean*/
    }
  }
}

16.1.136 JSON_IntelligentSearchCap
IntelligentSearchCap capability message in JSON format
{
 "requestURL":"",
/*optional, string type, request URL*/
 "statusCode":1,
/*required, int type, status code*/

 "statusString":"",
/*required, string type, status description*/
 "subStatusCode":"",
/*required, string type, sub status code*/
 "errorCode":1,
/*optional, int type, error code, this node is required when statusCode is not 1 and it corresponds to subStatusCode*/
 "errorMsg":"ok",
/*optional, string type, error details, this node is required, when statusCode is not 1 and it can be error details about a
specific parameter*/
 "startTime":"2004-05-03T17:30:08+08:00",
/*required, string type, start time in ISO8601 time format. This node only indicates that the device supports this field*/
 "endTime":"2004-05-03T17:30:08+08:00",
/*required, string type, end time in ISO8601 time format. This node only indicates that the device supports this field*/
 "resultMaxNum":100,
/*required, int type, supported maximum number of results that can be searched*/
 "channelIDLen":{
/*optional, camera ID length*/
   "min":1,
   "max":32
 },
 "channelNameLen":{
/*optional, camera name length*/
   "min":1,
   "max":32
 },
 "targetRect":{
/*required, target frame*/
   "height":{
     "min":1,
     "max":100
   },
   "width":{
     "min":1,
     "max":100
   },
   "x":{
     "min":1,
     "max":100
   },
   "y":{
     "min":1,
     "max":100
   }
 },
 "picUrlLen":{
/*required, URL length of the large picture*/
   "min":1,
   "max":128
 },
 "targetType":"vehicle",
/*string type, search object type*/
 "isSupportLicense":true,

/*required, boolean type, whether it supports license plate number*/
 "plateType":"unknown,92TypeCivil,arm,upDownMilitay,92TypeArm,leftRightMilitay,
02TypePersonalized,yellowTwoLine,
04NewMilitay,embassy,oneLineArm,twoLineArm,yellow1225FarmVehicle,green1325FarmVehicle,yellow1325FarmVehi
cle,motorola,coach,tempTravl,trailer,consulate,hongKongMacao,tempEntry,civilAviation,newEnergy",
/*optional, string type, license plate type: license plate type: "unknown", "92TypeCivil"-92-style civil vehicle, "arm"-
police vehicle, "upDownMilitay"-military vehicle (top-bottom type), "92TypeArm"-92-style police vehicle,
"leftRightMilitay"-military vehicle (left-right type), "02TypePersonalized"-02-style customized vehicle, "yellowTwoLine"-
yellow two-line rear license plate, "04NewMilitay"-04-style new military vehicle, "embassy"-embassy vehicle,
"oneLineArm"-new armed police vehicle (one-line), "twoLineArm"-new armed police vehicle (two-line),
"yellow1225FarmVehicle"-yellow agricultural vehicle with 1225 structure, "green1325FarmVehicle"-green agricultural
vehicle with 1325 structure, "yellow1325FarmVehicle"-yellow agricultural vehicle with 1325 structure, "motorola"-
motorcycle, "coach"-driver-training vehicle, "tempTravl"-vehicle with temporary license plate, "trailer"-trailer,
"consulate"-consular vehicle, "hongKongMacao"-vehicle entering and leaving Hong Kong/Macao, "tempEntry"-
temporary entry vehicle, "civilAviation"-civil aviation license plate, "newEnergy"-new energy license plate. Multiple
types should be separated by commas*/

"vehicleColor":"white,silver,gray,black,red,deepBlue,blue,yellow,green,brown,pink,purple,deepGray,cyan,orange,unkn
own",
/*optional, string type, vehicle color: "unknown", "white", "silver"-silvery, "gray", "black", "red", "deepBlue"-dark
blue, "blue", "yellow", "green", "brown", "pink", "purple", "deepGray"-dark gray, "cyan", "orange". Multiple colors
should be separated by commas*/
 "plateColor":"white,yellow,blue,black,green,civilAviationBlack,civilAviationGreen,other",
/*optional, string type, license plate color: "white", "yellow", "blue", "black", "green", "civilAviationBlack"-civil
aviation black, "civilAviationGreen"-civil aviation green, "0xff" or "other"-other color, "unknown"-unrecognized.
Multiple colors should be separated by commas*/

"vehicleType":"largeBus,truck,vehicle,van,buggy,pedestrian,twoWheelVehicle,threeWheelVehicle,SUVMPV,mediumBus
,motorVehicle,nonmotorVehicle,smallCar,miniCar,pickupTruck,unknown",
/*optional, string type, vehicle type: "largeBus"-large-sized bus, "truck"-truck, "vehicle"-salon car, "van"-minivan,
"buggy"-light truck, "pedestrian", "twoWheelVehicle"-two wheeler, "threeWheelVehicle"-tricycle, "SUVMPV"-SUV/
MPV, "mediumBus"-middle-sized bus, "motorVehicle"-motor vehicle (it will be transformed to "vehicle" (salon car) in
the platform), "nonmotorVehicle"-non-motor vehicle (it will be transformed to "threeWheelVehicle" (tricycle) in the
platform), "smallCar"-small sedan (it will be transformed to "vehicle" (salon car) in the platform), "miniCar"-mini
sedan (it will be transformed to "vehicle" (salon car) in the platform), "pickupTruck"-pick-up truck, "unknown".
Multiple types should be separated by commas*/
  "isSupportVehicleLogo":true,
/*optional, boolean type, whether it supports vehicle parent brand*/
  "isSupportvehicleSubLogo":true,
/*optional, boolean type, whether it supports vehicle sub brand*/
  "isSupportVehicleModel":true,
/*optional, boolean type, whether it supports vehicle model year*/
  "channelMaxNum":1,
/*required, integer type, maximum number of channels that support simultaneous search*/
  "supportSearchByUTC":true
/*optional, boolean type, whether it supports searching by UTC*/
}

16.1.137 JSON_VCASearchExportCond
VCASearchExportCond in JSON format
{
 "searchID":"",
/*required, string type, search ID. The content of searchID remains unchanged if the search conditions remain
unchanged. This node is used to check the same search. When the device performance is limited, you can search
asynchronously by applying conditions with the same searchID several times and getting the search progress*/
 "searchResultPosition": ,
/*required, int type, the start position of the search result in the result list. When there are multiple records and you
cannot get all search results at a time, you can search for the records after the specified position next time*/
 "maxResults": ,
/*required, int type, maximum number of search results obtained this time*/
 "startTime":"",
/*required, string type, start time in ISO8601 time format*/
 "endTime":"",
/*required, string type, end time in ISO8601 time format*/
 "choiceChannel":[{
/*optional*/
  "channelID":""
/*optional, string type, camera No.*/
 }],
 "targetType":"",
/*optional, string type, search object type: "human,vehicle,twoWheelVehicle,threeWheelVehicle". If this node is not
returned, it indicates no limit*/
 "targetSize":"",
/*optional, string type, target size. If this node is not returned, it indicates no limit*/
 "direction":"",
/*optional, string type, target direction. If this node is not returned, it indicates no limit*/
 "speed":"",
/*optional, string type, target speed. If this node is not returned, it indicates no limit*/
 "humanInfo":{
/*this node is valid when targetType is "human"*/
  "ageGroup":"",
/*optional, string type, age group. If this node is not returned, it indicates no limit*/
  "gender":"",
/*optional, string type, gender. If this node is not returned, it indicates no limit*/
  "glass":"",
/*optional, string type, whether the person wears glasses. If this node is not returned, it indicates no limit*/
  "bag":"",
/*optional, string type, whether the person is with backpack. If this node is not returned, it indicates no limit*/
  "hat":"",
/*optional, string type, whether the person wears glasses. If this node is not returned, it indicates no limit*/
  "mask":"",
/*optional, string type, whether the person wears mask. If this node is not returned, it indicates no limit*/
  "jacketType":"",
/*optional, string type, tops type. If this node is not returned, it indicates no limit*/
  "trousersType":"",
/*optional, string type, bottoms type. If this node is not returned, it indicates no limit*/
  "hairStyle":"",

/*optional, string type, hairstyle. If this node is not returned, it indicates no limit*/
    "jacketColor":"",
/*optional, string type, tops color. If this node is not returned, it indicates no limit*/
    "trousersColor":"",
/*optional, string type, bottoms color. If this node is not returned, it indicates no limit*/
    "ride":"",
/*optional, string type, whether the person is riding bicycle. If this node is not returned, it indicates no limit*/
    "things":"",
/*optional, string type, whether the person is carrying goods. If this node is not returned, it indicates no limit*/
    "cyclingType":"",
/*optional, string type, riding type*/
    "cyclingPersonNumber":""
/*optional, string type, number of riders*/
  },
  "vehicleInfo":{
/*this node is valid when targetType is "vehicle"*/
    "license":"",
/*optioinal, string type, license plate number*/
    "plateType":"",
/*optional, string type, license plate type: license plate type: "unknown", "92TypeCivil"-92-style civil vehicle, "arm"-
police vehicle, "upDownMilitay"-military vehicle (top-bottom type), "92TypeArm"-92-style police vehicle,
"leftRightMilitay"-military vehicle (left-right type), "02TypePersonalized"-02-style customized vehicle, "yellowTwoLine"-
yellow two-line rear license plate, "04NewMilitay"-04-style new military vehicle, "embassy"-embassy vehicle,
"oneLineArm"-new armed police vehicle (one-line), "twoLineArm"-new armed police vehicle (two-line),
"yellow1225FarmVehicle"-yellow agricultural vehicle with 1225 structure, "green1325FarmVehicle"-green agricultural
vehicle with 1325 structure, "yellow1325FarmVehicle"-yellow agricultural vehicle with 1325 structure, "motorola"-
motorcycle, "coach"-driver-training vehicle, "tempTravl"-vehicle with temporary license plate, "trailer"-trailer,
"consulate"-consular vehicle, "hongKongMacao"-vehicle entering and leaving Hong Kong/Macao, "tempEntry"-
temporary entry vehicle, "civilAviation"-civil aviation license plate, "newEnergy"-new energy license plate. If this node
is not returned, it indicates no limit*/
    "vehicleColor":"",
/*optional, string type, vehicle color: "unknown", "white", "silver"-silvery, "gray", "black", "red", "deepBlue"-dark
blue, "blue", "yellow", "green", "brown", "pink", "purple", "deepGray"-dark gray, "cyan", "orange". Multiple colors
should be separated by commas. If this node is not returned, it indicates no limit*/
    "vehicleType":"",
/*optional, string type, vehicle type: "largeBus"-large-sized bus, "truck"-truck, "vehicle"-salon car, "van"-minivan,
"buggy"-light truck, "pedestrian", "twoWheelVehicle"-two wheeler, "threeWheelVehicle"-tricycle, "SUVMPV"-SUV/
MPV, "mediumBus"-middle-sized bus, "unknown". If this node is not returned, it indicates no limit*/
    "vehicleLogo": ,
/*optional, int type, vehicle parent brand. If this node is not returned, it indicates no limit*/
    "vehicleSubLogo": ,
/*optional, int type, vehicle sub brand. If this node is not returned, it indicates no limit*/
    "vehicleModel": ,
/*optional, int type, vehicle model year. If this node is not returned, it indicates no limit*/
    "plateColor":"",
/*optional, string type, license plate color: "white", "yellow", "blue", "black", "green", "civilAviationBlack"-civil
aviation black, "civilAviationGreen"-civil aviation green, "0xff" or "other"-other color. If this node is not returned, it
indicates no limit*/
    "pilotSafebelt":"",
/*optional, string type, whether the driver buckled up. If this node is not returned, it indicates no limit*/
    "pilotSunvisor":"",
/*optional, string type, whether the driver's sun visor is pulled down. If this node is not returned, it indicates no limit*/

   "vicePilotSafebelt":"",
/*optional, string type, whether the front passenger buckled up*/
   "vicePilotSunvisor":"",
/*optional, string type, whether the front passenger's sun visor is pulled down*/
   "uphone":"",
/*optional, string type, whether the person is making a call*/
   "dangmark":"",
/*optional, string type, whether the vehicle is with hazardous material sign*/
   "envprosign":"",
/*optional, string type, whether it is a yellow-label vehicle*/
   "vehicleState":"",
/*optional, string type, license plate status*/
   "pdvs":"",
/*optional, string type, whether the passenger is standing out of sunroof*/
   "vehicleHead":"",
/*optional, string type, license plate recognition direction*/
   "pendant":"",
/*optional, string type, whether there is pendant*/
   "temporaryLicense":"",
/*optional, string type, whether the vehicle is with temporary license plate*/
   "tricycleCanopy":"",
/*optional, string type, whether the tricycle is with canopy*/
   "decoration":"",
/*optional, string type, whether there is ornament*/
   "tissueBox":"",
/*optional, string type, whether there is tissue box*/
   "card":"",
/*optional, string type, whether there are cards*/
   "cardType":"",
/*optional, string type, card type*/
   "copilot":"",
/*optional, string type, whether the front passenger is seated*/
   "frontChild":"",
/*optional, string type, whether the front passenger holds a baby or the child sits in front passenger's seat alone*/
   "muckTruck":"",
/*optional, string type, whether it is a dump truck*/
   "sunroof":"",
/*optional, string type, whether there is sunroof*/
   "luggageRack":"",
/*optional, string type, whether there is roof rack*/
   "vehicleSprayPainted":"",
/*optional, string type, whether there are characters painted on vehicle*/
   "spareTire":"",
/*optional, string type, whether there is spare tire*/
   "coverPlate":"",
/*optional, string type, whether there is cover on dump truck*/
   "label":""
/*optional, string type, whether the vehicle is with label*/
 },
 "twoWheelVehicle":{
/*this node is valid when targetType is "twoWheelVehicle"*/
   "ageGroup":"",

/*optional, string type, age group. If this node is not returned, it indicates no limit*/
    "gender":"",
/*optional, string type, gender. If this node is not returned, it indicates no limit*/
    "glass":"",
/*optional, string type, whether the person wears glasses. If this node is not returned, it indicates no limit*/
    "bag":"",
/*optional, string type, whether the person is with backpack. If this node is not returned, it indicates no limit*/
    "hat":"",
/*optional, string type, whether the person wears hat. If this node is not returned, it indicates no limit*/
    "mask":"",
/*optional, string type, whether the person wears mask. If this node is not returned, it indicates no limit*/
    "jacketType":"",
/*optional, string type, tops type. If this node is not returned, it indicates no limit*/
    "hairStyle":"",
/*optional, string type, hairstyle. If this node is not returned, it indicates no limit*/
    "jacketColor":"",
/*optional, string type, tops color. If this node is not returned, it indicates no limit*/
    "cyclingType":"",
/*optional, string type, riding type*/
    "cyclingPersonNumber":""
/*optional, string type, number of riders*/
  },
  "threeWheelVehicle":{
/*this node is valid when targetType is "threeWheelVehicle"*/
    "ageGroup":"",
/*optional, string type, age group. If this node is not returned, it indicates no limit*/
    "gender":"",
/*optional, string type, gender. If this node is not returned, it indicates no limit*/
    "glass":"",
/*optional, string type, whether the person wears glasses. If this node is not returned, it indicates no limit*/
    "bag":"",
/*optional, string type, whether the person is with backpack. If this node is not returned, it indicates no limit*/
    "hat":"",
/*optional, string type, whether the person wears hat. If this node is not returned, it indicates no limit*/
    "mask":"",
/*optional, string type, whether the person wears mask. If this node is not returned, it indicates no limit*/
    "jacketType":"",
/*optional, string type, tops type. If this node is not returned, it indicates no limit*/
    "hairStyle":"",
/*optional, string type, hairstyle. If this node is not returned, it indicates no limit*/
    "jacketColor":"",
/*optional, string type, tops color. If this node is not returned, it indicates no limit*/
    "cyclingPersonNumber":""
/*optional, string type, number of riders*/
  }
}

16.1.138 JSON_VCASearchExportProgress
VCASearchExportProgress message in JSON format

{
  "requestURL":"",
  "statusCode": ,
  "statusString":"",
  "subStatusCode":"",
  "errorCode": ,
  "errorMsg":"",
/*see the description of this node and the above nodes in the message of JSON_ResponseStatus*/
  "progress": ,
/*dep, it is valid when errcode values "1" and errMsg values "ok". Export progress, ranges from 0 to 100, int*/
  "URL": ""
/*dep, it is valid when progress values "100", the URL address of packaged result, string*/
}

See Also
JSON_ResponseStatus

16.1.139 JSON_VCASearchExportTaskInfo
VCASearchExportTaskInfo message in JSON format
{
  "requestURL":"",
  "statusCode": ,
  "statusString":"",
  "subStatusCode":"",
  "errorCode": ,
  "errorMsg":"",
/*see the description of this node and the above nodes in the message of JSON_ResponseStatus*/
  "taskID":
/*required, string type, task ID*/
}

See Also
JSON_ResponseStatus

16.1.140 JSON_IntelligentSearchResult
IntelligentSearchResult message in JSON format
{
 "requestURL":"",
/*required, string type, request URL*/
 "statusCode": ,
/*required, int type, status code*/
 "statusString":"",
/*required, string type,status description*/
 "subStatusCode":"",

/*required, string type, sub status code*/
 "errorCode": ,
/*optional, int type, error code, this node is required when statusCode is not 1 and it corresponds to subStatusCode*/
 "errorMsg":"",
/*optional, string type, error details, this node is required, when statusCode is not 1 and it can be error details about a
specific parameter*/
 "responseStatusStrg":"",
/*required, string type, searching status: "OK"-searching completed, "NO MATCH"-no matched results, "MORE"-
searching for more results. The maximum length is 32 bytes. This node is valid when errorCode is 1 and errorMsg is
"ok"*/
 "numOfMatches": ,
/*required, integer32, number of results returned this time. This node is valid when errorCode is 1 and errorMsg is
"ok"*/
 "totalMatches": ,
/*required, integer32, total number of matched results. This node is valid when errorCode is 1 and errorMsg is "ok"*/
 "progress": ,
/*optional, integer32 type, VCA search progress*/
 "targetInfo":[{
/*this node is valid when progress is 100*/
   "captureTime":"",
/*required, string type, capture time in ISO8601 time format*/
   "channelID":"",
/*optional, string type, camera No.*/
   "channelName":"",
/*optioanl, string type, camera name*/
   "streamType":"",
/*optional, string type, streaming type: "realtime,historyvideo,localvideo"*/
   "targetRect":{
/*required, target frame*/
     "height": ,
     "width": ,
     "x": ,
     "y":
   },
   "picUrl":"",
/*optional, string type, large picture URL*/
   "targetType ":"",
/*optional, string type, search object type*/
   "vehicleInfo ":{
/*this node is valid when targetType is "vehicle"*/
     "license":"",
/*optional, string type, license plate number*/
     "plateType":"",
/*optional, string type, license plate type: license plate type: "unknown", "92TypeCivil"-92-style civil vehicle, "arm"-
police vehicle, "upDownMilitay"-military vehicle (top-bottom type), "92TypeArm"-92-style police vehicle,
"leftRightMilitay"-military vehicle (left-right type), "02TypePersonalized"-02-style customized vehicle, "yellowTwoLine"-
yellow two-line rear license plate, "04NewMilitay"-04-style new military vehicle, "embassy"-embassy vehicle,
"oneLineArm"-new armed police vehicle (one-line), "twoLineArm"-new armed police vehicle (two-line),
"yellow1225FarmVehicle"-yellow agricultural vehicle with 1225 structure, "green1325FarmVehicle"-green agricultural
vehicle with 1325 structure, "yellow1325FarmVehicle"-yellow agricultural vehicle with 1325 structure, "motorola"-
motorcycle, "coach"-driver-training vehicle, "tempTravl"-vehicle with temporary license plate, "trailer"-trailer,
"consulate"-consular vehicle, "hongKongMacao"-vehicle entering and leaving Hong Kong/Macao, "tempEntry"-

temporary entry vehicle, "civilAviation"-civil aviation license plate, "newEnergy"-new energy license plate*/
     "vehicleColor":"",
/*optional, string type, vehicle color: "unknown", "white", "silver"-silvery, "gray", "black", "red", "deepBlue"-dark
blue, "blue", "yellow", "green", "brown", "pink", "purple", "deepGray"-dark gray, "cyan", "orange". Multiple colors
should be separated by commas*/
     "vehicleType":"",
/*optional, string type, vehicle type: "largeBus"-large-sized bus, "truck"-truck, "vehicle"-salon car, "van"-minivan,
"buggy"-light truck, "pedestrian", "twoWheelVehicle"-two wheeler, "threeWheelVehicle"-tricycle, "SUVMPV"-SUV/
MPV, "mediumBus"-middle-sized bus, "unknown"*/
     "vehicleLogo": ,
/*optional, int type, vehicle parent brand*/
     "vehicleSubLogo": ,
/*optional, int type, vehicle sub brand*/
     "vehicleModel": ,
/*optional, int type, vehicle model year*/
     "plateColor":"",
/*optional, string type, license plate color: "white", "yellow", "blue", "black", "green", "civilAviationBlack"-civil
aviation black, "civilAviationGreen"-civil aviation green, "0xff" or "other"-other color.*/
     "pilotSafebelt":"",
/*optional, string type, whether the driver buckled up*/
     "pilotSunvisor":"",
/*optional, string type, whether the driver's sun visor is pulled down*/
     "vicePilotSafebelt":"",
/*optional, string type, whether the front passenger buckled up*/
     "vicePilotSunvisor":"",
/*optional, string type, whether the front passenger's sun visor is pulled down*/
     "uphone":"",
/*optional, string type, whether the person is making a call*/
     "region":"",
/*optional, string type, region that the license plate belongs to: "EU"-Europe, "ER"-Russian region, "EUandCIS"-Europe
and Russia, "ME"-the Middle East, "All"-all regions, "other"*/
     "country":""
/*optional, string type, country that the license plate belongs to: "EU"-Europe, "ER"-Russian region, "EUandCIS"-
Europe and Russia, "ME"-the Middle East, "All"-all regions, "other"*/
   }
  }]
}

16.1.141 JSON_WhiteLightAlarm
WhiteLightAlarm message in JSON format
{
 "WhiteLightAlarm":{
  "durationTime": ,
/*required, integer type, flashing duration of supplement light, which is between 1 and 60 s*/
  "frequency":"",
/*required, string type, flashing frequency of supplement light: "high"-flashing 0.5s per second, "medium"-flashing
0.8s per 1.6s, "low"-flashing 1s per 2s*/
  "brightness": ,
/*optional, integer type, supplement light brightness, which is between 1 and 100*/

    "TimeRangeList":[{
/*optional, alarm output schedule list*/
     "week": ,
/*required, integer type, days of the week: 1-Monday, 2-Tuesday, 3-Wednesday, 4-Thursday, 5-Friday,6-Saturday, 7-
Sunday*/
     "TimeRange":[{
       "id": ,
/*required, integer type, ID of time period for each day*/
       "beginTime":"",
/*required, string type, start time in ISO8601 format*/
       "endTime":""
/*required, string type, end time in ISO8601 format*/
     }]
    }]
  }
}

16.1.142 JSON_WhiteLightAlarmCap
WhiteLightAlarmCap message in JSON format
{
 "WhiteLightAlarmCap":{
  "durationTime":{
/*required, integer type, flashing duration of supplement light, which is between 1 and 60 s*/
    "@min": ,
    "@max": ,
    "@def":
  },
  "frequency":{
/*required, string type, flashing frequency of supplement light: "high"-flashing 0.5s per second, "medium"-flashing
0.8s per 1.6s, "low"-flashing 1s per 2s*/
    "@opt":"",
    "@def":""
  },
  "brightness":{
/*optional, integer type, supplement light brightness, which is between 1 and 100*/
    "@min": ,
    "@max": ,
    "@def":
  },
  "TimeRangeCap":{
/*optional, alarm output schedule capability*/
    "week":{
/*required, integer type, days of the week: 1-Monday, 2-Tuesday, 3-Wednesday, 4-Thursday, 5-Friday,6-Saturday, 7-
Sunday*/
      "@opt":""
    },
    "id":{
/*required, integer type, ID of time period for each day*/
      "@maxSize":

      },
      "beginTime":{
/*required, string type, start time in ISO8601 format*/
        "@min":"",
        "@max":""
      },
      "endTime":{
/*required, string type, end time in ISO8601 format*/
        "@min":"",
        "@max":""
      }
    },
    "whiteLightMode":{
/*optional, string type, supplement light mode: "keepOn"-always on, "flashing"-flashing*/
      "@opt":"keepOn,flashing",
      "@def":"keepOn"
    }
  }
}

16.1.143 JSON_WorkingStatus
WorkingStatus message in JSON format
{
 "WorkingStatus":{
  "devStatus": ,
/*required, integer type, value of device status: 0-normal, 1-CPU usage, higher than 85%, 2-hardware error (e.g., serial
port exception)*/
  "ChanStatus":[{
   "chanNo": ,
/*required, integer type, channel No., which starts from 1*/
   "enable": ,
/*integer type, it is valid for analog channel only, 0-disable, 1-enable*/
   "online": ,
/*required, integer type, online status: 0-offline, 1-online*/
   "record": ,
/*required, whether the device is recording, 0-no, 1-yes*/
   "recordStatus ": ,
/*integer type, recording status: 0-recording, 1-recording exception (HDD exception), 2-recording exception (network
camera offline), 3-recording exception (other reason)*/
   "signal": ,
/*required, integer type, signal status: 0-normal, 1-signal loss*/
   "linkNum": ,
/*required, integer type, number of software clients connected to this channel*/
   "bitRate":
/*required, integer type, channel bit rate, unit: Kpbs*/
  }],
  "HDStatus":[{
   "hdNo": ,
/*required, integer type, HDD No., which starts from 1*/

      "status": ,
/*required, integer type, HDD status: 0-activate, 1-sleep, 2-exception, 3-sleepy HDD error, 4-unformated, 5-
disconnected (for network HDD), 6-formatting*/
      "volume": ,
/*required, integer type, HDD capacity, unit: MB*/
      "freeSpace":
/*required, integer type, free space, unit: MD*/
    }],
    "IOStatus":{
      "IOInTrig":[…,…,…,…],
/*integer type, triggered alarm input No., two places and below: analog alarm input No., two places and above: digital
alarm input No.; and the low 2-bit is the alarm input No., the 3-bit or above is the digital channel No., e.g., 3201-alarm
input No.1 of digital channel No.32*/
      "IOOutTrig":[…,…,…,…]
/*integer type, triggered alarm output No., two places and below: analog alarm output No., two places and above:
digital alarm output No.; and the lower 2 bits are the alarm output No., the 3-bit or above is the digital channel No.,
e.g., 3201-alarm output No.1 of digital channel No.32*/
    }
  }
}

16.1.144 JSON_XX
XX message in JSON format
{
  "XX":{
/*required, event/alarm configuration information*/
    "enabled": "",
/*required, enable or not, boolean*/
    "zoneName": ""
/*optional, zone name, it is valid only when event type is zone, string*/
  }
}

Remarks
The XX in the parameter "XX" corresponds to detailed event type. E.g., if the event type is
humanRecognition, then the returned node is "HumanRecognition".

16.1.145 JSON_XXCap
XXCap message in JSON format
{
 "XXCap":{
/*required, event configuration information*/
  "enabled": "true,false",
/*required, enable or not, boolean*/

    "zoneName":{
/*optional, zone name, it is valid only when event type is zone, string*/
      "@min": 1,
      "@max": 64,
    },
  }
}

Remarks
The XX in the parameter "XXCap" corresponds to detailed event type. E.g., if the event type is
humanRecognition, then the returned node is "HumanRecognitionCap".

16.2 XML Messages

16.2.1 XML_accessDevice
accessDevice message in XML format
<accessDevice version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:integer--></id>
 <MACAddress><!--opt, xs:string--></MACAddress>
 <ipV4Address><!--dep, xs:string--></ipV4Address>
 <accessTime><!--req, xs:time, ISO8601 data--></accessTime>
</accessDevice>

16.2.2 XML_accessDeviceList
accessDeviceList message in XML format
<accessDeviceList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <accessDevice/><!--see details in the message of XML_accessDevice-->
</accessDeviceList>

See Also
XML_accessDevice

16.2.3 XML_accessPoint
accessPoint message in XML format
<accessPoint version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:integer--></id>
 <networkMode>
  <!--opt, xs:string, "infrastructure, adhoc"-->
 </networkMode>

 <channel><!--opt, xs:string, "1 to 14, auto"--></channel>
 <ssid><!--req, xs:string--></ssid>
 <speed><!--opt, xs:integer, unit: Mbps--></speed>
 <signalStrength><!--opt, xs:integer, signal strength, which is between 0 and 100--></signalStrength>
 <securityMode>
  <!--req, xs:string, "disable,WEP,WPA-personal,WPA2-personal,WPA-RADIUS,WPA-enterprise,WPA2-enterprise"-->
 </securityMode>
 <connected><!--opt, xs:boolean--></connected>
 <connecting><!--opt, xs:boolean, whether the device is connecting to the Wi-Fi--></connecting>
</accessPoint>

16.2.4 XML_accessPointList
accessPointList message in XML format
<accessPointList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <accessPoint/><!--see details in the message of XML_accessPoint>
</accessPointList>

See Also
XML_accessPoint

16.2.5 XML_ActivateInfo
ActivateInfo message in XML format.
<ActivateInfo version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <password><!--req, xs:string--></password>
</ActivateInfo>

16.2.6 XML_AdminAccessProtocol
AdminAccessProtocol message in XML format
<AdminAccessProtocol version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--required, xs:string, ID--></id>
 <enabled><!--optional, xs:boolean, "true,false"--></enabled>
 <protocol><!--required, xs:string, protocol name:
"HTTP,HTTPS,RTSP,DEV_MANAGE,IOT,WebSocket,WebSocketS,SDK_OVER_TLS,TLS1_1Enable,TLS1_2Enable,SRTP"--></
protocol>
 <portNo><!--required, xs:integer--></portNo>
 <redirectToHttps>
   <!--opt, xs: boolean, whether to automatically go to HTTPS when connecting to HTTP port and HTTPS is enabled-->
 </redirectToHttps>
 <streamOverTls>
   <!--opt, xs: boolean, whether to enable TLS link encryption when the streaming mode is SDK_OVER_TLS, true-yes,
false-no-->

 </streamOverTls>
</AdminAccessProtocol>

Remarks
"TLS1_1Enable" and "TLS1_2Enable" are not available for port configuration.

16.2.7 XML_AdminAccessProtocolList
AdminAccessProtocolList message in XML format
<AdminAccessProtocolList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <AdminAccessProtocol/><!--see details in the message of XML_AdminAccessProtocol-->
</AdminAccessProtocolList>

See Also
XML_AdminAccessProtocol

16.2.8 XML_AlgorithmsVersion
AlgorithmsVersion message in XML format
<AlgorithmsVersion version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <AlgorithmsVersionInfoList><!--opt-->
  <AlgorithmsVersionInfo>
   <majorVersion><!--req,xs:integer, major version No.--></majorVersion>
   <minorVersion><!--req,xs: integer, minor version No.--></minorVersion>
   <revisionNumber><!--req,xs: integer, revision No.--></revisionNumber>
   <buildNumber><!--req,xs: integer, build No.--></buildNumber>
   <versionYear><!--req,xs: integer, date: year--></versionYear>
   <versionMonth><!--req,xs: integer, date: month--></versionMonth>
   <versionDay><!--req,xs: integer, date: day--></versionDay>
   <name>
    <!--req, xs:string, algorithm library name, "faceProperties"-face attributes, "behaviorAnalysis"-behavior analysis,
"humanAttribute"-human body attributes, "faceSnap"-face capture, "faceRecognition", "faceContrast"-face picture
comparison, "peopleCounting", "faceScore"-face picture score, "personQueueDetection"-queue management,
"depthMap"-->
   <name>
  </AlgorithmsVersionInfo>
 </AlgorithmsVersionInfoList>
</AlgorithmsVersion>

Example
AlgorithmsVersion Message Example
<AlgorithmsVersion version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <AlgorithmsVersionInfoList>
  <AlgorithmsVersionInfo>
   <majorVersion>1</majorVersion>

   <minorVersion>0</minorVersion>
   <revisionNumber>1</revisionNumber>
   <versionYear>17</versionYear>
   <versionMonth>12</versionMonth>
   <versionDay>12</versionDay>
   <name>faceSnap</name>
  </AlgorithmsVersionInfo>
  <AlgorithmsVersionInfo>
   <majorVersion>1</majorVersion>
   <minorVersion>0</minorVersion>
   <revisionNumber>0</revisionNumber>
   <versionYear>17</versionYear>
   <versionMonth>10</versionMonth>
   <versionDay>31</versionDay>
   <name>faceScore</name>
  </AlgorithmsVersionInfo>
  <AlgorithmsVersionInfo>
   <majorVersion>3</majorVersion>
   <minorVersion>4</minorVersion>
   <revisionNumber>1</revisionNumber>
   <versionYear>17</versionYear>
   <versionMonth>12</versionMonth>
   <versionDay>25</versionDay>
   <name>faceContrast</name>
  </AlgorithmsVersionInfo>
 </AlgorithmsVersionInfoList>
</AlgorithmsVersion>

16.2.9 XML_AudioCap
AudioCap capability message in XML format
<AudioCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <audioInputNums><!--req, xs:integer--></audioInputNums>
 <audioOutputNums><!--req, xs:integer--></audioOutputNums>
</AudioCap>

16.2.10 XML_AudioChannel
AudioChannel message in XML format
<AudioChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string--></id>
 <enabled><!--req, xs:boolean--></enabled>
</AudioChannel>

16.2.11 XML_AudioChannelList
AudioChannelList message in XML format
<AudioChannelList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <AudioChannel/><!--opt, see details in the message of XML_AudioChannel-->
</AudioChannelList>

See Also
XML_AudioChannel

16.2.12 XML_AudioDscriptor
AudioDscriptor message in XML format
<AudioDscriptor version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <audioCompressionType>
  <!--opt, xs: string,audio encoding type: "G.711alaw,G.711ulaw,G.726,G.729,G.729a,G.
729b,PCM,MP3,AC3,AAC,ADPCM,MP2L2"-->
 </audioCompressionType>
 <audioSamplingRate><!--opt, xs: float, kHz--></audioSamplingRate>
</AudioDscriptor>

16.2.13 XML_AudioIn
AudioIn message in XML format
<AudioIn version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id>
  <!--req, xs:string-->
 </id>
 <MixAudioIn>
  <!--req, ro-->
  <enabled>
   <!--req, xs:Boolean-->
  </enabled>
  <audioInputType>
   <!--opt, xs:string-->
  </audioInputType>
  <highPassFilter>
   <!--req, xs:integer, unit: Hz-->
  </highPassFilter>
  <noiseMargin>
   <!--req, xs:integer, unit: dB-->
  </noiseMargin>
  <AutoLimitWave>
   <!--dep-->

   <FBCEnable>
    <!--req, xs:Boolean-->
   </FBCEnable>
   <mode>
    <!--req, xs:string-->
   </mode>
   <filterQValue>
    <!--req, xs:string-->
   </filterQValue>
   <staticFilterNum>
    <!--req, xs:integer-->
   </staticFilterNum>
  </AutoLimitWave>
 </MixAudioIn>
 <AudioInVolumelist>
  <AudioInVlome>
   <type>
    <!--req, xs:string, "audioInput,audioEncode"-->
   </type>
   <volume>
    <!--req, xs:integer-->
   </volume>
  </AudioInVlome>
 </AudioInVolumelist>
</AudioIn>

16.2.14 XML_AudioInCap
AudioInCap capability message in XML format
<AudioInCap version="2.0" xmlns="http://wwwisapiorg/ver20/XMLSchema">
 <id>
  <!--req, xs:string-->
 </id>
 <MixAudioIn>
  <!--req, ro-->
  <enabled opt="true,false">
   <!--req, xs:Boolean-->
  </enabled>
  <audioInputType opt="micIn, lineIn">
   <!--opt, xs:string-->
  </audioInputType>
  <highPassFilter
opt="0,8,16,24,31,39,47,55,63,71,79,87,94,102,110,118,126,134,142,150,157,165,173,181,189,197,205,213,220,228,
236,244,252,260,268,276,283,291,299,307,315,323,331,339,346,354,362,370,378,386,394,402,409,417,425,433,441,
449,457,465,472,480,488,496,504,512,520,528,535,543,551,559,567,575,583,591,598,606,614,622,630,638,646,654,
661,669,677,685,693,701,709,717,724,732,740,748,756,764,772,780,787,795,803,811,819,827,835,843,850,858,866,
874,882,890,898,906,913,921,929,937,945,953,961,969,976,984,992,1000" default="30">
   <!--req, xs:integer, unit: Hz-->
  </highPassFilter>
  <noiseMargin

opt="1000,660,657,653,650,647,643,640,637,633,-630,627,623,620,617,613,610,607,603,600,597,593,590,587,583,5
80,577,573,570,567,563,560,557,553,550,547,543,540,537,533,530,527,523,520,517,513,510,507,503,500,497,493,4
90,487,483,480,477,473,470,467,463,460,457,453,450,447,443,440,437,433,430,427,423,420,417,413,410,407,403,4
00,397,393,390,387,383,380,377,373,370,367,363,360,357,353,350,347,343,340,337,333,330,327,323,320,317,313,3
10,307,303,300,297,293,290,287,283,280,277,273,270,267,263,260,257,253,250,247,243,240" default="30">
   <!--req, xs:integer, unit: dB-->
  </noiseMargin>
  <AutoLimitWave>
   <!--dep, audioInputType-->
   <FBCEnable opt="true,false">
    <!--req, xs:Boolean-->
   </FBCEnable>
   <mode opt="fast,general,slow" default="general">
    <!--req, xs:string-->
   </mode>
   <filterQValue opt="40,10" default="40">
    <!--req, xs:integer-->
   </filterQValue>
   <staticFilterNum min="0" max="12" default="0">
    <!--req, xs:integer-->
   </staticFilterNum>
  </AutoLimitWave>
 </MixAudioIn>
 <AudioInVolumelist>
  <AudioInVlome>
   <type>
    <!--req, xs:string, "audioOutput,audioEncode"-->
   </type>
   <volume min="0" max="127" defalut="50">
    <!--req, xs:integer-->
   </volume>
  </AudioInVlome>
 </AudioInVolumelist>
</AudioInCap>

16.2.15 XML_AudioOut
AudioOut message in XML format
<AudioOut version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string--></id>
 <MixAudioOut>
  <enabled><!--req, xs:Boolean--></enabled>
  <modulatorEnbale><!--req, xs:Boolean--></modulatorEnbale>
  <postFilter><!--req, xs:Boolean--></postFilter>
  <limitPressure><!--req, xs:Boolean--></limitPressure>
  <modulatorValue><!--req, xs:integer--></modulatorValue>
  <triggerTime><!--req, xs:integer, unit: ms--></triggerTime>
  <freeTime><!--req, xs:integer, unit: ms--></freeTime>
  <compressThreshold><!--req, xs:integer--></compressThreshold>
  <compressMode><!--req, xs:string--></compressMode>

  <compressRate><!--req, xs:integer--></compressRate>
  <recoveryGain><!--req, xs:integer--></recoveryGain>
  <outputGain><!--req, xs:integer --></outputGain>
 </MixAudioOut>
 <AudioOutVolumelist>
  <AudioOutVlome>
   <type><!--req, xs:string, "audioOutput,audioDecode"--></type>
   <volume><!--req, xs:integer--></volume>
  </AudioOutVlome>
 </AudioOutVolumelist>
</AudioOut>

16.2.16 XML_AudioOutCap
AudioOutCap capability message in XML format
<AudioOutCap xmlns="http://wwwisapiorg/ver20/XMLSchema" version="2.0" >
 <id>
  <!--req, xs:string-->
 </id>
 <MixAudioOut>
  <enabled opt="true,false" >
   <!--req, xs:Boolean-->
  </enabled>
  <modulatorEnbale opt="true,false" >
   <!--req, xs:Boolean-->
  </modulatorEnbale>
  <postFilter opt="false,true" default="true" >
   <!--req, xs:Boolean-->
  </postFilter>
  <limitPressure opt="false,true" default="true" >
   <!--req, xs:Boolean-->
  </limitPressure>
  <modulatorValue min="0" max="127" default="10" >
   <!--req, xs:integer-->
  </modulatorValue>
  <triggerTime
opt="1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,6,6,6,7,7,7,8,8,8,9,9,10,
10,11,11,12,12,13,14,15,15,16,17,18,19,20,21,23,24,25,27,29,30,32,34,36,38,41,43,46,49,52,55,59,63,67,72,76,82,87,
93,10,17,114,123,132,141,152,163,175,188,23,218,235,254,274,296,320,347,375,47,441,479,520,566,616,671,731,79
8,872" default="4" >
   <!--req, xs:integer, unit: ms-->
  </triggerTime>
  <freeTime
opt="98,11,15,18,112,116,120,124,129,133,138,143,148,154,159,165,171,177,184,191,198,26,213,222,230,239,248,2
58,268,278,289,31,313,325,338,352,366,381,397,413,430,448,467,486,57,528,551,575,60,626,653,682,712,743,776,8
11,848,887,927,970,1014,1062,1111,1163,1218,1276,1337,142,1470,1541,1617,1697,1781,1870,1964,2063,2168,227
9,2397,2521,2653,2792,2940,3097,3263,3439,3626,3825,4035,4259,4497,4750,5020,536,5611,5936,6282,6651,7045,
7465,7914,8393,895,9452,10037,10664,11335,12053,12824,13650,14537,15489,16511,17610,18793,20065,21435,22
911,2452,26219,28073,30075,32239,34580,37114,39859,42834,46062" default="42" >
   <!--req, xs:integer, unit: ms-->

  </freeTime>
  <compressThreshold opt="1,2,4,8" defalut="2" >
   <!--req, xs:integer-->
  </compressThreshold>
  <compressMode opt="soft,hard" default="soft" >
   <!--req, xs:string-->
  </compressMode>
  <compressRate min="0" max="127" >
   <!--req, xs:integer-->
  </compressRate>
  <recoveryGain opt="1,2,4,8" defalut="2" >
   <!--req, xs:integer-->
  </recoveryGain>
  <outputGain
opt="100,421,361,325,30,281,265,252,240,230,221,212,25,198,192,186,180,175,170,165,161,156,152,148,145,141,1
38,134,131,128,125,122,120,117,114,112,110,17,15,13,10,98,96,94,92,90,88,86,85,83,81,79,78,76,74,73,71,70,68,67,
65,64,62,61,60,58,57,56,54,53,52,51,49,48,47,46,45,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,
23,22,21,20,19,18,17,17,16,15,14,13,12,12,11,10,9,9,8,7,6,6,5,4,3,3,2,1,1,0" >
   <!--req, xs:integer-->
  </outputGain>
 </MixAudioOut>
 <AudioOutVolumelist>
  <AudioOutVlome>
   <type>
    <!--req, xs:string, "audioOutput,audioEncode"-->
   </type>
   <volume min="0" max="127" defalut="50" >
    <!--req, xs:integer-->
   </volume>
  </AudioOutVlome>
 </AudioOutVolumelist>
</AudioOutCap>

16.2.17 XML_BadSectorsTest
BadSectorsTest message in XML format
<BadSectorsTest version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <testType><!--opt, xs: string, "full,metadata"--></testType>
</BadSectorsTest>

16.2.18 XML_BadSectorsTestStatus
BadSectorsTestStatus message in XML format
<BadSectorsTestStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <diskID><!--req, xs: string--></diskID>
 <MaskAreaList><!--req-->
  <MaskArea><!--list-->

   <maskAreaID><!--req, xs: integer--></maskAreaID>
   <startLBA><!--opt,xs:integer--></startLBA>
   <endLBA><!--opt, xs: integer--></endLBA>
  </MaskArea>
 </MaskAreaList>
 <BlockAreaTestStatus><!--opt-->
  <testType><!--opt, xs: string, "full,metadata"--></testType>
  <testStatus><!--req, xs: string, "none,running,pause,complete,exceed,abort"--></testStatus>
  <fistBlock><!--opt, xs: integer--></fistBlock>
  <lastBlock><!--opt, xs: integer--></lastBlock>
  <currentBlock><!--opt, xs: integer--></currentBlock>
  <BadSectorsList><!--opt-->
   <BadSectors><!--list-->
     <id><!--req, xs: integer--></id>
     <block><!--opt, xs: integer--></block>
   </BadSectors>
  </BadSectorsList>
 </BlockAreaTestStatus>
</BadSectorsTestStatus>

16.2.19 XML_BatteryPowerOverlay
BatteryPowerOverlay message in XML format
<BatteryPowerOverlay version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs:boolean--></enabled>
 <positionX><!--req, xs:integer, X-coordinate--></positionX>
 <positionY><!--req, xs:integer, Y-coordinate--></positionY>
</BatteryPowerOverlay>

16.2.20 XML_BLC
BLC message in XML format
<BLC version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <enabled/><!--req, xs: boolean-->
 <BLCMode/><!--opt, xs: string, BLC mode: "UP, DOWN, LEFT, RIGHT, CENTER, MULTI-AREA, Region"-->
 <BLCLevel><!--opt, xs: integer--></BLCLevel>
 <BLCRegionList><!--dep-->
  <BLCRegion>
   <id><!--req, xs: integer--></id>
   <RegionCoordinatesList/>
  </BLCRegion>
 </BLCRegionList>
</BLC>

16.2.21 XML_BluetoothCap
BluetoothCap capability message in XML format
<BluetoothCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <isSupportIbeacon>
  <!--opt, xs:boolean, whether to support configuring ibeacon bluetooth parameters-->
 </isSupportIbeacon>
</BluetoothCap>

16.2.22 XML_BluetoothStatus
BluetoothStatus message in XML format
<BluetoothStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <connectStatus><!--opt, xs:boolean--></connectStatus>
 <connectDeviceName><!--opt, xs:string--></connectDeviceName>
</BluetoothStatus>

16.2.23 XML_Bond
Bond message in XML format
<Bond version="2.0" xmlns="urn:selfextension:ISAPIext-ver10-xsd">
 <id>
  <!--req, xs:integer-->
 </id>
 <enabled>
  <!--req, xs:boolean-->
 </enabled>
 <workMode>
  <!--req, xs:string, working mode: "balance-rr"-round-robin, "active-backup"-->
 </workMode>
 <primaryIf>
  <!--req, xs:string, default route ID-->
 </primaryIf>
 <slaveIfList>
  <!--req-->
  <ethernetIfId>
   <!--req, xs:string, ID-->
  </ethernetIfId>
 </slaveIfList>
 <IPAddress>
  <ipVersion>
   <!--req, xs:string, "v4,v6,dual"-->
  </ipVersion>
  <addressingType>
   <!--req, xs:string, "static,dynamic,apipa"-->

  </addressingType>
  <ipAddress>
   <!--dep, xs:string-->
  </ipAddress>
  <subnetMask>
   <!--dep, xs:string, subnet mask for IPv4 address-->
  </subnetMask>
  <ipv6Address>
   <!--dep, xs:string-->
  </ipv6Address>
  <bitMask>
   <!--dep, xs:integer, bitmask for IPv6 address-->
  </bitMask>
  <DefaultGateway>
   <!--dep-->
   <ipAddress>
    <!--dep, xs:string-->
   </ipAddress>
   <ipv6Address>
    <!--dep, xs:string-->
   </ipv6Address>
  </DefaultGateway>
  <PrimaryDNS>
   <!--dep-->
   <ipAddress>
    <!--dep, xs:string-->
   </ipAddress>
   <ipv6Address>
    <!--dep, xs:string-->
   </ipv6Address>
  </PrimaryDNS>
  <SecondaryDNS>
   <!--dep-->
   <ipAddress>
    <!--dep, xs:string-->
   </ipAddress>
   <ipv6Address>
    <!--dep, xs:string-->
   </ipv6Address>
  </SecondaryDNS>
 </IPAddress>
</Bond>

16.2.24 XML_BondList
BondList message in XML format
<BondList version="2.0" xmlns="urn:selfextension:ISAPIext-ver10-xsd">
 <Bond/><!--see details in the message of XML_Bond-->
</BondList>

See Also
XML_Bond

16.2.25 XML_BurningPreventionCap
BurningPreventionCap message in XML format
<BurningPreventionCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled opt="rue,false"><!--req, xs:boolean--></enabled>
 <mode opt="manual,automatic"><!--opt, xs:string, mode: manual, automatic--></mode>
 <closedDuration min="5" max="60" default="10">
  <!--opt, xs:integer, closed status duration, unit: second-->
 </closedDuration>
 <shutterStatus opt="closed,open"><!--opt, xs:string, shutter status: closed, open--></shutterStatus>
 <protectionMode opt="lensMovement,shutterClose">
  <!--opt, xs:string, protection mode: lensMovement-lens movement, shutterClose-close shutter-->
 </protectionMode>
 <burningRecoveryEnabled opt="true,false">
  <!--opt, xs:boolean, enable burning recovery or not-->
 </burningRecoveryEnabled>
 <movementDuration min="" max="" default="">
  <!-- opt, xs:integer, duration of lens movement for burning protection, unit: minute-->
 </movementDuration>
</ BurningPreventionCap>

Remarks
• When protectionMode is "lensMovement", the node movementDuration is valid.
• When protectionMode is "shutterClose", the node closedDuration, shutterStatus, and
  burningRecoveryEnabled are valid.
• When mode is "automatic", the shutter is open, and cannot be configured.

16.2.26 XML_Cap_accessDeviceList
accessDeviceList capability message in XML format
<accessDeviceList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <accessDevice size="4">
  <id><!--req, xs:integer--></id>
  <MACAddress><!--opt, xs:string--></MACAddress>
  <ipV4Address><!--opt, xs:string--></ipV4Address>
  <accessTime><!--req, xs:time, ISO8601 data--></accessTime>
 </accessDevice>
</accessDeviceList>

16.2.27 XML_Cap_AcsUpdate
AcsUpdate capability message in XML format
<AcsUpdate version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <type
opt="cardReader,FPModule,securityModule,extendModule,channelController,IRModule,lampModule,elevatorControll
er,FPAlgorithmProgram,uboot,keypad,wirelessRecv,wiredZone">
   <!--opt, upgrading type: "cardReader"-card reader, "FPModule"-fingerprint module, "securityModule"-secure door
control unit, "extendModule"-(IO) extension module, "channelController"-lane controller, "IRModule"-IR module,
"lampModule"-indicator module, "elevatorController"-slave elevator controller, "FPAlgorithmProgram"-fingerprint
algorithm program of the card reader, "uboot", "keypad", "wirelessRecv"-wireless receiving module, "wiredZone"-
wired zone module-->
 </type>
 <cardReaderNo min="" max="">
   <!--opt, range of No. of the card reader, this node is valid only when <type> contains "cardReader"-->
 </cardReaderNo>
 <FPModuleNo min="" max="">
   <!--opt, range of No. of the fingerprint module, this node is valid only when <type> contains "FPModule"-->
 </FPModuleNo>
 <securityModuleNo min="" max="">
   <!--opt, range of No. of the secure door control module, this node is valid only when <type> contains
"securityModule"-->
 </securityModuleNo>
 <extendModuleNo min="" max="">
   <!--opt, range of No. of the (IO) extension module, this node is valid only when <type> contains "extendModule"-->
 </extendModuleNo>
 <channelControllerNo min="" max="">
   <!--opt, range of No. of the lane controller, this node is valid only when <type> contains "channelController"-->
 </channelControllerNo>
 <IRModuleNo min="" max="">
   <!--opt, range of No. of the IR module, this node is valid only when <type> contains "IRModule"-->
 </IRModuleNo>
 <lampModuleNo min="" max="">
   <!--opt, range of No. of the indicator module, this node is valid only when <type> contains "lampModule"-->
 </lampModuleNo>
 <elevatorControllerNo min="" max="">
   <!--opt,range of No. of the slave elevator controller, this node is valid only when <type> contains
"elevatorController"-->
 </elevatorControllerNo>
 <FPAlgorithmProgramNo min="" max="">
   <!--opt, range of No. of the fingerprint algorithm program of the card reader, this node is valid only when <type>
contains "FPAlgorithmProgram"-->
 </FPAlgorithmProgramNo>
 <keypadAddress opt="1,3,5">
   <!--opt, range of keypad module address, this node is valid when <type> contains "keypad"-->
 </keypadAddress>
 <wirelessRecvAddress opt="1,3,5">
   <!--opt, range of wireless receiving module address, this node is valid when <type> contains "wirelessRecv"-->
 </wirelessRecvAddress>
 <wiredZoneAddress opt="1,3,5">

  <!--opt, range of wired zone module address, this node is valid when <type> contains "wiredZone"-->
 </wiredZoneAddress>
</AcsUpdate>

16.2.28 XML_Cap_AdminAccessProtocolList
AdminAccessProtocol capability message in XML format
<AdminAccessProtocolList version="1.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <AdminAccessProtocol><!--multiple <AdminAccessProtocol> nodes are allowed-->
   <id><!--req, xs: string, ID--></id>
   <enabled opt="true,false"><!--opt, xs: boolean--></enabled>
   <protocol opt="HTTP,HTTPS,SDK,RTSP,DEV_MANAGE,WebSocket,WebSocketS,SDK_OVER_TLS,SRTP">
    <!--req, xs: string-->
   </protocol>
   <portNo min="2000" max="65535" default="8443"><!--req, xs:integer --></portNo>
   <redirectToHttps opt="true,false">
    <!--opt, xs: boolean, whether to automatically go to HTTPS when connecting to HTTP port and HTTPS is enabled-->
   </redirectToHttps>
   <streamOverTls opt="true,false">
    <!--opt, xs: boolean, whether to enable TLS link encryption when the streaming mode is SDK_OVER_TLS, true-yes,
false-no-->
   </streamOverTls>
 </AdminAccessProtocol>
 <TLS1_0Enable opt="true,false">
   <!--dep, xs: boolean, whether to enable TLS version 1.0, it is valid when protocol is "HTTPS", "true"-yes, "false"-no-->
 </TLS1_0Enable>
 <TLS1_1Enable opt="true,false">
   <!--dep, xs: boolean, whether to enable TLS version 1.1, it is valid when protocol is "HTTPS", "true"-yes, "false"-no-->
 </TLS1_1Enable>
 <TLS1_2Enable opt="true,false">
   <!--dep, xs: boolean, whether to enable TLS version 1.2, it is valid when protocol is "HTTPS", "true"-yes, "false"-no-->
 </TLS1_2Enable>
</AdminAccessProtocolList>

16.2.29 XML_Cap_BatteryPowerOverlay
BatteryPowerOverlay capability message in XML format
<BatteryPowerOverlay version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled>
  <!--req, xs:boolean-->
 </enabled>
 <positionX>
  <!--req, xs:integer, X-coordinate-->
 </positionX>
 <positionY>
  <!--req, xs:integer, Y-coordinate-->

 </positionY>
</BatteryPowerOverlay>

16.2.30 XML_Cap_Color
Color capability message in XML format
<?xml version="1.0" encoding="utf-8"?>
<Color version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <brightnessLevel min="" max=""><!--opt,xs:integer, brightness--></brightnessLevel>
 <contrastLevel min="" max=""><!--opt,xs:integer, contrast--></contrastLevel>
 <saturationLevel min="" max=""><!--opt,xs:integer, saturation--></saturationLevel>
 <hueLevel min="" max=""><!--opt, xs:integer, hue--></hueLevel>
 <grayScale><!--opt, gray scale-->
  <grayScaleMode><!--opt,xs:string, gray scale mode: "indoor,outdoor"--></grayScaleMode>
 </grayScale>
 <nightMode opt="true,false">
  <!--opt, xs:boolean, enable night mode, when its value is "true", the saturation can be adjusted, otherwise, the
saturation cannot be adjusted-->
 </nightMode>
</Color>

16.2.31 XML_Cap_DatetimeOverlay
DatetimeOverlay capability message in XML format
<DateTimeOverlay version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled>
  <!--req, xs:boolean, whether to enable date and time overlay-->
 </enabled>
 <positionX min="0" max="1000">
  <!--req, xs:integer, X-coordinate-->
 </positionX>
 <positionY min="0" max="1000">
  <!--req, xs:integer, Y-coordinate-->
 </positionY>
 <dateStyle>
  <!--opt, xs:string, date format: "YYYY-MM-DD, MM-DD-YYYY, DD-MM-YYYY, CHR-YYYY-MM-DD, CHR-MM-DD-YYYY,
CHR-DD-MM-YYYY"-->
 </dateStyle>
 <timeStyle>
  <!--opt, xs:string, "12hour, 24hour"-->
 </timeStyle>
 <displayWeek>
  <!--opt, xs:boolean, whether to display week information-->
 </displayWeek>
 <displayMilliSecond>
  <!--opt, xs:boolean, whether to display millisecond-->

 </displayMilliSecond>
</DateTimeOverlay>

16.2.32 XML_Cap_DDNS
DDNS capability message in XML format
<DDNS version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id>
  <!--req, xs: string-->
 </id>
 <enabled>
  <!--req, xs:boolean, "true,false"-->
 </enabled>
 <ethernetIfId opt="1,2,3…">
  <!--opt, xs:string, ID-->
 </ethernetIfId>
 <provider opt="IPServer,DynDNS,PeanutHall,NO-IP, HiDDNS">
  <!--req, xs:string-->
 </provider>
 <serverAddress>
  <addressingFormatType opt="ipaddress,hostname">
   <!--req, xs:string-->
  </addressingFormatType>
  <hostname min="0" max="260">
   <!--dep, xs:string-->
  </hostName>
  <ipAddress min="0" max="64">
   <!--dep, xs:string-->
  </ipAddress>
  <ipv6Address min="0" max="64">
   <!--dep, xs:string-->
  </ipv6Address>
 </serverAddress>
 <portNo min="0" max="65535">
  <!--opt, xs:integer-->
 </portNo>
 <deviceDomainName min="0" max="64">
  <!--dep, xs:string-->
 </deviceDomainName>
 <username min="0" max="32">
  <!--dep, xs:string-->
 </userName>
 <password min="0" max="16">
  <!--wo, dep, xs:string-->
 </password>
</DDNS>

16.2.33 XML_Cap_DeviceInfo
DeviceInfo capability message in XML format
<DeviceInfo version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <deviceName min="" max="">
  <!--req, xs:string, device name-->
 </deviceName>
 <languageType opt="chinese,english,spanish,portuguese,italian,french,russian,german,polish"/><!--opt, xs:string-->
 <deviceID min="0" max="128">
  <!--ro, req, xs:string, uuid-->
 </deviceID>
 <deviceDescription min="0" max="16">
  <!--opt, xs:string-->
 </deviceDescription>
 <deviceLocation opt="STD-CGI, hangzhou">
  <!--opt, xs:string-->
 </deviceLocation>
 <systemContact opt="STD-CGI, Hikvision.China">
  <!--opt, req, xs:string-->
 </systemContact>
 <model min="0" max="64">
  <!--ro, req, xs:string-->
 </model>
 <serialNumber min="0" max="48">
  <!--ro, req, xs:string-->
 </serialNumber>
 <macAddress min="0" max="64">
  <!--ro, req, xs:string-->
 </macAddress>
 <firmwareVersion min="0" max="64">
  <!--ro, req, xs:string-->
 </firmwareVersion>
 <firmwareReleasedDate min="0" max="64">
  <!--ro, opt, xs:string-->
 </firmwareReleasedDate>
 <bootVersion min="0" max="16">
  <!--ro, opt, xs:string-->
 </bootVersion>
 <bootReleasedDate min="0" max="16">
  <!--ro, opt, xs:string-->
 </bootReleasedDate>
 <hardwareVersion min="0" max="16">
  <!--ro, opt, xs:string-->
 </hardwareVersion>
 <encoderVersion min="0" max="64">
  <!--ro, opt, xs:string-->
 </encoderVersion>
 <encoderReleasedDate min="0" max="64">
  <!--ro, opt, xs:stirng-->
 </encoderReleasedDate>

 <decoderVersion min="0" max="64">
  <!--ro, opt, xs:string-->
 </decoderVersion>
 <decoderReleasedDate min="0" max="64">
  <!--ro, opt, xs:stirng-->
 </decoderReleasedDate>
 <deviceType opt="IPCamera, IPDome, DVR, HybirdNVR, NVR, DVS, IPZoom">
  <!--ro, req, xs:string-->
 </deviceType>
 <telecontrolID min="1" max="255">
  <!--opt, xs:integer, "1-255"-->
 </telecontrolID>
 <supportBeep>
  <!--opt, xs:boolean: "true,false"-->
 </supportBeep>
 <firmwareVersionInfo>
  <!--ro, opt, xs:stirng-->
 </firmwareVersionInfo>
 <subChannelEnabled>
  <!--opt, xs:boolean: "true,false"-->
 </subChannelEnabled>
 <thrChannelEnabled>
  <!--opt, xs:boolean: "true,false"-->
 </thrChannelEnabled>
 <actualFloorNum>
  <!--req, xs:integer, "1-128"-->
 </actualFloorNum>
 <radarVersion>
  <!--opt, xs:string, radar version-->
 </radarVersion>
 <powerOnMode opt="button,adapter" def="button">
  <!--optional, xs:string, device startup mode: "button"-press button to power on (default), "adapter"-connect
adapter to power on-->
 </powerOnMode>
</DeviceInfo>

16.2.34 XML_Cap_DefaultParam
DefaultParam capability message in XML format
<DefaultParam version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <DialNum min="1" max="32"><!--opt, xs:string--></DialNum>
 <Username min="1" max="32"><!--opt, xs:string--></Username>
 <Password min="1" max="32"><!--opt, xs:string--></Password>
 <APNname min="1" max="32"><!--opt, xs:string--></APNname>
 <VerifyProto opt="auto,CHAP,PAP"><!--req, xs:string, verification protocol: "auto, CHAP, PAP"--></VerifyProto>
</DefaultParam>

16.2.35 XML_Cap_Dial
Dial capability message in XML format
<Dial version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled opt="true,false" def="false"><!--req, xs:boolean--></enabled>
 <DialMethod opt="auto,manual"><!--req, xs:string, "auto, manual"--></DialMethod>
 <SwitchMethod opt="auto,4GFirst,3GFirst,manualto2G,manualto3G,manualto4G,cableFirst">
  <!--req, xs:string, "auto,4GFirst,3GFirst, manualto2G, manualto3G,manualto4G,cableFirst"-->
 </SwitchMethod>
 <OfflineTime min="30" max="65535"><!--opt, xs:integer, unit: second--></OfflineTime>
 <UIMCardNum min="1" max="32"><!--opt, xs:string--></UIMCardNum>
 <DialNum min="1" max="32"><!--opt, xs:string--></DialNum>
 <Username min="1" max="32"><!--opt, xs:string--></Username>
 <Password min="1" max="32"><!--opt, xs:string--></Password>
 <APNname min="1" max="32"><!--opt, xs:string--></APNname>
 <SIMNum min="" max=""><!--opt, xs:string, SIM card No. (mobile phone number)--></SIMNum>
 <MTU min="100" max="1500"><!--opt, xs: integer--></MTU>
 <VerifyProto opt="auto,CHAP,PAP"><!--req, xs:string, verification protocol: "auto, CHAP, PAP"--></VerifyProto>
 <DefaultParam/><!--opt, default parameters, see details in the message of XML_Cap_DefaultParam-->
 <netAPN min="" max=""/><!--opt, xs:string, APN configuration for the private network-->
 <Flow><!--opt, flow configuration-->
  <limitEnabled opt="true,false"><!--opt, xs:boolean, whether to enable flow limitation--></limitEnabled>
  <consumeFlow opt="true,false"><!--opt, xs:boolean, whether supports displaying flow usage, unit: MB--></
consumeFlow>
  <threshold min="" max=""><!--opt, threshold of flow, unit: MB--></threshold>
 </Flow>
</Dial>

See Also
XML_Cap_DefaultParam

16.2.36 XML_Cap_Discovery
Discovery capability message in XML format
<Discovery version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <UPnP><!--req-->
  <enabled><!--req, xs:boolean, "true, false"--></enalbed>
 </UPnP>
 <ZeroConf><!--opt, channel-zero configuration-->
  <enabled><!--req, xs:boolean, "true, false"--></enabled>
 </ZeroConf>
</Discovery>

16.2.37 XML_Cap_EagleFocusing
EagleFocusing capability message in XML format
<?xml version="1.0" encoding="utf-8"?>
<EagleFocusing version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  <id><!--req,xs:string--></id>
  <enabled opt="true,false"><!--req, xs:boolean, "true"-start calibration, "false"-stop calibration--></enabled>
  <normalizedScreenSize><!--req,ro-->
   <normalizedScreenWidth><!--req,ro,xs:integer--></normalizedScreenWidth>
   <normalizedScreenHeight><!--req,ro,xs:integer--></normalizedScreenHeight>
  </normalizedScreenSize>
  <EagleFocusingRegionList><!--opt-->
   <EagleFocusingRegion><!--list-->
    <id><!--req, xs:string--></id>
    <sid><!--opt,xs:string, scene ID--></sid>
    <rate><!--opt,xs:integer, rate--></rate>
    <spotNum><!--opt,xs:integer, the number of calibration points--></spotNum>
    <type><!--req,xs:string,"line", region type, now only supports "line"--></type>
    <Region><!--dep, depends on type-->
      <RegionCoordinatesList size="4"><!--opt-->
       <RegionCoordinates><!--list-->
        <positionX><!--req,xs:integer,coordinate--></positionX>
        <positionY><!--req,xs:integer,coordinate--></positionY>
       </RegionCoordinates>
      </RegionCoordinatesList>
    </Region>
   </EagleFocusingRegion>
  </EagleFocusingRegionList>
  <sceneNum min="" max=""><!--opt,xs:integer, the maximum number of supported scenes--></sceneNum>
  <isSupportSceneGoto opt="true,false"><!--opt,xs:boolean, whether device supports turning to specified scene--></
isSupportSceneGoto>
  <rate min="" max=""><!--opt,xs:integer, rate--></rate>
  <spotNum min="" max=""><!--opt,xs:integer, the number of calibration points on line--></spotNum>
  <onlyReadParam opt="rate,spotNum"><!--opt,xs:string,"rate,spotNum"--></onlyReadParam>
  <isSupportAuto opt="true,false"><!--req,xs:boolean, whether device supports automatic calibration of rapid focus--
></isSupportAuto>
</EagleFocusing>

16.2.38 XML_Cap_EHome
EHome capability message in XML format
<Ehome version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id min="1" max="1"><!--opt, xs:string, EHome center ID--></id>
 <GPRSAddressingFormatType opt="ipaddress"><!--opt, xs:string, GPRS address type. If this node is not returned, the
address type will be determined by addressingFormatType which indicates that the address types configured by
different networks do not need to be distinguished--></GPRSAddressingFormatType>
 <addressingFormatType opt="ipaddress,hostname"><!--req, xs:string--></addressingFormatType>

 <hostName min="" max=""><!--dep, xs:string, domain name--></hostName>
 <ipAddress min="" max=""><!--dep, xs:string--></ipAddress>
 <ipv6Address min="" max=""><!--dep, xs:string--></ipv6Address>
 <portNo min="" max=""><!--opt, xs:integer--></portNo>
 <deviceID min="" max=""><!--req, xs:string--></deviceID>
 <registerStatus min="" max=""><!--ro, xs:boolean--></registerStatus>
 <key min="" max=""><!--opt, xs:string, EHome encryption key--></key>
 <version min="" max=""><!--ro, xs:string--></version>
 <netWork opt="0,1,2,3,4"/><!--opt,xs:integer, 0-make no sense, 1-automatic, 2-wired network preferred, 3-wired
network, 4-3G/4G/GPRS-->
 <voiceDeviceType opt="bluetooth,client"><!--opt, xs:string, two-way audio device type: "bluetooth", "client"--></
voiceDeviceType>
 <protocolVersion opt="v2.0,v2.6,v4.0,v5.0"><!--opt, xs:string, protocol type. If this node is set to "v2.0", the device
can only use protocol v2.0 to register; if this node is set to "v2.6", "v4.0" or "v5.0", the device will firstly use this
protocol to register. If this node is not returned, the protocol version will be determined by <version>--></
protocolVersion>
</Ehome>

16.2.39 XML_Cap_ExtraInfo
ExtraInfo capability message in XML format
<ExtraInfo version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <diskMode opt="singleDisk,RAID"><!--req, xs:string, disk mode: "singleDisk"-single disk, "RAID". The device needs to
reboot after changing the disk mode--></diskMode>
</ExtraInfo>

16.2.40 XML_Cap_FocusConfiguration
FocusConfiguration capability message in XML format
<FocusConfiguration>
 <focusStyle opt="AUTO,MANUAL,SEMIAUTOMATIC"><!--req, xs:string--></focusStyle>
 <focusLimited opt="50,100,300,600,1000,2000,5000,10000,15000" def="1000"><!--opt, xs:integer--></focusLimited>
 <focusPosition/><!--dep, xs:integer, depends on FocusStyle-->
 <focusSpeed><!--opt, xs:intger--></focusSpeed>
 <focusSensitivity min="0" max="2" def="1"><!--opt, xs:intger, sensitivity of focus, ranging from 0 to 2. It is valid when
the focus mode is automatic or semi-automatic--></focusSensitivity>
 <temperatureChangeAdaptEnabled opt="true,false"--><!--opt, xs:boolean--></temperatureChangeAdaptEnabled>
 <relativeFocusPos min="0" max="4000" def=""><!--opt, xs:intger--></relativeFocusPos>
 <highTemperaturePriority opt="true,false"><!--opt, xs:boolean, enable high temperature priority mode--></
highTemperaturePriority>
</FocusConfiguration>

16.2.41 XML_Cap_FTPNotification
FTPNotification capability message in XML format

<FTPNotification version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id>
   <!--req, xs:string, FTP ID-->
 </id>
 <enabled>
   <!--req, xs:boolean, whether to enable the FTP server-->
 </enabled>
 <useSSL>
   <!--opt, xs:boolean-->
 </useSSL>
 <addressingFormatType opt="ipaddress,hostname">
   <!--req, xs:string, this node can only be set to "ipaddress"-->
 </addressingFormatType>
 <hostName>
   <!--dep, xs:string-->
 </hostName>
 <ipAddress>
   <!--dep, xs:string-->
 </ipAddress>
 <ipv6Address>
   <!--dep, xs:string-->
 </ipv6Address>
 <portNo>
   <!--opt, xs:integer, FTP port No.-->
 </portNo>
 <userName>
   <!--req, xs:string, user name-->
 </userName>
 <password>
   <!--wo, xs:string, password-->
 </password>
 <passiveModeEnabled>
   <!--opt, xs:boolean-->
 </passiveModeEnabled>
 <annoyftp>
   <!--opt, xs:boolean-->
 </annoyftp>
 <uploadPicture>
   <!--opt, xs:boolean-->
 </uploadPicture>
 <uploadVideoClip>
   <!--opt, xs:boolean-->
 </uploadVideoClip>
 <uploadPath>
   <!--req-->
   <pathDepth>
    <!--req, xs:integer, directory levels, up to 16 levels can be supported-->
   </pathDepth>
   <topDirNameRule opt="none, devName, devId, devIp, positionInfo, time_month, time_date, illegalType, direction,
site, chanName, chanId, laneId, customize ,time, buildUnitNo">
    <!--dep, xs:string, parent directory name: "none", "devName"-device name, "devId"-device ID, "devIp"-device IP
address, "positionInfo"-camera 1, "time_month"-usage date (YYYY-MM), "time_date"-usage date (YYYY-MM-DD),

"illegalType"-violation type, "direction"-direction, "site"-place, "chanName"-channel name, "chanId"-channel No.,
"laneId"-lane No., "customize"-custom, "time", "buildUnitNo"-building No. and unit No. This node is set to NULL by
default-->
   </topDirNameRule>
   <topDirName min="" max="">
     <!--dep, xs:string, custom string for parent directory, the maximum string length is 32 bytes. This node is valid
when <topDirNameRule> is "customize". If attributes of "min" and "max" are not obtained after parsing, the default
value will be returned without error message-->
   <topDirName/><!--dep, xs:string, custom string for parent directory, the maximum string length is 32 bytes. This
node is valid when <topDirNameRule> is "customize"-->
   <subDirNameRule opt="none, devName, devId, devIp, positionInfo, time_month, time_date, illegalType, direction,
site, chanName, chanId, laneId, customize ,time, buildUnitNo">
     <!--dep, xs:string, child directory name-->
   </subDirNameRule>
   <subDirName min="" max="">
     <!--dep, xs:string, custom string for child directory, the maximum string length is 32 bytes. This node is valid when
<subDirNameRule> is "customize". If attributes of "min" and "max" are not obtained after parsing, the default value
will be returned without error message-->
   <subDirName/><!--dep, xs:string, custom string for child directory, the maximum string length is 32 bytes. This node
is valid when <subDirNameRule> is "customize"-->
   <threeDirNameRule opt="none, devName, devId, devIp, positionInfo, time_month, time_date, illegalType, direction,
site, chanName, chanId, laneId, customize ,time, buildUnitNo">
     <!--dep, xs:string, the third directory name-->
   </threeDirNameRule>
   <threeDirName/><!--req, xs:string, custom string for the third directory, the maximum string length is 32 bytes. This
node is valid when <threeDirNameRule> is "customize"-->
   <fourDirNameRule opt="none, devName, devId, devIp, positionInfo, time_month, time_date, illegalType, direction,
site, chanName, chanId, laneId, customize ,time, buildUnitNo">
     <!--dep, xs:string, the fourth directory name-->
   </fourDirNameRule>
   <fourDirName/><!--req, xs:string, custom string for the fourth directory, the maximum string length is 32 bytes. This
node is valid when <fourDirNameRule> is "customize"-->
  </uploadPath>
  <picArchivingInterval min="" max="">
   <!--opt, xs:integer, the value is between 1 and 30, 0-close-->
  </picArchivingInterval>
  <picNameRuleType opt="default,prefix">
   <!--opt, xs:string-->
  </picNameRuleType>
  <picNamePrefix min="0" max="32">
   <!--dep, xs:string-->
  </picNamePrefix>
  <ftpPicNameRuleType opt="videoIntercom,ITC">
   <!--req, xs:string, type of FTP picture name rule: "videoIntercom"-rule used by video intercom products, "ITC"-rule
used by traffic cameras-->
  </ftpPicNameRuleType>
  <FTPPicNameRule>
   <!--dep, picture name rule of a specific FTP-->
   <ItemList/><!--req, see details in the message of XML_Cap_ItemList-->
   <delimiter>
     <!--req, xs:string, delimiter, which is a single character and the default value is "_"-->
   </delimiter>

  <customStr min="1" max="128">
    <!--req, xs:string, custom string-->
  </customStr>
 </FTPPicNameRule>
 <upDataType opt="0,1,2">
  <!-- opt, xs:integer, picture uploading type: 0-all, 1-checkpoint, 2-violation. When only one FTP server is enabled,
this node can only be set to 0. When two FTP servers are both enabled, you should set 1 for one FTP server and set 2
for another FTP server, which means that two FTP servers cannot be set to the same type-->
 </upDataType>
 <uploadPlateEnable>
  <!--opt, xs:boolean, whether to enable uploading license plate thumbnail-->
 </uploadPlateEnable>
 <site min="1" max="128">
  <!--req, xs:string, place, the maximum string length is 128 bytes-->
 </site>
 <roadNum min="1" max="32">
  <!--req, xs:string, intersection No., the maximum string length is 32 bytes-->
 </roadNum>
 <instrumentNum min="1" max="32">
  <!--req, xs:string, device No., the maximum string length is 32 bytes-->
 </instrumentNum>
 <direction min="1" max="32">
  <!--req, xs:string, direction No., the maximum string length is 32 bytes-->
 </direction>
 <directionDesc min="1" max="32">
  <!--req, xs:string, direction description, the maximum string length is 32 bytes-->
 </directionDesc>
 <monitoringInfo1 min="1" max="44">
  <!--req, xs:string, camera 1 information, the maximum string length is 44 bytes-->
 </monitoringInfo1>
 <uploadAttachedInfomation>
  <!--req, xs:boolean, whether to upload additional information-->
 </uploadAttachedInfomation>
 <BrokenNetHttp><!--opt, whether it supports ANR (automatic network replenishment)-->
  <enabled opt="true,false"><!--opt, xs:boolean, whether to enable ANR (automatic network replenishment)--></
enabled>
  <supportEventType opt="personQueueCounting"/><!--opt, xs:string, event types supporting FTP ANR:
"personQueueCounting"-person queue counting detection, "personQueueTime"-person queue time detection,
"personQueueRealTimeData"-upload real-time data of person queue counting detection, "faceCapture"-face capture
and recognition, "fieldDetection"-intrusion, "attendedBaggage"-object removal, "unattendedBaggage"-unattended
baggage, "regionExiting"-region exiting, "regionEntrance"-region entrance, "lineDetection"-line crossing detection-->
 </BrokenNetHttp>
</FTPNotification>

See Also
XML_Cap_ItemList

16.2.42 XML_Cap_FTPNotificationList
FTPNotificationList capability message in XML format

<FTPNotificationList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <FTPNotification/><!--opt, see details in the message of XML_Cap_FTPNotification-->
</FTPNotificationList>

See Also
XML_Cap_FTPNotification

16.2.43 XML_Cap_GuardAgainstTheft
GuardAgainstTheft capability message in XML format
<GuardAgainstTheft version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled opt="true,false"><!--required, xs:boolean, whether it supports enabling device anti-theft--></enabled>
 <SMSEnabled opt="true,false"><!--required, xs:boolean, whether it supports enabling SMS--></SMSEnabled>
 <phoneNum min="0" max="32"><!--dependency, xs:string, phone No.--></phoneNum>
 <longitudeLatitudeEnabled opt="true,false"><!--dependency, xs:boolean, whether it supports enabling longitude and
latitude--></longitudeLatitudeEnabled>
 <siteLocationEnabled opt="true,false"><!--dependency, xs:boolean, whether it supports enabling site location--></
siteLocationEnabled>
 <siteLocationInfo min="0" max="128"><!--dependency, xs:string, site location information--></siteLocationInfo>
 <timeEnabled opt="true,false"><!--dependency, xs:boolean, whether it supports enabling time--></timeEnabled>
 <customInfo min="0" max="128"><!--dependency, xs:string, custom information--></customInfo>
</GuardAgainstTheft>

16.2.44 XML_Cap_HardwareService
HardwareService capability message in XML format
<HardwareService version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IrLightSwitch><!--opt-->
  <mode opt="open,close"><!--req, xs:string --></mode>
 </IrLightSwitch>
 <ABF><!--opt-->
  <enabled><!--req, xs:boolean --></enabled>
 </ABF>
 <LED><!--opt-->
  <enabled><!--req, xs:boolean --></enabled>
 </LED>
 <Defog><!--opt-->
  <enabled><!--req, xs:boolean --></enabled>
 </Defog>
 <SupplementLight><!--opt-->
  <enabled><!--req, xs:boolean --></enabled>
  <isSupportFireLaserLight opt="true,false"><!--opt,xs:boolen--></isSupportFireLaserLight>
  <isSupportSupplementLightWord opt="true,false"><!--opt,xs:boolen--></isSupportSupplementLightWord>
  <captureWithSupplimentLightEnabled opt="true,false">
   <!--opt, xs:boolean, enable snapshot supplement light or not-->
  </captureWithSupplimentLightEnabled>

 </SupplementLight>
 <Deicing><!--opt-->
  <enabled><!--req, xs:boolean --></enabled>
 </Deicing>
 <ManualDeicing><!--opt-->
  <enabled><!--req, xs:boolean --></enabled>
 </ManualDeicing>
 <mutexAbility opt="laserLight, deicing">
  <!--req, mutual exclusion ability, the laser light and deicing (including manual deicing and automatic deicing) are
mutual exclusive-->
 </mutexAbility>
 <HighTemperatureProtection><!--opt-->
  <enabled><!--req, xs:boolean --></enabled>
  <temperatureType opt="90,100,110" def="90"><!--dep, xs:string,unit:℃ --></temperatureType>
 </HighTemperatureProtection>
</HardwareService>

16.2.45 XML_Cap_hddList
hddList capability message in XML format
<hddList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema" size="">
 <hdd><!--list-->
  <id><!--ro, req, xs: string; ID--></id>
  <hddName><!--ro, req, xs: string--></hddName>
  <hddPath><!--ro, opt, xs: string--></hddPath>
  <hddType opt="IDE,SATA,eSATA,NFS,iSCSI,Virtual Disk"><!--ro, req, xs: string--></hddType>
  <status
opt="ok,unformatted,error,idle,mismatch,offline,smartFailed,reparing,formating,notexist,unRecordHostFormatted">
   <!--ro, req, xs: string, unRecordHostFormatted--unformatted in education sharing system-->
  </status>
  <capacity><!--ro, req, xs: float, unit: MB--></capacity>
  <freeSpace><!--ro, req, xs: float, unit: MB--></freeSpace>
  <property opt="RW,RO,Redund"><!--req, xs: string, HDD properties--></property>
  <group><!--opt, xs: string; HDD group ID--></group>
  <DataModeList><!--opt, ro, current HDD allocation mode-->
   <DataMode>
    <type opt="recordStorage,pictureCloudStorage,fileStorage">
     <!--req, xs: string, storage application type, recordStorage-video storage, pictureCloudStorage-picture to be
saved in cloud storage, fileStorage-file-storage->
    </type>
    <occupancyRate><!--req, xs: integer, HDD usage, range: [0,100]--></occupancyRate>
   </DataMode>
  </DataModeList>
  <formatType opt="FAT32,EXT4" def="FAT32">
   <!--ro, opt, xs: string, formatting type, this node is only available for SD card; if this node does not exist, the default
formatting type is FAT32-->
  </formatType>
  <Encryption>
   <passwordLen min="6" max="64"/>
   <encryptionStatus opt="unencrypted,encrypted,verfyFailed"><!--ro, opt, xs:string, encryption status:

"unencrypted", "encrypted", "verfyFailed"-verification failed--></encryptionStatus>
   <encryptFormatType opt="FAT32,EXT4"><!--ro, opt, xs:string--></encryptFormatType>
  </Encryption>
 </hdd>
</hddList>

16.2.46 XML_Cap_IbeaconParam
IbeaconParam capability message in XML format
<IbeaconParam version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <UUID min="" max="">
  <!--req, xs:string, parking lot ID, which supports using digits, letters and hyphen as the tag-->
 </UUID>
 <major min="" max="">
  <!--req, xs:integer, number of floors in the parking lot, which cannot be 0x00 for all-->
 </major>
 <minor min="" max="">
  <!--req, xs:integer, number of parking spaces on each floor, which cannot be 0x00 for all-->
 </minor>
 <sendPower min="" max="">
  <!--req, xs:integer, transmitted power: 01-0 dbm, 02- -6 dbm, 03- -23 dbm-->
 </sendPower>
 <frequency min="" max="">
  <!--req, xs:integer, transmitted frequency, which is the broadcast time interval, unit: 625 µs. The broadcast time
interval is between 32 (20 ms) to 8000 (5s), and the default value is 160 (100 ms)-->
 </frequency>
 <measurePower min="" max="">
  <!--req, xs:integer, rated power, which is the RSSI (Received Signal Strength Indication) in the position of 1 meter
away, unit: dbm-->
 </measurePower>
</IbeaconParam>

16.2.47 XML_Cap_IEEE802_1x
IEEE802_1x capability message in XML format
<IEEE802_1x version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs: boolean--></enabled>
 <authenticationProtocolType opt="EAP-TLS,EAP-TTLS,EAP-PEAP,EAP-LEAP,EAP-FAST,EAP-MD5">
  <!--req, xs: string-->
 </authenticationProtocolType>
 <innerTTLSAuthenticationMethod opt="MS-CHAP,MS-CHAPv2,PAP,EAP-MD5">
  <!--dep, xs: string, this node is required when <authenticationProtocolType> is "EAP-TLS"-->
 </innerTTLSAuthenticationMethod>
 <innerEAPProtocolType opt= "EAP-POTP,MS-CHAPv2">
  <!--dep, xs: string, this node is required when <authenticationProtocolType> is "EAP-PEAP" or "EAP-FAST"-->
 </innerEAPProtocolType>
 <validateServerEnabled><!--dep, xs: boolean--></validateServerEnabled>

 <userName><!--dep, xs: string--></userName>
 <password><!--dep, xs: string--></password>
 <anonymousID><!--opt, xs: string--></anonymousID>
 <autoPACProvisioningEnabled>
  <!--dep, xs: boolean, this node is required when <authenticationProtocolType> is "EAP-FAST"-->
 </autoPACProvisioningEnabled>
 <Extensions><!--opt-->
  <EAPOLVersion><!--opt, xs: string, "1, 2"--></EAPOLVersion>
 </Extensions>
</IEEE802_1x>

16.2.48 XML_Cap_ImageChannel
ImageChannel capability message in XML format
<ImageChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:integer--></id>
 <enabled><!--req, xs:boolean--></enabled>
 <videoInputID><!--req, xs:integer--></videoInputID>
 <Focusconfiguration/><!--opt-->
 <LensInitialization/><!--opt-->
 <ImageFlip/><!--opt-->
 <ImageFreeze/><!--opt-->
 <proportionalpan/><!--opt-->
 <WDR/><!--opt-->
 <BLC/><!--opt-->
 <NoiseReduce/><!--opt-->
 <ImageEnhancement/><!--opt-->
 <SlowShutter/><!--opt-->
 <DSS/><!--opt-->
 <WhiteBlance/><!--opt-->
 <Exposure/><!--opt, exposure configuration parameters, refer to the message XML_Exposure for details-->
 <DayNightGate/><!--opt-->
 <BrightEnhance/><!--opt-->
 <Sharpness/><!--opt-->
 <gammaCorrection/><!--opt-->
 <powerLineFrequency/><!--opt-->
 <Color/><!--opt, image adjustment capability, refer to the message XML_Cap_Color for details-->
 <IrcutFilter/><!--opt, configuration parameters of day/night auto-switch, refer to the message XML_IrcutFilter for
details-->
 <Scene/><!--opt-->
 <EPTZ/ ><!--opt-->
 <EIS/><!--opt-->
 <HLC/> <!--opt-->
 <ZoomLimit/> <!--opt-->
 <corridor/><!--opt-->
 <Dehaze/><!--opt-->
 <ImageMode opt="standard, indoor, outdoor, dimLight"/><!--opt, xs:string-->
 <enableImageLossDetection><!--opt, boolean--></enableImageLossDetection>
 <CaptureMode/><!--opt-->
 <IrLight/><!--opt-->

  <LensDistortionCorrection/><!--opt-->
  <SupplementLight/><!--opt, supplement light configuration capability, refer to the message
XML_Cap_SupplementLight for details-->
  <OpticalDehaze/><!--opt-->
  <ManualRanging/><!--opt-->
  <OIS/><!--opt-->
  <isSupportlaserSpotManual><!--opt, boolean--></isSupportlaserSpotManual>
  <isSupportLaserSpotAdjustment><!--opt, boolean--></isSupportLaserSpotAdjustment>
  <DigitalZoom>
   <ZoomRatio opt="1x,2x,4x,8x,16x,32x"><!--req, xs:string---></ZoomRatio>
  </DigitalZoom>
  <Palettes/><!--opt-->
  <ExposureSync opt="true,false" def="false">
   <enabled><!--req, xs:boolean--></enabled>
  </ExposureSync>
  <BrightnessSuddenChangeSuppressionCap/><!--opt-->
  <isSupportIcr><!--opt, boolean--></isSupportIcr>
  <isSupportMultishut><!--opt, boolean--></isSupportMultishut>
  <isSupportPlateBright><!--opt, boolean--></isSupportPlateBright>
  <isSupportJPEGParam><!--opt, boolean--></isSupportJPEGParam>
  <isSupportDarkEnhance><!--opt, boolean--></isSupportDarkEnhance>
  <isSupportHdr><!--opt, boolean--></isSupportHdr>
  <isSupportLse><!--opt, boolean--></isSupportLse>
  <isSupportMce><!--opt, boolean--></isSupportMce>
  <isSupportScve><!--opt, boolean--></isSupportScve>
  <isSupportSectionCtrl><!--opt, boolean--></isSupportSectionCtrl>
  <isSupportAutoContrast><!--opt, boolean--></isSupportAutoContrast>
  <isSupportGrayRange><!--opt, boolean--></isSupportGrayRange>
  <isSupportLSEDetail><!--opt, boolean--></isSupportLSEDetail>
  <isSupportCapture><!--opt, boolean--></isSupportCapture>
  <isSupportBrightEnhance><!--opt, boolean--></isSupportBrightEnhance>
  <isSupportRecord><!--opt, xs:boolean--></isSupportRecord>
  <isSupportDefog><!--opt, xs:boolean--></isSupportDefog>
  <isSupportGeneral><!--opt, xs:boolean, whether to display general configuration page on the interface--></
isSupportGeneral>
  <isSupportIa><!--opt, xs:boolean, whether to display video configuration page on the interface--></isSupportIa>
  <NoiseReduce2D>
   <noiseReduce2DEnable><!--req, xs:boolean--></noiseReduce2DEnable>
   <noiseReduce2DLevel min="0" max="100"><!--dep,xs:integer--></noiseReduce2DLevel>
  </NoiseReduce2D>
  <Shutter>
   <ShutterLevel min="100" max="40000"><!--req, xs:integer--></ShutterLevel>
  </Shutter>
  <Gain>
   <GainLevel min="0" max="100"><!--req, xs:integer--></GainLevel>
  </Gain>
  <TempRange/><!--opt, temperature range capability, see XML_Cap_tempRange for details-->
</ImageChannel>

Remarks
The nodes <DigitalZoom> and <ExposureSync> are not supported by thermographic automation
thermal camera (DS-2TA03-15SVI, DS2TA06-25SVI).

16.2.49 XML_Cap_InputProxyChannel
InputProxyChannel capability message in XML format
<InputProxyChannel version="1.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <id min="" max=""></id>
 <name min="" max=""></name>
 <sourceInputPortDescriptor>
  <adminProtocol opt="HIKVISION,SONY,ISAPI,ONVIF"></adminProtocol>
  <addressingFormatType opt="ipaddress,hostname"></addressingFormatType>
  <hostName min="" max=""></hostName>
  <ipAddress></ipAddress>
  <ipv6Address></ipv6Address>
  <adminPortNo min="2000" max="65535"></adminPortNo>
  <srcInputPort min="" max=""></srcInputPort>
  <userName min="" max=""><!--user name, which should be encrypted--></userName>
  <password min="" max=""><!--password, which should be encrypted--></password>
  <streamType opt="auto,tcp,udp"></streamType>
  <deviceID min="" max=""></deviceID>
 </sourceInputPortDescriptor>
 <enableAnr opt="true,false"></enableAnr>
 <NVRInfo>
  <ipAddressNVR>
   <!--opt, xs:string, IP address of NVR-->
  </ipAddressNVR>
  <portNVR min="2000" max="65535">
   <!--opt, xs:integer, port No. of NVR-->
  </portNVR>
  <ipcChannelNo min="" max="">
   <!--opt, xs:integer, channel No. of the network camera in NVR-->
  </ipcChannelNo>
 </NVRInfo>
</InputProxyChannel>

16.2.50 XML_Cap_IOInputPortList
IOInputPortList capability message in XML format
<IOInputPortList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IOInputPort><!--req-->
  <id><!--req, xs:string--></id>
  <triggeringType opt="high,low"><!--req, xs:string--></triggeringType>
  <name min="", max=""><!--req, xs:string--></name>
  <inputType opt="switch,semaphore">

   <!--opt, xs:string, switch, semaphore-->
  </inputType>
  <CombinationAlarmCap><!--opt, composite alarm capability-->
   <channel min="" max="">
    <!--req, xs:integer，channel No. range-->
   </channel>
   <EventTypeList size=""><!--req, event type list, the "size" indicates the max. number of supported events for
composition-->
    <eventType>
     <!--req, xs:string, event type-->
    </eventType>
   </EventTypeList>
  </CombinationAlarmCap>
 </IOInputPort>
</IOInputPortList>

16.2.51 XML_Cap_IOOutputPortList
IOOutputPortList capability message in XML format
<IOOutputPortList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IOOutputPort>
  <id min="" max=""><!-- req, xs:integer, "2" --></id>
  <PowerOnState><!--req, output port configuration parameters when the device is powered on>
   <defaultState opt="high,low">
    <!--ro, req, xs:string,default output port signal when it is not triggered-->
   </defaultState>
   <outputState opt="high,low,pulse">
    <!--ro, req, xs:string, output port signal when it is being triggered-->
   </outputState>
   <pulseDuration min="" max="">
    <!--dep, xs:integer, duration of a output port signal when it is being triggered, it is valid when outputState is
"pulse", unit: milliseconds-->
   </pulseDuration>
  </PowerOnState>
  <name><!--opt, xs:string--></name>
  <IOUseType opt="disable,electricLock,custom"><!--opt, xs:string--></IOUseType>
  <normalStatus opt="open, close"><!--opt, xs:string,normal status: open-remain open, close-remain closed--></
normalStatus>
 </IOOutputPort>
</IOOutputPortList>

16.2.52 XML_Cap_IpAddress
IpAddress capability message in XML format
<IpAddress version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ipVersion opt="IPv4,IPv6,dual">
  <!--req, xs:string-->

</ipVersion>
<addressingType opt="static,dynamic,apipa">
 <!--req, xs:string-->
</addressingType>
<ipAddress min="0" max="40">
 <!--dep, xs:string-->
</ipAddress>
<subnetMask min="0" max="15">
 <!--dep, xs:string-->
</subnetMask>
<ipv6Address min="0" max="40">
 <!--dep, xs:string-->
</ipv6Address>
<bitMask ask min="0" max="128">
 <!--dep, xs:integer-->
</bitMask>
<DefaultGateway>
 <!--dep-->
 <ipAddress min="0" max="40">
  <!--dep, xs:string-->
 </ipAddress>
 <ipv6Address min="0" max="40">
  <!--dep, xs:string-->
 </ipv6Address>
</DefaultGateway>
<PrimaryDNS>
 <!--dep-->
 <ipAddress min="0" max="40">
  <!--dep, xs:string-->
 </ipAddress>
 <ipv6Address min="0" max="40">
  <!--dep, xs:string-->
 </ipv6Address>
</PrimaryDNS>
<SecondaryDNS>
 <!--dep-->
 <ipAddress min="0" max="40">
  <!--dep, xs:string-->
 </ipAddress>
 <ipv6Address min="0" max="40">
  <!--dep, xs:string-->
 </ipv6Address>
</SecondaryDNS>
<Ipv6Mode><!--opt-->
 <ipV6AddressingType opt="router,ra,manual,dhcp">
  <!--dep, xs:string-->
 </ipV6AddressingType>
 <ipv6AddressList>
  <v6Address>
   <id min="0" max="255">
     <!--dep, xs:string-->
   </id>

    <type opt="router,ra,manual,dhcp">
     <!--dep, xs:string-->
    </type>
    <address min="0" max="40">
     <!--dep, xs:string-->
    </address>
    <bitmask min="0" max="255">
     <!--dep, xs:integer-->
    </bitMask>
   </v6Address>
  </ipv6AddressList>
 </Ipv6Mode>
</IpAddress>

16.2.53 XML_Cap_IPFilter
IPFilter capability message in XML format
<IPFilter version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled opt="true, false"><!--req, xs:boolean--></enabled>
 <permissionType opt="deny, allow">
  <!--req, xs:string, IP address filter status: "deny, allow". If this node is configured, it will overwrite value of all
<permissionType> in <IPFilterAddres>-->
 </permissionType>
 <IPFilterAddressList size="32"><!--opt, the attribute "size" refers to the maximum number of IP addresses supported
by the device. If the attribute "size" is not returned, the default supported number of IP addresses is 48-->
  <IPFilterAddress>
   <id min="" max=""><!--req, xs:string, ID--></id>
   <permissionType opt="deny, allow"><!--dep, ro, xs:string--></permissionType>
   <addressFilterType opt="mask,range">
     <!--dep, ro, xs:string, filter type: "mask"-single address, "range"-address range-->
   </addressFilterType>
   <AddressRange><!--dep, this node is valid when <addressFilterType> contains "range"-->
     <startIPAddress min="" max=""><!--dep, xs:string--></startIPAddress>
     <endIPAddress min="" max=""><!--dep, xs:string--></endIPAddress>
     <startIPv6Address min="" max=""><!--dep, xs:string--></startIPv6Address>
     <endIPv6Address min="" max=""><!--dep, xs:string--></endIPv6Address>
   </AddressRange>
   <AddressMask><!--dep, it is valid when <addressFilterType> contains "mask"-->
     <ipAddress min="" max=""><!--dep, xs:string--></ipAddress>
     <ipv6Address min="" max=""><!--dep, xs:string--></ipv6Address>
     <bitMask min="" max=""><!--opt, xs:string--></bitMask>
     <bitMaskIPV6 min="" max=""> <!--req, xs:string, IPv6 prefix length--></bitMaskIPV6>
   </AddressMask>
   <describeMsg min="" max=""><!--opt, xs:string--></describeMsg>
  </IPFilterAddress>
 </IPFilterAddressList>
</IPFilter>

16.2.54 XML_Cap_ItemList
ItemList capability message in XML format
<ItemList size="15">
 <Item>
  <itemID min="1" max="15">
    <!--req, xs:string, item ID, which is between 1 and 15-->
  </itemID>
  <itemOrder
opt="none,devIp,time,buildUnitNo,outDoorDevNo,unlockType,devName,deviceNo,channelName,channelNo,
plateNo,plateColor,laneNo,carSpeed,
positionInfo1,pictureNo,CarNo,speedLimit,illegalCode,siteNo,directionNo,carColor,platePosition,carType,illegalType,cu
stom">
    <!--req, xs:string, name element: "none", "devIp"-device IP address, "time", "buildUnitNo"-building No. and unit
No., "outDoorDevNo"-door station, "unlockType"-unlocking type, "devName"-device name, "deviceNo"-device No.,
"channelName"-channel name, "channelNo"-channel No., "plateNo"-license plate number, "plateColor"-license plate
color, "laneNo"-lane No., "carSpeed"-vehicle speed, "positionInfo1"-camera 1, "pictureNo"-picture No., "CarNo"-
vehicle No., "speedLimit"-speed limit, "illegalCode"-violation code, "siteNo"-intersection No., "directionNo"-direction
No., "carColor"-vehicle color, "platePosition"-license plate coordinates, "carType"-vehicle type, "illegalType"-violation
type, "custom"-->
  </itemOrder>
  <itemCustomStr min="1" max="32">
    <!--req, xs:string, element custom string, which is between 1 and 32, unit: bytes. This node is valid only when
<itemOrder> is "custom". Currently traffic cameras only support one custom name-->
  </itemCustomStr>
 </Item>
</ItemList>

16.2.55 XML_Cap_LensDistortionCorrection
LensDistortionCorrection capability message in XML format
<LensDistortionCorrection version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs: boolean--></enabled>
 <level opt="level1,level2,level3,custom">
  <!--opt, xs: string, distortion correction level: level 1, level 2, level 3, custom-->
 </level>
 <accurateLevel min="0" max="100">
  <!--opt, xs: integer, correction strength, value range: [0,100]-->
 </accurateLevel>
 <zoomedInDistantViewLevel min="0" max="100">
  <!--opt, xs: integer, zooming in range, value range: [0-100], this node is valid when distortion correction is enabled-->
 </zoomedInDistantViewLevel>
 <horizontalFOV min="0" max="100"><!--opt, xs: integer, horizontal FOV, value range: [0,100]--></horizontalFOV>
 <verticalFOV min="0" max="100"><!--opt, xs: integer, vertical FOV, value range: [0,100]--></verticalFOV>
</LensDistortionCorrection>

16.2.56 XML_Cap_Link
Link capability message in XML format.
<Link version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <MACAddress><!--req, xs:string--></MACAddress>
 <autoNegotiation><!--req, xs:boolean, "true, false"--> </autoNegotiation>
 <speed><!--req, xs:integer, "10.100, 1000"--></speed>
 <duplex><!--req, xs:string, "half, full"--></enalbed>
 <MTU><!--req, xs:integer, "500-1500"--></MTU>
</Link>

16.2.57 XML_Cap_LogConfig
LogConfig capability message in XML format.
<LogConfig version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--required, boolean type, whether to enable log--></enabled>
 <level opt="none,debug,info,error,fault,all">
  <!--required, string type, log types, multiple type can be selected, and each type should be separated by comma-->
 </level>
</LogConfig>

16.2.58 XML_Cap_MACFilter
MACFilter capability message in XML format
<MACFilter version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled opt="true,false"><!--req, xs:boolean--></enabled>
 <permissionType opt="deny, allow"><!-- req, xs:string,"deny, allow"--></permissionType>
 <MACFilterAddressList size="">
  <MACFilterAddress>
   <id> <!--req, xs:string;id--></id>
   <MACAddress max=""><!--req, xs:string--></MACAddress>
  </MACFilterAddress>
 </MACFilterAddressList>
</MACFilter>

16.2.59 XML_Cap_mailingList
mailingList capability message in XML format.
<mailingList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <mailing><!--opt,xs:string--></mailing>
</mailingList>

16.2.60 XML_Cap_MaxElevation
MaxElevation capability message in XML format
<MaxElevation version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <mElevation min="-20" max="0"><!--req, xs:integer, the lower limit of max. tilt-angle--> </mElevation>
 <mVerElevation><!--req, xs:integer, the upper limit of max. tilt-angle, normally it is 90°--></mVerElevation>
</MaxElevation>

16.2.61 XML_Cap_NetworkInterface
NetworkInterface capability message in XML format
<NetworkInterface version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string--></id>
 <IPAddress/><!--req-->
 <Wireless/><!--opt-->
 <Discovery/><!--opt-->
 <Link/><!--opt-->
 <defaultConnection><!--opt, xs:boolean--></defaultConnection>
 <macAddress min="" max=""><!--opt, xs:string--></macAddress>
 <EthernetPortList size="4"><!--opt, network interface information-->
  <EthernetPort><!--opt -->
   <id min="1",max="4"><!--req, xs: integer--></id>
   <MACAddress><!--req, xs:string--></MACAddress>
   <status opt="connected, disconnect"><!--opt, xs:string--></status>
   <speed><!--req, xs:integer, "10, 100, 1000, 10000"--></speed>
  </EthernetPort>
 </EthernetPortList>
</NetworkInterface>

16.2.62 XML_Cap_NTPServer
NTPServer capability message in XML format
<NTPServer version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id min="1" max=""><!--req, xs:string, ID--></id>
 <addressingFormatType opt="ipaddress,hostname"><!--req, xs:string, which field will be used to locate the NTP
server: "ipaddress, hostname"--></addressingFormatType>
 <hostname min="0" max="64"><!--dep, xs:string--></hostName>
 <ipAddress min="0" max="64"><!--dep, xs:string--></ipAddress>
 <ipv6Address min="0" max="64"><!--dep, xs:string--></ipv6Address>
 <portNo min="1" max="65535"><!--opt, xs:integer--></portNo>
 <synchronizeInterval min="0" max="65535"><!--opt, xs:integer, NTP time synchronization interval, unit: minute--></
synchronizeInterval>
</NTPServer>

16.2.63 XML_Cap_PreviewSwitch
PreviewSwitch message in XML format
<PreviewSwitch version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <groupNo min="0" max="15"><!--opt, xs: integer, group No.--></groupNo>
 <videoOutType
opt="CVBS,HDMI,VGA,AUXOutput1,AUXOutput2,AUXOutput3,AUXOutput4,extendHDMI1,extendHDMI2,extendHDMI3
,extendHDMI4,noSameSourceVGA1,noSameSourceVGA2,noSameSourceVGA3,noSameSourceVGA4,sameSourceVGA,m
ainLCD,AUX-VGA,AUX-LCD,zeroChannel">
   <!--opt, xs: string, video output types, if there are more than two outputs are homologous, you can combine these
outputs by "/" to be returned, e.g., if HDM1 and VGA1 are homologous outputs, "HDM1/VGA1" will be returned-->
 </videoOutType>
 <DisplayWindowList size="64">
   <DisplayWindow>
    <id><!--req, xs: string, window No., which equals to id × groupNo--></id>
    <displayChannelNo min="0" max="64"><!--req, xs: string, 0-not display, 1 to 64-displayed channel No.--></
displayChannelNo>
   </DisplayWindow>
 </DisplayWindowList>
 <previewFrameNo opt="1,4,6,8,9,25,32,36,auto1,auto2,auto3,auto4">
   <!--req, xs: string, number of live view windows, auto1-custom window division 1, auto2-custome window division
2, auto3-custome window division 3, auto4-custome window division 4-->
 </previewFrameNo>
 <sound><!--req, xs: boolean, whether to turn on audio during live view, true-yes--></sound>
 <switchTime opt="0,5,10,20,30,60,120,300"><!--req, xs: string, switching interval, unit: s--></switchTime>
 <sameSource>
   <!--dep, xs: boolean, whether the output is homologous, true-yes, this node is valid only when VideoOutType is
"noSameSourceVGA1", "noSameSourceVGA2", "noSameSourceVGA3", and "noSameSourceVGA4"-->
 </sameSource>
 <supportGetByPreviewNum>
   <!--opt, whether supports setting number of live view windows in the URL, true-yes-->
 </supportGetByPreviewNum>
 <supportGetByVideoOutType>
   <!--opt, xs: boolean, whether supports getting capability by output-->
 </supportGetByVideoOutType>
</PreviewSwitch>

16.2.64 XML_Cap_RegionClip
RegionClip capability message in XML format
<RegionClip version="2.0" xmlns="http://www.std-cgi.org/ver20/XMLSchema">
 <id><!--req, xs: string--></id>
 <enabled><!--req, xs: boolean--></enabled>
 <normalizedScreenSize><!--req, read-only-->
  <normalizedScreenWidth><!--req, read-only, xs: integer--></normalizedScreenWidth>
  <normalizedScreenHeight><!--req, read-only, xs: integer--></normalizedScreenHeight>
 </normalizedScreenSize>

 <regionType opt="rectangle,convexPolygon,concavePolygon"><!--req, ro, xs:string--></regionType>
 <videoResolutionWidth opt="704"></videoResolutionWidth>
 <videoResolutionHeight opt="576"></videoResolutionHeight>
 <ClipRegionList>
  <ClipRegion>
   <RegionCoordinatesList size="1">
    <RegionCoordinates><!--req-->
      <positionX><!--req, xs: integer; x-coordinate--></positionX>
      <positionY><!--req, xs: integer; y-coordinate--></positionY>
    </RegionCoordinates>
   </RegionCoordinatesList>
  </ClipRegion>
 </ClipRegionList>
</RegionClip>

16.2.65 XML_Cap_RuleInfo
RuleInfo capability message in XML format.
<RuleInfo version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <ruleId opt="1,2,3,4,5,6,7,8"><!—req, xs:string-></ruleId>
 <ruleName min="" max=""> <!—req, xs:string-> </ruleName>
 <combinedRuleId opt="15,16"><!—req, xs:string-></combinedRuleId>
 <enabled opt="true,false"><!—req, xs:boolean-></enabled>
 <ruleType opt="region,line"><!—req, xs:string->/ruleType>
 <LineDetectionParam>
  <detectionTarget opt="all,human,vehicle, human_vehicle "/>
   <!—detection target, node with underline indicates that it supports multiple selections, e.g., human_vehicle
indicates human and vehicle-->
  <directionSensitivity opt="left-right,right-left,any" def="any"><!—req, xs:string-></directionSensitivity>
  <isSupportHumanMisinfoFilter>
   <!--opt, xs:boolean, whether supports false alarm filter of human: true-supports, false or no return-not support-->
  </isSupportHumanMisinfoFilter>
  <isSupportVehicleMisinfoFilter>
   <!--opt, xs:boolean, whether supports false alarm filter of vehicle: true-supports, false or no return-not support-->
  </isSupportVehicleMisinfoFilter>
  <sensitivity min="1" max="100" default="50"><!--req, xs:integer, sensitivity, from 1 to 100--></sensitivity>
 </LineDetectionParam>
 <FieldDetectionParam>
  <durationTime min="1" max="100" def="5"><!--req,xs:integer--> </durationTime>
  <sensitivityLevel min="1" max="100"><!—req, xs:integer, sensitivity from 0 to 100--> </sensitivityLevel>
  <detectionTarget opt="all,human,vehicle, human_vehicle "/>
   <!—detection target, node with underline indicates that it supports multiple selections, e.g., human_vehicle
indicates human and vehicle-->
  <isSupportHumanMisinfoFilter>
   <!--opt, xs:boolean, whether supports false alarm filter of human: true-supports, false or no return-not support-->
  </isSupportHumanMisinfoFilter>
  <isSupportVehicleMisinfoFilter>
   <!--opt, xs:boolean, whether supports false alarm filter of vehicle: true-supports, false or no return-not support-->
  </isSupportVehicleMisinfoFilter>
 </FieldDetectionParam>

 <RegionEntranceParam>
  <detectionTarget opt="all,human,vehicle, human_vehicle "/>
   <!—detection target, node with underline indicates that it supports multiple selections, e.g., human_vehicle
indicates human and vehicle-->
  <isSupportHumanMisinfoFilter>
   <!--opt, xs:boolean, whether supports false alarm filter of human: true-supports, false or no return-not support-->
  </isSupportHumanMisinfoFilter>
  <isSupportVehicleMisinfoFilter>
   <!--opt, xs:boolean, whether supports false alarm filter of vehicle: true-supports, false or no return-not support-->
  </isSupportVehicleMisinfoFilter>
 </RegionEntranceParam>
 <RegionExitingParam>
  <detectionTarget opt="all,human,vehicle, human_vehicle "/><!—detection target, node with underline indicates
that it supports multiple selections, e.g., human_vehicle indicates human and vehicle-->
  <isSupportHumanMisinfoFilter>
   <!--opt, xs:boolean, whether supports false alarm filter of human, true-supports, false or no return-not support-->
  </isSupportHumanMisinfoFilter>
  <isSupportVehicleMisinfoFilter>
   <!--opt, xs:boolean, whether supports false alarm filter of vehicle, true-supports, false or no return-not support-->
  </isSupportVehicleMisinfoFilter>
 </RegionExitingParam>
 <PeopleNumChangeParam>
  <peopleNumThreshold min="" max="" default=""><!--opt,xs:integer--></peopleNumThreshold>
  <detectMode opt="greaterthan,lessThan,equal,notEqual"><!-- opt,xs:string--></detectMode>
  <noneStateEffectiveEnabled><!--opt,xs:boolean--></noneStateEffectiveEnabled>
  <durationTime min="" max="" default=""><!--opt,xs:integer--></durationTime>
 </PeopleNumChangeParam>
 <SpacingChangeParam>
  <spacingThreshold min="" max="" default=""><!--opt,xs: integer--></spacingThreshold>
  <detectMode><!--opt,xs:string,"greaterthan,lessThan"--></detectMode>
  <durationTime min="" max="" default=""><!--opt,xs:integer--></durationTime>
 </SpacingChangeParam>
 <ViolentMotionParam>
  <sensitivity min="" max="" default=""> <!--opt,xs:integer--> </sensitivity>
 </ViolentMotionParam>
 <LeavePositionParam>
  <leaveDelay min="" max="" default=""><!--opt,xs:integer--></leaveDelay>
  <onPosition min="" max="" default=""><!--opt,xs:integer--></onPosition>
 </LeavePositionParam>
 <FailDownParam>
  <durationTime min="" max="" default=""><!--opt,xs:integer--></durationTime>
  <heightThreshold min="" max="" default=""><!--opt,xs:integer--></heightThreshold>
 </FailDownParam>
 <RunningParam>
  <speed min="" max="" default=""><!--opt,xs:integer--></speed>
 </RunningParam>
 <RetentionParam><!--dep-->
  <durationTime min="" max="" default="">
   <!--req, xs:integer, duration time, from 60 seconds to 3600 seconds, default value: 1800 seconds-->
 </RetentionParam>
 <ParkingParam>
  <durationTime min="5" max="100"><!-- req,xs:integer--> </durationTime>

 </ParkingParam>
 <eventType
opt="none,lineDetection,fieldDetection,regionEntrance,regionExiting,parking,peopleNumChange,spacingChange,viole
ntMotion,leavePosition,failDown,running,retentionParam">
  <!—req, xs:string-->
 </eventType>
 <SizeFilter>
  <enabled opt="true,false"><!—req, xs:boolean--></enabled>
  <mode opt="pixels,actualSize"><!—req, xs:string, filter mode: "pixels"-filter according to pixel, "actualSize"-filter
according to actual size--></mode>
  <ObjectSizeList size="4">
   <ObjectSize><!--only return the default value of supported detection type-->
    <detectionTarget><!--opt,xs:string, detection target, "all"-all, "human"-human, "vehicle"-vehicle,
"human_vehicle"-human and vehicle--></detectionTarget>
    <MaxObjectSize><!--maximum size:float-->
      <positionX><!--req,xs:integer;coordinate--></positionX>
      <positionY><!--req,xs:integer;coordinate--></positionY>
      <width><!--req,xs:integer, default width value: when detectionTarget values "all", it is 500, "human"-200,
"vehicle"-500, "human_vehicle"-500, unit: cm--></width>
      <height><!--req,xs:integer, default height value: when detectionTarget values "all", it is 100, "human"-300,
"vehicle"-100, "human_vehicle"-100, unit: cm --></height>
    </MaxObjectSize>
    <MinObjectSize><!--minimum size:float-->
      <positionX><!--req,xs:integer;coordinate--></positionX>
      <positionY><!--req,xs:integer;coordinate--></positionY>
      <width><!--req,xs:integer, default width value: when detectionTarget values "all", it is 60, "human"-60,
"vehicle"-180, "human_vehicle"-60, unit: cm--></width>
      <height><!--req,xs:integer, default height value: when detectionTarget values "all", it is 10, "human"-10,
"vehicle"-140, "human_vehicle"-10, unit: cm--></height>
    </MinObjectSize>
   </ObjectSize>
  </ObjectSizeList>
 </SizeFilter>
 <RuleRegion>
  <RegionCoordinatesList size="4">
   <RegionCoordinates>
    <positionX min="" max=""><!--req, xs:integer--></positionX>
    <positionY min="" max=""><!--req, xs:integer--></positionY>
   </RegionCoordinates>
  </RegionCoordinatesList>
 </RuleRegion>
 <backgroundSuppression opt="open,close,selfAdapt"><!--opt, xs:string, background suppression--></
backgroundSuppression>
</RuleInfo>

Remarks
When the mode values "actualSize", the input value of positionX and positionY is 0.

16.2.66 XML_Cap_SerialCommand
SerialCommand capability message in XML format
<SerialCommand version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <chainNo min="1" max="16">
  <!--opt, xs:integer-->
 </chainNo>
 <command>
  <!--req, xs:hexBinary-->
 </command>
</SerialCommand>

16.2.67 XML_Cap_SerialPort
SerialPort capability message in XML format
<SerialPort version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id min="0" max="255">
  <!--req, xs:string, serial port ID-->
 </id>
 <enabled>
  <!--req, xs:boolean, whether to enable the serial port: "true, false"-->
 </enabled>
 <serialNumber opt="1,2,3,4,5">
  <!--opt, xs:integer, serial port No., which is between 1 and 5-->
 </serialNumber>
 <serialPortType opt="RS485,RS422,RS232">
  <!--req, xs:string, serial port type: "RS485", "RS422", "RS232"-->
 </serialPortType>
 <duplexMode opt="half,full">
  <!--req, xs:string, duplex mode of the serial port: "half", "full"-->
 </duplexMode>
 <direction opt="monodirectional,bdirectional">
  <!--req, xs:string-->
 </direction>
 <baudRate range="600,1200,2400,4800,9600,19200,38400,57600,76800,115200">
  <!--req, xs:integer-->
 </baudRate>
 <dataBits min="5" max="8">
  <!--req, xs:integer-->
 </dataBits>
 <parityType opt="none,even,odd,mark,space">
  <!--req, xs:string-->
 </parityType>
 <stopBits range="1,2">
  <!--req, xs:string, stop bit: "1,1.5,2"-->
 </stopBits>
 <workMode opt="console,transparent,narrowband,audiomixer,stairsControl,cardReader,disabled,custom">

  <!--dep, xs:string, working mode: "console","transparent","narrowband","audiomixer","stairsControl"-elevator
control,"cardReader"-card reader,"disabled","custom". This node is required only when <serialPortType> is set to
"RS232"-->
 </workMode>
 <flowCtrl opt="none,software,hardware">
  <!--req, xs:string-->
 </flowCtrl>
 <rs485WorkMode opt="Led, CaptureTrigger">
  <!--opt, xs:string, working mode of RS-485 serial port, which is used for LED display or triggering transmission of
captured pictures. This node is valid only when <serialPortType> is "RS485"-->
 </rs485WorkMode>
 <audiomixerProtocolType opt="HIKVISION">
  <!--opt, xs:string, "HIKVISION"-->
 </audiomixerProtocolType>
</SerialPort>

16.2.68 XML_Cap_SIPInfo
SIPInfo capability message in XML format
<SIPInfo version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <videoID opt="1,2,3">
  <!--req, xs:string-->
 </videoID>
 <AlarmInList>
  <AlarmIn>
   <id min="0" max="8">
    <!--req, xs:integer-->
   </id>
   <alarmInID min="0" max="64">
    <!--req, xs:string-->
   </alarmInID>
  </AlarmIn>
 </AlarmInList>
</SIPInfo>

16.2.69 XML_Cap_SIPServer
SIPServer capability message in XML format
<SIPServer version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id min="1" max="">
  <!--req, xs:interger, the maximum ID depends on the number of channels-->
 </id>
 <localPort min="0" max="65535">
  <!--req, xs:integer-->
 </localPort>
 <streamID min="1" max="255">
  <!--req, xs:integer, stream type: 1-main stream, 2-sub-stream, 3-third stream-->

</streamID>
<Standard>
 <!--opt-->
 <registerStatus>
  <!--ro, req, xs:boolean, registration status: "false"-unregistered, "true"-registered-->
 </registerStatus>
 <enabled >
  <!--req, xs:string, "true"-log in, "false"-log out-->
 </enabled>
 <registrar min="0" max="128">
  <!--req, xs:string-->
 </registrar>
 <registrarPort min="1024" max="65535">
  <!--req, xs:integer-->
 </registrarPort>
 <proxy min="0" max="128">
  <!--req, xs:string-->
 </proxy>
 <proxyPort min="0" max="65535">
  <!--req, xs:integer-->
 </proxyPort>
 <displayName min="0" max="64">
  <!--req, xs:string-->
 </displayName>
 <username min="0" max="64">
  <!--req, xs:string-->
 </userName>
 <authID min="0" max="64">
  <!--req, xs:string-->
 </authID>
 <password min="0" max="32">
  <!--wo, req, xs:string-->
 </password>
 <expires min="0" max="100000">
  <!--req, xs:integer-->
 </expires>
</Standard>
<GB28181>
 <!--opt-->
 <registerStatus>
  <!--req, xs:boolean, "true,false"-->
 </registerStatus>
 <enabled>
  <!--req, xs:boolean, "true,false"-->
 </enabled>
 <registrar min="0" max="128">
  <!--req, xs:string-->
 </registrar>
 <registrarPort min="1024" max="65535">
  <!--req, xs:integer-->
 </registrarPort>
 <serverId min="0" max="64">

   <!--req, xs:string-->
  </serverId>
  <serverDomain min="0" max="128">
   <!--req, xs:string-->
  </serverDomain>
  <username min="0" max="64">
   <!--req, xs:string-->
  </userName>
  <authID min="0" max="64">
   <!--req, xs:string-->
  </authID>
  <password min="0" max="32">
   <!--wo, req, xs:string-->
  </password>
  <expires min="30" max="100000">
   <!--req, xs:integer-->
  </expires>
  <liveTime min="30" max="100000">
   <!--req, xs:integer-->
  </liveTime>
  <heartbeatTime min="0" max="255">
   <!--req, xs:integer-->
  </heartbeatTime>
  <heartbeatCount min="3" max="255">
   <!--req, xs:integer-->
  </heartbeatCount>
 </GB28181>
</SIPServer>

16.2.70 XML_Cap_SmartSearchDescription
SmartSearchDescription capability message in XML format
<SmartSearchDescription version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <searchID>
  <!--req, xs:string, search ID, which is used to confirm the upper-level platform or system. If the platform or system
are same during two times of search, the search history will be recorded in the memory for next fast search-->
 </searchID>
 <searchResultPosition><!--req, xs: integer--></searchResultPosition>
 <maxResults><!--req, xs: integer--></maxResults>
 <trackID><!--req, xs: integer, channel ID, e.g., 101-main stream if first channel--></trackID>
 <startTime><!--req, xs: datetime, start time of validity period, e.g., 2013-06-10T 12:00:00Z--></startTime>
 <endTime><!--req, xs: datetime, end time of validity period, e.g., 2013-06-10T 13:00:00Z--></endTime>
 <type opt="motionDetection, traversePlaneDetection,FieldDetection, faceDetection">
  <!--req, xs: string; VCA event type-->
 </type>
 <MotionDetection><!--dep, it is valid when type is "motionDetection"-->
  <Grid>
   <rowGranularity></rowGranularity>
   <columnGranularity></columnGranularity>
  </Grid>

  <MotionDetectionLayout>
   <layout>
    <gridMap></gridMap>
   </layout>
  </MotionDetectionLayout>
  <sensitivity min="1", max="100"><!--opt, xs: integer--></sensitivity>
 </MotionDetection>
 <TraversePlane><!--dep, it is valid when type is "traversePlaneDetection"-->
  <TraversePlaneParam>
   <LineList>
    <Line>
      <StartPoint>
       <x><!--req, xs: float--></x>
       <y><!--req, xs: float--></y>
      </StartPoint>
      <EndPoint>
       <x><!--req, xs: float--></x>
       <y><!--req, xs: float--></y>
      </EndPoint>
    </Line>
   </LineList>
   <crossDirection opt="bothDirection, leftToRight, rightToLeft><!--opt, xs: string, crossing direction--
><crossDirection>
   <sensitivity min="1", max="100"><!-- opt, xs: integer--></sensitivity>
   <planeHeight><!--opt, xs: integer--></planeHeight>
   <detectionTarget opt="all, human, vehicle><!--req, xs: string--><detectionTarget>
  </TraversePlaneParam>
  <dwPreTime><!--opt, xs: integer, pre-recording time--></dwPreTime>
  <dwDelayTime><!--opt, xs: integer,post-recording time--></dwDelayTime>
  <PTZPos>
   <P><!--opt, xs: integer--></P>
   <T><!--opt, xs: integer--></T>
   <Z><!--opt, xs: integer--></Z>
  </PTZPos>
  <advancedType opt="humanFeature, objectFeature"><!--opt, xs: string--></advancedType>
  <advance><!--dep, it is valid when type is "motionDetection"-->
   <HumanFeature>
    <age min="0" max="100"><!--opt, xs: integer--></age>
    <sex opt="male,female"><!--opt, xs: string--></sex>
    <eyeGlass><!--opt, xs: boolean--></eyeGlass>
   </HumanFeature><!--dep, it is valid when type is "humanFeature"-->
   <ObjectFeature>
    <colorRatel><!--opt, xs: integer--></colorRatel>
    <R><!--opt, xs: integer--></R>
    <G><!--opt, xs: integer--></G>
    <B><!--opt, xs: integer--></B>
   </ObjectFeature><!--dep, it is valid when type is "objectFeature"-->
  </advance>
 </TraversePlane>
 <FieldDetection><!--dep, it is valid when type is "FieldDetection"-->
  <normalizedScreenSize>
   <normalizedScreenWidth><!--opt, xs: integer--></normalizedScreenWidth>

 <normalizedScreenHeight><!--opt, xs: integer--></normalizedScreenHeight>
</normalizedScreenSize>
<param>
 <region>
  <pointList>
   <point>
    <x><!--opt, xs: integer--></x>
    <y><!--opt, xs: integer--></y>
   </point>
  </pointList>
 </region>
</param>
<duration min="1", max="100"><!--opt, xs: integer--></duration>
 <sensitivity min="1", max="100"><!--opt, xs: integer--></sensitivity>
 <rate min="1", max="100"><!--opt, xs: integer--></rate>
 <detectionTarget opt="all, human, vehicle><!--req, xs: string--><detectionTarget>
 <dwPreTime><!--opt, xs: integer, pre-recording time--></dwPreTime>
 <dwDelayTime><!--opt, xs: integer, post-recording time--></dwDelayTime>
 <PTZPos>
  <P><!--opt, xs: integer--></P>
  <T><!--opt, xs: integer--></T>
  <Z><!--opt, xs: integer--></Z>
 </PTZPos>
 <advancedType opt="humanFeature, objectFeature"><!--opt, xs: string--></advancedType>
 <advance><!--dep, it is valid when type is "motionDetection"-->
  <HumanFeature>
   <age min="0" max="100"><!--opt, xs: integer--></age>
   <sex opt="male,female"><!--opt, xs: string--></sex>
   <eyeGlass><!--opt, xs: boolean--></eyeGlass>
  </HumanFeature><!--dep, it is valid when type is "humanFeature"-->
  <ObjectFeature>
   <colorRatel><!--opt, xs: integer--></colorRatel>
   <R></R>
   <G></G>
   <B></B>
  </ObjectFeature><!--dep, it is valid when type is "objectFeature"-->
 </advance>
</FieldDetection>
<FaceDetection><!--dep, it is valid when type is "faceDetection"-->
 <param>
  <region>
   <pointList>
    <point>
      <x/>
      <y/>
    </point>
   </pointList>
  </region>
 </param>
 <duration min="1", max="100"><!--opt, xs: integer--></duration>
 <sensitivity min="1", max="100"><!--opt, xs: integer--></sensitivity>
 <rate min="1", max="100"><!--opt, xs: integer--></rate>

   <detectionTarget opt="all, human, vehicle><!--req, xs: string--><detectionTarget>
   <dwPreTime><!--opt, xs: integer, pre-recording time--></dwPreTime>
   <dwDelayTime><!--opt, xs: integer, post-recording time--></dwDelayTime>
   <PTZPos>
    <P><!--opt, xs: integer--></P>
    <T><!--opt, xs: integer--></T>
    <Z><!--opt, xs: integer--></Z>
   </PTZPos>
   <advancedType opt="humanFeature, objectFeature"><!--opt, xs: string--></advancedType>
   <advance><!--dep, it is valid when type is "motionDetection"-->
   <HumanFeature>
    <colorRatel><!--opt, xs: integer--></colorRatel>
    <age min="0" max="100"><!--opt, xs: integer--></age>
    <sex opt="male,female"><!--opt, xs: string--></sex>
    <eyeGlass><!--opt, xs: boolean--></eyeGlass>
   </HumanFeature> <!--dep, it is valid when type is "humanFeature"-->
   <ObjectFeature>
    <colorRatel><!--opt, xs: integer--></colorRatel>
    <R></R>
    <G></G>
    <B></B>
   </ObjectFeature><!--dep, it is valid when type is "objectFeature"-->
  </advance>
 </FaceDetection>
</SmartSearchDescription>

16.2.71 XML_Cap_SoftwareService
SoftwareService capability message in XML format
<SoftwareService version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ThirdStream><!--opt, third stream configuration-->
  <enabled opt="true,false"><!--req, xs: boolean, whether to enable third stream configuration--></enabled>
  <thirdStreamPrompt opt="prompt5">
    <!--req, xs: string, set audible prompt for third stream, prompt5-"When third stream is enabled, functions such as
intrusion detection, line crossing detection, region entrance detection, region exiting detection, face detection, HDMI,
H.264+ and H265+, are not supported. New settings will take effect after a reboot."-->
  </thirdStreamPrompt>
 </ThirdStream>
 <PanoramaDisplay><!--opt, display the image range on panorama view-->
  <enabled opt="true,false" default="false">
    <!--req, xs: boolean, whether to enable image range display on panorama view-->
  </enabled>
 </PanoramaDisplay>
 <MotionDetect>
  <enabled opt="true,false"><!--whether to enable motion detetion--></enabled>
  <MotionDetectPrompt opt="prompt1">
    <!--req, xs: string, motion detection audible prompt, prompt1-"When motion detection is enabled, functions such
as intrusion detection, line crossing detection, region entrance detection, and region exiting detection, are not
supported. New settings will take effect after a reboot."-->
  </MotionDetectPrompt>

 </MotionDetect>
</SoftwareService>

16.2.72 XML_Cap_StreamingChannel
StreamingChannel capability message in XML format
<StreamingChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  <id opt="111,222,333,444"><!--req, xs:string, ID--></id>
  <channelName min="0" max="64"><!--req, xs:string, channel name--></channelName>
  <enabled opt="true,false" def="true"><!--req, xs:boolean--></enabled>
  <Transport><!--req-->
   <rtspPortNo min="0" max="65535" def="554">554</rtspPortNo>
   <maxPacketSize min="0" max="1500"><!--opt, xs:integer--></maxPacketSize>
   <audioPacketLength min="0" max="5000"/>
   <audioInboundPacketLength min="0" max="5000"/><!--opt, xs:integer-->
   <audioInboundPortNo min="0" max="65535"/><!--opt, xs:integer-->
   <videoSourcePortNo min="0" max="65535"/><!--opt, xs:integer-->
   <audioSourcePortNo min="0" max="65535"/><!--opt, xs:integer-->
   <ControlProtocolList><!--req-->
    <ControlProtocol><!--list-->
     <streamingTransport opt="RTSP/RTP,HTTP"><!--req, xs:string, "HTTP,RTSP,SHTTP,SRTP"--></streamingTransport>
    </ControlProtocol>
   </ControlProtocolList>
   <Unicast><!--opt-->
    <enabled opt="true,false" def="false"/><!--req, xs:boolean-->
    <rtpTransportType opt="RTP/UDP,RTP/TCP"/><!--opt, xs:string, "RTP/UDP,RTP/TCP"-->
   </Unicast>
   <Multicast><!--opt-->
    <enabled opt="true,false" def="false"/><!--req, xs:boolean-->
    <userTriggerThreshold/><!--opt, xs:integer-->
    <videoDestPortNo min="1" max="65535" def="8860"/><!--opt, xs:integer-->
    <audioDestPortNo min="1" max="65535" def="8860/><!--opt, xs:integer-->
    <destIPAddress min="8" max="16"/><!--dep, xs:string-->
    <destIPv6Address min="15" max="39"/><!--dep, xs:string-->
    <ttl min="0" max="127" def="1"/><!--opt, xs:integer-->
    <activeMulticastEnabled>
     <!--opt, xs: boolean, "true, false", whether to enable active multicast, which is mutually exclusive with passive
multicast-->
    </activeMulticastEnabled>
    <packagingFormat opt="RTP,TS,ES,PS"><!--opt, xs: string, encapsulation format--></packagingFormat>
    <FecInfo><!--opt-->
     <fecRatio min="0" max="100">
       <!--req, read-only, xs: integer, extra bandwidth occupation ratio of forward error correction (FEC) data, the value
is between 0 and 100, the default value is 0-->
     </fecRatio>
     <fecDestPortNo>
       <!--opt, xs: integer, port No. of FEC multicast, the default port No. is specified by device-->
     </fecDestPortNo>
    </FecInfo>
   </Multicast>

   <Security><!--opt-->
    <enabled opt="true,false" def="false"/><!--req, xs:boolean-->
    <certificateType opt="digest,digest/baisc" def="digest"><!--req, xs:string--></certificateType>
   </Security>
   <SRTPMulticast><!--opt-->
    <SRTPVideoDestPortNo min="" max=""><!--opt, xs:integer--></SRTPVideoDestPortNo>
    <SRTPAudioDestPortNo min="" max=""><!--opt, xs:integer--></SRTPAudioDestPortNo>
   </SRTPMulticast>
 </Transport>
 <Video>
   <enabled opt="true,false">true</enabled>
   <videoInputChannelID opt="1,2,3,4">2</videoInputChannelID>
   <videoCodecType opt="MJPEG,MPEG4">MPEG4</videoCodecType>
   <videoScanType opt="interlaced,progressive">progressive</videoScanType>
   <videoResolutionWidth min="0" max="640">640</videoResolutionWidth>
   <videoResolutionHeight min="0" max="480">480</videoResolutionHeight>
   <videoDiffResolutionList><!--opt, list, if this node exists, it indicates that the resolution depends on the node
<videoCodecType>, and <videoResolutionWidth> and <videoResolutionHeight> are invalid. For forward
compatibility, the maximum set of <videoCodecType>, <videoResolutionWidth>, and <videoResolutionHeight>-->
    <videoDiffResolution>
     <videoCodecType>
      <!--req, xs:string, "MPEG4,MJPEG,3GP,H.264,HK.264,MPNG,SVAC"-->
     </videoCodecType>
     <videoResolutionWidth><!--req, xs:integer--></videoResolutionWidth>
     <videoResolutionHeight><!--req, xs:integer--></videoResolutionHeight>
    </videoDiffResolution>
   </videoDiffResolutionList>
   <videoPositionX min="0" max="640">0</videoPositionX>
   <videoPositionY min="0" max="480">0</videoPositionY>
   <videoQualityControlType opt="CBR,VBR">CBR</videoQualityControlType>
   <constantBitRate min="50" max="4000" dynamic="true">2000</constantBitRate>
   <maxFrameRate opt="2500,1250,625,312,156,78，830" >2500</maxFrameRate>
   <keyFrameInterval min="0", max="10000">1000</keyFrameInterval>
   <rotationDegree opt="0,90,180,270" def="0">0</rotationDegree>
   <mirrorEnabled opt="true,false" def="false">false</mirrorEnabled>
   <snapShotImageType opt="JPEG" def="JPEG">JPEG</snapShotImageType>
   <IntelligentInfoDisplayMethod opt="player,non-player"><!--opt, xs:string, method of displaying intelligent
information: "player", "non-player"--></IntelligentInfoDisplayMethod>
   <minimumResolutionSupportedBySmartCode>
    <!--opt, xs:string, the minimum resolution supported by smart coding (smart264 and smart265), e.g., "640*512". If
this node is returned, it indicates the smart code of current device (H7, H5) is limited by the minimum resolution, and
the upper layer can get the supported minimum resolution for smart coding of current device. For the resolution
lower than the minimum resolution does not support smart coding. If this node is not returned, it indicates the smart
coding of current device (H3) is not limited by minimum resolution-->
   </minimumResolutionSupportedBySmartCode>
 </Video>
 <Audio>
   <enabled opt="true,false" def="false">false</enabled>
   <audioInputChannelID opt="1,2,3,4">2</audioInputChannelID>
   <audioCompressionType opt="G.726,G.711ulaw" def="G.726">G.726</audioCompressionType>
   <audioBitRate opt="16,24,32,40" def="32" dynamic="true">24</audioBitRate>
   <audioSamplingRate opt="8" dynamic="true">8</audioSamplingRate>

   <audioResolution opt="3,4,5,6" dynamic="true"/>
  </Audio>
  <isSpportDynamicCapWithCondition><!--opt, xs:boolean, whether to support dynamic capability with conditions--></
isSpportDynamicCapWithCondition>
  <enableCABAC><!--opt, xs:boolean, whether it supports compressing stream to improve performance--></
enableCABAC>
  <subStreamRecStatus><!--opt, xs:boolean--></subStreamRecStatus>
  <isSupportRefreshFrame><!--opt, xs:boolean, whether it supports refreshing frames when Smart264 is enabled--></
isSupportRefreshFrame>
  <isSupportBareDataOverlay><!--opt, xs:boolen--></isSupportBareDataOverlay>
  <isSupportRTCPCfg><!--opt, xs:boolean--></isSupportRTCPCfg>
  <customStreamEnable><!--opt, xs:boolean, whether the stream is custom stream: "true"-yes, this node is not
returned-no--></customStreamEnable>
</StreamingChannel>

16.2.73 XML_Cap_SupplementLight
SupplementLight capability message in XML format
<SupplementLight><!--opt-->
 <mode opt="schedule,off,on,auto"><!--opt, xs: string, adjustment mode of supplement light--></mode>
 <Schedule>
  <TimeRange><!--req-->
    <beginTime><!--req, xs: time, ISO8601 time--></beginTime>
    <endTime><!-- req, xs: time, ISO8601 time--></endTime>
  </TimeRange>
 </Schedule>
 <brightnessLimit min="0" max="100">
  <!--dep, xs: integer, brightness of supplement light, which is between 0 and 100; the brightness can be adjust when
<mode> is set to "on"-->
 </brightnessLimit>
 <supplementLightMode opt="mixed,whiteLight,close">
  <!--opt, xs: string, illumination mode: "mixed"-hybrid, "whitelight"-white light, "close"-disabled-->
 </supplementLightMode>
 <irLightBrightness min="0" max="100">
  <!--dep, xs: integer, brightness of IR supplement light, which is between 0 and 100; this node is valid only when
<supplementLightMode> is set to "mixed" and <mixedLightBrightnessRegulatMode> is set to "manual"-->
 </irLightBrightness>
 <mixedLightBrightnessRegulatMode opt="manual,auto">
  <!--dep, xs: string, brightness adjustment mode of hybrid supplement light; this node is valid only when
<supplementLightMode> is set to "mixed"-->
 </mixedLightBrightnessRegulatMode>
 <mixedModeSupportType opt="irLight,whiteLight">
  <!--dep, xs: string, light type of hybrid illumination mode, "irLight"-IR light, "whiteLight"-white light-->
 </mixedModeSupportType>
 <highIrLightBrightness min="0" max="100">
  <!--dep, xs: integer, brightness of far IR light, which is between 0 and 100; this node cannot be configured together
with node <irLightBrightness>-->
 </highIrLightBrightness>
 <highWhiteLightBrightness min="0" max="100">
  <!--dep, xs: integer, brightness of far white light, which is between 0 and 100; this node cannot be configured

together with node <brightnessLimit>-->
 </highWhiteLightBrightness>
 <lowIrLightBrightness min="0" max="100">
  <!--dep, xs: integer, brightness of near IR light, which is between 0 and 100; this node cannot be configured together
with node <irLightBrightness>-->
 </lowIrLightBrightness>
 <lowWhiteLightBrightness min="0" max="100">
  <!--dep, xs: integer, brightness of near white light, which is between 0 and 100; this node cannot be configured
together with node <brightnessLimit>-->
 </lowWhiteLightBrightness>
 <whiteLightBrightness min="0" max="100"><!--dep, xs: integer, white light brightness, which is between 0 and 100--
></whiteLightBrightness>
</SupplementLight>

16.2.74 XML_Cap_SyncSignalOutputList
SyncSignalOutputList capability message in XML format
<SyncSignalOutputList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IOOutNum min="3" max="8">
  <!--req, xs:string, number of IO outputs-->
 </IOOutNum>
 <SyncSignalOutput>
  <id min="1" max="8">
   <!--req, xs:integer, ID, which is between 1 and 8-->
  </id>
  <IOWorkMode opt="flashLight,polarizer,continuousLight,flashLightSwitch">
   <!--req, xs:string, IO output mode: "flashLight"-strobe light control mode, "polarizer"-polarizer control mode,
"continuousLight"-solid light control mode, "flashLightSwitch"-strobe light switching mode (used to switch between
the strobe supplement light mode and IR mode). When this node is set to "polarizer", only <outputStatus>,
<detectBrightnessEnable>, <brightnessThreshold>, <flashEnabled>, <startHour>, <startMinute>, <endHour>, and
<endMinute> are valid, and the <outputStatus> can only be set to "high" or "low". When this node is set to
"continuousLight", only <detectBrightnessEnable>, <brightnessThreshold>, <flashEnabled>, <startHour>,
<startMinute>, <endHour>, and <endMinute> are valid-->
  </IOWorkMode>
  <defaultStatus opt="hige,low">
   <!--req, xs:string, effective status-->
  </defaultStatus>
  <outputStatus opt="high,low,pulse">
   <!--req, xs:string, default status-->
  </outputStatus>
  <aheadTime min="" max="">
   <!--req, xs:integer, pre-output time-->
  </aheadTime>
  <timeDelay min="" max="">
   <!--req, xs:integer, output duration-->
  </timeDelay>
  <freqMultiplyulti min="1" max="15">
   <!--req, xs:integer, frequency multiplication, which is between 1 and 15-->
  </freqMultiplyulti>
  <dutyRate min="0" max="40">

    <!--req, xs:integer, duty ratio, which is between 0 and 40-->
  </dutyRate>
  <postFlashEnable>
    <!--req, xs:boolean-->
  </postFlashEnable>
  <illegalFlashEnable>
    <!--req, xs:boolean-->
  </illegalFlashEnable>
  <videoFlashEnable>
    <!--req, xs:boolean-->
  </videoFlashEnable>
  <detectBrightnessEnable>
    <!--req, xs:boolean-->
  </detectBrightnessEnable>
  <brightnessThreshold min="0" max="100">
    <!--dep, xs:integer, brightness threshold, which is between 0 and 100-->
  </brightnessThreshold>
  <flashEnabled>
    <!--req, xs:boolean-->
  </flashEnabled>
  <startHour min="" max="">
    <!--dep, xs:integer-->
  </startHour>
  <startMinute min="" max="">
    <!--dep, xs:integer-->
  </startMinute>
  <endHour min="" max="">
    <!--dep, xs:integer-->
  </endHour>
  <endMinute min="" max="">
    <!--dep, xs:integer-->
  </endMinute>
  <plateBrightness>
    <!--req, xs:boolean-->
  </plateBrightness>
  <incrBrightEnable>
    <!--opt, xs:boolean, whether to enable brightness enhancement mode (for solid light mode)-->
  </incrBrightEnable>
  <incrBrightTime min="0" max="10000">
    <!--req, xs:integer, brightness enhancement duration, which is between 0 and 10000, unit: millisecond. This node is
valid only when <incrBrightEnable> is "true"-->
  </incrBrightTime>
  <incrBrightPercent min="0" max="100">
    <!--req, xs:integer, percentage of brightness enhancement, which is between 0 and 100. This node is valid only
when <incrBrightEnable> is "true"-->
  </incrBrightPercent>
  <brightness min="0" max="100">
    <!--dep, xs:integer, solid light brightness (for solid light mode), which is between 0 and 100-->
  </brightness>
  <delayCaptureTime min="1" max="1000">
    <!--dep, xs:integer, delayed capture time, which is between 1 and 1000, unit: millisecond. This node is valid only
when <incrBrightEnable> is "true"-->

  </delayCaptureTime>
  <manualBrightnessEnable>
   <!--req, xs:boolean, whether to enable adjusting brightness manually-->
  </manualBrightnessEnable>
  <manualBrightness>
   <!--dep, xs:integer, brightness adjusted manually, which is between 0 and 100-->
  </manualBrightness>
 </SyncSignalOutput>
</SyncSignalOutputList>

16.2.75 XML_Cap_Telnetd
Telnetd capability message in XML format
<Telnetd version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled>
  <!--req, xs:boolean, whether to enable telnet: "true, false"-->
 </enabled>
 <radarMsgEnabled>
  <!--req, xs:boolean, whether to enable uploading radar debugging information: "true, false"-->
 </radarMsgEnabled>
 <illeagalLoginLock>
  <!--req, xs:boolean, "true, false"-->
 </illeagalLoginLock>
</Telnetd>

16.2.76 XML_Cap_tempRange
tempRange capability message in XML format
<?xml version="1.0" encoding="utf-8"?>
<TempRange version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  <mode opt="automatic,manual">
   <!--req, xs:string, temperature range mode: "automatic"-automatic mode, "manual"-manual mode-->
  </mode>
  <temperatureUpperLimit min="-20" max="550" def="150">
   <!--dep, xs:float, maximum temperature, corrects to one decimal, the minimum value is "-20", the maximum value
is "550", unit: Celsius degree; its value should be larger than temperatureLowerLimit; it is valid when the value of
mode is "manual"-->
  </temperatureUpperLimit>
  <temperatureLowerLimit min="-20" max="550" def="0">
   <!--dep, xs:float, minimum temperature, corrects to one decimal, the minimum value is "-20", the maximum value is
"550", unit: Celsius degree; its value should be smaller than temperatureUpperLimit; it is valid when the value of
mode is "manual"-->
  </temperatureLowerLimit>
</TempRange>

16.2.77 XML_Cap_Time
Time capability message in XML format
<Time version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <timeMode opt="NTP,manual, local,satellite,timecorrect" def="satellite"><!--req, xs:string--></timeMode>
 <localTime min="0" max="256">
  <!--dep, xs:datetime, this node is required when <timemode> is "manual" or "local"-->
 </localTime>
 <timeZone min="0" max="256">
  <!--dep, xs:string, POSIX time zone string, this node is required when <timemode> is "manual", "local" or "NTP"-->
 </timeZone>
 <satelliteInterval min="" max="">
  <!--dep, xs:integer, minutes, time synchronization interval of locating by satellite, this node is valid only when
<timemode> is "satellite"-->
 </satelliteInterval>
 <timeType opt="local, UTC">
  <!--opt, xs: string, time type, it can be local, or UTC, or local and UTC. If this node is not returned, it indicates that
device does not support getting or setting time type-->
 </timeType>
</Time>

16.2.78 XML_Cap_Track
Track capability message in XML format
<Track version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--xs:integer, the value of <id> and <Channel> is the same. For example, 201 refers to the main stream of
channel 1, 202 refers to the sub-stream of channel 2, and so on--></id>
 <Channel><!--req, xs:integer--></Channel>
 <Enable><!--req, xs:boolean--></Enable>
 <Description><!--req, xs:string, e.g., trackType=standard,sourceTag=AXIS210a,contentType=video,codecType=MPEG4-
SP,resolution=640x480,frameRate=20 fps,bitrate=6000 kbps--></Description>
 <TrackGUID><!--req, xs:string, GUID generated by the client, e.g., A01AAAAA-BBBB-CCCC-DDDD-033595353625--></
TrackGUID>
 <Size><!--opt, xs:integer--></Size>
 <Duration min="0" max="750"><!--opt, xs:string, video expiry date, e.g., P10DT15H indicates that the video will
expire after 10 days and 15 hours--></Duration>
 <DefaultRecordingMode opt="CMR,MOTION,ALARM,EDR,ALARMANDMOTION,AllEvent,POS"><!--req, xs:string,
default video type--></DefaultRecordingMode>
 <LoopEnable><!--opt, xs:boolean, whether to support recurrently overwriting--></LoopEnable>
 <SrcDescriptor><!--video source description-->
  <SrcGUID><!--req, xs:string, GUID generated by the device, e.g., E800A543-9D53-4520-8BB8-9509062C692D--></
SrcGUID>
  <SrcChannel><!--req, xs:integer, source channel--></SrcChannel>
  <StreamHint><!--req, xs:string, e.g., "video, mp4, 640x480, 20 fps, 6000 kbps"--></StreamHint>
  <SrcDriver><!--req, xs:string, stream executable driver name, e.g., RTP/RTSP--></SrcDriver>
  <SrcType><!--opt, xs:string, source type, e.g., "mp4", "video"--></SrcType>
  <SrcUrl opt="rtsp://localhost/PSIA/Streaming/channels/101,rtsp://localhost/PSIA/Streaming/channels/102,rtsp://

localhost/PSIA/Streaming/channels/103,,rtsp://localhost/PSIA/Streaming/channels/107"><!--req, xs:string, e.g.,
rtsp://10.3.2.26/mpeg4/media.amp--></SrcUrl>
   <SrcUrlMethods><!--req, xs:string, methods supported by the source: "DESCRIBE,SETUP,PLAY,TEARDOWN"--></
SrcUrlMethods>
   <SrcLogin><!--req, xs:string, login source password--></SrcLogin>
 </SrcDescriptor>
 <TrackSchedule><!--recording schedule-->
   <ScheduleBlockList>
    <ScheduleBlock><!--list, recording schedule list-->
     <ScheduleBlockGUID><!--xs:string, schedule GUID, e.g., ABC12345-CDEF-4520-8BB8-7135789C8790--></
ScheduleBlockGUID>
     <ScheduleBlockType><!--req, xs:string--></ScheduleBlockType>
     <ScheduleAction><!--list-->
      <id><!--req, xs:integer--></id>
      <ScheduleActionStartTime><!--start time of the schedule-->
       <DayOfWeek><!--req, xs:string, "Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday"--></
DayOfWeek><!--inclusive-->
       <TimeOfDay><!--xs:time, 00:00:00--></TimeOfDay>
      </ScheduleActionStartTime>
      <ScheduleActionEndTime><!--end time of the schedule-->
       <DayOfWeek><!--req, xs:string, "Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday"--></
DayOfWeek><!--exclusive-->
       <TimeOfDay><!--xs:time, 08:00:00--></TimeOfDay>
      </ScheduleActionEndTime>
      <ScheduleDSTEnable><!--req, xs:boolean, whether to enable DST (daylight saving time)--></ScheduleDSTEnable>
      <Description><!--req, xs:string, PreMorning (midnight to 8 a.m., local time)--></Description>
      <Actions><!--alarm or motion detection that triggers recording-->
       <Record><!--opt, xs:boolean--></Record>
       <Log><!--opt, xs:boolean--></Log>
       <SaveImg><!--opt, xs:boolean--></SaveImg>
       <ActionRecordingMode><!--req, xs:string, recording schedule type:
"CMR,EDR,ALARM,MOTION,ALARMANDMOTION,COMMAND,SMART"--></ActionRecordingMode>
       <PreRecordTimeSeconds><!--opt, xs:integer, pre-record time, it is between 0 and 10 and the default value is 5,
unit: second--></PreRecordTimeSeconds>
       <PostRecordTimeSeconds><!--opt, xs:integer, post-record time, it is between 0 and 20 and the default value is
5, unit: second--></PostRecordTimeSeconds>
      </Actions>
     </ScheduleAction>
    </ScheduleBlock>
   </ScheduleBlockList>
 </TrackSchedule>
 <CustomExtensionList>
   <CustomExtension>
    <CustomExtensionName><!--opt, xs:string, example: www.isapi.com/RaCM/trackExt/ver10--></
CustomExtensionName>
    <enableSchedule><!--opt, xs:boolean, whether to enable recording schedule configuration--></enableSchedule>
    <SaveAudio><!--opt, xs:boolean, whether to enable recording audio--></SaveAudio>
    <PreRecordTimeSeconds><!--opt, xs:integer, pre-record time, unit: second--></PreRecordTimeSeconds>
    <PostRecordTimeSeconds><!--opt, xs:integer, post-record time, unit: second--></PostRecordTimeSeconds>
    <HolidaySchedule>
     <ScheduleBlock>
      <ScheduleBlockGUID><!--req, xs:string, example: 00000000-0000-0000-0000-000000000000--></

ScheduleBlockGUID>
     <ScheduleBlockType><!--opt, xs:string, e.g., www.isapi.com/racm/schedule/ver10--></ScheduleBlockType>
    </ScheduleBlock>
   </HolidaySchedule>
  </CustomExtension>
 </CustomExtensionList>
 <IntelligentRecord><!--opt, xs:boolean, whether to enable VCA recording function: 0-no, 1-yes--></IntelligentRecord>
 <delayTime opt="0,3,4,5,10,30,60,120,300"><!--opt, xs:integer, capture delay time, unit: second--></delayTime>
 <durationEnabled opt="true,false"><!--opt, xs:boolean, whether to enable video expiry time. If this function is not
supported, this node will not be returned. If this function is supported, the video expiry date will be set by the node
<Duration>--></durationEnabled>
</Track>

16.2.79 XML_Cap_VCAResource
VCAResource message in XML format
<VCAResource version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <type
opt="basicBehavior,fullBehavior,facesnapBehavior,facesnap,TFS,smartVehicleDetection,smartHVTDetection,smart,judic
ial,smart264AndRoadDetection,smart264AndFaceDetection,smart264AndHeatMap,smartVehicleIllegalParkingDetectio
n,smartIntelligentMonitor,smartTrafficDataCollection, roadDetection,humanRecognition, perimeterCapture,
vehicleDetection,HVTDetection,mixedTargetDetection,trackingCaptureMode,nonTrackingCaptureMode,close,faceHum
anModelingContrast,cityManagement,teacherBehavior,
12MPLiveView,personQueueDetection,verticalPeopleCounting,safetyHelmet">
   <!--req, xs: string, intelligent resource types, "trackingCaptureMode"-panoramic capture mode,
"nonTrackingCaptureMode"-single target capture mode, "faceHumanModelingContrast"-resources of face/human
body+face modeling+face picture comparison, "verticalPeopleCounting"-vertical people counting, "safetyHelmet"-
hard hat detection-->
 </type>
 <PromptList><!--opt, prompt for switching intelligent resources-->
   <Prompt><!--list-->
    <resourceType opt="roadDetection">
     <!--opt, xs: string, intelligent resource to prompt, currently, only "roadDetection" is supported-->
    </resourceType>
    <resourcePrompt opt="smartCode">
     <!--opt, xs: string, prompt contents-->
    </resourcePrompt>
   </Prompt>
 </PromptList>
</VCAResource>

16.2.80 XML_Cap_VideoInputChannel
VideoInputChannel capability message in XML format
<VideoInputChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs: string--></id>
 <inputPort><!--req, xs: string--></inputPort>

 <videoInputEnabled><!--opt, xs: boolean--></videoInputEnabled>
 <name><!--opt, xs: string--></name>
 <videoFormat opt="PAL,NTSC"><!--opt, xs: string, video standards--></videoFormat>
 <portType opt="SDI,OPT,VGA,HDMI,YPbPr"><!--opt, xs: string, port type--></portType>
 <resDesc><!--opt, xs: string--></resDesc>
</VideoInputChannel>

16.2.81 XML_Cap_VideoOutputChannel
VideoOutputChannel capability message in XML format
<VideoOutputChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs: string; ID--></id>
 <type opt="VGA,CVBS,HDMI,Spot,SDI,LCD"><!--req, xs: string, video output type--></type>
 <menu><!--dep, read-only-->
  <mirrorMenu><!--req, xs: boolean--></mirrorMenu>
 </menu>
 <mode opt="close,clip,scale,open,SDI_1080P25,…,HDMI_1080P,HDMI_720P,HDMI_ 2160P">
  <!--opt, xs: string, video output mode-->
 </mode>
 <resolution opt="1920*1080/60HZ,1280*720/50HZ,…"><!--opt, xs: string, video resolution--></resolution>
</VideoOutputChannel>

16.2.82 XML_Cap_VideoOverlay
VideoOverlay capability message in XML format
<VideoOverlay version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <normalizedScreenSize>
  <!--req-->
  <normalizedScreenWidth>
   <!--ro, req, xs:integer-->
  </normalizedScreenWidth>
  <normalizedScreenHeight>
   <!--ro, req, xs:integer-->
  </normalizedScreenHeight>
 </normalizedScreenSize>
 <attribute>
  <!--opt-->
  <transparent>
   <!--req, xs:boolean-->
  </transparent>
  <flashing>
   <!--req, xs:boolean-->
  </flashing>
 </attribute>
 <TextOverlayList/><!--opt, see details in the message of XML_TextOverlayList-->
 <DateTimeOverlay/><!--opt, see details in the message of XML_DateTimeOverlay-->
 <channelNameOverlay/><!--opt, see details in the message of XML_channelNameOverlay-->

 <fontSize>
  <!--opt, xs:string, "adaptive,16*16,32*32,48*48,64*64,80*80,96*96,112*112,128*128"-->
 </fontSize>
 <frontColorMode>
  <!--opt, string, "auto,customize"-->
 </frontColorMode>
 <frontColor>
  <!--dep, xs:hexBinary;color-->
 </frontColor>
 <BatteryPowerOverlay/><!--opt, see details in the message of XML_BatteryPowerOverlay-->
 <alignment opt="customize,alignRight,alignLeft">
  <!--opt, xs:string, "customize,alignRight,alignLeft"-->
 </alignment>
 <publicSecurity>
  <!--req, xs:boolean-->
 </publicSecurity>
 <DeviceStatusDisplay><!--opt-->
  <batteryCapacityDisplay>
   <!--opt, xs:boolean-->
  </batteryCapacityDisplay>
  <chargingStatusDisplay>
   <!--opt, xs:boolean-->
  </chargingStatusDisplay>
  <bluetoothStatusDisplay>
   <!--opt, xs:boolean-->
  </bluetoothStatusDisplay>
  <dialStatusDisplay>
   <!--opt, xs:boolean-->
  </dialStatusDisplay>
 </DeviceStatusDisplay>
 <boundary>
  <!--opt, xs:integer-->
 </boundary>
</VideoOverlay>

See Also
XML_TextOverlayList
XML_DateTimeOverlay
XML_channelNameOverlay
XML_BatteryPowerOverlay

16.2.83 XML_Cap_Wireless
Wireless capability message in XML format
<Wireless version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs:boolean--></enabled>
 <wirelessNetworkMode opt="infrastructure,adhoc"><!--opt, xs:string--></wirelessNetworkMode>
 <channel opt="1,2,3,4,5,6,7,8,9,10,11,12,13,14,auto"><!--opt, xs:string--></channel>
 <ssid min="" max=""><!--opt, xs:string--></ssid>

<wmmEnabled><!--opt, xs:boolean--></wmmEnabled>
<WirelessSecurity><!--opt-->
 <securityMode opt ="disable,WEP,WPA-personal,WPA2-personal,WPA-RADIUS,WPA-enterprise,WPA2-enterprise">
  <!--opt, xs:string-->
 </securityMode>
 <WEP><!--dep, this node depends on <securityMode>-->
  <authenticationType opt = "open,sharedkey,auto"><!--req, xs:string--></authenticationType>
  <defaultTransmitKeyIndex min="" max=""><!--req, xs:integer--></defaultTransmitKeyIndex>
  <wepKeyLength opt="64,128"><!--opt, xs:integer--></wepKeyLength>
  <EncryptionKeyList>
    <encryptionKey>
     <!--req, xs:hexBinary, WEP encryption key in hexadecimal format-->
    </encryptionKey>
  </EncryptionKeyList>
 </WEP>
 <WPA><!--dep, depends on <securityMode>-->
  <algorithmType opt="TKIP,AES,TKIP/AES"><!--req, xs:string--></algorithmType>
  <sharedKey><!-- req, xs:string, pre-shared key used in WPA--></sharedKey>
  <wpaKeyLength min="8" max="64"><!--req, xs: integer--></wpaKeyLength>
 </WPA>
 <support64bitKey opt="WPA-personal, WPA2-personal"/><!--opt, xs:string--></support64bitKey>
</WirelessSecurity>
<AccessPointList>
 <InterfaceDisplay><!--opt-->
  <TableElementList>
    <TableElement>
     <!--opt,xs:string,opt="SSID,workingMode,securityMode,channel,signalStrength, speed,connectionStatus"-->
    </TableElement>
  </TableElementList>
 </InterfaceDisplay>
</AccessPointList>
<isSupportConnectStatus>
 <!-- opt, xs:boolean, whether supports Wi-Fi connection status-->
</isSupportConnectStatus>
<workScene opt="computerRoom,monitorTerminal"><!--opt, xs:string，working scenario--></workScene>
<protocol opt="802.11ac"><!--req,xs:string, protocol mode--></protocol>
<hideSsid><!--opt, xs:boolean--></hideSsid>
<ChannelConfig><!--opt-->
 <transmitPower opt="9,12,15,18,21,24,27"><!--opt, xs:integer, unit: dBm--><transmitPower>
 <ChannelCountryList><!--opt>
  <Country>
    <countryID><!--req, xs:integer, country code--></countryID>
    <ChannelList>
     <Node>
      <width opt="auto,20,40,80"><!--req, xs:string, bandwidth, unit: MHz--></width>
      <channel><!--req,dep, xs:string, unit: MHz></channel>
     </Node>
    </ChannelList>
  </Country>
 </ChannelCountryList>
</ChannelConfig>
<isSupportNullSsid>

  <!--opt, xs: boolean, whether supports setting SSID to null, if supports, return "true", otherwise, this node will not
be returned. If the SSID is empty, the device will filter the SSID configuration when configuring Wi-Fi-->-->
 </isSupportNullSsid>
</Wireless>

16.2.84 XML_Cap_WirelessServer
WirelessServer capability message in XML format
<WirelessServer version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <wifiApEnabled opt="true,false"><!--opt,xs: boolean,--></wifiApEnabled>
 <broadcastEnabled opt="true,false"><!--opt,xs: boolean--></broadcastEnabled>
 <wlanShareEnabled opt="true,false"><!--opt,xs: boolean--></wlanShareEnabled>
 <ssid min="" max=""><!--opt, xs: string--></ssid>
 <WirelessSecurity><!--req-->
  <securityMode opt="disable,WEP,WPA-personal,WPA2-personal,WPA-RADIUS,WPA-enterprise,WPA2-enterprise">
   <!--opt, xs: string-->
  </securityMode>
  <WEP><!--dep, depends on <securityMode>-->
   <authenticationType opt="open,sharedkey,auto">
    <!--req, xs: string-->
   </authenticationType>
   <defaultTransmitKeyIndex min="" max="">
    <!--req, xs: integer-->
   </defaultTransmitKeyIndex>
   <wepKeyLength opt="64,128"><!--opt, xs: integer--></wepKeyLength>
   <EncryptionKeyList size="">
    <encryptionKey>
      <!--req, xs: hexBinary, WEP encryption key in hexadecimal format-->
    </encryptionKey>
   </EncryptionKeyList>
  </WEP>
  <WPA><!--dep, depends on <securityMode>-->
   <algorithmType opt="TKIP,AES,TKIP/AES">
    <!--req, xs: string, "TKIP,AES,TKIP/AES"-->
   </algorithmType>
   <sharedKey><!--opt, xs: string, shared key used in WPA--></sharedKey>
   <wpaKeyLength min="" max=""><!-- opt, xs: integer, the ley length is between 8 and 63--></wpaKeyLength>
   <defaultPassword><!--opt, xs: boolean--></defaultPassword>
  </WPA>
 </WirelessSecurity>
 <DHCPEnabled opt="true,false"><!--opt, xs: boolean--></DHCPEnabled>
 <ipVersion opt="v4,v6"><!--opt, xs:string--></ipVersion>
 <HostIpAddress><!--opt-->
  <ipAddress><!--dep, xs:string--></ipAddress>
  <ipv6Address><!--dep, xs:string--></ipv6Address>
 </HostIpAddress>
 <IPMask><!--opt-->
  <subnetMask><!--dep, xs:string, subnet mask for IPv4 address--></subnetMask>
  <bitMask><!--dep, xs:integer, bitmask IPv6 address--></bitMask>
 </IPMask>

 <AddressPool><!--opt-->
  <startIPV4Address><!--dep, xs:string--></startIPV4Address>
  <endIPV4Address><!--dep, xs:string--></endIPV4Address>
  <startIPV6Address><!-- dep, xs:string--></startIPV6Address>
  <endIPV6Address><!--dep, xs:string--></endIPV6Address>
 <AddressPool>
 <DNSAddressList size="2"><!--opt-->
  <DNSAddress><!--opt>
   <id><!--opt,xs:string,start from 1--></id>
   <ipAddress><!--dep, xs: string--></ipAddress>
   <ipv6Address><!--dep, xs: string--></ipv6Address>
  </DNSAddress>
 </DNSAddressList>
 <GatewayAddress>
  <ipAddress><!--dep, xs:string--></ipAddress>
  <ipv6Address><!--dep, xs:string--></ipv6Address>
 <GatewayAddress>
 <wifiApModeType opt="true,false,auto">
  <!--opt, xs: string, current wireless access point (AP) mode, if this node is returned, it indicates that the device
supports auto mode-->
 </wifiApModeType>
</WirelessServer>

Remarks
For Client supports auto AP, the node <<wifiApModeType> is valid; for Client does not supports
auto AP, the node <wifiApEnabled> is valid; the values of these two nodes will effect each other,
and when <wifiApModeType> equals to "auto", the value of <wifiApEnabled> is "true".

16.2.85 XML_Cap_WirelessServerStatus
WirelessServerStatus capability message in XML format
<WirelessServerStatus version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <wifiApEnabled>
  <!--dep, xs:boolean-->
 </wifiApEnabled>
 <linkDevices min="0" max="20">
  <!--dep, xs:integer, maximum number of linked devices-->
 </linkDevices>
 <DeviceInfoList size="20">
  <!--opt-->
  <DeviceInfo>
    <!--opt-->
    <IpAddress>
     <!--req-->
     <ipAddress>
      <!--dep, xs:string-->
     </ipAddress>
     <ipv6Address>
      <!--dep, xs:string-->

    </ipv6Address>
   </IpAddress>
   <hostName>
    <!--opt, xs:string-->
   </hostName>
   <macAddress>
    <!--opt, xs:string-->
   </macAddress>
  </DeviceInfo>
 </DeviceInfoList>
</WirelessServerStatus>

16.2.86 XML_Cap_WirelessStatus
WirelessStatus capability message in XML format
<WirelessStatus version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled>
  <!--dep, xs:boolean-->
 </enabled>
 <connectionEnabled>
  <!--dep, xs:boolean-->
 </connectionEnabled>
 <IpAddress>
  <!--req-->
  <ipAddress>
   <!--dep, xs:string-->
  </ipAddress>
  <ipv6Address>
   <!--dep, xs:string-->
  </ipv6Address>
 </IpAddress>
 <SubnetMask>
  <!--req-->
  <ipAddress>
   <!--dep, xs:string-->
  </ipAddress>
  <ipv6Address>
   <!--dep, xs:string-->
  </ipv6Address>
 </SubnetMask>
 <RouterAddress>
  <!--req-->
  <ipAddress>
   <!--dep, xs:string-->
  </ipAddress>
  <ipv6Address>
   <!--dep, xs:string-->
  </ipv6Address>
 </RouterAddress>
 <DNSAddressList size="2">

  <!--opt-->
  <DNSAddress>
   <!--opt-->
   <id>
    <!--opt, xs:string, DNS address ID, which starts from 1-->
   </id>
   <ipAddress>
    <!--dep, xs:string-->
   </ipAddress>
   <ipv6Address>
    <!--dep, xs:string-->
   </ipv6Address>
  </DNSAddress>
 </DNSAddressList>
</WirelessStatus>

16.2.87 XML_CaptureMode
CaptureMode message in XML format
<CaptureMode version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <mode>
  <!--req, xs: string, video input mode: 1-640×480@30fps, 2-4CIF@30fps, 3-720P@25fps, 4-720P@30fps,
5-720P@60fps, 6-1280×960@15fps, 7-1280×960@25fps, 8-1280×960@30fps, 9-1280×1024@30fps,
10-1600×900@15fps, 11-1600×1200@15fps, 12-1080P@15fps, 13-1080P@25fps, 14-1080P@30fps,
15-1080P@50fps, 16-1080P@60fps, 17-2048×1536@15fps, 18-2048×1536@20fps, 19-2048×1536@24fps,
20-2048×1536@25fps, 21-2048×1536@30fps, 22-2560×2048@25fps, 23-2560×2048@30fps, 24-2560×1920@7.5fps,
25-3072×2048@30fps, 26-1944×1212@24fps, 27-1944×1212@25fps-->
 </mode>
</CaptureMode>

16.2.88 XML_CertificateInfo
CertificateInfo message in XML format
<CertificateInfo version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs: string--></id>
 <version><!--opt, xs: string--></version>
 <IssuerDN><!--req, isapi:DN-->
  <countryName><!--req, xs: string--></countryName>
  <stateOrProvinceName><!--opt, xs: string--></stateOrProvinceName>
  <localityName><!--opt, xs: string--></localityName>
  <organizationName><!--opt, xs: string--></organizationName>
  <organizationUnitName><!--opt, xs: string--></organizationUnitName>
  <commonName><!--req, xs: string--></commonName>
  <email><!--opt, xs: string--></email>
 </IssuerDN>
 <SubjectDN><!--req,isapi:DN-->
  <countryName><!--req, xs: string--></countryName>

  <stateOrProvinceName><!--opt, xs: string--></stateOrProvinceName>
  <localityName><!--opt, xs: string--></localityName>
  <organizationName><!--opt, xs: string--></organizationName>
  <organizationUnitName><!--opt, xs: string--></organizationUnitName>
  <commonName><!--req, xs: string--></commonName>
  <email><!--opt, xs: string--></email>
 </SubjectDN>
 <signatureAlgorithm><!--req, xs: string, signature algorithm: RSA_3, RSA_F4--></signatureAlgorithm>
 <keyAlgorithm><!--opt, xs: string--></keyAlgorithm>
 <startDate><!--req, xs: time, in ISO8601 time format--></startDate>
 <endDate> !--req, xs: time, in ISO8601 time format--></endDate>
 <serialNumber><!--req, xs: string, uuid--></serialNumber>
</CertificateInfo>

16.2.89 XML_CertificateReq
CertificateReq message in XML format
<CertificateReq version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs: string--></id>
 <SubjectDN><!--req, isapi:DN-->
  <countryName><!--req, xs: string--></countryName>
  <stateOrProvinceName><!--opt, xs: string--></stateOrProvinceName>
  <localityName><!--opt, xs: string--></localityName>
  <organizationName><!--opt, xs: string--></organizationName>
  <organizationUnitName><!--opt, xs: string--></organizationUnitName>
  <commonName><!--req, xs: string --></commonName>
  <email><!--opt, xs: string--></email>
 </SubjectDN>
 <validity><!--opt, xs: integer, expiry date, which is between 1 and 5000--></validity>
 <passwd><!--opt, xs: string, password to protect private key--></passwd>
 <RSAKeyLength><!--opt, xs: integer--></RSAKeyLength>
</CertificateReq>

16.2.90 XML_CertificateReq_ImportCert
CertificateReq message in XML format
<CertificateReq version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <certificateMode><!--opt, xs:string, importing method: "signingRequest"-signature request (import self-signed
certificate), "privateKey"-private key--></certificateMode>
 <privateKeyMode><!--dep, xs:string, private key mode: "seperateKey", "PKCS#12"--></privateKeyMode>
 <seperateKeyPassword><!--dep, xs:string, password in seperateKey mode, it should be encrypted--></
seperateKeyPassword>
 <PKCSPassword><!--dep, xs:string, password in PKCS#12 mode, it should be encrypted--></PKCSPassword>
 <dataType><!--dep, xs:string, data type: "certificate", "privateKey"-private key--><dataType>
</CertificateReq>

16.2.91 XML_CertificateReqInfo
CertificateReqInfo message in XML format
<CertificateReqInfo version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs: string--></id>
 <SubjectDN><!--req, isapi:DN-->
  <countryName><!--req, xs: string--></countryName>
  <stateOrProvinceName><!--opt, xs: string--></stateOrProvinceName>
  <localityName><!--opt, xs: string--></localityName>
  <organizationName><!--opt, xs: string--></organizationName>
  <organizationUnitName><!--opt, xs: string--></organizationUnitName>
  <commonName><!--req, xs: string --></commonName>
  <email><!--opt, xs: string--></email>
 </SubjectDN>
 <version><!--opt, xs: string--></version>
 <validity><!--opt, xs:int, expiry date, which is between 1 and 5000--></validity>
 <keyAlgorithm><!--opt, xs: string--></keyAlgorithm>
 <passwd><!--opt, xs: string, password to protect private key--></passwd>
 <RSAKeyLength><!--opt, xs: integer--></RSAKeyLength>
</CertificateReqInfo>

16.2.92 XML_CertificateResult
CertificateResult message in XML format
<CertificateResult version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <formatType><!--req, xs:string, certificate format, e.g., "PEM"--><formatType>
 <detailInfo><!--req, xs:string, certificate details--></detailInfo>
</CertificateResult>

16.2.93 XML_Challenge
Challenge message in XML format.
<Challenge version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <key><!--req, xs:string--></key>
</Challenge>

16.2.94 XML_ChanCtrl
ChanCtrl message (for traffic) in XML format
<ChanCtrl version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <streamGetType><!--streaming mode: 0-live view mode (default), 1-data receiving mode--></streamGetType>
</ChanCtrl>

16.2.95 XML_ChannelEventCap
ChannelEventCap message in XML format
<ChannelEventCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <eventType opt="VMD,motionDetection,shelteralarm,
tamperDetection,videoLoss,ROI,facedetection,faceDetection,intelliTrace,fielddetection,fieldDetection,defocus,defocus
Detection,audioexception,audioDetection,scenechangedetection,sceneChangeDetection,linedetection,lineDetection,r
egionEntrance,regionExiting,loitering,group,rapidMove,parking,unattendedBaggage,attendedBaggage,peopleDetectio
n,storageDetection,behavior,faceCapture,faceSnap,ANPR,vehicleDetection,fireDetection,shipsDetection,PIR,targetCapt
ure,humanRecognition,alarmResult,faceContrast,framesPeopleCounting,hide,audioLoss,cameraAngleAnormaly,violent
Motion,trial,humanEnter,operateOverTime,stickUp,installScanner,faceDetect,temperature,temperatureDetection,peop
leCounting,personQueueDetection,heatmap,mixedTargetDetection,MTD_face,MTD_human,MTD_vehicle,MTD_nonM
otor,faceSnapModeling,HVTVehicleDetection,PictureCaptureComparision,IO,smokeDetection,smokeAndFireDetection,
diskfull,diskerror,nicbroken,ipconflict,illaccess,personDensityDetection,AID,vehicleControl,vehicleRcogResult,cardMatc
h,overSpeed,highTempAlarm,abnormalAcceleration,failDown,leavePosition,peopleNumChange,retention,running,ther
mometry,heatmapPDC,heatmapDuration,intersectionAnalysis,AID_abandonedObject,AID_pedestrian,AID_congestion,
AID_roadBlock,AID_construction,AID_trafficAccident,AID_fogDetection,TFS_illegalParking,TFS_wrongDirection,TFS_cro
ssLane,TFS_laneChange,TFS_vehicleExist,TFS_turnRound,TFS_parallelParking,TPS,luma,chroma,snow,streak,freeze,sigLo
se,clarity,jitter,block,flowers,noise,ghost,purple,ICR,protectiveFilm"/>
  <!--req, xs:string, event types supported by the channel-->
 <shieldEventType opt="behavior,faceSnap,humanRecognition,faceCapture,targetCapture"/>
  <!--req, xs:string, event types that support area shield-->
 <channelID><!--opt, xs:integer, current device channel No.--></channelID>
 <id><!--req, xs:integer--></id>
</ChannelEventCap>

Remarks
The node <eventType> can be set to the following values: VMD, motionDetection, shelteralarm,
tamperDetection, videoLoss, ROI, facedetection, faceDetection, intelliTrace, fielddetection,
fieldDetection, defocus, defocusDetection, audioexception, audioDetection,
scenechangedetection, sceneChangeDetection, linedetection, lineDetection, regionEntrance,
regionExiting, loitering, group, rapidMove, parking, unattendedBaggage, attendedBaggage,
peopleDetection, storageDetection, behavior, faceCapture, faceSnap, ANPR, vehicleDetection,
fireDetection, shipsDetection, PIR, targetCapture, humanRecognition, alarmResult, faceContrast,
framesPeopleCounting, hide, audioLoss, cameraAngleAnormaly, violentMotion, trial, humanEnter,
operateOverTime, stickUp, installScanner, faceDetect, temperature, temperatureDetection,
peopleCounting, personQueueDetection, heatmap, mixedTargetDetection, MTD_face,
MTD_human, MTD_vehicle, MTD_nonMotor, faceSnapModeling, HVTVehicleDetection,
PictureCaptureComparision, IO, smokeDetection, smokeAndFireDetection, diskfull, diskerror,
nicbroken, ipconflict, illaccess, personDensityDetection, AID, vehicleControl, vehicleRcogResult,
cardMatch, overSpeed, highTempAlarm, abnormalAcceleration, failDown, leavePosition,
peopleNumChange, retention, running, thermometry, heatmapPDC, heatmapDuration,
intersectionAnalysis, AID_abandonedObject, AID_pedestrian, AID_congestion, AID_roadBlock,
AID_construction, AID_trafficAccident, AID_fogDetection, TFS_illegalParking, TFS_wrongDirection,
TFS_crossLane, TFS_laneChange, TFS_vehicleExist, TFS_turnRound, TFS_parallelParking, TPS, luma,

chroma, snow, streak, freeze, sigLose, clarity, jitter, block, flowers, noise, ghost, purple, ICR,
protectiveFilm, certificateRevocation.
                 Event Type                                           Description
VMD (motionDetection)                          Motion detection
Shelteralarm (tamperDetection)                 Video tampering alarm
videoLoss                                      Video loss
ROI                                            Region of interest
facedetection (faceDetection)                  Face detection
intelliTrace                                   Auto-track
fielddetection (fieldDetection)                Intrusion detection
defocus (defocusDetection)                     Defocus detection
audioexception (audioDetection)                Audio exception detection
scenechangedetection                           Sudden scene change detection
(sceneChangeDetection)
linedetection (lineDetection)                  Line-crossing detection
regionEntrance                                 Region entrance detection
regionExiting                                  Region exiting detection
loitering                                      Loitering detection
group                                          People gathering detection
rapidMove                                      Fast moving detection
parking                                        Parking detection
unattendedBaggage                              Unattended baggage
attendedBaggage                                Object removal detection
peopleDetection                                Human detection
storageDetection                               HDD health detection
behavior                                       Behavior analysis
faceCapture(faceSnap)                          Face capture
ANPR(vehicleDetection)                         Vehicle detection
fireDetection                                  Fire detection
shipsDetection                                 Ship detection

                 Event Type                                 Description
PIR                                   PIR alarm
targetCapture (humanRecognition)      Target capture
alarmResult (faceContrast)            Face comparison
framesPeopleCounting                  People counting in single frame
hide                                  Tampering detection
audioLoss                             Audio loss
cameraAngleAnormaly                   Image exception
violentMotion                         Violent motion
trial                                 Tailing
humanEnter                            Human entrance
operateOverTime                       Operation timed out
stickUp                               Sticking scrip
installScanner                        Installing scanner
faceDetect                            ATM face detection
temperature (temperatureDetection)    Temperature difference detection
PeopleCounting                        People counting
personQueueDetection                  People queuing-up detection
heatmap                               Heat map
mixedTargetDetection                  Multi-target-type detection
MTD_face                              Supported face attributes of multi-target-type
                                      detection (MTD)
MTD_human                             Supported human attributes of multi-target-type
                                      detection (MTD)
MTD_vehicle                           Supported motor vehicle attributes of multi-target-
                                      type detection (MTD)
MTD_nonMotor                          Supported non-motor vehicle attributes of multi-
                                      target-type detection (MTD)
faceSnapModeling                      Face capture modeling
HVTVehicleDetection                   Mixed-traffic detection
PictureCaptureComparision             N:1 face comparison

                 Event Type                                    Description
IO                                     Sensor alarm
smokeDetection                         Smoke detection
smokeAndFireDetection                  Smoke and fire detection
diskfull                               HDD is full
diskerror                              HDD error
nicbroken                              Network disconnected
ipconflict                             IP address conflicted
illaccess                              Illegal access
personDensityDetection                 People density detection
vehicleControl                         Upload alarm of vehicle in whitelist and blacklist
vehicleRcogResult                      Vehicle secondary recognition
cardMatch                              Authentication
overSpeed                              Overspeed alarm
highTempAlarm                          High temperature alarm
abnormalAcceleration                   Abnormal accelerated speed alarm
failDown                               People falling down
leavePosition                          Absence detection
peopleNumChange                        The number of people changed
retention                              Overstay detection
running                                Running
thermometry                            Temperature measurement
heatmapPDC                             Heat map people counting
heatmapDuration                        Heat map people staying duration
intersectionAnalysis                   Intersection analysis
AID_abandonedObject                    Thrown object in traffic events
AID_pedestrian                         Pedestrian detection in traffic events
AID_​congestion                        Congestion detection in traffic events
AID_roadBlock                          Roadblock detection in traffic events
AID_​construction                      Construction detection in traffic events

                 Event Type                                  Description
AID_​trafficAccident                Traffic accident detection in traffic events
AID_​fogDetection                   Fog detection in traffic events
TFS_illegalParking                  Illegal parking of enforcement events
TFS_​wrongDirection                 Wrong-way driving of enforcement events
TFS_crossLane                       Driving on lane line of enforcement events
TFS_laneChange                      Lane change of enforcement events
TFS_vehicleExist                    Vehicle existing of enforcement events
TFS_turnRound                       Turning round of enforcement events
TFS_parallelParking                 Parallel parking of enforcement events
TPS                                 Traffic data collection configuration
luma                                Brightness exception
chroma                              Color cast detection
snow                                Snow noise
streak                              Stripe noise
freeze                              Image freeze
sigLose                             Signal loss
clarity                             Clarity exception
jitter                              Image flutter
block                               Video tampering
flowers                             Blurred screen detection
noise                               Image noise
ghost                               Abnormal light spot detection
purple                              Image purple edge detection
ICR                                 ICR exception detection
protectiveFilm                      Protective film unremoved
certificateRevocation               Certificate is expired

     Note
The following event type values are updated to new version: VMD (motionDetection), Shelteralarm
(tamperDetection), facedetection (faceDetection), fielddetection (fieldDetection), defocus
(defocusDetection), audioexception (audioDetection), scenechangedetection
(sceneChangeDetection), linedetection (lineDetection), faceCapture (faceSnap), ANPR
(vehicleDetection), targetCapture (humanRecognition), alarmResult (faceContrast), and
temperature (temperatureDetection). The value in the bracket is the old version, and considering
the compatibility, both new and old value should be returned.

16.2.96 XML_ChannelInfo
ChannelInfo message in XML format.
<ChannelInfo version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:integer, channel number--></id>
 <EagleEye>
  <!--opt, the channel supports the functions of PanoVu series camera-->
  <StreamFusion>
   <!--opt, "panoramic + PTZ camera streaming channel, it is not returned when not support-->
   <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
  </StreamFusion>
  <PanoramicMetaData>
   <!--opt, panoramic camera streaming channel, it is not returned when not support-->
   <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
  </PanoramicMetaData>
 </EagleEye>
 <FishEye>
  <!--opt, the channel supports the functions of fisheye camera-->
   <FishEyeStream>
    <!--opt, fisheye camera stream, it is used for software decoding of play library, it is not returned when not
support-->
  <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
   </FishEyeStream>
 </FishEye>
 <Thermal>
  <!--opt, the channel supports the functions of thermal products-->
  <TemperatureMetaData>
   <!--opt, thermometry metadata, it is not returned when not support-->
   <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
  </TemperatureMetaData>
  <ThermometryDetection>
   <!--opt, thermometry detection, it is not returned when not support-->
   <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
  </ThermometryDetection>
  <ThermometryDiffDetection>
   <!--opt, temperature difference detection, it is not returned when not support-->
   <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
  </ThermometryDiffDetection>

  <FireDetection>
   <!--opt, fire detection, it is not returned when not support-->
   <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
  </FireDetection>
  <SmokeDetection>
   <!--opt,smoke detection, it is not returned when not support-->
   <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
  </SmokeDetection>
  <ShipsDetection>
   <!--opt, ship detection,it is not returned when not support-->
   <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
  </ShipsDetection>
  <IntelligentRuleDisplay>
   <!--opt, intelligent rule display parameters of thermal application, it is not returned when not support-->
   <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
  </IntelligentRuleDisplay>
  <IntelligentBehaviorRule>
   <!--opt, intelligent behavior rule configureation, it is not returned when not support-->
   <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
  </IntelligentBehaviorRule>
  <DPC>
   <!--opt, defective pixel correction, it is not returned when not support-->
   <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
  </DPC>
  <Metadata>
   <!--opt, metadata extraction,it is not returned when not support-->
   <InsertChanNo><!--opt, xs:integer, connected channel number--></InsertChanNo>
  </Metadata>
  <ThermometryShieldMask>
   <!--opt, thermometry shielded area,it is not returned when not support-->
   <InsertChanNo><!--opt,xs:integer, connected channel number--></InsertChanNo>
  </ThermometryShieldMask>
  <LensCorrection>
   <!--opt, lens correction, when this node is not returned, it indicates not support-->
   <InsertChanNo><!--opt, xs:integer, access channel number--></InsertChanNo>
  </LensCorrection>
  <BurningPrevention>
   <!--opt, burning prevention, when this node is not returned, it indicates not support-->
   <InsertChanNo><!--opt, xs:integer, access channel number--></InsertChanNo>
  </BurningPrevention>
 </Thermal>
 <isSupportChangedUpload/><!--opt, xs: boolean, whether supports uploading status changes-->
 <PanoramaCamera><!--opt, PTZ camera channel-->
  <PTZCtrl>
   <InsertChanNo><!--opt, xs:integer, access channel number--></InsertChanNo>
  </PTZCtrl>
 </PanoramaCamera>
 <GlobalCamera><!--opt, Panoramic camera channe-->
  <InsertChanNo><!--opt,xs:integer, access channel number--></InsertChanNo>
 </GlobalCamera>
</ChannelInfo>

16.2.97 XML_ChannelInfoList
ChannelInfoList message in XML format
<ChannelInfoList>version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ChannelInfo/><!--see details in the message of XML_ChannelInfo-->
</ChannelInfoList>

See Also
XML_ChannelInfo

16.2.98 XML_channelNameOverlay
channelNameOverlay message in XML format
<channelNameOverlay version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled>
  <!--req, xs:boolean, whether to enable channel name overlay-->
 </enabled>
 <name>
  <!--req, xs:string, channel name-->
 </name>
 <positionX>
  <!--req, xs:integer, X-coordinate-->
 </positionX>
 <positionY>
  <!--req, xs:integer, Y-coordinate-->
 </positionY>
</channelNameOverlay>

16.2.99 XML_CheckInfo
CheckInfo message in XML format
<CheckInfo version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <randomString><!--req, xs: string, random string--></randomString>
 <verificationCode>
  <!--opt, xs: string, verification code to be sent, which will be encrypted by sha256, and then convert the
hexadecimal code to a string, finally it will be encoded by Base64. The format is first 32-byte of randomString + actual
verification code-->
 </verificationCode>
</CheckInfo>

16.2.100 XML_CMSearchDataPackage
CMSearchDataPackage message in XML format.
<CMSearchDataPackage version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <metaId>
  <!--required, string type, metadata ID, its format is log.std-cgi.com+/major type+/minor type-->
 </metaId>
 <timeSpanList>
  <timeSpan>
   <startTime><!--required, start time with ISO8601 time format, e.g., 2017-08-02T00:00:00Z--></startTime>
   <endTime><!--required, end time with ISO8601 time format, e.g., 2017-08-02T00:00:00Z--></endTime>
  </timeSpan>
 </timeSpanList>
</CMSearchDataPackage>

16.2.101 XML_CMSearchDataPackageResult
CMSearchDataPackageResult message in XML format.
<CMSearchDataPackageResult version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <url>
  <!--required, string type, file URL, e.g., http://ip:port//ISAPI/ContentMgmt/logSearch/dataPackage/data?xx-->
 </url>
</CMSearchDataPackageResult>

16.2.102 XML_CMSearchDescription
CMSearchDescription message in XML format
<CMSearchDescription version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <searchID>
  <!--req, xs:string, search ID, e.g., {812F04E0-4089-11A3-9A0C-0305E82C2906}-->
 </searchID>
 <trackIDList>
  <trackID>
   <!--req, xs:integer, ID, XX01-search for the main stream video of channel XX, XX03-search for the pictures of
channel XX-->
  </trackID>
 </trackIDList>
 <timeSpanList>
  <timeSpan>
   <startTime><!--req, xs:time, ISO8601 time, start time of search, e.g.: 2017-08-02T00:00:00Z--></startTime>
   <endTIme><!--req, xs:time, ISO8601 time, end time of search, e.g.: 2017-08-02T23:59:59Z--></endTime>
  <timeSpan>
 </timeSpanList>
 <metaID><!--req, xs:string, metadata ID, e.g., log.std-cgi.com/Infomation/visAlarm--></metaID>
 <searchResultPostion><!--req, xs:integer, position of search result--></searchResultPostion>

 <maxResults><!--req, xs:integer, maximum number of search results--></maxResults>
 <contentTypeList>
  <contentType></contentType>
 </contentTypeList>
 <maxResults></maxResults>
 <metadataList>
  <metadataDescriptor>
   <!--searching conditions:
"evidence,illegalParking,crosslane,vehicleexist,lanechange,wrongdirection,congestion,turnround,pedestrian,constructi
on,roadBlock,abandonedObject,trafficAccident,fogDetection,dredgerDetection,safetyHelmet"-->
  </metadataDescriptor>
  <SearchProperity>
   <plateSearchMask>
    <!--opt, xs:string, ranges from 1 to 31-->
   </plateSearchMask>
   <stateOrProvince>
    <!--opt, xs:integer-->
   </stateOrProvince>
   <country>
    <!--opt, xs:string, country or region ID: 0-the algorithm library does not support the country or region ID,1-(CZ-
Czech Republic),2-(FRA-France),3-(DE-Germany),4-(E-Spain),5-(IT-Italy),6-(NL-Netherlands),7-(PL-Poland),8-(SVK-
Slovakia), 9-(BY-Belorussia), 10-(MDA-Moldova),11-(RU-Russia),12-(UA-Ukraine), 0xff-(All)-->
   </country>
  </SearchProperity>
 </metadataList>
</CMSearchDescription>

16.2.103 XML_CMSearchProfile
CMSearchProfile message in XML format
<CMSearchProfile version="1.0" xmlns="ISAPIllianxce.org:resourcedescription">
 <searchProfile><!--req, xs: string, video search conditions--></searchProfile>
 <textSearch>
  <!--req, xs: string, text type to be searched, such as recording information text and metadata text-->
 </textSearch>
 <maxSearchTimespans>
  <!--req, xs: integer, maximum time period of results returned in each search-->
 </maxSearchTimespans>
 <maxSearchTracks><!--req, xs: integer, maximum tracks can be searched--></maxSearchtracks>
 <maxSearchSources>
  <!--req, xs: integer, maximum recording channels can be searched-->
 </maxSearchSources>
 <maxSearchMetadatas>
  <!--req, xs: integer, maximum number of metadata can be searched-->
 </maxSearchMetadatas>
 <maxSearchMatchResults>
  <!--req, xs: integer, maximum search results can be returned-->
 </maxSearchMatchResults>
 <maxSearchTimeout><!--req, xs: integer, maximum search timeout--></maxSearchTimeout>
 <maxConcurrentSearches>

  <!--req, xs: integer, maximum concurrent search operations-->
 </maxConcurrentSearches>
</CMSearchProfile>

16.2.104 XML_CMSearchResult
CMSearchResult message in XML format
<CMSearchResult version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <searchID><!--req, xs:string, search ID--></searchID>
 <responseStatus><!--req, xs:string--></responseStatus>
 <responseStatusStrg><!--req, xs:string--></responseStatusStrg>
 <numOfMatches><!--opt, xs:integer--></numOfMatches>
 <matchList>
  <searchMatchItem>
    <logDescriptor>
     <metaId><!--req, xs:string--></metaId>
     <StartDateTime><!--req, xs:time, ISO8601 time--></StartDateTime>
     <paraType><!--opt, xs:string--></paraType>
     <userName><!--opt, xs:string--></userName>
     <logInfo><!--dep, log details-->
      <OpenDoorRecord>
        <type><!—req, xs: string, unlocking type: password, hijack (unlock under duress), card, resident, center--></
type>
      </OpenDoorRecord>
      <VisAlarmRecord>
        <type>
         <!—req, xs: string, alarm category: zone (zone alarm), dismantle (tampering alarm), hijack (duress alarm),
passwordErr (wrong password alarm), doorNotOpen-(door closed alarm), doorNotClose (door open alarm), SOS,
callReq (call request alarm), smartLockHijackFingerPrint (fingerprint duress alarm), smartLockHijackPassword
(password duress alarm), smartLockBreaking (forced-open door alarm), smartLockBeLocked (door locked alarm),
smartLockLowBattery (low battery alarm)-->
        </type>
      </VisAlarmRecord>
     </logInfo>
     <ipAddress><!--opt, xs:string--></ipAddress>
     <object><!--opt, xs:string, "network", "keypad", "remoteCtrl"-keyfob, "card"--></object>
     <params><!--opt, xs:string, parameters, such as zone No. and so on--></params>
     <seq><!--opt, xs:string, serial No.--></seq>
     <additionInformation><!--opt, xs:string, additional information--></additionInformation>
    </logDescriptor>
  </searchMatchItem>
  <matchElement>
    <sourceID></sourceID>
    <trackID></trackID>
    <timeSpan>
     <startTime></startTime>
     <endTime></endTime>
    </timeSpan>
    <mediaSegmentDescriptor>
     <contenType></contenType>

    <codecType></codecType>
    <rateType></rateType>
    <playbackURI></playbackURI>
   </mediaSegmentDescriptor>
   <metadataMatches>
    <metadataDescriptor><!--searching conditions:
"evidence,illegalParking,crosslane,vehicleexist,lanechange,wrongdirection,congestion,turnround,pedestrian,constructi
on,roadBlock,abandonedObject,trafficAccident,fogDetection"--></metadataDescriptor>
   </metadataMatches>
  </matchElement>
 </matchList>
</CMSearchResult>

16.2.105 XML_CMSRecordProfile
CMSRecordProfile message in XML format
<CMRecordProfile version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <trackType><!--opt, xs: string, video track type--></trackType>
</CMRecordProfile>

16.2.106 XML_Color
Color message in XML format
<Color version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <brightnessLevel><!--opt, xs:integer, brightness--></brightnessLevel>
 <contrastLevel><!--opt,xs:integer, contrast--></contrastLevel>
 <saturationLevel><!--opt,xs:integer, saturation--></saturationLevel>
 <hueLevel><!--opt, xs:integer, hue--></hueLevel>
 <grayScale>
  <grayScaleMode><!--opt,xs:string, gray scale mode: "indoor,outdoor"--></grayScaleMode>
 </grayScale>
 <nightMode>
  <!--opt, xs:boolean, enable night mode, when its value is "true", the saturation can be adjusted, otherwise, the
saturation cannot be adjusted-->
 </nightMode>
</Color>

16.2.107 XML_corridor
corridor message in XML format
<corridor version="2.0" xmlns="http://www.std-cgi.org/ver20/XMLSchema">
 <enabled><!--req, xs: boolean, whether to enable rotate mode--></enabled>
 <mirror><!--opt, xs: string, mirror mode: "on,off"--></mirror>
</corridor>

16.2.108 XML_DateTimeOverlay
DateTimeOverlay message in XML format
<DateTimeOverlay version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled>
  <!--req, xs:boolean, whether to enable date and time overlay-->
 </enabled>
 <positionX>
  <!--req, xs:integer, X-coordinate-->
 </positionX>
 <positionY>
  <!--req, xs:integer, Y-coordinate-->
 </positionY>
 <dateStyle>
  <!--opt, xs:string, date format: "YYYY-MM-DD, MM-DD-YYYY, DD-MM-YYYY, CHR-YYYY-MM-DD, CHR-MM-DD-YYYY,
CHR-DD-MM-YYYY"-->
 </dateStyle>
 <timeStyle>
  <!--opt, xs:string, "12hour, 24hour"-->
 </timeStyle>
 <displayWeek>
  <!--opt, xs:boolean, whether to display week information-->
 </displayWeek>
 <displayMilliSecond>
  <!--opt, xs:boolean, whether to display millisecond-->
 </displayMilliSecond>
</DateTimeOverlay>

16.2.109 XML_DDNS
DDNS message in XML format
<DDNS version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id>
  <!--req, xs: string-->
 </id>
 <enabled>
  <!--req, xs:boolean, "true,false"-->
 </enabled>
 <ethernetIfId>
  <!--opt, xs:string, ID. This node is used to link the DDNS to a network interface which is used by the DDNS client to
register-->
 </ethernetIfId>
 <provider>
  <!--req, xs:string, "IPServer, DynDNS, PeanutHall, NO-IP, HiDDNS..."-->
 </provider>
 <serverAddress><!--DDNS address. This node is required when <provider> is "IPServer"-->
  <addressingFormatType>

   <!--req, xs:string, method used to locate the NTP server: "ipaddress, hostname"-->
  </addressingFormatType>
  <hostname>
   <!--dep, xs:string-->
  </hostName>
  <ipAddress>
   <!--dep, xs:string-->
  </ipAddress>
  <ipv6Address>
   <!--dep, xs:string-->
  </ipv6Address>
 </serverAddress>
 <portNo>
  <!--opt, xs:integer, port No-->
 </portNo>
 <deviceDomainName>
  <!--dep, xs:string, domain name of the device-->
 </deviceDomainName>
 <username>
  <!--dep, xs:string-->
 </userName>
 <password>
  <!--wo, dep, xs:string-->
 </password>
</DDNS>

16.2.110 XML_DDNSList
DDNSList message in XML format
<DDNSList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <DDNS/><!--req, see details in the message of XML_DDNS-->
</DDNSList>

See Also
XML_DDNS

16.2.111 XML_DefaultParam
DefaultParam message in XML format
<DefaultParam version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <DialNum><!--opt, xs:string--></DialNum>
 <Username><!--opt, xs:string--></Username>
 <Password><!--opt, xs:string--></Password>
 <APNname><!--opt, xs:string--></APNname>
 <VerifyProto><!--req, xs:string, "auto, CHAP, PAP"--></VerifyProto>
</DefaultParam>

16.2.112 XML_Defog
Defog message in XML format
<Defog version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled>
  <!--req, xs:boolean-->
 </enabled>
</Defog>

16.2.113 XML_Dehaze
Dehaze message in XML format
<Dehaze version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <DehazeMode/><!--opt, xs: string, "open,close,auto"-->
 <DehazeLevel> <!--opt, xs: integer--></DehazeLevel>
</Dehaze>

16.2.114 XML_DeviceCap
DeviceCap capability message in XML format
<DeviceCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <SysCap><!--optional-->
  <isSupportDst><!--optional, xs: boolean, whether it supports daylight saving time--></isSupportDst>
  <NetworkCap/><!--optional, xs: boolean, network capability-->
  <IOCap/><!--optional, IO capability-->
  <SerialCap/><!--optional, serial port capability-->
  <VideoCap/><!--optional, video capability, see details in the message of XML_VideoCap-->
  <AudioCap/><!--optional, audio capability-->
  <isSupportHolidy><!--opt, xs:boolean--></isSupportHolidy>
  <RebootConfigurationCap>
   <Genetec><!--opt, xs:boolean--></Genetec>
   <ONVIF><!--opt, xs:boolean--></ONVIF>
   <RTSP><!--opt, xs:boolean--></RTSP>
   <HTTP><!--opt, xs:boolean--></HTTP>
   <SADP>
    <ISDiscoveryMode><!--opt, xs:boolean--></ISDiscoveryMode>
    <PcapMode><!--opt, xs:boolean--></PcapMode>
   </SADP>
   <IPCAddStatus><!--opt, xs:boolean--></IPCAddStatus>
  </RebootConfigurationCap>
  <isSupportExternalDevice><!--optional, xs:boolean--></isSupportExternalDevice>
  <isSupportChangedUpload>
   <!--opt, xs: boolean, whether it supports uploading status changes-->
  </isSupportChangedUpload>
  <isSupportGettingWorkingStatus>

    <!--opt, xs:boolean, whether it supports getting device status-->
   </isSupportGettingWorkingStatus>
   <isSupportGettingChannelInfoByCondition>
    <!--opt, xs:boolean-->
   </isSupportGettingChannelInfoByCondition>
   <isSupportDiagnosedDataParameter>
    <!--opt, xs:boolean-->
   </isSupportDiagnosedDataParameter>
   <isSupportSimpleDevStatus>
    <!--opt, xs: boolean, whether it supports getting device working status-->
   </isSupportSimpleDevStatus>
   <isSupportFlexible>
    <!--opt, xs: boolean, whether it supports getting channel status by condition-->
   </isSupportFlexible>
   <isSupportPTZChannels>
    <!--opt, xs:boolean, whether it supports returning PTZ channel (which is different from the video channel)-->
   </isSupportPTZChannels>
   <isSupportSubscribeEvent>
    <!--optional, xs:boolean, whether it supports alarm or event subscription: "true,false"-->
   </isSupportSubscribeEvent>
   <isSupportDiagnosedData>
    <!--optional, xs:boolean, "true,false", whether it supports diagnosis data-->
   </isSupportDiagnosedData>
   <isSupportTimeCap>
    <!--opt, xs:boolean, whether it supports time capability, which corresponds to URL: /ISAPI/System/time/
capabilities-->
   </isSupportTimeCap>
   <isSupportThermalStreamData>
    <!--opt, xs:boolean, whether it supports uploading thermal stream data in real-time. If it is supported, the returned
value is "true"; otherwise, this node will not be returned-->
   </isSupportThermalStreamData>
   <isSupportPostUpdateFirmware>
    <!--optional,xs:boolean,"true,false", whether it supports upgrading the firmware-->
   </isSupportPostUpdateFirmware>
   <isSupportPostConfigData>
    <!--optional, xs:boolean,"true,false", whether it supports importing or exporting the configuration file-->
   </isSupportPostConfigData>
   <isSupportUserLock>
    <!--optional, xs:boolean,"true,false", whether it supports locking user-->
   </isSupportUserLock>
   <isSupportModuleLock><!--opt, xs:boolean, whether it supports locking the module: "true,false"--></
isSupportModuleLock>
   <isSupportSoundCfg><!--optional, xs:boolean--></isSupportSoundCfg>
   <isSupportMetadata>
    <!--optional, xs:boolean, if it is supported, return "true", otherwise, this node will not be returned-->
   </isSupportMetadata>
   <isSupportShutdown><!--opt, xs:boolean, whether it supports shutdown configuration--></isSupportShutdown>
   <supportSmartOverlapChannles opt="1"/><!--opt, xs:boolean, whether it supports stream configuration of smart
events. If this function is supported, this node and the corresponding channel ID will be returned; otherwise, this node
will not be returned-->
  </SysCap>
  <voicetalkNums><!--optional, xs:integer, the number of two-way audio channels--></voicetalkNums>

<isSupportSnapshot><!--optional, xs:boolean, whether it supports capture: "true, false"--></isSupportSnapshot>
<SecurityCap/><!--optional, security capability-->
<EventCap/><!--optional, event capability-->
<ITCCap><!--opt--></ITCCap>
<ImageCap/><!--optional, image capability-->
<RacmCap/><!--optional, storage capability-->
<PTZCtrlCap>
 <isSupportPatrols><!--opt, xs:boolean--></isSupportPatrols>
</PTZCtrlCap>
<SmartCap/><!--optional, intelligent capability-->
<isSupportEhome><!--opt, xs:boolean--></isSupportEhome>
<isSupportStreamingEncrypt><!--opt, xs:boolean--></isSupportStreamingEncrypt>
<TestCap>
 <isSupportEmailTest><!--opt, xs:boolean--></isSupportEmailTest>
</TestCap>
<ThermalCap/><!--optional, thermometry capability-->
<WLAlarmCap/><!--opt, wireless alarm capability-->
<SecurityCPCapabilities/><!--opt, security control panel capability-->
<isSupportGIS>
 <!--opt, xs:boolean, whether it supports GIS capability-->
</isSupportGIS>
<isSupportCompass>
 <!--opt, xs:boolean-->
</isSupportCompass>
<isSupportRoadInfoOverlays>
 <!--opt, xs:boolean-->
</isSupportRoadInfoOverlays>
<isSupportFaceCaptureStatistics>
 <!--opt, xs:boolean-->
</isSupportFaceCaptureStatistics>
<isSupportExternalDevice>
 <!--opt, xs:boolean-->
</isSupportExternalDevice>
<isSupportElectronicsEnlarge>
 <!--opt, xs:boolean, whether it supports digital zoom-->
</isSupportElectronicsEnlarge>
<isSupportRemoveStorage>
 <!--opt, xs:boolean-->
</isSupportRemoveStorage>
<isSupportCloud>
 <!--opt, xs:boolean-->
</isSupportCloud>
<isSupportRecordHost>
 <!--opt, xs:boolean-->
</isSupportRecordHost>
<isSupportEagleEye>
 <!--opt, xs:boolean, whether it supports PanoVu series camera-->
</isSupportEagleEye>
<isSupportPanorama>
 <!--opt, xs:boolean, whether it supports panorama-->
</isSupportPanorama>
<isSupportFirmwareVersionInfo>

 <!--opt, xs:boolean, whether it supports displaying firmware version information-->
</isSupportFirmwareVersionInfo>
<isSupportExternalWirelessServer>
 <!--opt, xs: boolean-->
</isSupportExternalWirelessServer>
<isSupportSetupCalibration>
 <!--opt, xs:boolean, whether it supports setting calibration-->
</isSupportSetupCalibration>
<isSupportGetmutexFuncErrMsg>
 <!--opt, xs:boolean, whether it supports getting mutex information-->
</isSupportGetmutexFuncErrMsg>
<isSupportTokenAuthenticate><!--opt, xs:boolean--></isSupportTokenAuthenticate>
<isSupportStreamDualVCA><!--opt, xs:boolean--></isSupportStreamDualVCA>
<isSupportlaserSpotManual>
 <!--opt, boolean, whether it supports laser spot configuration-->
</isSupportlaserSpotManual>
<isSupportRTMP><!--opt, xs:boolean--></isSupportRTMP>
<isSupportTraffic><!--opt, xs:boolean--></isSupportTraffic>
<isSupportLaserSpotAdjustment>
 <!--opt, boolean, whether it supports adjusting laser spot size-->
</isSupportLaserSpotAdjustment>
<VideoIntercomCap/><!--optional, video intercom capability-->
<isSupportSafetyCabin>
 <!--opt, xs:boolean-->
</isSupportSafetyCabin>
<isSupportPEA>
 <!--opt, xs:boolean, whether it supports one-touch security control panel capability-->
</isSupportPEA>
<isSupportCurrentLock>
 <!--opt, xs:boolean, whether it supports locking current configuration-->
</isSupportCurrentLock>
<isSupportGuardAgainstTheft>
 <!--opt, xs:boolean, whether it supports device anti-theft configuration-->
</isSupportGuardAgainstTheft>
<isSupportPicInfoOverlap>
 <!--optional, xs:boolean, whether it supports picture information overlay-->
</isSupportPicInfoOverlap>
<isSupportPlay>
 <!--opt, xs: boolean, whether it supports live view: "true,false"-->
</isSupportPlay>
<isSupportPlayback>
 <!--opt, xs: boolean, whether it supports playback: "true,false"-->
</isSupportPlayback>
<UHFRFIDReader>
 <!--opt, supported capability of UHF RFID card reader-->
 <isSupportBasicInformation>
  <!--opt, xs:boolean, whether it supports basic parameters of UHF RFID card reader-->
 </isSupportBasicInformation>
 <isSupportHardDiskStorageTest>
  <!--opt, xs:boolean, whether it supports hard disk storage test of UHF RFID card reader-->
 </isSupportHardDiskStorageTest>
</UHFRFIDReader>

 <isSupportIntelligentStructureAnalysis>
  <!--opt, xs:boolean, whether it supports structured VCA-->
 </isSupportIntelligentStructureAnalysis>
 <isSupportIntelligentAnalysisEngines>
  <!--opt, xs:boolean, whether it supports VCA engine configuration-->
 </isSupportIntelligentAnalysisEngines>
 <PreviewDisplayNum>
  <!--opt, xs:integer, the number of live view windows, which is the number of simultaneous live view windows
controlled by the device. Limited by the performance of DeepinMind series network video recorder, currently only live
view of a network camera is supported, and playback is not supported-->
 </PreviewDisplayNum>
 <isSupportBoard opt="true,false">
  <!--opt, xs:boolean, whether it supports protocol related to sub-board-->
 </isSupportBoard>
 <ResourceSwitch>
  <workMode opt="4KPreview,educationRecord">
   <!--req, xs:string, device working mode："4KPreview"-4K live view mode, "educationRecord"-education recording
mode-->
  </workMode>
 </ResourceSwitch>
 <isSupportCustomStream><!--opt, xs:boolean--></isSupportCustomStream>
 <isSupportTriggerCapCheck>
  <!--opt, xs:boolean, whether it supports verifying capability of alarm linkage actions-->
 </isSupportTriggerCapCheck>
 <isSupportActiveMulticast>
  <!--opt, xs: boolean, whether it supports active multicast-->
 </isSupportActiveMulticast>
 <isSupportChannelEventCap>
  <!--opt, xs:boolean, whether it supports getting event capability by channel-->
 </isSupportChannelEventCap>
 <isSupportSensorCalibrating>
  <!--opt, xs:boolean, whether it supports double sensor calibration-->
 </isSupportSensorCalibrating>
 <isSupportChannelEventListCap>
  <!--opt, xs:boolean, whether it supports getting event capability of all channels-->
 </isSupportChannelEventListCap>
 <VCAResourceChannelsCap>
  <!--opt, whether it supports independently switching to another VCA resource by channel-->
  <ChannelsList>
   <channelsID>
     <!--req, xs:integer, channel No. supported by the device-->
   </channelsID>
  </ChannelsList>
 </VCAResourceChannelsCap>
 <SensorCap/><!--optional, intelligent cabinet capability-->
 <isSupportSecurityCP/>
  <!--optional, xs:boolean, whether it supports the applications of security control panel: "true, false"-->
 </isSupportSecurityCP>
 <isSupportClientProxyWEB>
  <!--optional, xs:boolean, whether it supports the function that the client proxy passes through the remote web
configuration: "true"-->
 </isSupportClientProxyWEB>

 <WEBLocation>
   <!--opt, string type, web page location: "local"-local device, "remote"-remote location. If this node is not returned,
the web page will be in the local device by default-->
 </WEBLocation>
 <isSupportTime/>
   <!--optional, xs:boolean, "true, false", whether it supports time configuration-->
 </isSupportTime>
 <isSupportTimeZone/>
   <!--optional, xs:boolean, "true, false", whether it supports daylight saving time (DST) configuration-->
 </isSupportTimeZone>
 <isSupportMixedTargetDetection>
   <!--opt, xs:boolean, "true, false", whether it supports multi-target-type detection-->
 </isSupportMixedTargetDetection>
 <isSupportFaceContrastMode>
   <!--opt, xs:boolean, whether it supports face picture comparison mode-->
 </isSupportFaceContrastMode>
 <isSupportPictureCaptureComparision>
   <!--opt, xs:boolean, whether it supports face picture N:1 comparison between face pictures captured by the camera
and imported face pictures-->
 </isSupportPictureCaptureComparision>
 <isSupportChannelFullEventListCap>
   <!--opt, xs:boolean, whether it supports getting event list capability of all channels-->
 </isSupportChannelFullEventListCap>
 <isSupportAUXInfoCap>
   <!--opt, xs:boolean, whether it supports getting property capability of all channels-->
 </isSupportAUXInfoCap>
 <isSupportCalibrationFile>
   <!--opt, xs:boolean, whether it supports importing calibration file-->
 </isSupportCalibrationFile>
 <isSupportDisplayTrajectory>
   <!--opt, xs:boolean, whether it supports displaying trajectory-->
 </isSupportDisplayTrajectory>
 <maximumSuperPositionTime opt="5,10,20,30">
   <!--dep,xs:integer, the maximum time of trajectory displaying，unit: second, it is valid only when displaying
trajectory is supported-->
 </maximumSuperPositionTime>
 <isSupportUnitConfig>
   <!--opt, xs:boolean, whether it supports unit configuration-->
 </isSupportUnitConfig>
 <isSupportAutoMaintenance>
   <!--opt, xs:boolean, whether it supports automatic maintenance. When this node exists and values "true", it
indicates support-->
 </isSupportAutoMaintenance>
 <isSupportGetLinkSocketIP>
   <!--opt, xs: boolean, "true,false", whether it supports getting the SoketIP of current connection-->
 </isSupportGetLinkSocketIP>
 <isSupportIntelligentSearch>
   <!--opt, xs:boolean, whether it supports intelligent search-->
 </isSupportIntelligentSearch>
 <IOTCap><!--opt, xs:boolean, IoT device access capability-->
   <supportChannelNum>
    <!--req, xs:integer, number of supported channels of IoT device-->

  </supportChannelNum>
  <startChannelNo>
    <!--opt, xs:integer, initial channel ID, if this node is not inputted, it indicates that the initial channel ID is 1-->
  </startChannelNo>
  <isSupportlinkageChannelsSearch>
    <!--opt, boolean, returns "true" if support, returns "false" if not support. Corresponds to URL (POST /ISAPI/
System/IOT/linkageChannels?format=json)-->
  </isSupportlinkageChannelsSearch>
 </IOTCap>
 <isSupportEncryption>
  <!--opt, xs: boolean, stream encryption capability-->
 </isSupportEncryption>
 <AIDEventSupport opt="abandonedObject,
pedestrian,congestion,roadBlock,construction,trafficAccident,fogDetection">
  <!--opt, xs:string, supported traffic incident type-->
 </AIDEventSupport>
 <TFSEventSupport opt="illegalParking ,wrongDirection,crossLane,laneChange,vehicleExist,turnRound,
parallelParking">
  <!--opt, xs:string, supported enforcement event type-->
 </TFSEventSupport>
 <isVehicleStatisticsSupport>
  <!--opt, xs: boolean, whether it supports setting parameters for traffic data collection-->
 </isVehicleStatisticsSupport>
 <isSupportIntersectionAnalysis>
  <!--opt, xs: boolean, whether it supports intersection analysis-->
 </isSupportIntersectionAnalysis>
 <isSptDiagnosis>
  <!--opt, xs:boolean, whether it supports device diagnosis: "true", "false"-->
 </isSptDiagnosis>
 <isSptSerialLogCfg>
  <!--opt, xs:boolean, whether it supports configuring serial port log redirection: "true", "false"-->
 </isSptSerialLogCfg>
 <isSptFileExport>
  <!--opt, xs:boolean, whether it supports exporting files from the device: "true", "false"-->
 </isSptFileExport>
 <isSptCertificationStandard>
  <!--opt, xs:boolean, whether it supports configuring authentication standard for security control panel: "true",
"false"-->
 </isSptCertificationStandard>
 <isSptKeypadLock>
  <!--opt, xs:boolean, whether it supports locking keypad: "true", "false"-->
 </isSptKeypadLock>
 <isSupportDiscoveryMode><!--opt, xs:boolean--></isSupportDiscoveryMode>
 <streamEncryptionType>
  <!--dep, xs:string, stream encryption type: "RTP/TLS", "SRTP/UDP", "SRTP/MULTICAST". This node is valid when
<isSupportEncryption> is "true", and the device can support one or more stream encryption types-->
 </streamEncryptionType>
 <isSupportLms><!--opt, xs:boolean, whether it supports laser--></isSupportLms>
 <isSupportLCDScreen><!--opt, xs:boolean, whether it supports LCD screen--></isSupportLCDScreen>
 <isSupportBluetooth><!--opt, xs:boolean, whether it supports bluetooth--></isSupportBluetooth>
 <isSupportAcsUpdate>
  <!--opt, whether it supports upgrading slave access control devices or peripheral modules: "true"-yes, this node is

not returned-no-->
  </isSupportAcsUpdate>
  <isSupportAccessControlCap>
   <!--opt, whether it supports access control capability: "true"-yes, this node is not returned-no-->
  </isSupportAccessControlCap>
  <isSupportIDCardInfoEvent><!--opt, whether it supports ID card swiping event: "true"-yes. This node will not be
returned if this function is not supported--></isSupportIDCardInfoEvent>
  <OpenPlatformCap><!--opt, embedded open platform capability, refer to the message XML_OpenPlatformCap for
details-->
  <isSupportInstallationAngleCalibration>
   <!--opt, xs:boolean, whether it supports installation angle calibration-->
  </isSupportInstallationAngleCalibration>
  <isSupportZeroBiasCalibration>
   <!--opt, xs:boolean, whether it supports zero bias calibration-->
  </isSupportZeroBiasCalibration>
  <isSupportDevStatus><!--opt, xs:boolean, whether device supports getting device status, corresponding URL: /ISAPI/
System/status--></isSupportDevStatus>
  <isSupportRadar><!--opt, xs:boolean, whether it supports security radar--></isSupportRadar>
  <SHMCap><!--opt-->
   <isSupportHighHDTemperature><!--opt, xs:boolean, whether it supports HDD high temperature detection--></
isSupportHighHDTemperature>
   <isSupportLowHDTemperature><!--opt, xs:boolean, whether it supports HDD low temperature detection--></
isSupportLowHDTemperature>
   <isSupportHDImpact><!--opt, xs:boolean, whether it supports HDD impact detection--></isSupportHDImpact>
   <isSupportHDBadBlock><!--opt, xs:boolean, whether it supports HDD bad sector detection--></
isSupportHDBadBlock>
   <isSupportSevereHDFailure><!--opt, xs:boolean, whether it supports HDD severe fault detection--></
isSupportSevereHDFailure>
  </SHMCap>
  <isSupportBVCorrect><!--opt, xs:boolean, whether it supports configuring camera correction parameters--></
isSupportBVCorrect>
  <guideEventSupport opt="linkageCapture">
   <!--opt,xs:string, events which support quick setup by instruction, "linkageCapture"-capture by linkage-->
  </guideEventSupport>
</DeviceCap>

16.2.115 XML_DeviceInfo
DeviceInfo message in XML format
<DeviceInfo version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <deviceName><!--req, xs:string--></deviceName>
 <deviceID><!--ro, req, xs:string, uuid--></deviceID>
 <deviceDescription>
  <!--opt, xs:string, description about the device defined in RFC1213. For network camera, this node is set to
"IPCamera"; for network speed dome, this node is set to "IPDome"; for DVR or DVS, this node is set to "DVR" or
"DVS"-->
 </deviceDescription>
 <deviceLocation><!--opt, xs:string, actual location of the device--></deviceLocation>
 <deviceStatus><!--ro, opt, xs:string, device status: "normal", "abnormal"-->
 <DetailAbnormalStatus>

  <!--dep, error status details, it is valid only when deviceStatus is "abnormal"-->
  <hardDiskFull>
    <!--ro, opt, xs: boolean, whether the error of "HDD full" occurred: "true"-yes,"false"-no-->
  </hardDiskFull>
  <hardDiskError>
    <!--ro, opt, xs:boolean, whether the error of "HDD error" occurred: "true"-yes,"false"-no-->
  </hardDiskError>
  <ethernetBroken>
    <!--ro, opt, xs: boolean, whether the error of "network disconnected" occurred: "true"-yes,"false"-no-->
  </ethernetBroken>
  <ipaddrConflict>
    <!--ro, opt, xs: boolean, whether the error of "IP address conflicted" occurred: "true"-yes,"false"-no-->
  </ipaddrConflict>
  <illegalAccess>
    <!--ro, opt, xs: boolean, whether the error of "illegal login" occurred: "true"-yes,"false"-no-->
  </illegalAccess>
  <recordError>
    <!--ro, opt, xs: boolean, whether the error of "recording exception" occurred: "true"-yes,"false"-no-->
  </recordError>
  <raidLogicDiskError>
    <!--ro, opt, xs: boolean, whether the error of "RAID exception" occurred: "true"-yes,"false"-no-->
  </raidLogicDiskError>
  <spareWorkDeviceError>
    <!--ro, opt, xs: boolean, whether the error of "working device exception" occurred: "true"-yes,"false"-no-->
  </spareWorkDeviceError>
 </DetailAbnormalStatus>
 <systemContact><!--opt, req, xs:string, contact information of the device--></systemContact>
 <model><!--ro, req, xs:string--></model>
 <serialNumber><!--ro, req, xs:string--></serialNumber>
 <macAddress><!--ro, req, xs:string--></macAddress>
 <firmwareVersion><!--ro, req, xs:string--></firmwareVersion>
 <firmwareReleasedDate><!--ro, opt, xs:string--></firmwareReleasedDate>
 <bootVersion><!--ro, opt, xs:string--></bootVersion>
 <bootReleasedDate><!--ro, opt, xs:string--></bootReleasedDate>
 <hardwareVersion><!--ro, opt, xs:string--></hardwareVersion>
 <encoderVersion><!--ro, opt, xs:string--></encoderVersion>
 <encoderReleasedDate><!--ro, opt, xs:stirng--></encoderReleasedDate>
 <decoderVersion><!--ro, opt, xs:string--></decoderVersion>
 <decoderReleasedDate><!--ro, opt, xs:stirng--></decoderReleasedDate>
 <softwareVersion><!--ro, opt, xs:string, software version--></softwareVersion>
 <capacity><!--ro, opt, xs:integer, unit: MB, device capacity--></capacity>
 <usedCapacity><!--ro, opt, xs:integer, unit: MB, capacity usage--></usedCapacity>
 <deviceType>
  <!--ro, req, xs:string,device type: "IPCamera", "IPDome", "DVR", "HybirdNVR", "NVR", "DVS", "IPZoom", "CVR",
"Radar", "PerimeterRadar"-perimeter radar, "ACS", "PHA"-Axiom hybrid security control panel-->
 <deviceType>
 <telecontrolID><!--opt, xs:integer, keyfob control ID, the value is between 1 and 255--></telecontrolID>
 <supportBeep><!--opt, xs:boolean--></supportBeep>
 <firmwareVersionInfo><!--ro, opt, xs:string, firmware version information--></firmwareVersionInfo>
 <actualFloorNum>
  <!--req, xs: integer, actual number of floors, which is between 1 and 128-->
 </actualFloorNum>

 <subChannelEnabled><!--opt, xs:boolean, whether to support sub-stream live view: "true"-yes, "false"-no--></
subChannelEnabled>
 <thrChannelEnabled><!--opt, xs:boolean, whether to support third stream live view: "true"-yes, "false"-no--></
thrChannelEnabled>
 <radarVersion><!--opt, xs:string, radar version--></radarVersion>
 <localZoneNum><!--opt, xs:integer, number of local zones--></localZoneNum>
 <alarmOutNum><!--opt, xs:integer, number of alarm outputs--></alarmOutNum>
 <distanceResolution><!--opt, xs:float, resolution of distance, unit: meter--></distanceResolution>
 <angleResolution><!--opt, xs:float, resolution of angle, unit: degree--></angleResolution>
 <speedResolution><!--opt, xs:float, resolution of speed, unit: m/s--></speedResolution>
 <detectDistance><!--opt, xs:float, detection distance, unit: meter--></detectDistance>
 <languageType opt="chinese,english,spanish,portuguese,italian,french,russian,german,polish"><!--opt, xs:string--></
languageType>
 <relayNum><!--opt, xs:integer, number of local relays--></relayNum>
 <electroLockNum><!--opt, xs:integer, number of local electronic locks--></electroLockNum>
 <RS485Num><!--opt, xs:integer, number of local RS-485--></RS485Num>
 <powerOnMode><!--optional, xs:string, device startup mode: "button"-press button to power on (default), "adapter"-
connect adapter to power on--></powerOnMode>
</DeviceInfo>

16.2.116 XML_DeviceStatus
DeviceStatus message in XML format
<DeviceStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <currentDeviceTime><!--opt, xs: datetime--></currentDeviceTime>
 <deviceUpTime><!--opt, xs: integer, seconds--></deviceUpTime>
 <TemperatureList><!--opt-->
  <Temperature>
   <tempSensorDescription><!--req, xs: string--></tempSensorDescription>
   <temperature><!--req, xs: float--></temperature>
  </Temperature>
 </TemperatureList>
 <FanList><!--opt-->
  <Fan>
   <fanDescription><!--req, xs: string--></fanDescription>
   <speed><!--req, xs: integer--></speed>
  </Fan>
 </FanList>
 <PressureList><!--opt-->
  <Pressure>
   <pressureSensorDescription><!--req, xs: string--></pressureSensorDescription>
   <pressure><!--req, xs: integer--></pressure>
  </Pressure>
 </PressureList>
 <TamperList><!--opt-->
  <Tamper><tamperSensorDescription><!--req, xs: string--></tamperSensorDescription>
   <tamper><!--req, xs: boolean--> </tamper>
  </Tamper>
 </TamperList>
 <CPUList><!--opt-->

 <CPU>
  <cpuDescription><!--req, xs: string--></cpuDescription>
  <cpuUtilization><!--req, xs: integer, percentage, which is between 0 and 100--></cpuUtilization>
 </CPU>
</CPUList>
<MemoryList><!--opt-->
 <Memory>
  <memoryDescription><!--req, xs: string--></memoryDescription>
  <memoryUsage><!--req, xs: float, unit: MB--></memoryUsage>
  <memoryAvailable><!--req, xs: float, unit: MB--></memoryAvailable>
 </Memory>
</MemoryList>
<openFileHandles><!--opt, xs: integer--></openFileHandles>
<CameraList><!--opt-->
 <Camera>
  <zoomReverseTimes><!--req, xs: integer--></zoomReverseTimes>
  <zoomTotalSteps><!--req, xs: integer--></zoomTotalSteps>
  <focusReverseTimes><!--req, xs: integer--></focusReverseTimes>
  <focusTotalSteps><!--req, xs: integer--></focusTotalSteps>
  <irisShiftTimes><!--req, xs: integer--></irisShiftTimes>
  <irisTotalSteps><!--req, xs: integer--></irisTotalSteps>
  <icrShiftTimes><!--req, xs: integer--></icrShiftTimes>
  <icrTotalSteps><!--req, xs: integer--></icrTotalSteps>
  <lensIntirTimes><!--req, xs: integer--></lensIntirTimes>
  <cameraRunTotalTime><!--req, xs: integer--></cameraRunTotalTime>
 </Camera>
</CameraList>
<DomeInfoList><!--opt-->
 <DomeInfo>
  <domeRunTotalTime><!--opt, xs: integer--></domeRunTotalTime >
  <runTimeUnderNegativetwenty><!--opt, xs: integer--></runTimeUnderNegativetwenty>
  <runTimeBetweenNtwentyPforty><!--opt, xs: integer--></runTimeBetweenNtwentyPforty>
  <runtimeOverPositiveforty><!--opt, xs: integer--></runtimeOverPositiveforty>
  <panTotalRounds><!--opt, xs: integer--></panTotalRounds>
  <tiltTotalRounds><!--opt, xs: integer--></tiltTotalRounds>
  <heatState><!--opt, xs: integer--></heatState>
  <fanState><!--opt, xs: integer--></fanState>
 </DomeInfo>
</DomeInfoList>
<deviceStatus><!--req, xs: string, device working status: "normal, abnormal 设"--></deviceStatus>
<dialSignalStrength>
 <!--optional, xs:integer, 4G signal strength, it is between 1 and 3-->
</dialSignalStrength>
<USBStatusList>
 <USBStatus>
  <!--list-->
  <id>
   <!--required, xs:integer-->
  </id>
  <state>
   <!--optional, xs:string, USB status: "connected", "fullCapacity", "deviceException", "disconnected"-->
  </state>

   </USBStatus>
  </USBStatusList>
  <WifiStatusList>
   <WifiStatus>
    <!--list-->
    <id>
      <!--required, xs:integer-->
    </id>
    <state>
      <!--optional, xs:string, Wi-Fi status: "disabled"-Wi-Fi is disabled, "enable"-Wi-Fi is enabled, "disconnected"-Wi-Fi
is disconnected, "enableHotspot"-Wi-Fi hot spot is enabled-->
    </state>
   </WifiStatus>
  </WifiStatusList>
  <AlertStreamServerList><!--opt, user of arming device-->
   <AlertStreamServer><!--list-->
    <id><!--opt, xs:integer--></id>
    <protocolType><!--opt, xs:string, "SDK,ISAPI", arming protocol type--></protocolType>
    <ipAddress><!--dep, xs:string, IP address of platform, server, NVR/CVR, and so on--></ipAddress>
   </AlertStreamServer>
  </AlertStreamServerList>
</DeviceStatus>

16.2.117 XML_Dial
Dial message in XML format
<Dial version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs:boolean--></enabled>
 <DialMethod><!--req, xs:string, "auto, manual"--></DialMethod>
 <SwitchMethod>
  <!--req, xs:string, "auto,4GFirst,3GFirst, manualto2G, manualto3G, manualto4G"-->
 </SwitchMethod>
 <OfflineTime><!--opt, xs:integer--></OfflineTime>
 <UIMCardNum><!--opt, xs:string--></UIMCardNum>
 <DialNum><!--opt, xs:string--></DialNum>
 <Username><!--opt, xs:string--></Username>
 <Password><!--opt, xs:string--></Password>
 <APNname><!--opt, xs:string--></APNname>
 <SIMNum><!--opt, xs:string, SIM card No. (mobile phone number)--></SIMNum>
 <MTU><!--opt, xs: integer--></MTU>
 <VerifyProto><!--req, xs:string, "auto, CHAP, PAP"--></VerifyProto>
 <DefaultParam/><!--opt, default parameters, see details in the message of XML_DefaultParam-->
 <netAPN><!--opt, xs:string, APN configuration of the private network--></netAPN>
 <Flow><!--opt, network traffic flow configuration-->
  <limitEnabled><!--opt, xs:boolean, whether to enable traffic flow limitation--></limitEnabled>
  <consumeFlow><!--opt, xs:float, unit: MB--></consumeFlow>
  <threshold><!--opt, xs:integer, unit: MB--></threshold>
 </Flow>

 <pinCode><!--opt, wo, xs:string--></pinCode>
</Dial>

See Also
XML_DefaultParam

16.2.118 XML_Dialstatus
Dialstatus message in XML format
<Dialstatus version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <RealtimeMode>
  <!--ro, xs:string, "CDMA 1x,EVDO,HYBRID,GSM,GPRS,EDGE,WCDMA,HSDPA,HSUPA,HSPA,TDSCDMA,TD-LTE,FDD-
LTE,LTE,UNKNOWN"-->
 </RealtimeMode>
 <UIMInfo>
  <!--ro, xs:string, "UNKNOWN,VALID,NOVALID,ROAM,NOEXIST"-->
 </UIMInfo>
 <SignalStrength>
  <!--ro, xs:integer-->
 </SignalStrength>
 <Dialstat>
  <!--ro, xs:string-->
 </Dialstat>
 <IpAddress>
  <!--req-->
  <ipAddress>
   <!--dep, xs:string-->
  </ipAddress>
  <ipv6Address>
   <!--dep, xs:string-->
  </ipv6Address>
 </IpAddress>
 <SubnetMask>
  <!--req-->
  <ipAddress>
   <!--dep, xs:string-->
  </ipAddress>
  <ipv6Address>
   <!--dep, xs:string-->
  </ipv6Address>
 </SubnetMask>
 <Gateway>
  <!--req-->
  <ipAddress>
   <!--dep, xs:string-->
  </ipAddress>
  <ipv6Address>
   <!--dep, xs:string-->
  </ipv6Address>

 </Gateway>
 <DNSAddress>
  <!--req-->
  <ipAddress>
   <!--dep, xs:string-->
  </ipAddress>
  <ipv6Address>
   <!--dep, xs:string-->
  </ipv6Address>
 </DNSAddress>
</Dialstatus>

16.2.119 XML_Discovery
Discovery message in XML format
<Discovery version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <UPnP><!--req-->
  <enabled><!--req, xs:boolean, "true, false"--></enalbed>
 </UPnP>
 <ZeroConf><!--opt, channel-zero configuration-->
  <enabled><!--req, xs:boolean, "true, false"--></enabled>
 </ZeroConf>
</Discovery>

16.2.120 XML_diskQuota
diskQuota message in XML format
<diskQuota version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs: integer, channel ID--></id>
 <useVideoQuota><!--read-only, xs: integer, quota for video files, unit: MB--></useVideoQuota>
 <usePictureQuota><!--read-only, xs: integer, quota for picture files, unit: MB--></usePictureQuota>
 <totalDiskVolume><!--read-only, xs: integer, total disk capacity, unit: MB--></totalDiskVolume>
 <videoQuota><!--req, xs: integer, unit: MB--></videoQuota>
 <pictureQuota><!--opt, xs: integer, unit: MB--></pictureQuota>
 <type><!--opt, xs: string, "volume,ratio,absent-ratio,otherwise-volume"--></type>
 <videoQuotaRatio><!--dep, xs: integer, video quota ratio (%): [0,100]--></videoQuotaRatio>
 <pictureQuotaRatio><!--dep, xs: integer, picture quota ratio (%): [0,100]--></pictureQuotaRatio>
 <totalVideoVolume><!--read-only, xs: integer, unit: MB--></totalVideoVolume>
 <totalPictureVolume><!--ro, xs: integer, unit: MB--></totalPictureVolume>
 <freeVideoQuota><!--ro, xs: integer, free space for video files, unit: MB--></freeVideoQuota>
 <freePictureQuota><!--ro, xs: integer, free space for picture files, unit: MB--></freePictureQuota>
</diskQuota>

16.2.121 XML_DoubleLensParkingCap
DoubleLensParkingCap capability message in XML format
<DoubleLensParkingCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <cameraType opt = "masterCamera, slaveCamera">
  <!--req, xs:string, dual-lens camera type: "masterCamera"-fixed dual-lens camera, "slaveCamera"-PTZ dual-lens
camera-->
 </cameraType>
</DoubleLensParkingCap>

16.2.122 XML_DownloadAbility
DownloadAbility message in XML format
<DownloadAbility version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <isSupportDownloadbyTime>
  <!--opt, xs:boolean, whether it supports download by time-->
 </isSupportDownloadbyTime>
 <isSupportDownloadbyFileName>
  <!--opt, xs:boolean, whether it supports download by file name -->
 </isSupportDownloadbyFileName>
 <isSupportDownloadToUSB>
  <!--opt, xs:boolean, whether it supports exporting files to devices via USB-->
 </isSupportDownloadToUSB>
</DownloadAbility>

16.2.123 XML_downloadRequest
downloadRequest message in XML format
<downloadRequest version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <playbackURI>
  <!--req, xs:string, playback URL, returned by the search service. It contains the information of file name and size,
e.g., <playbackURI>rtsp://IpAddress/Streaming/tracks/101?starttime=2016-07-18 00:00:00&endtime=2016-07-18
00:25:04Z&name=00000000721000000&size=1065437356</playbackURI>-->
 </playbackURI>
 <userName><!--opt, xs:string，double verification user name--></userName>
 <password><!--opt, xs:string，double verification password--></password>
</downloadRequest>

Remarks
When download file by name, the playbackURI inputs the file start time, end time, file name, and
size; when download file by time, the playbackURI inputs the start time and end time.

16.2.124 XML_DynamicCap
DynamicCap capability message in XML format.
<DynamicCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ResolutionAvailableDscriptorList><!--req-->
  <ResolutionAvailableDscriptor><!--req-->
   <videoResolutionWidth>
     <!--req, xs:integer-->
   </videoResolutionWidth>
   <videoResolutionHeight>
     <!--req, xs:integer-->
   </videoResolutionHeight>
   <supportedFrameRate>
     <!--req, xs:string, frame rate supported by this resolution, and its value is multiplied by 100 to be returned, e.g., if
the returned values are "2000, 2200, 2500", the actual frame rates are "20, 22, 25"-->
   </supportedFrameRate>
   <supportedBitRate min="" max=""/>
   <!--opt, xs:integer,in kbps-->
  </ResolutionAvailableDscriptor>
 </ResolutionAvailableDscriptorList>
 <CodecParamDscriptorList>
  <CodecParamDscriptor>
   <videoCodecType><!-- req, xs: string, "MPEG4,MJPEG,3GP,H.264,HK.264"--></videoCodecType>
   <isSupportProfile><!--dep, xs: boolean--></isSupportProfile>
   <CBRCap><!--constant bit rate-->
     <isSupportSmooth><!--dep, xs: boolean--></isSupportSmooth>
   </CBRCap>
   <VBRCap><!--variable bit rate-->
     <isSupportSmooth><!--dep, xs: boolean--></isSupportSmooth>
   </VBRCap>
   <isSupportSVC><!--opt, xs: boolean--></isSupportSVC>
   <isSupportCABAC><!--opt, xs: boolean--></isSupportCABAC>
   <SmartCodecCap><--opt-->
     <readOnlyParams opt="keyFrameInterval,Profile,SVC,fixedQuality">
      <!--opt, ro, xs: string, read-only options: I frame interval, encoding complexity, SVC, picture quality-->
     </readOnlyParams>
  <BitrateType>
      <Constant><!--opt, constant bit rate-->
     <support opt="videoBitrate">
         <!--opt, xs: string, "averageVideoBitrate"-average bit rate, "videoBitrate"-upper-limit of bit rate-->
       </support>
     <hiddenAbility opt="averageVideoBitrate">
         <!--opt, xs:string, "averageVideoBitrate"-average bit rate, "videoBitrate"-upper-limit of bit rate-->
       </hiddenAbility>
      </Constant>
   <Variable><!--opt, variable bit rate-->
     <support opt="averageVideoBitrate">
         <!--opt, xs: string, "averageVideoBitrate"-average bit rate, "videoBitrate"-upper-limit of bit rate-->
       </support>
     <readOnlyAbility opt="videoBitrate">

        <!--opt, xs: string, "averageVideoBitrate"-average bit rate, "videoBitrate"-upper-limit of bit rate-->
      </readOnlyAbility>
   </Variable>
  </BitrateType>
    <vbrAverageDefault><!--dep, xs: integer, recommended average bit rate, unit: Kbps--></vbrAverageDefault>
    <smart264EnabledPrompt opt="prompt1,prompt2,prompt3, prompt6, prompt25">
     <!--opt, wo, xs: string, audible prompt for Smart264 enabled-->
    </smart264EnabledPrompt>
    <smart265EnabledPrompt opt="prompt1,prompt2, prompt3, prompt25">
     <!--opt, wo, xs: string, audible prompt for Smart265 enabled-->
    </smart265EnabledPrompt>
   </SmartCodecCap>
  </CodecParamDscriptor>
 </CodecParamDscriptorList>
 <AudioDscriptorList>
  <AudioDscriptor>
   <audioCompressionType>
    <!--req, xs: string, audio encoding type: "G.711alaw,G.711ulaw,G.726,G.729,G.729a,G.
729b,PCM,MP3,AC3,AAC,ADPCM,MP2L2"-->
   </audioCompressionType>
   <audioItemList>
    <audioItem>
   <audioSamplingRate default=""><!--opt,xs: string--></audioSamplingRate>
   <audioBitRate opt=""> <!--dep, xs: integer--></audioBitRate>
   <noiseReduce opt="true,false"><!--req, xs: string--></noiseReduce>
  <audioItem>
   </audioItemList>
  </AudioDscriptor>
 </AudioDscriptorList>
</DynamicCap>

16.2.125 XML_Ehome
Ehome message in XML format
<Ehome version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--opt, xs: boolean--></enabled>
 <addressingFormatType>
  <!--req, xs: string, address format type: "ipaddress"-IP address, "hostname"-host name-->
 </addressingFormatType>
 <hostName><!--dep, xs: string, host name, this node is valid only when <addressingFormatType> is "hostname"--></
hostName>
 <ipAddress><!--dep, xs: string, IP address, this node is valid only when <addressingFormatType> is "ipaddress"--></
ipAddress>
 <ipv6Address><!--dep, xs: string, IPv6 address, this node is valid only when <addressingFormatType> is "ipaddress"--
></ipv6Address>
 <portNo><!--opt, xs: integer, port No.--></portNo>
 <deviceID><!--req, xs: string, device ID--></deviceID>
 <registerStatus><!--ro, xs: boolean, registration status--></registerStatus>
 <key><!--opt, xs: string, EHome encryption key--></key>
 <version><!--ro, xs: string, version No.--></version>

 <netWork><!--opt, xs:integer, 0-make no sense, 1-automatic, 2-wired network preferred, 3-wired network, 4-3G/4G/
GPRS--></netWork>
 <voiceDeviceType opt="bluetooth,client"><!--opt, xs:string, two-way audio device type: "bluetooth", "client"--></
voiceDeviceType>
 <protocolVersion><!--opt, xs:string, protocol type: "v2.0,v2.6,v4.0,v5.0". If this node is set to "v2.0", the device can
only use protocol v2.0 to register; if this node is set to "v2.6", "v4.0" or "v5.0", the device will firstly use this protocol
to register. If this node is not returned, the protocol version will be determined by <version>--></protocolVersion>
</Ehome>

16.2.126 XML_EPTZ
EPTZ message in XML format
<EPTZ version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs:string, whether to enable e-PTZ: "true"-yes, "false"-no--></enabled>
 <streamType><!--opt, xs:integer, stream type: 1-main stream, 2-sub-stream, 3-third stream, 4-fourth stream--></
streamType>
</EPTZ>

16.2.127 XML_EventCap
EventCap capability message in XML format
<EventCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  <isSupportHDFull><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportHDFull>
  <isSupportHDError><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportHDError>
  <isSupportNicBroken><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportNicBroken>
  <isSupportIpConflict><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportIpConflict>
  <isSupportIllAccess><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportIllAccess>
  <isSupportViException><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportViException>
  <isSupportViMismatch><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportViMismatch>
  <isSupportRecordException><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportRecordException>
  <isSupportTriggerFocus><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportTriggerFocus>
  <isSupportMotionDetection><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportMotionDetection>
  <isSupportVideoLoss><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportVideoLoss>
  <isSupportTamperDetection><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportTamperDetection>
  <isSupportStudentsStoodUp><!--opt, xs:boolean, "true"-support, "false"-not support--></
isSupportStudentsStoodUp>
  <isSupportFramesPeopleCounting><!--opt, xs:boolean, "true"-support, "false"-not support--></
isSupportFramesPeopleCounting>
  <isSupportRaidException><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportRaidException>
  <isSupportSpareException><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportSpareException>
  <isSupportPoePowerException><!--opt, xs:boolean, "true"-support, "false"-not support--></
isSupportPoePowerException>
  <isSupportRegionEntrance><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportRegionEntrance>
  <isSupportRegionExiting><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportRegionExiting>
  <isSupportLoitering><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportLoitering>
  <isSupportGroup><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportGroup>
  <isSupportRapidMove><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportRapidMove>

  <isSupportFireDetection><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportFireDetection>
  <isSupportillegalParking><!--opt, xs:boolean, whether it supports illegal parking detection: "true"-support, "false"-
not support--></isSupportillegalParking>
  <isSupportUnattendedBaggage><!--opt, xs:boolean --></isSupportUnattendedBaggage>
  <isSupportAttendedBaggage><!--opt, xs:boolean, "true"-support, "false"-not support--></
isSupportAttendedBaggage>
  <isSupportHumanAttribute><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportHumanAttribute>
  <isSupportFaceContrast><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportFaceContrast>
  <isSupportFaceLib><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportFaceLib>
  <isSupportWhiteListFaceContrast><!--opt, xs:boolean, "true"-support, "false"-not support--></
isSupportWhiteListFaceContrast>
  <isSupportBlackListFaceContrast><!--opt, xs:boolean, whether it supports blacklist face comparison: "true"-support,
"false"-not support--></isSupportBlackListFaceContrast>
  <isSupportHumanRecognition>><!--opt, xs:boolean, "true"-support, "false"-not support--></
isSupportHumanRecognition>
  <isSupportFaceSnap><!--opt, xs:boolean, "true"-support, "false"-not support--></isSupportFaceSnap>
  <isSupportPersonDensityDetection><!--opt, xs:boolean, "true"-support, "false"-not support--></
isSupportPersonDensityDetection>
  <isSupportMixedTargetDetection><!--opt, xs:boolean, whether it supports multi-target-type detection alarm: "true"-
support, "false"-not support--></isSupportMixedTargetDetection>
  <isSupportPedestrian><!--opt, xs:boolean, whether it supports pedestrian detection: "true"-support, "false"-not
support--></isSupportPedestrian>
  <isSupportTrafficAccident><!--opt, xs:boolean, whether it supports traffic accident detection: "true"-support, "false"-
not support--></isSupportTrafficAccident>
  <isSupportConstruction><!--opt, xs:boolean, whether it supports construction detection: "true"-support, "false"-not
support--></isSupportConstruction>
  <isSupportRoadBlock><!--opt, xs:boolean, whether it supports roadblock detection: "true"-support, "false"-not
support--></isSupportRoadBlock>
  <isSupportAbandonedObject><!--opt, xs:boolean, whether it supports thrown object detection: "true"-support,
"false"-not support--></isSupportAbandonedObject>
  <isSupportParallelParking><!--opt, xs:boolean, whether it supports parallel parking detection: "true"-support, "false"-
not support--></isSupportParallelParking>
  <isSupportParkingState><!--opt, xs:boolean, whether it supports parking space status detection: "true"-support,
"false"-not support, currently this node is not supported--></isSupportParkingState>
  <isSupportCongestion><!--opt, xs:boolean, whether it supports congestion detection: "true"-support, "false"-not
support--></isSupportCongestion>
  <isSupportVehicleStatistics><!--opt, xs:boolean, whether it supports data collection: "true"-support, "false"-not
support--></isSupportVehicleStatistics>
  <isSupportWrongDirection><!--opt, xs:boolean, whether it supports wrong-way driving detection: "true"-support,
"false"-not support--></isSupportWrongDirection>
  <isSupportTrunRound><!--opt, xs:boolean, whether it supports U-turning detection: "true"-support, "false"-not
support--></isSupportTrunRound>
  <isSupportCrossLane><!--opt, xs:boolean, whether it supports driving on the lane line detection: "true"-support,
"false"-not support--></isSupportCrossLane>
  <isSupportLaneChange><!--opt, xs:boolean, whether it supports illegal lane change detection: "true"-support, "false"-
not support--></isSupportLaneChange>
  <isSupportVehicleExist><!--opt, xs:boolean, whether it supports motor vehicle on non-motor vehicle lane detection:
"true"-support, "false"-not support--></isSupportVehicleExist>
  <isSupporFogDetection><!--opt, xs:boolean, whether it supports fog detection: "true"-support, "false"-not support--
></isSupporFogDetection>
  <isSupportIntersectionAnalysis><!--opt, xs: boolean, whether it supports configuring intersection analysis alarm:
"true"-support, "false"-not support--></isSupportIntersectionAnalysis>

  <isSupportVoltageInstable><!--opt,xs:boolean, whether it supports supply voltage exception alarm: "true"-support,
"false"-not support--></isSupportVoltageInstable>
  <isSupportSafetyHelmetDetection><!--opt, xs:boolean, whether it supports hard hat detection: "true"-support,
"false"-not support--></isSupportSafetyHelmetDetection>
  <isSupportCertificateRevocation><!--opt, xs:boolean, whether it supports certificate expiry alarm--></
isSupportCertificateRevocation>
</EventCap>

16.2.128 XML_EventNotificationAlert_AlarmEventInfo
EventNotificationAlert message with alarm/event information in XML format.
<EventNotificationAlert version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ipAddress><!--dep, xs:string, device IPv4 address--></ipAddress>
 <ipv6Address><!--dep, xs:string, device IPv6 address--></ipv6Address>
 <portNo><!--opt, xs:integer, device port number--></portNo>
 <protocol><!--opt, xs:string, protocol type for uploading alarm/event information, "HTTP,HTTPS"--></protocol>
 <macAddress><!--opt, xs:string, MAC address--></macAddress>
 <channelID><!--dep, xs:string, device channel No., starts from 1--></channelID>
 <dateTime><!--req, alarm/event triggered or occurred time, format: 2017-07-19T10:06:41+08:00--></dateTime>
 <activePostCount><!--req, xs:integer, alarm/event frequency, starts from 1--></activePostCount>
 <eventType><!--req, xs:string, alarm/event type, "peopleCounting, ANPR,..."--></eventType>
 <eventState>
  <!--req, xs:string, durative alarm/event status: "active"-valid, "inactive"-invalid, e.g., when a moving target is
detected,
   the alarm/event information will be uploaded continuously unit the status is set to "inactive"-->
 </eventState>
 <eventDescription><!--req, xs:string, alarm/event description--></eventDescription>
 <...><!--opt, for different alarm/event types, the nodes are different, see the message examples in different
applications--></...>
</EventNotificationAlert>

16.2.129 XML_EventNotificationAlert_HeartbeatInfo
EventNotificationAlert message with heartbeat information (when there is no alarm is triggered) in
XML format
<EventNotificationAlert version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ipv6Address><!--dep, xs:string, device IPv6 address--></ipv6Address>
 <portNo><!--opt, xs:integer, device port number--></portNo>
 <protocol><!--opt, xs:string, protocol type for uploading alarm/event information, "HTTP,HTTPS"--></protocol>
 <macAddress><!--opt, xs:string, MAC address--></macAddress>
 <channelID><!--dep, xs:string, device channel No., starts from 1--></channelID>
 <dateTime><!--req, heartbeat uploaded time, format: 2017-07-19T10:06:41+08:00--></dateTime>
 <activePostCount><!--req, xs:integer, heartbeat frequency, starts from 1--></activePostCount>
 <eventType><!--req, xs:string, for heartbeat, it is "videoloss"--></eventType>
 <eventState>
  <!--req, xs:string, for heartbeat, it is "inactive"-->
 </eventState>

 <eventDescription><!--req, xs: string, description--></eventDescription>
</EventNotificationAlert>

Remarks
• For network camera or network speed dome with the version 5.5.0 and lower, the heartbeat
  frequency is 300 ms per heartbeat.
• For network camera or network speed dome with the version 5.5.0 and higher, the heartbeat
  frequency is 10 s per heartbeat. If no heartbeat received for continuous 30 s, it indicates that the
  heartbeat is timed out.
Example
Message Example of Heartbeat
<EventNotificationAlert version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <ipAddress>10.17.133.46</ipAddress>
 <portNo>80</portNo>
 <protocol>HTTP</protocol>
 <macAddress>44:19:b6:6d:24:85</macAddress>
 <channelID>1</channelID>
 <dateTime>2017-05-04T11:20:02+08:00</dateTime>
 <activePostCount>0</activePostCount>
 <eventType>videoloss</eventType>
 <eventState>inactive</eventState>
 <eventDescription>videoloss alarm</eventDescription>
</EventNotificationAlert>

16.2.130 XML_EventNotificationAlert_IOSensorAlarmMsg
The I/O sensor alarms are uploaded in the XML format of EventNotificationAlert message.
<EventNotificationAlert version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ipAddress><!--dep, xs:string--></ipAddress>
 <ipv6Address><!--dep, xs:string--></ipv6Address>
 <portNo><!--opt, xs:integer--></portNo>
 <protocolType><!--opt, xs:string, "HTTP,HTTPS"--></protocolType>
 <macAddress><!--opt, xs:string, MAC address--></macAddress>
 <dynChannelID><!--opt, xs:string, digital channel No.--></dynChannelID>
 <channelID><!--dep, xs:string--></channelID>
 <dateTime><!--req, xs:datetime, ISO8601 time format, e.g., 2017-04-22T15:39:01+08:00--></dateTime>
 <activePostCount><!--req, xs:integer--></activePostCount>
 <eventType><!--req, xs:string, event type: "IO"--></eventType>
 <eventState><!--req, xs:string, "active,inactive"--></eventState>
 <eventDescription><!--req, xs:string--></eventDescription>
 <inputIOPortID><!--opt, xs:integer, local input port ID--></inputIOPortID>
 <dynInputIOPortID><!--opt, xs:integer, channel input port ID--></dynInputIOPortID>
 <channelName><!--opt, xs:string--></channelName>
 <deviceID><!--opt, xs:string, device ID--></deviceID>
 <Extensions>
  <serialNumber><!--req, xs:string--></serialNumber>

  <eventPush><!--req, xs:string--></eventPush>
 </Extensions>
</EventNotificationAlert>

16.2.131 XML_EventNotificationAlert_SubscriptionHeartbeat
Heartbeat information message returned when subscribing alarm/event, and it is in XML format.
<EventNotificationAlert version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <ipAddress>10.17.133.46</ipAddress>
 <portNo>80</portNo>
 <protocol>HTTP</protocol>
 <macAddress>44:19:b6:6d:24:85</macAddress>
 <channelID>1</channelID>
 <dateTime>2017-05-04T11:20:02+08:00</dateTime>
 <activePostCount>0</activePostCount>
 <eventType>heartBeat</eventType>
 <eventState>active</eventState>
 <eventDescription>heartBeat</eventDescription>
</EventNotificationAlert>

See Also
XML_EventNotificationAlert_AlarmEventInfo

16.2.132 XML_EventTrigger
EventTrigger message in XML format
<EventTrigger version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string, ID--></id>
 <eventType>
  <!--req, xs:string, see details in the "Remarks" below-->
 </eventType>
 <eventDescription><!--opt, xs:string--></eventDescription>
 <inputIOPortID><!--dep, xs:string, alarm input ID--></inputIOPortID>
 <dynInputIOPortID><!--dep, xs:string, dynamic alarm input ID--></dynInputPortID>
 <videoInputChannelID>
  <!--dep, xs:string, video input channel ID, it is valid when <eventType> is "VMD, videoloss, tamperdetection,
regionEntrance, regionExiting, loitering, group, rapidMove, parking, unattendedBaggage, attendedBaggage"-->
 </videoInputChannelID>
 <dynVideoInputChannelID><!--dep, xs:string, dynamic video input channel ID--></dynVideoInputChannelID>
 <intervalBetweenEvents><!--opt, xs:integer, event time interval, unit: second--></intervalBetweenEvents>
 <WLSensorID><!--dep, xs:string, ID--></WLSensorID>
 <EventTriggerNotificationList/><!--opt, alarm/event linkage actions, see details in the message of
XML_EventTriggerNotificationList-->
</EventTrigger>

Remarks
The node <eventType> can be the following values: IO, VMD, videoloss, raidfailure,
recordingfailure, badvideo, POS, analytics, fanfailure, overheat, tamperdetection, diskfull, diskerror,
nicbroken, ipconflict, illaccess, videomismatch, resolutionmismatch, radifailure, PIR, WLSensor,
spareException, poePowerException, heatmap, counting, linedetection, fielddetection,
regionEntrance, regionExiting, loitering, group,rapidMove, parking, unattendedBaggage,
attendedBaggage, HUMANATTRIBUTE, blackList, whitelist, peopleDetection, allVehicleList,
otherVehicleList, vehicledetection, storageDetection, shipsDetection, humanAttribute,
faceContrast, blackListFaceContrast, whiteListFaceContrast, faceSnap, faceLib,
personDensityDetection, personQueueDetecton, mixedTargetDetection, HVTVehicleDetection,
illegalParking, pedestrian, trafficAccident, construction, roadblock, abandonedObject,
parallelParking, parkingState, congestion, intersectionAnalysis, heatMap, thermometry,
shipsFlowDetection, dredgerDetection, reverseEntrance, luma, highHDTemperature,
lowHDTemperature, hdImpact, hdBadBlock, SevereHDFailure, safetyHelmetDetection.
See Also
XML_EventTriggerNotificationList

16.2.133 XML_EventTriggerCapType
EventTriggerCapType message in XML format
<EventTriggerCapType version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <isSupportCenter><!--opt, xs:boolean--></isSupportCenter>
 <isSupportRecord><!--opt, xs:boolean--></isSupportRecord>
 <isSupportMonitorAlarm><!--opt, xs:boolean--></isSupportMonitorAlarm>
 <isSupportBeep><!--opt, xs: boolean, whether it supports audible warning--></isSupportBeep>
 <isSupportIO><!--opt, xs:boolean--></isSupportIO>
 <isSupportFTP><!--opt, xs:boolean--></isSupportFTP>
 <isSupportEmail><!--opt, xs:boolean--></isSupEmail>
 <isSupportLightAudioAlarm><!--opt, xs:boolean--></isSupportLightAudioAlarm>
 <isSupportFocus><!--opt, xs:boolean--></isSupportFocus>
 <isSupportPTZ><!--opt, xs:boolean--></isSupportPTZ>
 <maxPresetActionNum>
  <!--dep, xs:integer, it is valid only when <isSupportPTZ> is "true"-->
 </maxPresetActionNum>
 <maxPatrolActionNum>
  <!--dep, xs:integer, it is valid only when <isSupportPTZ> is "true"-->
 </maxPatrolActionNum>
 <maxPatternActionNum>
  <!--dep, xs:integer, it is valid only when <isSupportPTZ> is "true"-->
 </maxPatternActionNum>
 <isSupportTrack><!--opt, xs:boolean, whether it supports PTZ linked tracking--></isSupportTrack>
 <isSupportWhiteLight>
  <!--opt, xs: boolean, whether it supports supplement light alarm linkage-->
 </isSupportWhiteLight>
 <isSupportCloud><!--opt, xs:boolean, whether it supports upload to the cloud--></isSupportCloud>

  <targetNotificationInterval max="1000" min="0" default="30"><!--xs:integer, range: [0, 1000], the default value is 30,
unit: seconds, this node is valid for <MotionDetectionTriggerCap> and <TamperDetectionTriggerCap> and this node is
valid when <isSupportPTZ> is "true"--></targetNotificationInterval>
  <direction opt="both,forward,reverse"><!--xs:string, triggering direction, this node is valid for the node
<BlackListTriggerCap>, <WhiteListTriggerCap>, and <VehicleDetectionTriggerCap>--></direction>
  <presetDurationTime min="" max=""><!--dep, xs:integer--></presetDurationTime>
  <isSupportSMS><!--opt, xs:boolean, whether it supports SMS (Short Message Service)--></isSupportSMS>
  <maxCellphoneNum><!--dep, xs:integer, this node is valid when <isSupportSMS> is "true"--></maxCellphoneNum>
  <isSupportOSD><!--opt, xs:boolean--></isSupportOSD>
  <isSupportAudio><!--opt, xs:boolean, whether it supports setting audio alarm independently. If this node is set to
"true", audio alarm and buzzer alarm can be linked separately, and the linage method is audio--></isSupportAudio>
  <AudioAction><!--dep, this node is valid when <isSupportBeep> is "true" or <isSupportAudio> is "true"-->
   <audioTypeList>
    <audioType><!--list-->
      <audioID><!--req, xs:integer, alarm sound type--></audioID>
      <audioDescription><!--req, xs:string, alarm sound description, it should correspond to the alarm sound type--></
audioDescription>
    </audioType>
   </audioTypeList>
   <alarmTimes opt="0,1,2,3,4,5,6,7,8,9,255"><!--req, xs:integer, alarm times, it is between 0 and 9, 255-continuous
alarm, unit: time--></alarmTimes>
  </AudioAction>
  <isNotSupportCenterModify><!--opt, xs:boolean, whether editing configuration parameters of the surveillance
center is not supported: "true"-yes (configuration parameters of the surveillance center cannot be edited), "false" or
this node is not returned-no (configuration parameters of the surveillance center can be edited)--></
isNotSupportCenterModify>
</EventTriggerCapType>

16.2.134 XML_EventTriggerNotification
EventTriggerNotification message in XML format
<EventTriggerNotification><!--opt-->
 <id><!--req, xs:string, device ID--></id>
 <notificationMethod>
   <!--req, xs:string, linkage actions, opt="email,IM,IO,syslog,HTTP,FTP,beep,ptz,record, monitorAlarm, center,
LightAudioAlarm,focus,trace,cloud,SMS,whiteLight,audio…"-->
 </notificationMethod>
 <notificationRecurrence>
   <!--opt, xs:string, "beginning,beginningandend,recurring"-->
 </notificationRecurrence>
 <notificationInterval><!--dep, xs:integer, unit: millisecond--></notificationInterval>
 <outputIOPortID><!--dep, xs:string, video output No., it is required only when notificationMethod is "IO"--></
outputIOPortID>
 <dynOutputIOPortID><!--dep, xs:string, dynamic video output No., it is required only when notificationMethod is
"IO"--></dynOutputIOPortID>
 <videoInputID><!--dep, xs:string, video input No., it is required only when notificationMethod is "record"--></
videoInputID>
 <dynVideoInputID><!--dep, xs:string, dynamic video input No., it is required only when notificationMethod is
"record"--></dynVideoInputID>
 <ptzAction><!--dep, it is required only when notificationMethod is "ptz"-->

  <ptzChannelID><!--req, xs:string, PTZ channel ID--></ptzChannelID>
  <actionName><!--req, xs:string, PTZ control type: "preset", "pattern", "patrol"--></actionName>
  <actionNum><!--dep, xs:integer></actionNum>
 </ptzAction>
</EventTriggerNotification>

16.2.135 XML_EventTriggerNotificationList
EventTriggerNotificationList message in XML format
<EventTriggerNotificationList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <EventTriggerNotification/><!--opt, see details in the message of XML_EventTriggerNotification-->
</EventTriggerNotificationList>

See Also
XML_EventTriggerNotification

16.2.136 XML_EventTriggersCap
EventTriggersCap capability message in XML format
<EventTriggersCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <DiskfullTriggerCap><!--opt, xs: EventTriggerCapType--></DiskfullTriggerCap>
 <DiskerrorTriggerCap><!--opt, xs: EventTriggerCapType--></DiskerrorTriggerCap>
 <NicbrokenTriggerCap><!--opt, xs: EventTriggerCapType--></NicbrokenTriggerCap>
 <IpconflictTriggerCap><!--opt, xs: EventTriggerCapType--></IpconflictTriggerCap>
 <IllaccesTriggerCap><!--opt, xs: EventTriggerCapType--></IllaccesTriggerCap>
 <BadvideoTriggerCap><!--opt, xs: EventTriggerCapType--></BadvideoTriggerCap>
 <VideomismatchTriggerCap><!--opt, xs: EventTriggerCapType--></VideomismatchTriggerCap>
 <IOTriggerCap><!--opt, xs: EventTriggerCapType--></IOTriggerCap>
 <LineDetectTriggerCap><!--opt, xs: EventTriggerCapType--></LineDetectTriggerCap>
 <RegionEntranceTriggerCap><!--opt, xs: EventTriggerCapType--></RegionEntranceTriggerCap>
 <RegionExitingTriggerCap><!--opt, xs: EventTriggerCapType--></RegionExitingTriggerCap>
 <LoiteringTriggerCap><!--opt, xs: EventTriggerCapType--></LoiteringTriggerCap>
 <GroupDetectionTriggerCap><!--opt, xs: EventTriggerCapType--></GroupDetectionTriggerCap>
 <RapidMoveTriggerCap><!--opt, xs: EventTriggerCapType--></RapidMoveTriggerCap>
 <ParkingTriggerCap><!--opt, xs: EventTriggerCapType--></ParkingTriggerCap>
 <UnattendedBaggageTriggerCap><!--opt, xs: EventTriggerCapType--></UnattendedBaggageTriggerCap>
 <AttendedBaggageTriggerCap><!--opt, xs: EventTriggerCapType--></AttendedBaggageTriggerCap>
 <FireDetectionTriggerCap><!--opt, xs: EventTriggerCapType--></FireDetectionTriggerCap>
 <FireDetectionCap><!--opt, xs: EventTriggerCapType--></FireDetectionCap>
 <StorageDetectionTriggerCap><!--opt, xs: EventTriggerCapType--></StorageDetectionTriggerCap>
 <ShipsDetectionTriggerCap><!--opt, xs: EventTriggerCapType--></ShipsDetectionTriggerCap>
 <ThermometryCap><!--opt, xs: EventTriggerCapType--></ThermometryCap>
 <VandalProofTriggerCap><!--opt, xs: EventTriggerCapType--></VandalProofTriggerCap>
 <BlackListTriggerCap><!--opt, xs: EventTriggerCapType, configuration capability of blacklist arming linkage--></
BlackListTriggerCap>
 <WhiteListTriggerCap><!--opt, xs: EventTriggerCapType, configuration capability of whitelist arming linkage--></
WhiteListTriggerCap>

  <AllVehicleListTriggerCap><!--opt,xs:EventTriggerCapType, configuration capability of other list arming linkage--></
AllVehicleListTriggerCap>
  <OtherVehicleListTriggerCap><!--opt,xs:EventTriggerCapType--></OtherVehicleListTriggerCap>
  <PeopleDetectionTriggerCap><!--opt,xs:EventTriggerCapType--></PeopleDetectionTriggerCap>
  <PIRAlarmCap><!--opt, xs: EventTriggerCapType--></PIRAlarmCap>
  <TamperDetectionTriggerCap><!--opt, xs: EventTriggerCapType--></TamperDetectionTriggerCap>
  <DefocusDetectionTriggerCap><!--opt, xs: EventTriggerCapType--></DefocusDetectionTriggerCap>
  <FaceDetectionTriggerCap><!--opt, xs: EventTriggerCapType--></FaceDetectionTriggerCap>
  <SceneChangeDetectionTriggerCap><!--opt, xs: EventTriggerCapType--></SceneChangeDetectionTriggerCap>
  <VandalProofAlarmCap><!--opt, xs: EventTriggerCapType--></VandalProofAlarmCap>
  <JudgmentTriggerCap><!--opt, xs: EventTriggerCapType--></JudgmentTriggerCap>
  <FightingTriggerCap><!--opt, xs: EventTriggerCapType--></FightingTriggerCap>
  <RisingTriggerCap><!--opt, xs: EventTriggerCapType--></RisingTriggerCap>
  <DozingTriggerCap><!--opt, xs: EventTriggerCapType--></DozingTriggerCap>
  <CountingTriggerCap><!--opt, xs: EventTriggerCapType--></CountingTriggerCap>
  <VideoLossTriggerCap><!--opt, xs: EventTriggerCapType--></VideoLossTriggerCap>
  <HideTriggerCap><!--opt, xs:EventTriggerCapType--></HideTriggerCap>
  <AlarmInTriggerCap><!--opt, xs: EventTriggerCapType--></AlarmInTriggerCap>
  <VehicleDetectionTriggerCap><!--opt, xs: EventTriggerCapType--></VehicleDetectionTriggerCap>
  <AudioExceptionCap><!--opt, xs: EventTriggerCapType--></AudioExceptionCap>
  <FiledDetectTriggerCap><!--opt, xs: EventTriggerCapType--></FiledDetectTriggerCap>
  <MotionDetectionTriggerCap><!--opt, xs: EventTriggerCapType--></MotionDetectionTriggerCap>
  <TemperatureCap><!--opt, xs: EventTriggerCapType--></TemperatureCap>
  <IntelligentTriggerCap><!--opt, xs: EventTriggerCapType--></IntelligentTriggerCap>
  <FaceContrastTriggerCap><!--opt, xs: EventTriggerCapType, face picture comparison alarm linkage--></
FaceContrastTriggerCap>
  <PersonDensityDetectionTriggerCap><!--opt, xs: EventTriggerCapType--></PersonDensityDetectionTriggerCap>
  <PersonQueueDetectionTriggerCap><!--opt, xs: EventTriggerCapType, queue management alarm linkage--></
PersonQueueDetectionTriggerCap>
  <WhiteListFaceContrastTriggerCap><!--opt, xs: EventTriggerCapType--></WhiteListFaceContrastTriggerCap>
  <HumanRecognitionTriggerCap><!--opt,xs: EventTriggerCapType--></HumanRecognitionTriggerCap>
  <FaceSnapTriggerCap><!--opt, xs: EventTriggerCapType--></FaceSnapTriggerCap>
  <isSupportWhiteLightAction>
   <!--dep, xs: boolean, see details in EventTriggerCapType, it is valid when isSupportWhiteLight is "true"-->
  </isSupportWhiteLightAction>
  <isSupportAudioAction>
   <!--dep, xs: boolean, see details in EventTriggerCapType, it is valid when isSupportBeep is "true"-->
  </isSupportAudioAction>
  <HFPDTriggerCap><!--opt, xs: EventTriggerCapType--></HFPDTriggerCap>
  <MixedTargetDetectionCap><!--opt, xs: EventTriggerCapType--></MixedTargetDetectionCap>
  <HVTVehicleDetectionTriggerCap><!--opt, xs: EventTriggerCapType--></HVTVehicleDetectionTriggerCap>
  <VCATriggerCap><!--opt, xs: EventTriggerCapType--></VCATriggerCap>
  <PIRCap><!--opt, xs: EventTriggerCapType--></PIRCap>
  <IllegalParkingTriggerCap><!--opt, xs: EventTriggerCapType, whether it supports illegal parking detection--></
IllegalParkingTriggerCap>
  <PedestrianTriggerCap><!--opt, xs: EventTriggerCapType, whether it supports pedestrian detection--></
PedestrianTriggerCap>
  <TrafficAccidentTriggerCap><!--opt, xs: EventTriggerCapType, whether it supports traffic accident detection--></
TrafficAccidentTriggerCap>
  <ConstructionTriggerCap><!--opt, xs: EventTriggerCapType, whether it supports construction detection--></
ConstructionTriggerCap>
  <RoadBlockTriggerCap><!--opt, xs: EventTriggerCapType, whether it supports roadblock detection--></

RoadBlockTriggerCap>
 <AbandonedObjectTriggerCap><!--opt, xs: EventTriggerCapType, whether it supports thrown object detection--></
AbandonedObjectTriggerCap>
 <ParallelParkingTriggerCap><!--opt, xs: EventTriggerCapType, whether it supports parallel parking detection--></
ParallelParkingTriggerCap>
 <ParkingStateTriggerCap><!--opt, xs: EventTriggerCapType, whether it supports parking space status detection,
currently this node is not supported--></ParkingStateTriggerCap>
 <CongestionTriggerCap><!--opt, xs: EventTriggerCapType, whether it supports congestion detection--></
CongestionTriggerCap>
 <IntersectionAnalysisCap><!--opt, xs: EventTriggerCapType, whether it supports intersection analysis--></
IntersectionAnalysisCap>
 <ShipsFlowDetectionTriggerCap><!--opt,xs:EventTriggerCapType, ship flow detection--></
ShipsFlowDetectionTriggerCap>
 <dredgerDetectionTriggerCap><!--opt,xs:EventTriggerCapType, dredger detection--></dredgerDetectionTriggerCap>
 <voltageInstableTriggerCap><!--opt,xs:EventTriggerCapType, supply voltage exception--></voltageInstableTriggerCap>
 <HighHDTemperatureTriggerCap><!--opt, xs:EventTriggerCapType, HDD high temperature detection--></
HighHDTemperatureTriggerCap>
 <LowHDTemperatureTriggerCap><!--opt, xs:EventTriggerCapType, HDD low temperature detection--></
LowHDTemperatureTriggerCap>
 <HDImpactTriggerCap><!--opt, xs:EventTriggerCapType, HDD impact detection--></HDImpactTriggerCap>
 <HDBadBlockTriggerCap><!--opt, xs:EventTriggerCapType, HDD bad sector detection--></HDBadBlockTriggerCap>
 <SevereHDFailureTriggerCap><!--opt, xs:EventTriggerCapType, HDD severe fault detection--></
SevereHDFailureTriggerCap>
 <HUMANATTRIBUTECap><!--opt, xs:EventTriggerCapType--></HUMANATTRIBUTECap>
 <HumanAttributeTriggerCap><!--opt, xs:EventTriggerCapType, human body attribute--></HumanAttributeTriggerCap>
 <BlackListFaceContrastTriggerCap><!--opt, xs:EventTriggerCapType, alarm linkage capability of blacklist face
comparison--></BlackListFaceContrastTriggerCap>
 <FaceLibTriggerCap><!--opt, xs:EventTriggerCapType--></FaceLibTriggerCap>
 <SafetyHelmetDetectionTriggerCap><!--opt, xs:EventTriggerCapType, alarm linkage capability of hard hat detection--
></SafetyHelmetDetectionTriggerCap>
</EventTriggersCap>

See Also
XML_EventTriggerCapType

16.2.137 XML_ExportStatus
ExportStatus message in XML format
<ExportStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <status><!--opt, xs:string, export status: "export"-exporting, "unexport"-not export--></status>
 <message><!--dep, xs:string, it is valid when status is "export"--></message>
</ExportStatus>

16.2.138 XML_Exposure
Exposure message in XML format

<Exposure version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ExposureType/><!--req, xs:string, "auto, IrisFirst, ShutterFirst, gainFirst, manual, pIris, T5280-PQ1, T5289-PQ1,
T1140-PQ1, T2712-PQ1, HV1250P-MPIR, pIris-General"-->
 <autoIrisLevel>
  <!--dep, xs:integer-->
 </autoIrisLevel>
 <OverexposeSuppress><!--opt-->
  <enabled>
   <!--req, xs:boolean-->
  </enabled>
  <Type>
   <!--dep, xs:string, this node depends on <enabled>, "AUTO,MANUAL"-->
  </Type>
  <DistanceLevel>
   <!--dep, xs: integer, this node depends on <Type>-->
  </DistanceLevel>
  <shortIRDistanceLevel>
   <!--dep, xs: integer, this node depends on <Type>-->
  </shortIRDistanceLevel>
  <longIRDistanceLevel>
   <!--dep, xs: integer, this node depends on <Type>-->
  </longIRDistanceLevel>
 </OverexposeSuppress>
 <pIris><!--opt-->
  <pIrisType/><!--dep, xs:string, this node depends on <ExposureType>, "AUTO,MANUAL"-->
  <IrisLevel>
   <!--dep, xs:integer, this node depends on <pIrisType>-->
  </IrisLevel>
 </pIris>
 <PIrisGeneral><!--dep, it is available when <ExposureType> is set to "pIris-General"-->
  <irisLevel>
   <!--opt, iris level of general lens, which is between 1 and 100, the default level is 50-->
  </irisLevel>
 </PIrisGeneral>
 <exposureLevel>
  <!--opt, xs:integer , this node depends on <ExposureType>-->
 </exposureLevel>
 <faceExposure><!--opt, face exposure-->
  <enabled opt="true,false">
   <!--opt, xs:boolean, whether to enable face exposure-->
  </enabled>
  <sensitivity min="0" max="100">
   <!--opt, xs:integer, sensitivity-->
  </sensitivity>
 </faceExposure>
</Exposure>

16.2.139 XML_externSecurityCap
externSecurityCap message in XML format

<externSecurityCap>
 <RestAdminPassWord>
  <isSupportWithSecurityQuestion>
   <!--opt, xs: boolean, whether supports resetting password by answering security questions, "true,false" -->
  </isSupportWithSecurityQuestion>
  <isSupportWithGUIDFileData>
   <!-- opt, xs: boolean, whether supports resetting password by importing GUID file, "true,false" -->
  </isSupportWithGUIDFileData>
  <isSupportWithSecurityEmail>
   <!-- opt, xs: boolean, whether supports resetting password by setting recovery email, "true,false" -->
  </isSupportWithSecurityEmail>
 </RestAdminPassWord>
 <SecurityLimits><!--opt-->
  <LoginPasswordLenLimit min="1" max="16">
   <!--opt, minimum and maximum lengths of login password-->
  </LoginPasswordLenLimit>
  <SecurityAnswerLenLimit min="1" max="128">
   <!--opt, minimum and maximum answer length of security questions-->
  </SecurityAnswerLenLimit>
 </SecurityLimits>
</externSecurityCap>

16.2.140 XML_ExtraInfo
ExtraInfo message in XML format
<ExtraInfo version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <diskMode><!--req, xs:string, disk mode: "singleDisk"-single disk, "RAID". The device needs to reboot after changing
the disk mode--></diskMode>
</ExtraInfo>

16.2.141 XML_EZVIZ
EZVIZ message in XML format.
<EZVIZ version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs:boolean--></enabled>
 <registerStatus><!--ro, opt, xs:boolean--></registerStatus>
 <redirect><!--opt, xs:boolean, whether to allow the device to redirect the server address--></redirect>
 <serverAddress><!--opt-->
  <addressingFormatType>
   <!--req, xs:string, "ipaddress,hostname"-->
  </addressingFormatType>
  <hostName><!--dep, xs:string--></hostName>
  <ipAddress><!--dep, xs:string--></ipAddress>
  <ipv6Address><!--dep, xs:string--></ipv6Address>
 <serverAddress>
 <verificationCode>

  <!--opt, xs:string, verification code. Only the "admin" user can edit the verification code using the control. The
verification code will be displayed for other users. If this node is returned, setting verification code is supported-->
 </verificationCode>
 <offlineStatus>
  <!--ro,dep,xs:string, it is valid when registerStatus values "false", device offline status, opt="secretKeyInvalid"-invalid
verification code-->
 </offlineStatus>
 <operateCode><!--opt, xs:string, operation code for binding device--></operateCode>
 <netWork>
  <!--opt, xs:integer，0-null；1-automatic；2-wired network priority；3-wired network(by default), 4-3G/4G/GPRS-->
 </netWork>
</EZVIZ>

16.2.142 XML_FocusConfiguration
FocusConfiguration message in XML format
<FocusConfiguration version=“2.0” xmlns=“http://www.isapi.org/ver20/XMLSchema”>
 <focusStyle/><!--req, xs:string, focus type, "AUTO, MANUAL, SEMIAUTOMATIC"-->
 <focusLimited/><!--opt, xs:integer, the minimum focus length, unit: cm-->
 <focusPosition/><!--dep, depends on "FocusStyle", xs:integer-->
 <focusSpeed><!--opt, xs:intger--></focusSpeed>
 <focusSensitivity>
  <!--opt, xs:intger, focus sensitivity, ranges from 0 to 2, it is valid when "focusStyle" is "MANUAL" or
"SEMIAUTOMATIC"-->
 </focusSensitivity>
 <temperatureChangeAdaptEnabled><!--opt, xs:boolean, "true,false"--></temperatureChangeAdaptEnabled>
 <relativeFocusPos>
  <!--opt, xs:intger, relative focus value, it is valid when "focusStyle" is "MANUAL" or "SEMIAUTOMATIC"-->
 </relativeFocusPos>
 <highTemperaturePriority><!--opt,xs:boolean, whether to enable high temperature priority mode--></
highTemperaturePriority>
</FocusConfiguration>

16.2.143 XML_FocusData
FocusData message in XML format
<FocusData version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <focus>
  <!--req, xs: integer, a vector, whose value is the percentage of maximum focus speed: negative value-focus near;
positive value-focus far-->
 </focus>
</FocusData>

16.2.144 XML_formatStatus
formatStatus message in XML format
<formatStatus version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <formating><!--ro, req, xs: boolean--></formating>
 <percent><!--ro, req, xs: integer, formatting progress percentage, which is between 0 and 100--></percent>
</formatStatus>

16.2.145 XML_FTPNotification
FTPNotification message in XML format
<FTPNotification version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id>
  <!--req, xs:string, FTP ID-->
 </id>
 <enabled>
  <!--req, xs:boolean, whether to enable the FTP server-->
 </enabled>
 <useSSL>
  <!--opt, xs:boolean-->
 </useSSL>
 <addressingFormatType opt="ipaddress,hostname">
  <!--req, xs:string, this node can only be set to "ipaddress"-->
 </addressingFormatType>
 <hostName>
  <!--dep, xs:string-->
 </hostName>
 <ipAddress>
  <!--dep, xs:string-->
 </ipAddress>
 <ipv6Address>
  <!--dep, xs:string-->
 </ipv6Address>
 <portNo>
  <!--opt, xs:integer, FTP port No.-->
 </portNo>
 <userName>
  <!--req, xs:string, user name-->
 </userName>
 <password>
  <!--wo, xs:string, password-->
 </password>
 <passiveModeEnabled>
  <!--opt, xs:boolean-->
 </passiveModeEnabled>
 <annoyftp>
  <!--opt, xs:boolean-->

  </annoyftp>
  <uploadPicture>
   <!--opt, xs:boolean-->
  </uploadPicture>
  <uploadVideoClip>
   <!--opt, xs:boolean-->
  </uploadVideoClip>
  <uploadPath>
   <!--req-->
   <pathDepth>
     <!--req, xs:integer, directory levels, up to 16 levels can be supported-->
   </pathDepth>
   <topDirNameRule>
     <!--dep, xs:string, parent directory name: "none", "devName"-device name, "devId"-device ID, "devIp"-device IP
address, "positionInfo"-camera 1, "time_month"-usage date (YYYY-MM), "time_date"-usage date (YYYY-MM-DD),
"illegalType"-violation type, "direction"-direction, "site"-place, "chanName"-channel name, "chanId"-channel No.,
"laneId"-lane No., "customize"-custom, "time", "buildUnitNo"-building No. and unit No. This node is set to NULL by
default-->
   </topDirNameRule>
   <topDirName/><!--dep, xs:string, custom string for parent directory, the maximum string length is 32 bytes. This
node is valid when <topDirNameRule> is "customize"-->
   <subDirNameRule>
     <!--dep, xs:string, child directory name: "none", "devName"-device name, "devId"-device ID, "devIp"-device IP
address, "positionInfo"-camera 1, "time_month"-usage date (YYYY-MM), "time_date"-usage date (YYYY-MM-DD),
"illegalType"-violation type, "direction"-direction, "site"-place, "chanName"-channel name, "chanId"-channel No.,
"laneId"-lane No., "customize"-custom, "time", "buildUnitNo"-building No. and unit No. This node is set to NULL by
default-->
   </subDirNameRule>
   <subDirName/><!--dep, xs:string, custom string for child directory, the maximum string length is 32 bytes. This node
is valid when <subDirNameRule> is "customize"-->
   <threeDirNameRule>
     <!--dep, xs:string, the third directory name: "none", "devName"-device name, "devId"-device ID, "devIp"-device IP
address, "positionInfo"-camera 1, "time_month"-usage date (YYYY-MM), "time_date"-usage date (YYYY-MM-DD),
"illegalType"-violation type, "direction"-direction, "site"-place, "chanName"-channel name, "chanId"-channel No.,
"laneId"-lane No., "customize"-custom, "time", "buildUnitNo"-building No. and unit No. This node is set to NULL by
default-->
   </threeDirNameRule>
   <threeDirName/><!--req, xs:string, custom string for the third directory, the maximum string length is 32 bytes. This
node is valid when <threeDirNameRule> is "customize"-->
   <fourDirNameRule>
     <!--dep, xs:string, the fourth directory name: "none", "devName"-device name, "devId"-device ID, "devIp"-device
IP address, "positionInfo"-camera 1, "time_month"-usage date (YYYY-MM), "time_date"-usage date (YYYY-MM-DD),
"illegalType"-violation type, "direction"-direction, "site"-place, "chanName"-channel name, "chanId"-channel No.,
"laneId"-lane No., "customize"-custom, "time", "buildUnitNo"-building No. and unit No. This node is set to NULL by
default-->
   </fourDirNameRule>
   <fourDirName/><!--req, xs:string, custom string for the fourth directory, the maximum string length is 32 bytes. This
node is valid when <fourDirNameRule> is "customize"-->
  </uploadPath>
  <picArchivingInterval>
   <!--opt, xs:integer, the value is between 1 and 30, 0-close-->
  </picArchivingInterval>

 <picNameRuleType>
  <!--opt, xs:string, picture name rule type: "default, prefix"-->
 </picNameRuleType>
 <picNamePrefix>
  <!--dep, xs:string, prefix length of the picture name, which is between 0 and 32-->
 </picNamePrefix>
 <ftpPicNameRuleType>
  <!--req, xs:string, type of FTP picture name rule: "videoIntercom"-rule used by video intercom products, "ITC"-rule
used by traffic cameras-->
 </ftpPicNameRuleType>
 <FTPPicNameRule>
  <!--dep, picture name rule of a specific FTP-->
  <ItemList/><!--req, see details in the message of XML_ItemList-->
  <delimiter>
    <!--req, xs:string, delimiter, which is a single character and the default value is "_"-->
  </delimiter>
  <customStr>
    <!--req, xs:string, custom string, its length is between 1 and 128-->
  </customStr>
 </FTPPicNameRule>
 <upDataType>
  <!-- opt, xs:integer, picture uploading type: 0-all, 1-checkpoint, 2-violation. When only one FTP server is enabled,
this node can only be set to 0. When two FTP servers are both enabled, you should set 1 for one FTP server and set 2
for another FTP server, which means that two FTP servers cannot be set to the same type-->
 </upDataType>
 <uploadPlateEnable>
  <!--opt, xs:boolean, whether to enable uploading license plate thumbnail-->
 </uploadPlateEnable>
 <site>
  <!--req, xs:string, place, the maximum string length is 128 bytes-->
 </site>
 <roadNum>
  <!--req, xs:string, intersection No., the maximum string length is 32 bytes-->
 </roadNum>
 <instrumentNum>
  <!--req, xs:string, device No., the maximum string length is 32 bytes-->
 </instrumentNum>
 <direction>
  <!--req, xs:string, direction No., the maximum string length is 32 bytes-->
 </direction>
 <directionDesc>
  <!--req, xs:string, direction description, the maximum string length is 32 bytes-->
 </directionDesc>
 <monitoringInfo1>
  <!--req, xs:string, camera 1 information, the maximum string length is 44 bytes-->
 </monitoringInfo1>
 <uploadAttachedInfomation>
  <!--req, xs:boolean, whether to upload additional information-->
 </uploadAttachedInfomation>
 <brokenNetHttp><!--opt, xs:boolean, whether to enable ANR (automatic network replenishment)--></
brokenNetHttp>
</FTPNotification>

See Also
XML_ItemList

16.2.146 XML_FTPNotificationList
FTPNotificationList message in XML format
<FTPNotificationList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <FTPNotification/><!--opt, see details in the message of XML_FTPNotification-->
</FTPNotificationList>

See Also
XML_FTPNotification

16.2.147 XML_FTPTestDescription
FTPTestDescription message in XML format
<FTPTestDescription version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <useSSL><!--opt, xs: boolean></useSSL>
 <addressingFormatType>
  <!--req, xs: string, "ipaddress,hostname" -->
 </addressingFormatType>
 <hostName><!--dep, xs: string--></hostName>
 <ipAddress><!--dep, xs: string--></ipAddress>
 <ipv6Address><!--dep, xs: string--></ipv6Address>
 <portNo><!--opt, xs: integer--></portNo>
 <userName><!--req, xs: string--></userName>
 <password><!--wo, xs: string--></password>
 <passiveModeEnabled><!--opt, xs: boolean--></passiveModeEnabled>
 <annoyftp><!--opt, xs: boolean--></annoyftp>
 <uploadPath><!--req-->
  <pathDepth><!--req, xs: integer, the value is from 0 to 2--></pathDepth>
  <topDirNameRule>
   <!--dep, xs: string, "devName, devId, devIp, customize"-->
  </topDirNameRule>
  <topDirName/><!--dep, xs: string-->
  <subDirNameRule>
   <!--dep, xs: string, "chanName, chanId, customize"-->
  </subDirNameRule>
  <subDirName/><!--dep, xs: string-->
 </uploadPath>
</FTPTestDescription>

16.2.148 XML_FTPTestResult
FTPTestResult message in XML format
<FTPTestResult version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <errorDescription><!--req, xs: string--></errorDescription>
</FTPTestResult>

16.2.149 XML_Gain
Gain message in XML format
<Gain version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <GainLevel/><!--dep, xs:integer, this node is valid when <ExposureType> in the message XML_Exposure is
"GainFisrt"-->
 <GainWindow><!--opt-->
  <RegionCoordinatesList><!--opt-->
   <RegionCoordinates><!--opt-->
    <positionX><!--req, xs: integer; x-coordinate--></positionX>
    <positionY><!--req, xs: integer; y-coordinate--></positionY>
   </RegionCoordinates>
  </RegionCoordinatesList>
 </GainWindow>
</Gain>

See Also
XML_Exposure

16.2.150 XML_GuardAgainstTheft
GuardAgainstTheft message in XML format
<GuardAgainstTheft version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--required, xs:boolean, whether to support enabling device anti-theft--></enabled>
 <SMSEnabled><!--required, xs:boolean, whether to support enabling SMS--></SMSEnabled>
 <phoneNum><!--dependency, xs:string, phone No.--></phoneNum>
 <longitudeLatitudeEnabled><!--dependency, xs:boolean, whether to support enabling longitude and latitude--></
longitudeLatitudeEnabled>
 <siteLocationEnabled><!--optional, xs:boolean, whether to support enabling site location--></siteLocationEnabled>
 <siteLocationInfo><!--dependency, xs:string, site location information--></siteLocationInfo>
 <timeEnabled><!--optional, xs:boolean, whether to support enabling time--></timeEnabled>
 <customInfo><!--optional, xs:string, custom information--></customInfo>
</GuardAgainstTheft>

16.2.151 XML_HardwareService
HardwareService message in XML format
<HardwareService version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IrLightSwitch><!--opt-->
  <mode><!--req, xs:string, "open,close"--></mode>
 </IrLightSwitch>
 <ABF><!--opt-->
  <enabled><!--req, xs:boolean--></enabled>
 </ABF>
 <LED><!--opt-->
  <enabled><!--req, xs:boolean--></enabled>
 </LED>
 <Defog>
  <!--opt -->
  <enabled>
   <!--req, xs:boolean-->
  </enabled>
 </Defog>
 <SupplementLight>
  <!--opt-->
  <enabled>
   <!--req, xs:boolean-->
  </enabled>
  <isSupportFireLaserLight>
   <!--opt, xs:boolean, "true, false"-->
  </isSupportFireLaserLight>
  <isSupportSupplementLightWord>
   <!--opt, xs:boolean, "true, false", whether to support displaying supplement light prompt-->
  </isSupportSupplementLightWord>
  <captureWithSupplimentLightEnabled>
   <!--opt, xs:boolean, "true,false", enable snapshot supplement light or not-->
  </captureWithSupplimentLightEnabled>
 </SupplementLight>
 <Deicing><!--opt-->
  <enabled><!--req, xs:boolean--></enabled>
 </Deicing>
 <ManualDeicing><!--opt-->
  <enabled><!--req, xs:boolean--></enabled>
 </ManualDeicing>
 <mutexAbility>
  <!--req, "laserLight,deicing", mutual exclusion ability, the laser light and deicing (including manual deicing and
automatic deicing) are mutual exclusive-->
 </mutexAbility>
 <VisibleMovementPower><!--opt-->
  <enabled><!--req, xs:boolean--></enabled>
 </VisibleMovementPower>
 <ThermalMovementPower><!--opt-->
  <enabled><!--req, xs:boolean--></enabled>
 </ThermalMovementPower>

 <PtzPower><!--opt-->
  <enabled><!--req, xs:boolean--></enabled>
 </PtzPower>
 <powerSavingControl><!--opt, xs:string, power saving strategy: "sleepMode"-sleeping mode, lowConsumptionMode-
低功耗模式 --></powerSavingControl>
 <HighTemperatureProtection><!--opt-->
  <enabled><!--req, xs:boolean --></enabled>
  <temperatureType><!--dep, xs:string,unit:℃, "90,100,110" --></temperatureType>
 </HighTemperatureProtection>
</HardwareService>

16.2.152 XML_hdd
XML Message about HDD Parameters
<hdd version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--ro, req, xs: string; ID--></id>
 <hddName><!--ro, req, xs: string--></hddName>
 <hddPath><!--ro, opt, xs: string--></hddPath>
 <hddType><!--ro, req, xs: string, "IDE, SATA, eSATA, NFS, iSCSI, Virtual Disk"--></hddType>
 <status>
   <!--ro, req, xs: string,
"ok,unformatted,error,idle,mismatch,offline,smartFailed,reparing,formating,notexist,unRecordHostFormatted",unReco
rdHostFormatted--unformatted in education sharing system-->
 </status>
 <capacity><!--ro, req, xs: float, unit: MB--></capacity>
 <freeSpace><!--ro, req, xs: float, unit: MB--></freeSpace>
 <property><!--req, xs: string, HDD properties, "RW,RO,Redund"--></property>
 <group><!--opt, xs: string; HDD group ID--></group>
 <DataModeList><!--opt, ro, current HDD allocation mode-->
   <DataMode>
    <type><!--req, xs: string, storage application type: recordStorage-video storage, pictureCloudStorage-picture to be
saved in cloud storage, fileStorage-file-storage--></type>
    <occupancyRate><!--req, xs: integer, HDD usage, range: [0,100]--></occupancyRate>
   </DataMode>
 </DataModeList>
 <formatType>
   <!--ro, opt, xs: string, formatting type: FAT32 (default) and EXT4, this node is only available for SD card; if this node
does not exist, the default formatting type is FAT32-->
 </formatType>
 <encryptionStatus><!--ro, opt, xs:string, encryption status: "unencrypted", "encrypted", "verfyFailed"-verification
failed--></encryptionStatus>
</hdd>

16.2.153 XML_hddList
hddList message in XML format

<hddList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <hdd/><!--opt, refer to the message XML_hdd for details-->
</hddList>

See Also
XML_hdd

16.2.154 XML_HDDSMARTTest
HDDSMARTTest message in XML format
<HDDSMARTTest version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <testType><!--opt, xs: string, checking type: short,expanded,conveyance--></testType>
</HDDSMARTTest>

16.2.155 XML_Hello
Hello message in XML format
<?xml version="1.0" encoding="UTF-8"?>
<Hello>
 <Types>hello</Types>
 <!--device type value-->
 <DeviceType>1234</DeviceType>
 <!--device type description-->
 <DeviceDescription>DS-2CD4024F</DeviceDescription>
 <!--device serial No.-->
 <DeviceSN>DS-2CD4024F20130925CCCH435107838</DeviceSN>
 <!--command port number of private protocol-->
 <CommandPort>8000</CommandPort>
 <!--http port number-->
 <HttpPort>80</HttpPort>
 <!--MAC address-->
 <MAC>44-19-b7-10-98-32</MAC>
 <!--IPv4 address-->
 <IPv4Address>172.9.3.106</IPv4Address>
 <!--IPv4 subnet mask-->
 <IPv4SubnetMask>255.255.255.0</IPv4SubnetMask>
 <!--IPv4 gateway-->
 <IPv4Gateway>172.9.3.1</IPv4Gateway>
 <!--IPv6 address-->
 <IPv6Address>2000:1:2:3:4619:b6ff:fe01:dd9d</IPv6Address>
 <!--IPv6 gateway-->
 <IPv6Gateway>2000:1:2:3:4619:b6ff:fe01:1</IPv6Gateway>
 <!--size of IPv6 subnet mask-->
 <IPv6MaskLen>64</IPv6MaskLen>
 <!--enable/disable DHCP, true: enable, false: disable-->
 <DHCP>false</DHCP>

 <!--total number of analog channels-->
 <AnalogChannelNum>32</AnalogChannelNum>
 <!--total number of digital channels-->
 <DigitalChannelNum>32</DigitalChannelNum>
 <!--device software version information, not encrypt-->
 <SoftwareVersion>V4.1.0 build130126</SoftwareVersion>
 <!--DSP version information, not encrypt-->
 <DSPVersion>V4.0 build130111</DSPVersion>
 <!--device started time-->
 <BootTime>2014-01-06 11:39:00</BootTime>
 <!--true: OEM device, false: baseline device-->
 <OEMCode>true</OEMCode>
 <!--OEM manufacturer information, optional.-->
 <OEMInfo>Axis</OEMInfo>
 <!--device software version information, it is encrypted in AES128/AES256 CBC mode with fixed key-->
 <SoftwareVersionEncrypt>V4.1.0 build130126</SoftwareVersionEncrypt>
 <!--DSP version, it is encrypted in AES128/AES256 CBC mode with fixed key-->
 <DSPVersionEncrypt>V4.0 build130111</DSPVersionEncrypt>
 <!--OEM manufacturer information, it is encrypted in AES128/AES256 CBC mode with fixed key, optional-->
 <OEMInfoEncrypt >Axis</OEMInfoEncrypt>
 <!--true: encrypted device, false: normal device>
 <Encrypt>true</ Encrypt >
 <!--security code generated by specific algorithm (reserved), which is to prevent piracy-->
 <SafeCode>123456</SafeCode>
 <!--support upgrading reset password or not, true: yes, false: no>
 <ResetAbility>true</ResetAbility>
 <!--number of HDDs>
 <DiskNumber>1</ DiskNumber >
 <!--true: activated, false: inactivated>
 <Activated>true</Activated>
 <!--support resetting password or not, true: yes, false: no>
 <PasswordResetAbility>true</PasswordResetAbility>
 <!--support synchronizing password of network camera or not, true: yes, false: no>
 <SyncIPCPassword>true</SyncIPCPassword>
 <!--support password reset mode 2 or not, true: yes, false: no>
 <PasswordResetModeSecond>true</PasswordResetModeSecond>
 <!--OEMCode details-->
 <DetailOEMCode>10101</DetailOEMCode>
 <!--true: EZVIZ device, false: baseline device-->
 <EZVIZCode>true</EZVIZCode>
 <!--support locking device or not, true: yes, false: no-->
 <DeviceLock>true</DeviceLock>
</Hello>

16.2.156 XML_HttpHostNotification
HttpHostNotification message in XML format
<HttpHostNotification version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string, ID--></id>
 <url><!--req, xs:string, the absolute path, e.g., http://<ipAddress>:<portNo>/<uri>--></url>

 <protocolType><!--req, xs:string, "HTTP,HTTPS,EHome"--></protocolType>
 <parameterFormatType><!--req, xs:string, alarm/event information format, "XML,JSON"--></parameterFormatType>
 <addressingFormatType><!--req, xs:string, "ipaddress,hostname"--></addressingFormatType>
 <hostName><!--dep, xs:string--></hostName>
 <ipAddress><!--dep, xs:string--></ipAddress>
 <ipv6Address><!--dep, xs:string--></ipv6Address>
 <portNo><!--opt, xs:integer--></portNo>
 <userName><!--dep, xs:string--></userName>
 <password><!--dep, xs:string--></password>
 <httpAuthenticationMethod><!--req, xs:string, "MD5digest,none"--></httpAuthenticationMethod>
 <eventType opt="AID,TFS,TPS"><!--req, xs:string--></eventType>
 <uploadImagesDataType>
  <!--opt, xs:string, "URL", "binary" (default), for cloud storage, only "URL" is supported-->
 </uploadImagesDataType>
 <eventMode><!--opt, xs:string, "all,list"--></eventMode>
 <EventList><!--dep, it is valid only when eventMode is "list"-->
  <Event><!--req-->
   <type><!--req, xs:string--></type>
  </Event>
 </EventList>
 <channels><!--opt, xs:string, "1,2,3,4…"--></channels>
 <SubscribeEvent/><!--opt, event subscription parameters, see details in the message of XML_SubscribeEvent-->
</HttpHostNotification>

Example
Message Example of HttpHostNotification
<HttpHostNotification version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <id>1</id>
 <url></url>
 <protocolType>HTTP</protocolType>
 <parameterFormatType>XML</parameterFormatType>
 <addressingFormatType>ipaddress</addressingFormatType>
 <ipAddress>0.0.0.0</ipAddress>
 <portNo>80</portNo>
 <userName></userName>
 <httpAuthenticationMethod>none</httpAuthenticationMethod>
</HttpHostNotification>

16.2.157 XML_HttpHostNotificationCap
HttpHostNotificationCap capability message in XML format
<HttpHostNotificationCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <hostNumber><!--Listening host No.--></hostNumber>
 <urlLen max=""/>
 <protocolType opt="HTTP,HTTPS,EHome"/>
 <parameterFormatType opt="XML,querystring,JSON"/>
 <addressingFormatType opt="ipaddress,hostname"/>
 <ipAddress opt="ipv4,ipv6"/>
 <portNo min="" max=""/>

 <userNameLen min="" max=""/>
 <passwordLen min="" max=""/>
 <httpAuthenticationMethod opt="MD5digest,none"/>
  <!--req, if the digest authentication is supported, configuring user name and password should be supported-->
 <uploadImagesDataType opt="URL,binary"/>
</HttpHostNotificationCap>

Example
HttpHostNotificationCap Message Example
<HttpHostNotificationCap version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <hostNumber>3</hostNumber>
 <urlLen max="64" />
 <protocolType opt="HTTP" />
 <parameterFormatType opt="XML" />
 <addressingFormatType opt="ipaddress,hostname" />
 <ipAddress opt="ipv4,ipv6" />
 <portNo min="1" max="65535" />
 <userNameLen min="5" max="32" />
 <passwordLen min="5" max="32" />
 <httpAuthenticationMethod opt="none" />
 <uploadImagesDataType opt="URL,binary" />
</HttpHostNotificationCap>

16.2.158 XML_HttpHostNotificationList
HttpHostNotificationList message in XML format
<HttpHostNotificationList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <HttpHostNotification>
  <id><!--req, xs:string, ID--></id>
  <url><!--req, xs:string--></url>
  <protocolType><!--req, xs:string, "HTTP,HTTPS"--></protocolType>
  <parameterFormatType><!--req, xs:string, alarm/event information format, "XML,JSON"--></parameterFormatType>
  <addressingFormatType><!--req, xs:string, "ipaddress,hostname"--></addressingFormatType>
  <hostName><!--dep, xs:string--></hostName>
  <ipAddress><!--dep, xs:string--></ipAddress>
  <ipv6Address><!--dep, xs:string--></ipv6Address>
  <portNo><!--opt, xs:integer--></portNo>
  <userName><!--dep, xs:string--></userName>
  <password><!--dep, xs:string--></password>
  <httpAuthenticationMethod><!--req, xs:string, "MD5digest,none"--></httpAuthenticationMethod>
  <uploadImagesDataType>
   <!--opt, xs:string, "URL", "binary" (default), for cloud storage, only "URL" is supported-->
  </uploadImagesDataType>
  <eventMode><!--opt, xs:string, "all,list"--></eventMode>
  <EventList><!--dep, it is valid only when eventMode is "list"-->
   <Event><!--req-->
    <type><!--req, xs:string--></type>
   </Event>
  </EventList>

  <channels><!--opt, xs:string, "1,2,3,4…"--></channels>
 </HttpHostNotification>
</HttpHostNotificationList>

Example
HttpHostNotificationList Message Example
<HttpHostNotificationList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <HttpHostNotification>
  <id>1</id>
  <url></url>
  <protocolType>HTTP</protocolType>
  <parameterFormatType>XML</parameterFormatType>
  <addressingFormatType>ipaddress</addressingFormatType>
  <ipAddress>0.0.0.0</ipAddress>
  <portNo>80</portNo>
  <userName></userName>
  <httpAuthenticationMethod>none</httpAuthenticationMethod>
 </HttpHostNotification>
</HttpHostNotificationList>

16.2.159 XML_HttpHostTestResult
HttpHostTestResult message in XML format.
<HttpHostTestResult version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <errorDescription>
  <!--req, xs:string-->
 </errorDescription>
</HttpHostTestResult>

16.2.160 XML_IbeaconParam
IbeaconParam message in XML format
<IbeaconParam xmlns="http://www.isapi.org/ver20/XMLSchema" version="2.0">
 <UUID min="" max="">
  <!--req, xs:string, parking lot ID, which supports using digits, letters and hyphen as the tag-->
 </UUID>
 <major min="" max="">
  <!--req, xs:integer, number of floors in the parking lot, which cannot be 0x00 for all-->
 </major>
 <minor min="" max="">
  <!--req, xs:integer, number of parking spaces in each floor, which cannot be 0x00 for all-->
 </minor>
 <sendPower min="" max="">
  <!--req, xs:integer, transmitted power: 01-0 dbm, 02- -6 dbm, 03- -23 dbm-->
 </sendPower>
 <frequency min="" max="">

  <!--req, xs:integer, transmitted frequency, which is the broadcast time interval, unit: 625 µs. The broadcast time
interval is between 32 (20 ms) to 8000 (5s), and the default value is 160 (100 ms)-->
 </frequency>
 <measurePower min="" max="">
  <!--req, xs:integer, rated power, which is the RSSI (Received Signal Strength Indication) in the position of one meter
away, unit: dbm-->
 </measurePower>
</IbeaconParam>

16.2.161 XML_IEEE802_1x
IEEE802_1x message in XML format
<IEEE802_1x version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  <enabled><!--req, xs: boolean--></enabled>
  <authenticationProtocolType>
   <!--req, xs: string, "EAP-TLS,EAP-TTLS,EAP-PEAP,EAP-LEAP,EAP-FAST,EAP-MD5"-->
  </authenticationProtocolType>
  <innerTTLSAuthenticationMethod>
   <!--dep, xs: string, "MS-CHAP,MS-CHAPv2,PAP,EAP-MD5", this node is required when <authenticationProtocolType>
is "EAP-TLS"-->
  </innerTTLSAuthenticationMethod>
  <innerEAPProtocolType>
   <!--dep, xs: string, "EAP-POTP,MS-CHAPv2", this node is required when <authenticationProtocolType> is "EAP-
PEAP" or "EAP-FAST-->
  </innerEAPProtocolType>
  <validateServerEnabled><!--dep, xs: boolean--></validateServerEnabled>
  <userName><!--dep, xs: string--></userName>
  <password><!--dep, xs: string--></password>
  <anonymousID><!--opt, xs: string--></anonymousID>
  <autoPACProvisioningEnabled>
   <!--dep, xs: boolean, this node is required when <authenticationProtocolType> is "EAP-FAST"-->
  </autoPACProvisioningEnabled>
  <Extensions><!--opt-->
   <EAPOLVersion><!--opt, xs:string, "1, 2"--></EAPOLVersion>
  </Extensions>
</IEEE802_1x>

Remarks
• For EAP-LEAP or EAP-MD5, the parameters userName, password, and Extensions can be
  configured.
• For EAP-TLS, the parameters userName, password, and Extensions can be configured, and the
  certificates with different types (i.e., CA, user certificate, key) can be uploaded.

16.2.162 XML_IllegalLoginLock
IllegalLoginLock message in XML format

<IllegalLoginLock version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled>true</enabled>
 <maxIllegalLoginTimes>
   <!--opt, xs: integer, maximum illegal login attempts, whose value is between 3 and 20, and the default value is 5-->
 </maxIllegalLoginTimes>
</IllegalLoginLock>

16.2.163 XML_ImageCap
ImageCap message in XML format
<ImageCap version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <isSupportRegionalExposure><!--opt, xs:boolean--></isSupportRegionalExposure>
 <isSupportRegionalFocus><!--opt, xs:boolean--></isSupportRegionalFocus>
</ImageCap>

16.2.164 XML_ImageChannel
ImageChannel message in XML format
<ImageChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs: integer--></id>
 <enabled><!--req, xs: boolean--></enabled>
 <videoInputID><!--req, xs: integer--></videoInputID>
 <Defog/><!--opt, electronic defogging parameters, see details in the message of XML_Defog-->
 <NoiseReduce2D/><!--opt, 2D noise reduction parameters, see details in the message of XML_NoiseReduce2D-->
 <Focusconfiguration/><!--opt-->
 <LensInitialization/><!--opt-->
 <ImageFlip/><!--opt, image automatic flipping parameters, see details in the message of XML_ImageFlip-->
 <ImageFreeze/><!--opt-->
 <proportionalpan/><!--opt-->
 <WDR/><!--opt, WDR parameters, refer to the message XML_WDR for details-->
 <BLC/><!--opt, BLC parameters, refer to the message XML_BLC for details-->
 <NoiseReduce/><!--opt, 3D DNR parameters, see details in the message of XML_NoiseReduce-->
 <ImageEnhancement/><!--opt, image enhancement parameters, see details in the message of
XML_ImageEnhancement-->
 <DSS/><!--opt, low illumination electronic shutter parameters in exposure, see details in the message of XML_DSS-->
 <WhiteBlance/><!--opt, WB parameters, see details in the message of XML_WhiteBlance-->
 <Exposure/><!--opt, exposure parameters, see details in the message of XML_Exposure-->
 <Sharpness/><!--opt, sharpness parameters, see details in the message of XML_Sharpness-->
 <gammaCorrection/><!--opt, gamma correction parameters, see details in the message of XML_gammaCorrection-->
 <powerLineFrequency/><!--opt, image standard parameters, refer to the message XML_powerLineFrequency for
details-->
 <Color/><!--opt, image color parameters, see details in the message of XML_Color-->
 <IrcutFilter/><!--opt, day/night auto switch parameters, see details in the message of XML_IrxutFilter-->
 <ImageModeList/><!--opt, default image mode parameters, see details in the message of XML_ImageModeList-->
 <BrightEnhance/><!--opt, brightness enhancement parameters, see details in the message of XML_BrightEnhance-->
 <ISPMode/><!--opt, day/night mode parameters, see details in the message of XML_ISPMode-->

 <Shutter/><!--opt, shutter parameters in exposure, see details in the message of XML_Shutter-->
 <Gain/><!--opt, gain parameters, see details in the message of XML_Gain-->
 <ImageIcrE/><!--opt, IR-cut filter parameters, see details in the message of XML_ImageIcrE-->
 <ImageMultishut/><!--opt, multi-shutter parameters, see details in the message of XML_ImageMultishut-->
 <PlateBright/><!--opt, license plate brightness compensation parameters, see details in the message of
XML_PlateBright-->
 <JPEGParam/><!--opt, JPEG picture size parameters, see details in the message of XML_JPEGParam-->
 <DarkEnhance/><!--opt, dark space enhancement parameters, see details in the message of XML_DarkEnhance-->
 <Hdr/><!--opt, WDR (Wide Dynamic Range) parameters, see details in the message of XML_Hdr-->
 <LSE/><!--opt, contrast enhancement parameters, see details in the message of XML_LSE-->
 <MCE/><!--opt, memory color enhancement parameters, see details in the message of XML_MCE-->
 <Svce/><!--opt, part contrast parameters, see details in the message of XML_Svce-->
 <SectionCtrl/><!--opt, configuration parameters of picture exposure control by video segment, see details in the
message of XML_SectionCtrl-->
 <AutoContrast/><!--opt, automatic contrast parameters, see details in the message of XML_AutoContrast-->
 <GrayRange/><!--opt, grayscale range parameters, see details in the message of XML_GrayRange-->
 <LSEDetail/><!--opt, contrast enhancement parameters, see details in the message of XML_LSE-->
 <ITCImageSnap/><!--opt, captured picture parameters, see details in the message of XML_ITCImageSnap-->
 <ImageRecord/><!--opt, image parameters in the recorded video, see details in the message of XML_ImageRecord-->
 <Scene/><!--opt-->
 <EPTZ/><!--opt-->
 <EIS/><!--opt-->
 <HLC/><!--opt-->
 <ZoomLimit/><!--opt-->
 <corridor/><!--opt, image rotate mode parameters, refer to the message XML_corridor for details-->
 <Dehaze/><!--opt, defog mode parameters, refer to the message XML_Dehaze for details-->
 <ImageMode/><!--opt, xs: string, image mode: "standard, indoor, outdoor, dimLight"-->
 <enableImageLossDetection><!--opt, xs: boolean--></enableImageLossDetection>
 <CaptureMode/><!--opt, video input mode parameters, refer to the message XML_CaptureMode for details-->
 <IrLight/><!--opt-->
 <LensDistortionCorrection/><!--opt-->
 <ExposureSync/><!--opt-->
 <BrightnessSuddenChangeSuppression/><!--opt-->
 <TempRange/><!--opt, temperature range, refer to the message XML_tempRange for details-->
</ImageChannel>

16.2.165 XML_ImageChannellist
ImageChannellist message in XML format
<ImageChannellist version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ImageChannel/><!--opt-->
</ImageChannellist>

See Also
XML_ImageChannel

16.2.166 XML_ImageFlip
ImageFlip message in XML format
<ImageFlip version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled/><!--req, xs:boolean-->
 <ImageFlipStyle/><!--opt, xs:string, "LEFTRIGHT, UPDOWN, CENTER, AUTO", it can be enabled only when the value is
"true"-->
 <flipAngle><!--opt, xs:string, "90, 180, 270"--></flipAngle>
</ImageFlip>

16.2.167 XML_ImageMode
ImageMode message in XML format
<ImageMode version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <type><!--req, xs:string, "standard, indoor, outdoor, dimLight"--></type>
 <recommendation><!--req, ro-->
  <brightnessLevel><!--opt, xs:integer, ranging from 0 to 100--></brightnessLevel>
  <contrastLevel><!--opt, xs:integer, ranging from 0 to 100--></contrastLevel>
  <sharpnessLevel><!--opt, xs:integer, ranging from 0 to 100--> </sharpnessLevel>
  <saturationLevel><!--opt, xs:integer, ranging from 0 to 100--></saturationLevel>
  <hueLevel><!--opt, xs:integer, ranging from 0 to 100--></hueLevel>
  <deNoiseLevel><!--opt, xs:integer, ranging from 0 to 100--></deNoiseLevel>
 </recommendation>
</ImageMode>

16.2.168 XML_ImageModeList
ImageModeList message in XML format
<ImageModeList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ImageMode/><!--opt, see details in the message of XML_ImageMode-->
</ImageModeList>

See Also
XML_ImageMode

16.2.169 XML_InputProxyChannel
InputProxyChannel message in XML format
<InputProxyChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string, starts from 1--></id>
 <name><!--opt, xs:string--></name>
 <sourceInputPortDescriptor><!--req-->

  <adminProtocol><!--req, xs:string, "HIKVISION,SONY,ISAPI,ONVIF,..."--></adminProtocol>
  <addressingFormatType><!--req, xs:string, "ipaddress,hostname"--></addressingFormatType>
  <hostName><!--dep, xs:string, domain name--></hostName>
  <ipAddress><!--dep, xs:string, IP address--></ipAddress>
  <ipv6Address><!--dep, xs:string, IPv6 address--></ipv6Address>
  <managePortNo><!--req, xs:integer--></managePortNo>
  <srcInputPort><!--req, xs:string, channel No.--></srcInputPort>
  <userName><!--req, xs:string, user name, which should be encrypted--></userName>
  <password><!--req, wo, xs:string, password, which should be encrypted--></password>
  <streamType><!--opt, xs:string, opt="auto,tcp,udp"--></streamType>
  <deviceID><!--dep, xs:string--></deviceID>
  <deviceTypeName><!--ro, opt, xs:string, device type name--></deviceTypeName>
  <serialNumber><!--ro, opt, xs:string, device serial No.--></serialNumber>
  <firmwareVersion><!--ro, opt, xs:string, firmware version--></firmwareVersion>
  <firmwareCode><!--ro, opt, xs:string, firmware code--></firmwareCode>
 </sourceInputPortDescriptor>
 <enableAnr>
  <!--opt, xs:boolean, whether enables ANR funtion-->
 </enableAnr>
 <NVRInfo>
  <ipAddressNVR>
   <!--opt, xs:string, IP address of NVR-->
  </ipAddressNVR>
  <portNVR>
   <!--opt, xs:integer, port No. of NVR-->
  </portNVR>
  <ipcChannelNo>
   <!--opt, xs:integer, channel No. of the network camera in NVR-->
  </ipcChannelNo>
 </NVRInfo>
</InputProxyChannel>

16.2.170 XML_InputProxyChannelList
InputProxyChannelList message in XML format
<InputProxyChannelList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <InputProxyChannel/><!--opt, see details in
                      XML_InputProxyChannel
                    -->
</InputProxyChannelList>

16.2.171 XML_Cap_InputProxyChannelListCap
InputProxyChannelListCap capability message in XML format
<InputProxyChannelListCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <InputProxyChannel>
  <id min="" max=""/><!--req,xs:string,starts from 1-->

  <name min="" max=""/><!--opt,xs:string-->
  <sourceInputPortDescriptor><!--req-->
   <adminProtocol opt="HIKVISION,SONY,ISAPI,ONVIF,..."/><!--req,xs:string-->
   <addressingFormatType opt="ipaddress,hostname"/><!--req,xs:string-->
   <hostName min="" max=""/><!--dep, xs:string, domain name-->
   <ipAddress min="" max=""/><!--dep, xs:string, IP address-->
   <ipv6Address min="" max=""/><!--dep, xs:string, IPv6 address-->
   <managePortNo min="" max=""/><!--req, xs:integer, port number-->
   <srcInputPort min="" max=""/><!--req, xs:string, channel No.-->
   <userName min="" max=""/><!--req, xs:string-->
   <password min="" max=""/><!--req, wo, xs:string-->
   <streamType opt="auto,tcp,udp"/><!--opt, xs:string-->
   <deviceID min="" max=""/><!--dep, xs:string-->
  </sourceInputPortDescriptor>
 </InputProxyChannel>
</InputProxyChannelListCap>

16.2.172 XML_InputProxyChannelStatus
InputProxyChannelStatus message in XML format
<InputProxyChannelStatus version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string--></id>
 <sourceInputPortDescriptor/><!--req-->
 <online><!--req, xs:boolean, whether the camera is online--></online>
 <streamingProxyChannelIdList><!--req-->
   <streamingProxyChannelId>
    <!--req, xs:string, stream channel No., e.g., 101-main stream of channel 1, 102-sub-stream of channel 1-->
   </streamingProxyChannelId>
 </streamingProxyChannelIdList>
 <chanDetectResult>
   <!--opt, xs:string, network camera status: "connect"-connected, "overSysBandwidth"-insufficient bandwidth,
"domainError"-incorrect domain name, "ipcStreamFail"-getting stream failed, "connecting", "chacnNoError"-incorrect
channel No., "cipAddrConflictWithDev": IP address is conflicted with device address, "ipAddrConflicWithIpc"-IP
address conflicted, "errorUserNameOrPasswd"-incorrect user name or password, "netUnreachable"-invalid network
address, "unknownError"-unknown error, "notExist"-does not exist, "ipcStreamTypeNotSupport"-the stream
transmission mode is not supported, "ipcResolutionNotSupport"-the resolution of network camera is not supported-->
 </chanDetectResult>
</InputProxyChannelStatus>

16.2.173 XML_InputProxyChannelStatusList
InputProxyChannelStatusList message in XML format
<InputProxyChannelStatusList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <InputProxyChannelStatus/><!--opt, see details in XML_InputProxyChannelStatus-->
</InputProxyChannelStatusList>

See Also
XML_InputProxyChannelStatus

16.2.174 XML_IntelliCap
IntelliCap capability message in XML format
<IntelliCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  <isFaceSupport><!--opt, xs:boolean, whether it supports face detection--></isFaceSupport>
  <isBehaviorSupport><!--opt, xs:boolean, whether it supports behavior analysis--></isBehaviorSupport>
  <isLineDetectionSupport><!--opt, xs:boolean, whether it supports line crossing detection--></
isLineDetectionSupport>
  <isFieldDetectionSupport><!--opt, xs:boolean, whether it supports intrusion detection--></isFieldDetectionSupport>
  <isRegionEntranceSupport><!--opt, xs:boolean, whether it supports region entrance detection--></
isRegionEntranceSupport>
  <isRegionExitingSupport><!--opt, xs:boolean, whether it supports region exiting detection--></
isRegionExitingSupport>
  <isLoiteringSupport><!--opt, xs:boolean, whether it supports loitering detection--></isLoiteringSupport>
  <isGroupSupport><!--opt, xs:boolean, whether it supports people gathering detection--></isGroupSupport>
  <isRapidMoveSupport><!--opt, xs:boolean, whether it supports fast moving detection--></isRapidMoveSupport>
  <isParkingSupport><!--opt, xs:boolean, whether it supports parking detection--></isParkingSupport>
  <isUnattendedBaggageSupport><!--opt, xs:boolean, whether it supports unattended baggage detection--></
isUnattendedBaggageSupport>
  <isAttendedBaggageSupport><!--opt, xs:boolean, whether it supports object removal detection--></
isAttendedBaggageSupport>
  <isTeacherSupport><!--opt, xs:boolean, whether it supports teacher's behavior detection--></isTeacherSupport>
  <isStudentSupport><!--opt, xs:boolean, whether it supports student's behavior detection--></isStudentSupport>
  <isCombinedSupport><!--opt, xs:boolean, whether it supports combined detection--></isCombinedSupport>
  <isTrafficSupport><!--opt, xs:boolean, whether it supports traffic detection--></isTrafficSupport>
  <RestoreLib>
   <libName opt="studentsStoodUp,peopleCounting,shipDetection"><!--opt,xs:string,--></libName>
  </RestoreLib>
  <RestoreDefParamForbid>
   <!--opt, xs:boolean "true, false", forbid restoring algorithm library to default. When the node does not exist, it
indicates restoring to default is not supported. When the node exists and its value is "ture", it indicates support, when
the value is "false", it indicates not support-->
  </RestoreDefParamForbid>
  <RestoreAlgLibParam>
  <!--opt, the capabilities of restoring algorithm library parameters according to algorithm library name-->
   <libName opt="faceSnap,HMS,behaviorAnalysis"><!--opt, xs:string--></libName>
  </RestoreAlgLibParam>
  <isFaceCaptureStatisticsSupport><!--whether it supports face picture statistics--></isFaceCaptureStatisticsSupport>
  <isSupportPersonQueueDetection><!--whether it supports queue management--></
isSupportPersonQueueDetection>
  <isSupportIntersectionAnalysis>
   <!--opt, xs: boolean, whether it supports intersection analysis-->
  </isSupportIntersectionAnalysis>
  <mixedTargetDetectionWithoutAttribute><!--opt, xs: boolean--></mixedTargetDetectionWithoutAttribute>
  <isSupportUploadFacePictureByForm><!--opt, xs:boolean, whether it supports uploading face pictures by form--></
isSupportUploadFacePictureByForm>

  <isSupportUploadFacePictureByUrl><!--opt, xs: boolean, whether it supports uploading face pictures by URL--></
isSupportUploadFacePictureByUrl>
  <isSupportUploadHumanPictureByForm><!--opt, xs:boolean, whether it supports uploading human pictures in form--
></isSupportUploadHumanPictureByForm>
  <isSupportFaceScore><!--opt,xs:boolean, whether it supports face grading configuration (camera)--></
isSupportFaceScore>
  <HumanRecognitionModeSearchCap>
   <searchTargetsNumMax><!--opt, xs:integer, maximum number of sample pictures that can be imported for
searching by picture--></searchTargetsNumMax>
   <HumanMode>
    <searchCond opt="age_group,gender,jacet_color,glass,bag,ride,unlimit"/><!--setting multiple search conditions is
supported-->
    <similarity min="0.0" max="100.0"/><!--opt, xs:float, similarity, range: [0.0,100.0]-->
   </HumanMode>
   <positive opt="true,false"/><!--opt, xs:boolean, whether it is false human body recognition alarm: "true"-yes,
"false"-no-->
   <eventType opt="unlimit,humanRecognition">
    <!--opt, xs:string, event type: "unlimit"-no limit, "humanRecognition"-human body detection alarm-->
   </eventType>
   <isSupportMultiChannelSearch>
    <!--opt, xs:boolean, whether it supports multi-channel search-->
   </isSupportMultiChannelSearch>
   <isSupportTotalSearchResult>
    <!--opt, xs:boolean, whether it supports limiting number of results that can be obtained after a single search-->
   </isSupportTotalSearchResult>
  </HumanRecognitionModeSearchCap>
  <VehicleRecognitionModeSearchCap>
   <searchTargetsNumMax><!--opt, xs:integer, maximum number of sample pictures that can be imported for
searching by picture--></searchTargetsNumMax>
   <eventType opt="unlimit,vehicleBlackList,vehicleWhiteList"/><!--xs:string, event type: "unlimit"-no limit,
"vehicleBlackList"-vehicle blacklist, "vehicleWhiteList"-vehicle whitelist-->
   <VehicleMode>
    <searchCond opt="licensePlate,vehicleLogo,vehicleSubLogoRecog,vehicleType,vehicleColor,unlimit"/>
    <similarity min="0.0" max="100.0"/><!--opt, xs:float, similarity, range: [0.0,100.0]-->
   </VehicleMode>
   <isSupportMultiChannelSearch>
    <!--opt, xs:boolean, whether it supports multi-channel search-->
   </isSupportMultiChannelSearch>
   <isSupportTotalSearchResult>
    <!--opt, xs:boolean, whether it supports limiting number of results that can be obtained after a single search-->
   </isSupportTotalSearchResult>
  </VehicleRecognitionModeSearchCap>
  <FaceContrastPersonInfoExtend><!--configuration capability of face comparison tag-->
   <personInfoCap>
    <maxPersonInfo min="0" max="4">
      <!--opt, xs:integer, maximum number of person tags-->
    </maxPersonInfo>
   </personInfoCap>
   <personInfoFDlibCap>
    <maxPersonInfo min="0" max="4">
      <!--opt, xs:integer, maximum number of person tags-->
    </maxPersonInfo>

  </personInfoFDlibCap>
 </FaceContrastPersonInfoExtend>
 <isSupportSafetyHelmetDetection>
  <!-- opt, xs:boolean, whether it supports hard hat detection-->
 </isSupportSafetyHelmetDetection>
</IntelliCap>

16.2.175 XML_IOCap
IOCap capability message in XML format
<IOCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IOInputPortNums>
  <!--opt, xs:integer-->
 </IOInputPortNums>
 <IOOutputPortNums>
  <!--opt, xs:integer-->
 </IOOutputPortNums>
 <isSupportStrobeLamp>
  <!--opt, xs:integer-->
 </isSupportStrobeLamp>
 <SoftIOInputPortNums>
  <!--opt, xs:integer-->
 </SoftIOInputPortNums>
 <isSupportIOOutputAdvanceParameter>
  <!--opt, xs:boolean, whether supports configuration of alarm input advanced parameters-->
 </isSupportIOOutputAdvanceParameter>
 <isSupportCombinationAlarm>
  <!--opt, xs:boolean, whether supports composite alarm-->
 </isSupportCombinationAlarm>
</IOCap>

16.2.176 XML_IOInputPort
IOInputPort message in XML format
<IOInputPort version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:integer--></id>
 <enabled><!--req,Boolean,"true,false"--></enabled>
 <IODescriptor><!--opt, I/O port description-->
  <proxyProtocol>
   <!--req, string, access protocol, "HIKVISION, AXIS, PANASONIC, BOSCH, PELCO, SONY…"-->
  </proxyProtocol>
  <userName><!--req, string, user name--></userName>
  <addressingFormatType>
   <!--req, string, address type: "ipaddress,hostname"-->
  </addressingFormatType>
  <hostName><!--dep, xs:string--></hostName>
  <ipAddress><!--dep, xs:string--></ipAddress>

  <ipv6Address><!--dep, xs:string--></ipv6Address>
  <managePortNo><!--req, integer, manage port--></managePortNo>
  <innerIOPortID><!--req, integer, I/O port--></innerIOPortID>
 </IODescriptor>
 <triggering><!-- req, xs:string, "high,low"--></triggering>
 <name><!--opt,xs:string--></name>
 <IOUseType>
  <!-- opt, xs:string, "disable,openDoor,doorStatus,custom" -->
 </IOUseType>
 <inputType>
  <!--opt, xs:string, opt="switch,semaphore"-->
 </inputType>
 <CombinationAlarm><!--opt, composite alarm list-->
  <channel><!--req, xs:integer，channel No.--></channel>
  <EventTypeList><!--req, event type list-->
   <eventType><!--req, xs:string, event type--></eventType>
  </EventTypeList>
 </CombinationAlarm>
</IOInputPort>

16.2.177 XML_IOInputPortList
IOInputPortList message in XML format
<IOInputPortList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IOInputPort/><!--opt, alarm input, see details in XML_IOInputPort-->
</IOInputPortList>

See Also
XML_IOInputPort

16.2.178 XML_IOOutputPort
IOOutputPort message in XML format
<IOOutputPort version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!-- req, xs:integer, "2"--></id>
 <PowerOnState>
  <!--req, output port configuration parameters when the device is powered on-->
  <defaultState>
   <!--ro, req, xs:string, default output port signal when it is not triggered, "high,low"-->
  </defaultState>
  <outputState>
   <!--ro, req, output port signal when it is being triggered, xs:string, "high,low,pulse"-->
  </outputState>
  <pulseDuration>
   <!--dep, xs:integer, duration of a output port signal when it is being triggered, it is valid when outputState is
"pulse", unit: milliseconds -->
  </pulseDuration>

 </PowerOnState>
 <name><!--opt, xs:string--></name>
 <IOUseType><!--opt, xs:string, "disable,electricLock,custom"--></IOUseType>
 <normalStatus><!--opt, xs:string, normal status: open-remain open, close-remain closed--></normalStatus>
</IOOutputPort>

16.2.179 XML_IOOutputPortList
IOOutputPortList message in XML format
<IOOutputPortList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IOOutputPort/><!--opt, see details in XML_IOOutputPort-->
</IOOutputPort>

See Also
XML_IOOutputPort

16.2.180 XML_IOPortData
IOPortData message in XML format
<IOPortData xmlns=“http://www.isapi.org/ver20/XMLSchema”>
 <outputState><!--req, xs:string, output level: "high, low"--></outputState>
</IOPortData>

16.2.181 XML_IOPortStatus
IOPortStatus message in XML format
<IOPortStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <!--req-->
 <ioPortID><!--req, xs: integer, I/O No.: 1, 2--></ioPortID>
 <ioPortType><!--req, xs: string, I/O type: "input", "output"--></ioPortType>
 <ioState><!--req, xs: string, I/O status: "active", "inactive"--></ioState>
</IOPortStatus>

16.2.182 XML_IOPortStatusList
IOPortStatusList message in XML format
<IOPortStatusList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IOPortStatus><!--req-->
  <ioPortID><!--req, xs: integer, I/O No.: 1, 2--></ioPortID>
  <ioPortType><!--req, xs: string, I/O type: input, output--></ioPortType>
  <ioState><!-- req, xs: string, I/O status: active, inactive--></ioState>

 </IOPortStatus>
</IOPortStatusList>

16.2.183 XML_IOProxyInputPort
IOProxyInputPort message in XML format
<IOProxyInputPort version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string--></id>
 <enabled><!--req, xs:boolean--></enabled>
 <IODescriptor><!--req, xs:string, description about the IO port connected to the front-end device-->
  <proxyProtocol><!--req, xs:string, "HIKVISION, AXIS, PANASONIC, BOSCH, PELCO, SONY, …"--></proxyProtocol>
  <userName><!--req, wo, xs:string --></userName>
  <password><!--req, wo, xs:string --></password>
  <addressingFormatType><!--dep, req, xs:enumeration, "ipaddress, hostname, …"--></addressingFormatType>
  <hostName><!--dep, xs:string--></hostName>
  <ipAddress><!--dep, xs:string--></ipAddress>
  <ipv6Address><!--dep, xs:string--></ipv6Address>
  <managePortNo><!--req, xs:integer--></managePortNo>
  <innerIOPortID><!--req, xs:string, ID--></innerIOPortID>
 </IODescriptor>
 <triggering><!--req, xs:string, "high, low, rising, falling"--></triggering>
 <name><!--opt, xs:string--></name>
 <CombinationAlarm><!--opt, information list of the combined alarm-->
  <channel><!--req, xs:integer, channel No.--></channel>
  <EventTypeList><!--req, event type list-->
   <eventType>
     <!--list, xs:string, event type-->
   </eventType>
  </EventTypeList>
 </CombinationAlarm>
</IOProxyInputPort>

16.2.184 XML_IOProxyInputPortList
IOProxyInputPortList message in XML format
<IOProxyInputPortList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IOProxyInputPort/><!--opt, input configuration of one digital channel, see details in the message of
XML_IOProxyInputPort-->
</IOProxyInputPortList>

See Also
XML_IOProxyInputPort

16.2.185 XML_IOProxyOutputPort
IOProxyOutputPort message in XML format
<IOProxyOutputPort version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string--></id>
 <IODescriptor/><!--req-->
 <PowerOnState><!--req-->
  <defaultState><!--req, xs:string, "high, low"--></defaultState>
  <outputState><!--req, xs:string, "high, low, pulse"--></outputState>
  <pulseDuration><!--dep, xs:integer, unit: milliseconds--></pulseDuration>
 </PowerOnState>
 <name><!--opt, xs:string--></name>
</IOProxyOutputPort>

16.2.186 XML_IOProxyOutputPortList
IOProxyOutputPortList message in XML format
<IOProxyOutputPortList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IOProxyOutputPort/><!--opt, output configuration of one digital channel, see details in the message of
XML_IOProxyOutputPort-->
</IOProxyOutputPortList>

See Also
XML_IOProxyOutputPort

16.2.187 XML_IOTTriggersCap
IOTTriggersCap message in XML format
<?xml version="1.0" encoding="utf-8"?>
<IOTTriggersCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <AccessController><!--opt, security control panel-->
  <XXTriggerCap><!--opt,xs: EventTriggerCapType--></XXTriggerCap>
 </AccessController>
 <VideoIntercom><!--opt, video intercom-->
  <XXTriggerCap><!--opt,xs: EventTriggerCapType --></XXTriggerCap>
 </VideoIntercom>
 <GJD><!--opt, GJD security control panel-->
  <XXTriggerCap><!--opt,xs: EventTriggerCapType--></XXTriggerCap>
 </GJD>
 <Luminite><!--opt, Luminite security control panel-->
  <XXTriggerCap><!--opt,xs: EventTriggerCapType--></XXTriggerCap>
 </Luminite>
 <OPTEX><!--opt, OPTEX security control panel-->
  <XXTriggerCap><!--opt,xs: EventTriggerCapType--></XXTriggerCap>

 </OPTEX>
 <CameraDetector><!--opt, detector-->
  <XXTriggerCap><!--opt,xs: EventTriggerCapType--></XXTriggerCap>
 </CameraDetector>
</IOTTriggersCap>

Remarks
The XX in the node <XXTriggerCap> corresponds to detailed event type. E.g., if the event type is
humanRecognition, then the returned node is <HumanRecognitionTriggerCap>.
See Also
XML_EventTriggerCapType

16.2.188 XML_IPAddress
IPAddress message in XML format
<IPAddress version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ipVersion><!--req, xs:string, "v4,v6,dual"--></ipVersion>
 <addressingType><!--req, xs:string, "static,dynamic,apipa--></addressingType>
 <ipAddress><!--dep, xs:string, ipv4 address--></ipAddress>
 <subnetMask><!--dep, xs:string, subnet mask for IPv4 address--></subnetMask>
 <ipv6Address><!--dep, xs:string--></ipv6Address>
 <bitMask><!--dep, xs:integer, bitmask IPv6 address--></bitMask>
 <DefaultGateway><!--dep-->
  <ipAddress><!--dep, xs:string--></ipAddress>
  <ipv6Address><!--dep, xs:string--></ipv6Address>
 </DefaultGateway>
 <PrimaryDNS><!--dep-->
  <ipAddress><!--dep, xs:string--></ipAddress>
  <ipv6Address><!--dep, xs:string--></ipv6Address>
 </PrimaryDNS>
 <SecondaryDNS><!--dep-->
  <ipAddress><!--dep, xs:string--></ipAddress>
  <ipv6Address><!--dep, xs:string--></ipv6Address>
 </SecondaryDNS>
 <Ipv6Mode><!--opt-->
  <ipV6AddressingType><!--dep, xs:string, "router,ra,manual,dhcp"--></ipV6AddressingType>
  <ipv6AddressList>
   <v6Address>
    <id><!--dep, xs:string; id--></id>
  <type><--dep, xs:string, "router,ra,manual,dhcp"--></type>
  <address><!--dep, xs:string--></address>
  <bitMask><!--dep, xs:integer--></bitMask>
   </v6Address>
  </ipv6AddressList>
 </Ipv6Mode>
</IPAddress>

16.2.189 XML_IPFilter
IPFilter message in XML format
<IPFilter version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs:boolean--></enabled>
 <permissionType><!--opt, xs:string, "deny,allow"--></permissionType>
 <IPFilterAddressList size = "32"/><!--opt, the character size indicates the max. number of supported IP address. See
XML_IPFilterAddressList for details-->
</IPFilter>

See Also
XML_IPFilterAddressList

16.2.190 XML_IPFilterAddress
IPFilterAddress message in XML format
<IPFilterAddress version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string;id--></id>
 <permissionType><!--dep, xs:string, "deny,allow" --></permissionType>
 <addressFilterType><!--ro, xs:string, "mask, range"--></addressFilterType>
 <AddressRange><!--dep, it is valid when <addressFilterType> is "range"-->
  <startIPAddress><!--dep, xs:string--></startIPAddress>
  <endIPAddress><!--dep, xs:string--></endIPAddress>
  <startIPv6Address><!--dep, xs:string--></startIPv6Address>
  <endIPv6Address><!--dep, xs:string--></endIPv6Address>
 </AddressRange>
 <AddressMask><!--dep, it is valid when <addressFilterType> is "mask"-->
  <ipAddress><!--dep, xs:string--></ipAddress>
  <ipv6Address><!--dep, xs:string--></ipv6Address>
  <bitMask><!--opt, xs:string--></bitMask>
 </AddressMask>
</IPFilterAddress>

16.2.191 XML_IPFilterAddressList
IPFilterAddressList message in XML format
<IPFilterAddressList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IPFilterAddress/><!--opt, see XML_IPFilterAddress for details-->
</IPFilterAddressList>

See Also
XML_IPFilterAddress

16.2.192 XML_IrcutFilter
IrcutFilter message in XML format
<IrcutFilter version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <IrcutFilterType>
  <!--opt, xs: string, day/night auto switch mode: "auto, day, night, schedule, eventTrigger, darkFighterX,
darkFighterXAuto, darkFighterXSchedule"-->
 </IrcutFilterType>
 <dayToNightFilterLevel>
  <!--opt, xs: string, level of switching day to night: "low, normal, high"-->
 </dayToNightFilterLevel>
 <dayToNightFilterTime>
  <!--opt, xs: integer, time interval of switching day to night-->
 </dayToNightFilterTime>
 <nightToDayFilterLevel>
  <!--opt, xs: string, level of switching night to day: "low, normal, high"-->
 </nightToDayFilterLevel>
 <nightToDayFilterTime>
  <!--opt, xs: integer, time interval of switching night to day-->
 </nightToDayFilterTime>
 <Schedule><!--dep-->
  <scheduleType><!--req, xs: string, schedule type: "day,night"></scheduleType>
  <TimeRange><!--req, time period on schedule-->
    <beginTime><!--req, xs: time, which is in ISO8601 time format--></beginTime>
    <endTime><!--req, xs:time, which is in ISO8601 time format--></endTime>
  </TimeRange>
 </Schedule>
 <EventTrigger><!--dep-->
  <eventType><!--req, xs: string, event type: "IO,VMD"></eventType>
  <IrcutFilterAction><!--req, xs:string, "day,night"></IrcutFilterAction >
 </EventTrigger>
</IrcutFilter>

16.2.193 XML_IrisData
IrisData message in XML format
<IrisData version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <iris>
  <!--req, xs: integer, a vector, whose value is the percentage of the maximum iris adjusting speed: negative value-
close iris; positive value-open iris-->
 </iris>
</IrisData>

16.2.194 XML_ISPMode
ISPMode message in XML format
<ISPMode version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <mode><!--opt, xs:string, "auto,schedule"--></mode>
 <Schedule><!--dep-->
  <scheduleType><!--req, xs:string, "day,night"--></scheduleType>
  <TimeRange><!--req-->
   <beginTime><!--req, xs:time, ISO8601 time--></beginTime>
   <endTime><!--req, xs:time, ISO8601 time--></endTime>
  </TimeRange>
 </Schedule>
</ISPMode>

16.2.195 XML_ItemList
ItemList message in XML format
<ItemList>
 <Item>
  <itemID>
    <!--req, xs:string, item ID, which is between 1 and 15-->
  </itemID>
  <itemOrder>
    <!--req, xs:string, name element: "none", "devIp"-device IP address, "time", "buildUnitNo"-building No. and unit
No., "outDoorDevNo"-door station, "unlockType"-unlocking type, "devName"-device name, "deviceNo"-device No.,
"channelName"-channel name, "channelNo"-channel No., "plateNo"-license plate number, "plateColor"-license plate
color, "laneNo"-lane No., "carSpeed"-vehicle speed, "positionInfo1"-camera 1, "pictureNo"-picture No., "CarNo"-
vehicle No., "speedLimit"-speed limit, "illegalCode"-violation code, "siteNo"-intersection No., "directionNo"-direction
No., "carColor"-vehicle color, "platePosition"-license plate coordinates, "carType"-vehicle type, "illegalType"-violation
type, "custom"-->
  </itemOrder>
  <itemCustomStr>
    <!--req, xs:string, element custom string, which is between 1 and 32, unit: bytes. This node is valid only when
<itemOrder> is "custom". Currently traffic cameras only support one custom name-->
  </itemCustomStr>
 </Item>
</ItemList>

16.2.196 XML_Language
Language message in XML format
<Language version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <type><!--req, xs: string, "GBK,EUC-KR", def="GBK"--></type>
</Language>

16.2.197 XML_LensDistortionCorrection
LensDistortionCorrection message in XML format
<PrivacyMaskRegion version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs: integer--></id>
 <enabled><!--req, xs: boolean--></enabled>
 <RegionCoordinatesList><!--req-->
  <RegionCoordinates><!--list-->
   <positionX><!--req, xs: integer; coordinate--></positionX>
   <positionY><!--req, xs: integer; coordinate--></positionY>
  </RegionCoordinates>
 </RegionCoordinatesList>
 <privacymaskName><!--opt, xs: string--></privacymaskName>
 <maskType>
  <!--opt, xs: string, "gray,red,yellow,blue,orange,green,transparent,half-transparent,mosaic"-->
 </maskType>
 <zoomdoorlimit><!--opt, xs: integer, the value is between 10 and 1000--></zoomdoorlimit>
</PrivacyMaskRegion>

16.2.198 XML_Link
Link message in XML format
<Link version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <MACAddress><!--req, xs:string--></MACAddress>
 <autoNegotiation><!--req, xs:boolean--></autoNegotiation>
 <speed><!--req, xs:integer, "10, 100, 1000"--></speed>
 <duplex><!--req, xs:string, "half, full"--></duplex>
 <MTU><!--req, xs:integer--></MTU>
</Link>

16.2.199 XML_localPermission
localPermission message in XML format
<localPermission version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <backup><!—opt, xs:boolean—></backup>
 <record><!—opt, xs:boolean—></record>
 <playBack><!—opt, xs:boolean—></playBack>
 <preview><!—opt, xs:boolean—></preview>
 <videoChannelPermissionList><!—opt—>
  <videoChannelPermission><!—opt—>
   <id><!—req, corresponds to the video input channel ID—></id>
   <playBack><!—opt, xs:boolean—></playBack>
   <preview><!—opt, xs:boolean—></preview>
   <record><!—opt, xs:boolean—></record>
   <backup><!—opt, xs:boolean—></backup>

   <playBackDoubleVerification>
    <!—opt, xs:boolean, whether supports secondary authentication for playback—>
   </playBackDoubleVerification>
   <backupDoubleVerification>
    <!—opt, xs:boolean, whether supports secondary authentication for backup—>
   </backupDoubleVerification>
  </videoChannelPermission>
 </videoChannelPermissionList>
 <ptzControl>
  <!—req, xs:boolean—>
 </ptzControl>
 <ptzChannelPermissionList><!—opt—>
  <ptzChannelPermission><!—req—>
   <id><!—req, corresponds to PTZ channel ID—></id>
   <ptzControl><!—opt, xs: boolean—></ptzControl>
  </ptzChannelPermission>
 </ptzChannelPermissionList>
 <logOrStateCheck><!—opt, xs: boolean—></logOrStateCheck>
 <parameterConfig><!—opt, xs: boolean—></parameterConfig>
 <restartOrShutdown><!—opt, xs: boolean—></restartOrShutdown>
 <upgrade><!—opt, xs: boolean—></upgrade>
</localPermission>

16.2.200 XML_LockPTZ
LockPTZ message in XML format
<LockPTZ version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <lockTime>
  <!--req, xs:integer, PTZ is unlocked when this node is set to 0, unit: second-->
 </lockTime>
</LockPTZ>

16.2.201 XML_LogConfig
LogConfig message in XML format.
<LogConfig version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--required, boolean type, whether to enable log--></enabled>
 <level>
  <!--required, string type, log types: "none,debug,info,error,fault,all", multiple type can be selected, and each type
should be separated by comma-->
 </level>
</LogConfig>

16.2.202 XML_LogServer
LogServer message in XML format
<LogServer version="2.0" xmlns="http://www.std-cgi.org/ver20/XMLSchema">
 <enabled><!--req, xs: boolean, opt="true,false"--></enabled>
 <addressingFormatType>
  <!--req, xs: string, "ipaddress,hostname"-->
 </addressingFormatType>
 <hostName><!--dep, xs: string--></hostName>
 <ipAddress><!--dep, xs: string--></ipAddress>
 <ipv6Address><!--dep, xs: string--></ipv6Address>
 <portNo><!--opt, xs: integer--></portNo>
 <transmissionEncryption>
  <!--opt, xs:boolean, whether to enable transmission encryption: "true"-yes, "false"-no (default). If this field is not
supported, the default encryption method is TLS-->
 </transmissionEncryption>
</LogServer>

16.2.203 XML_LogServerCap
LogServerCap message in XML format
<LogServerCap version="2.0" xmlns="http://www.std-cgi.org/ver20/XMLSchema">
 <enabled opt="true,false"></enabled>
 <addressingFormatType opt="ipaddress,hostname">
  <!--req,xs:string,"ipaddress,hostname"-->
 </addressingFormatType>
 <hostName min="" max="">
  <!--dep, xs:string-->
 </hostName>
 <ipAddress min="" max=""><!--dep, xs:string--></ipAddress>
 <ipv6Address min="" max=""><!--dep, xs:string--></ipv6Address>
 <portNo min="" max=""><!--opt, xs:integer--></portNo>
 <transmissionEncryption opt="true,false">
  <!--opt, xs:boolean, whether to enable transmission encryption: "true"-yes, "false"-no (default). If this field is not
supported, the default encryption method is TLS-->
 </transmissionEncryption>
</LogServerCap>

16.2.204 XML_LogServerTestDescription
LogServerTestDescription message in XML format
<LogServerTestDescription>
 <addressingFormatType>
  <!--req, xs:string, "ipaddress,hostname"-->
 </addressingFormatType>

 <hostName><!--dep, xs:string--></hostName>
 <ipAddress><!--dep, xs:string--></ipAddress>
 <ipv6Address><!--dep, xs:string--></ipv6Address>
 <portNo><!--opt, xs:integer--></portNo>
 <transmissionEncryption><!--opt, xs:boolean, whether to enable transmission encryption, and it is disabled by
default. If this field is not supported, the default encryption method used by the device is TLS--></
transmissionEncryption>
</LogServerTestDescription>

16.2.205 XML_MACFilter
MACFilter message in XML format
<MACFilter version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs:boolean--></enabled>
 <permissionType><!--req, xs:string,"deny, allow"--></permissionType>
 <MACFilterAddressList>
  <MACFilterAddress>
   <id><!--req, xs:string, id--></id>
   <MACAddress><!--req, xs:string--></MACAddress>
  </MACFilterAddress>
 </MACFilterAddressList>
</MACFilter>

16.2.206 XML_mailing
mailing message in XML format.
<mailing version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string--></id>
 <enabled><!--opt, xs:boolean--></enabled>
 <sender><!--req-->
  <name><!--req, xs:string--></name>
  <emailAddress><!--req, xs:string--></emailAddress>
  <smtp><!--req-->
   <enableAuthorization><!--req, xs:boolean--></enableAuthorization>
   <enableSSL><!--opt, xs:boolean--></enableSSL>
   <addressingFormatType>
    <!--req, xs:string,"ipaddress,hostname"-->
   </addressingFormatType>
   <hostName><!--dep, xs:string--></hostName>
   <ipAddress><!--dep, xs:string--></ipAddress>
   <ipv6Address><!--dep, xs:string--></ipv6Address>
   <portNo><!--opt, xs:integer--></portNo>
   <accountName><!--dep, xs:string--></accountName>
   <password><!--dep, xs:string--></password>
   <enableTLS><!--opt, xs:boolean--></enableTLS>
   <startTLS><!--dep, xs:boolean--></startTLS>
  </smtp>

 </sender>
 <receiverList><!--req-->
  <receiver><!--req-->
   <id><!--req, xs:string--></id>
   <name><!--req, xs:string--></name>
   <emailAddress><!--req,xs:string--></emailAddress>
  </receiver>
 </receiverList>
 <attachment><!--opt-->
  <snapshot><!--opt-->
   <enabled><!--req, xs:boolean--></enabled>
   <interval><!--req, xs:integer, unit: second--></interval>
  </snapshot>
 </attachment>
</mailing>

16.2.207 XML_mailingList
mailingList message in XML format
<mailingList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <mailing><!--opt,xs:string--></mailing>
</mailingList>

16.2.208 XML_mailingTestResult
mailingTestResult message in XML format
<mailingTestResult version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <errorDescription><!--req, xs:string--></errorDescription>
</mailingTestResult>

16.2.209 XML_mailingTestDescription
mailingTestDescription message in XML format.
<mailingTestDescription version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <sendName><!--opt, xs:string--></sendName>
 <sendEmailAddress><!--req, xs:string--></sendEmailAddress>
 <addressingFormatType>
  <!--req, xs:string,"ipaddress,hostname"-->
 </addressingFormatType>
 <hostName><!--dep, xs:string--></hostName>
 <ipAddress><!--dep, xs:string--></ipAddress>
 <ipv6Address><!--dep, xs:string--></ipv6Address>
 <portNo><!--req, xs:integer--></portNo>
 <enableSSL><!--opt, xs:boolean--></enableSSL>

 <enableAuthorization><!--req, xs:boolean--></enableAuthorization>
 <accountName><!--dep, xs:string--></accountName>
 <password><!--dep, xs:string--></password>
 <receiverList><!--req-->
  <receiver><!--req-->
   <id><!--req, xs:string--></id>
   <name><!--req, xs:string--></name>
   <emailAddress><!--req, xs:string--></emailAddress>
  </receiver>
 </receiverList>
</mailingTestDescription>

16.2.210 XML_MaxElevation
MaxElevation message in XML format
<MaxElevation version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <mElevation><!--req, xs:integer, the lower limit of max. tilt-angle--></mElevation>
</MaxElevation>

16.2.211 XML_MountList
MountList message in XML format
<MountList version="1.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <Mount>
  <id><!--req, xs: integer, storage node ID--></id>
  <path><!--req, xs: string, saving path--></path>
  <dir><!--req, xs: string--></dir>
  <size><!--req, xs: string,, storage size--></size>
  <descr><!--req, xs: string, storage description--></descr>
 </Mount>
</MountList>

16.2.212 XML_NetworkCap
NetworkCap capability message in XML format
<NetworkCap version="2.0" xmlns=“http://www.isapi.org/ver20/XMLSchema">
 <isSupportWireless>
  <!--req, xs:boolean, whether to support accessing via wireless network, "true"-yes, "false"-no-->
 <isSupportWireless>
 <isSupportPPPoE>
  <!--req, xs:boolean, whether to support PPPoE, "true"-yes, "false"-no-->
 <isSupportPPPoE>
 <isSupportBond>
  <!--req, xs:boolean, whether to support NIC bonding, "true"-yes, "false"-no-->

<isSupportBond>
<isSupport802_1x>
 <!--req, xs:boolean, whether to support 802_1x-->
</isSupport802_1x>
<isSupportNtp>
 <!--opt, xs:boolean, whether to support NTP-->
</ isSupportNtp>
<isSupportFtp>
 <!--opt, xs:boolean, whether to support FTP-->
</isSupportFtp>
<isSupportUpnp>
 <!--opt, xs:boolean, whether to support UPnP-->
</isSupportUpnp>
<isSupportPNP>
 <!--opt, xs:boolean, whether to support PnP-->
</isSupportPNP>
<isSupportDdns>
 <!--opt, xs:boolean, whether to support DNS-->
</isSupportDdns>
<isSupportHttps>
 <!--opt, xs:boolean, whether to support HTTPS-->
</isSupportHttps>
<SnmpCap><!--opt, whether to support SNMP-->
<isSupport><!--req, xs:boolean--></isSupport>
</SnmpCap>
<isSupportExtNetCfg>
 <!--opt, xs:boolean, whether to support configuring extended network parameters-->
</isSupportExtNetCfg>
<isSupportIPFilter>
 <!--opt, xs:boolean, whether to support filtering IP address-->
</isSupportIPFilter>
<isSupportSSH opt="true"><!--opt, xs:boolean, whether to support SSH--></isSupportSSH>
<isSupportEZVIZ>
 <!--opt, xs:boolean, whether to support Hik-Connect-->
</isSupportEZVIZ>
<isSupportEhome>
 <!--opt, xs:boolean, whether to support EHome-->
</isSupportEhome>
<isSupportWirelessServer>
 <!--opt, xs:boolean, whether to support Wi-Fi hotspot-->
</isSupportWirelessServer>
<isSupportWirelessDial>
 <!--opt, xs:boolean, whether to support wireless dial configuration-->
</isSupportWirelessDial>
<WPS><!--opt, Wi-Fi Protected Setup configuration-->
 <NetworkInterfaceList size="2">
  <NetworkInterface>
    <id><!--req, xs:string, NIC ID--></id>
    <enabled><!--req, xs:boolean, whether the NIC is enabled--></enabled>
    <isSupportAutoConnect><!--opt, xs:boolean--></isSupportAutoConnect>
    <isSupportDevicePinCode>
     <!--opt, xs:boolean, whether to support device PIN code-->

      </isSupportDevicePinCode>
      <isSupportDevicePinCodeUpdate>
       <!--opt, xs:boolean, whether to support updating device PIN code-->
      </isSupportDevicePinCodeUpdate>
      <ApPinCode><!--opt-->
       <ssid min="" max="">
        <!--opt, xs:string, maximum and minimum SSID length that can be returned by device-->
       </ssid>
       <pinCode min="" max="">
        <!--opt, xs:string, maximum and minimum PIN code length that can be returned by device-->
       </pinCode>
      </ApPinCode>
    </NetworkInterface>
   </NetworkInterfaceList>
  </WPS>
  <isSupportMACFilter>
   <!--opt, xs:boolean, whether to support filtering MAC address-->
  </isSupportMACFilter>
  <verificationCode max="">
   <!--opt, xs:string, the maximum length of verificationCode that can be returned by device-->
  </verificationCode>
  <WPSCap><!--opt-->
   <isSupport><!--req, xs: boolean--></isSupport>
   <isSupportAutoConnect><!--req, xs: boolean--></isSupportAutoConnect>
  </WPSCap>
  <NetWorkMode>
   <workMode><!--opt, xs:string, network mode: "close,wifi,wifiAp"--></workMode>
  </NetWorkMode>
  <VerificationCodeModification><!--opt, xs:string, whether the verification code can be edited by the admin user-->
   <verificationCodeType opt="normal,empty"></verificationCodeType>
   <isSupportDeclarationURL><!--opt, xs:boolean, whether to support URL declared by the service--></
isSupportDeclarationURL>
   <isSupportPrivacyPolicyURL><!--opt, xs:boolean, whether to support the privacy policy URL--></
isSupportPrivacyPolicyURL>
   <verificationCodeModify opt="true,false">
    <!--opt, whether the verification code is edited: "true"-yes, "false"-no, no return-not support-->
   </verificationCodeModify>
   <Hyperlinks><!--opt-->
    <declarationURL><!--opt,xs:string--></declarationURL>
    <privacyPolicyURL><!--opt,xs:string--></privacyPolicyURL>
   </Hyperlinks>
   <isSupportVerificationCodeCheck>
    <!--opt, xs: boolean, whether to support verifying and configuring the verification code, true-yes, if this node is not
returned or the value of the returned node is false, it indicates that not support-->
   </isSupportVerificationCodeCheck>
   <isSupportOldVerificationCode><!--opt, xs:boolean, whether to support old EZVIZ password configuration. The old
password contains six uppercase letters--></isSupportOldVerificationCode>
  </VerificationCodeModification>
  <EZVIZSecretKey>
   <!--opt, whether to support capability of editing verification code for Hik-Connect-->
   <offlineStatus>
    <!--ro,dep,xs:string; it is valid when registerStatus values "false", device offline status, opt="secretKeyInvalid"-

invalid verification code-->
   </offlineStatus>
   <secretKey min="0" max="64"><!--opt, xs:string, verification code for Hik-Connect--></secretKey>
  </EZVIZSecretKey>
  <isSupportplatformAccess><!--opt, xs:boolean, capability of accessing the platform, whether to support filtering IP
addresses that access to the platform--></isSupportplatformAccess>
  <isSupportIntegrate><!--opt, xs:boolean--></isSupportIntegrate>
  <isSupportIntelligentBoost><!--opt, xs:boolean, whether to support bandwidth adaption--></
isSupportIntelligentBoost>
  <isSupportWebSocket><!--opt, xs:boolean--></isSupportWebSocket>
  <isSupportWebSocketS><!--opt, xs:boolean--></isSupportWebSocketS>
  <isSupportResourceStatistics><!--opt, xs:boolean, whether supports network resource information--></
isSupportResourceStatistics>
  <isSupportBandwidthLimit><!--opt, xs:boolean--></isSupportBandwidthLimit>
  <isSupportPOEPortsDisableServer><!--opt, xs:boolean--></isSupportPOEPortsDisableServer>
  <isSupportPOEConfiguration><!--opt, xs:boolean--></isSupportPOEConfiguration>
  <Adaption>
   <streamType opt="0,1,2,3,4,5,7,8,9,10">
    <!--stream types that support network self-adaptive during live view: 0-main stream, 1-sub-stream, 2-third stream,
3-virtual stream, 4-stream 5, 5-stream 6, 7-stream 7, 8-stream 8, …, and so on-->
   </streamType>
   <isSupportPlayback><!--opt, xs: boolean, whether to support self-adaptive during playback--></isSupportPlayback>
  </Adaption>
  <isSupportWifiProbe><!--opt, xs:boolean, whether to support Wi-Fi probe configuration--></isSupportWifiProbe>
  <isSupportRFIDData><!--opt, xs:boolean, whether to support configuration of RFID data collection--></
isSupportRFIDData>
  <isSupportwifiProbeSSID><!--opt, xs:boolean, whether to support SSID configuration of Wi-Fi probe--></
isSupportwifiProbeSSID>
  <isSupportPOEPortsDisableAdaptiveServer><!--opt, xs:boolean--></isSupportPOEPortsDisableAdaptiveServer>
</NetworkCap>

16.2.213 XML_NetworkInterface
NetworkInterface message in XML format
<NetworkInterface version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string--></id>
 <IPAddress/><!--req-->
 <Wireless/><!--opt-->
 <Discovery/><!--opt-->
 <Link/><!--opt-->
 <defaultConnection><!--opt, xs:boolean, default network connection, this node is required when the device has
multiple network interfaces--></defaultConnection>
 <ActiveMulticast>
  <enabled><!--req, xs:boolean--></enabled>
  <streamID opt="main"><!--req, xs:string--></streamID>
  <ipV4Address><!--opt, xs:string--></ipV4Address>
  <ipV6Address><!--opt, xs:string--></ipV6Address>
  <port min="" max=""><!--opt, xs:integer--></port>
 </ActiveMulticast>
 <macAddress min="" max=""><!--opt, xs:string--></macAddress>

 <EthernetPortList size="4"><!--opt, network interface information-->
  <EthernetPort><!--opt-->
   <id><!--req, xs: integer, min="1",max="4"--></id>
   <MACAddress><!--req, xs:string--></MACAddress>
   <status><!--opt, xs:string; opt="connected, disconnect"--></status>
   <speed><!--req, xs:integer, "10, 100, 1000,10000"--></speed>
  </EthernetPort>
 </EthernetPortList>
</NetworkInterface>

16.2.214 XML_NetworkInterfaceList
NetworkInterfaceList message in XML format
<NetworkInterfaceList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <NetworkInterface/><!--opt, see details in the message of XML_NetworkInterface-->
</NetworkInterfaceList>

See Also
XML_NetworkInterface

16.2.215 XML_NetWorkMode
NetWorkMode message in XML format
<NetWorkMode version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <workMode><!--opt, xs:string, working mode: "close", "wifi"-Wi-Fi configuration, "wifiAp"-Wi-Fi access point (Wi-Fi
server) configuration--></workMode>
</NetWorkModeParam>

16.2.216 XML_NoiseReduce
NoiseReduce message in XML format
<NoiseReduce version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <mode><!--req, xs: string, 3D DNR mode: "close, general, advanced"--></mode>
 <GeneralMode><!--dep, this node is valid only when <mode> is "general"-->
  <generalLevel><!--req, xs: integer--></generalLevel>
 </GeneralMode>
 <AdvancedMode><!--dep, this node is valid only when <mode> is "advanced"-->
  <FrameNoiseReduceLevel><!--req, xs: integer--></FrameNoiseReduceLevel>
  <InterFrameNoiseReduceLevel><!--req, xs: integer--></InterFrameNoiseReduceLevel>
 </AdvancedMode>
</NoiseReduce>

16.2.217 XML_NTPServer
NTPServer message in XML format
<NTPServer version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string, NTP server ID--></id>
 <addressingFormatType>
  <!--req, xs:string, which field will be used to locate the NTP server: "ipaddress, hostname"-->
 </addressingFormatType>
 <hostName><!--dep, xs:string--></hostName>
 <ipAddress><!--dep, xs:string--></ipAddress>
 <ipv6Address><!--dep, xs:string--></ipv6Address>
 <portNo><!--opt, xs:integer--></portNo>
 <synchronizeInterval>
  <!--opt, xs:integer, NTP time synchronization interval, unit: minute-->
 </synchronizeInterval>
</NTPServer>

16.2.218 XML_NTPServerList
NTPServerList message in XML format
<NTPServerList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <NTPServer/><!--opt, see details in the message of XML_NTPServer-->
</NTPServerList>

See Also
XML_NTPServer

16.2.219 XML_NTPTestDescription
NTPTestDescription message in XML format
<NTPTestDescription version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <addressingFormatType>
  <!--req, xs:string, "ipaddress,hostname"-->
 </addressingFormatType>
 <hostName><!--dep, xs:string--></hostName>
 <ipAddress><!--dep, xs:string--></ipAddress>
 <ipv6Address><!--dep, xs:string--></ipv6Address>
 <portNo><!--req, xs:integer--></portNo>
</NTPTestDescription>

16.2.220 XML_NTPTestResult
NTPTestResult message in XML format
<NTPTestResult version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <errorDescription><!--req, xs:string--></errorDescription>
</NTPTestResult>

16.2.221 XML_OnlineUpgradeCap
OnlineUpgradeCap message in XML format
<OnlineUpgradeCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  <firmwareNum max="" />
   <!--req, the number of online upgrade packages, including full package and incremental package. Full package is
used for upgrading whole firmware, while incremental package is used for upgrade certain unit, such as openssl
library-->
  <firmwareCode max="" />
   <!--req, the maximum length of firmware code-->
  <firmwareVersion max="" />
   <!--req, the maximum length of version-->
  <firmwareCodeNumOnce max="" />
   <!--req, the maximum number of firmware codes can be obtained each time-->
  <upgradePercent min="" max="" />
   <!--req-->
  <Version>
   <!--req, upgrade package version information-->
   <newVersion max="" />
     <!--req-->
   <changeLog max="" />
     <!--req-->
  </Version>
  <DeviceParameter>
   <!--opt, online upgrade parameters-->
   <isSupportAutoDownloadPackage>
     <!--opt,xs:boolean,"true,false", whether supports automatic download of upgrade package-->
   </isSupportAutoDownloadPackage>
   <notSupportAutoUpgrade>
     <!--opt,xs:boolean,"true,false", whether not support automatic download of upgrade package and automatic
upgrade-->
   </notSupportAutoUpgrade>
   <isSupportTimingUpgrade>
     <!--opt,xs:boolean,"true,false", whether supports scheduled upgrade-->
   </isSupportTimingUpgrade>
  </DeviceParameter>
  <ManualDownloadPackage>
   <!--opt, manually download upgrade package-->
   <supportOperation opt="start,cancel,pause,resume" />
     <!--opt, supported operations: "start,cancel,pause,resume"-->

 </ManualDownloadPackage>
 <isSupportIgnoreCurrentVersion>
  <!--opt, xs:boolean, "true,false", whether supports ignoring current version-->
 </isSupportIgnoreCurrentVersion>
</OnlineUpgradeCap>

16.2.222 XML_OnlineUpgradeStatus
OnlineUpgradeStatus message in XML format
<OnlineUpgradeStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <status>
  <!--ro, req, xs:string,
"notUpgrade,upgrading,successful,languageMismatch,writeFlashError,packageTypeMismatch,packageVersionMismatc
h,netUnreachable,unknownError"-->
 </status>
 <percent><!-- ro, req, xs:integer “0-100” --></percent>
</OnlineUpgradeStatus>

16.2.223 XML_OnlineUpgradeVersion
OnlineUpgradeVersion message in XML format
<OnlineUpgradeVersion version="2.0" xmlns=“http://www.isapi.org/ver20/XMLSchema”>
 <newVersionAvailable><!--ro,req,xs:boolean, whether there is new verion of upgrade package--></
newVersionAvailable>
 <newVersion><!--ro, dep,xs:string, new version No.--></newVersion>
 <changeLog><!--ro, dep,xs:string, update content of new version--></changeLog>
</OnlineUpgradeVersion>

16.2.224 XML_OnlineUpgradeServer
OnlineUpgradeServer message in XML format
<OnlineUpgradeServer version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <connectStatus><!--ro, req xs:boolean, online upgrade server connection status--></connectStatus>
</OnlineUpgradeServer>

16.2.225 XML_Palettes
Palettes message in XML format
<Palettes version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <mode><!--opt, xs:string,
"WhiteHot,BlackHot,Fusion1,Rainbow,Fusion2,Ironbow1,Ironbow2,Sepia,Color1,Color2,IceFire,Rain,RedHot,GreenHot,
DeepBlue,Color3"--></mode>

 <ColorateTarget><!--dep, colorate target, it is valid when mode is "WhiteHot"-->
  <ColorateTargetModeList>
   <ColorateTargetMode>
    <id><!--req, xs:integer, serial number, starts from 1--></id>
    <mode>
     <!--req, xs:string, colorate target mode; colorateHotAreae-colorate area with temperature high than configured
threshold, colorateIntervalArea-colorate area with temperature between the configured threshold, colorateColdArea-
colorate area with temperature lower than the configured threshold-->
    </mode>
    <enabled><!--req, xs:bool, "true,false"--></enabled>
    <TemperatureLimit><!--req, temperature limit-->
     <minTemperature><!--dep, it is valid when mode is "colorateHotAreae"/"colorateIntervalArea", xs: float--></
minTemperature>
     <maxTemperature><!--dep, it is valid when mode is "colorateColdArea"/"colorateIntervalArea", xs: float--></
maxTemperature>
    </TemperatureLimit>
    <Color><!--req, area color-->
     <R><!--req, xs:integer--></R>
     <G><!--req, xs:integer--></G>
     <B><!--req, xs:integer--></B>
    </Color>
   </ColorateTargetMode>
  </ColorateTargetModeList>
 </ColorateTarget>
</Palettes>

16.2.226 XML_ParkAction
ParkAction message in XML format
<ParkAction version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs: boolean--></enabled>
 <Parktime min="" max=""><!--req, xs: integer, seconds--></Parktime>
 <Action>
  <ActionType opt="autoscan,framescan,randomscan,panoramascan,patrol,pattern,preset">
   <!--req, xs: string-->
  </ActionType>
  <ActionNum min="" max=""><!--req, xs: integer, from 0 to 255--></ActionNum>
 </Action>
</ParkAction>

16.2.227 XML_ParkingParam
ParkingParam message in XML format
<ParkingParam><!--dep-->
 <durationTime>
  <!—req, xs:integer, duration time, from 5 seconds to 100 seconds, default value: 5s-->

 </durationTime>
</ParkingParam>

16.2.228 XML_Probe
Probe message in XML format.
<?xml version="1.0" encoding="UTF-8"?>
<Probe>
 <!--the UUID will be returned in the device response message for matching, if not matched, it will not be handled.-->
 <Uuid>8d2091bc-1dd2-11b2-807b-8ce748cf9334</Uuid>
 <Types>inquiry</Types>
</Probe>

16.2.229 XML_port
port message in XML format
<port version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id/><!--req, xs: string, ID-->
 <enabled/><!—req, xs: boolean-->
 <internalPort/><!--req, xs: string, "http,admin,rtsp,https,WebSocket,WebSocket,SDK_OVER_TLS,SRTP..."-->
 <externalPort/><!—req, xs:integer-->
</port>

16.2.230 XML_portStatus
portStatus message in XML format
<portStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id/><!--req, xs: string, ID-->
 <enabled/><!--req-->
 <internalPort/><!--req, xs: string, "http,admin,rtsp,https,WebSocket,WebSocket,SDK_OVER_TLS,SRTP..."-->
 <externalPort/><!--req, xs: integer-->
 <status/><!--req, xs: string, "inactive, active, conflict, ..."-->
</portStatus>

16.2.231 XML_ports
ports message in XML format
<ports version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled/><!--req-->
 <mapmode><!--req, xs: string, "auto,manual"--></mapmode>
 <natRouterLanAddr><!--opt-->
  <ipVersion><!--req, xs: string, "v4,v6,dual"--></ipVersion>

  <ipAddress><!--dep, xs: string--></ipAddress>
  <ipv6Address><!--dep, xs: string--></ipv6Address>
 </natRouterLanAddr>
 <portList><!--req-->
  <port/><!--see details in the message XML_port-->
 </portList>
 <natType><!--req, xs: string, "manual, auto"--></natType>
</ports>

See Also
XML_port

16.2.232 XML_PortMapParam
PortMapParam message in XML format
<PortMapParam version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <userip><!--IP address of user terminal, or IP address of PoE0 or Eth0--></userip>
</PortMapParam>

16.2.233 XML_PortMapParamRet
PortMapParamRet message in XML format
<PortMapParamRet version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <mapResult><!--whether port mapping is required: 0-no, 1-yes, 2-unknown--></mapResult>
 <MapPortGop>
  <MapPort>
   <mapPortIdx><!--index No. of mapping ports--></mapPortIdx>
   <mapPortName><!--mapping port name--></mapPortName>
   <mapPortValue><!--mapping port number--></mapPortValue>
  <MapPort>
 </MapPortGop>
</PortMapParamRet>

16.2.234 XML_portsStatus
portsStatus message in XML format.
<portsStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled/><!--req-->
 <natRouterLanAddr><!--req-->
  <ipVersion><!--req, xs: string, "v4,v6,dual"--></ipVersion>
  <ipAddress><!--dep, xs: string--></ipAddress>
  <ipv6Address><!--dep, xs: string--></ipv6Address>
 </natRouterLanAddr>
 <natRouterWanAddr><!--req-->

  <ipVersion><!--req, xs: string, "v4,v6,dual"--></ipVersion>
  <ipAddress><!--dep, xs: string--></ipAddress>
  <ipv6Address><!--dep, xs: string--></ipv6Address>
 </natRouterWanAddr>
 <portStatusList><!--req-->
  <portStatus/><!--req, see details in the message XML_portStatus-->
 </portStatusList>
</portsStatus>

See Also
XML_portStatus

16.2.235 XML_powerLineFrequency
powerLineFrequency message in XML format
<powerLineFrequency version="2.0" mlns="http://www.isapi.org/ver20/XMLSchema">
 <powerLineFrequencyMode/><!--opt, xs: string, standard mode: "50hz, 60hz"-->
</powerLineFrequency>

16.2.236 XML_PreviewSwitch
PreviewSwitch message in XML format
<PreviewSwitch version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <DisplayWindowList size="64">
 <!--req, if the number of channels is larger or equal to 64, 64 channels should be applied by a group for one time;
otherwise, apply the maximum number of channels-->
  <DisplayWindow>
   <id><!--req, xs: string, actual window No., which equals to id × groupNo--></id>
   <displayChannelNo><!--req, xs: string, 0-not display, 1 to 64-displayed channel No., min="0" max="64"--></
displayChannelNo>
  </DisplayWindow>
 </DisplayWindowList>
 <previewFrameNo>
  <!--req, xs: string, number of live view windows: 1, 4, 6, 8, 9, 25, 32, 36, auto1-custom window division 1, auto2-
custome window division 2, auto3-custome window division 3, auto4-custome window division 4-->
 </previewFrameNo>
 <sound><!--req, xs: boolean, whether to turn on audio during live view: true-yes, false-no--></sound>
 <switchTime><!--req, xs: string, switching interval: 0, 5, 10, 20, 30, 60, 120, and 300, unit:s--></switchTime>
 <sameSource>
  <!--dep, xs: boolean, whether the output is homologous: true-yes, false-no, this node is valid only when
VideoOutType is "noSameSourceVGA1", "noSameSourceVGA2", "noSameSourceVGA3", and "noSameSourceVGA4"-->
 </sameSource>
</PreviewSwitch>

16.2.237 XML_PreviewSwitchVideoOutCap
PreviewSwitchVideoOutCap message in XML format
<PreviewSwitchVideoOutCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <DisplayWindowList size="64">
   <DisplayWindow>
    <id><!--req, xs: string, window No., which equals to id × groupNo--></id>
    <displayChannelNo min="0" max="64"><!--req, xs: string, 0-not display, 1 to 64-displayed channel No.--></
displayChannelNo>
   </DisplayWindow>
 </DisplayWindowList>
 <previewFrameNo opt="1,4,6,8,9,25,32,36,auto1,auto2,auto3,auto4">
   <!--req, xs: string, number of live view windows, auto1-custom window division 1, auto2-custome window division
2, auto3-custome window division 3, auto4-custome window division 4-->
 </previewFrameNo>
 <sound><!--req, xs: boolean, whether to turn on audio during live view: true-yes, false-no--></sound>
 <switchTime opt="0,5,10,20,30,60,120,300"><!--req, xs: string, switching interval, unit: s--></switchTime>
 <sameSource>
   <!--dep, xs: boolean, whether the output is homologous: true-yes, false-no, this node is valid only when
VideoOutType is "noSameSourceVGA1", "noSameSourceVGA2", "noSameSourceVGA3", and "noSameSourceVGA4"-->
 </sameSource>
 <supportGetByPreviewNum>
   <!--opt, whether supports setting number of live view windows in the URL, true-yes-->
 </supportGetByPreviewNum>
</PreviewSwitchVideoOutCap>

16.2.238 XML_PrivacyMask
PrivacyMask message in XML format
<PrivacyMask version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs: boolean--></enabled>
 <normalizedScreenSize><!--opt-->
  <normalizedScreenWidth><!--req, xs: integer--></normalizedScreenWidth>
  <normalizedScreenHeight><!--req, xs: integer--></normalizedScreenHeight>
 </normalizedScreenSize>
 <PrivacyMaskRegionList size=8/><!--opt-->
 <regionType><!--opt, xs: string, "quadrilateral"--></regionType>
</PrivacyMask>

16.2.239 XML_PrivacyMaskCap
PrivacyMaskCap message in XML format
<PrivacyMaskCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <maskTypeDscriptor>
  <!--opt, xs: string, privacy mask type: "gray,red,yellow,blue,orange,green,transparent,half-transparent,mosaic"-->

 </maskTypeDscriptor>
 <minZoomdoorlimit><!--opt, xs: integer></minZoomdoorlimit>
 <maxZoomdoorlimit><!--opt, xs: integer></maxZoomdoorlimit>
 <videoPrivacyType opt="privacyMask,privacyCover">
  <!--opt, xs: string, "privacyMask"-video tampering, "privacyCover"-privacy mask-->
 </videoPrivacyType>
</PrivacyMaskCap>

16.2.240 XML_PrivacyMaskRegion
PrivacyMaskRegion message in XML format
<PrivacyMaskRegion version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs: integer--></id>
 <enabled><!--req, xs: boolean--></enabled>
 <RegionCoordinatesList><!--req-->
  <RegionCoordinates><!--req-->
   <positionX><!--req, xs: integer; coordinate--></positionX>
   <positionY><!--req, xs: integer; coordinate--></positionY>
  </RegionCoordinates>
 </RegionCoordinatesList>
 <privacymaskName><!--opt, xs: string--></privacymaskName>
 <maskType>
  <!--opt, xs:string "gray,red,yellow,blue,orange,green,transparent,half-transparent,mosaic,black"-->
 </maskType>
 <zoomdoorlimit><!--opt, xs: integer, the value is between 10 and 1000--></zoomdoorlimit>
</PrivacyMaskRegion>

16.2.241 XML_PrivacyMaskRegionList
PrivacyMaskRegionList message in XML format
<PrivacyMaskRegionList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <PrivacyMaskRegion/><!--opt, refer to the message XML_PrivacyMaskRegion for details-->
</PrivacyMaskRegionList>

See Also
XML_PrivacyMaskRegion

16.2.242 XML_PTZAux
PTZAux message in XML format
<?xml version="1.0" encoding="utf-8"?>
<PTZAux version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req,xs:string,id--></id>
 <type><!--req, ro, xs:string,"LIGHT,WIPER,FAN,HEATER",auxiliary type: light, wiper, fan, heater--></type>

 <status><!--req, xs:string,"on,off", auxiliary status: turned on, turned off--></status>
</PTZAux>

16.2.243 XML_PTZAuxList
PTZAuxList message in XML format
<?xml version="1.0" encoding="utf-8"?>
<PTZAuxList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <PTZAux><!--list-->
  <id><!--req,xs:string,id--></id>
  <type><!--req, ro, xs:string,"LIGHT,WIPER,FAN,HEATER",auxiliary type: light, wiper, fan, heater--></type>
  <status><!--req, xs:string,"on,off", auxiliary status: turned on, turned off--></status>
 </PTZAux>
</PTZAuxList>

16.2.244 XML_PTZChannel
PTZChannel message in XML format
<PTZChanel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:integer--></id>
 <enabled><!--ro, req, xs:boolean--></enabled>
 <serialNumber><!--req,xs:integer--></serialNumber>
 <videoInputID><!--req, xs:integer--></videoInputID>
 <panMaxSpeed><!--ro, opt, xs:integer, degrees/sec--></panMaxSpeed>
 <tiltMaxSpeed><!--ro, opt, xs:integer, degrees/sec--></tiltMaxSpeed>
 <presetSpeed><!--opt, xs:integer, 1..8--></presetSpeed>
 <autoPatrolSpeed><!--opt, xs:integer, 0..100--></autoPatrolSpeed>
 <keyBoardControlSpeed><!--opt, xs:integer, 0..100--></keyBoardControlSpeed>
 <controlProtocol><!--opt, xs:string, "pelco-d,modbus-RTU,modbus-ASCII"--></controlProtocol>
 <controlAddress><!--opt-->
  <enabled><!--req, xs:boolean--></enabled>
  <Address><!--opt, xs:string, 1-255--></Address>
 </controlAddress>
 <defaultPresetID><!--opt, xs:string, id--></defaultPresetID>
 <PTZRs485Para><!--opt-->
  <baudRate><!--req, xs:integer--></baudRate>
  <dataBits><!--req, xs:integer--></dataBits>
  <parityType><!--req, xs:string, "none, even, odd, mark, space"--></parityType>
  <stopBits><!--req, xs:string, "1, 1.5, 2"--></stopBits>
  <flowCtrl><!--req, xs:string, "none, software, hardware"--></flowCtrl>
 </PTZRs485Para>
 <manualControlSpeed>
  <!--opt, xs:string, "pedestrian, nonMotorVehicle, motorVehicle, selfadaptive, compatible"-->
 </manualControlSpeed>
</PTZChannel>

16.2.245 XML_PTZChanelCap
PTZChanelCap capability message in XML format
<PTZChanelCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <AbsolutePanTiltPositionSpace><!--opt-->
  <XRange/><!--req-->
  <YRange/><!--req-->
 </AbsolutePanTiltPositionSpace>
 <AbsoluteZoomPositionSpace><!--opt-->
  <ZRange/><!--req-->
 </AbsoluteZoomPositionSpace>
 <RelativePanTiltSpace><!--opt-->
  <XRange/><!--req-->
  <YRange/><!--req-->
 </RelativePanTiltSpace>
 <RelativeZoomSpace><!--opt-->
  <ZRange/><!--req-->
 </RelativeZoomSpace>
 <ContinuousPanTiltSpace><!--opt-->
  <XRange/><!--req-->
  <YRange/><!--req-->
 </ContinuousPanTiltSpace>
 <ContinuousZoomSpace><!--opt-->
  <ZRange/><!--req-->
 </ContinuousZoomSpace>
 <MomentaryPanTiltSpace><!--opt-->
  <XRange/><!--req-->
  <YRange/><!--req-->
 </MomentaryPanTiltSpace>
 <MomentaryZoomSpace><!--opt-->
  <ZRange/><!--req-->
 </MomentaryZoomSpace>
 <homePostionSupport><!--req, xs:boolean--></homePostionSupport>
 <maxPresetNum>
  <!--req, xs:integer, max. supported preset number-->
 </maxPresetNum>
 <maxPatrolNum>
  <!--req,xs:integer, max. supported patrol number-->
 </maxPatrolNum>
 <maxPatternNum>
  <!--req,xs:integer, max. supported pattern number-->
 </maxPatternNum>
 <maxLimitesNum>
  <!--req,xs:integer, max. supported limit number-->
 </maxLimitesNum>
 <maxTimeTaskNum>
  <!--req,xs:integer, max. supported timing task number-->
 </maxTimeTaskNum>
 <serialNumber min="1" max="4">
  <!--configuration capability of RS-485 serial port supported by current channel-->

 </serialNumber>
 <controlProtocol>
  <!--opt, xs:string,"pelco-d,modbus-RTU,modbus-ASCII", supported PTZ control protocol-->
 </controlProtocol>
 <controlAddress>
  <!--opt, xs:string, 0-255, address-->
 </controlAddress>
 <PTZRs485Para>
  <!--opt, PTZ RS485 parameters capability-->
  <baudRate>
   <!--req, xs:integer, baud rate-->
  </baudRate>
  <dataBits>
   <!--req, xs:integer, data bit-->
  </dataBits>
  <parityType>
   <!--req, xs:string, "none,even,odd,mark,space", verification type-->
  </parityType>
  <stopBits>
   <!--req, xs:string, "1,1.5,2" , stop bit-->
  </stopBits>
  <flowCtrl>
   <!--req, xs:string, "none, software, hardware", stream control type-->
  </flowCtrl>
 </PTZRs485Para>
 <PresetNameCap>
  <!--opt, preset name capability-->
  <presetNameSupport>
   <!--opt,xs:boolean, whether to support preset name?-->
  </presetNameSupport>
  <maxPresetNameLen>
   <!--dep,xs:integer, preset name length-->
  </maxPresetNameLen>
  <specialNo/>
  <!--dep, special preset-->
 </PresetNameCap>
 <isSupportPosition3D>
  <!--opt, xs:boolean, whether to support 3D position-->
 </isSupportPosition3D>
 <isSupportManualTrack>
  <!--opt,xs:boolean, whether to support manual tracking position(NET_DVR_PTZ_MANUALTRACE)?-->
 </isSupportManualTrack>
 <manualControlSpeed opt="compatible,pedestrian,nonMotorVehicle,motorVehicle,selfadaptive">
  <!--opt,xs:string, manual control speed: "compatible"-compatible mode, "pedestrian"-pedestrian,
"nonMotorVehicle"-non-motor vehicle, "motorVehicle"-motor vehicle, "selfadaptive"-self adaptive-->
 </manualControlSpeed>
 <isSpportPtzlimiteds>
  <!--opt,xs:boolean, whether to support PTZ limitation-->
 </isSpportPtzlimiteds>
 <ParkAction/><!--see details in the message XML_ParkAction-->
 <TimeTaskList/><!--see details in the message XML_TimeTaskList-->
 <Thermometry>

   <maxThermometryPresetNum>
    <!--opt, xs:integer-->
   </maxThermometryPresetNum>
  </Thermometry>
  <isSpportPtzEagleFocusing>
   <!--opt, xs:boolean-->
  </isSpportPtzEagleFocusing>
  <TrackingRatio/>
   <!--opt, tracking zoom ratio-->
   <coefficient min="1" max="10" default="5">
    <!--opt, xs:integer, zoom ratio-->
   </coefficient>
  </TrackingRatio>
  <TrackInitPosition>
   <!--opt, tracking initial position-->
   <slaveCameraID>
    <!--opt, xs:integer, slave camera ID, 1..4 -->
   </slaveCameraID>
  </TrackInitPosition>
  <isSupportAbsoluteEx><!--opt,xs:boolean, whether to support extended capability for PTZ absolute position--></
isSupportAbsoluteEx>
  <isSupportCruise><!--opt,xs:boolean, whether to support auto-switch mode--></isSupportCruise>
  <isSupportAreaScan><!--opt,xs:boolean, whether to support area scan--></isSupportAreaScan>
  <isSupportFaceSnap3D><!--opt, xs: boolean--></isSupportFaceSnap3D>
  <isSupportOnepushSynchronizeFOV>
   <!--opt, xs:boolean, whether supports one-touch synchronize FOV, return true for supports, and no return indicates
not support-->
  </isSupportOnepushSynchronizeFOV>
  <isSupportLensCorrection>
   <!--opt, xs:boolean, whether supports lens correction, return true for supports, and no return indicates not support--
>
  </isSupportLensCorrection>
  <isSupportPTZTrackStatus>
   <!--opt, xs:boolean, whether to support getting PTZ tracking linkage status-->
  </isSupportPTZTrackStatus>
  <pqrsZoom min="" max=""/><!--opt, xs: integer, zooming coordinates of Sony zoom camera module-->
  <mnstFocus min="" max=""/><!--opt, xs: integer, focus coordinates of Sony zoom camera module-->
  <isSupportPTZSave>
   <!--opt, xs: boolean, whether supports saving the current PTZ position information-->
  </isSupportPTZSave>
  <isSupportPTZSaveGet>
   <!--opt, xs:boolean, whether to support saving the PTZ position information of the current channel by GET method--
>
  </isSupportPTZSaveGet>
  <isSupportAutoGotoCfg>
   <!--opt, xs: boolean, whether supports automatically restoring to saved PTZ position: "true"-yes, this node is not
returned-no-->
  <isSupportAutoGotoCfg>
  <lockTime><!--opt, xs:integer, PTZ locking time, unit: second--></lockTime>
</PTZChanelCap>

See Also
XML_ParkAction
XML_TimeTaskList

16.2.246 XML_PTZOSDDisplay
PTZOSDDisplay message in XML format
<PTZOSDDisplay version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <zoomlable><!--req, xs:string, "2sec, 5sec, 10sec, alwaysclose, alwaysopen"--></zoomlable>
 <azimuth><!--req, xs:string, "2sec, 5sec, 10sec, alwaysclose, alwaysopen"--></azimuth>
 <presetlable><!--req, xs:string, "2sec, 5sec, 10sec, alwaysclose, alwaysopen"--></presetlable>
 <actionStatusDisplayEnabled><!--opt, xs:boolean, display status or not--></actionStatusDisplayEnabled>
</PTZOSDDisplay>

16.2.247 XML_PTZStatus
PTZStatus message in XML format
<PTZStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <AbsoluteHigh><!--high-accuracy positioning which is accurate to one decimal place-->
   <elevation>
    <!--opt, xs:integer, tilting parameter, the value is between -900 and 2700, which corresponds to the range from
-90.0 degree to 270.0 degree vertically-->
   </elevation>
   <azimuth>
    <!--opt, xs:integer, panning parameter, the value is between 0 and 3600, which corresponds to the range from 0.0
degree to 360.0 degree horizontally-->
   </azimuth>
   <absoluteZoom>
    <!--opt, xs:integer, zooming parameter, the value is between 0 and 1000, which corresponds to the focus range
from 0.0 to 100.0-->
   </absoluteZoom>
 </AbsoluteHigh>
</PTZStatus>

16.2.248 XML_PublicKey
PublicKey message in XML format.
<PublicKey version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <key><!--req, xs:string--></key>
</PublicKey>

16.2.249 XML_RacmCap
RacmCap capability message in XML format
<RacmCap version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  <isSupportZeroChan>
   <!--opt, xs:boolean, whether supports channel-zero, "true"-yes, "false"-no-->
  </isSupportZeroChan>
  <inputProxyNums><!--opt, xs:integer, number of supported digital channels--></inputProxyNums>
  <eSATANums><!--opt, xs:integer, number of supported eSATAs--></eSATANums>
  <miniSASNums><!--opt, xs:integer, number of supported miniSATAs--></miniSASNums>
  <nasNums><!--opt, xs:integer, number of supported NASs--></nasNums>
  <ipSanNums><!--opt, xs:integer, number of supported IPSANs--></ipSanNums>
  <isSupportRaid>
   <!--opt, xs:boolean, whether supports RAID, "true"-yes, "false"-no-->
  </isSupportRaid>
  <isSupportExtHdCfg>
   <!--opt, xs:boolean, whether supports HDD advanced management, "true"-yes, "false"-no-->
  </isSupportExtHdCfg>
  <isSupportTransCode><!--opt, xs:boolean, whether supports auto-switch, "true"-yes, "false"-no--></
isSupportTransCode>
  <isSupportIpcImport>
   <!--opt, xs:boolean, whether supports importing configuration files to network camera, "true"-yes, "false"-no-->
  </isSupportIpcImport>
  <NasMountType><!--opt-->
   <isNFSSupportAuthentication/><!--opt, xs:boolean, whether supports NFS authentication, "true"-yes, "false"-no-->
   <isCIFSSupportAuthentication/><!--opt, xs:boolean, whether supports CIFS authentication, "true"-yes, "false"-no-->
  </NasMountType>
  <isSupportIpcStreamType/><!--opt, xs:boolean-->
  <isSupportIOInputProxy/><!--opt, xs:boolean, whether supports dynamic alarm input channel: "true"-yes, "false"-no--
>
  <isSupportIOOutputProxy/><!--opt, xs:boolean, whether supports dynamic alarm output channel: "true"-yes, "false"-
no-->
  <isSupportPTZRs485Proxy/><!--opt, xs:boolean, whether supports dynamic PTZ485 channel, "true"-yes, "false"-no-->
  <isSupportSrcIDSearch/><!--opt, xs:boolean, whether supports search by stream ID, "true"-yes, "false"-no-->
  <isSupportReversePlayback/><!--opt, xs:boolean, whether supports reverse playback, "true"-yes, "false"-no-->
  <isSupportSMARTTest/><!--opt, xs:boolean, whether supports HDD checking, "true"-yes, "false"-no-->
  <isSupportDownloadByTime/><!--opt, xs:boolean, whether supports downloading by time, "true"-yes, "false"-no-->
  <pictureSearchType
opt="AllEvent,CMR,MOTION,ALARM,EDR,ALARMANDMOTION,Command,pir,wlsensor,callhelp,facedetection,FieldDete
ction,scenechangedetection,LineDetection,regionEntrance,regionExiting,loitering,group,rapidMove,parking,unattende
dBaggage,attendedBaggage,vehicleDetection,manual,manualSnapShot,playSnapShot,allPic,evidence,illegalParking,cro
sslane,vehicleexist,lanechange,wrongdirection,congestion,turnround, parallelParking, pedestrian, construction,
roadblock, abandonedObject, trafficAccident, fogDetection, personQueueCounting,personQueueTime,
mixedTargetDetection, safetyHelmet"/>
   <!--opt, xs:string, picture search conditions-->
  <recordSearchType
opt="AllEvent,CMR,MOTION,ALARM,EDR,ALARMANDMOTION,Command,pir,wlsensor,callhelp,facedetection,FieldDete
ction,scenechangedetection,LineDetection,regionEntrance,regionExiting,loitering,group,rapidMove,parking,unattende
dBaggage,attendedBaggage,vehicleDetection,manual,manualSnapShot,playSnapShot,AudioDetection"/>
   <!--opt, xs:string, video file type to be searched-->

  <isSupportActivateIpc/><!--opt, xs:boolean, whether supports activating network camera, "true"-yes, "false"-no-->
  <isSupportCheckIpcSecurity><!--opt-->
   <isSupportCheckPassword/><!--opt, xs:boolean, whether supports password verification, "true"-yes, "false"-no-->
  </isSupportCheckIpcSecurity>
  <isSupportMainAndSubRecord/>
   <!--opt, xs:boolean, whether supports recording in main stream or sub-stream, "true"-yes, "false"-no-->
  <isSupportSyncIPCPassword>
   <!--opt, xs:boolean, whether supports synchronizing network camera's password, "true"-yes, "false"-no-->
  </isSupportSyncIPCPassword>
  <isSupportTransferIPC>
   <!--opt, xs:boolean, whether supports network camera passthrough function, "true"-yes, "false"-no-->
  </isSupportTransferIPC>
  <isSupportPOS><!--opt, xs:boolean, whether supports POS, "true"-yes, "false"-no--></isSupportPOS>
  <isSupportPassBackBasicCfg>
   <!--opt, xs:boolean, whether supports the ANR basic function of CVR, "true"-yes, "false"-no-->
  </isSupportPassBackBasicCfg>
  <PassBackTaskConfig><!--opt, task management function of ANR-->
   <isSupportAddTask><!--opt, xs:boolean, whether supports adding task, "true"-yes, "false"-no--></isSupportAddTask>
   <isSupportSearchTask><!--opt, xs:boolean, whether supports task search, "true"-yes, "false"-no--></
isSupportSearchTask>
   <isSupportControlTask><!--opt, xs:boolean, whether supports task control, "true"-yes, "false"-no--></
isSupportControlTask>
   <isSupportDeleteTask><!--opt, xs:boolean, whether supports deleting task, "true"-yes, "false"-no--></
isSupportDeleteTask>
  </PassBackTaskConfig>
  <PassBackPlanConfig><!--opt, task plan of ANR-->
   <isSupportAddPlan><!--opt, xs:boolean, whether supports adding plan, "true"-yes, "false"-no--></
isSupportAddPlan>
   <isSupportSearchPlan><!--opt, xs:boolean, whether supports plan search, "true"-yes, "false"-no--></
isSupportSearchPlan>
   <isSupportDeletePlan><!--opt, xs:boolean, whether supports deleting plan, "true"-yes, "false"-no--></
isSupportDeletePlan>
  </PassBackTaskConfig>
  <IRAIDCap/><!--opt, network RAID-->
  <isSupportStorageExtraInfo>
   <!--opt, xs:boolean, whether supports configuring storage additional information, "true"-yes, "false"-no-->
  </isSupportStorageExtraInfo>
  <isSupportRecordStatus><!--opt, xs:boolean--></isSupportRecordStatus>
  <supportAIDTFSType opt="illegalParking,wrongdirection crosslane,vehicleexist,lanechange, turnround, evidence"/>
   <!--opt, xs:string, event picture search conditions supported by both AID and TFS-->
  <isSupportRacmChannelsCap><!--opt, xs:boolen--></isSupportRacmChannelsCap>
  <LockCap/><!--opt, lock or unlock video-->
  <isSupportForamtAll><!--opt, xs:boolean, "true,false"--></isSupportForamtAll>
  <isSupportExtendCabinetCfg>
   <!--opt, xs:boolean, whether supports enclosure configuration-->
  </isSupportExtendCabinetCfg>
  <diskGroupNums><!--opt, xs:integer, number of supported HDD groups--></diskGroupNums>
  <isSupportCountingSearchByUTC><!--opt, xs:boolean, whether supports searching people counting results by UTC
time--></isSupportCountingSearchByUTC>
  <isSupportPlaybackReverseByUTC><!--opt, xs:boolean, whether supports reverse playback by UTC time--></
isSupportPlaybackReverseByUTC>
  <isSupportWebPrivatePlaybackByUTC>

  <!--opt, xs: boolean, whether supports playback based on Web private protocol-->
 </isSupportWebPrivatePlaybackByUTC >
 <isSupportFindCommonFileByUTC>
  <!--opt, xs: boolean, whether supports extending the time zone for searching files-->
 </isSupportFindCommonFileByUTC>
  <isSupportFindEventFileByUTC><!--opt, xs: boolean, whether supports extending the time zone for searching files
by event-->
 </isSupportFindEventFileByUTC >
 <isSupportSmartSearchRecordByUTC>
  <!--opt, xs: boolean, whether supports extending the time zone for VCA search-->
 </isSupportSmartSearchRecordByUTC>
 <isSupportMRDSearchByTimeZone>
  <!--opt, xs: boolean, whether supports extending the time zone for searching files by calendar-->
 </isSupportMRDSearchByTimeZone>
 <isSupportSearchRecordLabelByUTC>
  <!--opt, xs: boolean, whether supports extending the time zone for searching video tags-->
 </isSupportSearchRecordLabelByUTC>
 <isSupportSearchPictureByUTC>
  <!--opt, xs: boolean, whether supports extending the time zone for searching pictures-->
 </isSupportSearchPictureByUTC>
 <isSupportSmartSearchPictureByUTC>
  <!--opt, xs: boolean, whether supports extending the time zone for searching pictures with smart information-->
 </isSupportSmartSearchPictureByUTC>
 <isSupportFindLogByUTC>
  <!--opt, xs: boolean, whether supports extending the time zone for searching log-->
 </isSupportFindLogByUTC>
 <isSupportUploadRecordByUTC>
  <!--opt, xs: boolean, whether supports extending the time zone for uploading files to cloud storage-->
 </isSupportUploadRecordByUTC>
 <isSupportPlaybackByUTC>
  <!--opt, xs: boolean, whether supports extending the time zone for playback by time and locating by time-->
 </isSupportPlaybackByUTC>
 <SecurityLog>
  <isSupportSecurityLog><!--opt, boolean, whether supports security log--></isSupportSecurityLog>
  <isSupportLogServer><!--opt, boolean, whether supports log server configuration--></isSupportLogServer>
  <isSupportLogServerTest><!--opt, xs: boolean, whether supports log server test--></isSupportLogServerTest>
  <SecurityLogTypeList><!--req, xs: list, supported log type list-->
   <SecurityLogType>
     <primaryType><!--req, xs: string, major type--></primaryType>
     <secondaryType opt=""><!--req, xs: string, minor type--></secondaryType>
   </SecurityLogType>
  </SecurityLogTypeList>
 </SecurityLog>
 <iSptInputProxyChanCap>
  <!--opt, xs:boolean, whether to support getting the capability of the digital channel-->
 </iSptInputProxyChanCap>
 <isSupportLogDataPackage>
  <!--opt, xs:boolean, whether to support exporting logs: "true, false"-->
 </isSupportLogDataPackage>
 <logSearchTimeSpanNums>
  <!--opt, xs:integer, supported number of time periods for log search-->

 </logSearchTimeSpanNums>
</RacmCap>

16.2.250 XML_RegionalFocus
RegionalFocus message in XML format
<RegionalFocus version="2.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <StartPoint><!--0-1000-->
  <positionX><!--req, xs:integer--></positionX>
  <positionY><!--req, xs:integer--></positionY>
 </StartPoint>
 <EndPoint><!--0-1000-->
  <positionX><!--req, xs:integer--></positionX>
  <positionY><!--req, xs:integer--></positionY>
 </EndPoint>
</RegionalFocus>

16.2.251 XML_RegionClip
RegionClip message in XML format
<RegionClip version="2.0" xmlns="http://www.std-cgi.org/ver20/XMLSchema">
 <id><!--req, xs: string--></id>
 <enabled><!--req, xs: boolean--></enabled>
 <normalizedScreenSize><!--req, read-only-->
  <normalizedScreenWidth><!--req, read-only, xs: integer--></normalizedScreenWidth>
  <normalizedScreenHeight><!--req, read-only, xs: integer--></normalizedScreenHeight>
 </normalizedScreenSize>
 <regionType><!--req, ro, xs:string, opt="rectangle,convexPolygon,concavePolygon"--></regionType>
 <videoResolutionWidth><!--opt="704"--></videoResolutionWidth>
 <videoResolutionHeight><!--opt="576"--></videoResolutionHeight>
 <ClipRegionList>
  <ClipRegion>
   <RegionCoordinatesList>
    <RegionCoordinates><!--req, size=4-->
      <positionX><!--req, xs: integer; x-coordinate--></positionX>
      <positionY><!--req, xs: integer; y-coordinate--></positionY>
    </RegionCoordinates>
   </RegionCoordinatesList>
  </ClipRegion>
 </ClipRegionList>
</RegionClip>

16.2.252 XML_remotePermission
remotePermission message in XML format

<remotePermission version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <record><!—opt, xs: boolean—></record>
 <booleant><!—opt, xs: boolean—></booleant>
 <preview><!—opt, xs: boolean—></preview>
 <videoChannelPermissionList><!—opt—>
  <videoChannelPermission><!—opt—>
   <id><!—req, corresponds to the video input channel ID—></id>
   <preview><!—opt, xs: boolean—></preview>
   <palyBack><!—opt, xs: boolean—></palyBack>
   <record><!—opt, xs:boolean—></record>
   <playBackDoubleVerification>
    <!—opt, xs:boolean, whether supports secondary authentication for playback and download—>
   </playBackDoubleVerification>
  </videoChannelPermission>
 </videoChannelPermissionList>
 <ptzControl><!—opt, xs: boolean—></ptzControl>
 <ptzChannelPermissionList><!—opt—>
  <ptzChannelPermission><!—opt—>
   <id><!—req, corresponds to PTZ channel ID—></id>
   <ptzControl><!—opt, xs: boolean—></ptzControl>
  </ptzChannelPermission>
 </ptzChannelPermissionList>
 <logOrStateCheck><!—opt, xs: boolean, permission to view log and status—></logOrStateCheck>
 <parameterConfig><!—opt, xs: boolean, parameter configuration permission—></parameterConfig>
 <restartOrShutdown><!—opt, xs: boolean, permission to reboot and shutdown—></restartOrShutdown>
 <upgrade><!—opt, xs: boolean, permission to upgrade—></upgrade>
 <voiceTalk><!—opt, xs: boolean—></voiceTalk>
 <transParentChannel><!—opt, xs: boolean—></transParentChannel>
 <contorlLocalOut><!—opt, xs: boolean—></contorlLocalOut>
 <alarmOutOrUpload><!—opt, xs: boolean, permission to upload and output alarm—></alarmOutOrUpload>
 <factoryReset><!--opt, xs:boolean, restore default parameters--></factoryReset>
 <arm><!--opt, xs:boolean, arm--></arm>
 <disarm><!--opt, xs:boolean, disarm--></disarm>
 <accessControl><!--opt, xs:boolean, access control--></accessControl>
 <subSysOrZoneArm><!--opt, xs:boolean, partition or zone arming permission--></subSysOrZoneArm>
 <subSysOrZoneDisarm><!--opt, xs:boolean, partition or zone disarming permission--></subSysOrZoneDisarm>
 <subSysOrZoneClearArm><!--opt, xs:boolean, permission to clear partition or zone alarms--></
subSysOrZoneClearArm>
 <zoneBypass><!--opt, xs:boolean, permission to bypass zone--></zoneBypass>
 <zoneBypassRecover><!--opt, xs:boolean, permission to recover bypassing zone--></zoneBypassRecover>
 <IRAID>
  <rapidConfiguration><!--opt, xs:boolean--></rapidConfiguration>
  <reset><!--opt, xs:boolean--></reset>
 </IRAID>
 <subSystemList><!--opt, partitions that can be linked to operator when adding operator or setting operator
parameters-->
  <subSystem><!--opt, xs:integer, partition that can be linked to operator. When adding operator or setting operator
parameters, one or more partitions can be linked to an operator. An operator should be linked to at least one partition
and up to four partitions--></subSystem>
 </subSystemList>
</remotePermission>

16.2.253 XML_ResponseStatus
ResponseStatus message in XML format
<ResponseStatus version="2.0" xmlns="http://www.std-cgi.org/ver20/XMLSchema">
 <requestURL>
  <!--req, ro, xs:string, request URL-->
 </requestURL>
 <statusCode>
  <!--req, ro, xs:integer, status code: 0,1-OK, 2-Device Busy, 3-Device Error, 4-Invalid Operation, 5-Invalid XML Format,
6-Invalid XML Content, 7-Reboot Required, 9-Additional Error-->
 </statusCode>
 <statusString>
  <!--req, ro, xs:string, status description: OK, Device Busy, Device Error, Invalid Operation, Invalid XML Format, Invalid
XML Content, Reboot, Additional Error-->
 </statusString>
 <id>
  <!--opt, xs:integer, unique device ID created in POST operation-->
 </id>
 <subStatusCode>
  <!--req, ro, xs:string, describe the error reason in detail-->
 </subStatusCode>
 <errorCode>
  <!--opt, ro, xs:integer, error code, the returned value is the transformed decimal number-->
 </errorCode>
 <errorMsg>
  <!--opt, ro, xs:string, error message-->
 </errorMsg>
 <AdditionalErr>
  <!--dep, it is valid when statusCode is set to 9 (Additional Error). When setting or deleting in a batch failed, if the
error status of a specific device needs to be returned, statusCode should be set to 9 (Additional Error) and the node
<AdditionalError> should be returned-->
  <StatusList>
    <!--req-->
    <Status>
     <!--req-->
     <id>
      <!--opt, xs:string, device ID created in POST operation-->
     </id>
     <statusCode>
      <!--req, ro, xs:integer, status code: 0,1-OK, 2-Device Busy, 3-Device Error, 4-Invalid Operation, 5-Invalid XML
Format, 6-Invalid XML Content, 7-Reboot Required-->
     </statusCode>
     <statusString>
      <!--req, ro, xs:string, status description: OK, Device Busy, Device Error, Invalid Operation, Invalid XML Format,
Invalid XML Content, Reboot-->
     </statusString>
     <subStatusCode>
      <!--req, ro, xs:string, describe the error reason in detail-->
     </subStatusCode>
    </Status>

  </StatusList>
 </AdditionalErr>
</ResponseStatus>

     Note
See Error Codes in ResponseStatus for details about sub status codes and corresponding error
codes.

16.2.254 XML_ResponseStatus_AuthenticationFailed
ResponseStatus message in XML format for failed authentication.
<ResponseStatus version="1.0" xmlns="http://www.std-cgi.org/ver20/XMLSchema">
 <requestURL><!-- req, ro,xs:string --></requestURL>
 <statusCode><!-- req, ro,xs:integer --></statusCode>
 <statusString><!-- req, ro,xs:string --></statusString>
 <subStatusCode><!-- req, ro,xs:string --></subStatusCode>
 <lockStatus><!-- opt, ro,xs:string ,"unlock,locked", locking status--></lockStatus>
 <retryTimes><!-- opt, ro,xs:integer, remaining authentication attempts--></retryTimes>
 <resLockTime><!-- opt, ro,xs:integer, remaining locking time, unit: second--></resLockTime>
</ResponseStatus>

16.2.255 XML_Schedule
Schedule message in XML format
<Schedule version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string, ID--></id>
 <eventType>
  <!--opt, xs:string, alarm/event types, see details in the "Remarks" below-->
 </eventType>
 <inputIOPortID><!--ro, dep, xs:string, alarm input No.--></inputIOPortID>
 <outputIOPortID><!--ro, dep, xs:string, alarm output No.--></inputIOPortID>
 <videoInputChannelID><!--ro, dep, xs:string, video input channel ID--></videoInputChannelID>
 <TimeBlockList size="8"><!--req-->
  <TimeBlock><!--list-->
   <dayOfWeek>
    <!--opt, xs:integer, day of the week based on ISO8601, "1"=Monday, ...-->
   </dayOfWeek>
   <TimeRange><!--req-->
    <beginTime><!--req, xs:time, ISO8601 time--></beginTime>
    <endTime><!--req, xs:time, ISO8601 time--></endTime>
   </TimeRange>
   <CustomExtension>
    <vehicleDetectSceneID>
      <!--req, xs:interger-->
    </vehicleDetectSceneID>
   </CustomExtension>

  </TimeBlock>
 </TimeBlockList>
 <HolidayBlockList><!--opt-->
  <TimeBlock><!--list-->
   <TimeRange><!--req-->
    <beginTime><!--req, xs:time, ISO8601 time--></beginTime>
    <endTime><!--req, xs:time, ISO8601 time--></endTime>
   </TimeRange>
  </TimeBlock>
 </HolidayBlockList>
</Schedule>

Remarks
The node <eventType> can be set to the following values: IO, VMD,videoloss, PIR,linedetection,
fielddetection, audioexception, facedetection, regionEntrance, regionExiting, loitering, group,
rapidMove, parking, unattendedBaggage,attendedBaggage, storageDetection, shipsDetection,
HUMANATTRIBUTE, humanAttribute, faceContrast, faceSnap, faceLib, whiteListFaceContrast,
personDensityDetection, personQueueDetection, mixedTargetDetection, fireDetection,
illegalParking, pedestrian, trafficAccident,construction, roadblock, abandonedObject,
parallelParking, parkingState, congestion, intersectionAnalysis, heatMap, reverseEntrance,
vehicledetect, safetyHelmetDetection.

16.2.256 XML_SecurityCap
SecurityCap capability message in XML format
<SecurityCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <supportUserNums><!--opt, xs:integer, number of supported users--></supportUserNums>
 <userBondIpNums><!--opt, xs:integer, number of bound IP addresses supported by the user--></userBondIpNums>
 <userBondMacNums><!--opt, xs:integer, number of bound MAC addresses supported by the user--></
userBondMacNums>
 <issupIllegalLoginLock><!--opt, xs: boolean, whether it supports locking illegal login: "true,false"--
><issupIllegalLoginLock>
 <isSupportOnlineUser><!--opt, xs: boolean, "true,false"--><isSupportOnlineUser>
 <isSupportAnonymous><!--opt, xs: boolean, "true,false"--><isSupportAnonymous>
 <securityVersion opt="1,2"/><!--opt, xs:interger, encryption capability, each version contains encryption algorithm
and node range to be encrypted. "1"-encrypt by AES128, "2"-encrypt by AES256-->
 <keyIterateNum>
  <!--dep, xs:integer, iteration times, this node depends on securityVersion, and the value is usually between 100 and
1000-->
 </keyIterateNum>
 <isSupportUserCheck>
  <!--dep, opt, xs:boolean, whether it supports verifying password when editing/adding/deleting user parameters,
this node depends on securityVersion-->
 </isSupportUserCheck>
 <isSupportGUIDFileDataExport><!--opt, xs:boolean, "true,false"--></isSupportGUIDFileDataExport>
 <isSupportSecurityQuestionConfig><!--opt, xs:boolean, "true,false"--></isSupportSecurityQuestionConfig>
 <isSupportGetOnlineUserListSC><!--opt, xs:boolean, "true,false"--></isSupportGetOnlineUserListSC>
 <SecurityLimits><!--opt-->

   <LoginPasswordLenLimit min="1" max="16"><!--opt--></LoginPasswordLenLimit>
   <SecurityAnswerLenLimit min="1" max="128"><!--opt--></SecurityAnswerLenLimit>
  </SecurityLimits>
  <RSAKeyLength opt="512,1024,2048" def=2048/>
  <isSupportONVIFUserManagement><!--opt, xs: boolean, "true, false"--><isSupportONVIFUserManagement>
  <WebCertificateCap><!--opt-->
   <CertificateType opt="basic, digest, digest/basic"><!--req, xs:string--></CertificateType>
  </WebCertificateCap>
  <isSupportConfigFileImport>
   <!--opt, xs: boolean, whether it supports importing configuration files securely: "true"-yes. If it is not supported, this
node will not be returned-->
  </isSupportConfigFileImport>
  <isSupportConfigFileExport>
   <!-- opt, xs:boolean, whether it supports exporting configuration files securely: "true"-yes. If it is not supported, this
node will not be returned-->
  </isSupportConfigFileExport>
  <cfgFileSecretKeyLenLimit min="0" max="16">
   <!--opt, length limit of the configuration files' encryption key-->
  </cfgFileSecretKeyLenLimit>
  <isSupportDeviceCertificatesManagement>
   <!--opt, xs: boolean, whether it supports device certificate management: true-yes, if not support, this node will not
be returned-->
  </isSupportDeviceCertificatesManagement>
  <isIrreversible>
   <!--dep, opt, xs:boolean, whether it supports irreversible password storage. If this node does not exist, irreversible
password storage is not supported-->
  </isIrreversible>
  <salt>salt of username</salt>
  <keypadPassword min="1" max=""/><!--opt, xs:string, keypad password length. If different types of users have
different keypad password length, this node only indicates the administrator's keypad password length, otherwise this
node indicates that all types of users have the same keypad password length-->
  <installerKeypadPassword min="1" max=""/><!--opt, xs:string, installer's keypad password length-->
  <operatorKeypadPassword min="1" max=""/><!--opt, xs:string, operator's keypad password length-->
  <userOperateType opt="1,2,3">
   <!--opt, xs:string, user operation type: "1"-network user, "2"-keypad user, "3"-network user and keypad user-->
  </userOperateType>
  <isSptUserEnabled><!--opt, xs:boolean, whether it supports configuration of enabling user: "true"-yes, "false"-no--
></isSptUserEnabled>
  <isSptAdminCap><!--opt, xs:boolean, whether it supports getting administrator permission capability: "true"-yes,
"false"-no--></isSptAdminCap>
  <DoubleVerificationCap><!--opt, double verification capability-->
   <isSupportUsersConfig>
    <!--opt, xs: boolean, "true,false", whether it supports configuring double verification user-->
   </isSupportUsersConfig>
   <isSupportUsersPermissionConfig>
    <!--opt, xs: boolean, "true,false", whether it supports configuring the permission of double verification user-->
   </isSupportUsersPermissionConfig>
  </DoubleVerificationCap>
  <isSupportCertificateCustomID><!--opt, xs:Boolean, whether it supports certificate configuration with custom ID--></
isSupportCertificateCustomID>
</SecurityCap>

16.2.257 XML_SecurityQuestion
SecurityQuestion message in XML format
<SecurityQuestion version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  <QuestionList>
   <Question><!--the number of security question must be 3-->
     <id><!--required, xs: integer, question ID, which corresponds to that of device--></id>
     <answer>
       <!--write-only, xs: string, answer of the security question, it will not be returned when getting question; when
setting question, this node will be encrypted (BASE64-->AES128CBE) for transmission-->
     </answer>
     <mark>
       <!—required, read-only, xs: boolean, whether the configured security question is marked-->
     </mark>
   </Question>
  </QuestionList>
  <password>
   <!--write-only, xs: string, password that encrypted by CBC, this node will not be returned when getting question; but
it is required when setting question-->
  </password>
</SecurityQuestion>

See Also

16.2.258 XML_SerialCap
SerialCap capability message in XML format
<SerialCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <rs485PortNums min="1" max="5" def="1">
  <!--opt, xs: integer-->
 </rs485PortNums>
 <supportRS23Cconfig>
  <!--opt, xs: boolean-->
 </supportRS23Cconfig>
 <rs422PortNums opt="0">
  <!--opt, xs: integer-->
 </rs422PortNums>
 <rs232PortNums opt="1">
  <!--opt, xs: integer, range of RS-232 serial port No. supported by the device-->
 </rs232PortNums>
 <rs485WorkMode opt="Led, CaptureTrigger">
  <!--opt, xs: string, range of RS-485 serial port No. supported by the device-->
 </rs485WorkMode>
</SerialCap>

16.2.259 XML_SerialCommand
SerialCommand message in XML format
<SerialCommand version="1.0" xmlns="urn:psialliance-org">
 <chainNo>
  <!--opt, xs:string-->
 </chainNo>
 <command>
  <!--req, xs:hexBinary-->
 </command>
</SerialCommand>

16.2.260 XML_SerialPorList
SerialPorList message in XML format
<SerialPortList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <SerialPort/><!--opt, see details in the message of XML_SerialPort-->
</SerialPortList>

See Also
XML_SerialPort

16.2.261 XML_SerialPort
SerialPort message in XML format
<SerialPort version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id>
  <!--req, xs:string, serial port ID-->
 </id>
 <enabled>
  <!--req, xs:boolean, whether to enable the serial port: "true, false"-->
 </enabled>
 <serialPortType>
  <!--req, xs:string, serial port type: "RS485", "RS422", "RS232"-->
 </serialPortType>
 <duplexMode>
  <!--req, xs:string, duplex mode of the serial port: "half", "full"-->
 </duplexMode>
 <direction>
  <!--req, xs:string, "monodirectional, bdirectional"-->
 </direction>
 <baudRate>
  <!--req, xs:integer-->
 </baudRate>

 <dataBits>
  <!--req, xs:integer-->
 </dataBits>
 <parityType>
  <!--req, xs:string, parity type: "none,even,odd,mark,space"-->
 </parityType>
 <stopBits>
  <!--req, xs:string, stop bit: "1,1.5,2"-->
 </stopBits>
 <workMode>
  <!--dep, xs:string, working mode: "console","transparent","audiomixer","stairsControl"-elevator
control,"cardReader"-card reader,"disabled","custom". This node is required only when <serialPortType> is set to
"RS232"-->
 </workMode>
 <flowCtrl>
  <!--req, xs:string, "none, software, hardware"-->
 </flowCtrl>
 <rs485WorkMode>
  <!--opt, xs:string, working mode of RS-485 serial port, which is used for LED display or triggering transmission of
captured pictures: "Led, CaptureTrigger". This node is valid only when <serialPortType> is "RS485"-->
 </rs485WorkMode>
 <audiomixerProtocolType>
  <!--opt, xs:string, "HIKVISION". This node is required only when <workMode> is "audiomixer"-->
 </audiomixerProtocolType>
 <deviceName><!--deq, xs:string, device name, the maximum length is 32 bytes, this node is valid only when
<serialPortType> is "RS485"--></deviceName>
 <deviceType><!--deq, xs,integer, device type, this node is valid only when <serialPortType> is "RS485"--></
deviceType>
 <deviceProtocol><!--deq, xs,integer, device protocol, this node is valid only when <serialPortType> is "RS485"--></
deviceProtocol>
 <mode><!--deq, xs:string, working mode: "readerMode,clientMode,externMode,accessControlHost,disabled", this
node is valid only when <serialPortType> is "RS485"--></mode>
 <outputDataType><!--dep, xs:string, output data type: "cardNo,employeeNo", this node is valid when <mode>is
"accessControlHost"--></outputDataType>
</SerialPort>

16.2.262 XML_SIPInfo
SIPInfo message in XML format
<SIPInfo version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <videoID>
  <!--req, xs:string-->
 </videoID>
 <AlarmInList>
  <AlarmIn>
   <id>
    <!--req, xs:string-->
   </id>
   <alarmInID>
    <!--req, xs:string-->

   </alarmInID>
  </AlarmIn>
 </AlarmInList>
</SIPInfo>

16.2.263 XML_SIPInfoList
SIPInfoList message in XML format
<SIPInfoList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <SIPInfo>
  <videoID><!--req, xs: string--><videoID>
  <AlarmInList>
   <AlarmIn>
    <id><!--req, xs: string--></id>
  <alarmInID><!--req, xs: string--><alarmInID>
   </AlarmIn>
  </AlarmInList>
  <VideoInputList><!--opt-->
   <VideoInput>
  <id><!--req, xs: string--></id>
  <videoInputID><!--req, xs: string></videoInputID>
   </VideoInput>
  </VideoInputList>
  <AudioOutputList><!--opt,ID list of audio outputs-->
   <AudioOutput>
  <id><!--req, xs: string--></id>
  <audioOutputID><!--req, xs: string--></audioOutputID>
   </AudioOutput>
  </AudioOutputList>
  <platformNo><!-- opt, xs:integer--></platformNo>
 </SIPInfo>
<SIPInfoList>

16.2.264 XML_SIPServer
SIPServer message in XML format
<SIPServer version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id>
  <!--req, xs:interger, the maximum ID depends on the number of channels-->
 </id>
 <localPort>
  <!--req, xs:integer, local port No., which is between 1 and 65535-->
 </localPort>
 <streamID>
  <!--req, xs:integer, stream type: 1-main stream, 2-sub-stream, 3-third stream-->
 </streamID>
 <Standard>

 <!--opt-->
 <registerStatus>
  <!--ro, req, xs:boolean, registration status: "false"-unregistered, "true"-registered-->
 </registerStatus>
 <enabled >
  <!--req, xs:string, "true"-log in, "false"-log out-->
 </enabled>
 <registrar>
  <!--req, xs:string-->
 </registrar>
 <registrarPort>
  <!--req, xs:integer-->
 </registrarPort>
 <proxy>
  <!--req, xs:string-->
 </proxy>
 <proxyPort>
  <!--req, xs:integer-->
 </proxyPort>
 <displayName>
  <!--req, xs:string-->
 </displayName>
 <username>
  <!--req, xs:string-->
 </userName>
 <authID>
  <!--req, xs:string-->
 </authID>
 <password>
  <!--wo, req, xs:string-->
 </password>
 <expires>
  <!--req, xs:integer-->
 </expires>
</Standard>
<GB28181>
 <!--opt-->
 <registerStatus>
  <!--req, xs:boolean, "true,false"-->
 </registerStatus>
 <enabled>
  <!--req, xs:boolean, "true,false"-->
 </enabled>
 <registrar>
  <!--req, xs:string-->
 </registrar>
 <registrarPort>
  <!--req, xs:integer-->
 </registrarPort>
 <serverId>
  <!--req, xs:string-->
 </serverId>

  <serverDomain>
   <!--req, xs:string-->
  </serverDomain>
  <username>
   <!--req, xs:string-->
  </userName>
  <authID>
   <!--req, xs:string-->
  </authID>
  <password>
   <!--wo, req, xs:string-->
  </password>
  <expires>
   <!--req, xs:integer-->
  </expires>
  <liveTime>
   <!--req, xs:integer-->
  </liveTime>
  <heartbeatTime>
   <!--req, xs:integer-->
  </heartbeatTime>
  <heartbeatCount>
   <!--req, xs:integer-->
  </heartbeatCount>
 </GB28181>
</SIPServer>

16.2.265 XML_SIPServerList
SIPServerList message in XML format
<SIPServerList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <SIPServer/><!--opt, see details in the message of XML_SIPServer-->
</SIPServerList>

See Also
XML_SIPServer

16.2.266 XML_Sharpness
Sharpness message in XML format
<Sharpness version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <SharpnessMode><!--opt, xs:string, "manual", "auto"--></SharpnessMode>
 <SharpnessLevel><!--req, xs:integer--></SharpnessLevel>
</Sharpness>

16.2.267 XML_Shutter
Shutter message in XML format
<Shutter version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ShutterLevel>
  <!--dep, xs: string, shutter level: "1/1, 1/2, 1/3, 1/6, 1/12, 1/25, 1/50, 1/75, 1/100, 1/120, 1/125, 1/150, 1/175,
1/215, 1/225, 1/300, 1/400, 1/425, 1/600, 1/1000, 1/1250, 1/1750, 1/2500, 1/3500, 1/6000, 1/10000", this node is
valid when <ExposureType> in the message XML_Exposure is "ShutterFisrt"-->
 <ShutterLevel>
</Shutter>

See Also
XML_Exposure

16.2.268 XML_SmartCap
SmartCap capability message in XML format
<SmartCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  <isSupportROI><!--opt, xs:boolean, whether to support ROI (Region of Interest)--></isSupportROI>
  <isSupportFaceDetect><!--opt, xs:boolean, whether to support face detection--></isSupportFaceDetect>
  <isSupportIntelliTrace><!--opt, xs:boolean--></isSupportIntelliTrace>
  <isSupportFieldDetection><!--opt, xs:boolean, whether to support region detection--></isSupportFieldDetection>
  <isSupportDefocusDetection><!--opt, xs:boolean--></isSupportDefocusDetection>
  <isSupportAudioDetection><!--opt, xs:boolean--></isSupportAudioDetection>
  <isSupportSceneChangeDetection><!--opt, xs:boolean, whether to support scene change detection--></
isSupportSceneChangeDetection>
  <isSupportLineDetection><!--opt, xs:boolean--></isSupportLineDetection>
  <isSupportRegionEntrance><!--opt, xs:boolean--></isSupportRegionEntrance>
  <isSupportRegionExiting><!--opt, xs:boolean--></isSupportRegionExiting>
  <isSupportLoitering><!--opt, xs:boolean--></isSupportLoitering>
  <isSupportGroup><!--opt, xs:boolean--></isSupportGroup>
  <isSupportRapidMove><!--opt, xs:boolean--></isSupportRapidMove>
  <isSupportParking><!--opt, xs:boolean--></isSupportParking>
  <isSupportUnattendedBaggage><!--opt, xs:boolean--></isSupportUnattendedBaggage>
  <isSupportAttendedBaggage><!--opt, xs:boolean--></isSupportAttendedBaggage>
  <isSupportPeopleDetection><!--opt, xs:boolean--></isSupportPeopleDetection>
  <isSupportStorageDetection><!--opt, xs:boolean--></isSupportStorageDetection>
  <isSupportShipsDetection><!--opt, xs:boolean--></isSupportShipsDetection>
  <isSupportSmartCalibration><!--opt, xs:boolean--></isSupportSmartCalibration>
  <isSupportShield><!--opt, xs:boolean, whether to support shielded area--></isSupportShield>
  <isSupportAlgVersion><!--opt, xs:boolean, whether to support algorithm library version--></isSupportAlgVersion>
  <isSupportVideoOverlap><!--opt, xs:boolean, whether to support text overlay--></isSupportVideoOverlap>
  <isSupportParkingState><!--opt, xs:boolean, whether to support parking space status detection--></
isSupportParkingState>
  <isSupportChannelResource><!--opt, xs:boolean--></ isSupportChannelResource>
  <isSupportAnalysisUnitSwitch opt="true,false"><!--opt, xs:boolean, whether to support analysis unit switch--></
isSupportAnalysisUnitSwitch>

  <isSupportHFPD><!--opt, xs:boolean, whether to support frequently appeared person detection--></isSupportHFPD>
  <isSupportImageROI<!--opt, xs:boolean, whether to support smartJpeg (image ROI (Region of Interest))--></
isSupportImageROI>
</SmartCap>

16.2.269 XML_SmartSearchDescription
SmartSearchDescription message in XML format
<SmartSearchDescription version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <searchID>
  <!--req, xs:string, search ID, which is used to confirm the upper-level platform or system. If the platform or system
are same during two times of search, the search history will be recorded in the memory for next fast search-->
 </searchID>
 <searchResultPosition><!--req, xs: integer--></searchResultPosition>
 <maxResults><!--req, xs: integer--></maxResults>
 <trackID><!--req, xs: integer, channel ID, e.g., 101-main stream if first channel--></trackID>
 <startTime><!--req, xs: datetime, start time of validity period, e.g., 2013-06-10T 12:00:00Z--></startTime>
 <endTime><!--req, xs: datetime, end time of validity period, e.g., 2013-06-10T 13:00:00Z--></endTime>
 <type>
  <!--req, xs: string; VCA event type: "motionDetection, traversePlaneDetection,FieldDetection, faceDetection"-->
 </type>
 <MotionDetection><!--dep, it is valid when type is "motionDetection"-->
  <Grid>
   <rowGranularity></rowGranularity>
   <columnGranularity></columnGranularity>
  </Grid>
  <MotionDetectionLayout>
   <layout>
     <gridMap></gridMap>
   </layout>
  </MotionDetectionLayout>
  <sensitivity><!--opt, xs: integer, value range: [1,100]--></sensitivity>
 </MotionDetection>
 <TraversePlane><!--dep, it is valid when type is "traversePlaneDetection"-->
  <TraversePlaneParam>
   <LineList>
     <Line>
      <StartPoint>
       <x><!--req, xs: float--></x>
       <y><!--req, xs: float--></y>
      </StartPoint>
      <EndPoint>
       <x><!--req, xs: float--></x>
       <y><!--req, xs: float--></y>
      </EndPoint>
     </Line>
   </LineList>
   <crossDirection><!--opt, xs: string, crossing direction: "bothDirection, leftToRight, rightToLeft"--><crossDirection>
   <sensitivity><!-- opt, xs: integer, value range: [1,100]--></sensitivity>
   <planeHeight><!--opt, xs: integer--></planeHeight>

  <detectionTarget><!--req, xs: string, detection target type: "all, human, vehicle--><detectionTarget>
 </TraversePlaneParam>
 <dwPreTime><!--opt, xs: integer, pre-recording time--></dwPreTime>
 <dwDelayTime><!--opt, xs: integer,post-recording time--></dwDelayTime>
 <PTZPos>
  <P><!--opt, xs: integer--></P>
  <T><!--opt, xs: integer--></T>
  <Z><!--opt, xs: integer--></Z>
 </PTZPos>
 <advancedType><!--opt, xs: string, target sub type: "humanFeature, objectFeature"--></advancedType>
 <advance><!--dep, it is valid when type is "motionDetection"-->
  <HumanFeature>
   <age><!--opt, xs: integer, value range: [0,100]--></age>
   <sex><!--opt, xs: string, gender: "male,female"--></sex>
   <eyeGlass><!--opt, xs: boolean--></eyeGlass>
  </HumanFeature><!--dep, it is valid when advancedType is "humanFeature"-->
  <ObjectFeature>
   <colorRatel><!--opt, xs: integer--></colorRatel>
   <R><!--opt, xs: integer--></R>
   <G><!--opt, xs: integer--></G>
   <B><!--opt, xs: integer--></B>
  </ObjectFeature><!--dep, it is valid when advancedType is "objectFeature"-->
 </advance>
</TraversePlane>
<FieldDetection><!--dep, it is valid when type is "FieldDetection"-->
 <normalizedScreenSize>
  <normalizedScreenWidth><!--opt, xs: integer--></normalizedScreenWidth>
  <normalizedScreenHeight><!--opt, xs: integer--></normalizedScreenHeight>
 </normalizedScreenSize>
 <param>
  <region>
   <pointList>
     <point>
      <x><!--opt, xs: integer--></x>
      <y><!--opt, xs: integer--></y>
     </point>
   </pointList>
  </region>
 </param>
 <duration><!--opt, xs: integer, value range: [1,100]--></duration>
  <sensitivity><!--opt, xs: integer, value range: [1,100]--></sensitivity>
  <rate><!--opt, xs: integer, value range: [1,100]--></rate>
  <detectionTarget><!--req, xs: string, detection target type: "all, human, vehicle"--><detectionTarget>
  <dwPreTime><!--opt, xs: integer, pre-recording time--></dwPreTime>
  <dwDelayTime><!--opt, xs: integer, post-recording time--></dwDelayTime>
  <PTZPos>
   <P><!--opt, xs: integer--></P>
   <T><!--opt, xs: integer--></T>
   <Z><!--opt, xs: integer--></Z>
  </PTZPos>
  <advancedType><!--opt, xs: string, target sub type: "humanFeature, objectFeature"--></advancedType>
  <advance><!--dep, it is valid when type is "motionDetection"-->

   <HumanFeature>
    <age><!--opt, xs: integer, value range: [0,100]--></age>
    <sex><!--opt, xs: string, gender: "male,female"--></sex>
    <eyeGlass><!--opt, xs: boolean--></eyeGlass>
   </HumanFeature><!--dep, it is valid when advancedType is "humanFeature"-->
   <ObjectFeature>
    <colorRatel><!--opt, xs: integer--></colorRatel>
    <R><!--opt, xs: integer--></R>
    <G><!--opt, xs: integer--></G>
    <B><!--opt, xs: integer--></B>
   </ObjectFeature><!--dep, it is valid when advancedType is "objectFeature"-->
  </advance>
  </FieldDetection>
  <FaceDetection><!--dep, it is valid when type is "faceDetection"-->
   <param>
    <region>
     <pointList>
      <point>
        <x/>
        <y/>
      </point>
     </pointList>
    </region>
   </param>
   <duration><!--opt, xs: integer, value range: [1,100]--></duration>
   <sensitivity><!--opt, xs: integer, value range: [1,100]--></sensitivity>
   <rate><!--opt, xs: integer, value range: [1,100]--></rate>
   <detectionTarget><!--req, xs: string, detection target type: "all, human, vehicle"--><detectionTarget>
   <dwPreTime><!--opt, xs: integer, pre-recording time--></dwPreTime>
   <dwDelayTime><!--opt, xs: integer, post-recording time--></dwDelayTime>
   <PTZPos>
    <P><!--opt, xs: integer--></P>
    <T><!--opt, xs: integer--></T>
    <Z><!--opt, xs: integer--></Z>
   </PTZPos>
   <advancedType><!--opt, xs: string, target sub type: "humanFeature, objectFeature"--></advancedType>
   <advance><!--dep, it is valid when type is "motionDetection"-->
    <HumanFeature>
     <age><!--opt, xs: integer, value range: [0,100]--></age>
     <sex><!--opt, xs: string, gender: "male,female"--></sex>
     <eyeGlass><!--opt, xs: boolean--></eyeGlass>
    </HumanFeature><!--dep, it is valid when advancedType is "humanFeature"-->
    <ObjectFeature>
     <colorRatel><!--opt, xs: integer--></colorRatel>
     <R><!--opt, xs: integer--></R>
     <G><!--opt, xs: integer--></G>
     <B><!--opt, xs: integer--></B>
    </ObjectFeature><!--dep, it is valid when advancedType is "objectFeature"-->
   </advance>
 </FaceDetection>
</SmartSearchDescription>

16.2.270 XML_SmartSearchResult
SmartSearchResult message in XML format
<SmartSearchResult version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <searchID>
  <!--req, xs:string, search ID, which is used to confirm the upper-level platform or system. If the platform or system
are same during two times of search, the search history will be recorded in the memory for next fast search-->
 </searchID>
 <responseStatus><!--req, xs: string, "true,false"--></responseStatus>
 <responseStatusStrg><!--req, xs: string, "OK,NO MATCHES,MORE"--></responseStatusStrg>
 <numOfMatches><!--req, xs: integer--></numOfMatches>
 <totalMatches><!--req, xs: integer--></totalMatches>
 <matchList>
  <searchMatchItem><!--list-->
   <id><!--req, xs: integer--></id>
   <timeSpan>
     <startTime><!--req, xs: string, start time of validity period, e.g., 2013-06-10T 12:00:00Z--></startTime>
     <endTime><!--req,xs:string, end time of validity period, e.g., 2013-06-10T 12:00:00Z--></endTime>
   </timeSpan>
  </searchMatchItem>
 </matchList>
</SmartSearchResult>

16.2.271 XML_SMARTTestConfig
SMARTTestConfig message in XML format
<SMARTTestConfig version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enable opt="true,false"><!--req, xs:string, whether to continue using the HDD when the HDD SMART detection
failed--></enable>
</SMARTTestConfig>

16.2.272 XML_SMARTTestStatus
SMARTTestStatus message in XML format
<SMARTTestStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs: string--></id>
 <temprature><!--req, xs: integer, unit: °C--></temprature>
 <powerOnDay><!--req, xs: integer, unit: day--></powerOnDay>
 <selfEvaluaingStatus><!--req, xs: string, "ok, error"--></selfEvaluaingStatus>
 <allEvaluaingStatus><!--req, xs: string, "unctional,badsectors,fault"--></allEvaluaingStatus>
 <selfTestPercent><!--req, xs: integer--></selfTestPercent>
 <selfTestStatus>
  <!--req, xs: string,
"ok,aborted,interrupted,failed,unkown,electronic_element_error,servo_error,read_failed,progress,not_tested,not_rec
ognized"-->

 </selfTestStatus>
 <testType><!--req, xs: string, "short,expanded,conveyance"--></testType>
 <TestResultList><!--req, list, the maximum size is 30 bytes-->
  <TestResult><!--list-->
   <attributeID><!--req, xs: string--></attributeID>
   <attributeName><!--opt, xs: string--></attributeName>
   <status><!--req, xs: string, "ok,illegal"--></status>
   <flags><!--req, xs: integer--></flags>
   <thresholds><!--req, xs: integer--></thresholds>
   <value><!--req, xs: string--></value>
   <worst><!--req, xs: integer--></worst>
   <rawValue><!--req, xs: integer--></rawValue>
  </TestResult>
 </TestResultList>
</SMARTTestStatus>

16.2.273 XML_SoftwareService
SoftwareService message in XML format
<SoftwareService version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ThirdStream><!--opt, third stream configuration-->
  <enabled><!--req, xs: boolean, "true,false", whether to enable third stream configuration--></enabled>
 </ThirdStream>
 <PanoramaDisplay><!--opt, display the image range on panorama view-->
  <enabled>
   <!--req, xs: boolean, "true,false", whether to enable image range display on panorama view-->
  </enabled>
 </PanoramaDisplay>
 <MotionDetect>
  <enabled><!--whether to enable motion detetion--></enabled>
 </MotionDetect>
</SoftwareService>

16.2.274 XML_SocketIP
SocketIP message in XML format
<SocketIP version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ipAddress>
  <!--opt, xs: string-->
 </ipAddress>
 <ipv6Address>
  <!--opt, xs: string-->
 </ipv6Address>
</SocketIP>

16.2.275 XML_sourceCapability
sourceCapability message in XML format
<sourceCapability version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <videoInputNums><!--req, xs:integer--></videoInputNums>
 <audioInputNums><!--opt, xs:integer--></audioInputNums>
</sourceCapability>

16.2.276 XML_sourceDescriptor
sourceDescriptor message in XML format
<sourceDescriptor version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <adminProtocol><!--req, xs:string, "HIKVISION,SONY,ISAPI,ONVIF,..."--></adminProtocol>
 <addressingFormatType><!--req,xs:string, opt="ipaddress,hostname"--></addressingFormatType>
 <hostName><!--dep,xs:string, domain name--></hostName>
 <ipAddress><!--dep,xs:string, IP address--></ipAddress>
 <ipv6Address><!--dep,xs:string, IPv6 address--></ipv6Address>
 <managePortNo><!--req,xs:integer, port number--></managePortNo>
 <userName><!--req,xs:string--></userName>
 <password><!--req,wo,xs:string--></password>
</sourceDescriptor>

16.2.277 XML_SSH
SSH message in XML format
<SSH version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs:boolean--></enabled>
</SSH>

16.2.278 XML_staticRouteList
staticRouteList message in XML format
<staticRouteList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <staticRoute><!--opt-->
  <id>
   <!--req, xs: integer, this node must be configured when deleting-->
  </id>
  <enabled><!--req, xs: boolean--></enabled>
  <dstIpAddr><!--req, xs: string--></dstIpAddr>
  <dstNetmask><!--req, xs: string--></dstNetmask>
  <dstGateway><!--req, xs: string--></dstGateway>
  <ifName><!--req, xs: string， 0: G1, 1: G2--></ifName>

 </staticRoute>
</staticRouteList>

16.2.279 XML_StreamingChannel
StreamingChannel message in XML format
<StreamingChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  <id><!--req,xs:string;id--></id>
  <channelName><!--req,xs:string--></channelName>
  <enabled><!--req,xs:boolean--></enabled>
  <Transport><!--req-->
   <maxPacketSize><!--opt, xs: integer--></maxPacketSize>
   <audioPacketLength><!--opt, xs: integer--></audioPacketLength>
   <audioInboundPacketLength><!--opt, xs: integer--></audioInboundPacketLength>
   <audioInboundPortNo><!--opt, xs: integer--></audioInboundPortNo>
   <videoSourcePortNo><!--opt, xs: integer--></videoSourcePortNo>
   <audioSourcePortNo><!--opt, xs: integer--></audioSourcePortNo>
   <ControlProtocolList><!--req, protocol types for streaming-->
    <ControlProtocol><!--req-->
     <streamingTransport>
      <!--req,xs:string,"HTTP,RTSP,SHTTP,SRTP"-->
     </streamingTransport>
    </ControlProtocol>
   </ControlProtocolList>
   <Unicast><!--opt-->
    <enabled><!--req, xs: boolean--></enabled>
    <interfaceID><!--opt, xs: string--></interfaceID>
    <rtpTransportType
     <!--opt, xs: string, "RTP/UDP, RTP/TCP"-->
    </rtpTransportType>
   </Unicast>
   <Multicast><!--opt-->
    <enabled><!--req, xs: boolean--></enabled>
    <userTriggerThreshold><!--opt, xs: integer--></userTriggerThreshold>
    <destIPAddress><!--dep, xs: string--></destIPAddress>
    <videoDestPortNo><!--opt, xs: integer--></videoDestPortNo>
    <audioDestPortNo><!--opt, xs: integer--></audioDestPortNo>
    <destIPv6Address><!--dep, xs: string--></destIPv6Address>
    <ttl><!--opt, xs:integer--></ttl>
    <activeMulticastEnabled>
     <!--opt, xs: boolean, "true,false", whether to enable active multicast, which is mutual exclusion with passive
multicast-->
    </activeMulticastEnabled>
    <packagingFormat><!--opt, xs: string, container format--></packagingFormat>
    <FecInfo><!--opt-->
     <fecRatio>
      <!--req, read-only, xs: integer, extra bandwidth occupation ratio of forward error correction (FEC) data, the value
is between 0 and 100, the default value is 0-->
     </fecRatio>
     <fecDestPortNo>

    <!--opt, xs: integer, Port No. of FEC multicast, the default port No. is specified by device-->
   </fecDestPortNo>
  </FecInfo>
 </Multicast>
 <Security><!--opt-->
  <enabled><!--req, xs: boolean--></enabled>
  <certificateType><!--req, xs: string, opt="digest,digest/baisc" def="digest"--></certificateType>
 </Security>
 <SRTPMulticast><!--opt-->
  <SRTPVideoDestPortNo><!--opt, xs:integer--></SRTPVideoDestPortNo>
  <SRTPAudioDestPortNo><!--opt, xs:integer--></SRTPAudioDestPortNo>
 </SRTPMulticast>
</Transport>
<Video><!--opt-->
 <enabled><!--req,xs:boolean--></enabled>
 <videoInputChannelID>
  <!--req,xs:string;id-->
 </videoInputChannelID>
 <videoCodecType>
  <!--req,xs:string,"MPEG4,MJPEG,3GP,H.264,HK.264,MPNG,SVAC,H.265"-->
 </videoCodecType>
 <videoResolutionWidth>
  <!--req,xs:integer-->
 </videoResolutionWidth>
 <videoResolutionHeight>
  <!--req,xs:integer-->
 </videoResolutionHeight>
 <videoQualityControlType>
  <!--opt,xs:string,"CBR,VBR"-->
 </videoQualityControlType>
 <constantBitRate>
  <!--dep, xs:integer, constant bit rate, unit: kbps-->
 </constantBitRate>
 <vbrUpperCap>
  <!--dep, xs:integer, upper limit of variable bit rate, unit: kbps-->
 </vbrUpperCap>
 <vbrLowerCap>
  <!--dep, xs:integer, lower limit of variable bit rate, unit: kbps-->
 </vbrLowerCap>
 <maxFrameRate>
  <!--req, xs:integer, maximum frame rate, the value is multiplied by 100 to be returned-->
 </maxFrameRate>
 <keyFrameInterval><!--opt, xs:integer, milliseconds--></keyFrameInterval>
 <rotationDegree><!--opt, xs:integer, degrees, 0..360--></rotationDegree>
 <mirrorEnabled><!--opt, xs:boolean--></mirrorEnabled>
 <snapShotImageType><!--opt, xs:string, "JPEG,GIF,PNG"--></snapShotImageType>
 <Mpeg4Profile> <!--dep, xs:string, "SP,ASP"--></Mpeg4Profile>
 <H264Profile><!--dep, xs:string, "Baseline,Main,High, Extended"--></H264Profile>
 <SVACProfile><!--dep, xs:string, "Baseline,Main,High,Extended"--></SVACProfile>
 <GovLength> <!--opt, xs:integer--></GovLength>
 <SVC>
  <enabled><!--req, xs:boolean--></enabled>

   <SVCMode><!--dep, xs:string, "manual,auto"--></SVCMode>
  </SVC>
  <smoothing><!--opt, xs:integer--></smoothing>
  <SmartCodec><!--dep, -->
   <enabled><!--req, xs:boolean--></enabled>
  </SmartCodec>
  <vbrAverageCap><!--dep, xs:integer, in kbps--></vbrAverageCap>
  <IntelligentInfoDisplayMethod>
   <!--opt, intelligent information displaying method, xs:string, "player,non-player"-->
  </IntelligentInfoDisplayMethod>
 </Video>
 <Audio><!--opt-->
  <enabled><!--req, xs:boolean--></enabled>
  <audioInputChannelID><!--req, xs:string;id--></audioInputChannelID>
  <audioCompressionType>
   <!--req, xs:string,"G.711alaw,G.711ulaw,G.726,G.729,G.729a,G.729b,PCM,MP3,AC3,AAC,ADPCM，MP2L2"-->
  </audioCompressionType>
  <audioInboundCompressionType>
   <!--opt, xs:string,"G.711alaw,G.711ulaw,G.726,G.729,G.729a,G.729b,PCM,MP3,AC3,AAC,ADPCM,MP2L2"-->
  </audioInboundCompressionType>
  <audioBitRate><!--opt, xs:integer, in kbps--></audioBitRate>
  <audioSamplingRate><!--opt, xs:float, in kHz--></audioSamplingRate>
  <audioResolution><!--opt, xs:integer, in bits--></audioResolution>
  <VoiceChanger><!--opt, xs:integer, -12..0..12-->
   <enabled><!--req, xs:boolean--></enabled>
   <level><!--req, xs:integer, "-12..12"--></level>
  </VoiceChanger>
 </Audio>
 <enableCABAC><!--opt, xs: boolean--></enableCABAC>
 <subStreamRecStatus><!--opt, xs: boolean--></subStreamRecStatus>
 <customStreamEnable><!—opt, xs: boolean, whether the stream is custom stream: "true"-yes, this node is not
returned-no--></customStreamEnable>
</StreamingChannel>

16.2.280 XML_StreamingChannelList
StreamingChannelList message in XML format
<StreamingChannelList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <StreamingChannel/><!--opt, see details in XML_StreamingChannel-->
</StreamingChannelList>

See Also
XML_StreamingChannel

16.2.281 XML_StreamingStatus
StreamingStatus message in XML format

<StreamingStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <totalStreamingSessions><!--req, xs: integer, number of streaming sessions--></totalStreamingSessions>
 <StreamingSessionStatusList/><!--dep, this node is valid only when the number of sessions is larger than 0, refer to
XML_StreamingSessionStatusList for details-->
</StreamingStatus>

See Also
XML_StreamingSessionStatusList

16.2.282 XML_StreamingSessionStatusList
StreamingSessionStatusList message in XML format
<StreamingSessionStatusList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <StreamingSessionStatus>
  <clientAddress><!--req-->
   <ipAddress><!--dep, xs: string--></ipAddress>
   <ipv6Address><!--dep, xs: string--></ipv6Address>
  </clientAddress>
 </StreamingSessionStatus>
</StreamingSessionStatusList>

16.2.283 XML_SubscribeEvent
SubscribeEvent message in XML format
<SubscribeEvent version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema" >
 <heartbeat>
  <!--optional, xs:integer, heartbeat interval, unit: second, the default value is 30s-->
 </heartbeat>
 <eventMode>
  <!--required, xs:string, "all"-upload all alarms/events, "list"-upload specified alarm/event-->
 </eventMode>
 <EventList>
  <Event><!--uploading mode of specified alarm/event, this node exists only when eventMode is "list"-->
   <type>
     <!--required, xs:string, alarm/event types, which are obtained from the capability, refer to Alarm/Event Types for
Subscription for its values-->
   </type>
   <minorAlarm>
     <!--opt, xs:string, minor alarm type: "0x400,0x401,0x402,0x403", see details in Access Control Event Type. This
node is required when type is "AccessControllerEvent"-->
   </minorAlarm>
   <minorException>
     <!--opt, xs:string, minor exception type: "0x400,0x401,0x402,0x403", see details in Access Control Event Type.
This node is required when type is "AccessControllerEvent"-->
   </minorException>
   <minorOperation>

      <!--opt, xs:string, minor operation type: "0x400,0x401,0x402,0x403", see details in Access Control Event Type.
This node is required when type is "AccessControllerEvent"-->
    </minorOperation>
    <minorEvent>
      <!--opt, xs:string, minor event type: "0x01,0x02,0x03,0x04", see details in Access Control Event Type. This node is
required when type is "AccessControllerEvent"-->
    </minorEvent>
    <pictureURLType>
      <!--opt, xs:string, alarm picture format: "binary"-binary, "localURL"-device local URL, "cloudStorageURL"-cloud
storage URL-->
    </pictureURLType>
   </Event>
  </EventList>
  <channels>
      <!--optional, xs:string, event linked channel information, and multiple channels can be linked, each channel is
separated by comma, e.g., "1,2,3,4…"-->
    </channels>
  <channels>
   <!--optional, xs:string, specify channels (each channel is separated by comma, e.g., "1,2,3,4…") to be armed, this
node does not exist if you want to arm all channels, and if this node exists, the sub node <channels> in the node
<Event> is invalid-->
  </channels>
  <identityKey max="64"/>
  <!--opt, xs: string, interaction command of subscription, supports subscribing comparison results of face picture
library (importing with this command), the maximum length is 64-->
</SubscribeEvent>

16.2.284 XML_SubscribeEventCap
SubscribeEventCap capability message in XML format
<SubscribeEventCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <heartbeat min="" max="" />
   <!--optional, heartbeat time interval, unit: second-->
 <format opt="xml,json"/><!--req, supported message format-->
 <channelMode opt="all,list" />
   <!--required, channel subscription mode: "all"-subscribe events/alarms of all channels, "list"-subscribe events/
alarms of specific channels-->
 <eventMode opt="all,list" />
   <!--required, event subscription mode: "all"-subscribe all event types (must be supported), "list"-subscribe specific
event types, if "list" is returned, "all" will also be returned-->
   <!--if both the channelMode and eventMode returns "all", it indicates that the device does not support subscribing
event/alarm by event type or channel-->
 <EventList><!--required, dependent, upload mode of specified alarms/events, it is valid only when eventMode is
"list"-->
   <Event><!--required-->
    <type><!--required, xs:string, refer to Supported Alarm/Event Types for details--></type>
    <minorAlarm opt="0x400,0x401,0x402,0x403">
      <!--opt, xs:string, minor alarm type, see details in Access Control Event Type. This node is required when type is
"AccessControllerEvent"-->
    </minorAlarm>

    <minorException opt="0x400,0x401,0x402,0x403">
      <!--opt, xs:string, minor exception type, see details in Access Control Event Type. This node is required when type
is "AccessControllerEvent"-->
    </minorException>
    <minorOperation opt="0x400,0x401,0x402,0x403">
      <!--opt, xs:string, minor operation type, see details in Access Control Event Type. This node is required when type
is "AccessControllerEvent"-->
    </minorOperation>
    <minorEvent opt="0x01,0x02,0x03,0x04">
      <!--opt, xs:string, minor event type, see details in Access Control Event Type. This node is required when type is
"AccessControllerEvent"-->
    </minorEvent>
    <pictureURLType opt="binary,localURL,cloudStorageURL" def=""/>
    <!--opt, xs:string, alarm picture format: "binary"-binary, "localURL"-device local URL, "cloudStorageURL"-cloud
storage URL, and the def is followed by the default format-->
   </Event>
  </EventList>
  <pictureURLType opt="binary,localURL,cloudStorageURL" def=""/>
   <!--opt, xs:string, alarm picture format: "binary"-binary picture, "localURL"-device local URL, "cloudStorageURL"-
cloud storage URL. This node is the method of uploading all pictures related to the event. If this node is applied,
<pictureURLType> in <Event> is invalid; otherwise, pictures will be uploaded using the default method returned by the
device capability. For front-end devices, the default method is uploading binary pictures; for back-end devices, the
default method is by device local URL-->
  <ChangedUploadSub><!--message subscription-->
   <interval/><!--opt, xs:integer, lifecycle of arming GUID, the default value is 5 minutes, unit: second. The device will
generate new GUID for the arming connection after it is disconnected for the set lifecycle-->
   <StatusSub>
    <all/><!-- opt, xs:boolean, whether to subscribe all events-->
    <channel/><!--opt, xs:boolean, whether to subscribe channel status. This node is not required when <all> is
"true"-->
    <hd/><!--opt, xs:boolean, whether to subscribe disk status. This node is not required when <all> is "true"-->
    <capability/><!--opt, xs:boolean, whether to subscribe capability change status. This node is not required when
<all> is "true"-->
   </StatusSub>
  </ChangedUploadSub>
  <identityKey max="64"/>
  <!--opt, xs: string, interaction command of subscription, supports subscribing comparison results of face picture
library (importing with this command), the maximum length is 64-->
</SubscribeEventCap>

16.2.285 XML_SubscribeEventResponse
SubscribeEventResponse message in XML format
<SubscribeEventResponse>
 <id><!--req, xs:integer, subscription ID--></id>
 <FailedEventList>
 <!--opt, list of subscription failed events. When subscription failed, it should be returned, and the upper layer can
check whether all event/alarm subscriptions are succeeded via the existence of node FailedEventList-->
  <Event>
   <type>

     <!--req, xs:string, refer to Supported Alarm/Event Types for details-->
    </type>
    <minorAlarm>
     <!--opt, xs:string, minor alarm type: "0x400,0x401,0x402,0x403", see details in Access Control Event Type. This
node is required when type is "AccessControllerEvent"-->
    </minorAlarm>
    <minorException>
     <!--opt, xs:string, minor exception type: "0x400,0x401,0x402,0x403", see details in Access Control Event Type.
This node is required when type is "AccessControllerEvent"-->
    </minorException>
    <minorOperation>
     <!--opt, xs:string, minor operation type: "0x400,0x401,0x402,0x403", see details in Access Control Event Type.
This node is required when type is "AccessControllerEvent"-->
    </minorOperation>
    <minorEvent>
     <!--opt, xs:string, minor event type: "0x01,0x02,0x03,0x04", see details in Access Control Event Type. This node is
required when type is "AccessControllerEvent"-->
    </minorEvent>
    <pictureURLType>
     <!--opt,xs:string, opt="binary,localURL,cloudStorageURL", alarm picture transmission mode: "binary"-binary,
"localURL"-device local URL, "cloudStorageURL"-cloud storage URL-->
    </pictureURLType>
    <channels>
     <!--opt, xs:string, "1,2,3,4…", event related channel ID, supports multiple channels, and the channel ID is
separated by commas-->
    </channels>
    <subStatusCode>
     <!--req, string, subscription failure error code-->
    </subStatusCode>
   </Event>
 </FailedEventList>
</SubscribeEventResponse>

16.2.286 XML_SupplementLight
SupplementLight message in XML format
<SupplementLight><!--opt-->
 <mode><!--opt, xs: string, adjustment mode of supplement light, opt="schedule,off,on,auto"--></mode>
 <Schedule>
  <TimeRange><!--req-->
   <beginTime><!--req, xs: time, ISO8601 time--></beginTime>
   <endTime><!-- req, xs: time, ISO8601 time--></endTime>
  </TimeRange>
 </Schedule>
 <brightnessLimit>
  <!--dep, xs: integer, brightness of supplement light, which is between 0 and 100; the brightness can be adjust when
<mode> is set to "on"-->
 </brightnessLimit>
 <supplementLightMode>
  <!--opt, xs: string, illumination mode: "mixed"-hybrid, "whitelight"-white light, "close"-disabled-->

 </supplementLightMode>
 <irLightBrightness>
  <!--dep, xs: integer, brightness of IR supplement light, which is between 0 and 100; this node is valid only when
<supplementLightMode> is set to "mixed" and <mixedLightBrightnessRegulatMode> is set to "manual"-->
 </irLightBrightness>
 <mixedLightBrightnessRegulatMode>
  <!--dep, xs: string, brightness adjustment mode of hybrid supplement light, opt="manual,auto"; this node is valid
only when <supplementLightMode> is set to "mixed"-->
 </mixedLightBrightnessRegulatMode>
 <highIrLightBrightness>
  <!--dep, xs: integer, brightness of far IR light, which is between 0 and 100; this node cannot be configured together
with node <irLightBrightness>-->
 </highIrLightBrightness>
 <highWhiteLightBrightness>
  <!--dep, xs: integer, brightness of far white light, which is between 0 and 100; this node cannot be configured
together with node <brightnessLimit>-->
 </highWhiteLightBrightness>
 <lowIrLightBrightness>
  <!--dep, xs: integer, brightness of near IR light, which is between 0 and 100; this node cannot be configured together
with node <irLightBrightness>-->
 </lowIrLightBrightness>
 <lowWhiteLightBrightness>
  <!--dep, xs: integer, brightness of near white light, which is between 0 and 100; this node cannot be configured
together with node <brightnessLimit>-->
 </lowWhiteLightBrightness>
 <whiteLightBrightness><!--dep, xs: integer, white light brightness, which is between 0 and 100--></
whiteLightBrightness>
</SupplementLight>

16.2.287 XML_SyncSignalOutputList
SyncSignalOutputList message in XML format
<SyncSignalOutputList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <SyncSignalOutput>
  <IOWorkMode>
   <!--req, xs:string, IO output mode: "flashLight"-strobe light control mode, "polarizer"-polarizer control mode,
"continuousLight"-solid light control mode, "flashLightSwitch"-strobe light switching mode (used to switch between
the strobe supplement light mode and IR mode). When this node is set to "polarizer", only <outputStatus>,
<detectBrightnessEnable>, <brightnessThreshold>, <flashEnabled>, <startHour>, <startMinute>, <endHour>, and
<endMinute> are valid, and the <outputStatus> can only be set to "high" or "low". When this node is set to
"continuousLight", only <detectBrightnessEnable>, <brightnessThreshold>, <flashEnabled>, <startHour>,
<startMinute>, <endHour>, and <endMinute> are valid-->
  </IOWorkMode>
  <id>
   <!--req, xs:integer, number of IO outputs, which is between 1 and 8-->
  </id>
  <defaultStatus>
   <!--req, xs:string, IO default status: "high, low"-->
  </defaultStatus>
  <outputStatus>

   <!--req,xs:string, IO effective status: "high, low, pulse"-->
  </outputStatus>
  <aheadTime>
   <!--req, xs:integer, IO pre-output time, unit: microsecond-->
  </aheadTime>
  <timeDelay>
   <!--req, xs:integer, IO effective duration, unit: microsecond-->
  </timeDelay>
  <freqMultiplyulti>
   <!--req, xs:integer, frequency multiplication, which is between 1 and 15-->
  </freqMultiplyulti>
  <dutyRate>
   <!--req, xs:integer, duty ratio, which is between 0 and 40, unit: %-->
  </dutyRate>
  <postFlashEnable>
   <!--req, xs:boolean, checkpoint output: 0-enable, 1-disable-->
  </postFlashEnable>
  <illegalFlashEnable>
   <!--req, xs:boolean, violation output: 0/"true"-enable, 1/"false"-disable-->
  </illegalFlashEnable>
  <videoFlashEnable>
   <!--req, xs:boolean, video output: 0/"true"-enable, 1/"false"-disable-->
  </videoFlashEnable>
  <detectBrightnessEnable>
   <!--req, xs:boolean, whether to enable flash light for automatic brightness detection-->
  </detectBrightnessEnable>
  <brightnessThreshold>
   <!--dep, xs:integer, brightness threshold of the enabled flash light, which is between 0 and 100-->
  </brightnessThreshold>
  <flashEnabled>
   <!--req, xs:boolean, whether to enable flash light-->
  </flashEnabled>
  <startHour>
   <!--dep, xs:integer, start time in hour-->
  </startHour>
  <startMinute>
   <!--dep, xs:integer, start time in minute-->
  </startMinute>
  <endHour>
   <!--dep, xs:integer, end time in hour-->
  </endHour>
  <endMinute>
   <!--dep, xs:integer, end time in minute-->
  </endMinute>
  <plateBrightness>
   <!--req, xs:boolean, whether to enable flash light by license plate brightness: 0-disable, 1-enable. Only one node
among <detectBrightness>, <flashEnabled>, <manualBrightnessEnable> and <plateBrightness> can be enabled-->
  </plateBrightness>
  <incrBrightEnable>
   <!--opt, xs:boolean, whether to enable brightness enhancement mode (for solid light mode)-->
  </incrBrightEnable>
  <incrBrightTime>

   <!--req, xs:integer, brightness enhancement duration. This node is valid only when <incrBrightEnable> is "true"-->
  </incrBrightTime>
  <incrBrightPercent>
   <!--req, xs:integer, percentage of brightness enhancement, which is between 0 and 100. This node is valid only
when <incrBrightEnable> is "true"-->
  </incrBrightPercent>
  <brightness>
   <!--dep, xs:integer, solid light brightness (for solid light mode), which is between 0 and 100-->
  </brightness>
  <delayCaptureTime>
   <!--dep, xs:integer, delayed capture time, which is between 1 and 1000, unit: millisecond. This node is valid only
when <incrBrightEnable> is "true"-->
  </delayCaptureTime>
  <manualBrightnessEnable>
   <!--req, xs:boolean, whether to enable adjusting brightness manually-->
  </manualBrightnessEnable>
  <manualBrightness>
   <!--dep, xs:integer, brightness adjusted manually, which is between 0 and 100-->
  </manualBrightness>
 </SyncSignalOutput>
</SyncSignalOutputList>

16.2.288 XML_TargetEnhancement
TargetEnhancement message in XML format
<TargetEnhancement version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req,xs:boolean--></enabled>
</TargetEnhancement>

16.2.289 XML_TargetEnhancementCap
TargetEnhancementCap message in XML format
<TargetEnhancementCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled opt="true,false"><!--req, xs:boolean--></enabled>
</TargetEnhancementCap>

16.2.290 XML_Telnetd
Telnetd message in XML format
<Telnetd version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled>
  <!--req, xs:boolean, whether to enable telnet: "true, false"-->
 </enabled>
 <radarMsgEnabled>

  <!--req, xs:boolean, whether to enable uploading radar debugging information: "true, false"-->
 </radarMsgEnabled>
 <illeagalLoginLock>
  <!--req, xs:boolean, "true, false"-->
 </illeagalLoginLock>
</Telnetd>

16.2.291 XML_tempRange
tempRange message in XML format
<?xml version="1.0" encoding="utf-8"?>
<TempRange version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
  <mode>
   <!--req, xs:string, temperature range mode: "automatic"-automatic mode, "manual"-manual mode-->
  </mode>
  <temperatureUpperLimit>
   <!--dep, xs:float, maximum temperature, corrects to one decimal, the minimum value is "-20", the maximum value
is "550", unit: Celsius degree; its value should be larger than temperatureLowerLimit; it is valid when the value of
mode is "manual"-->
  </temperatureUpperLimit>
  <temperatureLowerLimit>
   <!--dep, xs:float, minimum temperature, corrects to one decimal, the minimum value is "-20", the maximum value is
"550", unit: Celsius degree; its value should be smaller than temperatureUpperLimit; it is valid when the value of
mode is "manual"-->
  </temperatureLowerLimit>
</TempRange>

16.2.292 XML_TextOverlay
TextOverlay message in XML format
<TextOverlay version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string, ID--></id>
 <enabled><!--req, xs:boolean--></enabled>
 <positionX><!--req, xs:float--></positionX>
 <positionY><!--req, xs:float--></positionY>
 <displayText><!--req, xs:string--></displayText>
</TextOverlay>

16.2.293 XML_TextOverlayList
TextOverlayList message in XML format
<TextOverlayList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <TextOverlay/><!--opt, see details in the message of XML_TextOverlay-->
</TextOverlayList>

See Also
XML_TextOverlay

16.2.294 XML_ThermalCap
ThermalCap message in XML format.
<ThermalCap version="2.0" xmlns="http://www.std-cgi.org/ver20/XMLSchema">
  <isSupportFireDetection><!--opt, xs:boolean, whether supports fire detection--></isSupportFireDetection>
  <isSupportThermometry><!--opt, xs:boolean, whether supports thermometry--></isSupportThermometry>
  <isSupportRealtimeThermometry><!--opt, xs:boolean, whether supports uploading real-time thermometry data--></
isSupportRealtimeThermometry>
  <isFireFocusZoomSupport><!--opt, xs:boolean, whether supports visible light lens zooming--></
isFireFocusZoomSupport>
  <isSupportManualRanging>
   <!--opt, xs:boolean, this node will be returned if one or more channels of device supports this function, see detailed
channel capability in the response information"-->
  </isSupportManualRanging>
  <isSupportPower><!--opt, xs:boolean, whether supports power on/off capability--></isSupportPower>
  <isSupportRealtimeTempHumi><!--opt, xs:boolean, whether supports real-time detection of temperature and
humidity--></isSupportRealtimeTempHumi>
  <ManualThermCap>
   <manualThermRuleNum>
    <!--opt, xs:integer, the max. number of supported rules for manual thermometry. If this node is not returned, it
indicates manual thermometry is not supported-->
   </manualThermRuleNum>
  </ManualThermCap>
  <isSupportManualThermBasic>
   <!--opt, xs:boolean, whether supports basic configuration of manual thermometry-->
  </isSupportManualThermBasic>
  <isSupportFireShieldMask><!--opt, xs:boolean--></isSupportFireShieldMask>
  <isSupportsmokeShieldMask><!--opt, xs:boolean--></isSupportsmokeShieldMask>
  <isSupportThermometryMode>
   <!--opt, xs:boolean, whether supports the configuration of temperature measurement mode-->
  </isSupportThermometryMode>
  <isSupportThermalPip>
   <!--opt, xs:boolean, whether supports the PIP configuration-->
  </isSupportThermalPip>
  <isSupportThermalIntelRuleDisplay><!--opt, xs:boolean, whether supports VCA rule configuration--></
isSupportThermaIntelRuleDisplay>
  <AlgVersionInfo><!-opt, whether supports getting the version information of thermal algorithms library-->
   <thermometryAlgName min = "1" max = "128">
    <!--ro, xs:string, version information of temperature measurement algorithms library-->
   </thermometryAlgName>
   <shipsAlgName min = "1" max = "128"><!--ro, xs:string, version name of ship detection algorithms library--></
shipsAlgName>
  </AlgVersionInfo>
  <isSupportFaceThermometry><!--opt, xs:boolean, whether supports body thermometry configuration--></
isSupportFaceThermometry>
  <isSupportThermalBlackBody><!--opt, xs:boolean, whether supports black body configuration--></

isSupportThermalBlackBody>
  <isSupportThermalStreamParam><!--opt, xs:boolean, whether supports stream configuration--></
isSupportThermalStreamParam>
  <isSupportBodyTemperatureCompensation>
   <!--opt, xs:boolean, whether supports temperature compensation configuration-->
  </isSupportBodyTemperatureCompensation>
  <isSupportTemperatureCorrection><!--opt, xs:boolean, whether device supports thermometry correction--></
isSupportTemperatureCorrection>
  <isSupportClickToThermometry><!--opt, xs:boolean, whether device supports clicking for thermometry--></
isSupportClickToThermometry>
  <isSupportThermometryHistorySearch><!--opt, xs:boolean--></isSupportThermometryHistorySearch>
  <isSupportBurningPrevention><!--opt, xs:boolean, whether device supports burning prevention--></
isSupportBurningPrevention>
  <isSupportTemperatureCollection><!--opt, xs:boolean, whether device supports temperature ANR--></
isSupportTemperatureCollection>
  <isSupportJpegPicWithAppendData>
   <!--opt, xs:boolean, whether device supports getting JPEG picture with pixel-to-pixel thermometry data. If supports,
it is returned and values true, if not support, it is not returned-->
  </isSupportJpegPicWithAppendData>
  <isSupportRealTimethermometryForHTTP>
   <!--opt, xs:boolean, whether device supports real-time thermometry. If supports, it is returned and its value is true,
if not support, it is not returned-->
  </isSupportRealTimethermometryForHTTP>
  <isSupportShipsDetectionWithScene>
   <!--opt, xs:boolean, whether device supports ship detection by scene, this node and isSupportShipsDetection in
XML_SmartCap are mutually exclusive-->
  </isSupportShipsDetectionWithScene>
  <isSupportthermometryOffLineCapture>
   <!--opt, xs:boolean, whether device supports offline capture. If supports, this node returned and its value is true; if
not, it is not returned-->
  </isSupportthermometryOffLineCapture>
</ThermalCap>

Remarks
When getting thermal product capabilities, isSupportShipsDetectionWithScene has a higher
priority than isSupportShipsDetection. That is, firstly check if the node
isSupportShipsDetectionWithScene exists and its value is "true", that indicates ship detection
according to scene is supported, otherwise, check the if the node isSupportShipsDetection exists.

16.2.295 XML_Time
Time message in XML format
<Time version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <timeMode><!--req, xs:string, "manual, NTP, local, satellite, timecorrect"--></timeMode>
 <localTime>
  <!--req, xs:datetime, ISO 8601 time format, device time set manually, e.g.: 2018-02-01T19:54:04. This node is
required when <timemode> is "manual" or "local"-->
 </localTime>
 <timeZone>

  <!-- req, xs:string, POSIX time zone string, device time synchronized with NTP, this node is required when
<timemode> is "manual", "local" or "NTP"-->
 </timeZone>
 <satelliteInterval><!--dep, xs:integer, unit: minute--></satelliteInterval>
</Time>

16.2.296 XML_TimeTaskList
TimeTaskList message in XML format
<TimeTaskList size="">
 <enabled><!--req, xs: boolean--></enabled>
 <Parktime min="" max=""><!--req, xs:integer, seconds--></Parktime>
 <TimeTaskBlock>
  <dayOfWeek><!--req, xs: integer, day of the week based on ISO8601, "1"-Monday, ...--></dayOfWeek>
  <TimeTaskRange>
   <TaskID min="" max=""><!--req, xs: string; ID--></TaskID>
   <beginTime><!--req, xs: time, ISO8601 time--></beginTime>
   <endTime> <!--req, xs: time, ISO8601 time--></endTime>
   <Task>
     <TaskType
opt="disable,autoscan,framescan,randomscan,panoramascan,patrol,pattern,preset,tiltscan,periodreboot,periodadjust,
auxoutput">
   <!--req, xs: strings-->
  </TaskType>
  <patrolTaskNum min="" max=""><!--dep, xs: integer, from 0 to 8--></patrolTaskNum>
  <patternTaskNum min="" max=""><!--dep, xs: integer, from 0 to 8--></patternTaskNum>
  <presetTaskNum min="" max=""><!--dep, xs: integer, from 0 to 8--></presetTaskNum>
  <auxoutputTaskNum min="" max=""><!--dep, xs: integer, from 0 to 8--></
auxoutputTaskNum>
   </Task>
  </TimeTaskRange>
 </TimeTaskBlock>
 <isSupportTimeTaskCopy><!--req, xs: boolean--></isSupportTimeTaskCopy>
</TimeTaskList>

16.2.297 XML_trackDailyParam
trackDailyParam message in XML format
<trackDailyParam version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <year><!--req, xs: integer, year--></year>
 <monthOfYear><!--req, xs: integer, month of the year--></monthOfYear>
</trackDailyParam>

16.2.298 XML_trackDailyDistribution
trackDailyDistribution message in XML format
<trackDailyDistribution version="1.0" xmlns="http://www.isapi.com/ver20/XMLSchema">
 <dayList>
  <day>
   <id><!--req, xs: integer, ID--></id>
   <dayOfMonth><!--req, xs: integer, day of the month, starts from 1st--></dayOfMonth>
   <record><!--req, xs: boolean, true-with video, false-no video--></record>
   <recordType>
     <!--req, xs: string, record type: time-continuous recording; event-record based on event-->
   </recordType>
  </day>
 </dayList>
</trackDailyDistribution>

16.2.299 XML_TrackList
TrackList message in XML format
<TrackList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <Track/><!--opt, recording schedule list, refer to the message XML_Track for details-->
</TrackList>

See Also
XML_Track

16.2.300 XML_Track
Track message in XML format
<Track version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs: integer--></id>
 <Channel><!--req, xs: integer--></Channel>
 <Enable><!--req, xs: boolean--></Enable>
 <Description><!--req, xs: string--></Description>
 <TrackGUID><!--req, xs: string--></TrackGUID>
 <Size><!--opt, xs: integer--></Size>
 <Duration min="" max=""><!--opt, xs: string--></Duration>
 <DefaultRecordingMode><!--req, xs: string--></DefaultRecordingMode>
 <LoopEnable><!--opt, xs: string--></LoopEnable>
 <SrcDescriptor>
  <SrcGUID><!--req, xs: string--></SrcGUID>
  <SrcChannel><!--req, xs: integer--></SrcChannel>
  <StreamHint><!--req, xs: string--></StreamHint>
  <SrcDriver><!--req, xs: string--></SrcDriver>

  <SrcType><!--req, xs: string--></SrcType>
  <SrcUrl><!--req, xs: string--></SrcUrl>
  <SrcUrlMethods><!--req, xs: string--></SrcUrlMethods>
  <SrcLogin><!--req, xs: string--></SrcLogin>
 </SrcDescriptor>
 <TrackSchedule>
  <ScheduleBlockList>
   <ScheduleBlock>
    <ScheduleBlockGUID><!--req, xs: string--></ScheduleBlockGUID>
    <ScheduleBlockType><!--req, xs: string--></ScheduleBlockType>
    <ScheduleAction>
     <id><!--req, xs: integer--></id>
     <ScheduleActionStartTime>
       <DayOfWeek><!--req, xs: string--></DayOfWeek>
       <TimeOfDay><!--req, xs: string--></TimeOfDay>
     </ScheduleActionStartTime>
     <ScheduleActionEndTime>
       <DayOfWeek><!--req, xs: string--></DayOfWeek>
       <TimeOfDay><!--req, xs: string--></TimeOfDay>
     </ScheduleActionEndTime>
     <ScheduleDSTEnable><!--req, xs: boolean--></ScheduleDSTEnable>
     <Description><!--req, xs: string--></Description>
     <Actions>
       <Record><!--req, xs: boolean--></Record>
       <Log><!--req, xs: boolean--></Log>
       <SaveImg><!--req, xs: boolean--></SaveImg>
       <ActionRecordingMode><!--req, xs: string--></ActionRecordingMode>
     </Actions>
    </ScheduleAction>
   </ScheduleBlock>
  </ScheduleBlockList>
 </TrackSchedule>
 <CustomExtensionList>
  <CustomExtension>
   <CustomExtensionName><!--req, xs: string--></CustomExtensionName>
   <enableSchedule><!--req, xs: boolean--></enableSchedule>
   <SaveAudio><!--req, xs: boolean--></SaveAudio>
   <PreRecordTimeSeconds><!--req, xs: integer--></PreRecordTimeSeconds>
   <PostRecordTimeSeconds><!--req, xs: integer--></PostRecordTimeSeconds>
   <HolidaySchedule>
    <ScheduleBlock>
     <ScheduleBlockGUID><!--req, xs: string--></ScheduleBlockGUID>
     <ScheduleBlockType><!--req, xs: string--></ScheduleBlockType>
    </ScheduleBlock>
   </HolidaySchedule>
  </CustomExtension>
 </CustomExtensionList>
 <IntelligentRecord><!--opt, xs:boolean, whether to enable VCA recording function: 0-no, 1-yes--></IntelligentRecord>
 <delayTime><!--opt, xs:integer, capture delay time, unit: second--></delayTime>
 <durationEnabled><!--opt, xs:boolean, whether to enable video expiry time. If this function is not supported, this
node will not be returned. If this function is supported, the video expiry date will be set by the node <Duration>--></

durationEnabled>
</Track>

16.2.301 XML_TwoWayAudioChannel
TwoWayAudioChannel message in XML format
<TwoWayAudioChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id>
  <!--req, xs:string, two-way audio channel ID-->
 </id>
 <enabled>
  <!--req, xs:boolean, whether to enable two-way audio: "true"-yes, "false"-no-->
 </enabled>
 <audioCompressionType>
  <!--req, xs:string, audio output encoding type: "G.711alaw,G.711ulaw,G.726,G.729,G.729a,G.
729b,PCM,MP3,AC3,AAC,ADPCM,MP2L2"-->
 </audioCompressionType>
 <audioInboundCompressionType>
  <!--opt, xs:string, audio input encoding type: "G.711alaw,G.711ulaw,G.726,G.729,G.729a,G.
729b,PCM,MP3,AC3,AAC,ADPCM"-->
 </audioInboundCompressionType>
 <speakerVolume>
  <!--opt, xs:integer, input volume-->
 </speakerVolume>
 <microphoneVolume>
  <!--opt, xs:integer, output volume-->
 </microphoneVolume>
 <noisereduce>
  <!--opt, xs:boolean, whether to enable noise reduction: "true, false"-->
 </noisereduce>
 <audioBitRate>
  <!--opt, xs:integer, audio frame rate, unit: kbs-->
 </audioBitRate>
 <audioInputType>
  <!--opt, xs:string, audio input type: "MicIn, LineIn"-->
 </audioInputType>
 <associateVideoInputs><!--opt-->
  <enabled>
    <!--req, xs:boolean-->
  </enabled>
  <videoInputChannelList>
    <!--req-->
    <videoInputChannelID>
     <!--opt, xs:string, ID-->
    </videoInputChannelID>
  </videoInputChannelList>
 </associateVideoInputs>
 <lineOutForbidden>
  <!--read-only, xs:boolean, whether the audio output is not supported, if this node is not returned or the value is
"false", it represents that audio output is supported; if the value is "true", it represents that audio output is not

supported-->
 </lineOutForbidden>
 <micInForbidden>
  <!--read-only, xs: boolean, whether the audio input is not supported, if this node is not returned or the value is
"false", it represents that audio input is supported; if the value is "true", it represents that audio input is not
supported-->
 </micInForbidden>
</TwoWayAudioChannel>

16.2.302 XML_TwoWayAudioChannelCap
TwoWayAudioChannelCap capability message in XML format
<TwoWayAudioChannelCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id opt="1">
  <!--req, xs:string, two-way audio channel ID-->
 </id>
 <enabled opt="true,false">
  <!--req, xs:boolean, whether to enable two-way audio: "true"-yes, "false"-no-->
 </enabled>
 <audioCompressionType opt="G.711alaw,G.711ulaw,G.726,G.729,G.729a,G.
729b,PCM,MP3,AC3,AAC,ADPCM,MP2L2">
  <!--req, xs:string, audio output encoding type-->
 </audioCompressionType>
 <audioInboundCompressionType opt=" G.711alaw,G.711ulaw,G.726,G.729,G.729a,G.
729b,PCM,MP3,AC3,AAC,ADPCM">
  <!--opt, xs:string, audio input encoding type-->
 </audioInboundCompressionType>
 <speakerVolume opt="0-100">
  <!--opt, xs:integer, input volume, which is between 0 and 100-->
 </speakerVolume>
 <microphoneVolume opt="0-100">
  <!--opt, xs:integer, output volume, which is between 0 and 100-->
 </microphoneVolume>
 <noisereduce opt="true,false">
  <!--opt, xs:boolean, whether to enable noise reduction: "true, false"-->
 </noisereduce>
 <audioBitRate opt="32,64,128">
  <!--opt, xs:integer, audio frame rate, unit: kbs-->
 </audioBitRate>
 <audioInputType opt="Micln,LineIn">
  <!--opt, xs:string, audio input type-->
 </audioInputType>
 <associateVideoInputs>
  <!--opt-->
  <enabled opt="true,false">
   <!--req, xs:boolean-->
  </enabled>
  <videoInputChannelList>
   <!--req-->
   <videoInputChannelID opt="1">

    <!--opt, xs:string, ID-->
   </videoInputChannelID>
  </videoInputChannelList>
 </associateVideoInputs>
</TwoWayAudioChannelCap>

16.2.303 XML_TwoWayAudioChannelList
TwoWayAudioChannelList message in XML format
<TwoWayAudioChannelList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <TwoWayAudioChannel/><!--opt, see details in the message of XML_TwoWayAudioChannel-->
</TwoWayAudioChannelList>

See Also
XML_TwoWayAudioChannel

16.2.304 XML_TwoWayAudioSession
TwoWayAudioSession message in XML format
<TwoWayAudioSession version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <sessionId><!--req, xs: string, communication session ID--></sessionId>
</TwoWayAudioSession>

16.2.305 XML_upgradeStatus
upgradeStatus message in XML format
<upgradeStatus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <upgrading><!--ro, req, xs:boolean--></upgrading>
 <percent><!--ro, req, xs:integer, upgrading progress, the value is between 0 and 100--></percent>
</upgradeStatus>

16.2.306 XML_UPnP
UPnP message in XML format
<UPnP version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled/><!--req-->
 <ports/><!--opt-->
</UPnP>

16.2.307 XML_User
User message in XML format
<User version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:integer, the value is between 1 and 16, the ID of the administrator account is 1 and the administrator
account cannot be deleted--></id>
 <enabled><!--opt, xs:boolean, whether to enable the user: "true"-yes, "false"-no--></enabled>
 <userName><!--req, xs:string, the sensitive information should be encrypted--></userName>
 <password><!--wo, opt, xs:string, the sensitive information should be encrypted--></password>
 <keypadPassword><!--wo, opt, xs:string, keypad password, the sensitive information should be encrypted--></
keypadPassword>
 <loginPassword><!--wo, dep, xs:string, this node depends on security in the URL and it is required when security
exists. The sensitive information should be encrypted, and the password is the administrator password--></
loginPassword>
 <userOperateType><!--opt, xs:integer, user operation type: "1"-network user, "2"-keypad user, "3"-network user and
keypad user. When this node is set to 1 or NULL, password is valid, and password is required when the method is
POST, otherwise it is optional. When this node is set to 2, keypadPassword is valid, and keypadPassword is required
when the method is POST, otherwise it is optional. When this node is set to 3, both password and keypadPassword
are valid, and they are required when the method is POST, otherwise they are optional--></userOperateType>
 <bondIpAddressList><!--opt-->
  <bondIpAddress><!--opt-->
    <id><!--req, xs:integer--></id>
    <ipAddress><!--dep, xs:string--></ipAddress>
    <ipv6Address><!--dep, xs:string--></ipv6Address>
  </bondIpAddress>
 </bondIpAddressList>
 <bondMacAddressList><!--opt-->
  <bondMacAddress><!--opt-->
    <id><!--req, xs:integer--></id>
    <macAddress><!--opt, xs:string--></macAddress>
  </bondMacAddress>
 </bondMacAddressList>
 <userLevel><!--opt, xs:string, "Administrator,Operator,Viewer,installer,manufacturer"--></userLevel>
 <attribute><!--opt-->
  <inherent><!--xs:boolean--></inherent>
 </attribute>
</User>

16.2.308 XML_userCheck
userCheck message in XML format
<userCheck version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <statusValue><!--req, xs:integer, status code: "200"-succeeded, "401"-failed--></statusValue>
 <statusString><!--opt, xs:string, status: "OK", "Unauthorized"--></statusString>
 <isDefaultPassword><!--opt, xs:boolean--></isDefaultPassword>
 <isRiskPassword><!--opt, xs:boolean></isRiskPassword>
 <isActivated><!--opt, xs:boolean></isActivated>

 <lockStatus><!--opt, xs:string, locking status: "unlock","locked"--></lockStatus>
 <unlockTime><!--opt, xs:integer, unlocking remaining time, unit: second--></ unlockTime>
 <retryLoginTime><!--opt, xs:integer, remaining login attempts--></retryLoginTime>
</userCheck>

16.2.309 XML_UserList
UserList message in XML format
<UserList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <User/><!--opt, see details in the message of XML_User-->
</UserList>

See Also
XML_User

16.2.310 XML_UserPermission
UserPermission message in XML format
<UserPermission version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs:string--></id>
 <userID><!--req, xs:string, user ID--></userID>
 <userType>
   <!--req, xs:string, user type: "admin"-administrator, which has all permissions and can review and edit user's
permission, "operator"-operator, which has default permissions, "viewer"-viewer, which has default permissions,
"installer", "manufacturer"-->
 </userType>
 <localPermission/>
   <!--opt, local permission, see details in the message of XML_localPermission -->
 <remotePermission/>
   <!--opt, remote permission, see details in the message of XML_remotePermission -->
</UserPermission>

See Also
XML_localPermission
XML_remotePermission

16.2.311 XML_UserPermissionCap
UserPermissionCap capability message in XML format
<UserPermissionCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <userType><!--req, xs:string, "admin"-administrator, "operator", "viewer", "installer", "manufacturer"--></userType>
 <localPermissionCap><!--opt, see details in the message of
                       XML_localPermission

                   --></localPermissionCap>
 <remotePermissionCap><!--opt, see details in the message of
                     XML_remotePermission
                   --></remotePermissionCap>
</UserPermissionCap>

16.2.312 XML_UserPermissionList
UserPermissionList message in XML format
<UserPermissionList version="2.0" xmlns=" http://www.isapi.org/ver20/XMLSchema">
 <UserPermission/>
  <!--opt, user permission, see details in the message of XML_UserPermission-->
</UserPermissionList>

See Also
XML_UserPermission

16.2.313 XML_WDR
WDR message in XML format
<WDR version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <mode><!--req, xs: string, WDR mode: "open,close,auto"--></mode>
 <WDRLevel><!--opt, xs: integer--></WDRLevel>
 <WDRContrastLevel><!--opt, xs: integer--></WDRContrastLevel>
 <WDRLevel1><!--opt, xs: integer--></WDRLevel1>
</WDR>

16.2.314 XML_WhiteBalance
WhiteBalance message in XML format
<WhiteBalance version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <WhiteBalanceStyle/><!--req, xs:string, "auto, manual, indoor, outdoor, autotrace, onece, sodiumlight,
mercurylight,auto0, atuo1, fluorescent, natural, warm, incandescent"-->
 <WhiteBalanceRed/><!--dep,xs:integer, this node depends on <WhiteBalanceStyle>-->
 <WhiteBalanceBlue/><!--dep,xs:integer, this node depends on <WhiteBalanceStyle>-->
</WhiteBalance>

Remarks
Setting WhiteBalanceRed and WhiteBalanceBlue is available only when WhiteBalanceStyle is set
to "manual".

16.2.315 XML_WirelessServer
WirelessServer message in XML format
<WirelessServer version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <wifiApEnabled><!--opt,xs:boolean,"true,false"--></wifiApEnabled>
 <broadcastEnabled><!--opt,xs:boolean,"true,false"--></broadcastEnabled>
 <wlanShareEnabled><!--opt,xs:boolean,"true,false"--></wlanShareEnabled>
 <ssid><!--opt, xs:string--></ssid>
 <WirelessSecurity><!--req-->
  <securityMode>
   <!--opt, xs: string, security mode: "disable,WEP,WPA-personal,WPA2-personal,WPA-RADIUS,WPA-enterprise,WPA2-
enterprise"-->
  </securityMode>
  <WEP><!--dep, depends on <securityMode>-->
   <authenticationType>
    <!--req, xs: string, authentication type: "open,sharedkey,auto"-->
   </authenticationType>
   <defaultTransmitKeyIndex>
    <!--req, xs: integer-->
   </defaultTransmitKeyIndex>
   <wepKeyLength><!--opt, xs: integer, the key length should be 64 and 128--></wepKeyLength>
   <EncryptionKeyList>
    <encryptionKey>
      <!--req, xs: hexBinary, WEP encryption key in hexadecimal format-->
    </encryptionKey>
   </EncryptionKeyList>
  </WEP>
  <WPA><!--dep, depends on <securityMode>-->
   <algorithmType>
    <!--req, xs: string, algorithm type: "TKIP,AES,TKIP/AES"-->
   </algorithmType>
   <sharedKey><!--opt, xs: string, shared key used in WPA--></sharedKey>
   <wpaKeyLength><!-- opt, xs: integer, the key length is between 8 and 63--></wpaKeyLength>
   <defaultPassword><!--opt, xs: boolean--></defaultPassword>
  </WPA>
 </WirelessSecurity>
 <DHCPEnabled><!--opt,xs:boolean,"true,false"--></DHCPEnabled>
 <ipVersion><!--opt, xs:string, opt="v4,v6"--></ipVersion>
 <HostIpAddress><!--opt-->
  <ipAddress><!--dep, xs:string--></ipAddress>
  <ipv6Address><!--dep, xs:string--></ipv6Address>
 </HostIpAddress>
 <IPMask><!--opt-->
  <subnetMask><!--dep, xs:string, subnet mask for IPv4 address--></subnetMask>
  <bitMask><!--dep, xs:integer, bitmask IPv6 address--></bitMask>
 </IPMask>
 <AddressPool><!--opt-->
  <startIPV4Address><!--dep, xs:string--></startIPV4Address>
  <endIPV4Address><!--dep, xs:string--></endIPV4Address>
  <startIPV6Address><!-- dep, xs:string--></startIPV6Address>

  <endIPV6Address><!--dep, xs:string--></endIPV6Address>
 <AddressPool>
 <DNSAddressList><!--opt-->
  <DNSAddress><!--opt>
   <id><!--opt,xs:string,start from 1--></id>
   <ipAddress><!--dep, xs:string--></ipAddress>
   <ipv6Address><!--dep, xs:string--></ipv6Address>
  </DNSAddress>
 </DNSAddressList>
 <GatewayAddress>
  <ipAddress><!--dep, xs:string--></ipAddress>
  <ipv6Address><!--dep, xs:string--></ipv6Address>
 <GatewayAddress>
 <wifiApModeType>
  <!--opt, xs: string, current wireless Access Point (AP) mode: "true,false,auto", if this node is returned, it indicates
that the device supports auto mode-->
 </wifiApModeType>
</WirelessServer>

Remarks
For Client supports auto AP, the node <<wifiApModeType> is valid; for Client does not supports
auto AP, the node <wifiApEnabled> is valid; the values of these two nodes will effect each other,
and when <wifiApModeType> equals to "auto", the value of <wifiApEnabled> is "true".

16.2.316 XML_WirelessServerStatus
WirelessServerStatus message in XML format
<WirelessServerStatus version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <wifiApEnabled>
  <!--dep, xs:boolean-->
 </wifiApEnabled>
 <linkDevices>
  <!--dep, xs:integer, maximum number of linked devices-->
 </linkDevices>
 <DeviceInfoList>
  <!--opt-->
  <DeviceInfo>
    <!--opt-->
    <IpAddress>
     <!--req-->
     <ipAddress>
      <!--dep, xs:string-->
     </ipAddress>
     <ipv6Address>
      <!--dep, xs:string-->
     </ipv6Address>
    </IpAddress>
    <hostName>
     <!--opt, xs:string-->

   </hostName>
   <macAddress>
    <!--opt, xs:string-->
   </macAddress>
  </DeviceInfo>
 </DeviceInfoList>
</WirelessServerStatus>

16.2.317 XML_WirelessStatus
WirelessStatus message in XML format
<WirelessStatus version="1.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled>
  <!--dep, xs:boolean-->
 </enabled>
 <connectionEnabled>
  <!--dep, xs:boolean-->
 </connectionEnabled>
 <IpAddress>
  <!--req-->
  <ipAddress>
   <!--dep, xs:string-->
  </ipAddress>
  <ipv6Address>
   <!--dep, xs:string-->
  </ipv6Address>
 </IpAddress>
 <SubnetMask>
  <!--req-->
  <ipAddress>
   <!--dep, xs:string-->
  </ipAddress>
  <ipv6Address>
   <!--dep, xs:string-->
  </ipv6Address>
 </SubnetMask>
 <RouterAddress>
  <!--req-->
  <ipAddress>
   <!--dep, xs:string-->
  </ipAddress>
  <ipv6Address>
   <!--dep, xs:string-->
  </ipv6Address>
 </RouterAddress>
 <DNSAddressList>
  <!--opt-->
  <DNSAddress>
   <!--opt-->
   <id>

    <!--opt, xs:string, DNS address ID, which starts from 1-->
   </id>
   <ipAddress>
    <!--dep, xs:string-->
   </ipAddress>
   <ipv6Address>
    <!--dep, xs:string-->
   </ipv6Address>
  </DNSAddress>
 </DNSAddressList>
</WirelessStatus>

16.2.318 XML_Wireless
Wireless message in XML format
<Wireless version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <enabled><!--req, xs:boolean--></enabled>
 <wirelessNetworkMode>
  <!--opt, xs:string, "infrastructure,adhoc"-->
 </wirelessNetworkMode>
 <channel><!--opt, xs:string, "1 to 14,auto"--></channel>
 <ssid><!--opt, xs:string--></ssid>
 <wmmEnabled><!--opt, xs:boolean--></wmmEnabled>
 <WirelessSecurity><!--opt-->
  <securityMode>
   <!--opt, xs:string, "disable,WEP,WPA-personal,WPA2-personal,WPA-RADIUS, WPA-enterprise,WPA2-enterprise"-->
  </securityMode>
  <WEP><!--dep, depends on <securityMode>-->
   <authenticationType>
    <!--req, xs:string, "open,sharedkey,auto"-->
   </authenticationType>
   <defaultTransmitKeyIndex><!--req, xs:integer--></defaultTransmitKeyIndex>
   <wepKeyLength><!--opt, xs:integer "64,128"--></wepKeyLength>
   <EncryptionKeyList>
    <encryptionKey>
      <!--req, xs:hexBinary, WEP encryption key in hexadecimal format-->
    </encryptionKey>
   </EncryptionKeyList>
  </WEP>
  <WPA><!--dep, depends on <securityMode>-->
   <algorithmType><!--req, xs:string, "TKIP,AES,TKIP/AES"--></algorithmType>
   <sharedKey><!--req, xs:string, pre-shared key used in WPA--></sharedKey>
   <wpaKeyLength><!--req, xs: integer, "8-63"--></wpaKeyLength>
  </WPA>
 </WirelessSecurity>
 <workScene><!--opt, xs:string, "computerRoom,monitorTerminal"--></workScene>
 <protocol><!--req,xs:string, "802.11ac"--></protocol>
 <protocolRealTime><!--req,xs:string, real-time mode--></protocolRealTime>
 <hideSsid><!--opt, xs:boolean--></hideSsid>
 <ChannelConfig><!--opt-->

  <width><!--opt, xs:string, "auto,20,40,80", bandwidth, unit: MHz--></width>
  <autoWidth>
   <!--dep,ro, xs:string, it is valid only when width is "auto"-->
  </autoWidth>
  <channel><!--opt, dep, xs:string, channel frequency, unit: MHz--></channel>
  <autoChannel><!--dep,ro,xs:string, it is valid only when channel is "auto"--></autoChannel>
  <transmitPower> <!--opt, xs:integer, "9,12,15,18,21,24,27", power, unit: dBm--><transmitPower>
  <transmitPowerRealTime> <!--opt, xs:integer, real-time power, unit: dBm--><transmitPowerRealTime>
  <countryID><!--opt,xs:integer，country code--></countryID>
 </ChannelConfig>
</Wireless>

16.2.319 XML_VCAResource
VCAResource message in XML format
<VCAResource version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <type>
  <!--req, xs:string,
"basicBehavior,fullBehavior,facesnapBehavior,facesnap,TFS,smartVehicleDetection,smartHVTDetection,smart,judicial,s
mart264AndRoadDetection,smart264AndFaceDetection,smart264AndHeatMap,smartIntelligentMonitor,smartTrafficD
ataCollection,roadDetection,humanRecognition,perimeterCapture,vehicleDetection,HVTDetection,mixedTargetDetecti
on,trackingCaptureMode,nonTrackingCaptureMode,close,faceHumanModelingContrast,cityManagement,teacherBeha
vior,12MPLiveView,personQueueDetection,verticalPeopleCounting,safetyHelmet"-->
 </type>
</VCAResource>

16.2.320 XML_VideoCap
VideoCap message in XML format
<VideoCap version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <videoInputPortNums><!--opt, xs: integer--><videoInputPortNums>
 <videoOutputPortNums><!--opt, xs: integer--><videoOutputPortNums>
 <isSupportHeatmap><!--opt, xs: boolean, whether to support heat map function--></isSupportHeatmap>
 <isSupportCounting><!--opt, xs: boolean--></isSupportCounting>
 <countingType><!--dep, xs: string, "human,object"--></countingType>
 <isSupportPreviewSwitch><!--opt, xs: boolean, whether to support live view switch--></isSupportPreviewSwitch>
 <isSupportRecodStatus>
  <!--opt, xs: boolean, whether supports getting recording status-->
 </isSupportRecodStatus>
 <isSupportPrivacyMask>
  <!--opt, xs: boolean, whether supports priavte mask function-->
 </isSupportPrivacyMask>
 <isSupportBinocularPreviewSwitch>
   <!--opt, xs: boolean, whether supports auto-switch during the live view of dual lens camera-->
 </isSupportBinocularPreviewSwitch>
 <isSupportCalibCheck>
  <!--opt, xs: boolean, whether supports calibration verification-->

  </isSupportCalibCheck>
  <isSupportPIP><!--opt, xs: boolean, "true, false"--></isSupportPIP>
  <channelFlexible opt ="name,enable,online,linknum">
   <!--capability of getting channel status by condition-->
  </channelFlexible >
  <isSupportFocusVideoMode>
   <!--opt, xs: boolean, video focus mode for installation and debug-->
  </isSupportFocusVideoMode>
  <isSupportExternalChannel>
   <!--opt, xs: boolean, whether supports extending analog channel-->
  </isSupportExternalChannel>
  <isSupportMultiChannelCounting>
   <!--opt, xs: boolean, whether supports people counting of multiple channels-->
  </isSupportMultiChannelCounting>
  <isSupportCountingCollection>
   <!--opt, xs:boolean, whether supports people counting data replenishment-->
  </isSupportCountingCollection>
  <isSupportHeatmapCollection>
   <!--opt, xs:boolean, whether supports heat map data replenishment-->
  </isSupportHeatmapCollection>
  <OSDLanguage opt="GBK,EUC-KR" def="GBK"/>
  <isSupportInitLens><!--req, xs:boolean, whether to support initializing lens--><isSupportInitLens>
  <isSupportOneFocus><!--req, xs:boolean, whether to support one-touch focusing--><isSupportOneFoucs>
  <notSupportFocus><!--req, xs:boolean, the focus capability is not supported--><notSupportFoucs>
  <notSupportIris><!--req, xs:boolean, the iris capability is not supported--><notSupportIris>
  <isSupportCapturePicOverlays><!--opt, xs:boolean, whether to support text overlay on the captured picture--></
isSupportCapturePicOverlays>
  <isSupportMergePicOverlays><!--opt, xs:boolean, whether to support text overlay on the composite picture--></
isSupportMergePicOverlays>
</VideoCap>

16.2.321 XML_VideoInput
VideoInput message in XML format
<VideoInput version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <VideoInputChannelList/><!--op, see details in the message of XML_VideoInputChannelList-->
</VideoInput>

See Also
XML_VideoInputChannelList

16.2.322 XML_VideoInputChannel
VideoInputChannel message in XML format
<VideoInputChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id>
  <!--req, xs:string-->

 </id>
 <inputPort>
  <!--req, xs:string-->
 </inputPort>
 <videoInputEnabled>
  <!--opt, xs:boolean-->
 </videoInputEnabled>
 <name>
  <!--opt, xs:string-->
 </name>
 <videoFormat>
  <!--opt, xs:string, "PAL, NTSC"-->
 </videoFormat>
 <portType>
  <!--opt, xs:string, "SDI, OPT, VGA, HDMI, YPbPr"-->
 </portType>
 <resDesc>
  <!--opt, xs:string-->
 </resDesc>
</VideoInputChannel>

16.2.323 XML_VideoInputChannelList
VideoInputChannelList message in XML format
<VideoInputChannelList version="2.0"
xmlns="http://www.isapi.org/ver20/XMLSchema">
 <VideoInputChannel/><!--opt, see details in the message of XML_VideoInputChannel-->
</VideoInputChannelList>

See Also
XML_VideoInputChannel

16.2.324 XML_VideoOutput
VideoOutput message in XML format
<VideoOutput version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <VideoOutputChannelList/><!--opt, refer to the message XML_VideoOutputChannelList for details-->
</VideoOutput>

See Also
XML_VideoOutputChannelList

16.2.325 XML_VideoOutputChannel
VideoOutputChannel message in XML format
<VideoOutputChannel version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <id><!--req, xs: string; ID--></id>
 <type><!--req, xs: string, video output type: "VGA,CVBS,HDMI,Spot,SDI"--></type>
 <menu><!--dep, read-only-->
  <mirrorMenu><!--req, xs: boolean--></mirrorMenu>
 </menu>
 <mode><!--opt,xs:string, video output mode: "close,clip,scale,open,SDI_1080P25,
…,HDMI_1080P,HDMI_720P,HDMI_2160P"--></mode>
 <resolution><!--opt, xs: string; video solution: "1920*1080/60HZ,1280*720/50HZ,…"--></resolution>
</VideoOutputChannel>

16.2.326 XML_VideoOutputChannelList
VideoOutputChannelList message in XML format
<VideoOutputChannelList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <VideoOutputChannel/><!--opt, refer to the message XML_VideoOutputChannel for details-->
</VideoOutputChannelList>

See Also
XML_VideoOutputChannel

16.2.327 XML_VideoOverlay
VideoOverlay message in XML format
<VideoOverlay version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <normalizedScreenSize><!--req, reference value of the region coordinates, which is 704*576 for PAL and 704*480 for
NTSC-->
  <normalizedScreenWidth><!--ro, req, xs: integer--></normalizedScreenWidth>
  <normalizedScreenHeight><!--ro, req, xs: integer--></normalizedScreenHeight>
 </normalizedScreenSize>
 <attribute><!--opt, OSD properties-->
  <transparent><!--req, xs: boolean--></transparent>
  <flashing><!--req, xs: boolean--><flashing>
 </attribute>
 <TextOverlayList>
  <TextOverlay><!--text overlay parameter-->
   <id><!-- req, xs: string; text ID--></id>
   <enabled><!--req, xs: boolean, whether to enable text overlay--></enabled>
   <positionX><!--req, xs: float, x-coordinate--></positionX>
   <positionY><!-- req, xs: float, y-coordinate--></positionY>
   <displayText><!-- req, xs: string, displayed text contents--></displayText>

  </TextOverlay>
 </TextOverlayList>
 <DateTimeOverlay>
  <enabled><!--req, xs: boolean, whether to enable date and time overlay--></enabled>
  <positionX><!--req, xs: integer; x-coordinate--></positionX>
  <positionY><!--req, xs: integer; y-coordinate--></positionY>
  <dateStyle>
   <!--opt, xs: string, date display format: YYYY-MM-DD, MM-DD-YYYY, DD-MM-YYYY, CHR-YYYY-MM-DD, CHR-MM-DD-
YYYY, CHR-DD-MM-YYYY, CHR-YYYY/MM/DD, CHR-MM/DD/YYYY, CHR-DD/MM/YYYY-->
  </dateStyle>
  <timeStyle><!--opt, xs: string, time format: 12hour, 24hour--></timeStyle>
  <displayWeek><!--opt, xs: boolean, wehther to display day of the week--></displayWeek>
 </DateTimeOverlay
 <channelNameOverlay>
  <enabled><!--req, xs: boolean, whether to enable channel name overlay--></enabled>
  <positionX><!--req, xs: integer; x-coordinate--></positionX>
  <positionY><!--req, xs: integer; y-coordinate--></positionY>
 </channelNameOverlay>
 <fontSize opt="adaptive,16*16,32*32,48*48,64*64,80*80,96*96,112*112,128*128"><!--opt, xs: string, font size of
video OSD: "adaptive,16*16,32*32,48*48,64*64,80*80,96*96,112*112,128*128", unit: pixel. Currently only 16*16
and 32*32 are supported--></fontSize>
 <frontColorMode opt="auto,customize"><!--opt, string, front color mode: "auto,customize"--></frontColorMode>
 <frontColor><!--dep, xs: hexBinary, front color--></frontColor>
 <alignment><!--opt, xs:string, "customize,alignRight,alignLeft"--></alignment>
 <BatteryPowerOverlay/><!--opt-->
 <DeviceStatusDisplay>
  <!--opt, display control of the device status on the video of portable speed dome-->
  <batteryCapacityDisplay>
   <!--opt, xs:boolean, whether to display battery capacity-->
  </batteryCapacityDisplay>
  <chargingStatusDisplay>
   <!--opt, xs:boolean, whether to display charging status-->
  </chargingStatusDisplay>
  <bluetoothStatusDisplay>
   <!--opt, xs:boolean, whether to display bluetooth status-->
  </bluetoothStatusDisplay>
  <dialStatusDisplay>
   <!--opt, xs:boolean, whether to display dial-up status-->
  </dialStatusDisplay>
 </DeviceStatusDisplay>
 <boundary><!--opt, xs:integer--></boundary>
 <alignment><!--opt, xs: string, alignment mode: "customize, alignRight, alignLeft"--></alignment>
 <publicSecurity><!--req, xs: boolean--></publicSecurity>
</VideoOverlay>

16.2.328 XML_VideoSourceActivation
XML Message about Parameters of Activating Network Device
<?xml version="1.0" encoding="utf-8"?>
<VideoSourceActivation version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">

 <ramerat><!--required, xs:string--></ramerat>
 <passwordType>
  <!--required, xs:string, password types: "default"-NVR password, "selfDefine", "IPCActivatePasswd"-activation
password-->
 </passwordType>
 <password><!--depend, xs:string--></password>
 <ActivationDevice>
  <mode><!--required, xs:string, "channel, descriptor"--></mode>
  <channel><!--depend-->
   <dynVideoInputChannelID><!--required, xs:integer--></dynVideoInputChannelID>
  </channel>
  <descriptor><!--depend-->
   <macAddress><!--required, xs:string--></macAddress>
   <addressingFormatType><!--required, xs:string, "ipaddress, hostname"--></addressingFormatType>
   <ramerat><!--depend, xs:string--></ramerat>
   <ipAddress><!--depend, xs:string--></ipAddress>
   <ipv6Address><!--depend, xs:string--></ipv6Address>
   <portNo><!--required, xs:integer--></portNo>
   <proxyProtocol><!--required, xs:string, "HIKVISION, SONY, ISAPI, ONVIF, …"--></proxyProtocol>
  </descriptor>
 </ActivationDevice>
</VideoSourceActivation>

16.2.329 XML_VideoSourceActivationCapability
XML Message about Capability of Activating Network Device
<?xml version="1.0" encoding="utf-8"?>
<VideoSourceActivationCapability version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <ActivateByChannel>
  <proxyProtocol opt="HIKVISION"/>
 </ActivateByChannel>
 <ActivateByAddress>
  <proxyProtocol opt="HIKVISION"/>
 </ActivateByAddress>
</VideoSourceActivationCapability>

16.2.330 XML_VideoSourceList
XML Message about Searched Network Devices
<VideoSourceList version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <VideoSourceDescriptor><!--list-->
  <id><!--req, xs: string;id--></id>
  <proxyProtocol><!--req, xs: string, "HIKVISION, SONY, ISAPI, ONVIF"--></proxyProtocol>
  <addressingFormatType><!--req, xs: string, address type: "ipaddress, hostname"--></addressingFormatType>
  <hostName><!--dep, xs: string--></hostName>
  <ipAddress><!--dep, xs: string--></ipAddress>
  <subnetMask><!--opt, xs: string, subnet mask for IPv4 address--></subnetMask>

  <ipv6Address><!--dep, xs: string--></ipv6Address>
  <bitMask><!--opt, xs: integer, bitmask IPv6 address--></bitMask>
  <serialNumber><!--opt, xs: string--></serialNumber>
  <macAddress><!--opt, xs: string--></macAddress>
  <firmwareVersion><!--opt, req, xs: string--></firmwareVersion>
  <managePortNo><!--opt, xs: integer--></managePortNo>
  <userName><!--opt, xs: string--></userName>
  <password><!--opt, xs: string--></password>
  <srcInputPortNums><!--req, xs: integer--></srcInputPortNums>
  <deviceID><!--dep, xs: string--></deviceID>
  <deviceModel><!-- opt, xs: string, device model--></deviceModel>
 </VideoSourceDescriptor>
</VideoSourceList>

16.2.331 XML_ZoomFocus
ZoomFocus message in XML format
<ZoomFocus version="2.0" xmlns="http://www.isapi.org/ver20/XMLSchema">
 <pqrsZoom/><!--opt, xs: integer, zoom coordinates of Sony zoom camera module-->
 <mnstFocus/><!--opt, xs: integer, focus coordinates of Sony zoom camera module-->
</ZoomFocus>

                           Appendix A. Appendixes

A.1 Log Types for ISAPI
There are four major log types, i.e., alarm log, exception log, operation log, and event log. And
each major type contains multiple minor types, see details in the following contents.

Alarm Logs

                   Log Type                                           Description
shortCircuit                                    Short Circuit Alarm
brokenCircuit                                   Open Circuit Alarm
alarmReset                                      Alarm Reset
alarmNormal                                     Return to Normal
passwordError                                   Incorrect Password (3 Tmes in a Row)
idCardIllegally                                 Invalid Card ID
keyPADRemove                                    Keypad Tampered
keyPADRemoveRestore                             Keypad Restored
devRemove                                       Device Tampered
devRemoveRestore                                Device Restored
belowAlarmLimit1                                Sensor Value is Lower than Alarm Limit Value 1
belowAlarmLimit2                                Sensor Value is Lower than Alarm Limit Value 2
belowAlarmLimit3                                Sensor Value is Lower than Alarm Limit Value 3
belowAlarmLimit4                                Sensor Value is Lower than Alarm Limit Value 4
aboveAlarmLimit1                                Sensor Value is Higher than Alarm Limit Value 1
aboveAlarmLimit2                                Sensor Value is Higher than Alarm Limit Value 2
aboveAlarmLimit3                                Sensor Value is Higher than Alarm Limit Value 3
aboveAlarmLimit4                                Sensor Value is Higher than Alarm Limit Value 4
UrgencyBtnON                                    Panic Button Triggered
UrgencyBtnOFF                                   Panic Button Restored
virtualDefenceBandit                            Virtual Zone Burglary Alarm
virtualDefenceFire                              Virtual Zone Fire Alarm

                  Log Type                                   Description
virtualDefenceUrgent                    Virtual Zone Panic Alarm
motDetStart                             Motion Detection Alarm Started
motDetStop                              Motion Detection Alarm Stopped
hideAlarmStart                          Device Blocked
hideAlarmStop                           Device Blocking Alarm Restored
UPSAlarm                                UPS Alarm
electricityMeterAlarm                   Coulombmeter Alarm
switchPowerAlarm                        Switch Power Supply Alarm
GasDetectSys                            Gas Detection Alarm
transformerTempAlarm                    Transformer Temperature Alarm
tempHumiAlarm                           Temperature and Humidity Sensor Alarm
UPSAlarmRestore                         UPS Alarm Restored
electricityMeterAlarmRestore            Coulombmeter Alarm Restored
switchPowerAlarmRestore                 Switch Power Supply Alarm Restored
GasDetectSysRestore                     Gas Detection Alarm Restored
transformerTempAlarmRestor              Transformer Temperature Alarm Restored
e
tempHumiAlarmRestore                    Temperature-Humidity Sensor Alarm Restored
waterLevelSensorAlarm                   Temperature-Humidity Sensor Alarm Restored
waterLevelSensorAlarmRestore            Flood Sensor Restored
dustNoiseAlarm                          Dust and Noise Sensor Alarm
dustNoiseAlarmRestore                   Dust and Noise Sensor Alarm Restored
environmentalLogger                     Environmental Data Collector Alarm
environmentalLoggerAlarm                Environmental Data Collector Restored
triggerTemper                           Detector Tampered
triggerTemperRestore                    Detector Restored
emergencyCallHelp                       Panic Alarm
emergencyCallHelpRestore                Panic Alarm Restored
consult                                 Consultation Alarm

                 Log Type                                    Description
consultRestore                            Consultation Alarm Restored
deviceMoveAlarm                           Device Motion Alarm
deviceMoveAlarmRestore                    Device Motion Alarm Restored
earlyWarningAlarm                         Early Warning Zone Alarm
earlyWarningAlarmRestore                  Early Warning Zone Restored
warningAlarm                              Warning Zone Alarm
warningAlarmRestore                       Warning Zone Restored
wirelessOutputModTamperEvident            Wireless Output Expander Tampered
wirelessOutputModTamperEvidentReset       Wireless Output Expander tamper Restored
wirelessRepeaterTamperEvident             Wireless Repeater Tampered
wirelessRepeaterTamperEvidentReset        Wireless Repeater tamper Restored
wirelessSirenTamperEvident                Wireless Siren Tampered
wirelessSirenTamperEvidentReset           Wireless Siren Tamper Restored
wirelessKeypadTamperEvident               Wireless Keypad Tampered
wirelessKeypadTamperEvidentReset          Wireless Keypad Tamper Restored
wirelessCardReaderTamperEvident           Wireless Card Reader Tampered
wirelessCardReaderTamperEvidentReset      Wireless Card Reader Tamper Restored
softZoneMedicalAlarm                      Virtual Zone Medical Alarm
accessControllerEvent                     Access Controller Event
videoIntercomEvent                        Video Intercom Event
GJDEvent                                  GJD Security Control Panel Event
LuminateEvent                             LUMINITE Security Control Panel Event
OPTEXEvent                                OPTEX Security Control Panel Event
cameraDetectorEvent                       Detector Event
securityControlPanelEvent                 Security Control Panel Event
RS-485AlarmInputModuleEvident             RS-485 Zone Module Tampered
RS-485AlarmInputModuleTamperReset         RS-485 Zone Module Tampering Reset
RS-485WirelessReceiverTamperEvident       RS-485 Wireless Receiver Module Tampered
RS-485WirelessReceiverTamperEvidentReset RS-485 Wireless Receiver Module Tampering Reset

                    Log Type                                           Description
dredgerDetectionAlarm                            Dredger Detection Alarm
crossLineAlarm                                   Line Crossing Alarm
crossLineAlarmRestore                            Line Crossing Alarm Restored
HFPDAlarmStart                                   High Frequently Appeared Person Alarm Started
HFPDAlarmStop                                    High Frequently Appeared Person Alarm Stopped
LFPDAlarmStart                                   Low Frequency Person Alarm Started
LFPDAlarmStop                                    Low Frequency Person Alarm Stopped

Exception Logs

         Log Type                                          Description
powerOn                        Power on
powerOff                       Power off
WDTReset                       WDT Reset
lowBatteryVoltage              Low Battery Voltage
ACLoss                         AC Power Disconnected
ACRestore                      AC Power Restored
RTCException                   RTC Real-​time Clock Exception
netFailure                     Network Disconnected
netRestore                     Network Connected
telLineBroken                  Telephone Line Disconnected
telLineRestore                 Telephone Line Connected
expanderBusLoss                Bus Expander Disconnected
expanderBusRestore             Bus Expander Connected
keypadBusLoss                  Keypad Expander Disconnected
keypadBusRestore               Keypad Expander Connected
sensorFailure                  Analog Sensor Fault
sensorRestore                  Analog Sensor Restored
RS485DisConnect                RS-485 Channel Disconnected
RS485Connect                   RS-486 Channel Connected

           Log Type                                    Description
batteryVoltageRestore      Battery Voltage Restored
wiredNetAbnormal           Wired Network Exception
wiredNetRestore            Wired Network Restored
GPRSAbnormal               GPRS Exception
GPRSRestore                GPRS Restored
3GAbnormal                 3G Network Exception
3GRestore                  3G Network Restored
SIMCardAbnormal            SIM Card Exception
SIMCardRestore             SIM Card Restored
VILost                     Video Loss
illegalAccess              Illegal Login
HDFull                     HDD Full
HDError                    HDD Error
DCDLost                    MODEM Disconnected
IPConflict                 IP Address Conflicted
netbroken                  Network Disconnected
recError                   Recording Error
VIError                    Video Input Exception(Only for Analog Channel)
formatHDDError             Remote HDD Formatting Failed
USBError                   USB Communication Error
USBRestore                 USB Communication Error Restored
printError                 Printer Error
printRestore               Printer Error Restored
subsystemCommunication Sub-board Communication Error
Error
IPCIPconflict              Network Camera IP Address Conflicted
VIMisMatch                 Video Standard Mismatches
MCURestart                 MCU Restarted
GprsMouleFault             GPRS Module Fault

         Log Type                                       Description
telephoneFault            Telephone Module Fault
wifiAbnormal              Wi-Fi Exception
wifiRestore               Wi-Fi Restored
RFAbornal                 RF Exception
RFRestore                 RF Restored
detectorOnline            Detector Connected
detectorOffline           Detector Disconnected
detectorBatteryNormal     Detector Battery Restored
detectorBatteryLow        Detector Battery Low
dataTrafficOverflow       Cellular Network Data Exceeded
radarSignalFault          Radar Transmitter Fault
radarSignalFaultRestore   Radar Transmitter Restored
wirelessOutputModOffline Wireless Output Expander Disconnected
wirelessOutputModOnline Wireless Output Expander Connected
wirelessRepeaterOffline   Wireless Repeater Disconnected
wirelessRepeaterOnline    Wireless Repeater Connected
triggerOffline            Trigger Disconnected
triggerOnline             Trigger Connected
wirelessSirenOffline      Wireless Siren Disconnected
wirelessSirenOnline       Wireless Siren Connected
sirenLowPower             Siren Battery Low
sirenPowerRecovery        Siren Battery Restored
ipcDisconnect             Network Camera Disconnected
ipcConnectRecovery        Network Camera Connected
sendMailFailed            Sending Email Failed
eventUploadException      Uploading Event Failed or Uploaded Event Lost
keyfobLowPower            Low Keyfob Battery
keyfobPowerRecovery       Normal Keyfob Battery
detectorOvertime          Detector Heartbeat Timed Out

        Log Type                                      Description
detectorOvertimeRecover Detector Heartbeat Timeout Restored
y
wSirenOvertime            Wireless Siren Heartbeat Timed Out
wSirenOvertimeRecovery    Wireless Siren Heartbeat Timeout Restored
wOutputOvertime           Wireless Output Module Heartbeat Timed Out
wOutputOvertimeRecover Wireless Output Module Heartbeat Timeout Restored
y
wRepeaterOvertime         Wireless Repeater Heartbeat Timed Out
wRepeaterOvertimeRecov Wireless Repeater Heartbeat Timeout Restored
ery
rfJamming                 RF Wireless Communication Blocked
rfJammingRecovery         RF Wireless Communication Blocking Restored
batteryMiss               Storage Battery Loss
batteryMissRecovery       Storage Battery Restored
ARCUploadFailed           ARC Uploading Failed
ARCUploadRecovery         ARC Uploading Restored
wirelessKeypadOffline     Wireless Keypad Disconnected
wirelessKeypadOnline      Wireless Keypad Connected
wirelessCardReaderOffline Wireless Card Reader Disconnected
wirelessCardReaderOnline Wireless Card Reader Connected
keypadLowPower            Low Keypad Battery
keypadLowPowerRecovery Low Keypad Battery Recovered
cardReaderLowPower        Low Card Reader Battery
cardReaderLowPowerReco Low Card Reader Battery Recovered
very
wKeypadOvertime           Wireless Keypad Heartbeat Timed Out
wKeypadOvertimeRecover Wireless Keypad Heartbeat Timeout Recovered
y
wCardReaderOvertime       Wireless Card Reader Heartbeat Timed Out

          Log Type                                   Description
wCardReaderOvertimeRec Wireless Card Reader Heartbeat Timeout Recovered
overy
RS-                     RS-485 Zone Module Offline
485AlarmInputModuleDisc
onnected
RS-                    RS-485 Zone Module Online
485AlarmInputModuleCon
nected
RS-                      RS-485 Wireless Receiver Module Offline
485WirelessReceiverDisco
nnected
RS-                     RS-485 Wireless Receiver Module Online
485WirelessReceiverConn
ected
keypadDisconnected        Keypad Offline
keypadConnected           Keypad Online
overvoltage               High Supply Voltage
undervoltage              Low Supply Voltage
highHDTemperature         HDD High Temperature
lowHDTemperature          HDD Low Temperature
hdImpact                  HDD Impact
hdBadBlock                HDD Bad Sector
severeHDFailure           HDD Severe Fault

Operation Logs

          Log Type                                   Description
guard                     Normal Arming
unguard                   Normal Disarming
bypass                    Bypass
duressAccess              Duress
localReboot               Local Reboot
remoteReboot              Remote Reboot

        Log Type                                           Description
localUpgrade               Local Upgrade
remoteUpgrade              Remote Upgrade
recoveryDefultParam        Restore Default Settings
outpulAlarm                Remote Alarm Output Control
accessOpen                 Access Control: Open
accessClose                Access Control : Closed
sirenOpen                  Siren: On
sirenClose                 Siren: Off
modZoneConfig              Zone Settings
modAlarmoutConfig          Alarm Output Settings
modAnalogConfig            Sensor Settings
RS485Config                RS-485 Channel Settings
phoneConfig                Dialing Settings
addAdmin                   Added Administrator
modAdminParam              Edited Administrator
delAdmin                   Deleted Administrator
addNetUser                 Added DVR/NVR Operator
modNetUserParam            Edited DVR/NVR Operator
delNetUser                 Deleted DVR/NVR Operator
addOperator                Added Camera Operator
modOperatorPw              Edited Camera Operator Password
delOperator                Deleted Camera Operator Password
addKeyPadUser              Added Keypad/Card Reader User
delKeyPadUser              Deleted Keyboard/Card Reader User
remoteUserLogin            Remote Login
remoteUserLogout           Remote Logout
remoteGuard                Remote Arming
remoteUnguard              Remote Disarming
modHostConfig              Edited Control Panel Settings

          Log Type                                   Description
restoreBypass            Bypass Restored
alarmOutOpen             Turned on Output
alarmOutClose            Turned off Output
modSubsystemParam        Edited Subsystem Parameters
groupBypass              Group Bypass
groupBypassRestore       Group Bypass Restored
modGprsParam             Edited GPRS Parameters
modNetReportParam        Edited Network Report Settings
modReportMode            Edited Uploading Mode
modGatewayParam          Edited Access Control Settings
remoteStartRec           Remote: Started Recording
remoteStopRec            Remote: Stopped Recording
transChanStart           Transparent Transmission Started
transChanStop            Transparent Transmission Stopped
startVoiceTalk           Two-way Audio Started
stopVoiceTalk            Two-way Audio Terminated
remotePlayByFile         Remote: Playback or Downloaded by File
remotePlayByTime         Remote: Playback by Time
remotePTZCtrl            Remote: PTZ Control
remoteLockFile           Remote: Locked File
remoteUnlockFile         Remote: Unlocked File
remoteFormatHd           Remote: Formatted HDD
remoteDownloadCfgFile    Remote: Exported Configuration Files
remoteUploadCfgFile      Remote: Imported Configuration Files
remoteDownloadRecFile    Remote: Exported File
stayArm                  Stay Arming
quickArm                 Instant Arming
keyswitchArm             Key Zone Arming
keyswitckDisarm          Key Zone Disarming

        Log Type                                         Description
clearAlarm                Alarm Cleared
modFaultConfig            Edited System Fault Settings
modAlarmOutConfig         Edited Event Alarm Output Settings
searchExternalModule      Searched for External Module
registerExternalModule    Re-registered External Module
closeKeypadAlarm          Disabled Keypad Beep
mod3GConfig               Edited Mobile Parameters
modPrintConfig            Edited Printer Parameters
SDCardFormat              Formatted SD Card
upgradeSubsystem          Upgraded Sub-board
planArmConfig             Arming/Disarming Schedule Configuration
phoneArm                  SMS Arming
phoneStayArm              SMS Stay Arming
phoneQuickArm             SMS Instant Arming
phoneDisarm               SMS Disarming
phoneClearAlarm           SMS Alarm Cleared
whiteConfig               Whitelist Settings
timeTriggerConfig         Enabled/Disabled Trigger Configuration by Schedule
pictureConfig             Capture Settings
tamperConfig              Zone Tamper-Proof Settings
remoteKeypadUpgrade       Remote: Upgraded Keypad
singlePartionArmORDisar   Single-Zone Arming/Disarming
m
cardConfiguration         Card Settings
cardAramORDisarm          Arming/Disarming by Card
expendNetCenterConfig     Extension Network Center Settings
netCardConfig             NIC Settings
DDNSConfig                DDNS Settings
RS485BusConfig            RS-485 Bus Settings

         Log Type                                       Description
RS485BusReRegistration    RS-485 Bus Re-​registration
remoteOpenElectricLock    Remote: Unlocked
remoteCloseElectricLock   Remote: Locked
localOpenElectricLock     Local: Unlocked
localCloseElectricLock    Local: Locked
openAlarmLamp             Remote: Turned On Alarm Lamp
closeAlarmLamp            Remote: Turned Off Strobe
temporaryPassword         Operation Record of Temporary Password
oneKeyAwayArm             One-Push Away Arming
oneKeyStayArm             One-Push Stay Arming
singleZoneArm             Single-Zone Arming
singleZoneDisarm          Single-Zone Disarming
HIDDNSConfig              HiDDNS Settings
remoteKeypadUpdata        Remote: Upgraded Keypad
zoneAddDetector           Added Detector
zoneDelDetector           Deleted Detector
qureyDetectorSignal       Checked Detector Signal Strength on Security Control Panel
qureyDetectorBattery      Checked Detector Remaining Battery on Security Control Panel
setDetectorGuard          Detector Arming
setDetectorUnguard        Detector Disarming
setWifiParm               Wi-Fi Settings
voiceOpen                 Audio On
voiceClose                Mute
functionKeyEnable         Enabled Function Key
functionKeyDisable        Disabled Panel Function Button
readCard                  Swiped Patrol Card
localDeviceActive         Activated Device Remotely
localFactoryDefault       Restored Factory Settings Locally
remoteFactoryDefault      Restored Factory Settings Remotely

          Log Type                                       Description
addWirelessOutputMod      Added Wireless Output Module
delWirelessOutputMod      Deleted Wireless Output Module
addWirelessRepeater       Added Wireless Repeater
delWirelessRepeater       Deleted Wireless Repeater
telListConfig             Mobile Phone Number Settings
searchRFSignal            Checked RF Signal
addWirelessSiren          Added Wireless Siren
delWirelessSiren          Deleted Wireless Siren
flowConfig                Cellular Data Limit Settings
addRemoter                Added Keyfob
delRemoter                Deleted Keyfob
addCard                   Added Card
delCard                   Deleted Card
remoteAddIpc              Added Network Camera
remoteDelIpc              Deleted Network Camera
remoteSetIpc              Edited Network Camera
localAddressFilterConfig/ Local/Remote Address Filter Configuration
remoteAddressFilterConfig
enterProgramMode          Programming Mode Enabled for Keypad
existProgramMode          Programming Mode Disabled for Keypad
localIOTCfgFileInput      Local operation: import IoT configuration file
localIOTCfgFileOutput     Local operation: export IoT configuration file
remoteIOTCfgFileInput     Remote operation: import IoT configuration file
remoteIOTCfgFileOutput    Remote operation: export IoT configuration file
localIOTAdd               Local operation: add IoT channel
remoteIOTAdd              Remote operation: add IoT channel
localIOTDelete            Local operation: delete IoT channel
remoteIOTDelete           Remote operation: delete IoT channel
localIOTSet               Local operation: configure IoT channel

         Log Type                                      Description
remoteIOTSet              Remote operation: configure IoT channel
armWithFault              Armed with Fault
entryDelay                Entering and Exiting Delay
modArmConfig              Edit Arming Parameters
modCertificateStandard    Edit Authentication Standard
entryPaceTest             Pacing Mode Entered
exitPaceTest              Pacing Mode Exited
addNetOperator            Add Operator
modNetOperator            Edit Operator Information
delNetOperator            Delete Operator
addNetInstaller           Add Installer
modNetInstaller           Edit Installer Information
delNetInstaller           Delete Installer
addManufacturer           Add Manufacturer
modManufacturer           Edit Manufacturer Information
delManufacturer           Delete Manufacturer
upgradeSuccessed          Upgraded
upgradeFailed             Upgrading Failed
zoneDisabled              Zone Shielded
localCfgSecurity          Security Parameter Configured Locally
remoteCfgSecurity         Security Parameter Configured Remotely
remoteGetParaSecurity     Security Parameters Obtained Remotely
delRS-485InputModule      RS-485 Zone Module Deleted
delRS-485OutputModule     RS-485 Output Module Deleted
delRS-                    RS-485 Wireless Receiver Module Deleted
485WirelessReceiver
enrollRS-485InputModule   RS-485 Zone Module Registered
enrollRS-                 RS-485 Output Module Registered
485OutputModule

          Log Type                                       Description
delRS-485OutputModule      RS-485 Output Module Deleted
enrollRS-                  RS-485 Wireless Receiver Module Registered
485WirelessReceiver
enrollKeypad               Keypad Registered
delKeypad                  Keypad Deleted
scheduledAngleCalibration Scheduled Angle Calibration
addZone                    Added Zone
modZone                    Edited Zone
delZone                    Deleted Zone
addAlarmLine               Added Trigger Line
modAlarmLine               Edited Trigger Line
delAlarmLine               Deleted Trigger Line
remoteHFPDconfig/          Remote/Local Configuration of Frequently Appeared Person
localHFPDconfig            Detection
remoteLFPDconfig           Remote Configuration of Low Frequency Person Detection

Event Logs

          Log Type                                       Description
SDKSchool                  SDK Synchronization
selfTimeSchool             Time Synchronization by Schedule
insertSubsystem            Plugged in Sub-board
pullOutSubsystem           Pulled out Sub-board
autoArm                    Auto Arming
autoDisarm                 Auto Disarming
triggerOn                  Activated Trigger by Schedule
triggerOff                 Deactivated Trigger by Schedule
autoArmFailed              Auto Arming Failed
autoDisarmFailed           Auto Disarming Failed
triggerOnFailed            Activating Trigger Failed
triggerOffFailed           Deactivating Trigger Failed

           Log Type                                         Description
mandatoryAlarm                Forced Arming
keyPADlocked                  Keypad Locked
keyPADunlocked                Keypad Unlocked
insetUSB                      Plugged in USB Flash Drive
pulloutUSB                    Removed USB Flash Drive
lateRemind                    Late to Disarm
keypadUnlocked                Unlocked Keypad
timeSynchronization           Time Synchronization
armFailed                     Arming Failed
ARCStart                      ARC Connected

Additional Logs

           Log Type                                         Description
doubleVerificationPass        Double Verification Completed
hdFormatStart                 Formatting HDD Started
hdFormatStop                  Formatting HDD Stopped

A.2 Supported Alarm/Event Types
This part lists the alarm or event types that can be received or subscribed via Intelligent Security
API and the corresponding values to be set for getting the details.

    Alarm/Event Type         Value of <type>                     Alarm/Event Details
Intrusion Detection         fielddetection      Refer to Intelligent Security API (Behavior Analysis)
                                                _Developer Guide for details.
Line Crossing Detection     linedetection
Region Entrance             regionEntrance
Detection
Region Exiting Detection regionExiting
Loitering Detection         loitering
People Gathering            group
Detection

   Alarm/Event Type       Value of <type>                   Alarm/Event Details
Fast Moving Detection    rapidMove
Parking Detection        parking
Unattended Baggage       unattendedBagga
Detection                ge
Object Removal           attendedBaggage
Detection
Absence Alarm            leavePosition
People Number Changed peopleNumChang
Alarm                 e
Fast Moving Alarm        running
Violent Motion Alarm     violentMotion
People Falling Down      failDown
Alarm
Overstay Alarm           retention
People Counting Alarm    PeopleCounting     Refer to Intelligent Security API (People Counting) _
                                            Developer Guide for details
Temperature Alarm        thermometry        Refer to Intelligent Security API (Thermal) _
                                            Developer Guide for details
Temperature Difference   temperature
Alarm
Fire Source Detection    fireDetection
Smoke Detection          smokeDetection
Fire and Smoke           smokeAndFireDet
Detection                ection
Ship Detection           shipsDetection
Face Detection Alarm     facedetection      Refer to Intelligent Security API (Facial) _Developer
                                            Guide for details.
Face Capture Alarm       faceCapture
Face Picture Comparison alarmResult
Result
Stranger Detection       whiteFaceContras
Alarm                    t
High Frequently Person   HFPD
Detection

   Alarm/Event Type        Value of <type>                    Alarm/Event Details
Low Frequency Person      LFPD
Detection
Waiting Time Detection    personQueueTim      Refer to Intelligent Security API (Queue
Alarm                     e                   Management) _Developer Guide for details
People Queuing-Up         personQueueCou
Alarm                     nting
Multi-​Target-​Type       mixedTargetDetect Refer to Intelligent Security API (Multi-Target-Type
Detection Alarm           ion               Detection) _Developer Guide for details
Traffic Incident Alarm    AID                 Refer to Intelligent Security API (Traffic
                                              Enforcement) _Developer Guide for details
Traffic Violation         TFS
Enforcement Alarm
Traffic Data Collection   TPS
Alarm
ANPR Alarm                ANPR                Refer to Intelligent Security API (Traffic Capture and
                                              Analysis) _Developer Guide for details
Blacklist and Whitelist   vehicleMatchResu
ANPR Alarm                lt
Vehicle Feature           vehicleRcogResult
Recognition Alarm
Radar Measurement         radarMeasureme
Data                      nt
Heat Map Alarm            heatmap             Refer to Intelligent Security API (Heat Map) _
                                              Developer Guide for details
Face and ID Card          cardMatch           Refer to Intelligent Security API (Access Control on
Recognition Alarm                             Person) _Developer Guide for details
Hot Spare Exception       hotSpare            The alarm or event details will be provided in the
Alarm                                         further versions.
Overspeed Alarm           overSpeed           The alarm or event details will be provided in the
                                              further versions.
Temperature Too Hight     highTempAlarm       The alarm or event details will be provided in the
Alarm                                         further versions.
Acceleration Exception    abnormalAccelerat The alarm or event details will be provided in the
Alarm                     ion               further versions.

   Alarm/Event Type      Value of <type>                  Alarm/Event Details
Collision Alarm         collision          The alarm or event details will be provided in the
                                           further versions.
Rollover Detection      rollover           The alarm or event details will be provided in the
                                           further versions.
Abnormal Driving        abnormalDriving    The alarm or event details will be provided in the
Behavior Detection                         further versions.
GPS Information         GPSUpload          The alarm or event details will be provided in the
Uploaded                                   further versions.
Video Standard          PALMismatch        The alarm or event details will be provided in the
Mismatched                                 further versions.
Sensor Alarm            IO                 The alarm or event details will be provided in the
                                           further versions.
Motion Detection Alarm VMD                 The alarm or event details will be provided in the
                                           further versions.
Video Loss Alarm        videoloss          The alarm or event details will be provided in the
                                           further versions.
Tampering Alarm         shelteralarm       The alarm or event details will be provided in the
                                           further versions.
Defocus Alarm           defocus            The alarm or event details will be provided in the
                                           further versions.
Audio Exception Alarm   audioexception     The alarm or event details will be provided in the
                                           further versions.
Scene Changed Alarm     scenechangedete The alarm or event details will be provided in the
                        ction           further versions.
PIR Alarm               PIR                The alarm or event details will be provided in the
                                           further versions.
HDD Full                diskfull           The alarm or event details will be provided in the
                                           further versions.
HDD Error               diskerror          The alarm or event details will be provided in the
                                           further versions.
Network Disconnected    nicbroken          The alarm or event details will be provided in the
                                           further versions.
IP Address Conflicted   ipconflict         The alarm or event details will be provided in the
                                           further versions.

   Alarm/Event Type         Value of <type>                  Alarm/Event Details
Illegal Login Alarm        illaccess          The alarm or event details will be provided in the
                                              further versions.
PoE Power Exception        poe                The alarm or event details will be provided in the
Alarm                                         further versions.
Video Exception Alarm      videoException     The alarm or event details will be provided in the
                                              further versions.
Recording Exception        recordException    The alarm or event details will be provided in the
Alarm                                         further versions.
HDD Unformatted Alarm diskUnformat            The alarm or event details will be provided in the
                                              further versions.
Supply Voltage Exception voltageinstable      Refer to
Alarm                                         JSON_EventNotificationAlert_voltageinstable for
                                              alarm/event details
HDD High Temperature       highHDTemperatu Refer to
                           re              JSON_EventNotificationAlert_HDDHighTemperatu
                                           reEventMsg for alarm/event details
HDD Low Temperature        lowHDTemperatur Refer to
                           e               JSON_EventNotificationAlert_HDDLowTemperatur
                                           eEventMsg for alarm/event details
HDD Impact                 hdImpact           Refer to
                                              JSON_EventNotificationAlert_HDDImpactEventMs
                                              g for alarm/event details
HDD Bad Sector             hdBadBlock         Refer to
                                              JSON_EventNotificationAlert_HDDBadSectorEvent
                                              Msg for alarm/event details
HDD Severe Fault           severeHDFailure    Refer to
                                              JSON_EventNotificationAlert_HDDSevereFaultEve
                                              ntMsg for alarm/event details
Certificate Expiry Alarm   certificateRevocat Refer to
                           ion                JSON_EventNotificationAlert_CertificateExpiryAlar
                                              mMsg for alarm/event details

A.3 Error Codes in ResponseStatus
The error classification returned by the ResponseStatus message is based on the status codes of
HTTP protocol. 7 kinds of status codes are predefined, including 1 (OK), 2 (Device Busy), 3 (Device
Error), 4 (Invalid Operation), 5 (Invalid Message Format), 6 (Invalid Message Content), and 7
(Reboot Required). Each kind of status code contains multiple sub status codes, and the error
codes are in a one-to-one correspondence with the sub status codes.

StatusCode=1

         SubStatusCode                      Error Code                        Description
ok                                0x1                               Operation completed.
riskPassword                      0x10000002                        Risky password.
armProcess                        0x10000005                        Arming process.

StatusCode=2

        Sub Status Code                     Error Code                        Description
noMemory                          0x20000001                        Insufficient memory.
serviceUnavailable                0x20000002                        The service is not available.
upgrading                         0x20000003                        Upgrading.
deviceBusy                        0x20000004                        The device is busy or no
                                                                    response.
reConnectIpc                      0x20000005                        The video server is
                                                                    reconnected.
transferUpgradePackageFailed      0x20000006                        Transmitting device upgrade
                                                                    data failed.
startUpgradeFailed                0x20000007                        Starting upgrading device
                                                                    failed.
getUpgradeProcessfailed.          0x20000008                        Getting upgrade status failed.
certificateExist                  0x2000000B                        The Authentication certificate
                                                                    already exists.

StatusCode=3

       Sub Status Code               Error Code                  Description
deviceError                  0x30000001                Hardware error.
badFlash                     0x30000002                Flash operation error.
28181Uninitialized           0x30000003                The 28181 configuration is not
                                                       initialized.
socketConnectError           0x30000005                Connecting to socket failed.
receiveError                 0x30000007                Receive response message
                                                       failed.
deletePictureError           0x3000000A                Deleting picture failed.
pictureSizeExceedLimit       0x3000000C                Too large picture size.
clearCacheError              0x3000000D                Clearing cache failed.
updateDatabasError           0x3000000F                Updating database failed.
searchDatabaseError          0x30000010                Searching in the database
                                                       failed.
writeDatabaseError           0x30000011                Writing to database failed.
deleteDatabaseError          0x30000012                Deleting database element
                                                       failed.
searchDatabaseElementError   0x30000013                Getting number of database
                                                       elements failed.
cloudAutoUpgradeException    0x30000016                Downloading upgrade packet
                                                       from cloud and upgrading
                                                       failed.
HBPException                 0x30001000                HBP exception.
UDEPException                0x30001001                UDEP exception
elasticSearchException       0x30001002                Elastic exception.
kafkaException               0x30001003                Kafka exception.
HBaseException               0x30001004                Hbase exception.
sparkException               0x30001005                Spark exception.
yarnException                0x30001006                Yarn exception.
cacheException               0x30001007                Cache exception.

        Sub Status Code                      Error Code                       Description
trafficException                 0x30001008                        Monitoring point big data
                                                                   server exception.
faceException                    0x30001009                        Human face big data server
                                                                   exception.
SSDFileSystemIsError             0x30001013                        SSD file system error (Error
                                                                   occurs when it is non-Ext4 file
                                                                   system)
insufficientSSDCapacityForFPD    0x30001014                        Insufficient SSD space for
                                                                   person frequency detection
wifiException                    0x3000100A                        Wi-Fi big data server exception.
structException                  0x3000100D                        Video parameters structure
                                                                   server exception.
captureTimeout                   0x30006000                        Data collection timed out.
lowScore                         0x30006001                        Low quality of collected data.

StatusCode=4

   Sub Status Code              Error Code                             Description
notSupport                0x40000001              Not supported.
lowPrivilege              0x40000002              No permission.
badAuthorization          0x40000003              Authentication failed.
methodNotAllowed          0x40000004              Invalid HTTP method.
notSetHdiskRedund         0x40000005              Setting spare HDD failed.
invalidOperation          0x40000006              Invalid operation.
hdFormatFail              \                       Formatting HDD failed.
notActivated              0x40000007              Inactivated.
hasActivated              0x40000008              Activated.
certificateAlreadyExist   0x40000009              The certificate already exists.
fileError                 0x4000000F              Upgrading file error.
USBNotExist               0x40000010              USB device is not connected.
upgradePackageMoret 0x40001000                    Up to 2GB upgrade package is allowed to be
han2GB                                            uploaded.

   Sub Status Code          Error Code                         Description
IDNotexist             0x40001001          The ID does not exist.
synchronizationError   0x40001003          Synchronization failed.
synchronizing          0x40001004          Synchronizing.
importError            0x40001005          Importing failed.
importing              0x40001006          Importing.
fileAlreadyExists      0x40001007          The file already exists.
invalidID              0x40001008          Invalid ID.
backupnodeNotAllowe 0x40001009             Accessing to backup node is not allowed.
Log
exportingError         0x4000100A          Exporting failed.
exporting              0x4000100B          Exporting.
exportEnded            0x4000100C          Exporting stopped.
exported               0x4000100D          Exported.
IPOccupied             0x4000100E          The IP address is already occupied.
IDAlreadyExists        0x4000100F          The ID already exists.
exportItemsExceedLimi 0x40001010           No more items can be exported.
t
noFiles                0x40001011          The file does not exist.
beingExportedByAnoth 0x40001012            Being exported by others.
erUser
needReAuthentication 0x40001013            Authentication is needed after upgrade.
unitAddNotOnline       0x40001015          The added data analysis server is offline.
unitControl            0x40001016          The data analysis server is already added.
analysis unitFull      0x40001017          No more data analysis server can be added.
unitIDError            0x40001018          The data analysis server ID does not exist.
unitExit               0x40001019          The data analysis server already exists in the
                                           list.
unitSearch             0x4000101A          Searching data analysis server in the list failed.
unitNotOnline          0x4000101B          The data analysis server is offline.
unitInfoEror           0x4000101C          Getting data analysis server information failed.

   Sub Status Code           Error Code                          Description
unitGetNodeInfoError    0x4000101D          Getting node information failed.
unitGetNetworkInfoErr 0x4000101E            Getting the network information of data
or                                          analysis server failed
unitSetNetworkInfoErr 0x4000101F            Setting the network information of data analysis
or                                          server failed
setSmartNodeInfoError 0x40001020            Setting node information failed.
setUnitNetworkInfoErr 0x40001021            Setting data analysis server network
or                                          information failed.
unitRestartCloseError   0x40001022          Rebooting or shutting down data analysis server
                                            failed.
virtualIPnotAllowed     0x40001023          Adding virtual IP address is not allowed.
unitInstalled           0x40001024          The data analysis server is already installed.
badSubnetMask           0x40001025          Invalid subnet mask.
uintVersionMismatche 0x40001026             Data analysis server version mismatches.
d
deviceMOdelMismatch 0x40001027              Adding failed. Device model mismatches.
ed
unitAddNotSelf          0x40001028          Adding peripherals is not allowed.
noValidUnit             0x40001029          No valid data analysis server.
unitNameDuplicate       0x4000102A          Duplicated data analysis server name.
deleteUnitFirst         0x4000102B          Delete the added data analysis server of the
                                            node first.
getLocalInfoFailed      0x4000102C          Getting the server information failed.
getClientAddedNodeFa 0x4000102D             Getting the added node information of data
iled                                        analysis server failed.
taskExit                0x4000102E          The task already exists.
taskInitError           0x4000102F          Initializing task failed.
taskSubmitError         0x40001030          Submiting task failed.
taskDelError            0x40001031          Deleting task failed.
taskPauseError          0x40001032          Pausing task failed.
taskContinueError       0x40001033          Starting task failed.

   Sub Status Code          Error Code                         Description
taskSeverNoCfg         0x40001035          Full-text search server is not configured.
taskPicSeverNoCfg      0x40001036          The picture server is not configured.
taskStreamError        0x40001037          Streaming information exception.
taskRecSDK             0x40001038          History recording is not supported.
taskCasaError          0x4000103A          Cascading is not supported.
taskVCARuleError       0x4000103B          Invalid VCA rule.
taskNoRun              0x4000103C          The task is not executed.
unitLinksNoStorageNo   0x4000103D          No node is linked with the data analysis server.
de                                         Configure the node first.
searchFailed           0x4000103E          Searching video files failed.
searchNull             0x4000103F          No video clip.
userScheOffline        0x40001040          The task scheduler service is offline.
updateTypeUnmatche     0x40001041          The upgrade package type mismatches.
d
userExist              0x40001043          The user already exists.
userCannotDelAdmin     0x40001044          The administrator cannot be deleted.
userInexistence        0x40001045          The user name does not exist.
userCannotCreatAdmi    0x40001046          The administrator cannot be created.
n
monitorCamExceed       0x40001048          Up to 3000 cameras can be added.
monitorCunitOverLimit 0x40001049           Adding failed. Up to 5 lower-levels are
                                           supported by the control center.
monitorReginOverLimit 0x4000104A           Adding failed. Up to 5 lower-levels are
                                           supported by the area.
monitorArming          0x4000104B          The camera is already armed. Disarm the
                                           camera and try again.
monitorSyncCfgNotSet 0x4000104C            The system parameters are not configured.
monitorFdSyncing       0x4000104E          Synchronizing. Try again after completing the
                                           synchronization.
monitorParseFailed     0x4000104F          Parsing camera information failed.

   Sub Status Code          Error Code                        Description
monitorCreatRootFaile 0x40001050           Creating resource node failed.
d
deleteArmingInfo       0x40001051          The camera is already . Disarm the camera and
                                           try again.
cannotModify           0x40001052          Editing is not allowed. Select again.
cannotDel              0x40001053          Deletion is not allowed. Select again.
deviceExist            0x40001054          The device already exists.
IPErrorConnectFailed   0x40001056          Connection failed. Check the network port.
cannotAdd              0x40001057          Only the capture cameras can be added.
serverExist            0x40001058          The server already exists.
fullTextParamError     0x40001059          Incorrect full-text search parameters.
storParamError         0x4000105A          Incorrect storage server parameters.
picServerFull          0x4000105B          The storage space of picture storage server is
                                           full.
NTPUnconnect           0x4000105C          Connecting to NTP server failed. Check the
                                           parameters.
storSerConnectFailed   0x4000105D          Connecting to storage server failed. Check the
                                           network port.
storSerLoginFailed     0x4000105E          Logging in to storage server failed. Check the
                                           user name and password.
searchSerConnectFaile 0x4000105F           Connecting to full-text search server failed.
d                                          Check the network port.
searchSerLoginFailed   0x40001060          Logging in to full-text search server failed.
                                           Check the user name and password.
kafkaConnectFailed     0x40001061          Connecting to Kafka failed. Check the network
                                           port.
mgmtConnectFailed      0x40001062          Connecting to system failed. Check the network
                                           port.
mgmtLoginFailed        0x40001063          Logging in to system failed. Check the user
                                           name and password.
TDAConnectFailed       0x40001064          Connecting to traffic data access server failed.
                                           Checking the server status.

   Sub Status Code           Error Code                        Description
86sdkConnectFailed      0x40001065          Connecting to listening port of iVMS-8600
                                            System failed. Check the parameters.
nameExist               0x40001066          Duplicated server name.
batchProcessFailed      0x40001067          Processing in batch failed.
IDNotExist              0x40001068          The server ID does not exist.
serviceNumberReache 0x40001069              No more service can be added.
sLimit
invalidServiceType.     0x4000106A          Invalid service type.
clusterGetInfo          0x4000106B          Getting cluster group information failed.
clusterDelNode          0x4000106C          Deletion node failed.
clusterAddNode          0x4000106D          Adding node failed.
clusterInstalling       0x4000106E          Creating cluster…Do not operate.
clusterUninstall        0x4000106F          Reseting cluster…Do not operate.
clusterInstall          0x40001070          Creating cluster failed.
clusterIpError          0x40001071          Invalid IP address of task scheduler server.
clusterNotSameSeg       0x40001072          The master node and slave node must be in the
                                            same network segment.
clusterVirIpError       0x40001073          Automatically getting virtual IP address failed.
                                            Enter manually.
clusterNodeUnadd        0x40001074          The specified master(slave) node is not added.
clusterNodeOffline      0x40001075          The task scheduler server is offline.
nodeNotCurrentIP        0x40001076          The analysis node of the current IP address is
                                            required when adding master and slave nodes.
addNodeNetFailed        0x40001077          Adding node failed. The network disconnected.
needTwoMgmtNode         0x40001078          Two management nodes are required when
                                            adding master and slave nodes.
ipConflict              0x40001079          The virtual IP address and data analysis server's
                                            IP address conflicted.
ipUsed                  0x4000107A          The virtual IP address has been occupied.
cloudAlalyseOnline      0x4000107B          The cloud analytic server is online.

   Sub Status Code          Error Code                         Description
virIP&mainIPnotSame    0x4000107C          The virtual IP address is not in the same
NetSegment                                 network segment with the IP address of
                                           master/slave node.
getNodeDispatchInfoFa 0x4000107D           Getting node scheduler information failed.
iled
unableModifyManage     0x4000107E          Editing management network interface failed.
mentNetworkIP                              The analysis board is in the cluster.
notSpecifyVirtualIP    0x4000107F          Virtual IP address should be specified for
                                           master and slave cluster.
armingFull             0x40001080          No more device can be armed.
armingNoFind           0x40001081          The arming information does not exist.
disArming              0x40001082          Disarming failed.
getArmingError         0x40001084          Getting arming information failed.
refreshArmingError     0x40001085          Refreshing arming information failed.
ArmingPlateSame        0x40001086          The license plate number is repeatedly armed.
ArmingParseXLSError    0x40001087          Parsing arming information file failed.
ArmingTimeError        0x40001088          Invalid arming time period.
ArmingSearchTimeErro 0x40001089            Invalid search time period.
r
armingRelationshipRea 0x4000108A           No more relation can be created.
chesLimit
duplicateAarmingNam 0x4000108B             The relation name already exists.
e
noMoreArmingListAdd 0x4000108C             No more blacklist library can be armed.
ed
noMoreCamerasAdded 0x4000108D              No more camera can be armed.
noMoreArmingListAdd 0x4000108E             No more library can be linked to the camera.
edWithCamera
noMoreArmingPeriodA 0x4000108F             No more time period can be added to the
dded                                       arming schedule.
armingPeriodsOverlap 0x40001090            The time periods in the arming schedule are
ped                                        overlapped.

   Sub Status Code          Error Code                         Description
noArmingAlarmInfo      0x40001091          The alarm information does not exist.
armingAlarmUnRead      0x40001092          Getting number of unread alarms failed.
getArmingAlarmError    0x40001093          Getting alarm information failed.
searchByPictureTimed   0x40001094          Searching picture by picture timeout. Search
Out                                        again.
comparisonTimeRange 0x40001095             Comparison time period error.
Error
selectMonitorNumber 0x40001096             No more monitoring point ID can be filtered.
UpperLimit
noMoreComparisonTas 0x40001097             No more comparison task can be executed at
ksAdded                                    the same time.
GetComparisonResultF 0x40001098            Getting comparison result failed.
ailed
comparisonTypeError    0x40001099          Comparison type error.
comparisonUnfinished 0x4000109A            The comparison is not completed.
facePictureModelInvali 0x4000109B          Invalid face model.
d
duplicateLibraryName. 0x4000109C           The library name already exists.
noRecord               0x4000109D          No record found.
countingRecordsFailed. 0x4000109E          Calculate the number of records failed.
getHumanFaceFrameF 0x4000109F              Getting face thumbnail from the picture failed.
ailed
modelingFailed.        0x400010A0          Modeling face according to picture URL failed.
1V1FacePictureCompar 0x400010A1            Comparison 1 VS 1 face picture failed.
isonFailed
libraryArmed           0x400010A2          The blacklist library is armed.
licenseExeedLimit      0x400010A3          Dongle limited.
licenseExpired         0x400010A4          Dongle expired.
licenseDisabled        0x400010A5          Unavailable dongle.
licenseNotExist        0x400010A6          The dongle does not exist.
SessionExpired         0x400010A7          Session expired .

   Sub Status Code           Error Code                          Description
beyondConcurrentLimi 0x400010A8             Out of concurrent limit.
t
stopSync                0x400010A9          Synchronization stopped.
getProgressFaild        0x400010AA          Getting progress failed.
uploadExtraCaps         0x400010AB          No more files can be uploaded.
timeRangeError          0x400010AC          Time period error.
dataPortNotConnected 0x400010AD             The data port is not connected.
addClusterNodeFailed    0x400010AE          Adding to the cluster failed. The device is
                                            already added to other cluster.
taskNotExist            0x400010AF          The task does not exist.
taskQueryFailed         0x400010B0          Searching task failed.
modifyTimeRuleFailed    0x400010B2          The task already exists. Editing time rule is not
                                            allowed.
modifySmartRuleFailed 0x400010B3            The task already exists. Editing VAC rule is not
                                            allowed.
queryHistoryVideoFaile 0x400010B4           Searching history video failed.
d
addDeviceFailed         0x400010B5          Adding device failed.
addVideoFailed          0x400010B6          Adding video files failed.
deleteAllVideoFailed    0x400010B7          Deleting all video files failed.
createVideoIndexFailed 0x400010B8           Indexing video files failed.
videoCheckTypeFailed    0x400010B9          Verifying video files types failed.
configStructuredAddre 0x400010BA            Configuring IP address of structured server
ssFailed                                    failed.
configPictureServerAd   0x400010BB          Configuring IP address of picture storaged
dressFailed                                 server failed.
storageServiceIPNotExi 0x400010BD           The storage server IP address does not exist.
st
syncBackupDatabaseFa 0x400010BE             Synchronizing slave database failed. Try again.
iled
syncBackupNTPTimeFa 0x400010BF              Synchronizing NTP time of slave server failed.
iled

   Sub Status Code         Error Code                        Description
clusterNotSelectLoopb 0x400010C0          Loopbacl address is not supported by the
ackAddress                                master or slave cluster.
addFaceRecordFailed   0x400010C1          Adding face record failed.
deleteFaceRecordFaile 0x400010C2          Deleting face record failed.
d
modifyFaceRecordFaile 0x400010C3          Editing face record failed.
d
queryFaceRecordFailed 0x400010C4          Searching face record failed.
faceDetectFailed      0x400010C5          Detecting face failed.
libraryNotExist       0x400010C6          The library does not exist.
blackListQueryExportin 0x400010C7         Exporting matched blacklists.
g
blackListQueryExporte 0x400010C8          The matched blacklists are exported.
d
blackListQueryStopExp 0x400010C9          Exporting matched blacklists is stopped.
orting
blackListAlarmQueryEx 0x400010CA          Exporting matched blacklist alarms.
porting
blackListAlarmQueryEx 0x400010CB          The matched blacklists alarms are exported.
ported
blackListAlarmQuerySt 0x400010CC          Exporting matched blacklist alarms is stopped.
opExporting
getBigDataCloudAnalys 0x400010CD          Getting big data cloud analytic information
isFailed                                  failed.
setBigDataCloudAnalys 0x400010CE          Configuring big data cloud analytic failed.
isFailed
submitMapSearchFaile 0x400010CF           Submitting search by picture task failed.
d
controlRelationshipNot 0x400010D0         The relation does not exist.
Exist
getHistoryAlarmInfoFai 0x400010D1         Getting history alarm information failed.
led
getFlowReportFailed   0x400010D2          Getting people counting report failed.

   Sub Status Code          Error Code                        Description
addGuardFailed         0x400010D3          Adding arming configuration failed.
deleteGuardFailed      0x400010D4          Deleting arming configuration failed.
modifyGuardFailed      0x400010D5          Editing arming configuration failed.
queryGuardFailed       0x400010D6          Searching arming configurations failed.
uploadUserSuperCaps    0x400010D7          No more user information can be uploaded.
bigDataServerConnect 0x400010D8            Connecting to big data server failed.
Failed
microVideoCloudRequ 0x400010D9             Adding response information of micro video
estInfoBuildFailed                         cloud failed.
microVideoCloudRespo 0x400010DA            Parsing response information of micro video
nseInfoBuildFailed                         cloud failed.
transcodingServerRequ 0x400010DB           Adding response information of transcoding
estInfoBuildFailed                         server failed.
transcodingServerResp 0x400010DC           Parsing response information of transcoding
onseInfoParseFailed                        server failed.
transcodingServerOffli 0x400010DD          Transcoding server is offline.
ne
microVideoCloudOfflin 0x400010DE           Micro video cloud is offline.
e
UPSServerOffline       0x400010DF          UPS monitor server is offline.
statisticReportRequestI 0x400010E0         Adding response information of statistics report
nfoBuildFailed                             failed.
statisticReportRespons 0x400010E1          Parsing response information of statistics report
eInfoParseFailed                           failed.
DisplayConfigInfoBuild 0x400010E2          Adding display configuration information failed.
Failed
DisplayConfigInfoParse 0x400010E3          Parsing display configuration information failed.
Failed
DisplayConfigInfoSaveF 0x400010E4          Saving display configuration information failed.
ailed
notSupportDisplayConf 0x400010E5           The display configuration type is not supported.
igType
passError              0x400010E7          Incorrect password.

   Sub Status Code          Error Code                        Description
upgradePackageLarge   0x400010EB           Too large upgrade package.
sesssionUserReachesLi 0x400010EC           No more user can log in via session.
mit
ISO                   0x400010ED           Invalid ISO8601 time format.
8601TimeFormatError
clusterDissolutionFaile 0x400010EE         Deleting cluster failed.
d
getServiceNodeInfoFail 0x400010EF          Getting service node information failed.
ed
getUPSInfoFailed      0x400010F0           Getting UPS configuration information failed.
getDataStatisticsRepor 0x400010F1          Getting data statistic report failed.
tFailed
getDisplayConfigInfoFai 0x400010F2         Getting display configuration failed.
led
namingAnalysisBoardN 0x400010F3            Renaming analysis board is not allowed.
otAllowed
onlyDrawRegionsOfCo 0x400010F4             Only drawing convex polygon area is supported.
nvexPolygon
bigDataServerRespons 0x400010F5            Parsing response message of big data service
eInfoParseFailed                           failed.
bigDataServerReturnFa 0x400010F6           No response is returned by big data service.
iled
microVideoReturnFaile 0x400010F7           No response is returned by micro video cloud
d                                          service.
transcodingServerRetu 0x400010F8           No response is returned by transcoding service.
rnFailed
UPSServerReturnFailed 0x400010F9           No response is returned by UPS monitoring
                                           service.
forwardingServer      0x400010FA           No response is returned by forwarding service.
ReturnFailed
storageServer         0x400010FB           No response is returned by storage service.
ReturnFailed

   Sub Status Code           Error Code                           Description
cloudAnalysisServerRet 0x400010FC           No response is returned by cloud analytic
urnFailed                                   service.
modelEmpty              0x400010FD          No model is obtained.
mainAndBackupNodeC 0x400010FE               Editing the management interface IP address of
annotModifyManagem                          master node and backup node is not allowed.
entNetworkInterfaceIP
IDTooLong               0x400010FF          The ID is too long.
pictureCheckFailed      0x40001100          Detecting picture failed.
pictureModelingFailed 0x40001101            Modeling picture failed.
setCloudAnalsisDefault 0x40001102           Setting default province of cloud analytic
ProvinceFailed                              service failed.
InspectionAreasNumbe 0x40001103             No more detection regions can be added.
rExceedLimit
picturePixelsTooLarge   0x40001105          The picture resolution is too high.
picturePixelsTooSmall   0x40001106          The picture resolution is too low.
storageServiceIPEmpty 0x40001107            The storage server IP address is required.
bigDataServerRequestI 0x40001108            Creating request message of big data service
nfoBuildFail                                failed.
analysiTimedOut         0x40001109          Analysis time out.
high-               0x4000110A              Please enable high-performance mode.
performanceModeDisa
bled.
configuringUPSMonito 0x4000110B             Configurating the UPS monitoring server time
ringServerTimedOut                          out. Check IP address.
cloudAnalysisRequestI   0x4000110C          Creating request message of cloud analytic
nformationBuildFailed                       service failed.
cloudAnalysisResponse 0x4000110D            Parsing response message of cloud analytic
InformationParseFailed                      service failed.
allCloudAnalysisInterfa 0x4000110E          Calling API for cloud analytic service failed.
ceFailed
cloudAnalysisModelCo 0x4000110F             Model comparison of cloud analytic service
mpareFailed                                 failed.

   Sub Status Code          Error Code                        Description
cloudAnalysisFacePictu 0x40001110          Getting face quality grading of cloud analytic
reQualityRatingFailed                      service failed.
cloudAnalysisExtractFe 0x40001111          Extracting feature of cloud analytic service
aturePointsFailed                          failed.
cloudAnalysisExtractPr 0x40001112          Extracting property of cloud analytic service
opertyFailed                               failed.
getAddedNodeInformat 0x40001113            Getting the added nodes information of data
ionFailed                                  analysis server failed.
noMoreAnalysisUnitsA 0x40001114            No more data analysis servers can be added.
dded
detectionAreaInvalid   0x40001115          Invalid detection region.
shieldAreaInvalid      0x40001116          Invalid shield region.
noMoreShieldAreasAd 0x40001117             No more shield region can be drawn.
ded
onlyAreaOfRectangleS   0x40001118          Only drawing rectangle is allowed in detection
hapeAllowed                                area.
numberReachedLlimit    0x40001119          Number reached the limit.
wait1~3MinutesGetIPAf 0x4000111A           Wait 1 to 3 minutes to get IP address after
terSetupDHCP                               configuring DHCP.
plannedTimeMustbeH 0x4000111B              Schedule must be half an hour.
alfAnHour
oneDeviceCannotBuild 0x4000111C            Creating master and backup cluster requires at
Cluster                                    least two devices.
updatePackageFileNot 0x4000111E            Upgrade package is not uploaded.
Uploaded
highPerformanceTasks 0x4000111F            Drawing detection area is not allowed under
NotSupportDrawingDe                        high-performance mode.
tectionRegions
controlCenterIDDoesN 0x40001120            The control center ID does not exist.
otExist
regionIDDoesNotExist   0x40001121          The area ID does not exist.
licensePlateFormatErro 0x40001122          Invalid license plate format.
r

   Sub Status Code           Error Code                        Description
managementNodeDoe 0x40001123                The operation is not supported.
sNotSupportThisOperat
ion
searchByPictureResour 0x40001124            The conditions for searching picture by picture
ceNotConfiged                               are not configured.
videoFileEncapsulation 0x40001125           The video container format is not supported.
FormatNotSupported
videoPackageFailure     0x40001126          Converting video container format failed.
videoCodingFormatNot 0x40001127             Video coding format is not supported.
Supported
monitorOfDeviceArmin 0x40001129             The camera is armed. Disarm it and try again.
gdeleteArmingInfo
getVideoSourceTypeFai 0x4000112A            Getting video source type failed.
led
smartRulesBuildFailed   0x4000112B          Creating VAC rule failed.
smartRulesParseFailed 0x4000112C            Parsing VAC rule failed.
timeRulesBuildFailed    0x4000112D          Creating time rule failed.
timeRulesParseFailed    0x4000112E          Parsing time rule failed.
monitoInfoInvalid       0x4000112F          Invalid camera information.
addingFailedVersionMi 0x40001130            Adding failed. The device version mismatches.
smatches
theInformationReturne 0x40001131            No response is returned by the cloud analytic
dAfterCloudAnalysisIsE                      service.
mpty
selectingIpAddressOfH 0x40001132            Setting IP address for master node and backup
ostAndSpareNodeFaile                        node failed. Check the node status.
dCheckTheStatus
theSearchIdDoesNotEx 0x40001133             The search ID does not exist.
ist
theSynchronizationIdD 0x40001134            The synchronization ID does not exist.
oesNotExist
theUserIdDoesNotExist 0x40001136            The user ID does not exist.

   Sub Status Code            Error Code                          Description
theIndexCodeDoesNot 0x40001138               The index code does not exist.
Exist
theControlCenterIdDoe 0x40001139             The control center ID does not exist.
sNotExist
theAreaIdDoesNotExist 0x4000113A             The area ID does not exist.
theArmingLinkageIdDo 0x4000113C              The arming relationship ID does not exist.
esNotExist
theListLibraryIdDoesNo 0x4000113D            The list library ID does not exist.
tExist
invalidCityCode          0x4000113E          Invalid city code.
synchronizingThePass 0x4000113F              Synchronizing backup system password failed.
wordOfSpareServerFail
ed
editingStreamingTypeIs 0x40001140            Editing streaming type is not supported.
NotSupported
switchingScheduledTas 0x40001141             Switching scheduled task to temporary task is
kToTemporaryTaskIsNo                         not supported.
tSupported
switchingTemporaryTas 0x40001142             Switching temporary task to scheduled task is
kToScheduledTaskIsNot                        not supported.
Supported
theTaskIsNotDispatche 0x40001143             The task is not dispatched or is updating.
dOrItIsUpdating
thisTaskDoesNotExist     0x40001144          This task does not exist in the cloud analytic
                                             serice.
duplicatedSchedule       0x40001145          Schedule period cannot be overlapped.
continuousScheduleWi 0x40001146              The continuous schedule periods with same
thSameAlgorithmType                          algorithm type should be merged.
ShouldBeMerged
invalidStreamingTimeR 0x40001147             Invalid streaming time period.
ange
invalidListLibraryType   0x40001148          Invalid list library type.

   Sub Status Code           Error Code                         Description
theNumberOfMatched 0x40001149               The number of search results should be larger
ResultsShouldBeLarger                       than 0.
Than0
invalidValueRangeOfSi   0x4000114A          Invalid similarity range.
milarity
invalidSortingType      0x4000114B          Invalid sorting type.
noMoreListLibraryCanB 0x4000114C            No more lists can be added to one device.
eLinkedToTheDevice
InvalidRecipientAddres 0x4000114D           Invalid address format of result receiver.
sFormat
creatingClusterFailedT 0x4000114E           Insert the dongle before creating cluster.
heDongleIsNotPlugged
In
theURLIsTooLong         0x4000114F          No schedule configured for the task.
noScheduleIsConfigure 0x40001150            No schedule configured for the task.
dForTheTask
theDongleIsExpiried     0x40001151          Dongle has expired.
dongleException         0x40001152          Dongle exception.
invalidKey              0x40001153          Invalid authorization service key.
decryptionFailed        0x40001154          Decrypting authorization service failed.
encryptionFailed        0x40001155          Encrypting authorization service failed.
AuthorizeServiceRespo 0x40001156            Authorization service response exception.
nseError
incorrectParameter      0x40001157          Authorization service parameters error.
operationFailed         0x40001158          Operating authorization service error.
noAnalysisResourceOr 0x40001159             No cloud analytic resources or no data in the list
NoDataInTheListLibrary                      library.
calculationException    0x4000115A          Calculation exception.
allocatingList          0x4000115B          Allocating list.
thisOperationIsNotSup 0x4000115C            This operation is not supported by the cloud
portedByTheCloudAnal                        analytic serice.
ytics

   Sub Status Code          Error Code                          Description
theCloudAnalyticsIsInt 0x4000115D          The operation of cloud analytic serice is
errupted                                   interrupted.
theServiceIsNotReady   0x4000115E          The service is not ready.
searchingForExternalA 0x4000115F           Searching external interfaces failed.
piFailed
noOnlineNode           0x40001160          No node is online.
noNodeAllocated        0x40001161          No allocated node.
noMatchedList          0x40001162          No matched list.
allocatingFailedTooMa 0x40001163           Allocation failed. Too many lists of big data
nyFacePictureLists                         service.
searchIsNotCompleted 0x40001164            Current searching is not completed. Search
SearchAgain                                again.
allocatingListIsNotCom 0x40001165          Allocating list is not completed.
pleted
searchingForCloudAnal 0x40001166           Searching cloud analytic serice overtime.
yticsResultsFailed
noDataOfTheCurrentLi 0x40001167            No data in the current library. Make sure there
braryFound                                 is data in the Hbase.
noFacePictureLibraryIs 0x40001168          No face picture library is armed for big data
Armed                                      service.
noAvailableDataSlicing 0x40001169          Invalid standard version information.
VersionInformationAr
mFirstAndSliceTheData
duplicatedOperationDa 0x4000116A           Slicing failed. Duplicated operation.
taSlicingIsExecuting
slicinDataFailedNoArm 0x4000116B           Slicing failed. No arming information in the face
edFacePictureLibrary                       big data.
GenerateBenchmarkFil 0x4000116C            Generating sliced file failed. Slice again.
eFailedSlicingAgain
NonprimaryNodeIsPro 0x4000116D             Slicing is not allowed by the backup node.
hibitedFromSlcingData
NoReadyNodeToCluste 0x4000116E             Creating the cluster failed. No ready node.
rServers

   Sub Status Code           Error Code                        Description
NodeManagementServ 0x4000116F               The node management server is offline.
iceIsOffline
theCamera(s)OfTheCo 0x40001170              Some cameras in control center are already
ntrolCenterAreAlready                       armed. Disarm them and try again.
Armed.DisarmThemFir
st
theCamera(s)OfTheAre 0x40001171             Some cameras in this area are already armed.
aAreAlreadyArmed.Dis                        Disarm them and try again.
armThemFirst
configuringHigh-      0x40001172            Configuring high frequency people detection
frequencyPeopleDetect                       failed.
ionFailed
searchingForHigh-     0x40001173            Searching detection event logs of high-
frequencyPeopleDetect                       frequency people detection failed.
ionLogsFailed.
gettingDetailsOfSearch 0x40001174           Getting the search result details of high
edHigh-                                     frequency alarms failed.
frequencyPeopleDetect
ionLogsFailed.
theArmedCamerasAlre 0x40001175              Some cameras in control center are already
adyExistInTheControlC                       armed.
enter
disarmingFailedTheCa    0x40001177          Disarming failed. The camera is not armed.
meraIsNotArmed
noDataReturned          0x40001178          No response is returned by the big data service.
preallocFailure         0x40001179          Pre-​allocating algorithm resource failed.
overDogLimit            0x4000117A          Configuration failed. No more resources can be
                                            pre-allocated.
analysisServicesDoNot 0x4000117B            Not supported.
Support
commandAndDispatch 0x4000117C               Scheduling service of cloud analytic serice error.
ServiceError
engineModuleError       0x4000117D          Engine module of cloud analytic serice error.
streamingServiceError   0x4000117E          Streaming component of cloud analytic serice
                                            error.

   Sub Status Code           Error Code                         Description
faceAnalysisModuleErr 0x4000117F            Face analysis module of cloud analytic serice
or                                          error.
vehicleAnalysisModule 0x40001180            Vehicle pictures analytic module of cloud
Error                                       analytic serice error.
videoStructuralAnalysis 0x40001181          Video structuring module of cloud analytic
ModuleError                                 serice error.
postprocessingModule 0x40001182             Post-processing module of cloud analytic serice
Error                                       error.
frequentlyAppearedPe 0x40001183             High frequency alarm is already armed for
rsonAlarmIsAlreadyCo                        blacklist library.
nfiguredForListLibrary
creatingListLibraryFaile 0x40001184         Creating list library failed.
d
invalidIdentiryKeyOfLis 0x40001185          Invalid identity key of list library.
tLibrary
noMoreDevicesCanBe     0x40001186           No more camera can be added.
Armed
settingAlgorithmTypeF 0x40001187            Allocating task resource failed.
orDeviceFailed
gettingHighFrequencyP 0x40001188            Setting high frequency alarm failed.
ersonDetectionAlarmIn
formationFailed
invalidSearchConfition 0x40001189           Invalid result.
theTaskIsNotComplete 0x4000118B             The task is not completed.
d
resourceOverRemainLi 0x4000118C             No more resource can be pre-allocated.
mit
frequentlyAppearedPe 0x4000118D             The high frequency alarm of this camera is
rsonAlarmIs                                 configured. Delete the arming information and
AlreadyConfiguredForT                       try again.
heCameraDisarmFirstA
ndTryAgain
noClientCertificate    0x40002036           The client certificate is not installed.
noCACertificate        0x40002037           The CA certificate is not installed.

   Sub Status Code           Error Code                           Description
authenticationFailed   0x40002038           Authenticating certificate failed. Check the
                                            certificate.
clientCertificateExpired 0x40002039         The client certificate is expired.
clientCertificateRevocat 0x4000203A         The client certificate is revoked.
ion
CACertificateExpired   0x4000203B           The CA certificate is expired.
CACertificateRevocatio 0x4000203C           The CA certificate is revoked.
n
connectFail            0x4000203D           Connection failed.
loginNumExceedLimit    0x4000203F           No more user can log in.
formattingFailed       0x40002056           Formatting HDD failed.
encryptedFormattingFa 0x40002057            Formatting encrypted HDD failed.
iled
wrongPassword          0x40002058           Verifying password of SD card failed. Incorrect
                                            password.
armingFailed           0x40008000           Arming failed.
disarmingFailed        0x40008001           Disarming failed.
clearAlarmFailed       0x40008002           Clearing alarm failed.
bypassFailed           0x40008003           Bypass failed.
bypassRecoverFailed    0x40008004           Bypass recovery failed.
outputsOpenFailed      0x40008005           Opening relay failed.
outputsCloseFailed     0x40008006           Closing relay failed.
registerTimeOut        0x40008007           Registering timed out.
registerFailed         0x40008008           Registering failed.
addedByOtherHost       0x40008009           The peripheral is already added by other
                                            security control panel.
alreadyAdded           0x4000800A           The peripheral is already added.
armedStatus            0x4000800B           The partition is armed.
bypassStatus           0x4000800C           Bypassed.
zoneNotSupport         0x4000800D           This operation is not supported by the zone.

   Sub Status Code          Error Code                         Description
zoneFault              0x4000800E          The zone is in fault status.
pwdConflict            0x4000800F          Password conflicted.
audioTestEntryFailed   0x40008010          Enabling audio test mode failed.
audioTestRecoveryFaile 0x40008011          Disabling audio test mode failed.
d
addCardMode            0x40008012          Adding card mode.
searchMode             0x40008013          Search mode.
addRemoterMode         0x40008014          Adding keyfob mode.
registerMode           0x40008015          Registration mode.
exDevNotExist          0x40008016          The peripheral does not exist.
theNumberOfExDevLi     0x40008017          No peripheral can be added.
mited
sirenConfigFailed      0x40008018          Setting siren failed.
chanCannotRepeatedB 0x40008019             This channel is already linked by the zone.
inded
masterSlaveIsEnable    0x4000802c          The master-slave relationship has taken effect,
                                           the slave radar does not support this operation.
forceTrackNotEnabled   0x4000802d          Mandatory tracking is disabled.
isNotSupportZoneConfi 0x4000802e           This area does not support the zone type.
gByLocalArea
alarmLineCross         0x4000802f          Trigger lines are overlapped.
zoneDrawingOutOfRan 0x40008030             The drawn zone is out of detection range.
ge
alarmLineDrawingOut    0x40008031          The drawn alarm trigger line is out of detection
OfRange                                    range.
hasTargetInWarningAr   0x40008032          The warning zone already contains targets.
ea                                         Whether to enable mandatory arming?
inProgramMode          0x4000801B          The keypad is in programming mode.
inPaceTest             0x4000801C          Pacing mode.
arming                 0x4000801D          Armed.

   Sub Status Code           Error Code                              Description
HDMIResolutionIllegal    /                     The HDMI video resolution cannot be larger
                                               than that of main and sub stream.
startAppFail             /                     Starting running application program failed.
yuvconflict              /                     The raw video stream conflicted.
overMaxAppNum            /                     No more application program can be uploaded.
alreadyExist             /                     The application program already exists.
noFlash                  /                     Insufficient flash.
noFlash                  /                     The platform mismatches.
alreadyRunning           /                     The application program is running.
notRunning               /                     The application program is stopped.
packNotFound             /                     The software packet does not exist.
noMemory                 /                     Insufficient memory.
invalLicense             /                     Invalid Licnese.

StatusCode=5

       Sub Status Code                    Error Code                        Description
badXmlFormat                  0x50000001                          Invalid XML format.

StatusCode=6

       Sub Status Code                    Error Code                        Description
badParameters                 0x60000001                          Invalid parameter.
badHostAddress                0x60000002                          Invalid host IP address.
badXmlContent                 0x60000003                          Invalid XML content.
badIPv4Address                0x60000004                          Invalid IPv4 address.
badIPv6Address                0x60000005                          Invalid IPv6 address.
conflictIPv4Address           0x60000006                          IPv4 address conflicted.
conflictIPv6Address           0x60000007                          IPv6 address conflicted.
badDomainName                 0x60000008                          Invalid domain name.
connectSreverFail             0x60000009                          Connecting to server failed.
conflictDomainName            0x6000000A                          Domain name conflicted.

       Sub Status Code                Error Code                   Description
badPort                       0x6000000B                Port number conflicted.
portError                     0x6000000C                Port error.
exportErrorData               0x6000000D                Importing data failed.
badNetMask                    0x6000000E                Invalid sub-net mask.
badVersion                    0x6000000F                Version mismatches.
badDevType                    0x600000010               Device type mismatches.
badLanguage                   0x600000011               Language mismatches.
incorrentUserNameOrPasswor    0x600000012               Incorrect user name or
d                                                       password.
invalidStoragePoolOfCloudServ 0x600000013               Invalid storage pool. The
er                                                      storage pool is not configured
                                                        or incorrect ID.
noFreeSpaceOfStoragePool      0x600000014               Storage pool is full.
riskPassword                  0x600000015               Risky password.
UnSupportCapture              0x600000016               Capturing in 4096*2160 or
                                                        3072*2048 resolution is not
                                                        supported when H.264+ is
                                                        enabled.
userPwdLenUnder8              0x60000023                At least two kinds of
                                                        characters, including digits,
                                                        letters, and symbols, should be
                                                        contained in the password.
userPwdNameSame               0x60000025                Duplicated password.
userPwdNameMirror             0x60000026                The password cannot be the
                                                        reverse order of user name.
beyondARGSRangeLimit          0x60000027                The parameter value is out of
                                                        limit.
DetectionLineOutofDetectionR 0x60000085                 The rule line is out of region.
egion
DetectionRegionError          0x60000086                Rule region error. Make sure
                                                        the rule region is convex
                                                        polygon.

           Sub Status Code             Error Code                    Description
DetectionRegionOutOfCountin 0x60000087                   The rule region must be
gRegion                                                  marked as red frame.
PedalAreaError                 0x60000088                The pedal area must be in the
                                                         rule region.
DetectionAreaABError           0x60000089                The detection region A and B
                                                         must be in the a rule frame.
ABRegionCannotIntersect        0x6000008a                Region A and B cannot be
                                                         overlapped.
analysisEnginesNoResourceErr   0x60001000                No analysis engine.
or
analysisEnginesUsageExcced     0x60001001                The engine usage is
                                                         overloaded.
PicAnalysisNoResourceError     0x60001002                No analysis engine provided for
                                                         picture secondary recognition.
analysisEnginesLoadingError    0x60001003                Initializing analysis engine.
analysisEnginesAbnormaError    0x60001004                Analysis engine exception.
analysisEnginesFacelibImportin 0x60001005                Importing pictures to face
g                                                        picture library. Failed to edit
                                                         analysis engine parameters.
analysisEnginesAssociatedChan 0x60001006                 The analysis engine is linked to
nel                                                      channel.
smdEncodingNoResource          0x60001007                Insufficient motion detection
                                                         encoding resources.
smdDecodingNoResource          0x60001008                Insufficient motion detection
                                                         decoding resources.
diskError                      0x60001009                HDD error.
diskFull                       0x6000100a                HDD full.
facelibDataProcessing          0x6000100b                Handling face picture library
                                                         data.
capturePackageFailed           0x6000100c                Capturing packet failed.
capturePackageProcessing       0x6000100d                Capturing packet.

       Sub Status Code                 Error Code               Description
noSupportWithPlaybackAbstra 0x6000100e                This function is not supported.
ct                                                    Playback by video synopsis is
                                                      enabled.
insufficientNetworkBandwidth   0x6000100f             Insufficient network
                                                      bandwidth.
tapeLibNeedStopArchive         0x60001010             Stop the filing operation of
                                                      tape library first.
identityKeyError               0x60001011             Incorrect interaction command.
identityKeyMissing             0x60001012             The interaction command is
                                                      lost.
noSupportWithPersonDensityD 0x60001013                This function is not supported.
etect                                                 The people density detection is
                                                      enabled.
ipcResolutionOverflow          0x60001014             The configured resolution of
                                                      network camera is invalid.
ipcBitrateOverflow             0x60001015             The configured bit rate of
                                                      network camera is invalid.
tooGreatTimeDifference         0x60001016             Too large time difference
                                                      between device and server.
noSupportWithPlayback          0x60001017             This function is not supported.
                                                      Playback is enabled.
channelNoSupportWithSMD        0x60001018             This function is not supported.
                                                      Motion detection is enabled.
channelNoSupportWithFD         0x60001019             This function is not supported.
                                                      Face capture is enabled.
illegalPhoneNumber             0x6000101a             Invalid phone number.
illegalCertificateNumber       0x6000101b             Invalid certificate No.
linkedCameraOutLimit           0x6000101c             Connecting camera timed out.
achieveMaxChannelLimit         0x6000101e             No more channels are allowed.
humanMisInfoFilterEnabledCha 0x6000101f               No more channels are allowed
nNumError                                             to enable preventing false
                                                      alarm.

       Sub Status Code                 Error Code                  Description
humanEnginesNoResource         0x60001020               Insufficient human body
                                                        analysis engine resources.
taskNumberOverflow             0x60001021               No more tasks can be added.
collisionTimeOverflow          0x60001022               No more comparison duration
                                                        can be configured.
invalidTaskID                  0x60001023               Invalid task ID.
eventNotSupport                0x60001024               Event subscription is not
                                                        supported.
invalidEZVIZSecretKey          0x60001034               Invalid verification code for Hik-
                                                        Connect.
needDoubleVerification         0x60001042               Double verification required
noDoubleVerificationUser       0x60001043               No double verification user
timeSpanNumOverLimit           0x60001044               Max. number of time buckets
                                                        reached
channelNumOverLimit            0x60001045               Max. number of channels
                                                        reached
noSearchIDResource             0x60001046               Insufficient searchID resources
noSupportDeleteStrangerLib     0x60001051               Deleting stranger library is not
                                                        supported
noSupportCreateStrangerLib     0x60001052               Creating stranger library is not
                                                        supported
TransitionUseEmmc              0x60002000               Starting device failed. The
                                                        EMMC is overused.
AdaptiveStreamNotEnabled       0x60002001               The stream self-​adaptive
                                                        function is not enabled .
AdaptiveStreamAndVariableBit 0x60002002                 Stream self-​adptive and
rateEnabled                                             variable bitrate function cannot
                                                        be enabled at the same time.
detectorTypeMismatch           0x60008000               The detector type mismatched.
nameExist                      0x60008001               The name already exists.
laneAndRegionOverlap           None.                    The lanes are overlapped.
unitConfigurationNotInEffect   /                        Invalid unit parameter.

StatusCode=7

       SubStatusCode               Error Code                  Description
rebootRequired             0x70000001                Reboot to take effect.

UD09761B
