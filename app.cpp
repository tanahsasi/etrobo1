#include <string.h>
#include <stdio.h>
#include <unistd.h>

// tag::walker_def[]
#include "app.h"
#include "util.h"

#include "Motor.h"

#include "Polling.h"
#include "MyColorSensor.h"
#include "Brightness.h"
#include "Length.h"
#include "TurnAngle.h"
#include "Odometry.h"
#include "HsvHue.h"
#include "HsvSatu.h"
#include "XPosition.h"
#include "YPosition.h"
#include "SimpleWalker.h"
#include "SpeedControl.h"
#include "LineTracer.h"
#include "VirCurveLine.h"
#include "VirStraightLine.h"
#include "TurnWalker.h"
#include "FileWalker.h"

#include "Process.h"
#include "Scene.h"
#include "MotorManager.h"
#include "JudgeReception.h"

using namespace ev3api;

int log_max=30000;
int log_idx=0;

double msg_logbuf[30000][10];


Motor       *gLeftWheel = new Motor(PORT_C,false,LARGE_MOTOR);
Motor       *gRightWheel = new Motor(PORT_B,false,LARGE_MOTOR);
Motor       *gArm = new Motor(PORT_A,true,LARGE_MOTOR);

Polling *gPolling;
MyColorSensor *gColor;
Brightness *gBrightness;
HsvHue *gHsvHue;
HsvSatu *gHsvSatu;

Odometry *gOdo;
Length *gLength;
TurnAngle *gTurnAngle;
XPosition *gXPosition;
YPosition *gYPosition;

SpeedControl *gSpeed;
SimpleWalker *gWalker;
LineTracer *gTracer;
VirCurveLine *gVirCLine;
VirStraightLine *gVirSLine;
TurnWalker *gTWalker;
FileWalker *gFile;

Scene *gScene;
Process *gProcess;

MotorManager *gMotor;


static void user_system_create() {

  gBrightness = new Brightness();
  gHsvHue = new HsvHue();
  gHsvSatu = new HsvSatu();

  gColor = new MyColorSensor(PORT_2,gBrightness,gHsvHue,gHsvSatu);
  gLength = new Length();
  gTurnAngle = new TurnAngle();
  gMotor = new MotorManager(gLeftWheel, gRightWheel);
  gXPosition = new XPosition();
  gYPosition = new YPosition();

  gOdo = new Odometry(gLeftWheel,gRightWheel,gLength,gTurnAngle,gXPosition,gYPosition);
  gSpeed = new SpeedControl(gOdo);  
  gWalker = new SimpleWalker(gOdo,gSpeed); 
  gTracer = new LineTracer(gOdo,gSpeed);
  gVirCLine = new VirCurveLine(gOdo,gSpeed);
  gVirSLine = new VirStraightLine(gOdo,gSpeed);
  gTWalker = new TurnWalker(gOdo,gSpeed);
  gFile = new FileWalker(gOdo);

  gPolling = new Polling(gColor,gOdo);
  gProcess = new Process();

  gScene = new Scene();

}
static void user_system_destroy() {

  delete gColor;
  delete gPolling;
}


void main_task(intptr_t unused) {
  user_system_create();

  sta_cyc(POLLING_CYC);
  sta_cyc(TRACER_CYC);

  slp_tsk();

  stp_cyc(POLLING_CYC);
  stp_cyc(TRACER_CYC);

  gLeftWheel->setPWM(0);
  gRightWheel->setPWM(0);

  ext_tsk();

  user_system_destroy();
}
// end::main_task[]

void polling_task(intptr_t unused) {

    gPolling->run();

    Measure *m = gBrightness;
    double br = m->getValue(); 
    double len = gLength->getValue();
    double turn = gTurnAngle->getValue();
    double h = gHsvHue->getValue();
    double s = gHsvSatu->getValue();
    double x = gXPosition->getValue();
    double y = gYPosition->getValue();

    rgb_raw_t rgb = gColor->getRgb();
    static char buf[100];
    //sprintf(buf,"len , bri,H,S r,g,b, turn, v : %3.3f,  %7.4f,  %5.1f, %3.2f, %d,%d,%d  , %4.2f, %4.2f \n",len,br,h,s,  rgb.r, rgb.g,rgb.b ,turn,v);
    //msg_log(buf);
    //printf("h,s %f,,%f\n", h,s);
    //�?:138, �?色:39, 赤:353, �?:214
    //printf("br,,%f\n", br);

    ext_tsk();
}

void tracer_task(intptr_t unused) {

#if defined(MAKE_SIM)

    if(ev3_button_is_pressed(BACK_BUTTON)) 
    {
        wup_tsk(MAIN_TASK);  // 左ボタン押下でメインを起こす
    }
#else
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    if(ev3_touch_sensor_is_pressed(EV3_PORT_1) == 1) 
    {
      wup_tsk(MAIN_TASK);
    }
#endif
    else{

    // とりあえずここで、アー�?の固定。設計に基づ�?て変えるべ�?
    int arm_cnt = gArm->getCount();
   // syslog(LOG_NOTICE,"%d",arm_cnt);
    int diff = -50 - arm_cnt;
#if defined(MAKE_SIM)
    gArm->setPWM(diff*4.0);
#endif

    gScene->run();
  }

  ext_tsk();
}

extern bool mresult;
void count()
{
  int cn = 0;
  while(cn <= 400)
  {
    //printf("%d\n", cn);
    //sleep(100);
    cn = cn + 1;
  }
  mresult = true;
}
int cnt = 0;
int app_flag = 0;
JudgeReception * mJr;

void judge_task(intptr_t unused) {
  //printf("task\n");
  char pipe[256];
  FILE * fp;
  //printf("rec = %d\n",rec);
  if(cnt == 0)
  {
    printf("app_flag=%d\n", app_flag);
    if(app_flag == 0)
    {
      count();
      fp = fopen("/home/pi/work/RasPike/sdk/workspace/etrobo2023_A/BlockPipe2","rw");
      app_flag = 1;
      printf("BlockPipe2\n");
      fgets(pipe, 11, fp);
    }
  }
  else
  {
    printf("app_flag=%d\n", app_flag);
    printf("SnapPipe2\n");
    //fp = fopen("/home/pi/work/RasPike/sdk/workspace/etrobo2023_A/SnapPipe2", "r");
    //fgets(pipe, , fp);
    //fclose(fp);
    if(app_flag == 0)
    {
      count();
      fp = fopen("/home/pi/work/RasPike/sdk/workspace/etrobo2023_A/SnapPipe2", "rw");
      printf("SnapPipe2\n");
      fgets(pipe, 2, fp);
      printf("count\n");
    }
    
    
    /*while(!strcmp(pipe,"") == 0)
    {
      fgets(pipe, 2, fp);
    }*/
  }
  
  
  //読み込んだ1行を画面に出力す�?
  printf("%s\n", pipe);
  mJr->reception(pipe);
  
  cnt++;
  printf("cnt=%d\n",cnt);
  fclose(fp);
  app_flag = 0;
  ext_tsk();
}