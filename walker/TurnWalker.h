#ifndef TURNWALKER
#define TURNWALKER

#include "SimpleWalker.h"
#include "Odometry.h"
#include "SpeedControl.h"
#include "PID.h"

class TurnWalker : public SimpleWalker 
{
    public:
        TurnWalker(Odometry *odo,
            SpeedControl *scon);
        void setParam(double power[]);
        void setBias(double curve);
        void init();
        void execStart();
        double calcTurn(double val2);

    protected:

    private:

        double mTargetLen;
        double mCurrentLen;

        int mTargetSpeed;
        double mTarget;

        double mCurve;
        double mBias;
        double mPFactor;
        double mIFactor;
        double mDFactor;

};

#endif  
