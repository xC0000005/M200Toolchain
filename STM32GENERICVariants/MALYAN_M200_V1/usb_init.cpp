#include <arduino.h>

void setupUSB() {
  pinMode(PB9, OUTPUT);
  digitalWrite(PB9,1);
  for(volatile unsigned int i=0;i<1024;i++);// Leave this high long enough for the host to notice

  digitalWrite(PB9,0);
  for(volatile unsigned int i=0;i<512;i++);// Only small delay seems to be needed, and USB pins will get configured in Serial.begin
  // and return to high so USB works.
  digitalWrite(PB9,1);
}
