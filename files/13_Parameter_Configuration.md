# Chapter 13 Parameter Configuration


13.1 I/O Settings

I/O (Alarm Input and Output)
• Get I/O configuration capability
  Request URL: GET /ISAPI/System/IO/capabilities .
• Get I/O status
  Request URL: GET /ISAPI/System/IO/status

Alarm Input
• Get configuration capability of alarm inputs
  Request URL: GET /ISAPI/System/IO/inputs/capabilities .
• Get parameters of all alarm inputs
  Request URL: GET /ISAPI/System/IO/inputs
• Get or set parameters of one alarm input
  Request URL: GET or PUT /ISAPI/System/IO/inputs/<ID>
• Get status of one alarm input
  Request URL: GET /ISAPI/System/IO/inputs/<ID>/status
• Alarm Input Configuration of Digital Channel

        Note
  To check if the alarm input configuration of digital channel is supported, you can call the request
  URL: GET /ISAPI/ContentMgmt/capabilities to get the device storage management capability
  ( XML_RacmCap ).
  If this function is supported, the node <isSupportIOInputProxy> is returned and its value is
  "true".
  • Get or set alarm input parameters of all digital channels
    Request URL: GET or PUT /ISAPI/ContentMgmt/IOProxy/inputs
  • Added alarm input configuration of a specific digital channel
    Request URL: POST /ISAPI/ContentMgmt/IOProxy/inputs
  • Get or set alarm input parameters of a specific digital channel
    Request URL: GET or PUT /ISAPI/ContentMgmt/IOProxy/inputs/<ID>
  • Delete alarm input configuration of a specific digital channel
    Request URL: DELETE /ISAPI/ContentMgmt/IOProxy/inputs/<ID>
  • Get alarm input status of a specific digital channel
    Request URL: GET /ISAPI/ContentMgmt/IOProxy/inputs/<ID>/status

Alarm Output
• Basic Alarm Output Parameters

  • Get configuration capability of alarm outputs
    Request URL: GET /ISAPI/System/IO/outputs/capabilities
  • Get parameters of all alarm outputs
    Request URL: GET /ISAPI/System/IO/outputs
  • Get or set parameters of one alarm output
    Request URL: GET or PUT /ISAPI/System/IO/outputs/<ID>
  • Get status of one alarm output
    Request URL: GET /ISAPI/System/IO/outputs/<ID>/status
• Supplement Light Alarm Output
  • Get configuration capability of supplement light alarm outputs
    Request URL: GET /ISAPI/Event/triggers/notifications/whiteLightAlarm/capabilities?
    format=json
  • Get or set parameters of supplement light alarm outputs
    Request URL: GET or PUT /ISAPI/Event/triggers/notifications/whiteLightAlarm?format=json
• Audible Alarm Output
  • Get configuration capability of audible alarm outputs
    Request URL: GET /ISAPI/Event/triggers/notifications/AudioAlarm/capabilities?format=json
  • Get or set parameters of audible alarm outputs
    Request URL: GET or PUT /ISAPI/Event/triggers/notifications/AudioAlarm?format=json
• Manually trigger an alarm output
  Request URL: PUT /ISAPI/System/IO/outputs/<ID>/trigger
• Alarm Output Configuration of Digital Channel

        Note
  To check if the alarm output configuration of digital channel is supported, you can call the
  request URL: GET /ISAPI/ContentMgmt/capabilities to get the device storage management
  capability ( XML_RacmCap ).
  If this function is supported, the node <isSupportIOOutputProxy> is returned and its value is
  "true".
  • Get or set alarm output parameters of all digital channels
    Request URL: GET or PUT /ISAPI/ContentMgmt/IOProxy/outputs
  • Added alarm output configuration of a specific digital channel
    Request URL: POST /ISAPI/ContentMgmt/IOProxy/outputs
  • Get or set alarm output parameters of a specific digital channel
    Request URL: GET or PUT /ISAPI/ContentMgmt/IOProxy/outputs/<ID>
  • Delete alarm output configuration of a specific digital channel
    Request URL: DELETE /ISAPI/ContentMgmt/IOProxy/outputs/<ID>
  • Get alarm output status of a specific digital channel
    Request URL: GET /ISAPI/ContentMgmt/IOProxy/outputs/<ID>/status
  • Trigger alarm output of a specific digital channel
    Request URL: PUT /ISAPI/ContentMgmt/IOProxy/outputs/<ID>/trigger

       Note
  The alarm details are uploaded by the message
  XML_EventNotificationAlert_IOSensorAlarmMsg .

13.2 Video/Image Settings

Basic Image Parameters
• Get image configuration capability
  Request URL: GET /ISAPI/Image/channels/<ID>/capabilities .
• Get or set image parameters of all channels
  Request URL: GET or PUT /ISAPI/Image/channels
