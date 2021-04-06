#include "mpu.h"
#define pwm 40
float angle = 0;
bool stopManual = 1;
byte v = 0;

void autoTask() {

  //  while(encoder < 3500) {
  //    left(50);
  //  }
  //  bot.brake();
  //  while (limitBase == 1 && tfmini1.getDistance() <= 100) {
  //    left(pwm);
  //  }
  //  bot.brake();
  //  delay(500);
  //  while (limitBase == 0) {
  //    //    bot.right(pwm, pwm, pwm, pwm);
  //    bot.brake();
  //    delay(500);
  //    backward(pwm);
  //  }

  //  bot.brake();
  //  delay(500);
  //  //  back(pwm);
  //  while (limitBase == 0 || tfmini2.getDistance() >= 50 ) { //&& tfmini1.getDistance() <= 30) {
  //    bot.downLeft(100);
  //    //    backward(pwm);/
  //    v = 1;
  //  }
  //  bot.brake();
  //  delay(500);

  //   if(limitBase == 0)
  //   {
  //     bot.brake();
  //   }
  //   while(tfmini2.getDistance() >= 50)
  //   {
  //     bot.downLeft(100);
  //   }

  //  while (limitBase == 1 && v == 1 && tfmini2.getDistance() >= 50) {
  //    bot.downLeft(100);
  //  }

  //  while ((tfmini2.getDistance() == 30 || tfmini2.getDistance() < 70) && tfmini1.getDistance() > 100 ) { //&& stopManual == 1) {
  //    if (button == PS) {
  //      bot.brake();
  //      //      stopManual = 0;
  //      break;
  //    }
  //    forward(50);
  //  }
  //  bot.brake();
  //  delay(500);
  //
  //  while (tfmini2.getDistance() > 60 && tfmini1.getDistance() > 45 ) { //&& stopManual == 1) {
  //    if (button == PS) {
  //      bot.brake();
  //      //      stopManual = 0;
  //      break;
  //    }
  //    bot.downLeft(50);
  //  }
  //  bot.brake();
  //  delay(500);

  //  while (tfmini1.getDistance() > 50 && tfmini2.getDistance() > 65 ) { //&& stopManual == 1) {
  //    if (button == PS) {
  //      bot.brake();
  //      //      stopManual = 0;
  //      break;
  //    }
  //    left(50);
  //  }
  //  bot.brake();
  //  delay(500);
  //
  //  while (tfmini2.getDistance() > 70 && tfmini1.getDistance() < 45 ) { //&& stopManual == 1) {
  //    if (button == PS) {
  //      bot.brake();
  //      stopManual = 0;
  //      break;
  //    }
  //    backward(50);
  //    angle = mpu6050.getAngleZ();
  //    Serial.print("angle : ");  Serial.println(angle);
  //  };
  //  bot.brake();
  //  bot.backward(50, 50, 50, 50);
  //  delay(150);
  //  bot.brake();
  //  delay(500);

  Grabber.Close();

  while (readEncoder < 200) {        //    grabberClk(200);
    GrabMotor.aclk(50);
  }
  GrabMotor.brake();
  delay(100);
  while (tfmini2.getDistance() < 75) {
    forward(50);
    angle = mpu6050.getAngleZ();
  }
  bot.brake(50);
  delay(500);
  while (readEncoder < 3499 && tfmini1.getDistance() < 50 && tfmini2.getDistance() < 100) {
    mpu6050.update();
    b = mpu6050.getAngleZ();
    while (readEncoder < 2400) {     //    grabberClk(2400);
      GrabMotor.aclk(50);
    }
    GrabMotor.brake();
    delay(500);
    Thrower.Close();
    throwerFlag = 0;
    delay(500);
    while (readEncoder < 3200) {     //    grabberClk(3200);
      GrabMotor.aclk(50);
    }
    GrabMotor.brake();
    delay(500);
    Grabber.Open();
    delay(500);
    while (readEncoder < 3500) {     //    grabberClk(3500);
      GrabMotor.aclk(50);
    }
    GrabMotor.brake();
    delay(500);
    angle = mpu6050.getAngleZ();
  }
//  bot.brake();
//  delay(500);

  while (b > -28 && readEncoder > 3300 && tfmini2.getDistance() < 150) {
    mpu6050.update();
    b = mpu6050.getAngleZ();
    bot.clk(50);
  }
  Thrower_reed();
  throwerFlag = 1;
  bot.brake(50);
  delay(5000);
  while (1);


}
