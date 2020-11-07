#define PVRX A2
#define PVRY A1
#define PSW 2

void setup() {
  // put your setup code here, to run once:

pinMode (PVRX, INPUT);
pinMode (PVRY, INPUT);
pinMode (PSW, INPUT_PULLUP);


Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

int valorVRX = analogRead(PVRX);
int valorVRY = analogRead(PVRY);
bool StatusSW = digitalRead(PSW);

Serial.print("valorVRY VRY: ");
Serial.print ( valorVRY);

Serial.print("valorVRX VRX: ");
Serial.print ( valorVRX);

Serial.print("StatusSW: ");
Serial.print ( StatusSW);

if (StatusSW) {
       Serial.println("Botao: [Solto]");
    }else{
      Serial.println("Botao: [Apertado]");
    }

}
