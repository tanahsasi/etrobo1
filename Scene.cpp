#include "Scene.h"
#include "MyColorSensor.h"


#include "ev3api.h"

extern MyColorSensor *gColor;
        
extern Brightness *gBrightness;

extern HsvHue *gHsvHue;

extern HsvSatu *gHsvSatu;

bool flag = false;

Scene::Scene():
    mState(UNDEFINED)
{

    gColor = new MyColorSensor(PORT_2,gBrightness,gHsvHue,gHsvSatu);
    mSsm = new SpeedSectionManager();
    mDs = new DoubleSection();
    mDs2 = new DoubleSection();
    mBs = new BlockSection();
    int mv = ev3_battery_voltage_mV();
    printf("%d\n",mv);
    printf("作った\n");
}

bool Scene::run()
{
    switch(mState) {
        case UNDEFINED:
            execUndefined();
            break;
        case CALIBRATION:
            execCalibration();
            break;
        case START:
            execStart();
            break;
        case SPEED:
            execSpeed();
            break;
        case DOUBLELOOP:
            execDoubleloop();
            break;
        case BLOCK:
            execBlock();
            break;
        /*
        case BINGO:
            execBingo();
            break;
        case GARAGE:
            execGarage();
            break;
        */
        case END:
            return true;
        default:
            return true;
    }
    return false;
}

void Scene::execUndefined()
{
    //printf("Undefined_Start\n");
    //mState=START;
    mState=CALIBRATION;
    printf("Undefined\n");

}

void Scene::execCalibration()
{
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    if(ev3_button_is_pressed(LEFT_BUTTON))
    {
        printf("left\n");
        mSsm->course(0);
        mDs->course(0);
        mDs2->scircle(0);
        mBs->course(0);
        gColor->setRGB();
        mState=START;
    }
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    if(ev3_button_is_pressed(RIGHT_BUTTON))
    {
        printf("right\n");
        mSsm->course(1);
        mDs->course(1);
        mDs2->scircle(1);
        mBs->course(1);
        gColor->setRGB();
        mState=START;
    }
    /*
    printf("Calibration_Start\n");
    gColor->setRGB();
#if defined(MAKE_SIM)
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    if (ev3_button_is_pressed(LEFT_BUTTON))
    {
        mState=START;
        printf("Calibration_Finish\n");
    }
#else
    if(ev3_button_is_pressed(LEFT_BUTTON))
    {
        mState=START;
        printf("Calibration_Finish\n");
    }
#endif
*/
}

void Scene::execStart()
{
    //printf("Start_Start\n");
    /*ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    if(ev3_button_is_pressed(LEFT_BUTTON))
    {
        printf("left\n");
        mSsm->course(0);
        mDs->course(0);
        gColor->setRGB();
    }
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    if(ev3_button_is_pressed(RIGHT_BUTTON))
    {
        printf("right\n");
        mSsm->course(1);
        mDs->course(1);
        gColor->setRGB();
    }*/

#if defined(MAKE_SIM)
// とりあえず動かすだけなので、設計に基づ�?て書き直そう
    //msg_log("Press Touch Button to start.");
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    if (ev3_touch_sensor_is_pressed(EV3_PORT_1) == 1)
    {
        printf("SPEED\n");
            mState=SPEED;
    }
#else
    if (ev3_button_is_pressed(ENTER_BUTTON))
    {
        printf("SPEED\n");
        mState=SPEED;
        //mState=DOUBLELOOP;
        //mState=BLOCK;
    }
#endif
//printf("Start_Finish\n");
}
void Scene::execSpeed()
{
    //printf("Speed_Start\n");
    if(mSsm->run()) {
        delete mSsm;
        //mState=DOUBLELOOP;
        //printf("speed終わった\n");
        mState = END;
    }
    //printf("Speed_Finish\n");
}
void Scene::execDoubleloop()
{
    printf("デブリ");
    if(flag != true)
    {
        if(mDs->run())
        {
            printf("大円終わった\n");
            delete mDs;
            delete mDs2;
            delete mBs;
            //flag = true;
            mState=END;
        }
    }
    else
    {
        if(mDs2->run())
        {
            printf("double終わった\n");
            delete mDs2;
            //mState=END;
            //mState=BLOCK;
        }
    }
}
void Scene::execBlock()
{
    if(mBs->run())
    {
        printf("block終わった\n");
        delete mBs;
        mState=END;
    }
}
/*void Scene::execBingo()
{

}
void Scene::execGarage()
{

}
*/