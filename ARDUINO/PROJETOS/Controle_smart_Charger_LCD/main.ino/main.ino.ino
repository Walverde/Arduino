
#include <LiquidCrystal.h> //INCLUSÃO DE BIBLIOTECA
  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //PORTAS DO ARDUINO QUE SÃO UTILIZADAS PELO SHIELD KEYPAD DISPLAY LCD

#define leitor 0
int ll;
  
void setup(){  
 Serial.begin(9600);
 pinMode(leitor, INPUT);
 lcd.begin(16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY. EM SUMA: UMA MATRIZ DE 16 COLUNAS E 2 LINHAS
 lcd.setCursor(0,0); //SETA A POSIÇÃO EM QUE O CURSOR INCIALIZA(LINHA 1) 
 lcd.print("APERTOU A TECLA"); //ESCREVE A FRASE "APERTOU A TECLA" NA PRIMEIRA LINHA DO DISPLAY LCD  
}  
  
void loop(){  

ll = analogRead(leitor);
  
 Serial.println(ll);
 lcd.setCursor(0,1); //SETA A POSIÇÃO EM QUE O CURSOR RECEBE O TEXTO A SER MOSTRADO(LINHA 2)
 // if ((analogRead(0)) < 80) { //SE A LEITURA DO PINO FOR MENOR QUE 80, FAZ 
 if ((analogRead(leitor)) < 20) { //SE A LEITURA DO PINO FOR MENOR QUE 80, FAZ 
  lcd.print ("    DIREITA    "); //ESCREVE NO LCD O TEXTO 
 }  
 else if ((analogRead(leitor)) < 200) { //SE A LEITURA DO PINO FOR MENOR QUE 200, FAZ
  lcd.print ("      CIMA     ");  //ESCREVE NO LCD O TEXTO
 }  
 else if ((analogRead(leitor)) < 400){ //SE A LEITURA DO PINO FOR MENOR QUE 400, FAZ  
  lcd.print ("     BAIXO     "); //ESCREVE NO LCD O TEXTO 
 }  
 else if ((analogRead(leitor)) < 600){ //SE A LEITURA DO PINO FOR MENOR QUE 600, FAZ  
  lcd.print ("    ESQUERDA   "); //ESCREVE NO LCD O TEXTO 
 }  
 else if ((analogRead(leitor)) < 800){ //SE A LEITURA DO PINO FOR MENOR QUE 800, FAZ 
  lcd.print ("     SELECT    "); //ESCREVE NO LCD O TEXTO 
 }  
}
