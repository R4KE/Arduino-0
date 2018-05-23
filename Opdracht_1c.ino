//speed var for disco mode :)
float speed = 50;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
   pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(speed);
  digitalWrite(13, LOW);
  delay(speed);
  digitalWrite(12, HIGH);
  delay(speed);                      
  digitalWrite(12, LOW);    
  delay(speed);             
}
