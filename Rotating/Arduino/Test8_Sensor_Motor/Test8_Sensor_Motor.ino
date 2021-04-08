#include <Servo.h>

Servo servoAngle;
Servo servoRotate;
int positionAngle = 50;
int positionRotate = 0;
float BO;
float LR;
float VoltageReadValue;

void setup() {
  Serial.begin(9600);
  servoAngle.attach(5);
  servoRotate.attach(6);
}

void loop() {
  VoltageReadValue = analogRead(A2);
  BO = analogRead(A1);
  LR = analogRead(A0);

while(BO > 517 || BO < 506 || LR > 517 || LR < 506) {
  VoltageReadValue = analogRead(A2);
  BO = analogRead(A1);
  LR = analogRead(A0);

    if(BO > 517) {
  positionAngle -= 1;
  } else if(BO < 506) {
   positionAngle += 1;
  }

    if(LR > 517) {
  positionRotate -= 1;
  } else if(LR < 506) {
   positionRotate += 1;
  }

  positionAngle = constrain(positionAngle, 50,130);
  positionRotate = constrain(positionRotate, 0,180);

    if ( positionAngle == 50 || positionAngle == 130) {
    BO = 512;
  }

  servoAngle.write(positionAngle);

  servoRotate.write(positionRotate);
  Serial.println((String)Voltage(VoltageReadValue) + "/" + Angle(positionRotate) + "/" + Angle(positionAngle) + "/" + LR + "/" + BO);
  delay(500);
}
delay(5 * 60000);
}

float Angle(float degree) {
  return (degree/180)*270;
}

float Voltage(float Voltage) {
  return (VoltageReadValue/1023)*15;
}
