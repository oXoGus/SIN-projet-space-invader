#include <rgb_lcd.h>

rgb_lcd lcd_1;


void setup() {
  lcd_1.begin(16, 2);
  lcd.setRGB(0, 0, 0);
  lcd_1.createChar(1, playHautGauche);
  lcd_1.createChar(9, playHautDroit);
  lcd_1.createChar(10, playBasGauche);
  lcd_1.createChar(2, playBasDroit);
  lcd_1.createChar(3, playHaut1);
  lcd_1.createChar(4, playBas1);
  lcd_1.createChar(5, playHaut2);
  lcd_1.createChar(6, playBas2);
  lcd_1.createChar(7, playHaut3);
  lcd_1.createChar(8, playBas3);
}

void loop() {
  lcd_1.setCursor(0, 0);
  lcd_1.write(1);
  lcd_1.write(3);
  lcd_1.write(5);
  lcd_1.write(7);
  lcd_1.write(9);

  lcd_1.setCursor(0, 1);
  lcd_1.write(2);
  lcd_1.write(4);
  lcd_1.write(6);
  lcd_1.write(8);
  lcd_1.write(10);
}