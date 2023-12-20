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
#define UPPER 1
#define LOWER 0
#define PAGEONE 0
#define PAGETWO 1




int n = 0;
unsigned char select = START;
unsigned char gameCounter = 0;

rgb_lcd lcd;

String lcdEnterNameLineZero[] = {
  "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "_", "OK", 
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
          }
          else if (digitalRead(bDown)){
            select = BACK; 
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
  char alphabetPage = 0;
  char row = 1;
  char col = 0;
  char typePosition = 0;
  char Case = LOWER;
  char psedo[14];
  String lineOne[] = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "O", "K"};
  String lineTwo[] = {"^", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m"};
  lcd.setCursor(0, 0); // curseur a 0, 0
  for (char i = 0; i < 16; i++){
    lcd.print(lineOne[i]);
  }
  lcd.setCursor(0, 1);
  for (char i = 0; i < 14; i++){
    lcd.print(lineTwo[i]);
  }
  lcd.write(0b01111111); // ecrit <-
  lcd.write(0b00111110); // ecrit >
  lcd.setCursor(col, row);
  lcd.blink();
  while (select != OK || select != QUIT){
    /*
    systeme de déplacement du curseur 
    */
    if (digitalRead(bRight)){
      if (col+1 < 16){ // tant que l'on sort pas du lcd
        col++;
        lcd.setCursor(col, row);
      }
    }
    if (digitalRead(bLeft)){
      if (col-1 >= 0){ // tant que l'on sort pas du lcd
        col--;
        lcd.setCursor(col, row);
      }
    }
    if (digitalRead(bUp)){
      if (row - 1  >= 0 ){
        row--;
        lcd.setCursor(col, row);
      }
    }
    if (digitalRead(bDown)){
      if (row + 1 < 2 ){
        row++;
        lcd.setCursor(col, row);
      }
    }
    /*
    systeme d'action sur le clavier 
    */
    if (digitalRead(bShoot)){
      typePosition, Case, alphabetPage = actions(typePosition, col, row, Case, alphabetPage);
    }
  }
}

char setCase(char Case, char alphabetPage){
  String lineTwoUpperPageOne[] = {"^", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M"};
  String lineTwoLowerPageOne[] = {"^", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m"};
  String lineTwoUpperPageTwo[] = {"^", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
  String lineTwoLowerPageTwo[] = {"^", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
  lcd.setCursor(0, 1);
  /*
  systeme de flag avec Case et alphabetPage
  */
  if (Case == UPPER && alphabetPage == PAGEONE){ // si 
    for (char i = 0; i < 14; i++){
      lcd.print(lineTwoUpperPageOne[i]);
    }
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111110); // ecrit >
    Case = LOWER;
    return Case;
  }
  else if (Case == LOWER && alphabetPage == PAGEONE){
    for (char i = 0; i < 14; i++){
      lcd.print(lineTwoLowerPageOne[i]);
    }
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111110); // ecrit >
    Case = UPPER;
    return Case;
  }
  else if (Case == UPPER && alphabetPage == PAGETWO){
    for (char i = 0; i < 14; i++){
      lcd.print(lineTwoUpperPageTwo[i]);
    }
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111100); // ecrit <
    Case = LOWER;
    return Case;
  }
  else if (Case == LOWER && alphabetPage == PAGETWO){
    for (char i = 0; i < 14; i++){
      lcd.print(lineTwoLowerPageTwo[i]);
    }
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111100); // ecrit <
    Case = UPPER;
    return Case;
  }
}

char setPage(char Case, char alphabetPage){
  String lineTwoUpperPageOne[] = {"^", "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M"};
  String lineTwoLowerPageOne[] = {"^", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m"};
  String lineTwoUpperPageTwo[] = {"^", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
  String lineTwoLowerPageTwo[] = {"^", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
  lcd.setCursor(0, 1);
  /*
  systeme de flag avec Case et alphabetPage
  */
  if (Case == UPPER && alphabetPage == PAGEONE){ // si 
    for (char i = 0; i < 14; i++){
      lcd.print(lineTwoUpperPageOne[i]);
    }
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111110); // ecrit >
    alphabetPage = PAGETWO;
    return alphabetPage;
  }
  else if (Case == LOWER && alphabetPage == PAGEONE){
    for (char i = 0; i < 14; i++){
      lcd.print(lineTwoLowerPageOne[i]);
    }
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111110); // ecrit >
    alphabetPage = PAGETWO;
    return alphabetPage;
  }
  else if (Case == UPPER && alphabetPage == PAGETWO){
    for (char i = 0; i < 14; i++){
      lcd.print(lineTwoUpperPageTwo[i]);
    }
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111100); // ecrit <
    alphabetPage = PAGEONE;
    return alphabetPage;
  }
  else if (Case == LOWER && alphabetPage == PAGETWO){
    for (char i = 0; i < 14; i++){
      lcd.print(lineTwoLowerPageTwo[i]);
    }
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111100); // ecrit <
    alphabetPage = PAGEONE;
    return alphabetPage;
  }
}

char actions(char typePosition, char col, char row, char Case, char alphabetPage){
  if (col == 0 && row == 1){
    Case = setCase(Case, alphabetPage);
    return typePosition, Case, alphabetPage;
  }
  else if (col == 15 && row == 1){
    alphabetPage = setPage(Case, alphabetPage);
    Serial.println(alphabetPage);
    return typePosition, Case, alphabetPage;
  }

}




