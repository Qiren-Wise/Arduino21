#include <AccelStepper.h>

const int xdirPin = 5;    //方向控制引脚
const int xstepPin = 2;   //步进控制引脚
const int xenablePin = 8; //使能控制引脚

const int moveSteps = 200; //运行步数

AccelStepper stepper1(1,xstepPin,xdirPin); //建立步进电机对象

void setup() {
  // put your setup code here, to run once:
  pinMode(xstepPin,OUTPUT);
  pinMode(xdirPin,OUTPUT);
  pinMode(xenablePin,OUTPUT);
  pinMode(xenablePin,LOW);

  stepper1.setMaxSpeed(300.0);   //设置电机最大速度300
  stepper1.setAcceleration(20.0);//设置电机加速度20.0
}

void loop() {
  // put your main code here, to run repeatedly:
 if (stepper1.currentPosition() == 0)
   {
    stepper1.moveTo(moveSteps);
    } else if (stepper1.currentPosition() == moveSteps)
      {
        stepper1.moveTo(0);
        }

        stepper1.run();
}
