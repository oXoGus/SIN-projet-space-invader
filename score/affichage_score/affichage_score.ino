#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

int counter = 0;

#define IMAGE_WIDTH 128
#define IMAGE_HEIGHT 32

void setup() {
  u8g2.begin();
}

void loop() {
  score(counter);
  counter++;
  delay(1000);
}

void score(int x){
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    char buffer[20];
    sprintf(buffer, "Score :");
    u8g2.drawStr(0, 16, buffer);

    char buffer2[20];
    u8g2.setFont(u8g2_font_10x20_tn);
    sprintf(buffer2, "%d", x);
    u8g2.drawStr(10, 48, buffer2);

  } while (u8g2.nextPage());
}