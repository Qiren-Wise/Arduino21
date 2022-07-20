#include <AccelStepper.h>

const int xdirPin = 5;    //方向控制引脚
const int xstepPin = 2;   //步进控制引脚
const int enablePin = 8; //使能控制引脚

const int ydirPin = 6;    //方向控制引脚
const int ystepPin = 3;   //步进控制引脚

const int zdirPin = 7;    //方向控制引脚
const int zstepPin = 4;   //步进控制引脚


const int adirPin = 13;    //方向控制引脚
const int astepPin = 12;   //步进控制引脚

const int moveSteps = 200; //运行步数

AccelStepper stepper1(1,xstepPin,xdirPin); //建立步进电机对象1
AccelStepper stepper2(1,ystepPin,ydirPin); //建立步进电机对象2
AccelStepper stepper3(1,zstepPin,zdirPin); //建立步进电机对象3
AccelStepper stepper4(1,astepPin,adirPin); //建立步进电机对象4

void setup() {
  // put your setup code here, to run once:
  pinMode(xstepPin,OUTPUT);
  pinMode(xdirPin,OUTPUT);

  pinMode(ystepPin,OUTPUT);
  pinMode(ydirPin,OUTPUT);

  pinMode(zstepPin,OUTPUT);
  pinMode(zdirPin,OUTPUT);

  pinMode(astepPin,OUTPUT);
  pinMode(zdirPin,OUTPUT);
  
  pinMode(enablePin,OUTPUT);
  pinMode(enablePin,LOW);

  stepper1.setMaxSpeed(300.0);   //设置电机最大速度300
  stepper1.setAcceleration(20.0);//设置电机加速度20.0

  stepper2.setMaxSpeed(300.0);   //设置电机最大速度300
  stepper2.setAcceleration(20.0);//设置电机加速度20.0

  stepper3.setMaxSpeed(300.0);   //设置电机最大速度300
  stepper3.setAcceleration(20.0);//设置电机加速度20.0

  stepper4.setMaxSpeed(300.0);   //设置电机最大速度300
  stepper4.setAcceleration(20.0);//设置电机加速度20.0
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

    if (stepper2.currentPosition() == 0)
   {
    stepper2.moveTo(moveSteps/2);
    } else if (stepper2.currentPosition() == moveSteps/2)
      {
        stepper2.moveTo(0);
        }

   if (stepper3.currentPosition() == 0)
   {
    stepper3.moveTo(moveSteps/4);
    } else if (stepper3.currentPosition() == moveSteps/4)
      {
        stepper3.moveTo(0);
        }

   if (stepper4.currentPosition() == 0)
   {
    stepper4.moveTo(moveSteps/8);
    } else if (stepper4.currentPosition() == moveSteps/8)
      {
        stepper4.moveTo(0);
        }
       

        stepper1.run();
        stepper2.run();
        stepper3.run();
        stepper4.run();
}
