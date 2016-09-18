// Chapter 7 - Communications
// I2C Slave
// By Cornel Amariei for Packt Publishing
/*
arduino nano: A4(SDA), A5(SCL)
arduino uno pinout: 
*/
// Include the required Wire library for I2C
#include <Wire.h>

void receiveEvent(int);
void debugging_flasher( int pin, int time, int v, char c);

int LED = 13;
int x = 0;

void setup() {
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  pinMode(12,OUTPUT);
  
  digitalWrite(LED, HIGH);
  digitalWrite(12, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  digitalWrite(12, LOW);  
  delay(200);
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED,LOW);
  
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  
}

void loop() {
  //If value received is 0 blink LED for 200 ms
  delay(100);
}

void receiveEvent(int bytes) {


/*  
  while(1 <Wire.available()){// loop through all but the last
    char c=Wire.read(); // receive the byte as a character
    Serial.print(c); // print the character
  x = Wire.read();    // read one character from the I2C
}
*/
int inVar;
char inByte;

// receive byte as an integer

inVar = Wire.read();
inByte = Wire.read();
int test = perform_function(inVar,inByte);

Serial.print("   success?: ");
Serial.println(test);// now it is time to test functionality

}//END: void receiveEvent(int bytes)

