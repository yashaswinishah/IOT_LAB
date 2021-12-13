int sensorValue;
int outputValue;
void setup() {
  Serial.begin(9600);
}

void loop() {
 
  sensorValue=analogRead(A0);
  outputValue=map(sensorValue,0,1023,0,255);
  analogWrite(9,outputValue);
  Serial.print("Sensor Value = ");
  Serial.println(sensorValue);
  Serial.print("Output Value = ");
  Serial.println(outputValue);
  delay(2000);
}
