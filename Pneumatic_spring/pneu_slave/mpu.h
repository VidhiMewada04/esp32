#include "Func.h"
byte plus = 10;
byte offset = 30;
byte pwm = 100;
//int pmap1 = 0;
//int pmap2 = 0;
int pmap1 = map(pwm, -3, -40, 100, 150);
int pmap2 = map(pwm, 3, 40, 100, 150);
//map(pwm,-3,3,/

void forwardmap(byte pwm) {
  mpu6050.update();
  b =  mpu6050.getAngleZ();
  if (b - newAngle < 3 && b - newAngle > -3) {
    //    Serial.println(b - newAngle);
    bot.forward(pwm, pwm + plus, pwm, pwm);
  }
  if (b - newAngle > 3) { // shift right
    //    Serial.println(b - newAngle);
    bot.forward(pwm, pwm + plus, pmap2, pmap2);
  }
  if (b - newAngle < -3) {  //shift left
    //    Serial.println(b - newAngle);
    bot.forward(pmap1, pmap1 + plus, pwm, pwm);
  }
}

void forward(byte pwm) {
  mpu6050.update();
  b =  mpu6050.getAngleZ();
  if (b - newAngle < 3 && b - newAngle > -3) {
    //    Serial.println(b - newAngle);
    bot.forward(pwm, pwm, pwm, pwm+plus);
  }
  if (b - newAngle > 3) { // shift right
    //    Serial.println(b - newAngle);
    bot.forward(pwm, pwm, pwm + offset, pwm + offset+plus);
  }
  if (b - newAngle < -3) {  //shift left
    //    Serial.println(b - newAngle);
    bot.forward(pwm + offset, pwm + offset, pwm, pwm+plus);
  }
}

void backward(byte pwm) {
  mpu6050.update();
  b = mpu6050.getAngleZ();
  if (b - newAngle < 3 && b - newAngle > -3) {
    //    Serial.println(b - newAngle);
    bot.backward(pwm, pwm, pwm, pwm+plus);
  }
  if (b - newAngle > 3) {
    //    Serial.println(b - newAngle);
    bot.backward(pwm + offset, pwm + offset, pwm, pwm+plus);
  }
  if (b - newAngle < -3) {
    //    Serial.println(b - newAngle);
    bot.backward(pwm, pwm, pwm + offset, pwm + offset+plus);
  }
}

void left(byte pwm) {
  mpu6050.update();
  b = mpu6050.getAngleZ();
  if (b - newAngle < 3 && b - newAngle > -3) {
    bot.left(pwm, pwm, pwm, pwm+plus);
  }
  else if (b - newAngle > 3) {
    bot.left(pwm, pwm + offset, pwm + offset, pwm+plus);
  }
  else if (b - newAngle < -3) {
    bot.left(pwm + offset, pwm, pwm, pwm + offset+plus);
  }
}


void right(byte pwm) {
  mpu6050.update();
  b = mpu6050.getAngleZ();
  if (b - newAngle < 3 && b - newAngle > -3) {
    bot.right(pwm, pwm, pwm, pwm+plus);
  }
  else if (b - newAngle > 3) {
    bot.right(pwm + offset, pwm, pwm, pwm + offset+plus);
  }
  else if (b - newAngle < -3 ) {
    bot.right(pwm, pwm + offset, pwm + offset, pwm+plus);
  }
}

void back(byte pwm) {
  while (limitBase == 1 && tfmini2.getDistance() >= 55 && tfmini1.getDistance() < 45) {
    if (tfmini1.getDistance() <= 30) {
      bot.backward(pwm, pwm, pwm, pwm + plus);
    }
    else if (tfmini1.getDistance() > 45) {
      bot.backward(pwm + 5, pwm + 5, pwm, pwm + plus);
    }
    else {
      bot.brake();
    }
  }
}
