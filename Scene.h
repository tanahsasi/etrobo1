#ifndef _SCENE_H_
#define _SCENE_H_

#include "SpeedSectionManager.h"
#include "ColorSensor.h"
#include "MyColorSensor.h"
#include "DoubleSection.h"
#include "BlockSection.h"



class Scene{
    public:
        Scene();
        bool run();
        void execUndefined();
        void execCalibration();
        void execStart();
        void execSpeed();
        void execDoubleloop();
        void execBlock();
        //void execBingo();
        //void execGarage();

    private:
        enum State {
            UNDEFINED,
            CALIBRATION,
            START,
            SPEED,
            DOUBLELOOP,
            BLOCK,
            //BINGO,
            //GARAGE,
            END
        };

        State mState;

        SpeedSectionManager *mSsm;

        MyColorSensor *mColor;

        DoubleSection *mDs;

        DoubleSection *mDs2;

        BlockSection *mBs;

        
};
#endif
