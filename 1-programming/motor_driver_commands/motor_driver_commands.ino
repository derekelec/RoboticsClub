
/* 
 Stepper Motor Control - speed control
 - general control for stepper motors using the existing arduino C++ library files
 - input: serial communication from an Rasp Pi
 - output to drive stepper motors (duhh!)

  Created 23 Aug. 2016
  by Matthew McCann  
  CAUTION: Do not program the Pi or the Arduino while the serial communication is connected.
  - the TX/RX pin is at 5V even when the pin is set as input and no internal pullup! 
  - maybe it has a weak external pullup due to the double function as programming interface
  "SUGGESTED TO USE MAX3232 3-V to 5.5-V Multichannel RS-232 Line Driver/Receiver" ($2.59) OR A "Level converter chip"
  
  
  


stepper motor functions include the following:  
void Stepper::Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);
void Stepper::setSpeed(long whatSpeed);
void Stepper::step(int steps_to_move);
void Stepper::stepMotor(int thisStep);
int Stepper::version(void);

Serial communication input should be tested with an arduino
- input serial hex data, read it on the digital analyzer
- use arduino to serial read the hex input, and flash LEDs on ports to test the input
- code the input to handle the hexidecimal serial input
- use case statements to handle the input

Pi code: <http://codeandlife.com/2012/07/29/arduino-and-raspberry-pi-serial-communication/ >

// begining of pi code
#!/usr/bin/env python

import serial
import string

rot13 = string.maketrans( 
    "ABCDEFGHIJKLMabcdefghijklmNOPQRSTUVWXYZnopqrstuvwxyz", 
    "NOPQRSTUVWXYZnopqrstuvwxyzABCDEFGHIJKLMabcdefghijklm")

test=serial.Serial("/dev/ttyAMA0",9600)
test.open()

try:
    while True:
                line = test.readline(eol='\r')
                test.write(string.translate(line, rot13))
                
except KeyboardInterrupt:
    pass # do cleanup here

test.close()

// end of pi code

 */

#include <Stepper.h>
#define ACK 'A' // saved as 65 (in decimal) 
#define SYN_ACK 'B' // saved as 66 (decimal)

/*
- insert part for testing lights, that flash for communication made and flash LEDs for each command executed
flashLED(); // fuction used to flash an LED on a port for 2 seconds at 10 Hz
*/

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution for your motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            
int stepCount = 0;  // number of steps the motor has taken


// setup() will only stop once the establish contact function gets something > 0 is read on the serial port
void setup() 
{
 
  Serial.begin(9600);
//  Serial.setTimeout();// defaults to delaying 1s

  while (!Serial) {;}// wait for serial port to connect. Needed for native USB port only
// does not stop sending "A" until Rx reads something
  establishContact();
}

void loop() 
{
  // now your communication has been set, and the PI has access to the motor functions
  // run timer and have it track the total on-time, have this as a time out function, then go back to low-power mode  
  
  // wait for commands
  int incomingByte=0;
  if( Serial.read >0)
  {
// read and store Rx line
  incomingByte = Serial.read(); 

// this function should just save the command and then perform it   
// if it receives ACK then it will just do wait and do the command
  while(perform_function(incomingByte)!=1);
  }
  
}// end of void loop()


/*
FUNCTIONS 

*/

//sends "A" on Tx line until it reads something > zero on the Rx line.
void establishContact()
{
  //variables to control the handshake
  int read_serial=0;
 //control variables for safe exit
  boolean ackTest = false;
  boolean synAckTest = false;

//while(ackTest && synAckTest == false)
//{  
  while (Serial.available() <= 0) 
{
    Serial.print(ACK);   // send a capital A
    delay(300);
}
/*
read_serial = Serial.read(); // save the input value
  if( read_serial == ACK){
   // may need to empty the buffer? test it out
   // now you should expect the SYN_ACK or "B" incoming
  ackTest=true;
  read_serial=0; // reset to zero for the next incoming byte
  Serial.print(SYN_ACK);

read_serial = Serial.read(); 
    if( synAck == SYN_ACK) {
      // now both booleans are true so you can exit
     synAckTest = true;
     Serial.print(ACK);
     // sending ACK should initiate communication with device that is connected
     // now your device should be sending information to me
    }
  }
// can insert printOut or flash to show which step was received if you want

} // end of "while(ackTest && synAckTest == false)"

*/


/* A SNIPPET OF RECIPROCAL CODE FOR THE SENDER TO USE

// one variables that are used to handle incoming data
// two boolean control variables
// while loop until read something, and send out ACK
// if you read ACK then send SYN_ACK
// start a timeout timer  for listening
// if you receive SYN_ACK then wait for ACK and you can send data
// make sure timeout counter is disable, otherwise return to sending ACK
*/
}// END OF void establishContact()


/*
FUNCTION :    int perform_function(incomingByte)
DESCRIPTION: returns zero for ACK, and '1' for a command executed
NOTES: this function needs to be able to read quite a large range of data, look at Stepper:Stepper(int number_of_steps .. 
*/


int perform_function(incomingByte)
{
// test so that "ACK" is not what is received
int motorCommand=inComingByte;

if(motorCommand==ACK)
{
 // now you should just discard then and return to waiting for a command
// look around again but send zero
return 0; //break from this function and return zero
}

//  now do the task: set up with tasks 0-4, this could be changed to ASCII table
// investigate difference between how functions handle the following: number_of_steps, whatSpeed, thisStep

switch(motorCommand)
{  
  case 0:
    {
    //  void Stepper::Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);  
  }
  case 1:
  {
    // void Stepper::setSpeed(long whatSpeed);    
  }
  case 2:
    {
    // void Stepper::step(int steps_to_move);    
  }
  case 3:
    {
    //  void Stepper::stepMotor(int thisStep);    
  }
  case 4:
    {
    // int Stepper::version(void);
  }
  
/*
  case 5:
  case 6:
  case 7:
  case 8: 
*/


// return '1' so that the function knows it has received a command
return 1;

}// END OF switch(motorCommand)  
  

} // END OF perform_function()
