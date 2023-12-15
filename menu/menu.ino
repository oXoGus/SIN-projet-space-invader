#include <rgb_lcd.h>

rgb_lcd lcd_1;

byte playHautGauche[8] = {0b00001111,
                 		      0b00011000,
              		        0b00010000,
             		          0b00010000,
                 		      0b00010000,
                 		      0b00010001,
                 		      0b00010001,
                 		      0b00010001};

byte playHautDroit[8] = {0b00011110,
                 		     0b00000011,
                 		     0b00000001,
                 		     0b00000001,
                 		     0b00000001,
                 		     0b00000001,
                 		     0b00000001,
                 		     0b00000001};

byte playBasGauche[8] = {0b00010001,
                 		     0b00010001,
                 		     0b00010001,
                 		     0b00010000,
                 		     0b00010000,
                 		     0b00010000,
                 		     0b00011000,
                 		     0b00001111};

byte playBasDroit[8] = {0b00000001,
                 		    0b00000001,
                 		    0b00000001,
                     		0b00000001,
                     		0b00000001,
                     		0b00000001,
                 	    	0b00000011,
                 		    0b00011110};

byte playHaut1[8] = {0b00011111,
                 	   0b00000000,
                   	 0b00000000,
                   	 0b00000000,
                   	 0b00000000,
                   	 0b00011100,
                   	 0b00000010,
                   	 0b00000010};

byte playHaut2[8] = {0b00011111,
                 	   0b00000000,
                 	   0b00000000,
                   	 0b00000000,
                   	 0b00000000,
                   	 0b00000000,
                   	 0b00000000,
                   	 0b00000000};

byte playHaut3[8] = {0b00011111,
                   	 0b00000000,
                   	 0b00000000,
                   	 0b00000000,
                   	 0b00000000,
                   	 0b00000000,
                   	 0b00000000,
                   	 0b00000000};


byte playBas1[8] = {0b00011100,
               	    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00011111};


byte playBas2[8] = {0b00000000,
               	    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00011111};

byte playBas3[8] = {0b00000000,
               	    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00000000,
                    0b00011111};


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