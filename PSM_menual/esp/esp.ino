#include<Ps3Controller.h>
#include<SPI.h> 
SPIClass * vspi = NULL;     //pointer   
#define reset 0    
#define n1u 1
#define n1d 2    
#define n2u 3
#define n2d 4

void setup() 
{
  vspi = new SPIClass(VSPI);          
  vspi->begin(); 
  pinMode(5, OUTPUT); 
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  Serial.begin(115200);
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  Ps3.begin("33:33:33:33:33:33");
//  Ps3.begin("66:55:44:33:22:11");
  Ps3.attach(notify); 
}
 
void sendData(int x) 
{
  vspi->beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));  //spiClk = 1000000
  digitalWrite(5, LOW); 
  vspi->transfer(x);
  digitalWrite(5, HIGH); 
  vspi->endTransaction();
}
  
void notify() 
{
  
  if (!Ps3.isConnected()) {
    Serial.println("disconnected");
    digitalWrite(4, LOW);
    Serial.println("reset");
    sendData(reset);
    Serial.println("bot-stop"); }
    
  else if (Ps3.data.button.up) {
    sendData(n1u); }
  else if (Ps3.data.button.down) {
    sendData(n1d); }
  else if (Ps3.data.button.left) {
    sendData(n2u); }
  else if (Ps3.data.button.right) {
    sendData(n2d); }
//  else if (Ps3.data.button.triangle) {
//    spi_send(TRIANGLE); }
//  else if (Ps3.data.button.circle) {
//    spi_send(CIRCLE); }
//  else if (Ps3.data.button.cross) {
//    spi_send(CROSS); }
//  else if (Ps3.data.button.square) {
//    spi_send(SQUARE); }
  else if ( Ps3.event.button_down.r2 ) {
    sendData(9); } 
  else if ( Ps3.event.button_down.l2 ) {
    sendData(11); }
  else if ( Ps3.data.button.l1 ) {
    sendData(aclk); }
  else if ( Ps3.data.button.r1 ) {
    sendData(clk); }
  else if (Ps3.data.analog.stick.lx == -1 && Ps3.data.analog.stick.ly == -128) {
    sendData(f); }
  else if (Ps3.data.analog.stick.lx == -1 && Ps3.data.analog.stick.ly == 127) {
    sendData(b); }   
  else if (Ps3.data.analog.stick.lx == -128 && Ps3.data.analog.stick.ly == -1) {
    sendData(l); }
  else if (Ps3.data.analog.stick.lx  == 127  && Ps3.data.analog.stick.ly == -1) {
    sendData(r); }
  else if (Ps3.data.analog.stick.lx == -128 && Ps3.data.analog.stick.ly == -128) {
    sendData(ul); }
  else if (Ps3.data.analog.stick.lx == 127 && Ps3.data.analog.stick.ly == -128) {
    sendData(ur); }
  else if (Ps3.data.analog.stick.lx == -128 && Ps3.data.analog.stick.ly == 127) {
    sendData(dl); }
  else if (Ps3.data.analog.stick.lx == 127 && Ps3.data.analog.stick.ly == 127) {
    sendData(dr); }
  else if (Ps3.data.button.start) {
    sendData(33); }
  else if (Ps3.data.button.select) {
    sendData(35); }
  else if (Ps3.data.button.ps) {
    Serial.println("reset");
    ESP.restart(); }
  else {
    sendData(50); }
      
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //  if (!Ps3.isConnected()) {
  //    Serial.println("Disconnected");
  //    digitalWrite(4, LOW);
  //    sendData(0);

}
