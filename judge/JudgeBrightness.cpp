#include "JudgeBrightness.h"

JudgeBrightness::JudgeBrightness()
{

}

void JudgeBrightness::setParam(double brcn[])
{
    mBrightkids = brcn[0];
}

void JudgeBrightness::init()
{

}

bool JudgeBrightness::judgement()
{
    
    if(mBrightkids>=mBrightness->getValue())
    {
        printf("%f\n",mBrightkids);
        printf("%f\n",mBrightness->getValue());
        return true;
    }
    return false;

}
