#include <Servo.h> 
Servo servo;

int led = 8;   
int botao = 2;

int estadoBotao = 0;
int ultimoEstadoBotao = 0;
bool portaAberta = false;  // Variável para controlar se a porta está aberta ou fechada

unsigned long debounceDelay = 50; // Tempo para o debounce
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(7, OUTPUT); 
  pinMode(botao, INPUT);
  servo.attach(6);  // Liga o servo na porta 6
  servo.write(0);    // Inicializa o servo na posição 0 (fechado)
  digitalWrite(led, HIGH); // Inicializa o LED como ativo
}

void loop() {  
  int leituraAtual = digitalRead(botao);

  // Implementação do debounce
  if (leituraAtual != ultimoEstadoBotao) {
    lastDebounceTime = millis();  // Atualiza o tempo de debounce
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Se o botão foi pressionado (mudou para HIGH)
    if (leituraAtual == HIGH) {
      // Alterna o estado da porta (aberta ou fechada)
      portaAberta = !portaAberta;

      if (portaAberta) {
        // Abrir porta
        digitalWrite(led, LOW);    // Desliga o LED indicando que a porta está abrindo
        digitalWrite(7, HIGH);     // Ativa outro LED ou componente
        servo.write(90);           // Move o servo para a posição aberta (90 graus)
        delay(1000);               // Tempo de abertura
      } else {
        // Fechar porta
        digitalWrite(7, LOW);      // Desativa o segundo LED
        digitalWrite(led, HIGH);   // Liga o LED indicando que a porta está fechando
        servo.write(0);            // Move o servo para a posição fechada (0 graus)
        delay(1000);               // Tempo de fechamento
      }
    }
  }

  ultimoEstadoBotao = leituraAtual;  // Atualiza o estado do botão
}
