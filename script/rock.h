#ifndef ROCK_H
#define ROCK_H

#include<rgb_lcd.h>

class Laser : {
  
  public : 
  
  Laser(rgb_lcd& lcdRef); // constructeur de l'objet Laser "&" indique qu'au lieu de passer une copie de l'objet on passe un réference a l'objet original

  void update();

  char y; // coordonnée en y de l'objet 

  char x; // coordonnée en x de l'objet

  char hit = 0;

  rgb_lcd& lcd;

}

#endif