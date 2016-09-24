/*
FUNCTION :    void establishContact()
DESCRIPTION: establishing serial communication between two arduinos
NOTES: none

*/


//sends "A" on Tx line until it reads something > zero on the Rx line.
void establishContact(){
  
  
  //variables to control the handshake
  int read_serial=0;
 //control variables for safe exit
 //boolean ackTest = false;
 //boolean synAckTest = false;

//while(ackTest && synAckTest == false)
//{  
  while (Serial.available() <= 0){
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

} // END: "while(ackTest && synAckTest == false)"

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
}// END: void establishContact()
