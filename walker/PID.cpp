#include "PID.h"
#include "util.h"

PID::PID()
    :PID(0.010)
{


}

PID::PID(double delta) {
    limit = 100;
    diff[0]=diff[1]=0.0;
    integral=0;
    DELTAT=delta;

    firstCnt = 0;
    resetFlg=true;

    sec = 50;
    cnt=0;

    for(int i=0;i<sec;i++) 
        last_integral[i]=0.0f;

  //  printf("created %f %d\n",DELTAT,sec);
    clk = new Clock();

}
PID::~PID() 
{
}

void PID::setLimit(double limit) 
{
    this->limit = limit;
}
void PID::setTarget(double t)
{
    this->target = t;
}

double PID::getOperation(double value)
{

//   static char buf[256];


    diff[0]=diff[1];
    diff[1] = target-value;
    double prev_i=integral;

    delta = (diff[1]-diff[0])/DELTAT;
    /*
    if(debug)printf("%d\n",cnt);
    printf("debug\n");
    for(int i=0;i<section;i++) 
        printf("%d %f\n",i,last_integral[i]);
        */
    last_integral[cnt] = (diff[0]+diff[1])/2.0*DELTAT; 
    integral+=last_integral[cnt]; 
    integral-=last_integral[(cnt+1)%sec];
    
    cnt=(cnt+1)%sec;

    if (firstCnt==1) {
        delta=0;
        firstCnt++;
    }
    if(resetFlg) {
        diff[0]=diff[1];
        delta=0.0f;
        integral=0.0f;
        for(int i=0;i<sec;i++) 
            last_integral[i]=0.0f;
        cnt=0;
        resetFlg=false;
        firstCnt++;
    }


    double val = diff[1]*Kp + delta*Kd + integral*Ki; 

    static int i=0;
    if (debug) {
       // printf("pid:(%3.1f-%3.1f), diff:%4.2f d:%4.2f i:%4.2f  op:%5.3f\n",target,value,diff[1],delta,integral,val);
        printf("%c,%d,%f,%f,%f,%f\n",debug_char,clk->now(),diff[1],integral,delta, val);
        msg_num(debug_char,i,diff[1],integral,delta, val);
        i++;
    }

    if(val>limit) 
        val=limit;
    if(val<-limit)
        val=-limit;
    
    return val;
}

void PID::setKp(double kp)
{
    Kp = kp;
}

void PID::setKi(double ki)
{
    Ki = ki;
}

void PID::setKd(double kd)
{
    Kd = kd;
}

double PID::getDiff() 
{
    return diff[1];
}

double PID::getIntegral()
{
    return integral;
}

void PID::resetParam()
{
    diff[0]=diff[1]=0.0f;
    integral=0;
    resetFlg=true;
}

double PID::getTarget()
{
    return target;
}

void PID::setDeltaT(double delta)
{
    DELTAT = delta;
}