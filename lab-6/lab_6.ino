int ledPin = 11; 
int analogPin = A3;
int val = 0;
void setup() {
 pinMode(ledPin, OUTPUT);
 pinMode (analogPin, INPUT);
}
void loop() {
val = analogRead(analogPin);
analogWrite(ledPin, val / 4);
}