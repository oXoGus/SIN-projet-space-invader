#include<rgb_lcd.h>
#include"monster.h"

#define ROCK 7

Mob::Mob(rgb_lcd& lcdRef) : lcd(lcdRef){ 
  y = monRandom(0, 1);
  display(); // on affiche le rocher 
}

char Mob::monRandom(unsigned char borneMin,unsigned char borneMax){
	randomSeed(analogRead(0)); //on initialise une nouvelle seed 
  char resultat=0; 
	resultat=random()%(borneMax-borneMin+1)+borneMin; // on calcule de nombre aléatoire 
	return resultat; // on renvoie le resultat 

void Mob::clear(){
  lcd.setCursor(x, y);
  lcd.print(" ");
  lcd.setCursor(x, y);
}

void Mob::display(){ // on affiche le laser sur le lcd
  lcd.setCursor(x, y);
  lcd.write(ROCK);
}

void Mob::update(){ // on décale le rocher 
  clear();
  x--;
  display();
}