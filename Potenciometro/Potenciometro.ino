int gas = 1;

void setup() {
  Serial.begin(115200);

  pinMode(gas, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int valPot = analogRead(gas);

  valPot = map(valPot, 0, 1023, 0, 99);

  //Serial.println(valPot);
  

  if(valPot < 10){Serial.print("C5600"); Serial.println(valPot);}
  if(valPot >= 10){Serial.print("C560"); Serial.println(valPot);}
  delay(50);
}
