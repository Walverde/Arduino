
/*
  ________________________________________________________
  | Name: Led Control for RC car.                          |
  | By: Walgreen Melo                                      |
  | Date: 26/10/2019                                       |
  |                                                        |
  | Edit: v2-2 : Substition Dellay for Millis              |
  |                                                        |
  |Older Versions                                          |
  |                                                        |
  |                                                        |
  | V2.1:  Subistition IF for While                        |
  |       Chanel three (3) for front LED.                  |
  |       Vercions Control                                 |
  | V1:   Radio recognition off                            |
  |       OUTPUTT Whith PWM Control                        |
  | V0:   Only led control whith reader PWM reciver.       |
  |________________________________________________________|
*/

//PRE SET chanels________________________________________________

// Variables
  //Quantidade de canais a serem usados____________________
int ch1;
int ch2;
int ch3;
  // dados
  int temperature;
  int volts;
  int current;
//int ch4;
//Pinos de ENTRADA de SINAL para cada canal______________
#define s1 9  // para canal 1 (Direcao)
#define s2 10 // para canal 2 (Trotter)
#define s3 11 // para canal 3 (Auxiliar) 

// Dados 
#define dt 8 // temperatura
#define dv 7 // tensao
#define di 6 // corrente

//#define s3 12 // para canal 4
//Pinos de SAIDA para os LEDS _____________________________
#define LFront 2 // Definindo o Pino do LED Frente
#define LLeft  3 // Definindo o Pino do LED Esquerda
#define LRight 4 // Definindo o Pino do LED Direita
#define LBack  5 // Definindo o Pino do LED TRAZ

//Valores PRE SET em PWM___________________________________
unsigned long Xcorte = 350; // Valor fixo de minimo dos canais
unsigned long Min = 1100;   // Valor fixo de minimo dos canais
unsigned long Med = 1450;   // Valor fixo de Medio dos canais
unsigned long Max = 1950;   // Valor fixo de Maximo dos canais

//Setando contador Millis _________________________________

unsigned long delay1 = 0;

void setup() {
  //Comunicação serial______________________________________
  
  Serial.begin(115200);
  Serial.println();
  // Serial.print("Connecting to ");
  // Serial.println(ssid);

  //Entradas _______________________________________________
  pinMode(s1, INPUT); // Configurando com pino de entrada da direcao
  pinMode(s2, INPUT); // Configurando com pino de entrada da Throter
  pinMode(s3, INPUT); // Configurando com pino de entrada do Auxiliar
      // Leitura de dados. 
  pinMode(dt, INPUT); // temperatura
  pinMode(dv, INPUT); // tensao
  pinMode(di, INPUT); // corrente
  //Saidas _________________________________________________
  pinMode(LFront, OUTPUT); // Configurando com pino de saida LED
  pinMode(LBack, OUTPUT); // Configurando com pino de saida LED
  pinMode(LRight, OUTPUT); // Configurando com pino de saida LED
  pinMode(LLeft, OUTPUT); // Configurando com pino de saida LED
  /*
    st1 = pulseIn (s1, HIGH, 25000);
    st2 = pulseIn (s2, HIGH, 25000);
    st3 = pulseIn (s3, HIGH, 25000);
  */
  // Serial.begin(9600); // Pour a bowl of Serial
}

void loop() {

  ch1 = pulseIn(s1, HIGH, 25000); // Read the pulse width of
  ch2 = pulseIn(s2, HIGH, 25000); // each channel
  ch3 = pulseIn(s3, HIGH, 25000); // Auxiliar 

// Reading Datas dt, dv, di. (Corrent, tensao e temperatura) 

  temperature = digitalRead(dt);
  volts = digitalRead(dv);
  current = digitalRead(di);

// LEDS--------------------------------------------------------------------------------
  //Front Led control ch3 Chanel____________________________
  do {
    digitalWrite(LFront, !HIGH);
    // delay(500);
  } while (ch3 > (Max - Xcorte));

  do {
    digitalWrite(LFront, !LOW);
  } while (ch3 < (Min + Xcorte));

  //Throter_________________________________________________

  do {
    digitalWrite(LBack, !HIGH);

    // delay(500);
  } while (ch2 < (Min + Xcorte));

  do {
    digitalWrite(LBack, !LOW);
  } while (ch2 != (Min + Xcorte));

  //Turn ____________________________________________________

  //LEFT
  do {
    if ((millis() - delay1) >= 500) {
      digitalWrite(LLeft, !HIGH);
    }
    if ((millis() - delay1) < 500) {
      digitalWrite(LLeft, !LOW);
    }
    if ((millis() - delay1) >= 1000) {
      delay1 = millis();
    }
  } while ((ch1 < (Min + Xcorte)) && (ch1 != 0));
  do {
    digitalWrite(LLeft, !LOW);
  } while ((ch1 != (Min + Xcorte)) && (ch1 != 0));

  //RIGHT
  do {
    if ((millis() - delay1) > 500) {
      digitalWrite(LRight, !HIGH);
    }
    if ((millis() - delay1) < 500) {
      digitalWrite(LRight, !LOW);
    }
    if ((millis() - delay1) >= 1000) {
      delay1 = millis();
    }
  } while (ch1 > (Max - Xcorte));
  do {
    digitalWrite(LRight, !LOW);
  } while (ch1 != (Max - Xcorte));

//Radio off _________________________________________

  do {
    if ((millis() - delay1) > 500) {
      digitalWrite(LLeft, !HIGH);
      digitalWrite(LRight, !HIGH);
      digitalWrite(LFront, !HIGH);
      digitalWrite(LBack, !HIGH);
    }
    if ((millis() - delay1) < 500) {
      digitalWrite(LLeft, !LOW);
      digitalWrite(LRight, !LOW);
      digitalWrite(LFront, !LOW);
      digitalWrite(LBack, !LOW);
    }
    if ((millis() - delay1) >= 1000) {
      delay1 = millis();
    }
  } while ((ch1 == 0) && (ch2 == 0));

  /*else{
    digitalWrite(LLeft,!LOW);
    digitalWrite(LRight,!LOW);
    }
  */
  Serial.print(ch1);

  delay(100); // I put this here just to make the terminal
  // window happier
}
