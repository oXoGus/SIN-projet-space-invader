#include <rgb_lcd.h>
#include "player.h"
#define bUp 2
#define bDown 3
#define bRight 4
#define bLeft 5
#define bShoot 6
#define bMenu 1
#define START 16
#define SCORE 2 
#define QUIT 3
#define BACK 4



int n = 0;
unsigned char select ;
unsigned char gameCounter = 0;

rgb_lcd lcd;

char lcdEnterNameLineZero[] = {
  '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'O', 'K', 
}

char alphabetUpperCase[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

char alphabetLowerCase[] = {
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};
void setup() {
  pinMode()
}

void loop() {
  lcdEnterNme();
}


void lcdEnterName(){
  lcd.home() // curseur a 0, 0
  for (unsigned char i; i<16; i++){
    lcd.print(lcdEnterNameLineZero[i]);
  }
}