• Get or set image parameters of one channel
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>
• Get basic image parameters of all channels
  Request URL: GET /ISAPI/Image/channels/<ID>/imageModes
• Get basic image parameters of one channel
  Request URL: GET /ISAPI/Image/channels/<ID>/imageMode/<ID>
• Reset image parameters
  Request URL: PUT /ISAPI/Image/channels/<ID>/reset
• Restore to default image settings
  Request URL: PUT /ISAPI/Image/channels/<ID>/restore

Camera Video/Image Parameters
• Get or set day/night mode parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/ISPMode
• Get or set image auto flip parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/ImageFlip
• Get or set wide dynamic range (WDR) parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/WDR
• Get or set backlight compensation (BLC) parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/BLC
• Get or set day/night auto switch parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/IrcutFilter
• Get or set 3-dimention digital noise reduction (3D DNR) parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/noiseReduce
• Get or set white balance (WB) parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/whiteBalance
• Exposure
  • Get or set exposure parameters

    Request URL: GET or PUT /ISAPI/Image/channels/<ID>/exposure
  • Get or set shutter parameters in exposure mode
    Request URL: GET or PUT /ISAPI/Image/channels/<ID>/shutter
  • Get or set gain parameters in exposure mode
    Request URL: GET or PUT /ISAPI/Image/channels/<ID>/gain
• Get or set sharpness parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/sharpness
• Get or set defog parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/dehaze
• Get or set image standard
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/powerLineFrequency
• Image Adjustment
  • Get image adjustment capability
    Request URL: GET /ISAPI/Image/channels/<ID>/color/capabilities
  • Get or set image adjustment parameters
    Request URL: GET or PUT /ISAPI/Image/channels/<ID>/color
• Get or set image rotate mode parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/corridor

Other Video/Image Parameters
• Focus
  • Get focus configuration capability
    Request URL: GET /ISAPI/Image/channels/<ID>/focusConfiguration/capabilities
  • Get or set focus parameters
    Request URL: GET or PUT /ISAPI/Image/channels/<ID>/focusConfiguration
  • Perform regional focus
    Request URL: PUT /ISAPI/Image/channels/<ID>/regionalFocus

         Note
    To check if the regional focus is supported by device, you can call the request URL: GET to get
    the image capability ( XML_ImageCap ). If supports, the node <isSupportRegionalFocus> will
    be returned in the capability.

• Get or set target colorating parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/Palettes
• On Screen Display (OSD)
  • Get or set OSD parameters
    Request URL: GET or PUT /ISAPI/System/Video/inputs/channels/<ID>/overlays
  • Get or set text language of OSD
    Request URL: GET /ISAPI/System/Video/inputs/OSDLanguage

         Note
    To check if the OSD language configuration is supported by device, you can call the request
    URL: GET / to get the video capability ( XML_VideoCap ). If supports, the node
    <OSDLanguage> will be returned.

• Stream Configuration for Displaying VCA Rules of Smart Events
  • Get capability of configuring stream for displaying VCA rules of smart events
    Request URL: GET /ISAPI/Streaming/channels/<ID>/smartOverlap/capabilities?format=json
  • Get or set stream parameters for displaying VCA rules of smart events
    Request URL: GET or PUT /ISAPI/Streaming/channels/<ID>/smartOverlap?format=json

       Note
  To check if the stream configuration for displaying VCA rules of smart events is supported by the
  device, you can call the request URL: GET /ISAPI/System/capabilities to get the device capability
  ( XML_DeviceCap ). If this function is supported, the node <supportSmartOverlapChannles> will
  be returned and its value is "true".
• Target Enhancement
  • Get target enhancement capability
    Request URL: GET /ISAPI/Image/channels/<ID>/targetEnhancement/capabilities
  • Get or set target enhancement parameters
    Request URL: GET or PUT /ISAPI/Image/channels/<ID>/targetEnhancement
• Privacy Mask
  • Get configuration capability of privacy mask
    Request URL: GET /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/
    privacyMaskCap
  • Get or set privacy mask parameters
    Request URL: GET or PUT /ISAPI/System/Video/inputs/channels/<ID>/privacyMask
  • Get or set multiple privacy mask regions
    Request URL: GET or PUT /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/regions
  • Get or set one privacy mask region
    Request URL: GET or PUT /ISAPI/System/Video/inputs/channels/<ID>/privacyMask/regions/
    <ID>
• Get or set video input mode parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/capturemode
• Distortion Correction
  • Get configuration capability of distortion correction
    Request URL: GET /ISAPI/Image/channels/<ID>/lensDistortionCorrection/capabilities
  • Get or set distortion correction parameters
    Request URL: GET or PUT /ISAPI/Image/channels/<ID>/lensDistortionCorrection
