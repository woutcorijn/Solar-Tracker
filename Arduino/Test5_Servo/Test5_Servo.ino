#include <Servo.h>

Servo servo;
float degree;
float y;

void setup() {
  Serial.begin(9600);
  servo.attach(3);
}

void loop() {
  for(int i=1; i<270; i++) {
  y = i;
  degree = (y / 270)*180;
  servo.write(degree);
  Serial.println((String) degree + " " + i);
  delay(200);
}
}
