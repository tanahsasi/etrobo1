#include "Polling.h"

Polling::Polling(MyColorSensor *col,
                 Odometry *odo):
    mColor(col),
    mOdo(odo)
{

}

void Polling::run()
{
    mColor->update();
    mOdo->update();    
}