/*
FUNCTION :    int perform_function(incomingByte)
DESCRIPTION: returns zero for ACK, and '1' for a command executed
NOTES: this function needs to be able to read quite a large range of data, look at Stepper:Stepper(int number_of_steps .. 
*/


int perform_function(int var){


// use LEDs to indicate the command was received
pinMode(12, OUTPUT); //ACK testing
pinMode(11, OUTPUT); // ___ testing
pinMode(10, OUTPUT); // ___ testing
pinMode(9, OUTPUT); // ___ testing

// test so that "ACK" is not what is received
int motorCommand=var;
//  set to "zero" if ACK is received, and return it; otherwise, keep at "one" and return it  
int control = 5;

// make sure that "break;" stops the entire fuction
if(motorCommand==ACK){
  // flash LED on D12 for 2 seconds
  for( int i=0; i<10;i++){
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for half a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for half a second
  } 
control = 0; // used to return '0' which means that ACK was received
motorCommand = 10; // set to something outside the case statement range
}

if(motorCommand==SYN_ACK){
    // flash LED on D12 for 2 seconds
  for( int i=0; i<10;i++){
  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for half a second
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for half a second
  } 
control = 0; // used to return '0' which means that ACK was received
motorCommand = 10; // set to something outside the case statement range
}

if(motorCommand==COMMAND){
      send_command(1);
  // flash LED on D12 for 2 seconds
  for( int i=0; i<10;i++){
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for half a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for half a second
  } 
control = 0; // used to return '0' which means that ACK was received
motorCommand = 10; // set to something outside the case statement range
}
  

//  now do the task: set up with tasks 0-4, this could be changed to ASCII table
// investigate difference between how functions handle the following: number_of_steps, whatSpeed, thisStep

switch(motorCommand)
{  
  case 0:
    {
    //  void Stepper::Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);
    
    // flash LED on D11 for 2 seconds
    for( int i=0; i<10;i++){
      digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for half a second
      digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
      delay(100);              // wait for half a second
      }     
    
    // set "control" so that the function returns '1', which means that a command was executed and not an ACK received
    control = 1;
    break;
  }
  case 1:
  {
    // void Stepper::setSpeed(long whatSpeed);

    // flash LED on D11 for 2 seconds
    for( int i=0; i<10;i++){
      digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for half a second
      digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
      delay(100);              // wait for half a second
      } 

    // set "control" so that the function returns '1', which means that a command was executed and not an ACK received      
    control = 1;
    break; 
  }
  case 2:
    {
    // void Stepper::step(int steps_to_move);
  
    // flash LED on D11 for 2 seconds
    for( int i=0; i<10;i++){
      digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for half a second
      digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
      delay(100);              // wait for half a second
      } 

    // set "control" so that the function returns '1', which means that a command was executed and not an ACK received    
    control = 1;
    break;  
  }
  case 3:
    {
    //  void Stepper::stepMotor(int thisStep);   
   
    // set "control" so that the function returns '1', which means that a command was executed and not an ACK received    
    control = 1;
    break;
  }
  case 4:
    {
    // int Stepper::version(void);
    
    // set "control" so that the function returns '1', which means that a command was executed and not an ACK received    
    control = 1;
    break;
  }
  // default statement just in case!
  default:
  break;
  
/*
  case 5:
  case 6:
  case 7:
  case 8: 
*/


}// END OF switch(motorCommand)  
  
// indicate if a command or handshake was received
return control;
} // END: perform_function()
