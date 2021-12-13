int red1 = 2;                             // red LED 1    - pin 2
int yellow1 = 3;                          // yellow LED 1 - pin 3 
int green1 = 4;                           // greed LED 1  - pin 4
int red2 = 5;                             // red LED 2    - pin 5
int yellow2 = 6;                          // yellow LED 2 - pin 6
int green2 = 7;                           // green LED  2 - pin 7
unsigned long PreviousMillis = 0;         // previous millisecond
unsigned long CurrentMillis;              // current millisecond
int atraso;                               // delay
int state;                                // state for FSM
const int pingPin = 8;                    // ping 1
const int pingPin2 = 9;                   // ping 2
int cross=0;                              // presence of pedestrian 1
int cross2=0;                             // presebce of pedestrian 2
long duration, cm, cm2;                   // range calculation variables

void setup ()
{
  
  pinMode(red1, OUTPUT);                  //all LED pins are set to "output"
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);
  state=1;                                // initiate the FSM in the first state
  Serial.begin(9600);                     // initialize serial communication
}
void loop ()
{
  CurrentMillis = millis();               // updates current millisecond
  atraso=CurrentMillis-PreviousMillis;    // calculates the delay
  
  ping();                                 // runs the first ping function
  ping2();                                // runs the second ping function
  next_state_FSM();                       // runs the FSM function (next state)
  output_FSM();                           // runs the FSM function (output)

                                          //notice the loop is almost empty due to the implementation of an FSM
}
void ping(){
                                          // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
                                          // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

                                          // The same pin is used to read the signal from the PING))): a HIGH
                                          // pulse whose duration is the time (in microseconds) from the sending
                                          // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

                                          // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  if(cm<10){                              //in reallity it would be aproximatly 100cm but 10cm is more practical for testing the circuit on a small scale
    cross=1;                              //if the pedestrian is close enough the "cross" variable will change to 1
  }else{
    cross=0;                              //"cross" will be 0 when there is no presence of pedestrians
  }
}

void ping2(){
                                          // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
                                          // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin2, OUTPUT);
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2, LOW);

                                          // The same pin is used to read the signal from the PING))): a HIGH
                                          // pulse whose duration is the time (in microseconds) from the sending
                                          // of the ping to the reception of its echo off of an object.

  pinMode(pingPin2, INPUT);
  duration = pulseIn(pingPin2, HIGH);

                                          // convert the time into a distance
  cm2 = microsecondsToCentimeters(duration);

  if(cm2<10){                             //in reallity it would be aproximatly 100cm but 10cm is more practical for testing the circuit on a small scale
    cross2=1;                             //if the pedestrian is close enough the "cross2" variable will change to 1
  }else{
    cross2=0;                             //"cross2" will be 0 when there is no presence of pedestrians
  }
}

void output_FSM(){
 switch (state){
    case 1:                               //LED outputs are defined for state 1
      digitalWrite (red1,     LOW);
      digitalWrite (yellow1,  LOW);
      digitalWrite (green1,   HIGH);
      digitalWrite (red2,     HIGH);
      digitalWrite (yellow2,  LOW);
      digitalWrite (green2,   LOW);
    break;

    case 2:                               //LED outputs are defined for state 2
      digitalWrite (red1,     LOW);
      digitalWrite (yellow1,  HIGH);
      digitalWrite (green1,   LOW);
      digitalWrite (red2,     HIGH);
      digitalWrite (yellow2,  LOW);
      digitalWrite (green2,   LOW);
    break;

    case 3:                               //LED outputs are defined for state 3
      digitalWrite (red1,     HIGH);
      digitalWrite (yellow1,  LOW);
      digitalWrite (green1,   LOW);
      digitalWrite (red2,     HIGH);
      digitalWrite (yellow2,  LOW);
      digitalWrite (green2,   LOW);
    break;

    case 4:                               //LED outputs are defined for state 4
      digitalWrite (red1,     HIGH);
      digitalWrite (yellow1,  LOW);
      digitalWrite (green1,   LOW);
      digitalWrite (red2,     LOW);
      digitalWrite (yellow2,  LOW);
      digitalWrite (green2,   HIGH);
    break;

    case 5:                               //LED outputs are defined for state 5
      digitalWrite (red1,     HIGH);
      digitalWrite (yellow1,  LOW);
      digitalWrite (green1,   LOW);
      digitalWrite (red2,     LOW);
      digitalWrite (yellow2,  HIGH);
      digitalWrite (green2,   LOW);
    break;

    case 6:                               //LED outputs are defined for state 6
      digitalWrite (red1,     HIGH);
      digitalWrite (yellow1,  LOW);
      digitalWrite (green1,   LOW);
      digitalWrite (red2,     HIGH);
      digitalWrite (yellow2,  LOW);
      digitalWrite (green2,   LOW);
    break;

    case 7:                               //LED outputs are defined for state 7
      digitalWrite (red1,     LOW);
      digitalWrite (yellow1,  LOW);
      digitalWrite (green1,   HIGH);
      digitalWrite (red2,     HIGH);
      digitalWrite (yellow2,  LOW);
      digitalWrite (green2,   LOW);
    break;

    case 8:                               //LED outputs are defined for state 8
      digitalWrite (red1,     HIGH);
      digitalWrite (yellow1,  LOW);
      digitalWrite (green1,   LOW);
      digitalWrite (red2,     LOW);
      digitalWrite (yellow2,  LOW);
      digitalWrite (green2,   HIGH);
    break;
  }
}

void next_state_FSM(){                    //this function defines when to change state and which state to change to based on the delay value and the presence of pedestrians
  switch (state){
    case 1:
       if(atraso>5000){
        state=2;
        PreviousMillis=CurrentMillis;
      }else{
        if(cross==1){
          state=7;                        // does not reset previous millis so the "timer" can keep counting
        }
      }
    break;
    
    case 2:
      if(atraso>2000){
        state=3;
        PreviousMillis=CurrentMillis;
      }
    break;
    
    case 3:
    if(atraso>2000){
      state=4;
      PreviousMillis=CurrentMillis;
    }
    break;
    
    case 4:
    if(atraso>5000){
      state=5;
      PreviousMillis=CurrentMillis;    
    }else{
      if(cross2==1){
        state=8;
      }
    }
    
    break;
    
    case 5:
      if(atraso>2000){
        state=6;
        PreviousMillis=CurrentMillis;
      }
    break;
    
    case 6:
      if(atraso>2000){
        state=1;
        PreviousMillis=CurrentMillis;
      }
    break;
    
    case 7:                                 // auxiliar state to make the green light go out sooner
      if(cross==0){
          state=1;                          // does not reset previous millis so the "timer" can keep counting
      }else{
        if(atraso>1000){
          state=2;
          PreviousMillis=CurrentMillis;
        }
      }
    break;

    case 8:                                 // auxiliar state to make the green light go out sooner
      if(cross2==0){
          state=4;                          // does not reset previous millis so the "timer" can keep counting
      }else{
        if(atraso>1000){
          state=5;
          PreviousMillis=CurrentMillis;
        }
      }
    break;
  }
}

long microsecondsToCentimeters(long microseconds) {
                                            // The speed of sound is 340 m/s or 29 microseconds per centimeter.
                                            // The ping travels out and back, so to find the distance of the
                                            // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
