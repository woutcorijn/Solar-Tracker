#include <Servo.h>

Servo servoAngle;
Servo servoRotate;

void setup() {
  Serial.begin(9600);
  servoAngle.attach(5);
  servoRotate.attach(6);
  servoAngle.write(90);
  servoRotate.write(0);
}

void loop() {

}
