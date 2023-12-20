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
#define OK 55



int n = 0;
unsigned char select ;
unsigned char gameCounter = 0;

rgb_lcd lcd;

char lcdEnterNameLineZero[] = {
  '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'O', 'K', 
};

char lcdEnterNameLineOne[] = {
  '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'O', 'K', 
};

char alphabetUpperCase[] = {
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

char alphabetLowerCase[] = {
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};



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
                 0b00011011,
                 0b00010011,
     		         0b00000011,
         		     0b00000111,
         		     0b00000110,
         		     0b00000000,
         		     0b00000000};

byte menu4[8] = {0b00011111,
                 0b00011011,
                 0b00011001,
     		         0b00011000,
         		     0b00011100,
         		     0b00001100,
         		     0b00000000,
         		     0b00000000};



void setup(){
  
  // setup du lcd 
  lcd.begin(16, 2);
  lcd.setRGB(255, 255, 255);
  lcd.createChar(1, sprite);
  lcd.createChar(2, menu1);
  lcd.createChar(3, menu2);
  lcd.createChar(4, menu3);
  lcd.createChar(5, menu4);
  lcd.createChar(6, mob1);
  lcd.createChar(7, rock);

  Serial.begin(9600);
  // setup des boutons 
  pinMode(bUp, INPUT);
  pinMode(bDown, INPUT);
  pinMode(bLeft, INPUT);
  pinMode(bRight, INPUT);
  pinMode(bShoot, INPUT);
  pinMode(bMenu, INPUT);
}

void loop(){
  Serial.println(select); // debug
  menu(select);
  if (digitalRead(bUp)){
    select = START; 
  }
  else if (digitalRead(bDown)){
    select = SCORE;
  }
  if (select == START && digitalRead(bShoot)){
    unsigned int score = 0;
    lcd.clear();
    while(select != QUIT){
      //debut du jeu

      if (gameCounter == 0){
        // entrer le psedo du joueur
        
        lcdEnterName();
        char name ;
        Player player(name, score); // on crée l'objet joueur avec comme parametre son psedo
      } 

      
      // jeu
      // menu pause

      if (digitalRead(bMenu)){
        lcd.clear();
        while (!(select == QUIT && digitalRead(bShoot)) || !(select == BACK && digitalRead(bShoot))){
          if (digitalRead(bUp)){
            select = QUIT; 
            lcd.cursor(); // on affiche le curseur après le start  
            lcd.blink(); // clignotement du curseur 
          }
          else if (digitalRead(bDown)){
            select = BACK; 
            lcd.cursor(); // on affiche le curseur après le start  
            lcd.blink(); // clignotement du curseur
          }  
        }
      }

      // retour du jeu

      // a la mort du joueur 
      // sauvegarde en mémoir UPROM
      
    }
  }
  if (select == SCORE && digitalRead(bShoot)){
    while(!(select == QUIT && digitalRead(bShoot))){
      // on afficher ce qu'il y a dans la mémoire UPROM
    }
  }

 }

void menu(unsigned char select){
  if (select == SCORE){
    lcd.setCursor(15, 0);
    lcd.write(1);
    lcd.setCursor(15, 1);
    lcd.write(6);
    lcd.setCursor(14, 0);
    lcd.write(7);
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(3);
    lcd.print("|   Start");
    lcd.setCursor(0, 1);
    lcd.write(4);
    lcd.write(5);
    lcd.print("|  ");
    lcd.write(0b11110011);
    lcd.print("Scores");
    lcd.setCursor(0, 11);

  }
  else{
    lcd.setCursor(15, 0);
    lcd.write(1);
    lcd.setCursor(15, 1);
    lcd.write(6);
    lcd.setCursor(14, 0);
    lcd.write(7);
    lcd.setCursor(0, 0);
    lcd.write(2);
    lcd.write(3);
    lcd.print("|  ");
    lcd.write(0b11110011);
    lcd.print("Start");
    lcd.setCursor(0, 1);
    lcd.write(4);
    lcd.write(5);
    lcd.print("|   Scores");
    lcd.setCursor(0, 11);
  }
}

char lcdEnterName(){
  char pseudo[14];

  while (select != OK){
    lcd.setCursor(0, 0); // curseur a 0, 0
    for (unsigned char i; i<16; i++){
      lcd.print(lcdEnterNameLineZero[i]);
    }
    lcd.setCursor(0,1);
    for (unsigned char i; i<16; i++){
      lcd.print(lcdEnterNameLineOne[i]);
    }

  }
}









