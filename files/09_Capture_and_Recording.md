# Chapter 9 Capture and Recording

For some remarkable views in the live view, you can manually capture the views or record the
video segments and save the captured pictures or videos to the configured storage. For recording,
you can also configure recording schedule to record videos continuously or based on command or
event.

Capture
Request URL: GET /ISAPI/Streaming/channels/<ID>/picture
Recording
• Get video track type
  Request URL: GET /ISAPI/ContentMgmt/record/profile
• Set storage for recorded files
  Request URL: /ISAPI/ContentMgmt/record/storageMounts

       Note
  To check if setting recording storage is supported, you can call the request URL: GET /ISAPI/
  ContentMgmt/capabilities to get the device storage management capability ( XML_RacmCap ).
• Recording Schedule
  • Get configuration capability of a recording schedule
    Request URL: GET /ISAPI/ContentMgmt/record/tracks/<ID>/capabilities
  • Get all recording schedules
    Request URL: GET /ISAPI/ContentMgmt/record/tracks
  • Add a recording schedule
    Request URL: POST /ISAPI/ContentMgmt/record/tracks
  • Set a recording schedule
    Request URL: PUT /ISAPI/ContentMgmt/record/tracks/<ID>
• Manual Recording
  • Start manual recording
    Request URL: POST /ISAPI/ContentMgmt/record/control/manual/start/tracks/<ID>
  • Stop manual recording
    Request URL: POST /ISAPI/ContentMgmt/record/control/manual/stop/tracks/<ID>
