#include "JudgeTurnAngle.h"

JudgeTurnAngle::JudgeTurnAngle()
{

}

void JudgeTurnAngle::setParam(double tucn[])
{
    mTurnkids = tucn[0];
    //printf("mTurnkids = %f\n",mTurnkids);
    memoAng = tucn[1];
}

void JudgeTurnAngle::init()
{
    if(memoAng == Section::RESETANG)
    {
        Section::MEMOANG = mTurnAngle->getValue();
        //printf("MEMOANG,,%f\n",Judge::MEMOANG);
    }
    mdirect = true;
    mTurnkids = mTurnkids + Section::MEMOANG;

    if(mTurnkids < mTurnAngle->getValue())
    {
        mdirect = false;
    }
}

bool JudgeTurnAngle::judgement()
{
    //printf("mTurnkids%f\n", mTurnkids);
    //printf("mTurnAngle->getValue()%f\n", mTurnAngle->getValue());
    if(mdirect)
    {
        if(mTurnkids<=mTurnAngle->getValue())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(mTurnkids>=mTurnAngle->getValue())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}