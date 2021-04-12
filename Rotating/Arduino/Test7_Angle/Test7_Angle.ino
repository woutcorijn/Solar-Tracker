int input = 0;

void setup() {
Serial.begin(9600);
}

void loop() {
if (Serial.available() > 0) {
  input = Serial.readString().toInt();
  Serial.println(Angle(input));  
}
delay(50);
}

float Angle(float degree) {
  return (degree/270)*180;
}
