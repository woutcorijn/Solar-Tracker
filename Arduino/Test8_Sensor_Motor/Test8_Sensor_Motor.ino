#include <Servo.h>

Servo servoAngle;
Servo servoRotate;
int positionAngle = 67.5;
int positionRotate = 0;
float BO;
float LR;

void setup() {
  Serial.begin(9600);
  servoAngle.attach(5);
  servoRotate.attach(6);
}

void loop() {
  BO = analogRead(A1);
  LR = analogRead(A0);
    
while(BO > 517 || BO < 506 || LR > 517 || LR < 506) {
  BO = analogRead(A1);
  LR = analogRead(A0);

  //Serial.println("Boven-Onder: " + String(BO));
  //Serial.println("Links-Rechts: " + String(LR));

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
  //Serial.println("Hoek: " + String(positionAngle));
  
  servoRotate.write(positionRotate);
  //Serial.println("Rotatie: " + String(positionRotate));
  Serial.println((String)"5.00" + "/" + Angle(positionRotate) + "/" + Angle(positionAngle));
  delay(500);
}
//Serial.println("Break");
delay(60000);
}

float Angle(float degree) {
  return (degree/180)*270;
}
