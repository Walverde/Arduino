//Motor 01

//o que fuunciou, foi jampeado o PWM como ativo. E o Proprio Sinal PWM foi mandado direto no VCC do Motor. 
#define vmotorL 10
#define mla 9
#define mlb 8
//Motor 02
#define vmotorR 11
#define mlc 12
#define mld 13
//Pre-set tempos de Dalay
#define t1 250
#define t2 500
#define t3 1000
#define t4 1500
//Sensores
int Sensor1 =14;   // Definindo sensor1 para o pino 1
int Sensor2 =15;   // Definindo sensor2 para o pino 2
int  Valor_Sensor1;  // Objeto para guardar valor lido de Sensor1
int  Valor_Sensor2;  // Objeto para guardar valor lido de Sensor2

// Pre-Set Velocidades Padrao
int v0= 70;  // Velocidade padrão

void setup() {
// Definindo modo leitura para pinos de sensores de faixa
  pinMode(Valor_Sensor1,INPUT);
  pinMode(Valor_Sensor2,INPUT);
// Definindo pinos de Saida para motor 01  
  pinMode(vmotorL,OUTPUT);
  pinMode(mla,OUTPUT);
  pinMode(mlb,OUTPUT);
// Definindo pinos de Saida para motor 02  
  pinMode(vmotorR,OUTPUT);
  pinMode(mlc,OUTPUT);
  pinMode(mld,OUTPUT);
}

void loop() {
//Lendo para Valor_Sensor# o pino Sensor#
  Valor_Sensor1=analogRead(Sensor1); 
  Valor_Sensor2=analogRead(Sensor2); 
  
  //para seguir reto
  if((Valor_Sensor1 < 700) && (Valor_Sensor2 < 700)){
    
    // Setando o Sentido do motor 
    digitalWrite(mla,LOW); 
    digitalWrite(mlb,HIGH); 
    digitalWrite(mlc,LOW); 
    digitalWrite(mld,HIGH); 

    // Acelerando
    analogWrite(vmotorL,v0);
    analogWrite(vmotorR,v0);
  }


  
  //Para a Direita 
  if((Valor_Sensor1 > 700) && (Valor_Sensor2 < 700)){
    
    // Setando o Sentido do motor 
    digitalWrite(mla,LOW); 
    digitalWrite(mlb,HIGH); 
    digitalWrite(mlc,LOW); 
    digitalWrite(mld,HIGH); 

    // Virando para a Direita
    analogWrite(vmotorL,v0*0.5);
    analogWrite(vmotorR,v0*2);
 }
  //Para a esquerda
  if((Valor_Sensor1 < 700) && (Valor_Sensor2 > 700)){

    // Setando o Sentido do motor 
    digitalWrite(mla,LOW); 
    digitalWrite(mlb,HIGH); 
    digitalWrite(mlc,LOW); 
    digitalWrite(mld,HIGH); 

    // Virando para a Esquerda
    analogWrite(vmotorL,v0*2);
    analogWrite(vmotorR,v0*0.5);
}  
  
}
