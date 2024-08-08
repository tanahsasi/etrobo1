#ifndef JUDGE_RECEPTION
#define JUDGE_RECEPTION

#include "Judge.h"

class JudgeReception : public Judge
{
    public:
        JudgeReception();
        void init();
        bool judgement();
        void reception(char result[]);
        void measureTime();
        void setParam(double recn[]);
        
    protected:
    enum BLOCK_COLOR{
        RED = 1,
        BLUE1,
        BLUE2
    };

    private:
        

};
#endif