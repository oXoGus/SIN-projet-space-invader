#include<rgb_lcd.h>
#include"rock.h"

#define ROCK 7

Rock::Rock(rgb_lcd& lcdRef) : lcd(lcdRef){
  y = monRandom(0, 1);
  display();
}

char monRandom(unsigned char borneMin,unsigned char borneMax){
	randomSeed(analogRead(0)); //on initialise une nouvelle seed 
  char resultat=0; 
	resultat=random()%(borneMax-borneMin+1)+borneMin; // on calcule de nombre aléatoire 
	return resultat; // on renvoie le resultat 

void Rock::clear(){
  lcd.setCursor(x, y);
  lcd.print(" ");
  lcd.setCursor(x, y);
}

void Rock::display(){ // on affiche le laser sur le lcd
  lcd.setCursor(x, y);
  lcd.write(ROCK);
}

void Rock::update(){
  clear();
  x--;
  display();
}