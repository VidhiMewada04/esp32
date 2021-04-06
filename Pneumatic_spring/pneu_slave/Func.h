#include "Bot.h"
#include "Pneumatic.h"
#include "TFMini.h"
#include <Encoder.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Ultrasonic.h>

#define limitClkPin A6
#define limitBasePin A2
#define reedPin A7
Encoder GrabEnc(3, 2);
Encoder Enc(18, 19);
Ultrasonic ultrasonic(38, 36);
MPU6050 mpu6050(Wire);
TFMini tfmini1;
TFMini tfmini2;

#define limitClk digitalRead(limitClkPin)
#define limitBase digitalRead(limitBasePin)
#define reedSwitch digitalRead(reedPin)
#define readEncoder GrabEnc.read()
#define encoder Enc.read()

byte reedCount = 0;
volatile byte button = 0;
float b = 0 ;
bool throwerFlag = 0;
float newAngle = 0;
bool resetFlag = 0;

unsigned long resetMillis = 0;
unsigned long currentMillis = 0;

//void checkReedCount() {
//  //  Serial.print("Reed Count = ");
//  //  Serial.println(reedCount);
//  //  Serial.print("Reed Status = ");
//  //  Serial.println(reedSwitch);
//  if (throwerFlag == 1) {
//    if (reedSwitch == 0) {
//      reedCount++;
//    }
//    if (reedCount > 2) {
//      Thrower.Open();
//      reedCount = 0 ;
//      throwerFlag = 0;
//    }
//  }
//}

void Thrower_reed() {
  while (reedCount < 2) {
    if (reedSwitch == 0) {
      reedCount++;
    } else {
      Thrower.Free();
    }
  }
  Thrower.Open();
  reedCount = 0;
}

void pinModes() {
  //  pinMode(GrabP1, OUTPUT);
  //  pinMode(GrabP2, OUTPUT);
  //  pinMode(ThrowP1, OUTPUT);
  //  pinMode(ThrowP2, OUTPUT);
  pinMode(reedPin, INPUT_PULLUP);
  pinMode(limitClkPin, INPUT_PULLUP);
  pinMode(limitBasePin, INPUT_PULLUP);
  pinMode(MISO, OUTPUT);
}

void relaysOff() {
  Thrower.Free();
  Grabber.Free();
  //  digitalWrite(GrabP1, HIGH);
  //  digitalWrite(GrabP2, HIGH);
  //  digitalWrite(ThrowP1, HIGH);
  //  digitalWrite(ThrowP2, HIGH);
}

void mpuSetup() {
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void tfMiniSetup() {
  Serial.println ("Tf mini 1 Initializing...");
  Serial2.begin(TFMINI_BAUDRATE);
  tfmini1.begin(&Serial3);
  Serial.println ("Tf mini 2 Initializing...");
  Serial3.begin(TFMINI_BAUDRATE);
  tfmini2.begin(&Serial2);
}

void grabberAclk(int pulses) {
  while (readEncoder < pulses) {
    GrabMotor.aclk(50);
    //    Serial.println(GrabEnc.read());
  }
  GrabMotor.brake();
}

void grabberClk(int pulses) {
  while (readEncoder > -pulses) {
    GrabMotor.clk(50);
    //    Serial.println(GrabEnc.read());
  }
  GrabMotor.brake();
}

void stopGrabberMotor() {
  if (limitClk == LOW ) {
    GrabMotor.aclk(100);
    delay(50);
    GrabMotor.brake();
    //      grabberClk(25);
    //      GrabEnc.write(0);
  } 
}

void (*resetFunc)(void) = 0;

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
#define L1 5
#define L2 6
#define R1 7
#define R2 8
#define TRIANGLE 9
#define CIRCLE 10
#define CROSS 11
#define SQUARE 17
#define L3 15
#define R3 16
#define PS 12
#define START 13
#define SELECT 14
//////////////////////////
#define DISC 255
#define UPRIGHT 20
#define UPLEFT 21
#define DOWNLEFT 22
#define DOWNRIGHT 23
#define CLOCKWISE 25
#define ANTICLOCKWISE 24
#define JOYUP 26
#define JOYRIGHT 27
#define JOYDOWN 28
#define JOYLEFT 29
#define AUTOMATIC 99
#define MANUAL 100
