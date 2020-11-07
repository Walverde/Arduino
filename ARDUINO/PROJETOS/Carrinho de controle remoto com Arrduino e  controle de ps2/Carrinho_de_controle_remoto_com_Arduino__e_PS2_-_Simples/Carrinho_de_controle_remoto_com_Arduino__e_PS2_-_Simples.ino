
//Codigo Real
/* 

int Ledpin=9;

int analogpin=A0;
int value=0;
int x;

void setup()
{
Serial.begin(9600);
pinMode(Ledpin, OUTPUT);
}

void loop()
{
value=analogRead(analogpin);
x=map(value,0,1023,0,255);
analogWrite(Ledpin,x);
Serial.println(x);
delay(100);
}

//No lugar do potenciometro resolvi tascar o controle e o codigo ficou mais ou menos assim: (claro tem erro):
*/

// Codigo editado. 

#include <PS2X_lib.h>
PS2X ps2x;

int Ledpin=3;
int analogpin=PSS_LY;
int value=0;
int x;
byte vibrate = 0;

void setup()
{
Serial.begin(9600);
pinMode(Ledpin, OUTPUT);
ps2x.config_gamepad(13, 11, 10, 12, true, true);
}

void loop()
{
ps2x.read_gamepad(false, vibrate);
value=analogRead(analogpin);
x=map(value,0,1023,0,255);
analogWrite(Ledpin,x);
Serial.print(x);
delay(100);
}
