#include <rgb_lcd.h>
#define bUp 2
#define bDown 3
#define bRight 4
#define bLeft 5
#define bShoot 6


int n = 0;
rgb_lcd ldc;

void setup()
{
  lcd.begin(16, 2);
  lcd.print(maFonc(6, 3));
}

void loop()
{
  if(digitalRead(bShoot)){
    lcd.clear();
    lcd.print(n);
    n++;
    delay(75);
 }
}