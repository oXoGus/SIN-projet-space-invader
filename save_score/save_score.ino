#include <EEPROM.h>

char pseudo[5][2] = {{'Test0', '00000'},
                     {'Test1', '00001'},
                     {'Test2', '00002'},
                     {'Test3', '00003'},
                     {'Test4', '00004'}};

void setup() {
  Serial.begin(115200);
  for(char i=0; i<5; i++){
    for(char j=0; i<2; j++){
      //char valeur[5]={pseudo[i][j][0],pseudo[i][j][1],pseudo[i][j][2],pseudo[i][j][3],pseudo[i][j][4]};
      Serial.println(pseudo[i][j]);
      delay(1000);
      //for (char k=0;k<5;k++){
      //  EEPROM.write((i+j)*5,valeur[k]);
      //}
    }
  } 
}

void loop() {
}
