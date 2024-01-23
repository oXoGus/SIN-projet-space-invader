#ifndef ROCK_H
#define ROCK_H

#include<rgb_lcd.h>

class Rock {
  
  public : 
  
  Rock(rgb_lcd& lcdRef); // constructeur de l'objet Laser "&" indique qu'au lieu de passer une copie de l'objet on passe un réference a l'objet original

  void update();

  void clear();

  void display();


  char monRandom(unsigned char borneMin,unsigned char borneMax);

  void explode();

  char y; // coordonnée en y de l'objet 

  bool active = 0;

  char x = 15; // coordonnée en x de l'objet

  char hit = 0;

  rgb_lcd& lcd;

};

#endif