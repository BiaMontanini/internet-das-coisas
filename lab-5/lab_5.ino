int leds[] = {2,3,4};
int pinBT = 7;
int leitura;
int contador = 0;
bool chave = false;
void setup()
{
  for(int i = 0;i<=2;i++){
   pinMode(leds[i],OUTPUT); 
  }
  pinMode(pinBT,INPUT);
  Serial.begin(9600);
}

void loop()
{
  //Campo de leitura
  //A LEITURA DO BOTÃO É FEITA A CADA 5 SEGUNDOS
  //POR ISSO PRECIONAR POR MAIS TEMPO
  leitura = digitalRead(pinBT);
  Serial.print("Valor botao:");
  Serial.println(leitura);
 //Avanço dos sinais
  //Do vermelho ao verde
  if(contador <= 2 && !chave){
    digitalWrite(leds[contador],1);
    delay(500);
    digitalWrite(leds[contador],0);
    delay(10);
    if(contador == 2){chave = true;}
    else{contador+=1;}
  }
  //Do verde ao vermelho
  else if(contador >= 0 && chave){
    contador-=1;
    digitalWrite(leds[contador],1);
    if(contador == 0 && leitura){delay(2000);}//Caso o botão esteja precionado,delay 20s
    else{delay(500);}
    digitalWrite(leds[contador],0);
    delay(10);
    if(contador == 0){chave = false;contador += 1;}
  }
  
}