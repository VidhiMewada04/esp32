bool lastCommand = 0;

class Motor {
  private:
    uint8_t input_1, pwm_pin, input_2;
  public:
    Motor() {};
    Motor( uint8_t pwm_pin, uint8_t input_1, uint8_t input_2 = 100) {
      this->pwm_pin = pwm_pin;
      this->input_1 = input_1;
      this->input_2 = input_2;
      pinMode(pwm_pin, OUTPUT);
      pinMode(input_1, OUTPUT);
      pinMode(input_2, OUTPUT);
    }
    void aclk(uint8_t pwm) {
      analogWrite(pwm_pin, pwm);
      digitalWrite(input_1, LOW);
      digitalWrite(input_2, HIGH);
      lastCommand = 0;
    }
    void clk(uint8_t pwm) {
      analogWrite(pwm_pin, pwm);
      digitalWrite(input_1, HIGH);
      digitalWrite(input_2, LOW);
      lastCommand = 1;
    }
    void fre(uint8_t pwm) {
      analogWrite(pwm_pin, 0);
      digitalWrite(input_1, LOW);
      digitalWrite(input_2, LOW);
    }
    void brake(uint8_t pwm = 0) {
      analogWrite(pwm_pin, 0);
      digitalWrite(input_1, HIGH);
      digitalWrite(input_2, HIGH);
      //      if (lastCommand = 0) {
      //        aclk(pwm);
      //        delay(150);
      //      } else {
      //        clk(pwm);
      //        delay(150);
      //      }
    }
};

Motor motor1(8, 11);
Motor motor2(12, 7);
Motor motor3(6, 13);
Motor motor4(10, 9);

Motor GrabMotor(4, 28, 5);
//Motor GrabMotor(Grab_pwm, Grab_in1, Grab_in2);


// pneu_Slave --> mpu.h --> Func.h --> Config.h --> Bot.h --> Motor.h
//                                              --> Pneumatic.h
