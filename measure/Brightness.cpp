#include "Brightness.h"

Brightness::Brightness()
    : Measure()
{

}

double Brightness::getValue()
{
    return mLpf->getFillteredValue();
}

void Brightness::update(double br)
{
    mLpf->addValue(br);
    mBrightness = br;
}