#include "lib.h"
#include "extensions.h"
#include "graphics.h"

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <ArduinoJson.h>     // JSON Parsing library
#include <ESP8266WiFi.h>     // Hardware ESP8266 wifi library

// ST7789 TFT module connections
#define TFT_DC    D1     // TFT DC  pin is connected to NodeMCU pin D1 (GPIO5)
#define TFT_RST   D2     // TFT RST pin is connected to NodeMCU pin D2 (GPIO4)
#define TFT_CS    D8     // TFT CS  pin is connected to NodeMCU pin D8 (GPIO15)

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

word rgb( byte R, byte G, byte B) {
  return ( ((R & 0xF8) << 8) | ((G & 0xFC) << 3) | (B >> 3) );
}

const uint16_t regularBlueCloud  = rgb(96, 170, 246);
const uint16_t regularBlueBorder = rgb(57, 128, 203);
const uint16_t rainColor         = rgb(57, 162, 219);
const uint16_t snowColor         = rgb(221, 223, 225);
const uint16_t sunColor          = rgb(244, 218, 39);
const uint16_t sunBorderColor    = rgb(235, 169, 26);

DynamicJsonDocument doc(2000);

// api - https://openweathermap.org/api
String token = "{YOUR_API_KEY}";
String cities[] = {"Moscow", "Berlin", "Prague"};
String wifiName = "YOUR_WIFI_NETWORK_NAME";
String wifiPass = "password123";



int cityCounter = 0;
int cityAmount = sizeof(cities)/sizeof(cities[0]);

void setup() {
  Serial.begin(9600);
  Serial.println("123");
  // SCREEN INITIALIZATION
  tft.init(240, 240, SPI_MODE2);
  tft.setRotation(2);
  tft.fillScreen(ST77XX_BLACK);

  tft.println("Screen initialized.");

  // WIFI INITIALIZATION
  WiFi.begin(wifiName, wifiPass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    tft.print(".");
  }

  tft.println("\nWiFi connected");


  doc = weather.getCurrentWeatherJson(cities[0], token);
}

void loop() {
  tft.fillScreen(ST77XX_BLACK);

  String stateCode = extensions.getState(doc["weather"][0]["main"]);
  
  Serial.println("WeatherMain = " + String(doc["weather"][0]["main"]));
  Serial.println("stateCode = " + stateCode);

  if (stateCode == "clear")
    gr.drawSun(sunColor, sunBorderColor, tft);

  else if (stateCode == "clouds")
    gr.drawCloud(regularBlueCloud, regularBlueBorder, tft);

  else if (stateCode == "rain") {
    gr.drawCloud(regularBlueCloud, regularBlueBorder, tft);
    gr.drawRain(rainColor, tft);
  }

  else if (stateCode == "snow") {
    gr.drawCloud(regularBlueCloud, regularBlueBorder, tft);
    gr.drawSnow(snowColor, tft);
  }

  delay(3000);
  tft.fillScreen(ST77XX_BLACK);


  extensions.displayWeatherText(doc, tft);
  delay(10000);

  if (cityCounter + 1 < cityAmount)
    cityCounter++;
  else
    cityCounter = 0;
    
  Serial.println("\nCITYCOUNTER = ");
  Serial.print(cityCounter); 
  Serial.println("\nCITYAMOUNT = " );
  Serial.print(cityAmount);
  Serial.println(); Serial.println();
  
  doc = weather.getCurrentWeatherJson(cities[cityCounter], token);
  
}
