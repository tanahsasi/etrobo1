#ifndef XPOSITION
#define XPOSITION
#include "Measure.h"

class XPosition : public Measure
{
    public:
        XPosition();
        double getValue();
        void update(double x);
        void reset();

    private:
        double mXPosition;
};

#endif