#ifndef __LENGTH_H__
#define __LENGTH_H__
#include "Measure.h"

class Length : public Measure
{
    public:
        Length();
        double getValue();
        void update(double len);
        void reset();

    private:
        double mLength;
};

#endif

