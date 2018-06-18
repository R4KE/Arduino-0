const int analogInPin0 = A0;
const int analogInPin1 = A1;
const int analogInPin2 = A2;
const int buttonPin = 2;
const int ledPin = 13;

int sensorValue0 = 0;
int sensorValue1 = 1;
int sensorValue2 = 2;

const int buzzer = 8; //buzzer to arduino pin 9

int delaytime = 0;
int buzztone = 100;
int constantSpeed = 10;
int modulator = 0;

int activeState = LOW;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(buttonPin, INPUT);
}

void loop() {
  activeState = digitalRead(buttonPin);
  if (activeState == HIGH) 
  {
      sensorValue0 = analogRead(analogInPin0);
      sensorValue1 = analogRead(analogInPin1);
      sensorValue2 = analogRead(analogInPin2);
      buzztone = map(sensorValue0, 0, 1023, 2500, 0);
      delaytime = map(sensorValue1, 0, 1023, 300, 0);
      modulator = map(sensorValue2, 0, 1023, 1000, 0);
      tone(buzzer, buzztone);
      tone(buzzer, buzztone + modulator);
      digitalWrite(ledPin, HIGH);
    
      if (delaytime > constantSpeed)
      {
        delay(delaytime);
        noTone(buzzer);
        noTone(buzzer);
        digitalWrite(ledPin, LOW);
        delay(delaytime);
      }  
  }
  else 
  {
    noTone(buzzer);
    noTone(buzzer);  
    digitalWrite(ledPin, LOW);
  }
}

