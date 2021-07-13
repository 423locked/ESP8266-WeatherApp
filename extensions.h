#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789

#ifndef extensions_h
#define extensions_h

class Extensions {
  public:
    Extensions();

    void displayWeatherText(DynamicJsonDocument weatherObj, Adafruit_ST7789 tft) {

      String city = String(weatherObj["name"]);
      String wind = "Wind " + String(weatherObj["wind"]["speed"]) + " m/s";
      String humidity = "Humidity " + String(weatherObj["main"]["humidity"]) + " %";
      String cloudiness = "Clouds " + String(weatherObj["clouds"]["all"]) + " %";
      String pressure = "Pressure " + String(weatherObj["main"]["pressure"]) + " mmHc";
      String temp = "T = " + String(weatherObj["main"]["temp"]) + " C";

      printTextOnCursor(city, 3, 20, 30, tft);
      printTextOnCursor(wind, 2, 20, 70, tft);
      printTextOnCursor(humidity, 2, 20, 90, tft);
      printTextOnCursor(cloudiness, 2, 20, 110, tft);
      printTextOnCursor(pressure, 2, 20, 130, tft);
      printTextOnCursor(temp, 3, 20, 180, tft);
    }

    String getState(String WeatherMain) {

      if (WeatherMain == "Clear")
        return "clear";
      if (WeatherMain == "Snow")
        return "snow";

      char *rains[4] = { "Thunderstorm", "Rain", "Tornado", "Drizzle"};
      for (int i = 0; i < 4; i++)
        if (WeatherMain == rains[i])
          return "rain";

      char *clouds[10] = { "Clouds",  "Mist", "Smoke", "Haze", "Dust", "Fog", "Sand", "Dust", "Ash", "Squall" };
      for (int i = 0; i < 10; i++)
        if (WeatherMain == clouds[i])
          return "clouds";

      return "error";
    }

    void printText(String text, uint16_t color, int textSize, Adafruit_ST7789 tft) {
      tft.setTextWrap(false);
      tft.setTextSize(textSize);
      tft.setTextColor(color);
      tft.println(text);
    }

    void printTextOnCursor(String text, int textSize, int X, int Y, Adafruit_ST7789 tft) {
      tft.setCursor(X, Y);
      tft.setTextWrap(false);
      tft.setTextSize(textSize);
      tft.setTextColor(ConvertRGB(23, 232, 225), ST77XX_BLACK);
      tft.print(text);
    }
    
    word ConvertRGB( byte R, byte G, byte B)
    {
      return ( ((R & 0xF8) << 8) | ((G & 0xFC) << 3) | (B >> 3) );
    }
};

extern Extensions extensions;
#endif
