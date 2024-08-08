#include "Process.h"
#include "stdio.h"
#include "app.h"

extern void judge_task(intptr_t exinf);
extern int app_flag;

Process::Process()
{
}


void Process::writing1(int pass) //snap
{
    FILE * fp;
    printf("snappipe1\n");
    printf("app_flag=%d\n", app_flag);
    if(app_flag == 0)
    {
        printf("snap1\n");
        fp = fopen("/home/pi/work/RasPike/sdk/workspace/etrobo2023_A/SnapPipe", "w");
        printf("Popen\n");

        switch(pass)
        {
            case 0:
                fprintf(fp,"snapa\n");
                printf("snapa\n");
                break;
            case 1:
                fprintf(fp,"getsnap\n");
                printf("getsnap\n");
                break;
            case 2:
                fprintf(fp,"snapb\n");
                printf("snapb\n");
                break;
        }
    }

    printf("close\n");
    fclose(fp);
    app_flag = 0;
    printf("closed\n");
}

void Process::writing2(int pass) //Block
{
    FILE * fp;
    if(app_flag == 0)
    {
        fp = fopen("/home/pi/work/RasPike/sdk/workspace/etrobo2023_A/BlockPipe", "w");
        app_flag = 1;
        fprintf(fp,"socket!\n");
    }
    
    printf("close\n");
    fclose(fp);
    app_flag = 0;
    printf("closed\n");
}

void Process::writing3(int pass) //Iot
{
    FILE * fp;
    if(app_flag == 0)
    {
        printf("SPpipe1\n");
        fp = fopen("/home/pi/work/RasPike/sdk/workspace/etrobo2023_A/sp2", "w");
        printf("%d\n",fp);
        printf("SPpipe2\n");

        fputs("socket!",fp);
    }
    
    printf("SPpipe3\n");
    printf("close\n");
    fclose(fp);
    app_flag = 0;
    printf("closed\n");
}
