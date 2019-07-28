#include <YoutubeApi.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET LED_BUILTIN
Adafruit_SSD1306 display(OLED_RESET);
 
//------- Replace the following! ------
char ssid[] = "IoTIAN";       // your network SSID (name)
char password[] = "birla$$8319";  // your network key
#define API_KEY "AIzaSyByDuSX-FLifLrSwttwOvZrI44RP9-KYBE"  // your google apps API Token
#define CHANNEL_ID "UCa4EPxD8tbDejcYBIrmSX6Q" // makes up the url of channel
String chanelName = "IoTIAN Innovator";

int nextStatDelay = 5000;
 
WiFiClientSecure client;
YoutubeApi api(API_KEY, client);
 
int api_mtbs = 60000;
long api_lasttime;
long subs = 0;

#if (SSD1306_LCDHEIGHT != 64)
//#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup()   {                
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(13,17);
  display.println("IoTIAN Innovator");
  display.setCursor(27,35);
  display.println("counter");
  display.display();
 
  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
 
  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
}
 
void loop() {
  if (millis() > api_lasttime + api_mtbs)  {
    if (api.getChannelStatistics(CHANNEL_ID)) {
      Serial.println("---------Stats---------");
      Serial.print("Subscriber Count: ");
      Serial.println(api.channelStats.subscriberCount);
      Serial.print("View Count: ");
      Serial.println(api.channelStats.viewCount);
      Serial.print("Video Count: ");
      Serial.println(api.channelStats.videoCount);
      Serial.println("------------------------");
    }
    api_lasttime = millis();
  }
  
  //SUBSCIBER COUNT
  long subcountme = api.channelStats.subscriberCount;
 
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(5, 0);
  display.println("Subscriber:");
 
  if (subcountme == 0) {
    display.setTextSize(1);
    display.setCursor(34, 24);
    display.println("loading ...");
  } else {
    display.setTextSize(1);
    if (subcountme < 10) {
      display.setCursor(60, 24);
    }
    if (subcountme > 9 && subcountme < 100) {
      display.setCursor(60, 24);
    }
    if (subcountme > 99 && subcountme < 1000) {
      display.setCursor(56, 24);
    }
    if (subcountme > 999 && subcountme < 10000) {
      display.setCursor(52, 24);
    }
    if (subcountme > 9999 && subcountme < 100000) {
      display.setCursor(48, 24);
    }
    if (subcountme > 99999 && subcountme < 1000000) {
      display.setCursor(44, 24);
    }
    if (subcountme > 999999 && subcountme < 10000000) {
      display.setCursor(40, 24);
    }
    if (subcountme > 9999999 && subcountme < 100000000) {
      display.setCursor(36, 24);
    }
    if (subcountme > 99999999 && subcountme < 1000000000) {
      display.setCursor(32, 24);
    }
    display.println(String(subcountme));
  }

  display.setCursor(0, 50);
  display.println("YouTube: " + chanelName);

  display.display();

  delay(nextStatDelay);

  //VIEW COUNT
  long viewcountme = api.channelStats.viewCount;
 
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(30, 0);
  display.println("Views:");
 
  if (viewcountme == 0) {
    display.setTextSize(1);
    display.setCursor(34, 24);
    display.println("loading ...");
  } else {
    display.setTextSize(1);
    if (viewcountme < 10) {
      display.setCursor(60, 24);
    }
    if (viewcountme > 9 && subcountme < 100) {
      display.setCursor(60, 24);
    }
    if (viewcountme > 99 && subcountme < 1000) {
      display.setCursor(56, 24);
    }
    if (viewcountme > 999 && subcountme < 10000) {
      display.setCursor(52, 24);
    }
    if (viewcountme > 9999 && subcountme < 100000) {
      display.setCursor(48, 24);
    }
    if (viewcountme > 99999 && subcountme < 1000000) {
      display.setCursor(44, 24);
    }
    if (viewcountme > 999999 && subcountme < 10000000) {
      display.setCursor(40, 24);
    }
    if (viewcountme > 9999999 && subcountme < 100000000) {
      display.setCursor(36, 24);
    }
    if (viewcountme > 99999999 && subcountme < 1000000000) {
      display.setCursor(32, 24);
    }
    display.println(String(viewcountme));
  }

  display.setCursor(0, 50);
  display.println("YouTube: " + chanelName);

  display.display();

  delay(nextStatDelay);

  //VIDEOS COUNT
  long videocountme = api.channelStats.videoCount;
 
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(25, 0);
  display.println("Videos:");
 
  if (videocountme == 0) {
    display.setTextSize(1);
    display.setCursor(34, 24);
    display.println("loading ...");
  } else {
    display.setTextSize(1);
    if (videocountme < 10) {
      display.setCursor(60, 24);
    }
    if (videocountme > 9 && subcountme < 100) {
      display.setCursor(60, 24);
    }
    if (videocountme > 99 && subcountme < 1000) {
      display.setCursor(56, 24);
    }
    if (videocountme > 999 && subcountme < 10000) {
      display.setCursor(52, 24);
    }
    if (videocountme > 9999 && subcountme < 100000) {
      display.setCursor(48, 24);
    }
    if (videocountme > 99999 && subcountme < 1000000) {
      display.setCursor(44, 24);
    }
    if (videocountme > 999999 && subcountme < 10000000) {
      display.setCursor(40, 24);
    }
    if (videocountme > 9999999 && subcountme < 100000000) {
      display.setCursor(36, 24);
    }
    if (videocountme > 99999999 && subcountme < 1000000000) {
      display.setCursor(32, 24);
    }
    display.println(String(videocountme));
  }

  display.setCursor(0, 50);
  display.println("YouTube: " + chanelName);

  display.display();

  delay(nextStatDelay);
}
