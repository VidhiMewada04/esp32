#include "Motor.h"
class Bot
{
  private:
    Motor m1, m2, m3, m4;

  public:
    Bot(Motor m1, Motor m2, Motor m3, Motor m4) {
      this->m1 = m1;
      this->m2 = m2;
      this->m3 = m3;
      this->m4 = m4;
    }
    void forward(byte pwm1, byte pwm2, byte pwm3, byte pwm4) {
      m1.clk(pwm1);
      m2.clk(pwm2);
      m3.aclk(pwm3);
      m4.aclk(pwm4);
    }
    void backward(byte pwm1, byte pwm2, byte pwm3, byte pwm4) {
      m1.aclk(pwm1);
      m2.aclk(pwm2);
      m3.clk(pwm3);
      m4.clk(pwm4);
    }
    void left(byte pwm1, byte pwm2, byte pwm3, byte pwm4) {
      m1.clk(pwm1);
      m2.aclk(pwm2);
      m3.aclk(pwm3);
      m4.clk(pwm4);
    }
    void right(byte pwm1, byte pwm2, byte pwm3, byte pwm4) {
      m1.aclk(pwm1);
      m2.clk(pwm2);
      m3.clk(pwm3);
      m4.aclk(pwm4);
    }
    void hold(byte pwm) {
      m1.clk(pwm);
      m2.aclk(pwm);
      m3.clk(pwm);
      m4.aclk(pwm);
    }
    void upLeft(byte pwm) {
      m1.clk(pwm);
      m2.brake(pwm);
      m3.aclk(pwm);
      m4.brake(pwm);
    }
    void upRight(byte pwm) {
      m1.brake(pwm);
      m2.clk(pwm);
      m3.brake(pwm);
      m4.aclk(pwm);
    }
    void downLeft(byte pwm) {
      m1.brake();
      m2.aclk(pwm);
      m3.brake();
      m4.clk(pwm);
    }
    void downRight(byte pwm) {
      m1.aclk(pwm);
      m2.brake(pwm);
      m3.clk(pwm);
      m4.brake(pwm);
    }
    void clk(byte pwm1) {
      m1.aclk(pwm1);
      m2.aclk(pwm1);
      m3.aclk(pwm1);
      m4.aclk(pwm1);
    }
    void aclk(byte pwm1) {
      m1.clk(pwm1);
      m2.clk(pwm1);
      m3.clk(pwm1);
      m4.clk(pwm1);
    }
    //    void brake(byte pwm = 80) {
    //      m1.aclk(pwm-20);
    //      m2.clk(pwm);
    //      m3.aclk(pwm-10);
    //      m4.clk(pwm);
    //    }
    void brake(byte pwm = 0) {
      m1.brake();
      m2.brake();
      m3.brake();
      m4.brake();
    }
    void testMotors(byte pwm) {
      m1.clk(pwm);
      delay(1500);
      m1.aclk(pwm);
      delay(1500);
      m1.brake();
      m2.clk(pwm);
      delay(1500);
      m2.aclk(pwm);
      delay(1500);
      m2.brake();
      m3.clk(pwm);
      delay(1500);
      m3.aclk(pwm);
      delay(1500);
      m3.brake();
      m4.clk(pwm);
      delay(1500);
      m4.aclk(pwm);
      delay(1500);
      m4.brake();
    }
};

Bot bot(motor1, motor2, motor3, motor4);
