#include "VirStraightLine.h"
#include "math.h"

VirStraightLine::VirStraightLine(Odometry *odo,
                        SpeedControl *scon):
    SimpleWalker(odo,scon),
    mBias(0)
{
}

void VirStraightLine::execStart()
{
    //printf("VirStraight\n");
    calcSenoer();
    val1 = targetLine();
    mTurn = calcTurn();
    setCommand((int)mTargetSpeed, (int)mTurn);

    SimpleWalker::execStart();
}

double VirStraightLine::calcTurn()
{
    double val2_turn = mPid->getOperation(val1);
    
    if(mTargetSpeed < 0)
    {
        val2_turn = -val2_turn;
    }
    

    setBias(mCurve);
   
    return val2_turn;
}

void VirStraightLine::setParam(double vstraight[]) //?��?��?��x,?��p?��x,0,P,I,D
{
    //printf("Angle%f,,\n",(mAngle->getValue()));
    mTargetSpeed = vstraight[0];
    mSetAngle = vstraight[1];
    mTarget = vstraight[2];
    mPFactor = vstraight[3];
    mIFactor = vstraight[4];
    mDFactor = vstraight[5];
    resetAng = vstraight[6];
  
    mPid->setTarget(mTarget);
    mPid->setKp(mPFactor); 
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
}

void VirStraightLine::setBias(double curve) //?��J?��[?��u?��p?��?��?��?��
{
    mBias = curve;
}

void VirStraightLine::init()
{
    //printf("mSetAngle--,,%f\n,", mSetAngle);
    //printf("mSetAngle,,%f\n,", mSetAngle);

    if(resetAng == 1)
    {
        //printf("WWWWWWWW\n");
        Section::MEMOANG = mAngle->getValue();
        //printf("MEMOANG,,%f\n",Judge::MEMOANG);
    }

    mSetAngle = mSetAngle + Section::MEMOANG;

    //printf("MEMOANG,,%f\n,", Section::MEMOANG);
    /*
    if(mTargetSpeed > 0)
    {
        mSetAngle = mSetAngle + Judge::MEMOANG;//(mAngle->getValue());
        //printf("Angle%f,,\n",(mAngle->getValue()));
    }
    else
    {
        mSetAngle = mSetAngle + Judge::MEMOANG;//((mAngle->getValue()) * -1);
        //printf("Angle%f,,\n",(mAngle->getValue()));
    }
    */
    targetPoint();
}

void VirStraightLine::targetPoint() //?��i?��s?��?��?��?��
{
    mx = mXpos->getValue();
    my = mYpos->getValue();
    double angle1 = mSetAngle*(M_PI/180);//(mAngle->getValue())*(M_PI/180);
    //printf("mSetAngle,,%f\n",mSetAngle*(M_PI/180) );
    //printf("mAngle,,%f\n",(mAngle->getValue())*(M_PI/180));
    mtx = cos(angle1) + mx; 
    mty = sin(angle1) + my;
    //printf("mx,,,%f\n",mx);
    //printf("my,,,%f\n",my);
    //printf("angle1,,%f\n",angle1);
    //printf("mtx,,%f\n",mtx);
    //printf("mty,,%f\n",mty);

}

void VirStraightLine::calcSenoer() //?��Z?��?��?��T?��[?��ʒu
{
    double angle2 = (mAngle->getValue())*(M_PI/180);
    maddsensor = 5;

    if(mTargetSpeed < 0)
    {   
        //angle2 = angle2 * -1;
        maddsensor = maddsensor * -1;
    }

    //printf("angle2,,%f\n",angle2);

    double mpx = mXpos->getValue();
    double mpy = mYpos->getValue();

    msx = maddsensor * cos(angle2) + mpx;
    msy = maddsensor * sin(angle2) + mpy;
}

double VirStraightLine::targetLine()
{
    //mLine = (mty - my) * msx - (mtx - mx) * msy + (mtx * my) - (mty * mx);  
    double MTY = (mty - my);
    double MTX = (mtx - mx);
    double mkx = (mtx * my);
    double mky = (mty * mx);
    MTY = MTY * msx;
    MTX = MTX * msy;

    double mkk = mkx - mky;
    mLine = MTY - MTX + mkk;

    //printf("MTY,,%f\n", MTY);
    //printf("MTX,,%f\n", MTX);
    //printf("mkx,,%f\n", mkx);
    //printf("mky,,%f\n", mky);
    //printf("mkk,,%f\n", mkk);
    //printf("mty * mx,,%f\n", (mty * mx));
    

    //printf("mty - my,,%f\n", (mty - my));
    //printf("mtx - mx,,%f\n", (mtx - mx));
    
    //printf("mtx * my,,%f\n", (mtx * my));
    //printf("mty * mx,,%f\n", (mty * mx));

    //printf("mx,,,%f\n",mx);
    //printf("my,,,%f\n",my);
    
    //printf("mtx,,%f\n",mtx);
    //printf("mty,,%f\n",mty);
    

    //printf("msx,,%f\n",msx);
    //printf("msy,,%f\n",msy);
    //printf("mLine,,%f\n", mLine);
    //printf("MEMOANG,,%f\n,", Section::MEMOANG);


    return mLine;
}
