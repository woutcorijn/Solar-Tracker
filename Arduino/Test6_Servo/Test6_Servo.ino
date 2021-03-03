#include <Servo.h>

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(3);
}

void loop() {
  for(int i=0; i<181; i += 5) {
  servo.write(i);
  delay(1000);
}
  for(int i=180; i>-1; i-= 5) {
  servo.write(i);
  delay(1000);
}
}
