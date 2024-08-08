#include "SpeedSectionManager.h"
#include "Section.h"

SpeedSectionManager::SpeedSectionManager()
{
    mSectionIdx=0;
    mLastIdx=0;
}

void SpeedSectionManager::course(int direct)
{
    //printf("BBBBBB\n");
    if(direct == 0)
    {
        //printf("e\n");
        set(Lcourse3);
    }
    else
    {
        //printf("f\n");
        set(Rcourse3);
    }
}

