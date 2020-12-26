void setup() {
  Serial.begin(9600);
}

void loop() {
  int Val1 = analogRead(A0);
  int Val2 = analogRead(A1);
  Serial.println((String)Val1 + "/" + Val2);
  delay(1000);
}
