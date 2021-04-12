#include <Servo.h>

float VoltageReadValue;

void setup() {
  Serial.begin(9600);
}

void loop() {
  VoltageReadValue = analogRead(A0);
  Serial.println((String)Voltage(VoltageReadValue) + "/");
  delay(500);
}

float Voltage(float Voltage) {
  return (VoltageReadValue/1023)*15;
}
