  // put your setup code here, to run once:

  int sinal1 = 0; // Objeto do Sensor. 
  int val;





void setup() {
  Serial.begin(9600);

  pinMode(sinal1, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  val=analogRead(sinal1);
  Serial.print("Valor do Potenciometro:");
  Serial.println(val);

}
