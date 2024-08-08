#include "FileWalker.h"

extern Process *gProcess;

FileWalker::FileWalker(Odometry *odo):
    Walker(odo)
{

}

void FileWalker::execStart()
{
    //printf("GO\n");
    //int check = mPro->writing();
    //printf("check%f,,\n", check);
}

void FileWalker::init()
{
    
    printf("a\n");
    switch(mNo){
        case SNAP:
            printf("snap\n");
            mPro->writing1(mComment);
            break;
        case BLOCK:
            printf("block\n");
            mPro->writing2(mComment);
            break;
        case IOT:
            printf("iot\n");
            mPro->writing3(mComment);
            break;
        default:
            break;
    }
    //mPro->writing();
    
}

void FileWalker::setParam(double flwk[]) //??申?申g??申?申??申?申??申?申??申?申??申?申??申?申??申?申p??申?申C??申?申v??申?申A??申?申??申?申??申?申e
{
    mNo = flwk[0];
    mComment = flwk[1];
}