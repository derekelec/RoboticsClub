


int speedVar = 0;
int testPin = 5; // LED pin so that user can see it is working

// LEDs on ports D9-D12 for testing purposes
int red = 12;
int yellow = 11;
int green = 10;
int blue = 9


int scaler=0;
int frequency=0;

boolean control = true;

void setup() {
  Serial.begin(9600);
}

void loop() {

Serial.print("Enter zero scalar: i.e 1=Hz, 3=KHz, 6=MHz:");
int scalar = 0;
while(scalar==0){
  scalar = SerialReader('0','9');
}

// this code cannot accept a string!  So make it able to detect numbers from 1-999!
Serial.print("Enter frequency from 1 - 999:");
int frequency = 0;
while(frequency==0){
 frequency = SerialReader('0','999'); 
}

Serial.print("Frquency obtained:  ");
int end_frequency = frequency*pow(10,scalar);
Serial.println(end_frequency);

 // now execute something cool
}

int SerialReader(char bound1, char bound2){   
  
  if(Serial.available() > 0) {    // is a character available?
    char rx_byte = 0;
    rx_byte = Serial.read();       // get the character

    // only register if something either than newline was entered  
    // check if a number was received
        if ((rx_byte >= bound1) && (rx_byte <= bound2)) {
        Serial.println(rx_byte);
        return rx_byte;
     }
    else {
      return 0;       

    }
  } // end: if (Serial.available() > 0)
  
}
