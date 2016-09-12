// MultiStepper.pde
// -*- mode: C++ -*-
//
// Shows how to multiple simultaneous steppers
// Runs one stepper forwards and backwards, accelerating and decelerating
// at the limits. Runs other steppers at the same time
//
// Copyright (C) 2009 Mike McCauley
// $Id: MultiStepper.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>
#include <Wire.h>

void receiveEvent(int);
boolean perform_function(int,char);
void changeMicrostepping(int);


int step1 = 2;
int dir1 = 3;
int enable1 = 13;
int ms1 = 12;
int ms2 = 11;
int ms3 = 10;
int step2 = 4;
int dir2 = 5;
int enable2 = 6;
int maxspeed = 2000;
int maxaccel = 200;
bool currentlyRunning = true;
int currentMicrostep = 0;
const int microstepping[] = {0,0,0,1,0,0,0,1,0,1,1,0,1,1,1};

// Define some steppers and the pins the will use
//AccelStepper stepper1; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
//AccelStepper stepper2(AccelStepper::FULL4WIRE, 6, 7, 8, 9);
AccelStepper stepper1(AccelStepper::FULL2WIRE,step1 , dir1);
AccelStepper stepper2(AccelStepper::FULL2WIRE, step2, dir2);





void setup()
{  
    static int microstepping[] = {0,0,0,1,0,0,0,1,0,1,1,0,1,1,1};
    //set up microstepping to half stepping
    pinMode(ms1,OUTPUT);
    pinMode(ms2,OUTPUT);
    pinMode(ms3,OUTPUT);
    changeMicrostepping(currentMicrostep);
   
    
    stepper1.setEnablePin(enable1);
    stepper1.setMaxSpeed(maxspeed);
    stepper1.setAcceleration(maxaccel);
    //stepper1.moveTo(10000);
    stepper1.setPinsInverted(true,false,true);
    stepper1.enableOutputs();
    stepper1.setSpeed(0.1);

    stepper2.setEnablePin(enable2);
    stepper2.setMaxSpeed(maxspeed);
    stepper2.setAcceleration(maxaccel);
    //stepper2.moveTo(10000);
    stepper2.setPinsInverted(false,false,true);
    stepper2.enableOutputs();
    stepper2.setSpeed(0.1);

    // Start the I2C Bus as Slave on address 9
    Wire.begin(9); 
    // Attach a function to trigger when something is received.
    Wire.onReceive(receiveEvent);
    //Serial.begin(9600);
    //Serial.print("completed setup\n");

 
}

void loop()
{
    // Change direction at the limits
    //if (stepper1.distanceToGo() == 0)
	  //  stepper1.moveTo(-stepper1.currentPosition());
    stepper1.runSpeed();
    stepper2.runSpeed();
}

void receiveEvent(int bytes) {

  int inValue;
  char inChar;
  
  // receive byte as an integer
  inValue = Wire.read();
  inChar = Wire.read();
  //boolean test = perform_function( int inVar, char inByte);

  switch(inChar){
    case 'A':
      stepper1.setSpeed(map(inValue,0,255,0.1,maxspeed));
      break;
    case 'B':
      stepper2.setSpeed(map(inValue,0,255,0.1,maxspeed));
      break;
    case 'C':
      stepper1.setSpeed(map(inValue,0,255,-0.1,-maxspeed));
      break;
    case 'D':
      stepper2.setSpeed(map(inValue,0,255,-0.1,-maxspeed));
      break;
    case 'S':
      currentlyRunning = !currentlyRunning;
      if(currentlyRunning){
        stepper1.enableOutputs();
        stepper2.enableOutputs();
      }
      else{
        stepper1.disableOutputs();
        stepper2.disableOutputs();
      }
      break;
    case 'M':
      currentMicrostep++;
      currentMicrostep = currentMicrostep % 3;
      changeMicrostepping(currentMicrostep);
    default:
      break;
  }
  
  //Serial.print("   success: ");
  //Serial.println(test);// now it is time to test functionality
}
void changeMicrostepping(int i){
    digitalWrite(ms1,microstepping[i*3]);
    digitalWrite(ms2,microstepping[i*3+1]);
    digitalWrite(ms3,microstepping[i*3+2]);
}

