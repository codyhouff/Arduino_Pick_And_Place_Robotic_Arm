

#include "ATD.h"
#include "Base.h"
//#include "MergeSort.h"

using namespace std;

// Function Declarations
void setMotorPower(int percent, bool forward);      //Done
void selectMotor(int motor);                        //Done
void armHome();                                     //Done
void baseHome();                                    //Done
void goToNextBase();                                //Done
void goToPrevBase();                                //Done
double getDist();                                   //Done
void raiseArm();                                    //Done
int getGrey();                                      //Done
int grabBall();                                     //Done
void grip(bool);                                    //Done
void releaseBall();                                 //DOne

// Global Variable Declaration

const int armMotor = 2;
const int baseMotor = 1;
const int gripMotor = 3;

volatile int motorPOSA[4] = {0,0,0,0};
volatile int motorPOSB[4] = {0,0,0,0};
bool forwardDir[4] = {true,true,true,true};
bool verifyForwardDir = false;
int baseline = 0;
int motorNum = 1;

ATD* lightSens = new ATD();
ATD* ultraSens = new ATD();

//*************************************************************************************************

//*************************************************************************************************

void setup() {
  // Initialization

  // Initialize Serial Monitor
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Program Start");
  
  //PWM
  DDRB = 0x20;      
  TCCR1A = 0x83;
  TCCR1B = 0x09;

  //Motor Controller
  Serial.print("PINA AFTER DIR: ");
  Serial.println(PINA,HEX);
  DDRA = 0x0f;  
  PORTA = 0x00;
  Serial.print("PINA AFTER DIR: ");
    Serial.println(PINA,HEX);
  //DDRE |= 0x30;

  //Light Sensor
  lightSens->setPin(0);
  lightSens->setJustified(false);
  lightSens->setPrescale(7);
  lightSens->setRef(1);

  //Ultrasonic Sensor
  ultraSens->setPin(1);
  ultraSens->setJustified(false);
  ultraSens->setPrescale(7);
  ultraSens->setRef(1);
  

  

  // Init pos and baselines
  baseHome();
  armHome();
  grip(false);
  int sum = 0;
  for(int i = 0; i < 50; i++){
    sum += lightSens->getData();
  }
  baseline = sum / 50;
  
  //Main single run program trial
  
}

void loop() {
  goToNextBase();
  grabBall();
  baseHome();
  releaseBall();
  goToNextBase();
  goToNextBase();
  grabBall();
  goToPrevBase();
  releaseBall();
  while(true);
  baseHome();
  grabBall();
  goToNextBase();
  goToNextBase();
  releaseBall();
  baseHome();
Serial.println(getDist());
}

//**************************************************************************************************

//**************************************************************************************************

// Function Definitions
void setMotorPower(int percent, bool forward){
  //Correct input parameters
  delay(200);
  if(percent < 0) percent = 0;
  else if(percent > 100) percent = 100;

  OCR1A = percent * 255 / 25;   //Set motor power level
                                        //Motor driver is active low
                                        //so the waveform is inverted
  //Serial.print("OCRA1: ");
  //Serial.println(OCR1A, HEX);

  //Set direction
  if(forward){
    Serial.print("PINA BEFORE DIR: ");
    Serial.println(PINA,HEX);
    PORTA &= 0xf3;    //Set pins 24 and 25 to 0
    PORTA |= 0x04;    //Set pin 24 to 1
    Serial.print("PINA AFTER DIR: ");
    Serial.println(PINA,HEX);
  }
  else{
    Serial.print("PINA BEFORE DIR: ");
    Serial.println(PINA,HEX);
    PORTA &= 0xf3;    //Set pins 24 and 25 to 0
    PORTA |=0x08;     //Set pin 25 to 1
    Serial.print("PINA AFTER DIR: ");
    Serial.println(PINA,HEX);
  }  
}

void selectMotor(int motor){    //motor selection is 1-based
  delay(100);
  //Correct input parameters
  char temp;
  if(motor < 1) motor = 1;
  else if(motor > 4) motor = 4;

  motorNum = motor;

  //Select motor
  Serial.println(motor, DEC);
  Serial.println(PORTA, HEX);
  PORTA &= 0xfc;
  Serial.println(PORTA, HEX);
  PORTA |= motor - 1;
  Serial.println(PORTA, HEX);
}

void goToNextBase(){
  int threshold = 12;
  int power = 85;
  
  selectMotor(baseMotor);
  setMotorPower(power, true);
  
  if(getDist() < threshold){
    while(getDist() < threshold);  
  }

  delay(1000);

  while(getDist() > threshold);

  delay(80);

  setMotorPower(0, true);

  delay(250);
}

void goToPrevBase(){
  int threshold = 12;
  int power = 85;
  
  selectMotor(baseMotor);
  setMotorPower(power, false);
  
  if(getDist() < threshold){
    while(getDist() < threshold);  
  }

  delay(1000);

  while(getDist() > threshold);

  delay(80);

  setMotorPower(0,true);

  delay(250);
}


double getDist(){
  double sum = 0;
  for (int i = 0; i < 15; i++){ 
    sum += ultraSens->getData();
  }
  sum = sum / 15;
  double dist = 8490 * pow(sum,-1.09);
  return dist;
}


void armHome(){
  selectMotor(armMotor);                //Select arm motor
  setMotorPower(80,false);    //Start motor to move
  bool hitBase = false;
  while(!hitBase){
    Serial.print("Waiting arm for Button: PINA = ");
    Serial.print(PINA, HEX);
    Serial.print("\nFound: ");
    Serial.println(PINA & 0x10,HEX);
    if((PINA & 0x20) == 0x20){
      hitBase =true;
    }
    }        //Wait until the home button is pressed 1111 1000
  setMotorPower(55,true);
  while((PINA & 0x20) == 0x20);
  setMotorPower(0,true);
}

void baseHome(){
  selectMotor(baseMotor);                //Select base motor
  if(PINA & 0x10 == 0x10){
    setMotorPower(100,true);
    delay(15);
  }
  setMotorPower(100, false);  //Start motor to move
  bool hitBase = false;
  while(!hitBase){
    Serial.print("Waiting base for Button: PINA = ");
    Serial.print(PINA, HEX);
    Serial.print("\nFound: ");
    Serial.println(PINA & 0x10,HEX);
    if((PINA & 0x10) == 0x10){
      hitBase =true;
    }
    }        //Wait until the home button is pressed 1111 1000
  setMotorPower(75,true);
  while((PINA & 0x10));
  setMotorPower(0,true);
}

void raiseArm(){
  selectMotor(armMotor);
  setMotorPower(80, true);
  delay(3);
  setMotorPower(0,true);
}

int getGrey(){
  int sum = 0;
  for(int i = 0; i < 20; i++){
    sum += lightSens->getData(); 
  }
  return sum / 20 - baseline;
}

int grabBall(){
  armHome();
  grip(true);
  raiseArm();
  return getGrey();
}

void grip(bool grab){
  if(grab){
    selectMotor(gripMotor);
    setMotorPower(70,true);
    delay(1000);
  }
  else{
    selectMotor(gripMotor);
    setMotorPower(70,false);
    delay(500);
  }
}

void releaseBall(){
  armHome();
  grip(false);
  raiseArm();
}
