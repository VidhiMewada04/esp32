/*

  ##########    ##########     ##########             #########################################
  ##########    ##########     ##########             #########################################
  ###           ###    ###     ###                    #########################################
  ###           ##########     ###                                      ###
  ###  #####    ###  ###       ###                                    #######
  ###  #####    ###   ###      ###                                      ###
  ###    ###    ###   ###      ###                    #########################################
  ##########    ###    ###     ##########             #########################################
  ##########    ###     ###    ##########             #########################################

*/

#include "Auto.h"
#include <SPI.h>
#define p 100

void setup() {
  Serial.begin(115200);
  Serial.println("Mega restarted");
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
  pinModes();
  relaysOff();
  mpuSetup();
  tfMiniSetup();
  Serial.println("setup end");
}

ISR(SPI_STC_vect) {
  if (SPDR != 135) {
    button = SPDR;
  }
  //  Serial.print("Button - "); Serial.println(button);
}

void loop() {
  stopGrabberMotor();
  //  checkReedCount();
  mpu6050.update();
  b = mpu6050.getAngleZ();
  //while (1) {
  //  autoTask();    //  Grabber.Close();
  //  delay(1000);
  //  Grabber.Open();
  //  delay(1000);
  //  Serial.println(ultrasonic.read());
  Serial.println(readEncoder);
  //  Serial.println(encoder);
  //  Serial.println(b);
  //  Serial.print(limitClk);
  //  Serial.print(" - ");
  //  Serial.println(limitBase);
  //  Serial.print(tfmini1.getDistance());       // 34
  //  Serial.print(" - ");
  //  Serial.println(tfmini2.getDistance());     // 46
  //}

  switch (button)
  {
    case DISC:
      currentMillis = millis();
      resetFlag = 1;
      if (abs(currentMillis - resetMillis) > 500 && resetFlag == 1) {
        Serial.println("inside reset func");
        resetMillis = currentMillis;
        resetFlag = 0;
        resetFunc();
      }
      break;
    case PS:
      Serial.println("Reset");
      resetFunc();
      break;
    case START:
      autoTask();
      //      Serial.print(" auto ");
      break;
    case UP:
      forward(p);
      //      checkReedCount();
      break;
    case DOWN:
      backward(p);
      //      checkReedCount();
      break;
    case LEFT:
      left(p);
      //      checkReedCount();
      break;
    case RIGHT:
      right(p);
      //      checkReedCount();
      break;
    case TRIANGLE:
      Thrower_reed();
      //      throwerFlag = 1;
      break;
    case CROSS:
      Thrower.Close();
      //      throwerFlag = 0;
      break;
    case SQUARE:
      Grabber.Close();
      break;
    case CIRCLE:
      Grabber.Open();
      break;
    case UPRIGHT:
      bot.upRight(p);
      break;
    case UPLEFT:
      bot.upLeft(p);
      break;
    case DOWNRIGHT:
      bot.downRight(p);
      break;
    case DOWNLEFT:
      bot.downLeft(p);
      break;
    case CLOCKWISE:
      bot.clk(50);
      mpu6050.update();
      newAngle = mpu6050.getAngleZ();
      break;
    case ANTICLOCKWISE:
      bot.aclk(50);
      mpu6050.update();
      newAngle = mpu6050.getAngleZ();
      break;
    case JOYUP:
      stopGrabberMotor();
      GrabMotor.aclk(100);
      break;
    case JOYDOWN:
      stopGrabberMotor();
      GrabMotor.clk(100);
      break;
    case L3:
      Thrower.Free();
      GrabEnc.write(0);
      grabberClk(2400);
      delay(1000);
      Thrower.Close();
      delay(300);
      Thrower.Free();
      throwerFlag = 1;
      delay(1000);
      grabberClk(3200);
      Grabber.Open();
      delay(1000);
      grabberClk(3500);
      GrabMotor.brake();
      break;
    case R3:
      Grabber.Close();
      delay(200);
      grabberAclk(100);
      bot.forward(50, 50, 50, 50);
      delay(800);
      bot.brake(100);
      break;
    default:
      resetFlag = 0;
      bot.brake();
      GrabMotor.brake(0);
      break;
  }
}
