#include <mdMotorController.h>

#define Mpin 2 //Pin connected to M pin on motor controller
#define Epin 3 //Pin connected to E pin on motor controller - must be PWM capable
#define pot A0 //Pin reading a potentiometer value
#define button 8 //Pin connected to a push button

//define motor controller object
mdMotorController motor = mdMotorController(Epin,Mpin);

void setup() {
  //declare button and potentiometer pins as inputs
  pinMode(pot,INPUT);
  pinMode(button,INPUT_PULLUP);
  //perform setup for motor controller
  motor.init();
}

void loop() {
  //set target speed for motor based on push button and potentiometer states
  if (digitalRead(button)) //button not pressed - forward
    motor.setSpeed(analogRead(pot)/1023.0*255);
  else  //button pressed - reverse
    motor.setSpeed(-analogRead(pot)/1023.0*255);

  //Call run() during every loop to ensure motor continuously adjusts to target speed
  motor.run();
}