#include "XPosition.h"
#include "stdio.h"

XPosition::XPosition(): 
    Measure()
{
}

double XPosition::getValue()
{
    return mXPosition;
}

void XPosition::update(double x)
{
    mXPosition = x;
    //printf("mX%f\n", mXPosition);
}

void XPosition::reset()
{

}