/******************************************************************************
 *  SimpleWalker.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Implementation of the Class SimpleWalker
 *  Author: Kazuhiro.Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "SimpleWalker.h"
#include "Walker.h"
#include "util.h"

extern MotorManager *gMotor;

// 定数宣言
/**
 * コンストラクタ
 * @param gyroSensor ジャイロセンサ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 * @param balancer   バランサ
 */
SimpleWalker::SimpleWalker(
                        Odometry *odo,
                        SpeedControl *scon
                       ):
        Walker(odo),
        mSpeedControl(scon),
        mForward(0),
        mTurn(0),
        mBreake_flag(false),
        mMode_flag(false),
        mMotor(gMotor)
{

}


void SimpleWalker::execStart() {

    //printf("SimpleWalker_check\n");
    static double speed=0;

    //mForward = mSpeedControl->getPwm();

    double pwm_l = mForward + mTurn;      // <2>
    double pwm_r = mForward - mTurn;      // <2>
    static const int MAXPWM=100;
    int diff = 0;
    //printf("pwm_l,pwm_r%f,,%f\n", pwm_l, pwm_r);

    if(pwm_l>MAXPWM) {
        pwm_r = (int)((double)MAXPWM*pwm_r/pwm_l);
        pwm_l=MAXPWM;
    }
    if(pwm_l<-MAXPWM) {
        pwm_r = (int)((double)-MAXPWM*pwm_r/pwm_l);
        pwm_l=-MAXPWM;
    }

    if(pwm_r>MAXPWM) {
        pwm_l = (int)((double)MAXPWM*pwm_l/pwm_r);
        pwm_r=MAXPWM;
    }
    if(pwm_r<-MAXPWM) {
        pwm_l = (int)((double)-MAXPWM*pwm_l/pwm_r);
        pwm_r=-MAXPWM;
    }

    if(pwm_r>100) pwm_r=100;
    if(pwm_l>100) pwm_l=100;
    if(pwm_r<-100) pwm_r=-100;
    if(pwm_l<-100) pwm_l=-100;

    //printf("pwm_l%fpwm_r%f\n", pwm_l,pwm_r);
    //printf("MFORWARD_%f\n", mForward);
    mMotor->setPwm(pwm_l,pwm_r);
}

/**
 * PWM値を設定する
 * @param forward 前進値
 * @param turn    旋回値
 */
void SimpleWalker::setCommand(int forward, int turn) {
    mForward = forward;
    mSpeedControl->resetParam();
    mSpeedControl->setTargetSpeed(forward);
    mTurn    = turn;
    //mMode_flag = false;
    mSpeedControl->setMode(false);

    //printf("forward%f\n",mForward);

}

void SimpleWalker::setCommandV(double forward, int turn)
{

    mSpeedControl->setTargetSpeed(forward);
    mSpeedControl->setBreak(false);
    
    if (forward==0) {
        mSpeedControl->setBreak(true);
        mForward=0;
    }
    mTurn    = turn;
    mSpeedControl->setMode(true);
}

void SimpleWalker::setParam(double simArray[])
{
    //printf("AAAAAAA\n");
    //setCommand(simArray[0],simArray[1]);
    mInitForword = simArray[0];
    mInitTurn = simArray[1];
}

void SimpleWalker::resetParam()
{
    mSpeedControl->resetParam();
}

void SimpleWalker::init()
{
    setCommand(mInitForword,mInitTurn);
    //printf("mForward%f\n", mForward);
}



