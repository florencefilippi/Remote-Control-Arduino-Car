#include <IRremote.hpp>

const int remotePin = 8;

const int in1 = 3;
const int in2 = 5;
const int in3 = 6;
const int in4 = 9;

void setup(){
  IrReceiver.begin(remotePin, ENABLE_LED_FEEDBACK);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop(){

  if(IrReceiver.decode()){
    unsigned long code = IrReceiver.decodedIRData.command;

  //0x9  forward button
  //0xD  back button
  //0xC  left button
  //0xE  right button
  //0x1  stop button

  if(code == 0x9){
    forward();
  }
  else if(code == 0xD){
    backward();
  }
  else if(code == 0xC){
    left();
  }
  else if(code == 0xE){
    right();
  }
  else if(code == 0x1){
    stop();
  }

  IrReceiver.resume();

  }
}

void forward(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}
void backward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

}
void left(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}
void right(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

}
void stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}
