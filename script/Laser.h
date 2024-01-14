#ifndef LASER_H
#define LASER_H

#include<rgb_lcd.h>

class Laser : {
  
  public : 
  
  Laser(rgb_lcd& lcdRef); // constructeur de l'objet Laser 



  char y; // coordonnée en y de l'objet 

  char x; // coordonnée en x de l'objet


}

#endif