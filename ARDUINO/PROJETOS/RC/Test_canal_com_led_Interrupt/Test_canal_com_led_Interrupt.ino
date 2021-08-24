     
/*
 RC PulseIn Serial Read out
 By: Nick Poole
 SparkFun Electronics
 Date: 5
 License: CC-BY SA 3.0 - Creative commons share-alike 3.0
 use this code however you'd like, just keep this license and
 attribute. Let me know if you make hugely, awesome, great changes.
 */
 
int ch1; // Here's where we'll keep our channel values
int ch2;
int ch3;

#define s1 4  // Definindo Pino de sinal 1 Direcao. 
#define s2 3 // Definindo Pino de sinal 2 Troter.
#define s3 2 // Definindo Pino de sinal 3 Auxiliar.
/*
int st1; // Vai Quardar o estado do pino Direcao. 
int st2; // Vai Quardar o estado do pino Troter.
int st3; // Vai Quardar o estado do pino Auxiliar
*/
unsigned long Xcorte = 350; // Valor fixo de minimo dos canais

unsigned long Min = 1100; // Valor fixo de minimo dos canais
unsigned long Med = 1450; // Valor fixo de Medio dos canais
unsigned long Max = 1950; // Valor fixo de Maximo dos canais


#define LFront 7 // Definincio o Pino do LED Frente
#define LLeft  8 // Definincio o Pino do LED Esquerda
#define LRight 6 // Definincio o Pino do LED Direita
#define LBack  5 // Definincio o Pino do LED TRAZ

void SinalThroter ();

void setup() {

  pinMode(s1, INPUT); // Configurando com pino de entrada da direcao
  pinMode(s2, INPUT); // Configurando com pino de entrada da Throter
  pinMode(s3, INPUT); // Configurando com pino de entrada do Auxiliar
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

 // attachInterrupt(digitalPinToInterrupt(s2), SinalThroter, CHANGE);


}

void loop() {

  ch1 = pulseIn(s1, HIGH, 25000); // Read the pulse width of 
  ch2 = pulseIn(s2, HIGH, 25000); // each channel
  ch3 = pulseIn(s3, HIGH, 25000); //

// digitalWrite(LFront,!HIGH); To usando um display LED Catodo comum. Por isso o sinal investido, se caso usar LED pela saida normal 5v, so tirar os ! 
  
//Turn ______________________________________________________________________________

if ((ch1 < (Min + Xcorte))&&(ch1 != 0)){
 digitalWrite(LLeft,HIGH); 
 delay(300);
 digitalWrite(LLeft,LOW); 
 delay(300);
}else{
  digitalWrite(LLeft,LOW);
}
if (ch1 > (Max - Xcorte)){
 digitalWrite(LRight,HIGH); 
 delay(300);
 digitalWrite(LRight,LOW); 
 delay(300);
}else{
  digitalWrite(LRight,LOW);
}
//Radio Desligado ______________________________________________________________________________
if ((ch1 == 0)||(ch2 == 0)){
 digitalWrite(LLeft,HIGH); 
 digitalWrite(LRight,HIGH); 
 digitalWrite(LFront,HIGH); 
 digitalWrite(LBack,HIGH); 
 delay(300);
 digitalWrite(LLeft,LOW); 
 digitalWrite(LRight,LOW);
 digitalWrite(LFront,LOW); 
 digitalWrite(LBack,LOW);  
 delay(300);
}/*else{
  digitalWrite(LLeft,!LOW);
  digitalWrite(LRight,!LOW);
}
*/

//Throter______________________________________________________________________________
if (ch2 > (Max - Xcorte)){
 digitalWrite(LFront,HIGH); 
// delay(500);
}else{
  digitalWrite(LFront,LOW);
}
//if ((ch1 < (Min + Xcorte))&&(ch1 !=0)){
if   ((ch2 < (Min + Xcorte))&&(ch2 !=0)) {
 digitalWrite(LBack,HIGH); 
 
// delay(500);
}else{
  digitalWrite(LBack,LOW);
}

  Serial.print(ch1);
  delay(100); // I put this here just to make the terminal 
  // window happier
}
/*
void SinalThroter (){
//Throter______________________________________________________________________________
if (ch2 > (Max - Xcorte)){
 digitalWrite(LFront,HIGH); 
// delay(500);
}else{
  digitalWrite(LFront,!LOW);
}
//if ((ch1 < (Min + Xcorte))&&(ch1 !=0)){
if   ((ch2 < (Min + Xcorte))&&(ch2 !=0)) {
 digitalWrite(LBack,HIGH); 
 
// delay(500);
}else{
  digitalWrite(LBack,LOW);
}
}*/
