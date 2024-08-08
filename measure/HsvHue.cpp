#include "HsvHue.h"

HsvHue::HsvHue()
    : Measure()
{

}

double HsvHue::getValue()
{
    return mHsvHue;
}

void HsvHue::update(double h)
{
    mHsvHue = h;
}