#include "Length.h"

Length::Length()
    : Measure()
{

}

double Length::getValue()
{
    return mLength;
}

void Length::update(double len)
{
    mLength = len;
}

void Length::reset()
{
    
}