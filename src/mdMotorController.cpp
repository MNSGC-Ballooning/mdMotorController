#include "mdMotorController.h"

//Constructor for motor controller. Each side of board controlled by separate object.
mdMotorController::mdMotorController(int Epin,int Mpin):
  Epin(Epin), Mpin(Mpin) {
}

//Call during setup() to set pins to outputs
void mdMotorController::initialize() {
  pinMode(Epin,OUTPUT);
  pinMode(Mpin,OUTPUT);
}

//Call during every loop() to update motor speed as it tracks the target
void mdMotorController::run() {
  //Wait 10 ms before incrementing or decrementing speed -
  //limits unnecessary load from sudden speed/direction changes
  if (millis()-lastUpdate < 10) return;
  lastUpdate = millis();
  if (speed < target) {
    speed++;
    if (speed == 1)
      digitalWrite(Mpin,LOW);
  }
  else if (speed > target) {
    speed--;
    if (speed == -1)
      digitalWrite(Mpin,HIGH);
  }
  analogWrite(Epin,abs(speed));
}

//Used to set the target speed for the motor, ranging from 0 to +/-255
//0 = full stop
//255 = full forward
//-255 = full reverse
//Values outside this range are interpreted as +/-255
void mdMotorController::setSpeed(int target) {
  if (target > 255)
    this->target = 255;
  else if (target < -255)
    this->target = -255;
  else
    this->target = target;
}