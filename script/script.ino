#include <rgb_lcd.h>
#define bUp 2
#define bDown 3
#define bRight 4
#define bLeft 5
#define bShoot 6
#define START 1
#define SCORE 2 


rgb_lcd lcd;
int n = 0;
unsigned char select;
unsigned char gameCounter = 0;

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
  lcd.setRGB(0, 0, 0);
  lcd.createChar(1, sprite);
  lcd.createChar(2, menu1);
  lcd.createChar(3, menu2);
  lcd.createChar(4, menu3);
  lcd.createChar(5, menu4);
  lcd.createChar(6, mob1);
  lcd.createChar(7, rock);

  // setup des boutons 
  pinMode(bUp, INPUT);
  pinMode(bDown, INPUT);
  pinMode(bLeft, INPUT);
  pinMode(bRight, INPUT);
  pinMode(bShoot, INPUT);
}

void loop(){
  menu();
  if (digitalRead(bUp)){
    select = START; 
    lcd.setCursor(0, 11); 
    lcd.lcdcursor(); // on affiche le curseur après le start  
    lcd.blink(); // clignotement du curseur 
  }
  else if (digitalRead(bDown)){
    select = SCORE; 
    lcd.setCursor(1, 12); 
    lcd.lcdcursor(); // on affiche le curseur après le start  
    lcd.blink(); // clignotement du curseur
  }
  if (select == START && digitalRead(bShoot)){
    unsigned int score = 0;
    while(select != QUIT){
      //debut du jeu
      if (gameCounter == 0){
        // entrer le psedo du joueur
        char name = ...;
        Player player(name, score); // on crée l'objet joueur avec comme parametre son psedo
      } 
      // jeu
      // menu pause

      if (digitalRead(bMenu)){
        pauseMenu();
        while (!(select == QUIT && digitalRead(bSoot)) || !(select == BACK && digitalRead(bSoot))){
          if (digitalRead(bUp)){
            select = QUIT; 
            lcd.setCursor(...); 
            lcd.lcdcursor(); // on affiche le curseur après le start  
            lcd.blink(); // clignotement du curseur 
          }
          else if (digitalRead(bDown)){
            select = BACK; 
            lcd.setCursor(...); 
            lcd.lcdcursor(); // on affiche le curseur après le start  
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
    while(!(select == QUIT && digitalRead(bSoot))){
      // on afficher ce qu'il y a dans la mémoire UPROM
    }
  }

 }

void menu(){
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
  lcd.print("|   Scores");
}



