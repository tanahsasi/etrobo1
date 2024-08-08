#include "JudgeLength.h"

JudgeLength::JudgeLength()
{
    //printf("const%d\n",mState);
}

void JudgeLength::setParam(double lencn[])
{
    mLengthkids = lencn[0];
    memoLen = lencn[1];
}

void JudgeLength::init()
{
    if(memoLen == Section::RESETLEN)
    {
        printf("check\n");

        Section::MEMOLEN = mLength->getValue();
    }
    mdirect = true;
    mLengthkids = mLengthkids + Section::MEMOLEN;

    //printf("mdirect%d\n",mdirect);
    //printf("mlengthkids%f\n",mLengthkids);
    //printf("mlengthget%f\n",mLength->getValue());
    if(mLengthkids < mLength->getValue())
    {
        mdirect = false;
    }

}

bool JudgeLength::judgement()
{
    //printf("mdirect%d\n",mdirect);
    //printf("mlengthkids%f\n",mLengthkids);
    //printf("Lastmlengthget%f\n",mLength->getValue());

    //printf("mLengthkids%f\n", mLengthkids);
    //printf("mLength->getValue%f\n", mLength->getValue());

    if(mdirect)
    {
        if(mLengthkids <= mLength->getValue())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(mLengthkids >= mLength->getValue())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
