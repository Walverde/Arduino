int rele = 10;     // Constante do Rele referente ao pino 12
int rele1 = 13;
 
 

void setup() {
pinMode(rele, OUTPUT);      // Define o pino 12 (Relé) como pino de saída

}
 
// Comando de loop executado enquanto o Arduino estiver ligado
void loop() {

 
digitalWrite(rele, LOW);       // Relé permanece em seu estado inicial
delay(500);                   // Pressione por 2 segundos para alter/ar o estado do botão
digitalWrite(rele1, LOW);       // Relé permanece em seu estado inicial
delay(500);

digitalWrite(rele, HIGH);     // Relé altera seu estado inicial
delay(500);                  // Permanece acionado por 5 segundos
digitalWrite(rele1, HIGH);     // Relé altera seu estado inicial
delay(500);
}
