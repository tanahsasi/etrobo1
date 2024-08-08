#include "VirCurveLine.h"
#include "math.h"

VirCurveLine::VirCurveLine(Odometry *odo,
                        SpeedControl *scon):
    SimpleWalker(odo,scon),
    mBias(0)
{
}

void VirCurveLine::execStart()
{
    //printf("1\n");
    calcSenoer();
    calcLength();
    mTurn = calcTurn();

    setCommand((int)mTargetSpeed, (int)mTurn);

    SimpleWalker::execStart();
}

double VirCurveLine::calcTurn()
{
    double val2;
    //printf("RRR%f\n",R);
    if(mradius < 0)
    {
        val2 = mradius + R;
        //printf("minas\n");
    }
    else
    {
        val2 = mradius - R;
        //printf("plus\n");
    }
    
    //printf("val2,,%f,,\n", val2);
    double val2_turn = mPid->getOperation(val2);

    //printf("val2_turn,,%f,,", val2_turn);

    if(mradius) val2_turn = -val2_turn;
    setBias(mCurve);
    double turn =  val2_turn+mBias;
   
    return turn;
}

void VirCurveLine::setParam(double vcurve[])
{
    mradius = vcurve[1];
    //速度
    mTargetSpeed = vcurve[0];
    mTarget = 0;
    mPFactor = vcurve[2];
    mIFactor = vcurve[3];
    mDFactor = vcurve[4];
  
    mPid->setTarget(mTarget);
    mPid->setKp(mPFactor); 
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
   
}

void VirCurveLine::setBias(double curve) //�J�[�u�p����
{
    mBias = curve;
}

void VirCurveLine::init()
{
    calcSenter();
}

void VirCurveLine::calcSenter() //���S���W�̓���
{
    double angle1 = (mAngle->getValue())*M_PI/180;

    mx = mXpos->getValue();
    my = mYpos->getValue();

    centerx = (mradius * -sin(angle1)) +  mx;
    centery = (mradius * cos(angle1)) +  my;

    //printf("X,,%f\n", centerx);
    //printf("Y,,%f\n", centery);

}

void VirCurveLine::calcLength() //���s�̂ƒ��S���W�Ƃ̔��a
{
    R = sqrt((centerx - xsensor) * (centerx - xsensor) + (centery - ysensor) * (centery - ysensor));
    //printf("R%f\n", R);
}

void VirCurveLine::calcSenoer() //�Z���T�[�̏ꏊ
{
    double angle2 = (mAngle->getValue())*M_PI/180;
    maddsensor = 5;
    
    mx = mXpos->getValue();
    my = mYpos->getValue();
    xsensor = maddsensor * cos(angle2) + mx;
    ysensor = maddsensor * sin(angle2) + my;
}
