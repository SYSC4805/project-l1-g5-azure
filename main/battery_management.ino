//Arkash sundralingam 101115738
#include "battery.h"
char state;
int x;
void loop() { 
x=battery();
 battery_mangement(x);
 }

void battery_mangement(){
state='z';
if (x>=60){
state='H';
//keep all on
}else if((x>=20)&&(x<=60)){
pinmode(pin(),low);
pinmode(pin(),low);
state='S'
//Line + small block are on
}else{
pinmode(pin(),low);
pinmode(pin(),low);
//Line sensor is only on
state='L';
}
}
