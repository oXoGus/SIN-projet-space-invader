#ifndef LASER_H
#define LASER_H

#include<rgb_lcd.h>
#include"player.h"

class Laser {
  
  public : 
  
  Laser(rgb_lcd& lcdRef, Player& shipRef); // constructeur de l'objet Laser "&" indique qu'au lieu de passer une copie de l'objet on passe un réference a l'objet original

  void update();

  void reset();

  void shoot();

  void clear();

  void display();

  char y; // coordonnée en y de l'objet 

  char x; // coordonnée en x de l'objet

  char active = 0+48;

  rgb_lcd& lcd;

  Player& ship;
};

#endif