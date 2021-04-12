#include <Servo.h>

Servo servoAngle;
Servo servoRotate;
int positionAngle = 90;
int positionRotate = 90;
int sensorMax = 518;
int sensorMin = 505;
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

while(BO > sensorMax || BO < sensorMin || LR > sensorMax || LR < sensorMin) {
  VoltageReadValue = analogRead(A2);
  BO = analogRead(A1);
  LR = analogRead(A0);

    if(BO > sensorMax) {
  positionAngle -= 1;
  } else if(BO < sensorMin) {
   positionAngle += 1;
  }

    if(LR > sensorMax) {
  positionRotate -= 1;
  } else if(LR < sensorMin) {
   positionRotate += 1;
  }

  positionAngle = constrain(positionAngle, 60,120);
  positionRotate = constrain(positionRotate, 0,180);

    if ( positionAngle == 60 || positionAngle == 120) {
    BO = 512;
  }

  servoAngle.write(positionAngle);

  servoRotate.write(positionRotate);
  Serial.println((String)Voltage(VoltageReadValue) + "/" + Angle(positionRotate) + "/" + Angle(positionAngle) + "/" + LR + "/" + BO);
  delay(500);
}
for(int i = 0; i < 601; i++) {
  VoltageReadValue = analogRead(A2);
  Serial.println((String)Voltage(VoltageReadValue) + "/" + Angle(positionRotate) + "/" + Angle(positionAngle) + "/" + LR + "/" + BO);
  delay(500);
}
}

float Angle(float degree) {
  return (degree/180)*270;
}

float Voltage(float Voltage) {
  return (VoltageReadValue/1023)*15;
}
