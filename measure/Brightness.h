#ifndef __BRIGHTNESS_H__
#define __BRIGHTNESS_H__
#include "Measure.h"

class Brightness : public Measure
{
    public:
        Brightness();
        double getValue();
        void update(double br);

    private:
        double mBrightness;
};

#endif

