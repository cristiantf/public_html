# Chapter 10 PTZ Control

PTZ control is to implement the panning, tilting, zoom functions of cameras, set presets for specific
monitoring areas to fast switch the cameras as needed, and group the user-defined presets as a
scanning track for patrol.

Basic PTZ Parameters
• Get PTZ control capability
  Request URL: GET /ISAPI/PTZCtrl/channels/<ID>/capabilities
• Get or set zoom/focus coordinate parameters
  Request URL: GET or PUT /ISAPI/PTZCtrl/channels/<ID>/zoomFocus
• Maximum Tilt Angle
  • Get configuration capability of maximum tilt angle
    Request URL: GET /ISAPI/PTZCtrl/channels/<ID>/maxelevation/capabilities
  • Get or set parameters of maximum tilt angle
    Request URL: GET or PUT /ISAPI/PTZCtrl/channels/<ID>/maxelevation .
• Get PTZ position information of current channel
  Request URL: GET /ISAPI/PTZCtrl/channels/<ID>/save
• Set PTZ position information of current channel
  Request URL: PUT /ISAPI/PTZCtrl/channels/<ID>/save?format=json
• Get PTZ status of a specific channel
  Request URL: GET /ISAPI/PTZCtrl/channels/<ID>/status

Other PTZ Parameters
• Lens
  • Initialize lens
    Request URL: PUT /ISAPI/PTZCtrl/channels/<ID>/onepushfoucs/reset
  • Get lens correction capability
    Request URL: GET /ISAPI/PTZCtrl/channels/<ID>/lensCorrection/capabilities?format=json
  • Get or set lens correction parameters
    Request URL: GET or PUT /ISAPI/PTZCtrl/channels/<ID>/lensCorrection?format=json

         Note
    To check if the lens correction is supported by device, you can call the request URL: GET /
    ISAPI/PTZCtrl/channels/<ID>/capabilities to get the PTZ control capability
    ( XML_PTZChanelCap ). If supports, the node <isSupportLensCorrection> will be returned.

• Get or set PTZ locking time duration
  Request URL: GET or PUT /ISAPI/PTZCtrl/channels/<ID>/lockPTZ

       Note
  You can call the request URL: GET /ISAPI/PTZCtrl/channels/<ID>/capabilities to get the
  supported locking time duration (<lockTime>) from the PTZ control capability
  ( XML_PTZChanelCap ).
• Get or set PTZ OSD parameters
  Request URL: GET or PUT /ISAPI/PTZCtrl/channels/<ID>/PTZOSDDisplay

PTZ Auxiliaries Control
• Get or set all PTZ auxiliaries status
  Request URL: GET or PUT /ISAPI/PTZCtrl/channels/<ID>/auxcontrols
• Get or set the status of single PTZ auxiliary
  Request URL: GET or PUT /ISAPI/PTZCtrl/channels/<ID>/auxcontrols/<ID>

E-PTZ Parameters
• Get or set e-PTZ parameters
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/EPTZ
• Get capability of switching e-PTZ mode
  Request URL: GET /ISAPI/Image/channels/<ID>/EPTZ/mode/capabilities?format=json
• Get or set parameters of switching e-PTZ mode
  Request URL: GET or PUT /ISAPI/Image/channels/<ID>/EPTZ/mode?format=json
