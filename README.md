# ESP8266-WeatherApp

<br>

## ESP8266 (microcontroller) is connected to an IPS screen GMT 130 and displays different weather information with associated icon images.

<br>

> ## _Installation_

<br>

## Before starting, don't forget to import four essential libraries.
````
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <ArduinoJson.h>     // JSON Parsing library
#include <ESP8266WiFi.h>     // Hardware ESP8266 wifi library
````

<br><br>
> ## All the configuration and settings are changed in the **app.ino** file
> ![Configuration](https://i.ibb.co/QPt9vwG/settings.png)

<br><br>

### 1. Firstly, connect your devices according on the [scheme](https://github.com/423locked/GMT130-ESP8266).
### 2. Secondly, copy the initial project repository and open the app.ino file via Arduino IDE.
### 3. Install the needed libraries.
### 4. Alter the configurations (your WiFi credentials, [API](https://openweathermap.org/api) key/token and necessary cities).
### 5. Compile and upload the code to the ESP8266 microcontroller.
### 6. Enjoy!

<br>
<br>
<br>

> ## _Project Information_

### Weather icon images
![Weather_Icons](https://i.ibb.co/9N5nxtF/icons.pg)

<br>

### Weather parameteres
![Weather_Parameters](https://i.ibb.co/hsWQvJh/Params.p)

## These are the features that are currently implemented in the project:
* ### Connection to the IPS screen
* ### Connection to your home WiFi
* ### Creating [API](https://openweathermap.org/api) queries with your token and city/array of cities
* ### Displaying icon images according on the weather state
* ### Parsing JSON
* ### Displaying weather parametres received from the API

<br><br>

## The application pipeline:
* ### Connect to the WiFi
* ### Make a GET request to an API
* ### Parse received JSON document
* ### Parse weather state
* ### Display weather icon according on the local state
* ### (shows it for 3 seconds)
* ### Display weather parametres
* ### (shows them for 10 seconds)
* ### loop


<br><br>


