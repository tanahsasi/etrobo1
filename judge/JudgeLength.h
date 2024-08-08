#ifndef JUDGE_LENGTH
#define JUDGE_LENGTH

#include "Judge.h"
#include "Section.h"


class JudgeLength : public Judge
{
    public:
        JudgeLength();
        void setParam(double lencn[]);
        void init();
        bool judgement();

    private:
        double mLengthkids;
        double memoLen;
        bool mdirect;

};
#endif