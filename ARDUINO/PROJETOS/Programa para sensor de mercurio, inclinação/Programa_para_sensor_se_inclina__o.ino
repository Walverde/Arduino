
/* Setando pinos para nomes*/

int ledAzul = 13; //Pino para por o LED AZUL
int ledvermelho = 12; //Pino para por o VERMELHO
int estadosensor ; //Variavel para armazenar os dados lidos no pino do Sensor. 
int sensor = 8; //Set pino do sensor. 

void setup(){

  pinMode(ledAzul, OUTPUT); // Configurando a variavel "ledAzul" como saida. 
  pinMode(ledvermelho, OUTPUT); // Configurando a variavel "ledvermelho" como saida.
  pinMode(sensor, INPUT_PULLUP); // Configurando a variavel "sensor" como entrada.

}

void loop(){

estadosensor = digitalRead(sensor); // Lendo o valor no pino do Sensro e armazendanod em estadosensor
// Faze farol

//comparando o estado do sensor com o nivel logico baixo "0" ou LOW, se for verdadeiro, então o ledAzul liga e o ledvermelho apaga. Em caso contrario, se inverte os leds.  
if(estadosensor && HIGH ){
  digitalWrite(ledAzul, HIGH); 
  digitalWrite(ledvermelho, LOW); 
  }else{
    digitalWrite(ledAzul, LOW); 
    digitalWrite(ledvermelho, HIGH); 
    }
}
