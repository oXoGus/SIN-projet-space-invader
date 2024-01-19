#include"player.h"
#include<rgb_lcd.h>

#define SHIP 1

Player::Player(rgb_lcd& lcdRef) : lcd(lcdRef){
}

void Player::display(){
  lcd.clear();
  lcd.setCursor(xShip, yShip);
  lcd.write(SHIP);
}


void Player::clear(){
  lcd.setCursor(xShip, yShip);
  lcd.print(" ");
  lcd.setCursor(xShip, yShip);
}


void Player::down(){
  if (yShip + 1 <2){
    clear();
    yShip++;
    lcd.setCursor(xShip, yShip);
    lcd.write(SHIP);
  }
}

void Player::up(){
  if (yShip - 1 >= 0){
    clear();
    yShip--;
    lcd.setCursor(xShip, yShip);
    lcd.write(SHIP);
  }
}

void Player::left(){
  if (xShip - 1 >= 0){
    clear();
    xShip--;
    lcd.setCursor(xShip, yShip);
    lcd.write(SHIP);
  }
}

void Player::right(){
  if (xShip + 1 < 16){
    clear();
    xShip++;
    lcd.setCursor(xShip, yShip);
    lcd.write(SHIP);
  }
}