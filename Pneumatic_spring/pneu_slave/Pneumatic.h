class Pneumatic {
  private:
    uint8_t pin1, pin2;
  public:
  Pneumatic (){};
    Pneumatic(uint8_t pin1, uint8_t pin2) {
      this-> pin1 = pin1;
      this-> pin2 = pin2;
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
    }
    void Close() {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
    }
    void Open() {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
    }
    void Free() {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, HIGH);
    }
    void Hold() {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
    }
};
Pneumatic Thrower(35, 41);
Pneumatic Grabber(39, 37);
//Pneumatic Thrower(ThrowP1, ThrowP2);
//Pneumatic Grabber(GrabP1, GrabP2);
