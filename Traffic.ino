int redpin =12;
int yellowpin =11;
int greenpin =10;
void setup() {
  pinMode(redpin,OUTPUT);
  pinMode(yellowpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
}

void loop() {
digitalWrite(redpin,HIGH);
digitalWrite(yellowpin,LOW);
digitalWrite(greenpin,LOW);
delay(5000);
digitalWrite(redpin,LOW);
digitalWrite(yellowpin,HIGH);
digitalWrite(greenpin,LOW);
delay(1000);
digitalWrite(redpin,LOW);
digitalWrite(yellowpin,LOW);
digitalWrite(greenpin,HIGH);
delay(5000);
}
