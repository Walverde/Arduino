//Leds ______________________________________________________________________________
int PLF = 12; // pino led set 12
int PLB = 11; // pino led set 11
int PLL = 10; // pino led set 10
int PLR = 9; // pino led set 9
//Botao botoes______________________________________________________________________________
int PB = 8; // pino Buser set 8
int BF = 7; // pino botao farol set 7
int BLL = 6; // pino botao pisca esquerta set 6
int BLR = 5; // pino botao pisca direita set 5
int BB = 4; // pino botao Buser set 4
int BBK = 3; // pino botao brack set 3


void setup() {

pinMode(PLF, OUTPUT);
pinMode(PLB, OUTPUT);
pinMode(PLL, OUTPUT);
pinMode(PLR, OUTPUT);
pinMode(PB, OUTPUT);

pinMode(BF, INPUT_PULLUP);
pinMode(BLL, INPUT_PULLUP);
pinMode(BLR, INPUT_PULLUP);
pinMode(BB, INPUT_PULLUP);
pinMode(BBK, INPUT_PULLUP);


}

void loop() {
  
// DE DIA

    if((BF == HIGH)&&(BLL == LOW)&& (BLR == HIGH)&&(BB==HIGH)&&(BBK = HIGH)){
    }
    if((BF == HIGH)&&(BLL == HIGH)&& (BLR == LOW)&&(BB==HIGH)&&(BBK = HIGH)){  
    }
    if((BF == HIGH)&&(BLL == LOW)&& (BLR == HIGH)&&(BB==HIGH)&&(BBK = HIGH)){
    }
    if((BF == HIGH)&&(BLL == HIGH)&& (BLR == LOW)&&(BB==HIGH)&&(BBK = HIGH)){  
    }
    if((BF == LOW)&&(BLL == LOW)&& (BLR == HIGH)&&(BB==HIGH)&&(BBK = HIGH)){
      
    }
  


}
