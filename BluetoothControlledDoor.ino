/*	Bluetooth Controller Bluetooth Door Opener 
]											
// Constants
const int lock = 8;		// Electric door opener ground throug an NPN 2222 transistor - Base pin at pin 8 of Arduino uno
const int buzzer = A5;	// Buzzer at A05 arduino pin

// Variables
int data; 				// Vasriable to store incoming byte from serial port

void setup(){
	Serial.begin(9600);
	pinMode(lock, OUTPUT);
}

void loop(){
	// Read incoming byte only if the serial port is available 
	if (Serial.available()>0){
		data = Serial.read();
	}
	// If incoming data is equal with W open the lock for 5 seconds.
	if (data == 'W'){ 	  			// 'W' is the letter that we sending from bluetooth application by pressing the unlock button 
		tone(buzzer,300); 			// Play a tone
		digitalWrite(lock, HIGH); 	// Unlock the door
		delay(3000); 				// for 3 seconds
	}
	else{
		noTone(buzzer);
		digitalWrite(lock,LOW);
	}
	
	data=0;						// 
}
https://www.instructables.com/Arduino-Bluetooth-Controlled-Electric-Door-Opener/
