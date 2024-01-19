#include"Laser.h"
#include<rgb_lcd.h>
#include"player.h"


Laser::Laser(rgb_lcd& lcdRef, Player& shipRef): lcd(lcdRef), ship(shipRef){

}

void Laser::shoot(){
  xLaser = ship.xShip + 1; // on initialise la position initial du laser a droite du vaisseau 
  yLaser = ship.yShip;
  display(); // on affiche le laser sur le lcd
}

void Laser::clear(){
  lcd.setCursor(xLaser, yLaser);
  lcd.print(" ");
}

void Laser::display(){ // on affiche le laser sur le lcd
  lcd.setCursor(xLaser, yLaser);
  lcd.print("-");
}

void Laser::reset(){
  active = 0;
  
}

void Laser::update(){
  clear();
  if (xLaser + 1 < 16){
    xLaser++;
    display();
  }
  else{
    reset();
    xLaser = ship.xShip+1;
    yLaser = ship.yShip;
  }
}