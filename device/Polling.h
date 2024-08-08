#ifndef __POLLING_H__
#define __POLLING_H__

#include "MyColorSensor.h"
#include "Odometry.h"

class Polling
{
    public:
        Polling(MyColorSensor *col,
                Odometry *odo);
        void run();

    private:
        MyColorSensor *mColor;
        Odometry *mOdo;

};

#endif

