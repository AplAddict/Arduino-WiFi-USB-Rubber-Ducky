<p align="center"><img src="https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/logo.png" width="150"/></p>

# <p align="center">Arduino Pentesting Tool</p>


<p align="center"><img src="https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/preview.GIF"></p>


## Description
  My capstone project is a pentesting tool to showcase computer vulnerabilities and teach people how to secure their devices. This runs on an Arduino MKR1000. In the future, I hope to use an Arduino Uno, USB Host Shield, two Bluetooth Chips, and a joystick too add more features. Ideally it will be four devices in one: A WiFi Bad USB/USB Rubber Ducky, a WiFi Keylogger, a WiFi Deauther, & a Bluetooth mouse.
  Currently, I have an initial version of the WiFi Bad USB up and running with a nice web interface and many [features](#Current-Web-Console-Features). I’m having [issues](#Ideate) with input fields running sending extra commands to the target.
  [In the future](#Reflect), I hope to make it a WiFi deauther which uses the IEEE 802.11 protocol to send deauthentication frames to disconnect a client from WiFi. I also looked into using ARP Spoofing instead. I will be adding a USB Host Shield so you can plug a keyboard in and record what the user types. Also, I plan on adding a Bluetooth chip to communicate with the Uno that contains a joystick so that I can hijack mouse functionality. I thought of adding a keyboard however it is too bulky. I may add an input on the web interface allowing you to type anything on the computer. This is easy as long as I can figure out the text input bug.
  [Hopefully](#survey-of-approximately-20-students-after-a-demo), this project will be able to show people how vulnerable their devices are and how they can prevent these types of malicious attacks. You can view the code which consists of almost 900 lines [here](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/hack.ino).
  
  ## [Video](http://www.youtube.com/watch?v=6sug0pERvDY0)
  <p align="center"><a href="http://www.youtube.com/watch?v=6sug0pERvDY0"><img src="https://img.youtube.com/vi/6sug0pERvDY/0.jpg" width="300"></a></p>
  

  ## How To
  1. Get an Arduino MKR1000 (<a target="_blank" href="https://www.amazon.com/gp/product/B071LRYYHH/ref=as_li_tl?ie=UTF8&camp=1789&creative=9325&creativeASIN=B071LRYYHH&linkCode=as2&tag=apladdict07-20&linkId=cf213781ba0ffd4c951cc1cecbda1e24">Arduino MKR1000 WiFi with Headers [ABX00011]</a>)
  2. [Download the Arduino IDE](https://www.arduino.cc/en/software)
  3. Download the following librarys from the Arduino library manager:
      - SPI.h
      - WiFi101.h
      - rBase64.h
      - Keyboard.h
      - Mouse.h
  4. Download "Arduino SAMD Boards (32-bits ARM Cortex-M0+)" from the Arduino boards manager 
  5. Set your bord type to "Arduino MKR1000"
  7. Download the Arduino Pentesting code ([hack.h](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/hack.ino))
  8. Upload the code to your Arduino using the IDE
  9. Done!

[You can also 3d print the case.](#prototype)


  ## [crashios.com/share](https://crashios.com/share)
  CrashiOS is a website I developed using HTML/CSS/JS/PHP that initially was made as a proof of concept website that combined all iOS crash bugs and ran the ones that will affect the user's device. Over time, it became more and more effective. Now, it works on almost all versions of iOS and Google Chrome. On the newest version of iOS, it only works when launched through iMessages. CrashiOS plays a big the Arduino Pentesting Tool, it is what makes the "Attempt to crash browser" [feature](#Current-Web-Console-Features) work. According to [surveys](#survey-of-approximately-20-students-after-a-demo) I did at my school the "Attempt to crash browser" feature was people's favorite. You can view the code [here](https://github.com/AplAddict/Arduino-Pentesting-Tool/tree/main/crashios.com/public_html).
  
  
  ## Market Research
  Currently, our main competitors are the [Malduino Bad USBs by Maltronics](https://maltronics.com/collections/malduinos). They have two different versions the Malduino and the Malduino W. However, this Arduino Pentesting Tool is clearly better than the competition's. Take a look at how they match up.
  
  ### Bad USB Comparison
  Arduino Pentesting Tool | Malduino | Malduino W
------------ | ------------- | -------------
Has over 30 scripts | Only holds 3 scripts | Holds many scripts
Scripts are pre coded (great for non-tech savy users) | Scripts need to be coded | Scripts need to be coded
Scripts can be changed and run wirelessly through the WiFi web console | Needs a computer in order to upload scripts | Scripts can be changed and run wirelessly through the WiFi web console
No computer needed; everything can be done using a smart phone or any device with a search engine | Needs a computer in order to upload scripts | No computer needed; everything can be done using a smart phone or any device with a search engine
No micro SD Card needed | Needs a micro SD Card | No micro SD Card needed
Has a replacable cord so that you can hide it out of sight | Has no cord so it is harder to hide | Has no cord so it is harder to hide
Costs around $33.00 to make | Costs over $39.00 | Costs over $61.00
  
## Survey of Approximately 20 Students After a Demo
  - Were you suprised by how easy it was to mess with your computer?
    > Yes!
  - Would you have noticed the Arduino Pentesting Tool if it was plugged into your desktop computer?
    > No, I wouldn't have even thought to look!
  - Will you start checking your ports more often to make sure nothing unauthorized is plugged in?
    > For sure!
  - Which [feature](#Current-Web-Console-Features) was your favorite?
    > "Attempt to crash browser"


## Define
As you can see from the survey, this device really impacted people. They never thought a little USB looking thing would be able to affect their device so easily. The Arduino Pentesting Tool did what it was made to do! It taught those students to be more careful and to watch out for unauthorized devices plugged into their ports. I believe that schools, businesses, and government offices should have security researchers whose job is to go around and teach people using tools like this how to keep their devices safe. I am sure that once I finish implementing the rest of the features (WiFi Deauther/WiFi Arp Spoof/Keylogger/Wireless Mouse & Keyboard) people will be much more aware and able to stop their devices from being attacked.


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
I used a less common version of the Arduino MKR1000 that includes pins and headers so I had to design a custom case to protect it. It is available below or on [Thingiverse.](https://www.thingiverse.com/thing:4854251) I also made a custom vinyl decal of our logo for it.

[Bottom .stl file](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Case/Bottom.stl)

[Top .stl file](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Case/Top.stl)

<img src="https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Case/case.jpeg" width="300"/><img src="https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Case/case2.jpeg" width="300"/>


## Engineering Drawings
### Wiring Diagram
Since this project was focused on software there is only one wire. It goes from pin 7 to the reset pin so that if there are any issues you can reset the arduino remotely.

<img src="https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/wirediagram.jpeg" width="300"/>

### Code Diagrams
### WiFi Code
<img src="https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/wifidiagram.png" width="100%"/>

### Ghost Shuffle Code
<img src="https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/gsdiagram.png" width="100%"/>
Since the code file is almost 900 lines I was not able to make a flow chart of the whole thing so I chose to just do one for the WiFi code and one for the Ghost Shuffle feature code. Also, I attempted to make a diagram for the CrashiOS code however it is so deadly that when I tried uploading just the code to the flow chart software it froze the tab. 


## Reflect
The Arduino Pentesting Tool works amazingly well right now. The only thing that would need to be fixed is the user input bug mentioned in the "Ideate" section. However, I would still like to add many features.

Feature | Additional Parts | Appx. Cost $ | How?
------------ | ------------- | ------------- | -------------
WiFi Deauther | NA | NA | Uses the IEEE 802.11 protocol to send deauthentication frames to disconnect a client from WiFi.
WiFi AP Beacon | NA | NA | Spams WiFi Access Points with preconfigured names.
ARP Spoofer | NA | NA | Makes the target device think the Arduino is the wifi router effectively not allowing the device to access the internet.
Hardware Keylogger | Mini USB Host Shield | $6.10 | Keyboard is plugged into the Arduino. The Arduino records everything typed and then relays it to the computer using the Keyboard.h library.
Bluetooth Joystick Mouse | 2x HM10 & Joystick & Arduino Uno| $20 | Gets coordinates of joystick and the button state and sends it from Uno over bluetooth to the MKR where the Mouse.h library moves the cursor.

Many of these features will increase the cost and size of product so it would be best to offer a basic model and a premium model. The MKR1000 costs around $33.00 but if we are able to buy them in bulk or make our own off of the open source platform (like CIJE did with the UNO) then we could get them for even cheaper. So, we could sell the standard version for around $40.00. The premium version has around an extra $26.10 in parts however I am sure this will also be lower if we buy in bulk. Then, we could sell the premium version for around $60.00 to $65.00. Hopefully, these features could be used to show people other ways their devices are vulnerable and how they can prevent these types of malicious attacks.

This project was partially inspired by [Maltronics](https://maltronics.com).


## Current Web Console Features
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
 - Hide Desktop
 ![](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/hide.GIF)
 - Show Desktop
 ![](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/Images&Videos/show.GIF)
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

## Developer
Developed by Isaac Zipperstein ([@AplAddict](https://twitter.com/AplAddict))- Ida Crown Jewish Acdemy

Thank you to Mr. Keller & Mr. Jones


## License
[MIT](https://github.com/AplAddict/Arduino-Pentesting-Tool/blob/main/LICENSE)
