#include"player.h"
#include<rgb_lcd.h>

#define SHIP 1

Player::Player(rgb_lcd& lcdRef) : lcd(lcdRef){
}

void Player::display(){
  lcd.clear();
  lcd.setCursor(x, y);
  lcd.write(SHIP);
}


void Player::clear(){
  lcd.setCursor(x, y);
  lcd.print(" ");
  lcd.setCursor(x, y);
}


void Player::down(){
  if (y + 1 <2){
    clear();
    y++;
    lcd.setCursor(x, y);
    lcd.write(SHIP);
  }
}

void Player::up(){
  if (y - 1 >= 0){
    clear();
    y--;
    lcd.setCursor(x, y);
    lcd.write(SHIP);
  }
}

void Player::left(){
  if (x - 1 >= 0){
    clear();
    x--;
    lcd.setCursor(x, y);
    lcd.write(SHIP);
  }
}

void Player::right(){
  if (x + 1 < 16){
    clear();
    x++;
    lcd.setCursor(x, y);
    lcd.write(SHIP);
  }
}