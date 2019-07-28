
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


int GAS_SENSOR = A3;

void setup(){
  
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  delay(2000);
//  display.setFont(&FreeSerif9pt7b);
  display.clearDisplay();

  
  display.setTextColor(WHITE);

}

void loop(){
  int sensor_value  = analogRead(A0);
 
  Serial.println(sensor_value);
  delay(200);
  //clear display
  display.clearDisplay();

  // display temperature
  display.setTextSize(2);
  display.setCursor(40,0);
  display.print("Gas");
  display.setTextSize(2);
  display.setCursor(40,25);
  display.print(sensor_value);
  display.setTextSize(1);
  display.setCursor(44,45);
  display.print("ppm");
  display.print(" ");
  display.display();
  delay(1000);
}

