/*
FUNCTION :    int perform_function(incomingByte)
DESCRIPTION: returns '1' for a command executed and '0' if nothing was executed
NOTES: this function needs to be able to read quite a large range of data, look at Stepper:Stepper(int number_of_steps .. 
*/


boolean perform_function(int var, char command){


// use LEDs to indicate the command was received
pinMode(13,OUTPUT);
pinMode(12, OUTPUT); 
pinMode(11, OUTPUT); 
pinMode(10, OUTPUT); 
pinMode(9, OUTPUT); 
boolean control = 0;


//  now do the task: set up with tasks 0-4, this could be changed to ASCII table
// investigate difference between how functions handle the following: number_of_steps, whatSpeed, thisStep

switch(command){  
  case 'A':     {
    //  void Stepper::Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);
 
debugging_flasher(13,500,var, command); 
    control = 1;
    break;
  }
  case 'B':   {
    // void Stepper::setSpeed(long whatSpeed);

    // flash LED on D11 for 2 seconds
debugging_flasher(12,500, var, command);          
    control = 1;
    break; 
  }
  case 'C':     {
    // void Stepper::step(int steps_to_move);
  
    // flash LED on D11 for 2 seconds
debugging_flasher(11,500, var, command); 
    control = 1;
    break;  
  }
  case 'D':     {
    //  void Stepper::stepMotor(int thisStep);      
debugging_flasher(10,500,var, command); 
control = 1;
break;
    }
  case 'E':     {
    // int Stepper::version(void);
debugging_flasher(9,500,var, command);
    control = 1; 
    break;
  }
  
  /*
  case 5:{}
  case 6:{}
  case 7:{}
  case 8:{} 
*/
  // default statement just in case!
  default:
    Serial.print(var);
    Serial.print(command);      
    control = 0;
  break;
  


}// END OF switch(motorCommand)  
  
// indicate if a command or handshake was received
return control;
} // END: perform_function()
