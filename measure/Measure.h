#ifndef __MEASURE_H__
#define __MEASURE_H__

#include "LowPassFilter.h"

class Measure
{
    public:
        Measure();
        virtual double getValue();
        virtual void update(double value);

    protected:
            LowPassFilter *mLpf;

    private:

};

#endif

