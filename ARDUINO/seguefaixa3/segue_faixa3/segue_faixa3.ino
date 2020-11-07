
//==================================Segue faixa===================================== 

//==================================Equipe: Vinicius Barboza e Eduardo Panceri==================================================== 
//*************** Definição dos Pinos ***********************
#define pinIN1 10    //Motor 1
#define pinIN2 9     //Motor 1
#define pinIN3 6     //Motor 2
#define pinIN4 5     //Motor 2 
#define Sensor_direita 4  //pino do sensor da direita
#define Sensor_esquerda 7 // pino so sensor da esquerda 
// valores para o pwm
#define veloc0 0
#define veloc1 25
#define veloc1b 20
#define veloc2 50
#define veloc21 40
#define veloc3 255 // nao foi usado o valor maximo 255 pois o motor e muito rapido





//*************** Variaveis para controle da direção ************
bool direita, esquerda;


void setup() {
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinIN3, OUTPUT);
  pinMode(pinIN4, OUTPUT);
  pinMode(Sensor_direita, INPUT);
  pinMode(Sensor_esquerda, INPUT);
  // pinMode(pinBotao, INPUT_PULLUP);
}


void loop() {

  //leitura dos sensores

  direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);
  Serial.print(direita); // serial.print apenas para calibraçao dos sensores
  Serial.print(" || ");
  Serial.println(esquerda);

  //=============================Controle da direção ==============================
  if (direita == false && esquerda == false) {
    analogWrite(pinIN1, veloc2);
    analogWrite(pinIN2, 0);
    analogWrite(pinIN3, veloc21);
    analogWrite(pinIN4, 0);
  } else if (direita == false && esquerda == true) {
    delay(300);
    analogWrite(pinIN1, veloc2);
    analogWrite(pinIN2, 0);
    analogWrite(pinIN3, veloc1);
    analogWrite(pinIN4, 0);
    delay(300);
  } else if (direita == true && esquerda == false) {
    delay(300);
    analogWrite(pinIN1, veloc1);
    analogWrite(pinIN2, 0);
    analogWrite(pinIN3, veloc21);
    analogWrite(pinIN4, 0);
    delay(300);
  } else if (direita == true && esquerda == true) {
    analogWrite(pinIN1, veloc0);
    analogWrite(pinIN2, 0);
    analogWrite(pinIN3, veloc0);
    analogWrite(pinIN4, 0);
  }
  /*Para frente
    int velocidade = map(pot1, 512, 1023, 0, 255);

    analogWrite(pinIN1, velocidade * pDireita / 100);
    analogWrite(pinIN2, 0);

    analogWrite(pinIN3, velocidade * pEsquerda / 100);
    analogWrite(pinIN4, 0);*/

}
