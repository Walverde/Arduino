



void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
}

extern void umsegund();
extern void control_leds();
extern void meiosegund();

void loop() {
   umsegund();
   control_leds();
   meiosegund();
  delay(2000);                      // Wait for two seconds (to demonstrate the active low LED)
}
