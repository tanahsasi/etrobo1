#ifndef __HSVHUE_H__
#define __HSVHUE_H__
#include "Measure.h"

class HsvHue : public Measure
{
    public:
        HsvHue();
        double getValue();
        void update(double h);

    private:
        double mHsvHue;
};

#endif

