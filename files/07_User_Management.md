# Chapter 7 User Management

You can add, edit, and delete users to manage for logging in to the device via ISAPI protocol. And
you can also assign permission to users according to actual needs.

Manage Users
• Add one user
  Request URL: GET /ISAPI/Security/users
• Get, edit, or delete all users
  Request URL: GET, PUT, or DELETE /ISAPI/Security/users
• Get, edit, or delete one user
  Request URL: GET, PUT, or DELETE /ISAPI/Security/users/<ID>

User Permission
• Get guest's permission capability
  Request URL: GET /ISAPI/Security/UserPermission/viewerCap
• Get operator's permission capability
  Request URL: GET /ISAPI/Security/UserPermission/operatorCap
• Get administrator's permission capability
  Request URL: GET /ISAPI/Security/UserPermission/adminCap
• Get User Permission
  • Get permissions of all users
    Request URL: GET /ISAPI/Security/UserPermission
  • Get permission of one user
    Request URL: GET /ISAPI/Security/UserPermission/<ID>
  • Get local permission of one user
    Request URL: GET /ISAPI/Security/UserPermission/<ID>/localPermission
  • Get remote permission of one user
    Request URL: GET /ISAPI/Security/UserPermission/<ID>/remotePermission
• Assign Permission
  • Assign permission to all users
    Request URL: PUT /ISAPI/Security/UserPermission
  • Assign permission to one user
    Request URL: PUT /ISAPI/Security/UserPermission/<ID>
  • Assign local permission to one user
    Request URL: PUT /ISAPI/Security/UserPermission/<ID>/localPermission
  • Assign remote permission to one user
    Request URL: PUT /ISAPI/Security/UserPermission/<ID>/remotePermission

Lock and Unlock User
• Get configuration capability of user locking and unlocking

  Request URL: GET /ISAPI/System/userLock/config/capabilities?format=json .
• Get information of all locked users
  Request URL: GET /ISAPI/System/userLock/lockedUsers?format=json
• Get user locking parameter
  Request URL: GET /ISAPI/System/userLock/config?format=json
• Lock user
  Request URL: PUT /ISAPI/System/userLock/config?format=json
• Unlock user
  Request URL: PUT /ISAPI/System/userLock/unlockUser?format=json

7.1 Configure Double Verification
Double verification helps to protect the critical video files of NVR/DVR by limiting playback and
download. The basic concept is that two users should always be required to start playback and
download. For example, when a normal user A (operator or guest) wants to play back the video of
a channel which requires double verification, he/she should ask a double verification user to enter
the correct user name and password for double verification.
Before You Start
Make sure you have logged in to the device.

Steps

            Figure 7-1 Programming Flow of Configuring Double Verification

    Note
• Only the admin can configure double verification.
• The admin is not required for double verification.
• The double verification user name and password is only for double verification, and cannot be
  used for login.

1. Optional: Get the device security capability via the URL: GET /ISAPI/Security/capabilities to
   check whether the double verification function is supported.
   The security capability XML_SecurityCap is returned.
2. Enable double verification via the URL: PUT /ISAPI/Security/doubleVerification?format=json

        Note
   Before enabling double verification, you can check whether double verification is enabled via
   the URL: GET /ISAPI/Security/doubleVerification?format=json .
3. Optional: Get the capability of double verification user configuration via the URL: GET /ISAPI/
   Security/doubleVerification/users/capabilities?format=json .
4. Add a double verification user via the URL: POST /ISAPI/Security/doubleVerification/users?
   format=json .

        Note
   Before adding a double verification user, you can get all verification users via the URL: GET /
   ISAPI/Security/doubleVerification/users?format=json .
   The ID of added double verification user is returned in JSON_id .
5. Edit a specified double verification user via the URL: PUT /ISAPI/Security/doubleVerification/
   users/<ID>?format=json .

        Note
   Before editing the double verification user, you can get the user information via the URL: GET /
   ISAPI/Security/doubleVerification/users/<ID>?format=json .
6. Optional: Delete a specified double verification user via the URL: DELETE /ISAPI/Security/
   doubleVerification/users/<ID>?format=json .
7. Optional: Get the capability of permission configuration for double verification users via the
   URL: GET /ISAPI/Security/doubleVerification/UsersPermission/capabilities?format=json .
8. Set the permission of a specified double verification user via the URL: PUT /ISAPI/Security/
   doubleVerification/UsersPermission/<ID>?format=json .

       Note
   Before setting the permission of a double verification user, you can get the permission
   parameters via the URL: GET /ISAPI/Security/doubleVerification/UsersPermission/<ID>?
   format=json .

What to do next
Configure the user permission, determine whether double verification are required for them
during playback and download.
