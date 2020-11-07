     
/*
 ________________________________________________________
| Name: Led Control for RC car.                          |
| By: Walgreen Melo                                      |
| Date: 26/10/2019                                       |
|                                                        |
| Edit: 2.1 Subistition IF for While                     |
|       Chanel three (3) for front LED.                  |
|       Vercions Control                                 |
|                                                        |
|Older Versions                                          |
| V1: Radio recognition off                              |
|     OUTPUTT Whith PWM Control                          |
| V0: Only led control whith reader PWM reciver.         |  
|________________________________________________________|
 */
//PRE SET________________________________________________

//Quantidade de canais a serem usados____________________
int ch1;
int ch2;
int ch3;
//int ch4;
//Pinos de ENTRADA de SINAL para cada canal______________
#define s1 9  // para canal 1
#define s2 10 // para canal 2
#define s3 11 // para canal 3
//#define s3 12 // para canal 4
//Pinos de SAIDA para os LEDS _____________________________
#define LFront 2 // Definincio o Pino do LED Frente
#define LLeft  3 // Definincio o Pino do LED Esquerda
#define LRight 4 // Definincio o Pino do LED Direita
#define LBack  5 // Definincio o Pino do LED TRAZ
/*
int st1; // Vai Quardar o estado do pino Direcao. 
int st2; // Vai Quardar o estado do pino Troter.
int st3; // Vai Quardar o estado do pino Auxiliar
*/
//Valores PRE SET em PWM_________________________________
unsigned long Xcorte = 350; // Valor fixo de minimo dos canais
unsigned long Min = 1100;   // Valor fixo de minimo dos canais
unsigned long Med = 1450;   // Valor fixo de Medio dos canais
unsigned long Max = 1950;   // Valor fixo de Maximo dos canais



void setup() {
//Entradas _______________________________________________
  pinMode(s1, INPUT); // Configurando com pino de entrada da direcao
  pinMode(s2, INPUT); // Configurando com pino de entrada da Throter
  pinMode(s3, INPUT); // Configurando com pino de entrada do Auxiliar
//Saidas _________________________________________________
  pinMode(LFront,OUTPUT); // Configurando com pino de saida LED
  pinMode(LBack,OUTPUT); // Configurando com pino de saida LED
  pinMode(LRight,OUTPUT); // Configurando com pino de saida LED
  pinMode(LLeft,OUTPUT); // Configurando com pino de saida LED
/*
  st1 = pulseIn (s1, HIGH, 25000);
  st2 = pulseIn (s2, HIGH, 25000);
  st3 = pulseIn (s3, HIGH, 25000);
*/
  Serial.begin(9600); // Pour a bowl of Serial
}

void loop() {

 // Foi comentado na Versao 2, verificar se não vai ter bugs
  
  ch1 = pulseIn(s1, HIGH, 25000); // Read the pulse width of 
  ch2 = pulseIn(s2, HIGH, 25000); // each channel
  ch3 = pulseIn(s3, HIGH, 25000); // 
  
  
//Throter_________________________________________________
if (ch3 > (Max - Xcorte)){
 digitalWrite(LFront,!HIGH); 
// delay(500);
}else{
  digitalWrite(LFront,!LOW);
}
if (ch2 < (Min + Xcorte)){
 digitalWrite(LBack,!HIGH); 
 
// delay(500);
}else{
  digitalWrite(LBack,!LOW);
}
//Read Chanels ____________________________________________
  ch1 = pulseIn(s1, HIGH, 25000); // Read the pulse width of 
  ch2 = pulseIn(s2, HIGH, 25000); // each channel
  ch3 = pulseIn(s3, HIGH, 25000); // 
//Turn ____________________________________________________

if ((ch1 < (Min + Xcorte))&&(ch1 != 0)){
 digitalWrite(LLeft,!HIGH); 
 delay(500);
 digitalWrite(LLeft,!LOW); 
 delay(500);
}else{
  digitalWrite(LLeft,!LOW);
}
if (ch1 > (Max - Xcorte)){
 digitalWrite(LRight,!HIGH); 
 delay(500);
 digitalWrite(LRight,!LOW); 
 delay(500);
}else{
  digitalWrite(LRight,!LOW);
}
//Read Chanels ____________________________________________
  ch1 = pulseIn(s1, HIGH, 25000); // Read the pulse width of 
  ch2 = pulseIn(s2, HIGH, 25000); // each channel
  ch3 = pulseIn(s3, HIGH, 25000); // 
//Radio Desligado _________________________________________
/*
if ((ch1 == 0)||(ch2 == 0)){
 digitalWrite(LLeft,!HIGH); 
 digitalWrite(LRight,!HIGH); 
 digitalWrite(LFront,!HIGH); 
 digitalWrite(LBack,!HIGH); 
 delay(500);
 digitalWrite(LLeft,!LOW); 
 digitalWrite(LRight,!LOW);
 digitalWrite(LFront,!LOW); 
 digitalWrite(LBack,!LOW);  
 delay(500);
 
}
*/
/*else{
  digitalWrite(LLeft,!LOW);
  digitalWrite(LRight,!LOW);
}
*/
  Serial.print(ch1);

  delay(100); // I put this here just to make the terminal 
  // window happier
}
