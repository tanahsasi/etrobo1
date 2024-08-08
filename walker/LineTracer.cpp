/******************************************************************************
 *  LineTracer.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/26
 *  Implementation of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "LineTracer.h"
#include <math.h>

#include "util.h"

const int LineTracer::LEFTEDGE = true;
const int LineTracer::RIGHTEDGE = false;

/**
 * コンストラクタ
 * @param lineMonitor     ライン判定
 * @param balancingWalker 倒立走行
 */
LineTracer::LineTracer( Odometry *odo,
                        SpeedControl *scon
                    ) 
    : SimpleWalker(odo,scon),
      mSpeed(0),
      mLeftEdge(true),
      mLimit(100),
      mBias(0)
{
}
 
void LineTracer::execStart()
{
    double  brightness;
    double direction;
    //printf("LineTracer\n");
    brightness=mBright->getValue();
    mTurn = calcTurn(brightness);

   /* static char buf[256];
    sprintf(buf,"LT %2.3f, %d,%d",brightness,mTargetSpeed,mTurn);
    msg_log(buf);*/

    setCommand((int)mTargetSpeed, (int)mTurn);

    SimpleWalker::execStart();

}


   
double LineTracer::calcTurn(double val1) {

    /*
    double bai = 1.0;   //CompositeSection用？
    if(mSpeedControl->getCurrentSpeed()<15) {  //12
        bai=0.5;
    }
    mPid->setKp(mPFactor*bai); //0.376
    mPid->setKi(mIFactor*bai);
    mPid->setKd(mDFactor*bai);
    */

    double val1_turn =  mPid->getOperation(val1); 

  //  mPid->debug=true;

    if(mLeftEdge) val1_turn = -val1_turn;
    setBias(mCurve);
    double turn =  val1_turn+mBias;
   
    return turn;
}

void LineTracer::setParam(double speed,double target,double kp, double ki, double kd) 
{
    setParam(speed, target, kp,  ki,  kd,
                         1, 1);

}

void LineTracer::setParam(double speed,double target,double kp, double ki, double kd,
                        double angleTarget,double angleKp) 
{

  /*  static char buf[256];
      sprintf(buf,"Lintracer setParam %2.1f,%3.1f,  %3.1f,%3.1f,%3.1f,  %2.1f, %2.1f",speed,target, kp,ki,kd, angleTarget,angleKp);
    msg_log(buf);*/
  
    mTargetSpeed = speed;
    mTarget= target;
    mPFactor = kp;
    mIFactor = ki;
    mDFactor = kd;

  
    mPid->setTarget(mTarget);
    mPid->setKp(mPFactor); 
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
   
    mCurve = angleTarget;
    mAngleKp = angleKp;

}

void LineTracer::setParam(double lineArray[])
{
    setParam(lineArray[0],lineArray[1],lineArray[2],lineArray[3],lineArray[4],lineArray[5],lineArray[6]);
    setEdgeMode(lineArray[7]);
}


void LineTracer::setEdgeMode(bool isLeftEdge)
{
    mLeftEdge = isLeftEdge;
}

bool LineTracer::getEdgeMode()
{
    return mLeftEdge;
}

void LineTracer::setLimit(double limit)
{
    mLimit=limit;
    mPid->setLimit(limit);
}

bool LineTracer::isLeftEdge()
{
    return mLeftEdge;
}

void LineTracer::setBias(double curve) //カーブパラム
{
    mBias = curve;
}

void LineTracer::addBias(double add) //カーブパラム
{
    mBias += add;
}

void LineTracer::printInfo()
{
    msg_log("LineTracer");
}

void LineTracer::init()
{

}