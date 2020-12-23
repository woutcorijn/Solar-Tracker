void setup() {
  Serial.begin(9600);
}

void loop() {
  int Val1 = analogRead(A0);
  Serial.println((String)Val1 + "V");
  delay(1000);
}
