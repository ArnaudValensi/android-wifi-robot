android-wifi-robot
==================

An Arduino Robot with an Android phone embed to stream video and be drive with WiFi or 3g

Windows compil instruction
==========================

To compile on windows you have to install:
* QtSDK
* Boost (I have the 1.51.0 but it should be work with others versions)
* vlc sdk (contained on windows vlc intall, some time the second last, i have the 2.0.2 but it should be work with others versions)

You have to set some environment variable:
* BOOST_ROOT=c:\path\to\boost (contain 'boost', 'doc', 'libs', 'tools', ...)
* VLC_SDK=c:\path\to\vlc\sdk (contain 'include' and 'lib' folders)

When you have compiled, you must:
* add *.dll and 'plugins' folder located in the vlc folder
* add 'QtCore4.dll' and 'QtGui4.dll' located in the QtSDK installation