#include "base.h"
#include "pneu.h"
#include <Encoder.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
float angle = 0;
float oldangle = 0;
float newangle = 0;
int p = 100;
int count = 0;
#define l1 A6
#define l2 A0
#define Reed A7
Encoder E(2, 3);
long oldE  = -999;
MPU6050 mpu(Wire);
void (*resetFunc) (void) = 0;

void setUP() { 
  pinMode(l1, INPUT_PULLUP);
  pinMode(l2, INPUT_PULLUP);
  pinMode(Reed, INPUT_PULLUP);
  Wire.begin();
  mpu.begin(); 
  mpu.calcGyroOffsets(true); }

void relayoff() {
  N1.fre();
  N2.fre(); }

void limitoff() {
  if(digitalRead(l1) == 0) {
    m.stp(0); 
    m.clk(50);
    delay(70); }    
  else if(digitalRead(l2) == 0) {
    m.stp(0); 
    m.aclk(50);
    delay(70); } }

void REED() {
    while(count < 2){
      if(digitalRead(Reed) == 0){
        count++; } 
      else{ 
        N1.fre(); } }
    N1.up(); 
    count = 0; }

void mpu6050() {
  mpu.update();
  angle = mpu.getAngleZ();
  if (angle != oldangle){
    oldangle = angle; }
//  Serial.println("/////////////////////////");
//  Serial.println(angle); }
//  Serial.println(oldangle);
//  Serial.println("/////////////////////////"); }
  }
  
void encoder() {
  long newE = E.read();   
  if (newE != oldE) {
    oldE = newE; } }
    
void mpuL1() {  //+
  mpu.update();
  angle = mpu.getAngleZ();
  m1.clk(p);
  m2.clk(p);    
  m3.aclk(p+50);
  m4.aclk(p+50); }
  
void mpuR1() {  //- 
  mpu.update();
  angle = mpu.getAngleZ();
  m1.clk(p+50);
  m2.clk(p+50);
  m3.aclk(p);
  m4.aclk(p); }

void mpuL2() {  //+
  mpu.update();
  angle = mpu.getAngleZ();
  m1.aclk(p);
  m2.aclk(p);    
  m3.clk(p+50);
  m4.clk(p+50); }
  
void mpuR2() {  //- 
  mpu.update();
  angle = mpu.getAngleZ();
  m1.aclk(p+50);
  m2.aclk(p+50); 
  m3.clk(p);
  m4.clk(p); }
    
void Forward() {
  mpu.update();
  if(-40 < oldangle && oldangle < -5) {
    mpuR1(); }
  if(-5 < oldangle && oldangle < 5) {
    bot.forward(); }
  if(5 < oldangle && oldangle < 40) {
    mpuL1();  }
  else {
    bot.stpp(); }}
//    Serial.print("angle:");
//    Serial.println(angle);
//    Serial.print("oldangle:");
//    Serial.println(oldangle); 
//    Serial.print("newangle:");
//    Serial.println(newangle); }

void Backward() {
  mpu.update();
  if(-40 < oldangle && oldangle < -5) {
    mpuR2(); }
  if(-5 < oldangle && oldangle < 5) {
    bot.backward(); }
  if(5 < oldangle && oldangle < 40) {
    mpuL2(); }
  else {
    bot.stpp(); } }
//    Serial.print("angle:");
//    Serial.println(angle);
//    Serial.print("oldangle:");
//    Serial.println(oldangle); 
//    Serial.print("newangle:");
//    Serial.println(newangle); }

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
#define UPRIGHT 20
#define UPLEFT 21
#define DOWNLEFT 22
#define DOWNRIGHT 23
#define CLOCKWISE 24
#define ANTICLOCKWISE 25
#define JOYUP 26
#define JOYRIGHT 27
#define JOYDOWN 28
#define JOYLEFT 29
#define DISC 255
