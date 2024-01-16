#include"Laser.h"
#include<rgb_lcd.h>
#include"player.h"


Laser::Laser(rgb_lcd& lcdRef, player& shipRef): lcd(lcdRef), ship(shipRef){
  if (ship.x + 1 < 16){
    x = ship.x + 1; // on initialise la position initial du laser a droite du vaisseau 
    display(); // on affiche le laser sur le lcd
  }
}

void Laser::clear(){
  lcd.setCursor(x, y);
  lcd.print(" ");
  lcd.setCursor(x, y);
}

void Laser::display(){ // on affiche le laser sur le lcd
  lcd.setCursor(x, y);
  lcd.print("-");
}

void Laser::update(){
  clear();
  x++;
  display();
}