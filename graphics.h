#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789

/*
   There is a handy function to convert rgb to uint16_t called rgb()
   But when initializing the const colors, you can't use functions in the class, that's
   why you should try using https://www.rgbtohex.net to convert your rgb colors into (0x+"hex")
*/

#ifndef graphics_h
#define graphics_h

class Graphics {
  public:
    Graphics();

    void drawSun(uint16_t mainColor, uint16_t borderColor, Adafruit_ST7789 tft) {
      for (int i = 61; i <= 68; i++)
        tft.drawCircle(120, 80, i, mainColor);
      tft.fillCircle(120, 80, 60, borderColor);
    }

    void drawCloud(uint16_t mainColor, uint16_t borderColor, Adafruit_ST7789 tft) {
      // Cloud base border
      tft.fillRoundRect(35, 66, 170, 70, 25, borderColor);

      // Cloudpart borders
      tft.fillCircle(52, 100, 34, borderColor);
      tft.fillCircle(188, 100, 34, borderColor);
      tft.fillCircle(58, 92, 40, borderColor);
      tft.fillCircle(90, 70, 34, borderColor);
      tft.fillCircle(140, 60, 44, borderColor);
      tft.fillCircle(175, 75, 24, borderColor);


      // Cloud base drawing
      tft.fillRoundRect(40, 70, 160, 61, 20, mainColor);

      // Cloudpart drawings
      tft.fillCircle(52, 100, 30, mainColor);
      tft.fillCircle(188, 100, 30, mainColor);
      tft.fillCircle(58, 92, 37, mainColor);
      tft.fillCircle(90, 70, 30, mainColor);
      tft.fillCircle(140, 60, 40, mainColor);
      tft.fillCircle(175, 75, 20, mainColor);
    }

    void drawSnow(uint16_t color, Adafruit_ST7789 tft) {
      int X[20];
      X[0] = 30;
      X[1] = 40;
      X[2] = 48;
      X[3] = 54;
      X[4] = 62;
      X[5] = 68;
      X[6] = 74;
      X[7] = 81;
      X[8] = 89;
      X[9] = 96;
      X[10] = 107;
      X[11] = 114;
      X[12] = 122;
      X[13] = 134;
      X[14] = 145;
      X[15] = 161;
      X[16] = 169;
      X[17] = 177;
      X[18] = 189;
      X[19] = 198;

      int Y[20];
      Y[0] = 154;
      Y[1] = 171;
      Y[2] = 184;
      Y[3] = 167;
      Y[4] = 161;
      Y[5] = 179;
      Y[6] = 156;
      Y[7] = 164;
      Y[8] = 162;
      Y[9] = 171;
      Y[10] = 182;
      Y[11] = 165;
      Y[12] = 155;
      Y[13] = 189;
      Y[14] = 170;
      Y[15] = 156;
      Y[16] = 184;
      Y[17] = 196;
      Y[18] = 176;
      Y[19] = 149;

      for (int i = 0; i < 20; i++)
        tft.fillRoundRect(X[i], Y[i], 4, 6, 3, color);
    }

    void drawRain(uint16_t color, Adafruit_ST7789 tft) {
      int X[9];
      X[0] = 40;
      X[1] = 62;
      X[2] = 66;
      X[3] = 93;
      X[4] = 110;
      X[5] = 130;
      X[6] = 149;
      X[7] = 168;
      X[8] = 190;

      int Y[9];
      Y[0] = 172;
      Y[1] = 150;
      Y[2] = 195;
      Y[3] = 160;
      Y[4] = 180;
      Y[5] = 170;
      Y[6] = 200;
      Y[7] = 155;
      Y[8] = 176;

      for (int i = 0; i < 9; i++)
        tft.fillRoundRect(X[i], Y[i], 7, 14, 6, color);
    }


};




extern Graphics gr;
#endif
