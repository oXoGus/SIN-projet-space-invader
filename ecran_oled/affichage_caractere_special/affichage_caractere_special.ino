#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

#define IMAGE_WIDTH 128
#define IMAGE_HEIGHT 32


void setup() {
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB24_tr);
}

void loop() {
  score();
  delay(1000);
  menu();
  delay(1000);
  play();
  delay(1000);
}


void menu() {
  u8g2.clearBuffer();
  u8g2.drawStr(8, 45, "MENU");
  u8g2.sendBuffer();
}

void play() {
  u8g2.clearBuffer();
  u8g2.drawStr(15, 45, "PLAY");
  u8g2.sendBuffer();
}

void score() {
  u8g2.clearBuffer();
  u8g2.firstPage();

  int counter = 0;
  char counterStr[10];

  for (int x = 0; x < 3; x++) {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0, 16, "Score : ");
    utoa(counter, counterStr, 10);
    u8g2.sendBuffer();

    u8g2.setFont(u8g2_font_10x20_tn);
    u8g2.drawStr(70, 48, counterStr);
    u8g2.sendBuffer();
    counter++;
    delay(1000);
  }
}
