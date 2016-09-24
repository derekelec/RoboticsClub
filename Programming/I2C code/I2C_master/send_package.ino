
void send_package(int outVar, char outChar){

  Wire.beginTransmission(9);   // transmit to device #9
  Wire.write(outVar);               // send value
  Wire.write(outChar); // sends command selection    
  Wire.endTransmission();      // stop transmitting
// flash LEDs
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
    
    
}//END: void send_package()
