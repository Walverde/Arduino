#include <Servo.h> //BIBLIOTECA DE FUNÇÕES COM MOTORES SERVOS

 // DECLARAÇÃO DOS MOTORES UZADOS NO PROJETO...
  Servo servoEsq; //RODA ESQUERDA DA BASE DO BRAÇO...
  Servo servoDir;  //RODA DIREITA...
  Servo servoGarra;   //GARRA DO B RAÇO MECÂNICO...
  Servo servoBraco;  //MOTOR RESPONSÁVEL PELA MOVIMENTAÇÃO VERTICL DO BRAÇO...
  Servo servoBraco2;
 
  int posicaoBraco = 0;
  int posicaoGarra = 80;
 
void setup() //FUNÇÃO ONDE SÃO ESPECIFICADAS AS CONFIGURAÇÕES DO PROJETO...
{
  //ATRIBUIÇÃO DE PINOS PARA OS MOTORES
  servoGarra.attach(3);
  servoBraco.attach(5);
  servoBraco2.attach(6);
  servoEsq.attach(9);
  servoDir.attach(10);
  Serial.begin(9600);
}
//______________________________________________________________________________
void parado() //FUNÇÃO QUE MANTÉN OS DOIS SERVOS DE ROTAÇÃO CONTÍNUA USADOS NAS RODAS PARADOS (ROBÔ PARADO)...
{
  if(Valor_Sensor1 > 700 && Valor_Sensor2 > 700){
    sdirecao.attach(pinservo1); // Adcionando o servo ao pinservo1 
    delay(5);
    sdirecao.write(90); // virando servo de direcao para frente
    delay(10);
    sdirecao.detach();
    
    smotor.attach(pinservo2); // Adcionando o servo ao pinservo2
    delay(5);
    smotor.write(120); //acelerando somente com o servo de aceleracao
    delay(50); 
    smotor.detach();
}
void esquerda() //FUNÇÃO RESPONSÁVEL POR GIRAR A BASE PARA A DIREITA...
{
  if(Valor_Sensor1 < 700  && Valor_Sensor2 > 700){
    sdirecao.attach(pinservo1); // Adcionando o servo ao pinservo1 
    delay(5);
    sdirecao.write(150); // virando servo de direcao um pouco para direira
    delay(10);
    sdirecao.detach();
    
    smotor.attach(pinservo2); // Adcionando o servo ao pinservo2
    delay(5);
    smotor.write(88); // acelerando para reencontrar a faixa
    delay(50);
    sdirecao.detach();
}

void direita()  //FUNÇÃO RESPONSÁVEL POR GIRAR A BASE PARA A ESQUERDA...
{
  if(Valor_Sensor1 > 700 && Valor_Sensor2 < 700 ){
  sdirecao.attach(pinservo1); // Adcionando o servo ao pinservo1 
  delay(5);
  sdirecao.write(10); // virando servo de direcao para a esquerda 
  delay(10);
  sdirecao.detach();
    
  smotor.attach(pinservo2); // Adcionando o servo ao pinservo2
  delay(5);
  smotor.write(88); // acelerando para reencontrar a faixa 
  delay(50);
  sdirecao.detach();
}

void sobeBraco() // FUNÇÃO RESPONSÁVELPORLEVANTAR O BRAÇO MECÂNICO...
{
  if(Valor_Sensor1 < 700 && Valor_Sensor2 < 700 ){
    sdirecao.attach(pinservo1); // Adcionando o servo ao pinservo1 
    delay(5);
    sdirecao.write(90); // virando servo de direcao para a esquerda 
    delay(20);
    sdirecao.detach();

    smotor.attach(pinservo2); // Adcionando o servo ao pinservo2
    delay(5);
    smotor.write(90); // acelerando para reencontrar a faixa 
    delay(50);
    sdirecao.detach();
}

void baixaBraco() //FUNÇÃO RESPONSÁVEL POR BAIXAR O BRAÇO MECÂNICO...
{
  int i;
  for(i = posicaoBraco; i > 0;i--)
  {
      servoBraco.write(180-i);
      servoBraco2.write(i);
      delay(45);
  }
  posicaoBraco = i;
}

void abre() // FUNÇÃO QU ABRE A GARRA...
{
   int i;
  for(i = posicaoGarra; i < 160;i++)
  {
      servoGarra.write(i);
      delay(40);
  }
  posicaoGarra = i;
}

void fecha()  // FUNÇÃO QU FECHA A GARRA...
{
   int i;
  for(i = posicaoGarra; i > 80;i--)
  {
      servoGarra.write(i);
      delay(40);
  }
  posicaoGarra = i;
}


void loop()
{
    char tecla = Serial.read(); // A PORTA SERIAL LÊ UMA TECLA DIGITADA NO TECLADO DO COMPUTADOR...
                                //E DE ACORDO COM O CARACTER LIDO CHAMA UMA DAS FUNÇÕES ACIMA...
   
    if(tecla == 'd' || tecla == 'D') //CASO PRESSIONE A TECLA 'D', O ROBO GIRA PARA A DIREITA...
    {
      direita();
    }
    else if(tecla == 'e' || tecla == 'E') //CASO PRESSIONE A TECLA 'D', O ROBO GIRA PARA A ESQUERDA...
    {
      esquerda();
    }
   
    else if (tecla == 'a' || tecla == 'A') //CASO PRESSIONE A TECLA 'A', O ROBO ABRE A GARRA...
    {
       abre();
    }
    else if(tecla == 'f' || tecla == 'F') //CASO PRESSIONE A TECLA 'F', O ROBO FECHA A GARRA...
    {
      fecha();
    }
    else if (tecla == 's' || tecla == 'S') //CASO PRESSIONE A TECLA 'S', O ROBO SOBE O BRAÇO...
    {
        sobeBraco();
    }
    else if (tecla == 'b' || tecla == 'B') //CASO PRESSIONE A TECLA 'B', O ROBO BAIXA O BRAÇO...
    {
       baixaBraco();
    }
   
    else // CASO NÃO PRESSIONE NENHUMA TECLA O ROBÔ PERMANECE PARADO...
    {
        parado();
    }
}
