int VRX = 0; // Variacao No eixo X
int VRY = 0; // Variacao No eixo Y

/* Arduino Micro output pins*/

int ledAzul = 13; //Led Brack
int ledvermelho = 12; //Led Front
int estadorsensor ;
int sensor = 8; //Botao Brack

/*Arduino Micro Input Pins */




void setup(){

  pinMode(ledAzul, OUTPUT);
  pinMode(ledvermelho, OUTPUT);
  pinMode(sensor, INPUT_PULLUP);
  

}

void loop(){

estadorsensor = analogRead(sensor);

// Faze farol

if(estadorsensor && LOW ){
  digitalWrite(ledAzul, HIGH); 
  }else{
    digitalWrite(ledvermelho, LOW);
    }
}


