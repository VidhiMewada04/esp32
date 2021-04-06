class pneu
{
  private:
    int p1, p2;
  public:
    pneu(int p1, int p2) {
      this->p1 = p1;
      this->p2 = p2;
      pinMode(p1, OUTPUT);
      pinMode(p2, OUTPUT); }
    void up() {
      digitalWrite(p1, LOW);
      digitalWrite(p2, HIGH); }
    void down() {
      digitalWrite(p1, HIGH);
      digitalWrite(p2, LOW); }
    void fre() {
      digitalWrite(p1, HIGH);
      digitalWrite(p2, HIGH); }
    void hold() {
      digitalWrite(p1, LOW);
      digitalWrite(p2, LOW); }
};
pneu N1(41, A12);
pneu N2(45, 43);
