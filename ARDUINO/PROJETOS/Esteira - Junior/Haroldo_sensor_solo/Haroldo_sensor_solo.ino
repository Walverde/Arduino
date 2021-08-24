
#define rout D7 // Pino D8 para o Rele. 
#define sa A0 // Pino D7 para o sensorA
#define sd D5 // Pino D7 para o sensorB

bool staterele = HIGH;

float valsa;
bool valsd;

float xcorte = 250;
float seco = 1024;
float molhado = 800;

unsigned long lastMsg = 0;
char *stringstate[] = {"Regando","Nao Esta regando","Erro"};

void setup() {
  // put your setup code here, to run once:
pinMode(rout, OUTPUT); // Configurando o pino do rele como saida. 
pinMode(sa, INPUT); // Configurando o rele como saida.
pinMode(sd, INPUT); // Configurando o rele como saida. 
  // inicializa o wifi, mqtt e led de status. 
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    valsa = analogRead(sa);
    lastMsg = now;
        if (valsa < seco - xcorte ){
          // staterele = HIGH;
          digitalWrite(rout, LOW); // tout D7, sa d6, sd d5
          Serial.println(stringstate[1]);
      }else{
        digitalWrite(rout, HIGH); // tout D7, sa d6, sd d5
        Serial.println(stringstate[0]);
      }; 
    
    };

}
