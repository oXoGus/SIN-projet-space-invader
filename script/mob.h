#ifndef MOB_H
#define MOB_H

#include<rgb_lcd.h>

class Mob : {
  
  public : 
  
  Rock(rgb_lcd& lcdRef); // constructeur de l'objet Laser "&" indique qu'au lieu de passer une copie de l'objet on passe un réference a l'objet original

  void update();

  void clear();

  void display();

  char monRandom();

  char y; // coordonnée en y de l'objet 

  char x = 15; // coordonnée en x de l'objet

  rgb_lcd& lcd;

}

#endif