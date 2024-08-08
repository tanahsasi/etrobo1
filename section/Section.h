#ifndef _SECTION_H_
#define _SECTION_H_

#include "LineTracer.h"
#include "SimpleWalker.h"
#include "VirCurveLine.h"
#include "VirStraightLine.h"
#include "TurnWalker.h"
#include "FileWalker.h"

#include "Walker.h"
#include "Judge.h"
#include "JudgeLength.h"
#include "JudgeBrightness.h"
#include "JudgeColor.h"
#include "JudgeTime.h"
#include "JudgeTurnAngle.h"
#include "JudgeReception.h"


class Section {
    public:

        Section();
        ~Section();
        virtual bool run();
        Walker *selectWalker(int no);
        Judge *selectJudge(int no);
        //EmgJudge *selectEmgJudge(int no);

        static double MEMOLEN;
        static double MEMOANG;

        enum WALKER_NO{
            WALKER,
            TRACER,
            VIRCLINE,
            VIRSLINE,
            TWALKER,
            FILE,
            WANONE
        };

        enum JUDGE_NO{
            LENGTH,
            COLOR,
            BRIGHTNESS,
            TURNANGLE,
            TIME,
            RECEPTION,
            JUNONE
        };

        enum EMGJUDGE_NO{
            EMNONE
        };

        enum FLAG_NO{
            RESETLEN,
            RESETANG,
            FLNONE
        };




    protected:
        Walker *mWalker;
        Judge *mJudge;
        Judge *mMissJudge;

    private:

};

#endif
