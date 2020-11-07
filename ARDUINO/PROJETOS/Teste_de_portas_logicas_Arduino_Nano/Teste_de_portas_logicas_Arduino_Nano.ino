//Configurando nomeclatura padrão dos botoes na plaquinha.  

int a0 = 14;
int a1 = 15;
int a2 = 16;
int a3 = 17;
int a4 = 18;
int a5 = 19;
int a6 = 20;
int a7 = 21;
int D2 = 2;
int D3 = 3;
int D4 = 4;
int D5 = 5;
int D6 = 6;
int D7 = 7;
int D8 = 8;
int D9 = 9;
int D10 = 10;
int D11 = 11;
int D12 = 12;
int D13 = 13;


void setup() {
  // Setando todos os pino como saidas para teste de OutPut Voltage:

pinMode(a0,OUTPUT);
pinMode(a1,OUTPUT);
pinMode(a2,OUTPUT);
pinMode(a3,OUTPUT);
pinMode(a4,OUTPUT);
pinMode(a5,OUTPUT);
pinMode(a6,OUTPUT);
pinMode(a7,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
pinMode(D5,OUTPUT);
pinMode(D6,OUTPUT);
pinMode(D7,OUTPUT);
pinMode(D8,OUTPUT);
pinMode(D9,OUTPUT);
pinMode(D10,OUTPUT);
pinMode(D11,OUTPUT);
pinMode(D12,OUTPUT);
pinMode(D13,OUTPUT);
}

void loop() {
  // Testando todos os pinos com 5v para teste de contato. 

  
  digitalWrite(a0,HIGH);
  digitalWrite(a1,HIGH);
  digitalWrite(a2,HIGH);
  digitalWrite(a3,HIGH);
  digitalWrite(a4,HIGH);
  digitalWrite(a5,HIGH);
  digitalWrite(a6,HIGH);
  digitalWrite(a7,HIGH);
  digitalWrite(D13,HIGH);
  digitalWrite(D12,HIGH);
  digitalWrite(D11,HIGH);
  digitalWrite(D10,HIGH);
  digitalWrite(D9,HIGH);
  digitalWrite(D8,HIGH);
  digitalWrite(D7,HIGH);
  digitalWrite(D6,HIGH);
  digitalWrite(D5,HIGH);
  digitalWrite(D4,HIGH);
  digitalWrite(D3,HIGH);
  digitalWrite(D2,HIGH);

}