• Target Cropping
  • Get configuration capability of target cropping

    Request URL: GET /ISAPI/Streaming/channels/<ID>/regionClip/capabilities
  • Get or set target cropping parameters
    Request URL: GET or PUT /ISAPI/Streaming/channels/<ID>/regionClip
• Temperature Range
  • Get temperature range configuration capability
    Request URL: GET /ISAPI/Image/channels/<ID>/tempRange/capabilities
  • Get or set temperature range
    Request URL: GET or PUT /ISAPI/Image/channels/<ID>/tempRange

13.3 Audio Settings

Basic Audio Configuration
• Get audio capability
  Request URL: GET /ISAPI/System/Audio/capabilities
• Get dynamic audio capability by channel
  Request URL: GET /ISAPI/System/Audio/channels/<ID>/dynamicCap
• Get parameters of all audio channels
  Request URL: GET /ISAPI/System/Audio/channels
• Get parameters of a specific audio channel
  Request URL: GET /ISAPI/System/Audio/channels/<ID>

Audio Input Configuration
• Get audio input capability of a specific channel
  Request URL: GET /ISAPI/System/Audio/AudioIn/channels/<ID>/capabilities
• Get or set audio input parameters of a specific channel
  Request URL: GET or PUT /ISAPI/System/Audio/AudioIn/channels/<ID>

Audio Output Configuration
• Get audio output capability of a specific channel
  Request URL: GET /ISAPI/System/Audio/AudioOut/channels/<ID>/capabilities
• Get or set audio output parameters of a specific channel
  Request URL: GET or PUT /ISAPI/System/Audio/AudioOut/channels/<ID>

13.4 Channel Settings

Basic Channel Parameters
• Get all channels' attributes
  Request URL: GET /ISAPI/AUXInfo/attributes/Channels
• Get one channel's attributes
  Request URL: GET /ISAPI/AUXInfo/attributes/Channels/<ID>

Video Input Channel
• Get configuration capability by video input channel
  Request URL: GET /ISAPI/System/Video/inputs/channels/<ID>/capabilities
• Get parameters of all video input channels
  Request URL: GET /ISAPI/System/Video/inputs/channels?format=json
• Get parameters of one video input channel
  Request URL: /ISAPI/System/Video/inputs/channels/<ID>?format=json

Video Output Channel
• Get parameters of all video outputs
  Request URL: GET /ISAPI/System/Video/outputs
• Get configuration capability by video output channel
  Request URL: GET /ISAPI/System/Video/outputs/channels/<ID>/capabilities
• Get parameters of all video output channels
  Request URL: GET /ISAPI/System/Video/outputs/channels
• Get parameters of one video output channel
  Request URL: GET /ISAPI/System/Video/outputs/channels/<ID>

Digital Channel

     Note
To check if the digital channel management or configuration is supported, you can call the request
URL: GET /ISAPI/ContentMgmt/capabilities to get the device storage management capability
( XML_RacmCap ).
• Get management capability of all digital channels
  GET /ISAPI/ContentMgmt/InputProxy/channels/capabilities
• Get management capability of one digital channel
  GET /ISAPI/ContentMgmt/InputProxy/channels/<ID>/capabilities
• Get supported number of digital channels
  Request URL: POST /ISAPI/ContentMgmt/InputProxy/sourceCapability
• Get parameters of all digital channels
  Request URL: GET /ISAPI/ContentMgmt/InputProxy/channels
• Get status of all digital channels
  Request URL: GET /ISAPI/ContentMgmt/InputProxy/channels/status
• Get, add, or delete parameters of one digital channel
  Request URL: GET, POST, or PUT /ISAPI/ContentMgmt/InputProxy/channels
• Get status of one digital channel
  Request URL: GET /ISAPI/ContentMgmt/InputProxy/channels/<ID>/status
• Get or set control parameters of a digital channel
  Request URL: GET or PUT /ISAPI/ContentMgmt/InputProxy/channels/<ID>/chanCtrl
• Reboot a digital channel

  Request URL: GET /ISAPI/ContentMgmt/InputProxy/channels/<ID>/reboot
• Check if port mapping is required for connecting to a digital channel
  Request URL: POST /ISAPI/ContentMgmt/InputProxy/channels/<ID>/portMapParam

13.5 Peripherals Settings
• Get configuration capability of built-in supplement light
  Request URL: GET /ISAPI/Image/channels/<ID>/SupplementLight/capabilities
• Get or set parameters of built-in supplement light
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/SupplementLight

       Note
  To check if configuring built-in supplement light is supported, you can call the request URL: GET /
  ISAPI/Image/channels/<ID>/capabilities to get the image channel capability
  ( XML_Cap_ImageChannel ). If supports, the node <SupplementLight> will be returned in the
  message.
