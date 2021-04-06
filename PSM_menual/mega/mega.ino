/*

  ##########    ##########     ##########
  ##########    ##########     ##########
  ###           ###    ###     ###
  ###           ##########     ###
  ###  #####    ###  ###       ###
  ###  #####    ###   ###      ###
  ###    ###    ###   ###      ###
  ##########    ###    ###     ##########
  ##########    ###     ###    ##########

*/

#include <SPI.h>
#include "func.h"
byte c;
unsigned long millisC = 0;
unsigned long millisR = 0;

void setup()
{
  Serial.begin (115200);
  Serial.println("setup started");
  setUP();
  relayoff();
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
  Serial.println("setup end");
}

ISR(SPI_STC_vect) {
  c = SPDR;
  millisC = millisR;
  Serial.println(c);
}

void loop()
{
  Serial.println("loop started");
  millisC = millis();
  if (abs(millisC - millisR) > 1000) {
    resetFunc();
  }

  mpu.update();
  angle = mpu.getAngleZ();
  if (oldangle != angle) {
    oldangle = angle;
  }
  //  Serial.print("angle:");
  //  Serial.println(angle);
  //  Serial.print("oldangle:");
  //  Serial.println(oldangle);
  limitoff();
  encoder();
  mpu6050();

  if (c == UP) {
    REED();
  }
  else if (c == DOWN) {
    N1.down();
    delay(10);
  }
  else if (c == LEFT) {
    N2.up();
  }
  else if (c == RIGHT) {
    N2.down();
  }
  else if (c == TRIANGLE) {
    m.clk(50);
  }
  else if (c == CROSS) {
    m.aclk(50);
  }

  else if (c == JOYUP) {
    oldangle = angle - newangle;
    Forward();
  }
  Serial.println("forward");
}
else if (c == JOYDOWN) {
  oldangle = angle - newangle;
  Backward();
}
else if (c == JOYLEFT) {
  bot.left();
}
else if (c == JOYRIGHT) {
  bot.right();
}
else if (c == UPLEFT) {
  bot.upleft();
}
else if (c == UPRIGHT) {
  bot.upright();
}
else if (c == DOWNLEFT) {
  bot.downleft();
}
else if (c == DOWNRIGHT) {
  bot.downright();
}

else if (c == CLOCKWISE) {
  newangle = oldangle;
  bot.clockwise();
  oldangle = oldangle - angle;
}
else if (c == ANTICLOCKWISE) {
  newangle = oldangle;
  bot.anticlockwise();
  oldangle = oldangle - angle;
}

else if (c == START) {
  bot.forward();
  delay(700);
  mpu6050();
  while (angle < -70) {
    bot.clockwise();
  }
  bot.stpp();
}
else if (c == SELECT) {
  N2.down();
  delay(40);
  N2.up();
}
else if (c == PS) {
  resetFunc();
}

else {
  bot.stpp();
  m.stp(0);
}

Serial.println("loop end");
}
