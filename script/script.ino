#include <rgb_lcd.h>
#include "player.h"
#include "Laser.h"
#include "rock.h"
#include "mob.h"
//#include <U8g2lib.h>
#include <Wire.h>
#define bUp 5
#define bDown 6
#define bRight 3
#define bLeft 4
#define bShoot 2
#define bMenu 8
#define START 16
#define SCORE 2 
#define QUIT 66
#define BACK 4
#define OK 55
#define UPPER 1
#define LOWER 2
#define PAGEONE 3
#define PAGETWO 4
#define DEFAULT 100
#define SHIP 1

String LaserCount[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"};

//U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);

int counter = 0;

#define IMAGE_WIDTH 128
#define IMAGE_HEIGHT 32

unsigned int score = 0;
int n = 0;
unsigned char gameCounter = 0;
char lcdEnterNameSelect;
char menuSelect;
char select;
char startMenuSelect;
char laserCount = 0;
char laserAvailable = 0;


rgb_lcd lcd;
Player ship(lcd);
Laser laser1(lcd, ship);
Laser laser2(lcd, ship);
Laser laser3(lcd, ship);
Laser laser4(lcd, ship);
Laser laser5(lcd, ship);
Laser laser6(lcd, ship);
Laser laser7(lcd, ship);
Laser laser8(lcd, ship);
Laser laser9(lcd, ship);
Laser laser10(lcd, ship);
Laser laser11(lcd, ship);
Laser laser12(lcd, ship);
Laser laser13(lcd, ship);
Laser laser14(lcd, ship);
Laser laser15(lcd, ship);
Laser laser16(lcd, ship);
Laser laser17(lcd, ship);


char alphabetPage = PAGEONE;
char y = 1;
char x = 0;
char typePosition = 0;
char Case = LOWER;

char lineTwoLowerPageOne[] = {'^', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', '\0'};

char lineTwoUpperPageOne[] = {'^', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', '\0'};
char lineTwoUpperPageTwo[] = {'^', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
char lineTwoLowerPageTwo[] = {'^', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};

char lineOne[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'K', '\0'};
char lineOneInit[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'O', 'K', '\0'};


char pseudo[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'} ;


byte Ship[8] = {0b00001110,
                 	0b00010101,
                  0b00000100,
     		          0b00001110,
         		      0b00001110,
         		      0b00000100,
         		      0b00010101,
         		      0b00001110};

byte mob1[8] = {0b00011100,
                0b00001110,
                0b00011011,
     		        0b00001110,
         		    0b00001110,
         		    0b00011011,
         		    0b00001110,
         		    0b00011100};

byte rock[8] = {0b00000000,
                0b00000000,
     		        0b00001110,
         		    0b00011111,
         		    0b00011111,
         		    0b00000110,
         		    0b00000000,
                0b00000000};

byte explode[8] = {0b00000000,
                   0b00000000,
                   0b00000100,
     		           0b00001010,
         		       0b00001010,
         		       0b00000100,
         		       0b00000000,
         		       0b00000000};

byte explode2[8] = {0b00000000,
                    0b00001010,
                    0b00010001,
     		            0b00000000,
         		        0b00000000,
         		        0b00010001,
         		        0b00001010,
         		        0b00000000};

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
  //setup de l'écran oled
  //u8g2.begin();
  
  // setup du lcd 
  lcd.begin(16, 2);
  lcd.setRGB(255, 255, 255);
  lcd.createChar(SHIP, Ship);
  lcd.createChar(2, explode);
  lcd.createChar(3, explode2);
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
  startMenuSelect = START;
}

void loop(){
  startMenu(startMenuSelect);
  if (digitalRead(bUp)){
    startMenuSelect = START; 
  }
  else if (digitalRead(bDown)){
    startMenuSelect = SCORE;
  }
  if (startMenuSelect == START && digitalRead(bShoot) && antiRebond(bShoot)){
    
    lcd.clear();
    //if (gameCounter == 0){
        // entrer le psedo du joueur
    //   lcdEnterName();
    //  } 
    lcd.clear();
    Serial.println(select);
    ship.display();
    Serial.println("DONE");
    while(select != QUIT){
      //debut du jeu
      if (digitalRead(bUp)){
        antiRebond(bUp);
        ship.up();
      }
      else if (digitalRead(bDown)){
        antiRebond(bDown);
        ship.down();
      }
      else if (digitalRead(bLeft)){
        antiRebond(bLeft);
        ship.left();
      }
      else if (digitalRead(bRight)){
        antiRebond(bRight);
        ship.right();
      }
      else if (digitalRead(bShoot)){
        isLaserActive().shoot();
      }
      

      //displayScore(score);
      laserUpdate();
      delay(150);


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
    }
  }
      

      
      // jeu
      // menu pause

      

      // retour du jeu

      // a la mort du joueur 
      // sauvegarde en mémoir UPROM
}
  

void startMenu(unsigned char startMenuSelect){
  if (startMenuSelect == SCORE){
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
  menuSelect = BACK;
  lcd.clear();
  while (1){
    if (digitalRead(bRight)){
      menuSelect = QUIT;
    }
    else if (digitalRead(bLeft)){
      menuSelect = BACK;
    }
    else if (digitalRead(bShoot) && menuSelect == QUIT && antiRebond(bShoot)){
      lcdEnterNameSelect = QUIT;
      select = QUIT;
      return;
    }
    else if (digitalRead(bShoot) && menuSelect == BACK){
      lcd.setCursor(0, 0); // curseur a 0, 0
      lcd.print(lineOne);
      lcd.setCursor(0, 1);
      lcd.print(lineTwoLowerPageOne);
      lcd.write(0b01111111); // ecrit <-
      lcd.write(0b00111110); // ecrit >
      lcd.setCursor(x, y);
      lcd.blink();
      antiRebond(bShoot);
      return;
    }
    if (menuSelect == BACK){
      lcd.setCursor(5, 0);
      lcd.print("menu");
      lcd.setCursor(1, 1);
      lcd.write(0b11110011);
      lcd.print("BACK");
      lcd.setCursor(8, 1);
      lcd.print(" QUIT");
    }
    else {
      lcd.setCursor(5, 0);
      lcd.print("menu");
      lcd.setCursor(1, 1);
      lcd.print(" BACK");
      lcd.setCursor(8, 1);
      lcd.write(0b11110011);
      lcd.print("QUIT");
    }
      
    
    
  }
  
}

char lcdEnterName(){
  lcdEnterNameSelect = DEFAULT;
  Case = LOWER;
  alphabetPage = PAGEONE;
  lcd.setCursor(0, 0); // curseur a 0, 0
  lcd.print(lineOne);
  lcd.setCursor(0, 1);
  lcd.print(lineTwoLowerPageOne);
  lcd.write(0b01111111); // ecrit <-
  lcd.write(0b00111110); // ecrit >
  lcd.setCursor(x, y);
  lcd.blink();
  delay(1000);
  while ((lcdEnterNameSelect != OK || lcdEnterNameSelect == QUIT) && (lcdEnterNameSelect == OK || lcdEnterNameSelect != QUIT)){
    //Serial.println(lcdEnterNameSelect+111);

    /*
    systeme de déplacement du curseur 
    */
  
    if (digitalRead(bRight)){
      antiRebond(bRight);
      if (x+1 < 16){ // tant que l'on sort pas du lcd
        x++;
        char dizaine = char(x/10+48);
        char unite = char(x%10+48);
        Serial.print(dizaine);
        Serial.println(unite);
        lcd.setCursor(x, y);
      }
      else{
        x = 0;
        char dizaine = char(x/10+48);
        char unite = char(x%10+48);
        Serial.print(dizaine);
        Serial.println(unite);
        lcd.setCursor(x, y);
      }
    }
    else if (digitalRead(bLeft)){
      antiRebond(bLeft);
      if (x-1 >= 0){ // tant que l'on sort pas du lcd
        x--;
        char dizaine = char(x/10+48);
        char unite = char(x%10+48);
        Serial.print(dizaine);
        Serial.println(unite);
        lcd.setCursor(x, y);
      }
      else{
        x = 15;
        char dizaine = char(x/10+48);
        char unite = char(x%10+48);
        Serial.print(dizaine);
        Serial.println(unite);
        lcd.setCursor(x, y);
      }
    }
    else if (digitalRead(bUp)){
      antiRebond(bUp);
      if (y - 1  >= 0 ){
        y--;
        char dizaine = char(y/10+48);
        char unite = char(y%10+48);
        Serial.print(dizaine);
        Serial.println(unite);
        lcd.setCursor(x, y);
      }
    }
    else if (digitalRead(bDown)){
      antiRebond(bDown);
      if (y + 1 < 2 ){
        y++;
        char dizaine = char(y/10+48);
        char unite = char(y%10+48);
        Serial.print(dizaine);
        Serial.println(unite);
        lcd.setCursor(x, y);
      }
    }
    else if (digitalRead(bMenu)){
      
      menu();
    }
    /*
    systeme d'action sur le clavier 
    */
    else if (digitalRead(bShoot)){
      antiRebond(bShoot);
      actions();
      lcd.setCursor(x, y);
    }

  }
  lcd.clear();

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
  if (x == 0 && y == 1){ // position du "^" sur le lcd
    setCase();
  }
  else if (x == 15 && y == 1){ //  position du ">" sur le lcd
    setPage();
  }
  else if (y == 1 && x > 0 && x < 14 && Case == LOWER && alphabetPage == PAGEONE && typePosition < 14){ // si le joueur tape sur une des lettre en minuscule de la première page 
    lineOne[typePosition] = lineTwoLowerPageOne[x]; // on met la lettre qu'a choisit le joueur dans le tableau char de la ligne 1 a la bonne position
    lcd.setCursor(0, 0);
    lcd.print(lineOne); 
    pseudo[typePosition] = lineTwoLowerPageOne[x];
    typePosition++; // on décale la position du curseur de 1 vers la droite 

  }
  else if (y == 1 && x > 0 && x < 14 && Case == LOWER && alphabetPage == PAGETWO && typePosition < 14){ // si le joueur tape sur une des lettre en minuscule de la première page 

    lineOne[typePosition] = lineTwoLowerPageTwo[x]; // on met la lettre qu'a choisit le joueur dans le tableau char de la ligne 1 a la bonne position
    lcd.setCursor(0, 0);
    lcd.print(lineOne); 
    pseudo[typePosition] = lineTwoLowerPageOne[x];
    typePosition++; // on décale la position du curseur de 1 vers la droite 
  }
  else if (y == 1 && x > 0 && x < 14 && Case == UPPER && alphabetPage == PAGEONE && typePosition < 14){ // si le joueur tape sur une des lettre en minuscule de la première page 
    lineOne[typePosition] = lineTwoUpperPageOne[x]; // on met la lettre qu'a choisit le joueur dans le tableau char de la ligne 1 a la bonne position
    lcd.setCursor(0, 0);
    lcd.print(lineOne); 
    pseudo[typePosition] = lineTwoLowerPageOne[x];
    typePosition++; // on décale la position du curseur de 1 vers la droite 
  }
  else if (y == 1 && x > 0 && x < 14 && Case == UPPER && alphabetPage == PAGETWO && typePosition < 14){ // si le joueur tape sur une des lettre en minuscule de la première page 
    lineOne[typePosition] = lineTwoUpperPageTwo[x]; // on met la lettre qu'a choisit le joueur dans le tableau char de la ligne 1 a la bonne position
    lcd.setCursor(0, 0);
    lcd.print(lineOne); 
    pseudo[typePosition] = lineTwoLowerPageOne[x];
    typePosition++; // on décale la position du curseur de 1 vers la droite 
  }
  else if (y == 1 && x == 14){ // la ou se trouve le symbole delet
    if(typePosition - 1 >= 0){
      typePosition--; // on recule d'une case et on la remplace avec un espace
      lineOne[typePosition] = ' ';
      lcd.setCursor(0, 0);
      lcd.print(lineOne); 
      pseudo[typePosition] = lineTwoLowerPageOne[x];
    }
  }
  else if (y == 0 && (x == 14 || x == 15)){
    if (strcmp(lineOne, lineOneInit) == 0){ // la fonction strcmp retourne 0 si les tableau ont les meme caractère 
      Serial.println("pas de pseudo");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ecrivez votre");
      lcd.setCursor(0, 1);
      lcd.print("pseudo");
      delay(3000);
      lcd.clear();
      lcd.setCursor(0, 0); // curseur a 0, 0
      lcd.print(lineOne);
      lcd.setCursor(0, 1);
      lcd.print(lineTwoLowerPageOne);
      lcd.write(0b01111111); // ecrit <-
      lcd.write(0b00111110); // ecrit >
      lcd.setCursor(x, y);
      lcd.blink();
    }
    else{
      Serial.println("pseudo");
      lcdEnterNameSelect = OK;
      gameCounter = 1;
      lcd.noBlink();
    }
  }
}

bool antiRebond(char pin){
  delay(10);
  while (digitalRead(pin));
  return 1;
}

void laserUpdate(){
  //Serial.println("avant la mise a jour du laser");
  //laserDebbug();
  if (laser1.active){
    laser1.update();
  }
  if (laser2.active){
    laser2.update();
  }
  if (laser3.active){
    laser3.update();
  }
  if (laser4.active){
    laser4.update();
  }
  if (laser5.active){
    laser5.update();
  }
  if (laser6.active){
    laser6.update();
  }
  if (laser7.active){
    laser7.update();
  }
  if (laser8.active){
    laser8.update();
  }
  if (laser9.active){
    laser9.update();
  }
  if (laser10.active){
    laser10.update();
  }
  if (laser11.active){
    laser11.update();
  }
  if (laser12.active){
    laser12.update();
  }
  if (laser13.active){
    laser13.update();
  }
  if (laser14.active){
    laser14.update();
  }
  if (laser15.active){
    laser15.update();
  }
  if (laser16.active){
    laser7.update();
  }
  if (laser17.active){
    laser17.update();
  }
  //Serial.println("après la mise a jour du laser");
  //laserDebbug();
}

void laserDebbug(){
  char laser1XDizaine = char(laser1.xLaser/10+48);
  char laser1XUnite = char(laser1.xLaser%10+48);
  Serial.print("laser1.active = "); Serial.print(laser1.active); Serial.print(" | ");Serial.print("laser1.x et y = ");Serial.print(laser1XDizaine);Serial.print(laser1XUnite);Serial.print(" ");Serial.println((char)laser1.yLaser);
  Serial.print("laser2.active = "); Serial.print(laser2.active); Serial.print(" | ");Serial.print("laser2.x et y = ");Serial.print((char)laser2.xLaser);Serial.print(" ");Serial.println((char)laser2.yLaser);
  Serial.print("laser3.active = "); Serial.print(laser3.active); Serial.print(" | ");Serial.print("laser3.x et y = ");Serial.print((char)laser3.xLaser);Serial.print(" ");Serial.println((char)laser3.yLaser);
  Serial.print("laser4.active = "); Serial.print(laser4.active); Serial.print(" | ");Serial.print("laser4.x et y = ");Serial.print((char)laser4.xLaser);Serial.print(" ");Serial.println((char)laser4.yLaser);
}

Laser isLaserActive(){
  //Serial.println("avant l'activation du laser");
  //laserDebbug();
  if (laser1.active == 0){
    laser1.active = 1;
    laser1.xLaser = ship.xShip + 1;
    laser1.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser1;
  }
  else if (laser2.active == 0){
    laser2.active = 1;
    laser2.xLaser = ship.xShip + 1;
    laser2.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser2;
  }
  else if (laser3.active == 0){
    laser3.active = 1;
    laser3.xLaser = ship.xShip + 1;
    laser3.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser3;
  }
  else if (laser4.active == 0){
    laser4.active = 1;
    laser4.xLaser = ship.xShip + 1;
    laser4.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser4;
  }
  else if (laser5.active == 0){
    laser5.active = 1;
    laser5.xLaser = ship.xShip + 1;
    laser5.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser5;
  }
  else if (laser6.active == 0){
    laser6.active = 1;
    laser6.xLaser = ship.xShip + 1;
    laser6.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser6;
  }
  else if (laser7.active == 0){
    laser7.active = 1;
    laser7.xLaser = ship.xShip + 1;
    laser7.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser7;
  }
  else if (laser8.active == 0){
    laser8.active = 1;
    laser8.xLaser = ship.xShip + 1;
    laser8.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser8;
  }
  else if (laser9.active == 0){
    laser9.active = 1;
    laser9.xLaser = ship.xShip + 1;
    laser9.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser9;
  }
  else if (laser10.active == 0){
    laser10.active = 1;
    laser10.xLaser = ship.xShip + 1;
    laser10.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser10;
  }
  else if (laser11.active == 0){
    laser11.active = 1;
    laser11.xLaser = ship.xShip + 1;
    laser11.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser11;
  }
  else if (laser12.active == 0){
    laser12.active = 1;
    laser12.xLaser = ship.xShip + 1;
    laser12.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser12;
  }
  else if (laser13.active == 0){
    laser13.active = 1;
    laser13.xLaser = ship.xShip + 1;
    laser13.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser13;
  }
  else if (laser14.active == 0){
    laser14.active = 1;
    laser14.xLaser = ship.xShip + 1;
    laser14.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser14;
  }
  else if (laser15.active == 0){
    laser15.active = 1;
    laser15.xLaser = ship.xShip + 1;
    laser15.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser15;
  }
  else if (laser16.active == 0){
    laser16.active = 1;
    laser16.xLaser = ship.xShip + 1;
    laser16.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser16;
  }
  else if (laser17.active == 0){
    laser17.active = 1;
    laser17.xLaser = ship.xShip + 1;
    laser17.yLaser = ship.yShip;
    Serial.println("après l'activation du laser");
    laserDebbug();
    return laser17;
  }
  
}

/*
void displayScore(unsigned int score){
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    char buffer[20];
    sprintf(buffer, "Score :");
    u8g2.drawStr(0, 16, buffer);

    char buffer2[20];
    u8g2.setFont(u8g2_font_10x20_tn);
    sprintf(buffer2, "%d", score);
    u8g2.drawStr(10, 48, buffer2);

  } while (u8g2.nextPage());
}
*/
/*
void laserCollision(){
  for(char i = 0; i < 17; i++){ // on test tout les objet 
    if (lasers[i].x + 1 == rocks[i].x && lasers[i].y == rocks[i].y){ // si le laser et le rocher sont cote a cote
      rocks[i].hit++; // on incrémente le nombre de hit qu'a pris le rocher 
      if (rocks[i].hit == 3 ){ // si le rocher s'est pris 3 coup il explose
        rocks[i].explode;     
      }
      lasers[i].x = -1; // on deplace le laser en dehore du lcd pour faire grn qu'il disparait 
    }
    if (lasers[i].x + 1 == mobs[i].x && lasers[i].y == mobs[i].y){ // le laser et le monster sont cote a cote 
      mobs[i].explode;
      lasers[i].x = -1; // on deplace le laser en dehore du lcd pour faire grn qu'il disparait
    }
  }
}*/

