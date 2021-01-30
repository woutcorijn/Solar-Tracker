int voltage[] = {3,5,1,6,3,2};
int position1[] = {0,20,30,45,80,270};
int position2[] = {40,35,60,45,200,240};

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 6; i++) {
  Serial.println((String)voltage[i] + "/" + position1[i] + "/" + position2[i] + "/");
  delay(1000);
   }
}
