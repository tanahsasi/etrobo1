#ifndef __SPEED_CONTROL_H__
#define __SPEED_CONTROL_H__

#include "PID.h"
#include "Odometry.h"

class SpeedControl
{
    public:
        SpeedControl(Odometry *odo);
        void setTargetSpeed(double speed);
        int getPwm();
        void resetParam();
        void setMode(bool mode);
        void setBreak(bool brk);
        double getCurrentFwd();
        double getCurrentSpeed();

    private:
        PID *mPid;
        Odometry *mOdo;

        double mTargetSpeed;
        int mForward; //現在PWM値
        double mCurrentSpeed;

        bool mBreake_flag;
        bool mMode_flag;//setComandVだとtrue、setComandだとfalse
        int mCnt=0;


};
#endif
