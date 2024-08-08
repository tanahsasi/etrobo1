#ifndef __TURNANGLE_H__
#define __TURNANGLE_H__
#include "Measure.h"

#define M_PI 3.14159265358979323846

class TurnAngle : public Measure
{
    public:
        TurnAngle();
        double getValue();
        void update(double angle);
        void reset();

    private:
        double mTurnAngle;
        bool mAngleDeg;
};

#endif

