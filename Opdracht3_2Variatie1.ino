const int led = 9;      // PWM ("analog out")
const int upButton = 2;
const int downButton = 3;
int brightnessAmount = 32;

int ledLevel = 1;     // always a power of 2, 1..256

void setup() {
  pinMode(led, OUTPUT);
  pinMode(upButton, INPUT);
  pinMode(downButton, INPUT);
}

void loop() {
  
  if (digitalRead(upButton)) {
     if (ledLevel < 256) {
      ledLevel = ledLevel + brightnessAmount;
     }
     delay(300);
  }

  if (digitalRead(downButton)) {
    if (ledLevel > 1) {
      ledLevel = ledLevel - brightnessAmount;
    }
    delay(300);
  }

  analogWrite(led, ledLevel - 1); 
}
