// Chapter 7 - Communications
// I2C Slave
// By Cornel Amariei for Packt Publishing
/*
arduino nano: A4(SDA), A5(SCL)
arduino uno pinout: 
*/
// Include the required Wire library for I2C
#include <Wire.h>
#include <Stepper.h>

void receiveEvent(int);
//void debugging_flasher( int pin, int time, int v, char c);
boolean perform_function(int,char);

//int LED = 13;
int x = 0;
int motor_pin_1 = 1;
int motor_pin_2 = 2;
int motor_pin_3 = 3;
int motor_pin_4 = 4;
int motor_pin_5 = 5;
int motor_pin_6 = 6;
int motor_pin_7 = 7;
int motor_pin_8 = 8;

const int number_of_steps = 400;

Stepper myStepper1(number_of_steps, motor_pin_1, motor_pin_2, motor_pin_3, motor_pin_4);
Stepper myStepper2(number_of_steps,motor_pin_5,motor_pin_6,motor_pin_7,motor_pin_8);


void setup() {
 // myStepper1.setSpeed(60);
 // myStepper2.setSpeed(60);
  
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  Serial.print("completed setup\n");
}

void loop() {
  //If value received is 0 blink LED for 200 ms
  delay(100);
}

void receiveEvent(int bytes) {

int inVar;
char inByte;

// receive byte as an integer
inVar = Wire.read();
inByte = Wire.read();
boolean test = perform_function(inVar,inByte);

Serial.print("   success?: ");
Serial.println(test);// now it is time to test functionality

}//END: void receiveEvent(int bytes)
