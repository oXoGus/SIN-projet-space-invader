#ifndef PLAYER_H
#define PLAYER_H

#include<rgb_lcd.h>


class Player {
  public :
  Player(rgb_lcd& lcdRef); // constructeur

  void display();

  void clear();

  void down();

  void up();

  void left();
  
  void right();
 
  char y;

  char x;
  
  rgb_lcd& lcd;


};

#endif
