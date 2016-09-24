/*
- testing script 
- LED testing script: each command lights a different LED <D9,D10,D11,D12>


*/

// define for : establishContact()
#define ACK 'A' // saved as 65 (in decimal) 
#define SYN_ACK 'B' // saved as 66 (decimal)
#define COMMAND 'Z' 

// function declarations
void establishContact(void);
int perform_function(int var);
void send_command(int var); //, int var1, int var2, int var3);

// setup() will only stop once the establish contact function gets something > 0 is read on the serial port
void setup() {
  Serial.begin(9600);
//  Serial.setTimeout();// defaults to delaying 1s
// does not stop sending "A" until Rx reads something
  establishContact();
}// END: void setup()

void loop() {
  // now your communication has been set, and the PI has access to the motor functions
  // run timer and have it track the total on-time, have this as a time out function, then go back to low-power mode  
  
  // wait for commands
  int incomingByte=0;
  
  if( Serial.available() >0 ) {
    incomingByte = Serial.read();
    int test = perform_function(incomingByte); 
  }//END: if( Serial.available() >0 )
  
}// END: void loop()
