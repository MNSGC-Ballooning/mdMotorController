#ifndef mdMotorController_h
#define mdMotorController_h

#include <Arduino.h>

class mdMotorController {
  public:
    mdMotorController(int Epin,int Mpin);
    void initialize();
    void run();
    void setSpeed(int target);
  private:
    int target;
    int speed;
    unsigned long lastUpdate;
    byte Epin, Mpin; //speed and direction pins
};

#endif