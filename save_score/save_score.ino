#include <EEPROM.h>

char pseudo[5][2][20] = {{{"Zeffut0", "0"},
                          {"Zeffut1", "1"},
                          {"Zeffut2", "2"},
                          {"Zeffut3", "3"},
                          {"Zeffut4", "4"}}}

void setup() {
  Serial.begin(9600);
  for(char i=0; i<5; i++){
    for(char j=0; i<2; j++){
      for(char k=0; k<1; k++){
        EEPROM.write[i][j][k]
      }}}
    }
  }

void loop() {
  Serial.print();
}
