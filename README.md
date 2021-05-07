# Arduino-Pentesting-Tool
Arduino MKR 1000 Pentesting Tool

![](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/preview.mov)

## Description
  My capstone project is a pentesting tool to showcase computer vulnerabilities and teach people how to secure their devices. This runs on an Arduino MKR1000. In the future, I hope to use an Arduino Uno, USB Host Shield, two Bluetooth Chips, and a joystick too add more features. Ideally it will be four devices in one: A WiFi Bad USB/USB Rubber Ducky, a WiFi Keylogger, a WiFi Deauther, & a Bluetooth mouse.
  Currently, I have an initial version of the WiFi Bad USB up and running with a nice web interface and many features. I’m having issues with input fields running sending extra commands to the target.
  In the future, I hope to make it a WiFi deauther which uses the IEEE 802.11 protocol to send deauthentication frames to disconnect a client from WiFi. I also looked into using ARP Spoofing instead. I will be adding a USB Host Shield so you can plug a keyboard in and record what the user types. Also, I plan on adding a Bluetooth chip to communicate with the Uno that contains a joystick so that I can hijack mouse functionality. I thought of adding a keyboard however it is too bulky. I may add an input on the web interface allowing you to type anything on the computer. This is easy as long as I can figure out the text input bug.
  Hopefully, this project will be able to show people how vulnerable their devices are and how they can prevent these types of malicious attacks. [Watch our video.](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/video.mov)
  
## Currently Features In the Web Console
### Universal
 - Zoom In
 - Zoom Out
 - Ghost Deleter
 - Ghost Shuffle
### Windows
 - Test
 - Lock Computer
 - Logout
 - Shutdown
 - RickRoll
 - Invert Colors (only works on some versions of windows)
 - Say: user input
 - Open url: user input
 - Attempt to crash browser
 - Rotate left
 - Rotate right
 - Rotate down
 - Rotate up
### Mac
 - Test
 - Launch Voice Over
 - Quit Current App
 - Quit All Apps
 - Log Out
 - Close Web Browser Tab
 - Hide Desktop ([Video Demo](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/hide&show.mov))
 - Show Desktop ([Video Demo](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/hide&show.mov))
 - Max Volume
 - Say: user input
 - Change Wallpaper to: user input
 - Open Url: user input
 - Attempt To Crash Browser
 - View Web Browser History
### Linux
 - Test
 - Lock
 - Logout
 - Shutdown
 - Reboot
 - Launch Reverse Shell


## Currently used Components
 - Arduino MKR1000

## Future Components
 - Arduino Uno
 - USB Host Shield
 - Two HM-10 Bluetooth Chips
 - Joystick

## License
[MIT](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/LICENSE)
