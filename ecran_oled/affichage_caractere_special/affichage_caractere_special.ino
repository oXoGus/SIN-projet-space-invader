#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB24_tr);
}

void loop() {
  u8g2.clearBuffer();

  u8g2.drawStr(15, 45, "PLAY");
  u8g2.sendBuffer();
  delay(1000);
  u8g2.clearBuffer();

  u8g2.drawStr(8, 45, "MENU");
  u8g2.sendBuffer();
  delay(1000);
  u8g2.clearBuffer();
}
