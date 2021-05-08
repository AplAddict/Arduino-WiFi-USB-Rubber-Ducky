# Arduino-Pentesting-Tool
Arduino MKR 1000 Pentesting Tool

![](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/preview.mov)

## Description
  My capstone project is a pentesting tool to showcase computer vulnerabilities and teach people how to secure their devices. This runs on an Arduino MKR1000. In the future, I hope to use an Arduino Uno, USB Host Shield, two Bluetooth Chips, and a joystick too add more features. Ideally it will be four devices in one: A WiFi Bad USB/USB Rubber Ducky, a WiFi Keylogger, a WiFi Deauther, & a Bluetooth mouse.
  Currently, I have an initial version of the WiFi Bad USB up and running with a nice web interface and many features. I’m having issues with input fields running sending extra commands to the target.
  In the future, I hope to make it a WiFi deauther which uses the IEEE 802.11 protocol to send deauthentication frames to disconnect a client from WiFi. I also looked into using ARP Spoofing instead. I will be adding a USB Host Shield so you can plug a keyboard in and record what the user types. Also, I plan on adding a Bluetooth chip to communicate with the Uno that contains a joystick so that I can hijack mouse functionality. I thought of adding a keyboard however it is too bulky. I may add an input on the web interface allowing you to type anything on the computer. This is easy as long as I can figure out the text input bug.
  Hopefully, this project will be able to show people how vulnerable their devices are and how they can prevent these types of malicious attacks. [Watch our video](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/video.mov). You can view the code which consists of almost 900 line [here](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/hack.ino).
  
  ## [crashios.com/share](https://crashios.com/share)
  CrashiOS is a website I developed using HTML/CSS/JS/PHP that initially was made as a proof of concept website that combined all iOS crash bugs and ran the ones that will effect the users device. Over time, it became more and more effective. Now, it works on almost all versions of iOS and google chrome. On the newest version of iOS, it only works when launched through iMessages. CrashiOS plays a big the Arduino Pentesting Tool, it is what makes the "Attempt to crash browser" feature work. According to surveys I did at my school the "Attempt to crash browser" feature was peoples favorite. You can view the code [here](https://github.com/AplAddict/Arduino-Pentesting-Tool/tree/main/crashios.com/public_html).
  
  ## Market Research
  Currently, our main competitors are the [Malduino Bad USBs by Maltronics](https://maltronics.com/collections/malduinos). They have two different versions the Malduino and the Malduino W. However, this Arduino Pentesting Tool is clearly better than the competitions. Take a look at how they mach up.
  ### Bad USB Comparison
  #### Arduino Pentesting Tool
  - Has over 30 scripts pre coded (great for non-tech savy users)
  - Scripts can be changed and run wirelessly through the WiFi web console
  - No computer needed everything can be done using a smart phone or any device with a search engine
  - No micro SD Card needed
  - Has a replacable cord so that you can hide it out of sight.
  - Costs around 33$ to make.
  #### Malduino
  - Only holds 3 scripts
  - Scripts need to be coded
  - Needs a computer in order to upload scripts
  - Needs to be taken apart and then a switch has to be flipped to change the script that is currently running
  - Needs a micro SD Card
  - Has no cord so it is harder to hide
  - Costs over $39.00
  #### Malduino W
  - Holds many scripts
  - Scripts need to be coded
  - Scripts can be changed and run wirelessly through the WiFi web console
  - Scripts can be uploaded 
  - No micro SD Card needed
  - Has no cord so it is harder to hide.
  - Costs over $61.00
  
## Survey of Approximately 20 Students After a Demo
  - Were you suprised by how easy it was to mess with your computer?
    - Yes!
  - Would you have noticed the Arduino Pentesting Tool if it was plugged into your desktop computer?
    - No, I wouldn't have even thought to look!
  - Will you start checking your ports more often to make sure nothing unauthorized is plugged in?
    - For sure!
  - Which feature was your favorite?
    - "Attempt to crash browser"

## Define
As you can see from the survey, this device really impacted people. They never thought a little USB looking thing would be able to affect their device so easily. The Arduino Pentesting Tool did what it was made to do! It taught those students to be more careful and to watch out for unauthorized devices plugged into their ports. I believe that schools and businesses should have security researchers whos job is to go around and teach people using tools like this how to keep their devices safe. I am sure that once I finish implementing the rest of the features (WiFi Deauther/WiFi Arp Spoof/Keylogger/Wireless Mouse & Keyboard) people will be much more aware and able to stop their device from being attacked.

## Ideate
When developing the Arduino Pentesting Tool I had major issues with the user input text fields. First, I had to figure out how I was going to get the user input from the web console to the Arduino. [Online](https://blog.startingelectronics.com/html-text-box-to-send-text-to-arduino-web-server/), the only solution people had was creating an Ajax I/O web server and sending GET requests to it. This seemed way too complicated and slow for my application so I tried brainstorming for another way to do it. I had an idea! I decided to send the text in the url path. However, there was an issue. When passing complicated strings like URLs there are charcters and strings I can't pass in the URL without having issues like "://". So, I decided to use base64 encryption first. I then wrote up some basic HTML & JS to encode the user input and pass it to the arduino.

Example:
```html
"What You Would Like The Computer To Say: <input type=\"text\" id=\"WSAY\" name=\"WSAY\"><input type=\"submit\" onclick=\"window.location.replace('http://192.168.1.1/' + btoa(document.getElementById('WSAY').value) + '/wsay');\"><br>
```
After that, I had code a way for the Arduino to recieve that encoded text and decode it.
```C++
else if (currentLine.endsWith("/wsay"))
  {
    wsay(currentLine);
  }
  
...

void wsay(String currentLine)
{
  rbase64.decode(currentLine.substring(5, currentLine.length() - 5));
  String url = rbase64.result();
  
...
```
Sadly, there was another issue. The code was running correctly once but then automaticaly running again a couple more times with gibberish as the text. I thought the problem was the base64 library I was using so I tried a few others. This didn't make a difference so I stuck with the "<rBase64.h>" library. I tried many many things including using a ton of print statements to follow the user inputted text and pinpoint where it gets messed up. I was never able to do so. Instead, I lowered the affect it had by finding some of the gibberish it passed through and making sure not too include it: 
```C++
if (url.endsWith("z����i����o�����_�") != true)
```
This is the only bug I wasn't able to solve and one of the ones I spent the longest working on. I hope this gives you a small taste of what it was like developing this.

## Prototype
I used a less common version of the Arduino MKR1000 that includes pins and headers so I had to design a custom case to protect it.

[Bottom](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/case/Bottom.stl)

[Top](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/case/Top.stl)

[![View Image](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/case/Case.jpeg)](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/case/Case.jpeg)

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
