#include "DoubleSection.h"
#include "Section.h"

DoubleSection::DoubleSection()
{
    mSectionIdx=0;
    mLastIdx=0;
}

bool DoubleSection::run()
{   
    printf("ダブル1\n");
    switch(NO)
    {
    case SET_LBLUE_MARKER:
        printf("走行\n");
        set(sLnextpoint);
        NO = LBLUE_MARKER;
        break;
    case LBLUE_MARKER:
        bluemarker(num1);
        break; 
    case SET_LNEXT_POINT:
        printf("走行2\n");
        set(sLnextpoint);
        NO = LNEXT_POINT;
        break;
    case LNEXT_POINT:
        bluemarker(num1);
        break;
    case SET_LFINISHE1:
        set(sLnextpoint);
        printf("いらん\n");
        NO = LFINISHE1;
        break;
    case LFINISHE1:
        bluemarker(8);
        break;
    case SET_LFINISHE2:
        set(Lbluemarker2);
        printf("いらん\n");
        NO = LFINISHE2;
        break;
    case LFINISHE2:
        bluemarker(8);
        break;
    case SET_LFINISHE3:
        set(Lbluemarker3);
        printf("いらん\n");
        NO = LFINISHE3;
        break;
    case LFINISHE3:
        bluemarker(8);
        break;
    case SET_LFINISHE4:
        set(Lbluemarker4);
        printf("いらん\n");
        NO = LFINISHE4;
        break;
    case LFINISHE4:
        bluemarker(8);
        break;    
    case SLCOURSE:
        bluemarker(8);
        break;
    case SET_RBLUE_MARKER:
        set(sRcourse);
        NO = SET_RNEXT_POINT;
        break;
    case RBLUE_MARKER:
        bluemarker(num1);
        break; 
    case SET_RNEXT_POINT:
        set(sRnextpoint);
        NO = RNEXT_POINT;
        break;
    case RNEXT_POINT:
        bluemarker(num1);
        break;
    case SET_RFINISHE1:
        set(Rbluemarker1);
        NO = RFINISHE1;
        break;
    case RFINISHE1:
        bluemarker(8);
        break;
    case SET_RFINISHE2:
        set(Rbluemarker2);
        NO = RFINISHE2;
        break;
    case RFINISHE2:
        bluemarker(8);
        break;
    case SET_RFINISHE3:
        set(Rbluemarker3);
        NO = RFINISHE3;
        break;
    case RFINISHE3:
        bluemarker(8);
        break;
    case SET_RFINISHE4:
        set(Rbluemarker4);
        NO = RFINISHE4;
        break;
    case RFINISHE4:
        bluemarker(8);
        break;    
    case SRCOURSE:
        bluemarker(8);
        break;        
    case END:
        printf("END\n");
        return true;
    }
    return false;
}

void DoubleSection::course(int direct)
{
    if(direct == 0)
    {
        NO = SET_LBLUE_MARKER;
        num1 = 0;
    }
    else
    {
        NO = SET_RBLUE_MARKER;
        num1 = 4;
    }
}

void DoubleSection::bluemarker(int num2/*char pass*/)
{
    if(SectionManager::run())
    {
        switch(num2){
        case 0:
            NO = SET_LFINISHE1;
            break;
        case 1:
            NO = SET_LFINISHE2;
            break;
        case 2:
            NO = SET_LFINISHE3;
            break;
        case 3:
            NO = SET_LFINISHE4;
            break;
        case 4:
            NO = SET_RFINISHE1;
            break;
        case 5:
            NO = SET_RFINISHE2;
            break;
        case 6:
            NO = SET_RFINISHE3;
            break;
        case 7:
            NO = SET_RFINISHE4;
            break;
        case 8:
            NO = END;
            break;
        }
        num1++;

        //extern JudgeReception *mJr;
        //int pass = mJr->mini;
        extern int mini;
        printf("mini = %d\n",mini);
        if(mini == 0)
        {
            if(num2 < 3)
            {
                NO = SET_LNEXT_POINT;
            }
            if(num2 > 3 && num2 < 7)
            {
                printf("RIGHT\n");
                NO = SET_RNEXT_POINT;
            }
    
        }
    }
}

void DoubleSection::scircle(int direct)
{
    if(direct == 0)
    {
        printf("smallleft\n");
        NO = SLCOURSE;
        set(SLcourse);
    }
    else
    {
        printf("smallright\n");
        NO = SRCOURSE;
        set(SRcourse);
    }
}
