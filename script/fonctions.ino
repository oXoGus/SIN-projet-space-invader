#include <rgb_lcd.h>
#define bUp 2
#define bDown 3
#define bRight 4
#define bLeft 5
#define bShoot 6

rgb_lcd lcd_1;
int n = 0;

void setup(){
  lcd_1.begin(16, 2);
  lcd_1.setRGB(0, 0, 0);
  lcd_1.createChar(1, sprite);
}

void loop(){
  lcd_1.setCursor(0, 0);
  lcd_1.write(1);
 }