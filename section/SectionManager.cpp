#include "SectionManager.h"
#include "Section.h"

SectionManager::SectionManager()
{
    
    mSectionIdx=0;
    mLastIdx=0;
}

SectionManager::~SectionManager()
{
    msg_log("destruct SectionManager");

    for(int i=0;i<mLastIdx;i++) {
        delete mSection[i];
    }
}

void SectionManager::set(SecParam* array) //?��?��Ԃ�?��?��?��?��?��?��
{

    for(int i=0;; i++)
    {
        printf("set\n");
        if(array[i].walker_no == Section::WANONE)
        {
            //printf("breakSet\n");
            printf("SET内(if)\n");
            break;
        }
        Section *sc = new Section(); //create

        Walker* walker = sc->selectWalker(array[i].walker_no);
        walker->setParam(array[i].secList); 

        Judge* judge = sc->selectJudge(array[i].judge_no); 
        judge->setParam(array[i].judList);

        addSection(sc);
        
    }
}

bool SectionManager::run() //?��?��?��s?��?��?��?��
{
    if(mSection[mSectionIdx]->run())
    {
        mSectionIdx++;
        if(mSectionIdx == mLastIdx)
        {
            //printf("speed????????????\n");
            reset();
            return true;
        }
        /*else
        {
            mSectionIdx++;
        }*/
        //printf("mscetion%d\n", mSectionIdx);
        //printf("mlast%d\n", mLastIdx);
        
    }
    return false;
}

void SectionManager::addSection(Section *sec) //?��?��Ԓǉ�
{
    mSection[mLastIdx++]=sec;
    //printf("mLast %d\n",mLastIdx);
}

void SectionManager::reset() //?��?��?��?��?��?��
{
    for(int i=0;i<mLastIdx;i++) {
        delete mSection[i];
    }
    mSectionIdx = 0;
    mLastIdx=0;
}

