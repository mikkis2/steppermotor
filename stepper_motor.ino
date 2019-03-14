const int stepPin = 13;   //pin to pulse for steps
const int dirPin = 12;    //pin to change step direction
int sensorvalue = 0;
const int upPin = 7;
int steps = 0;

void setup(){
  Serial.begin(115200);
  //set pins as outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(upPin, OUTPUT);
  Serial.println("Setup completed");
}

void loop(){
  digitalWrite(upPin, HIGH);
  //step forward X steps
  stepperFWD();
  for(int i = 0; i < 1000; i++){
    motorStep();
    delay(10);
    steps ++;
  }

  //step backwards X steps
  stepperREV();
  for(int i = 0; i < 1000; i++){
    motorStep();
    delay(10);
    steps ++;
  }

}

//change the stepper direction to forward
void stepperFWD(){
  digitalWrite(dirPin, HIGH);
}

//change the stepper direction to reverse
void stepperREV(){
  digitalWrite(dirPin, LOW);

}

//have the stepper motor take one step
void motorStep(){
  digitalWrite(stepPin, HIGH);
  delay(2);
  digitalWrite(stepPin, LOW);
}

