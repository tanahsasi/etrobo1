#ifndef JUDGE_COLOR
#define JUDGE_COLOR

#include "Judge.h"

class JudgeColor : public Judge
{
    public:
        JudgeColor();
        void setParam(double cocn[]);
        void init();
        bool judgement();

    private:
        double mHRange;
        double mSRange;


};
#endif