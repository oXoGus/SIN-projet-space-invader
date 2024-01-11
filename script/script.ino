#include <rgb_lcd.h>
#include "player.h"
#define bUp 5
#define bDown 6
#define bRight 3
#define bLeft 4
#define bShoot 2
#define bMenu 8
#define START 16
#define SCORE 2 
#define QUIT 3
#define BACK 4
#define OK 55
#define UPPER 1
#define LOWER 2
#define PAGEONE 3
#define PAGETWO 4




int n = 0;
unsigned char select = START;
unsigned char gameCounter = 0;

rgb_lcd lcd;

char alphabetPage = PAGEONE;
char row = 1;
char col = 0;
char typePosition = 0;
char Case = LOWER;

char lineTwoLowerPageOne[] = {'^', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', '\0'};
char lineOne[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'K', '\0'};
char lineTwoUpperPageOne[] = {'^', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', '\0'};
char lineTwoUpperPageTwo[] = {'^', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
char lineTwoLowerPageTwo[] = {'^', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};

char pseudo[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'} ;


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

  Serial.begin(115200);
  // setup des boutons 
  pinMode(bUp, INPUT);
  pinMode(bDown, INPUT);
  pinMode(bLeft, INPUT);
  pinMode(bRight, INPUT);
  pinMode(bShoot, INPUT);
  pinMode(bMenu, INPUT);
}

void loop(){
  startMenu(select);
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

void startMenu(unsigned char select){
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

char menu(){
  while (select != QUIT || select != BACK){

  }

}

char lcdEnterName(){
  lcd.setCursor(0, 0); // curseur a 0, 0
  lcd.print(lineOne);
  lcd.setCursor(0, 1);
  lcd.print(lineTwoLowerPageOne);
  lcd.write(0b01111111); // ecrit <-
  lcd.write(0b00111110); // ecrit >
  lcd.setCursor(col, row);
  lcd.blink();
  delay(1000);
  while (select != OK || select != QUIT){
    
    
    

    /*
    systeme de déplacement du curseur 
    */
  
    if (digitalRead(bRight)){
      antiRebond(bRight);
      if (col+1 < 16){ // tant que l'on sort pas du lcd
        col++;
        char dizaine = char(col/10+48);
        char unite = char(col%10+48);
        Serial.print(dizaine);
        Serial.println(unite);
        lcd.setCursor(col, row);
      }
      else{
        col = 0;
        char dizaine = char(col/10+48);
        char unite = char(col%10+48);
        Serial.print(dizaine);
        Serial.println(unite);
        lcd.setCursor(col, row);
      }
    }
    else if (digitalRead(bLeft)){
      antiRebond(bLeft);
      if (col-1 >= 0){ // tant que l'on sort pas du lcd
        col--;
        char dizaine = char(col/10+48);
        char unite = char(col%10+48);
        Serial.print(dizaine);
        Serial.println(unite);
        lcd.setCursor(col, row);
      }
      else{
        col = 15;
        char dizaine = char(col/10+48);
        char unite = char(col%10+48);
        Serial.print(dizaine);
        Serial.println(unite);
        lcd.setCursor(col, row);
      }
    }
    else if (digitalRead(bUp)){
      antiRebond(bUp);
      if (row - 1  >= 0 ){
        row--;
        char dizaine = char(row/10+48);
        char unite = char(row%10+48);
        Serial.print(dizaine);
        Serial.println(unite);
        lcd.setCursor(col, row);
      }
    }
    else if (digitalRead(bDown)){
      antiRebond(bDown);
      if (row + 1 < 2 ){
        row++;
        char dizaine = char(row/10+48);
        char unite = char(row%10+48);
        Serial.print(dizaine);
        Serial.println(unite);
        lcd.setCursor(col, row);
      }
    }
    else if (digitalRead(bMenu)){

    }
    /*
    systeme d'action sur le clavier 
    */
    else if (digitalRead(bShoot)){
      antiRebond(bShoot);
      actions();
      lcd.setCursor(col, row);
    }

  }
}

char setCase(){
  
  lcd.setCursor(0, 1);
  /*
  systeme de flag avec Case et alphabetPage
  */
  if (Case == UPPER && alphabetPage == PAGEONE){ // si 
    Serial.println("upper && pageOne");
    lcd.print(lineTwoLowerPageOne);
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111110); // ecrit >
    Case = LOWER;
    Serial.println("LOWER");
  }
  else if (Case == LOWER && alphabetPage == PAGEONE){
    Serial.println("lower && pageOne");
    lcd.print(lineTwoUpperPageOne);
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111110); // ecrit >
    Case = UPPER;
    Serial.println("UPPER");
  }
  else if (Case == UPPER && alphabetPage == PAGETWO){
    Serial.println("upper pageTwo");
    lcd.print(lineTwoLowerPageTwo);  
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111100); // ecrit <
    Case = LOWER;
    Serial.println("LOWER");
  }
  else if (Case == LOWER && alphabetPage == PAGETWO){
    Serial.println("upper && pageTwo");
    lcd.print(lineTwoUpperPageTwo);
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111100); // ecrit <
    Case = UPPER;
    Serial.println("UPPER");
  }
}

char setPage(){
  lcd.setCursor(0, 1);
  /*
  systeme de flag avec Case et alphabetPage
  */
  if (Case == UPPER && alphabetPage == PAGEONE){ // si 
    lcd.print(lineTwoUpperPageTwo);
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111110); // ecrit >
    alphabetPage = PAGETWO;
  }
  else if (Case == LOWER && alphabetPage == PAGEONE){
    lcd.print(lineTwoLowerPageTwo);
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111110); // ecrit >
    alphabetPage = PAGETWO;
  }
  else if (Case == UPPER && alphabetPage == PAGETWO){
    lcd.print(lineTwoUpperPageOne);
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111100); // ecrit <
    alphabetPage = PAGEONE;
  }
  else if (Case == LOWER && alphabetPage == PAGETWO){
    lcd.print(lineTwoLowerPageOne);
    lcd.write(0b01111111); // ecrit <-
    lcd.write(0b00111100); // ecrit <
    alphabetPage = PAGEONE;
  }
}
// utiliser les variable globales
char actions(){
  if (col == 0 && row == 1){ // position du "^" sur le lcd
    setCase();
  }
  else if (col == 15 && row == 1){ //  position du ">" sur le lcd
    setPage();
  }
  else if (row == 1 && col > 0 && col < 14 && Case == LOWER && alphabetPage == PAGEONE && typePosition < 14){ // si le joueur tape sur une des lettre en minuscule de la première page 
    lineOne[typePosition] = lineTwoLowerPageOne[col]; // on met la lettre qu'a choisit le joueur dans le tableau char de la ligne 1 a la bonne position
    lcd.setCursor(0, 0);
    lcd.print(lineOne); 
    pseudo[typePosition] = lineTwoLowerPageOne[col];
    typePosition++; // on décale la position du curseur de 1 vers la droite 

  }
  else if (row == 1 && col > 0 && col < 14 && Case == LOWER && alphabetPage == PAGETWO && typePosition < 14){ // si le joueur tape sur une des lettre en minuscule de la première page 

    lineOne[typePosition] = lineTwoLowerPageTwo[col]; // on met la lettre qu'a choisit le joueur dans le tableau char de la ligne 1 a la bonne position
    lcd.setCursor(0, 0);
    lcd.print(lineOne); 
    pseudo[typePosition] = lineTwoLowerPageOne[col];
    typePosition++; // on décale la position du curseur de 1 vers la droite 
  }
  else if (row == 1 && col > 0 && col < 14 && Case == UPPER && alphabetPage == PAGEONE && typePosition < 14){ // si le joueur tape sur une des lettre en minuscule de la première page 
    lineOne[typePosition] = lineTwoUpperPageOne[col]; // on met la lettre qu'a choisit le joueur dans le tableau char de la ligne 1 a la bonne position
    lcd.setCursor(0, 0);
    lcd.print(lineOne); 
    pseudo[typePosition] = lineTwoLowerPageOne[col];
    typePosition++; // on décale la position du curseur de 1 vers la droite 
  }
  else if (row == 1 && col > 0 && col < 14 && Case == UPPER && alphabetPage == PAGETWO && typePosition < 14){ // si le joueur tape sur une des lettre en minuscule de la première page 
    lineOne[typePosition] = lineTwoUpperPageTwo[col]; // on met la lettre qu'a choisit le joueur dans le tableau char de la ligne 1 a la bonne position
    lcd.setCursor(0, 0);
    lcd.print(lineOne); 
    pseudo[typePosition] = lineTwoLowerPageOne[col];
    typePosition++; // on décale la position du curseur de 1 vers la droite 
  }
  else if (row == 1 && col == 14){ // la ou se trouve le symbole delet
    if(typePosition - 1 >= 0){
      typePosition--; // on recule d'une case et on la remplace avec un espace
      lineOne[typePosition] = ' ';
      lcd.setCursor(0, 0);
      lcd.print(lineOne); 
      pseudo[typePosition] = lineTwoLowerPageOne[col];
    }
  }
  else if (row == 0 && (col == 14 || col == 15)){
    select = OK;
  }
}

void antiRebond(char pin){
  delay(10);
  while (digitalRead(pin));
}


