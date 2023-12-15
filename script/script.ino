#include <rgb_lcd.h>
#define bUp 2
#define bDown 3
#define bRight 4
#define bLeft 5
#define bShoot 6

rgb_lcd lcd_1;
int n = 0;

byte sprite[8] = {0b00001110,
                 	0b00010101,
                  0b00000100,
     		          0b00001110,
         		      0b00001110,
         		      0b00000100,
         		      0b00010101,
         		      0b00001110};

byte mob1[8] = {0b00000111,
                0b00001110,
                0b00011011,
     		        0b00001110,
         		    0b00001110,
         		    0b00011011,
         		    0b00001110,
         		    0b00000111};

byte rock[8] = {0b00000000,
                0b00000000,
     		        0b00001110,
         		    0b00011111,
         		    0b00011111,
         		    0b00000110,
         		    0b00000000,
                0b00000000};

byte menu1[8] = {0b00000000,
                 0b00000000,
                 0b00000000,
     		         0b00000000,
         		     0b00001100,
         		     0b00011000,
         		     0b00011011,
         		     0b00011111};

byte menu2[8] = {0b00000000,
                 0b00000000,
                 0b00000000,
     		         0b00000000,
         		     0b00000110,
         		     0b00000011,
         		     0b00011011,
         		     0b00011111};

byte menu3[8] = {0b00011111,
                 0b00011111,
                 0b00001111,
     		         0b00000111,
         		     0b00000011,
         		     0b00000000,
         		     0b00000000,
         		     0b00000000};

byte menu4[8] = {0b00011111,
                 0b00011111,
                 0b00011110,
     		         0b00011100,
         		     0b00011000,
         		     0b00000000,
         		     0b00000000,
         		     0b00000000};



void setup(){
  lcd_1.begin(16, 2);
  lcd_1.setRGB(0, 0, 0);
  lcd_1.createChar(1, sprite);
  lcd_1.createChar(2, menu1);
  lcd_1.createChar(3, menu2);
  lcd_1.createChar(4, menu3);
  lcd_1.createChar(5, menu4);
  lcd_1.createChar(6, mob1);
  lcd_1.createChar(7, rock);

  menu();
}

void loop(){
 }

void menu(){
  lcd_1.setCursor(15, 0);
  lcd_1.write(1);
  lcd_1.setCursor(15, 1);
  lcd_1.write(6);
  lcd_1.setCursor(14, 0);
  lcd_1.write(7);

  lcd_1.setCursor(0, 0);
  lcd_1.write(2);
  lcd_1.write(3);
  lcd_1.print("|   Start");
  lcd_1.setCursor(0, 1);
  lcd_1.write(4);
  lcd_1.write(5);
  lcd_1.print("|   Scores");
}