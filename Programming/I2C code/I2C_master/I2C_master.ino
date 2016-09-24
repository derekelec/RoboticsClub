// Chapter 7 - Communications
// I2C Master
// By Cornel Amariei for Packt Publishing

// Include the required Wire library for I2C
#include <Wire.h>

void send_package(int outVar, char outChar);

/*
definitions for the stepper motor library commands
*/
#define STEPPER_STEPPER 'A' //  void Stepper::Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);
#define STEPPER_STEPSPEED 'B' // void Stepper::setSpeed(long whatSpeed);
#define STEPPER_STEP 'C' // void Stepper::step(int steps_to_move);
#define STEPPER_STEPMOTOR 'D'     //  void Stepper::stepMotor(int thisStep);
#define STEPPER_VERSION 'E'     // int Stepper::version(void);

int x = 0;
int LED = 13;

void setup() {
  // Start the I2C Bus as Master
  Wire.begin();
  Serial.begin(9600);
  pinMode (LED, OUTPUT);
}

void loop() {
Serial.println("Testing all packages:");
send_package(55,STEPPER_STEPPER);
send_package(66,STEPPER_STEPSPEED);
send_package(77,STEPPER_STEP);
send_package(88,STEPPER_STEPMOTOR);
send_package(99,STEPPER_VERSION);
send_package(101,'G'); // tests functionality, should output "test fail"

delay(1000);    
}
