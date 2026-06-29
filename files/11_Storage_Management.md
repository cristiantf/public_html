# Chapter 11 Storage Management

• Get capability of storing additional information
  Request URL: GET /ISAPI/ContentMgmt/Storage/ExtraInfo/capabilities
• Get or set parameters for storing additional information
  Request URL: GET or PUT /ISAPI/ContentMgmt/Storage/ExtraInfo

11.1 HDD Management
The HDD (Hard Disk Drive) is used for storage. Before storing information in HDD, you must format
it, and you can also reallocate its space for better storage management.

HDD Configuration
• Get HDD management capability
  Request URL: GET /ISAPI/ContentMgmt/Storage/hdd/capabilities
• Get parameters of all HDDs
  Request URL: GET /ISAPI/ContentMgmt/Storage/hdd
• Get or set parameters of one HDD
  Request URL: GET or PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>
• Get parameters of all HDD quotas
  Request URL: /ISAPI/ContentMgmt/Storage/quota
• Verify HDD encryption password
  Request URL: PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/encryptVerfy?format=json

HDD Formatting
• Format all HDDs
  Request URL: PUT /ISAPI/ContentMgmt/Storage/hdd/format
• Specify formatting type to format one HDD
  Request URL: PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/format?formatType=
• Format multiple specified HDDs
  Request URL: PUT /ISAPI/ContentMgmt/Storage/hdd/specifyHddFormat?format=json
• Format an encrypted HDD
  Request URL: PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/encryptFormat?format=json
• Get formatting status of one HDD
  Request URL: GET /ISAPI/ContentMgmt/Storage/hdd/<ID>/formatStatus

HDD Checking
• Get or set parameters for checking HDD status
  Request URL: GET or PUT /ISAPI/ContentMgmt/Storage/hdd/SMARTTest/config
• Start checking HDD status
  Request URL: PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/SMARTTest/start

• Get HDD checking status
  Request URL: GET /ISAPI/ContentMgmt/Storage/hdd/<ID>/SMARTTest/status
• Start checking bad sectors of a HDD
  Request URL: PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/start
• Get bad sector checking status of a HDD
  Request URL: GET /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/status
• Pause checking bad sectors of a HDD
  Request URL: PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/pause
• Resume checking bad sectors of a HDD
  Request URL: PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/resume
• Stop checking bad sectors of a HDD
  Request URL: PUT /ISAPI/ContentMgmt/Storage/hdd/<ID>/BadSectorsTest/stop

SHM (SkyHawk Health Management) Alarm Linkage
• Get or set linkage parameters of HDD high temperature detection
  Request URL: GET or PUT /ISAPI/Event/triggers/highHDTemperature
• Get or set linkage parameters of HDD low temperature detection
  Request URL: GET or PUT /ISAPI/Event/triggers/lowHDTemperature
• Get or set linkage parameters of HDD impact detection
  Request URL: GET or PUT /ISAPI/Event/triggers/hdImpact
• Get or set linkage parameters of HDD bad sector detection
  Request URL: GET or PUT /ISAPI/Event/triggers/hdBadBlock
• Get or set linkage parameters of HDD severe fault detection
  Request URL: GET or PUT /ISAPI/Event/triggers/severeHDFailure
