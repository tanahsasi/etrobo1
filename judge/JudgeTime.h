#ifndef JUDGE_TIME
#define JUDGE_TIME

#include "Judge.h"

class JudgeTime : public Judge
{
    public:
        JudgeTime();
        void setParam(double ticn[]);
        void init();
        bool judgement();

    private:
        double mTime;
};
#endif