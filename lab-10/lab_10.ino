int FTR = A0;//FoToResistência
int PIR = 2;//Sensor PIR
int RLY = 3;//Relé

int t;

void setup(){
  pinMode(PIR, INPUT);
  pinMode(RLY, OUTPUT);
}

void loop(){
  
  if(digitalRead(PIR) && (analogRead(FTR) < 300)){
    digitalWrite(RLY, HIGH);
    t=millis() + 9000;
  }
  
  if(t < millis()){
    digitalWrite(RLY, LOW);}
  else{
    digitalWrite(RLY, HIGH);}
  delay(4);
}