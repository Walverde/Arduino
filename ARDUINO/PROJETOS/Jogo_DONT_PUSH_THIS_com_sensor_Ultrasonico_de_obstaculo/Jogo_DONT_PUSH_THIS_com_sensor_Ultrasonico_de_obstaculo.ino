#include <NewPing.h>
#include <Servo.h> 
 
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
 
//representa o sonar
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
 
//representa o servo
Servo myservo;  // create servo object to control a servo
 
//armazena o estado da aplicacao
int state = 0; //0= leitura, 1=lendo, 2= abrindo, 3= mantendo aberto, 4= fechando
 
//guardo as leituras de marcos de tempo
unsigned long firstRead;
 
//abre a lixeira
void openTrash () {
  myservo.write(100);
  delay(100)  ;
}
 
//fecha a lixeira devagar
void closeTrash () {
  int i = 100;
  for (i = 100; i< 176; i+=1) {
   myservo.write(i);
  delay(20);
  }
 
}
 
void setup()
{
    myservo.attach(14);  //analog pin 0
    Serial.begin(9600);
    myservo.write(176); //fecha a lixeira
 
}
 
void loop()
{
 
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  //calcula os CMs do sonar
  unsigned int cm = uS / US_ROUNDTRIP_CM;
 
  //se for 0, a medida nao eh valida e jogamos para o infinito
  if (cm==0)
   cm = 1000;
 
 //estado 0. Leu medicao > 10 cm
 if (state == 0) {
    if (cm < 10) {
       firstRead = millis ();
       state = 1;
     }
 } else //estado 1. se continuar lendo a medicao por meio segundo, manda pro proximo estado //senao volta pro estado inicial
 if (state == 1) {
    if (cm > 10) {
       state = 0;
    } else {
       unsigned long now = millis();
       if (now - firstRead > 50) {
          state = 2;
       }
     }
 } else
 //estado 2. abre a lixeira e inicia o marco para calcular
 //o tempo de fechamento 1seg, e passa para o proximo estado
 if (state == 2) {
    openTrash ();
    firstRead = millis ();
    state = 3;
 } else
 //estado 3. Se a mao continuar a menos de 10cm, zerar o marco
 //se jah passou 1seg do marco, entao vai para o estado 4 de fechamento
 if (state == 3) {
    if (cm < 10)
    firstRead = millis ();
    unsigned long now = millis();
    if (now - firstRead > 1000) {
       state = 4;
    }
 } else
 //fecha o lixo
 if (state == 4) {
    closeTrash ();
    state = 0;
 }
 
}
