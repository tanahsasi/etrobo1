#ifndef VIRCURVELINE
#define VIRCURVELINE

#include "SimpleWalker.h"
#include "Odometry.h"
#include "SpeedControl.h"
#include "PID.h"

class VirCurveLine : public SimpleWalker 
{
    public:
        VirCurveLine(Odometry *odo,
            SpeedControl *scon);
        void setParam(double vcurve[]);
        void setBias(double curve);

        void init();
        void execStart();

    protected:

    private:
        double calcTurn();
        void calcSenter();
        void calcLength();
        void calcSenoer();

        double mradius;
        double maddsensor;
        double R;
        double mx;
        double my;
        double xsensor;
        double ysensor;
        double centerx;
        double centery;

        int mTargetSpeed;
        double mTarget;
        double mPFactor;
        double mIFactor;
        double mDFactor;

        double mAngleKp;
        double mCurve;


        double mBias;    
};

#endif  
