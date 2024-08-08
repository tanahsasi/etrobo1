#include "YPosition.h"
#include "stdio.h"

YPosition::YPosition():
    Measure()
{
}

double YPosition::getValue()
{
    return mYPosition;
}

void YPosition::update(double y)
{
    mYPosition = y;
    //printf("mY%f\n", mYPosition);
}

void YPosition::reset()
{

}