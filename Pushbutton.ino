int buttonstate ,count=1;
int ledPin=13;
int buttonpinb=2;
void setup() {
   pinMode(Ledpin,OUTPUT);
   pinMode(buttonpin,INPUT);
}

void loop() {
  buttonstate = digitalRead(buttonpin);
  if(value == HIGH)
  {
    digitalWrite(ledpin,HIGH);
    delay(1000);
    Serial.print("Count = ");
    Serial.print(count++);
  }
  else
  digitalWrite(ledpin,LOW);
  
}

