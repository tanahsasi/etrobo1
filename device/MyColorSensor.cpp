#include "MyColorSensor.h"

#include "util.h"

 const int MyColorSensor::BRIGHT = false;
 const int MyColorSensor::COLOR = true;

MyColorSensor::MyColorSensor(ePortS port,
                            Brightness *br,
                            HsvHue *h,
                            HsvSatu *s):
    mPort(port),
    mBrightness(br),
    mColorMode(COLOR),
    mHue(h),
    mSatu(s),
    mNorm(true)
{
    mColor = new ColorSensor(mPort);

    mMax_brightness = 36;
    mMin_brightness = 6;
#if defined(MAKE_SIM)
    mMax_R  = 129;
    mMin_R  = 4;
    mMax_G  = 120;
    mMin_G  = 5;
    mMax_B  = 165;
    mMin_B  = 8;
#else
    mMax_R  = 217;
    mMin_R  = 0;
    mMax_G  = 228;
    mMin_G  = 0;
    mMax_B  = 235;
    mMin_B  = 0;  
#endif 
}

void MyColorSensor::update()
{
   // ColorSensor col(PORT_2);

    if(mColorMode==BRIGHT) {
        mBright = mColor->getBrightness();
        mNorm_bright = normBrightness(mBright, mMin_brightness, mMax_brightness);
    } else {
        mColor->getRawColor(raw);
       // syslog(LOG_NOTICE,"%d,%d,%d",raw.r,raw.g,raw.b);
        mRgb.r = normColor(raw.r,mMin_R,mMax_R);
        mRgb.g = normColor(raw.g,mMin_G,mMax_G);
        mRgb.b = normColor(raw.b,mMin_B,mMax_B);
        //printf("r,g,b%f%f%f\n", mRgb.r, mRgb.g, mRgb.b);
        getHSV(mRgb,mHsv);
        mHue->update(mHsv.h);
        mSatu->update(mHsv.s);

        mBright =  0.298912 * mRgb.r  + 0.586611 * mRgb.g + 0.114478 * mRgb.b ;
        //syslog(LOG_NOTICE,"(x100) %d,%d,%d  %d",(int)(mRgb.r*100),(int)(mRgb.g*100),(int)(mRgb.b*100) , (int)(mBright));
        mNorm_bright = normBrightness(mBright, 0, 100);
    }

    if(mNorm)
        mBrightness->update(mNorm_bright);
    else
        mBrightness->update(mBright);

    
}

double MyColorSensor::normBrightness(double br,double min, double max)
{
    double grayLevel = (max+min)/2.0;

    double rate = (br-grayLevel)/(max-grayLevel);
    if(rate>1.0) rate=1.0;
    if(rate<-1.0) rate=-1.0;
    
    return rate;
}

double MyColorSensor::normColor(double br,double min, double max)
{
    double rate = (br-min)/(max-min);
    if(rate>1.0) rate=1.0;
    if(rate<0) rate=0;

    return rate*100;
}

void MyColorSensor::getHSV(rgb_f_t rgb, hsv_t& hsv)
{
    double r = rgb.r;
    double g = rgb.g;
    double b = rgb.b;
               
    double mr = mMin_R;
    double mg = mMin_G;
    double mb = mMin_B;
    
    double h=0, s=0, v=0;

    /*
    if (r-0.5 < 0)
    {
        r = 0;
    }
    else
    {
        r = r - 0.5;
        r = r * 2;
    }

    if (g-0.5 < 0)
    {
        g = 0;
    }
    else
    {
        g = g - 0.5;
        g = g * 2;
    }

    if (b-0.5 < 0)
    {
        b = 0;
    }
    else
    {
        b = b - 0.5;
        b = b * 2;
    }
    */
    r = r + 30;
    g = g + 30;
    b = b + 30;
    
    if (r >= g && g >= b) { 
        
        if(r!=0)
            s = (r - b) / r;
        else 
            s=0;
        v = r;
        if(r==b)
            h=0;
        else if(s!=0)
            h = 60.0 * (g - b) / (r- b);
    }
    if (r >= b && b >= g)
    {
        v = r;
        if(r!=0)
          s = (r - g) / r;
        else 
            s=0;
        if(r==g)
            h=0;
        else if(s!=0)
            h = 60.0 * (g - b) / (r - g) + 360.0;
    }
    if (g >= r && r >= b)
    {
        v = g;
        if(g!=0)
            s = (g - b) / g;
        else 
            s=0;
        if(g==b)
            h=0;
        else if(s!=0)
            h = 60.0 * (b - r) / (g - b) + 120.0;
    }
    if (g >= b && b >= r)
    {
        v = g;
        if(g!=0)
            s = (g - r) / g;
        else 
            s=0;
        if(r==g)
            h=0;
        else if(s!=0)
            h = 60.0 * (b - r) / (g - r) + 120.0;
    }
    if (b >= r && r >= g)
    {
        v = b;
        if(b!=0)
            s = (b - g) / b;
        else
            s=0;
        if(g==b)
            h=0;
        else if(s!=0)
            h = 60.0 * (r - g) / (b - g) + 240.0;
    }
    if (b >= g && g >= r)
    {
        v = b;
        if(b!=0) 
            s = (b - r) / b;
        else
            s=0;
        
        if(r==b)
            h=0;
        else if(s!=0)
            h = 60.0 * (r - g) / (b - r) + 240.0;
    }

    hsv.h = h;
    hsv.s = s;
    hsv.v = v;

}

void MyColorSensor::setRGB()
{
    mColor->getRawColor(raw);
    //printf("raw.r = %d\n",raw.r);
    //printf("raw.g = %d\n",raw.g);
    //printf("raw.b = %d\n",raw.b);
    mMax_R = raw.r;
    mMax_G = raw.g;
    mMax_B = raw.b;
    //printf("r,g,b %d %d %d\n",mMax_R,mMax_G,mMax_B);
}

// debug用
rgb_raw_t MyColorSensor::getRgb()
{
    return raw;
}