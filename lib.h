#include <ArduinoJson.h>
#include <ESP8266WiFi.h>

#ifndef weather_h
#define weather_h

class Weather {
  public:
    Weather();
    String getJson(String city, String token) {
      Serial.println("getJson called");
      String line;
      WiFiClient client;
      const int httpPort = 80;
      if (!client.connect("api.openweathermap.org", httpPort)) {
        Serial.println("connection failed");
        return "";
      }

      String query = "GET /data/2.5/weather?units=metric&q=" + city + "&appid=" + token +" HTTP/1.1";
      client.println(query);
      client.println("Host: api.openweathermap.org");
      client.println("Connection: close");
      client.println();

      delay(1500);
      // Read all the lines of the reply from server and print them to Serial
      while (client.available()) {
        line = client.readStringUntil('\r');
      }
      Serial.print(line);
      Serial.println();
      return line;
    }
    
    DynamicJsonDocument getCurrentWeatherJson(String city, String token) {
      Serial.println("Current Weather called");
      String City = city;
      String Token = token;
      String line = getJson(City, Token);
      if (line != "") {
        
        DynamicJsonDocument doc(2000);
        DeserializationError err = deserializeJson(doc, line);
        
        if (err) {
          Serial.println("parseObject() failed");             // if error accused, tell about it
          getCurrentWeatherJson(City, Token);
        }
        return doc;
      }
      else getCurrentWeatherJson(City, Token);
    }
};

extern Weather weather;
#endif
