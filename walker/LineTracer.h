/******************************************************************************
 *  LineTracer.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_LINETRACER_H_
#define EV3_APP_LINETRACER_H_

#include "SimpleWalker.h"
#include "PID.h"
#include "Odometry.h"
#include "SpeedControl.h"

class LineTracer : public SimpleWalker {
public:
    LineTracer(Odometry *odo,
            SpeedControl *scon);

    void setParam(double speed,double target,double kp, double ki, double kd);
    void setParam(double speed,double target,double kp, double ki, double kd,double angleTarget,double angleKp);
    void setParam(double lineArray[]);
                       
    void setEdgeMode(bool isLeftEdge);
    bool getEdgeMode();
    void changeEdgeMode();
    void setLimit(double limit);

    bool isLeftEdge();
  
    void setBias(double curve);
    void addBias(double add);

    void printInfo();

    void init();
    void execStart();

    static const int LEFTEDGE;
    static const int RIGHTEDGE;


private:
    double calcTurn(double val1);

    double mSpeed;

    int mTargetSpeed;
    double mTarget;
    double mPFactor;
    double mIFactor;
    double mDFactor;

    double mAngleKp;
    bool mLeftEdge;
    double mCurve;


    double mBias;

    int mLimit;  
};

#endif  // EV3_APP_LINETRACER_H_
