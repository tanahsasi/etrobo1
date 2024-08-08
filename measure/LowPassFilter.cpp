#include "LowPassFilter.h"

LowPassFilter::LowPassFilter()
{
    prev=0.0;
    mRate = 0.4;
}
LowPassFilter::~LowPassFilter()
{
}

void LowPassFilter::addValue(double value)
{
    prev = prev*mRate + value*(1-mRate);
}

double LowPassFilter::getFillteredValue()
{    
    return prev;
}

void LowPassFilter::setRate(double rate)
{
    mRate = rate;
}
