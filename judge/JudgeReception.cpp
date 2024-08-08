#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "JudgeReception.h"

double rtime = 0;
bool mresult;
double wr;
double limtime;
int rec = 0;
int relength;
char * blo1;
char * blo2;
char * blo3;
char * ro;
char blo[2];
char zr[2];
char buffer[10];
int mcount = 0;
int redblo = 1;
int blueblo1 = 5;
int blueblo2 = 9;
int pat = 1;
int mini = 0;

JudgeReception::JudgeReception()
{
    
}

void JudgeReception::init()
{
   
    rtime = 0.0;
    mresult = false;
    act_tsk(JUDGE_TASK);
    //printf("wr = %d",wr);
    /*if(wr == 1)
    {
        printf("judgereception1\n");
        act_tsk(JUDGE_TASK);
    }*/
}

bool JudgeReception::judgement()
{
    measureTime();
    if(rtime > limtime || mresult == true)
    {
        printf("timeout\n");
        return true;
    }
    return false;
}

void JudgeReception::reception(char result[])
{
    rec = 0;
    if(rec == 0)
    {
        relength = strlen(result);
        printf("length = %d\n",relength);

        switch(relength)
        {
            case 10:
                blo1 = strtok(result,","); //赤ブロック
                printf("%s\n",blo1);
            
                blo2 = strtok(NULL,","); //青ブロック
                printf("%s\n",blo2);

                blo3 = strtok(NULL,",");
                printf("%s\n",blo3);

                ro = strtok(NULL,",");
                printf("%s\n",ro);
                relength = 4;
                break;
            case 9:
                blo1 = strtok(result,","); //赤ブロック
                printf("%s\n",blo1);
            
                blo2 = strtok(NULL,","); //青ブロック
                printf("%s\n",blo2);

                blo3 = strtok(NULL,",");
                printf("%s\n",blo3);
                relength = 3;
                break;
            case 6:
                blo1 = strtok(result,","); //赤ブロック
                printf("%s\n",blo1);
            
                blo2 = strtok(NULL,","); //青ブロック
                printf("%s\n",blo2);
                relength = 2;
                break;
            case 3:
                blo1 = strtok(result,","); //赤ブロック
                printf("%s\n",blo1);
                relength = 1;
                break;
        }
        

        for(int a=0; a<relength; a++)
        {
            switch (a){
                case 0:
                    strcpy(blo,blo1);
                    break;
                case 1:
                    strcpy(blo,blo2);
                    break;
                case 2:
                    strcpy(blo,blo3);
                    break;
                case 3:
                    strcpy(blo,ro);
                    break;
            }
        
            if (a != 3)
            {
                for(int a=0; a<=16; a++)
                {
                    if(a < 10)
                    {
                        strcpy(zr,"0");
                        sprintf(zr, "%s%d", zr, a);
                        //printf("zr = %s\n",zr);
                        //printf("blo = %s\n",blo);
                        if(strcmp(blo,zr) == 0)
                        {
                            printf("count1\n");
                            mcount++;
                            switch(mcount){ //ブロックの位置を格納
                                case RED:
                                    redblo = a;
                                    printf("red = %d\n",redblo);
                                    break;
                                case BLUE1:
                                    blueblo1 = a;
                                    printf("blue1 = %d\n",blueblo1);
                                    break;
                                case BLUE2:
                                    blueblo2 = a;
                                    printf("blue2 = %d\n",blueblo2);
                                    break;
                            }
                        }
                    }
                    else
                    {
                        sprintf(buffer, "%d", a);
                        if(strcmp(blo,buffer) == 0)
                        {
                            printf("count2\n");
                            mcount++;
                            switch(mcount){
                                case RED: //赤ブロックの位置
                                    redblo = a;
                                    printf("red = %d\n",redblo);
                                    break;
                                case BLUE1: //青ブロックの位置
                                    blueblo1 = a;
                                    printf("blue1 = %d\n",blueblo1);
                                    break;
                                case BLUE2:
                                    blueblo2 = a;
                                    printf("blue2 = %d\n",blueblo2);
                                    break;
                            }
                        }
                    }

                }
            }
            else
            {
                for(int b=1; b<9; b++)
                {
                    sprintf(buffer, "%d", b);
                    if(strcmp(blo,buffer) == 0)
                    {
                        mcount++;
                        pat = atoi(blo);
                        printf("pat = %d\n", pat);
                    }
                }
            }
            
            
        }

        if(mcount == 4)
        {
            mresult = true;
        }
        rec++;
        
    }
    else
    {
        mresult = false;
        
            if(strcmp(result,"1") == 0)
            {
                mresult = true;
                mini = atoi(result);
                printf("root = %d\n", mini);
                /*if(rec < 4)
                {
                    rec = 3;
                }*/

            }
            else
            {
                if(strcmp(result,"0") == 0)
                {
                    mresult = true;
                    //mini = atoi(result);
                    printf("root = %d\n", mini);
                }
            }
            rec++;
    }
    
}
void JudgeReception::measureTime()
{
    rtime = rtime + 1.0;
    //printf("rtime = %f\n",rtime);
}

void JudgeReception::setParam(double recn[])
{
    //wr = recn[0];
    //printf("wr = %d\n",wr);
    limtime = recn[1];
}