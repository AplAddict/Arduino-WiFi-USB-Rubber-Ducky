# Arduino-Pentesting-Tool
Arduino MKR 1000 Pentesting Tool
  
  
  My capstone project is an all in one pentesting tool to showcase computer vulnerabilities and teach people how to secure their devices. This runs on an Arduino MKR1000 using an Arduino Uno, USB Host Shield, two Bluetooth Chips, and a joystick. Ideally it will be four devices in one: A WiFi Bad USB/USB Rubber Ducky, a WiFi Keylogger, a WiFi Deauther, & a Bluetooth mouse.
       Currently, I have an initial version of the WiFi Bad USB up and running with a nice web interface and many features (pictured right). I’m having issues with input fields running sending extra commands to the target. I have begun attaching the USB shield to the MKR for the Keylogger (to record keyboard input). 
       In the future, I hope to make it a WiFi deauther which uses the IEEE 802.11 protocol to send deauthentication frames to disconnect a client from WiFi. I also looked into using ARP Spoofing instead. I plan on adding a Bluetooth chip to communicate with the Uno that contains a joystick so that I can hijack mouse functionality. I thought of adding a keyboard however it is too bulky. I may add an input on the web interface allowing you to type anything on the computer. This is easy as long as I can figure out the text input bug.
       Hopefully, this project will be able to show people how vulnerable their devices are and how they can prevent these types of malicious attacks.
