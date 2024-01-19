#include"Laser.h"
#include<rgb_lcd.h>
#include"player.h"


Laser::Laser(rgb_lcd& lcdRef, Player& shipRef): lcd(lcdRef), ship(shipRef){

}

void Laser::shoot(){
  x = ship.x + 1; // on initialise la position initial du laser a droite du vaisseau 
  y = ship.y;
  display(); // on affiche le laser sur le lcd
}

void Laser::clear(){
  lcd.setCursor(x, y);
  lcd.print(" ");
}

void Laser::display(){ // on affiche le laser sur le lcd
  lcd.setCursor(x, y);
  lcd.print("-");
}

void Laser::reset(){
  active=0;
}

void Laser::update(){
  clear();
  if (x + 1 < 16){
    x++;
    display();
  }
  else{
    reset();
  }
}