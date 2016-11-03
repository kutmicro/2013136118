#include "Adafruit_LEDBackpack.h"           //¶óÀÌºê·¯¸®´Â Ã·ºÎ
#include "Adafruit_GFX.h"

Adafruit_7segment matrix = Adafruit_7segment();
void setup() 
{
#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);
}
void loop()
{
  matrix.print(10000, DEC);
  matrix.writeDisplay();
  delay(500);
  matrix.print(0xBEEF, HEX);
  matrix.writeDisplay();
  delay(500);
  matrix.print(12.34);
  matrix.writeDisplay();
  delay(500);
  for (uint16_t counter = 0; counter < 9999; counter++)
  {
    matrix.println(counter);
    matrix.writeDisplay();
    delay(10);
  }
  uint16_t blinkcounter = 0;
  boolean drawDots = false;
  for (uint16_t counter = 0; counter < 9999; counter ++)
  {
    matrix.writeDigitNum(0, (counter / 1000), drawDots);
    matrix.writeDigitNum(1, (counter / 100) % 10, drawDots);
    matrix.drawColon(drawDots);
    matrix.writeDigitNum(3, (counter / 10) % 10, drawDots);
    matrix.writeDigitNum(4, counter % 10, drawDots);
     blinkcounter+=50;
    if (blinkcounter < 500)
    {
      drawDots = false;
    }
    else if (blinkcounter < 1000)
    {
      drawDots = true;
    } else {
      blinkcounter = 0;
    }
    matrix.writeDisplay();
    delay(10);
}
}
