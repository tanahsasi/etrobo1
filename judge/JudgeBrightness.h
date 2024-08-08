#ifndef JUDGE_BRIGHTNESS
#define JUDGE_BRIGHTNESS

#include "Judge.h"

class JudgeBrightness : public Judge
{
    public:
        JudgeBrightness();
        void setParam(double brcn[]);
        void init();
        bool judgement();   
    private:
        double mBrightkids;
};
#endif