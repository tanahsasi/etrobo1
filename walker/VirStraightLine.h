#ifndef VIRSTRAIGHTLINE
#define VIRSTRAIGHTLINE

#include "SimpleWalker.h"
#include "PID.h"
#include "Odometry.h"
#include "SpeedControl.h"
#include "Judge.h"
#include "Section.h"

class VirStraightLine : public SimpleWalker 
{
    public:
        VirStraightLine(Odometry *odo,
            SpeedControl *scon);
        void init();
        void setParam(double vstraight[]);
        void setBias(double curve);

        void execStart();

    
    protected:

    private:
        double calcTurn();
        void calcSenoer();
        void targetPoint();
        double targetLine();

        int resetAng;

        double mx;
        double my;
        double mLine;
        double msx;
        double msy;
        double mtx;
        double mty;
        double maddsensor;
        double val1;
        double val2;

        int mTargetSpeed;
        double mSetAngle;
        double mTarget;
        double mPFactor;
        double mIFactor;
        double mDFactor;
        
        double mCurve;
        double mBias;  
};

#endif  
