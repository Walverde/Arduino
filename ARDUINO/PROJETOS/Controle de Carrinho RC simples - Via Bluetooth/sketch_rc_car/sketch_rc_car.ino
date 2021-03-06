#include <SoftwareSerial.h>  

int bluetoothTx = 2; // TX-O pin of BT module to Arduino pin2
int bluetoothRx = 3; // RX-I pin of B module to Arduino pin3

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);


int forward = 4;
int backward = 5;
int left = 6;
int right = 7;

char cmd[100];
int cmdIndex;


void exeCmd() {
  
  if(cmd[0]=='f') {  // forward
    digitalWrite(backward, LOW);  // disable backward
    digitalWrite(forward, HIGH);  // enable forward
  } 
  
  if(cmd[0]=='b') {  // backward
    digitalWrite(forward, LOW); 
    digitalWrite(backward, HIGH);  
  } 
  
  if(cmd[0]=='s') {  // stop
    digitalWrite(backward, LOW);  
    digitalWrite(forward, LOW);
  }
  
  
  if(cmd[0]=='l') { // left
    digitalWrite(right, LOW);
    digitalWrite(left, HIGH);
  } 
  
  if(cmd[0]=='r') {  // right
    digitalWrite(left, LOW);
    digitalWrite(right, HIGH);
  } 
  
  if(cmd[0]=='c') {  // center
    digitalWrite(left, LOW);
    digitalWrite(right, LOW);
  } 
  
}



void setup() {   // at power on
  
  delay(500); // wait for bluetooth module to start
  
  pinMode(forward, OUTPUT);
  digitalWrite(forward, LOW);
  
  pinMode(backward, OUTPUT);
  digitalWrite(backward, LOW);
  
  pinMode(left, OUTPUT);
  digitalWrite(left, LOW);
  
  pinMode(right, OUTPUT);
  digitalWrite(right, LOW);
  
  // change Bluetooth module baud rate to 9600:
  
  bluetooth.begin(115200); // Bluetooth default baud is 115200
  
  bluetooth.print("$");
  bluetooth.print("$");
  bluetooth.print("$"); // enter cmd mode
  delay(250);  
  bluetooth.println("U,9600,N"); // change baud to 9600
  
  bluetooth.begin(9600);
  
  cmdIndex = 0;

}


void loop() {
  
  if(bluetooth.available()) {
 
    char c = (char)bluetooth.read();
    
    cmd[cmdIndex] = c;  
    if(cmdIndex<99) cmdIndex++;
      
    if(c=='\n') {   // each command ends with '\n'
      exeCmd();
      cmdIndex = 0;
    }  
  
  } 
  
}

