#include <Servo.h>

Servo servo;
int PR1;
int Pos = 90;

void setup() {
  Serial.begin(9600);
  servo.attach(3);
}

void loop() {
  PR1 = analogRead(A0);
  if(PR1 > 600) {
  Pos += 1;
  } else if(PR1 < 400) {
   Pos -= 1;
  }

Pos = constrain(Pos, 0, 180);
servo.write(Pos);
Serial.println(PR1);
Serial.println(Pos);
Serial.println("\n");
delay(50);
  
}
