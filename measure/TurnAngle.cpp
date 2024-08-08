#include "TurnAngle.h"
#include "stdio.h"

TurnAngle::TurnAngle()
    : Measure(),
    mAngleDeg(true)
{
}

double TurnAngle::getValue()
{
    //printf("angle%f\n", mAngleDeg?mTurnAngle*180/M_PI:mTurnAngle); //rad -> �x
    return mAngleDeg?mTurnAngle*180/M_PI:mTurnAngle;
}

void TurnAngle::update(double angle)
{
    //printf("angle%f\n", angle);
    mTurnAngle = angle;
}

void TurnAngle::reset()
{
    
}