#ifndef YPOSITION
#define YPOSITION
#include "Measure.h"

class YPosition : public Measure
{
    public:
        YPosition();
        double getValue();
        void update(double y);
        void reset();

    private:
        double mYPosition;
};

#endif