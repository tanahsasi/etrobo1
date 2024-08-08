#include "HsvSatu.h"

HsvSatu::HsvSatu()
    : Measure()
{

}

double HsvSatu::getValue()
{
    return mLpf->getFillteredValue();
}

void HsvSatu::update(double s)
{
    mLpf->addValue(s);
    mHsvSatu = s;
}