/*
- test script to send serial communication from one arduino to another
- this script establishes contact with the arduino via Tx/Rx pins, then sends out commands


*/

void send_command(int var, int var1, int var2, int var3){
  // should send information about how long the data transfer is for security or something fantastic like that
  
  Serial.println(var);
  Serial.println(var1);
  Serial.println(var2);
  Serial.println(var3);
  
  
  
}// END: send_command()
