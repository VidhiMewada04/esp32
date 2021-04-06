#include "motor.h"
class base
{
  private:
    byte p;
  public:
    base(byte p) {
      this -> p = p;
      pinMode(p, OUTPUT); } 
      void forward() {
        m1.clk(p);
        m2.clk(p);
        m3.aclk(p);
        m4.aclk(p); }
      void backward() {
        m1.aclk(p); 
        m2.aclk(p);
        m3.clk(p);
        m4.clk(p); }
      void left() {
        m1.clk(p);
        m2.aclk(p);
        m3.aclk(p);
        m4.clk(p); }
      void right() {
        m1.aclk(p);
        m2.clk(p);
        m3.clk(p);
        m4.aclk(p); }
      void upleft() {
        m1.clk(p);
        m2.stp(p);
        m3.aclk(p);
        m4.stp(p); }
      void upright() {
        m1.stp(p);
        m2.clk(p);
        m3.stp(p);
        m4.aclk(p); }
      void downleft() {
        m1.stp(p);
        m2.aclk(p);
        m3.stp(p);
        m4.clk(p); }
      void downright() {
        m1.aclk(p);
        m2.stp(p);
        m3.clk(p);
        m4.stp(p); }
      void clockwise() {
        m1.aclk(50);
        m2.aclk(50);
        m3.aclk(50);
        m4.aclk(50); }
      void anticlockwise() {
        m1.clk(50);
        m2.clk(50);
        m3.clk(50);
        m4.clk(50); }
      void stpp() {
        m1.stp(0);
        m2.stp(0);
        m3.stp(0);
        m4.stp(0); }
};
base bot(70);

// angle 70 
// pressure 4.4 bar
// distance line

//    m1.clk(p);
//    delay(1000);
//    m1.aclk(p);
//    delay(1000);
//    m1.stp(p);
//    delay(1000);
