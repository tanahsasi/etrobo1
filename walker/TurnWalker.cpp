#include "TurnWalker.h"

TurnWalker::TurnWalker(Odometry *odo,
                        SpeedControl *scon):
    SimpleWalker(odo,scon)
{

}

void TurnWalker::execStart()
{
    mCurrentLen = mLength->getValue();
    //printf("current%f\n", mCurrentLen);
    double val1 = mTargetLen - mCurrentLen;
    //printf("val1%f\n", val1);
    mTargetSpeed = calcTurn(val1);

    setCommand((int)mTargetSpeed, (int)mTurn);

    SimpleWalker::execStart();
}

void TurnWalker::setParam(double power[])
{
    mTargetSpeed = 0;
    mTarget = 0;

    mTurn = power[0];
    mPFactor = power[1];
    mIFactor = power[2];
    mDFactor = power[3];
  
    mPid->setTarget(mTarget);
    mPid->setKp(mPFactor); 
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
}

double TurnWalker::calcTurn(double val2)
{
    double val3 = mPid->getOperation(val2);
    //printf("val1%f\n", val1_turn);

    val3 = val3*-1;
    //setBias(mCurve);
    double val4 =  val3+mBias;
    //double turn = mTarget;
    //printf("turn%f,,\n", turn);
   
    return val4;
}

void TurnWalker::setBias(double curve) //�J�[�u�p����
{
    mBias = curve;
}

void TurnWalker::init()
{
    mTargetLen = mLength->getValue();
    printf("target%f\n", mTargetLen);
}