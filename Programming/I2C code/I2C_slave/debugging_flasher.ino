void debugging_flasher( int pin, int time, int v, char c){ // time in milliseconds
 
     // flash LED on D11 for 2 seconds
    for( int i=0; i<10;i++){
      digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(time);              // wait for half a second
      digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
      delay(time);              // wait for half a second
      }
    Serial.print(v);
    Serial.print(c);      
}
