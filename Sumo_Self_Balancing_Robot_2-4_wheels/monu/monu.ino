#include <Servo.h>

#include <PID_v1.h>
#include "I2Cdev.h"
#include "pins.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include <digitalIOPerformance.h>   //library for faster pin R/W
#include <SoftwareSerial.h>
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
      #include "Wire.h"
#endif
#define DEBUGING            //uncomment it to debug.It will decrease the processing speed.
MPU6050 mpu;
Servo myservo;

#define Rp 40
#define Rd 1.5
#define Ri 100

const int rxpin =3; // pin used to receive (not used in this version) 
const int txpin = 4; // pin used to send to LCD
int flag=0;

SoftwareSerial blue(rxpin,txpin );
//********************************************


#define LED_PIN 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)
bool blinkState = false;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
}
//********************************************
double referenceAngle=3,previousAngle=0;
double orireferenceAngle= referenceAngle;

double yinput,yout,ysetpoint=0;
double yoriginalSetpoint=ysetpoint;
PID pid(&currentAngle,&motorSpeedo,&referenceAngle,35,300,0,DIRECT);
PID rot(&yinput,&yout,&ysetpoint,Rp,Ri,Rd,DIRECT);    
int resetpin= 12;
void setup() {
  
  digitalWrite(resetpin,HIGH);
  delay(200);
   myservo.attach(7);
  #ifdef DEBUGING
  Serial.begin(9600);
  #endif
  imuinit();
  motorInit();
blue.begin(9600);
pid.SetMode(AUTOMATIC);                  //For info about these,see Arduino PID library
pid.SetOutputLimits(-255, 255);
pid.SetSampleTime(10);
rot.SetMode(AUTOMATIC);
rot.SetOutputLimits(-35, 35);
rot.SetSampleTime(10);
pinMode(resetpin,OUTPUT);
}

void loop() {
  if(blue.available()>0)
  {
    tunning=blue.read();// changing from automatic to manual vice versa
    if (tunning=='X')
        
        {
              for (pos = 0; pos <= 180; pos++) { // goes from 0 degrees to 180 degrees
               // in steps of 1 degree
               myservo.write(pos); 
               delay(10);// tell servo to go to position in variable 'pos'
                                      // waits 15ms for the servo to reach the position
             }
             delay(3000);
              while (1)
              {
              getvalues();
              readPIDTuningValues();
              npid();          //call pid
              Bt_control(); 
              //App control           
              }
              }
      else if(tunning=='Y')
              {
               
                   for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
                  
                   myservo.write(pos);              // tell servo to go to position in variable 'pos'
                    delay(15);                       // waits 15ms for the servo to reach the position
                 }
                    while(1){
                       mpu.setDMPEnabled(false);
                    manualmotor(); 
                    //manual device control
                  }
               }
  }
}




