#ifndef _PID_H_
#define _PID_H_

#include "ev3api.h"
#include "Clock.h"
using namespace ev3api;

class PID {
    public:
        PID();
        PID(double delta);
        ~PID();
        void setLimit(double);
        void setTarget(double);
        double getOperation(double value);

        void setKp(double kp);
        void setKi(double ki);
        void setKd(double kd);

        double getDiff();
        double getIntegral();

        void resetParam();
        double getTarget();

        void setDeltaT(double delta);

        bool debug = false;
        char debug_char=' ';
    private:
       double diff[2];
       double integral;
        double last_integral[1000];
       double target;
       double limit; 
       double delta;
       double Kp;
       double Ki;
       double Kd;
       double DELTAT;

       double tgt_limit;

       bool resetFlg;

        int sec;
        int cnt;

        int firstCnt=0;

        Clock *clk;

};

#endif
