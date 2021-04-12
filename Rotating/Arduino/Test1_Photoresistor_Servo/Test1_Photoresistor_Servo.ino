#include <Servo.h>

Servo servo;
int pos = 0;
int pos_con;
int PR1 = A0;
int PR2 = A1;
int PRval1;
int PRval2;

void setup() {
  Serial.begin(9600);
  servo.attach(3);
}

void loop() {
  PRval1 = round(analogRead(PR1)/100);
  PRval2 = round(analogRead(PR2)/100);
  Serial.print(PRval1);
  Serial.print(" ");
  Serial.print(PRval2);
  Serial.print("\n");
  if(PRval1 > PRval2) {
   pos++;
  } else if(PRval1 < PRval2) {
   pos--;
  } if(pos > 180) {
    pos = 180;
  } else if(pos < 0){
    pos = 0;
  }
  Serial.print(pos);
  Serial.print("\n");
  servo.write(pos);
  delay(20);

}
