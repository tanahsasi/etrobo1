#include "MotorManager.h"
#include "Walker.h"

extern Motor *gLeftWheel;
extern Motor *gRightWheel;
double mTime =0.0;

MotorManager::MotorManager(Motor *left, Motor *right):
	mLeftMotor(left),
	mRightMotor(right)
{
}
void MotorManager::setPwm(int left,int right)
{
	int setleft;
	int setright;
	
	current_lmotor = mLeftMotor->getCount();
	current_rmotor = mRightMotor->getCount();
	
	if(left != 0)
	{
		if(current_lmotor == prev_lmotor)
		{
			if(mlCount >= 200)
			{
				if(current_lmotor >= 0)
				{
					setleft = 100;
				}
				else
				{
					setleft = -100;
				}
			} 
			else
			{
				mlCount = mlCount + 1.0;
			}
		}
		else
		{
			//prev_lmotor = current_lmotor;
			mlCount = 0.0;
		}
	}

	if(right != 0)
	{
		if(current_rmotor == prev_rmotor)
		{
			if(mrCount >= 200)
			{
				if(current_rmotor >= 0)
				{
					setright = 100;
				}
				else
				{
					setright = -100;
				}
			} 
			else
			{
				mrCount = mrCount + 1.0;
			}
		}
		else
		{
			//prev_rmotor = current_rmotor;
			mrCount = 0.0;
		}
	}


/*
	if(mlCount == 200 && mrCount == 200)
	{
		mLeftMotor->setPWM(90);
		mRightMotor->setPWM(90);
		while(mTime < 20)
		{
			printf("AAAAAA\n");
			//mLeftMotor->setPWM(90);
			//mRightMotor->setPWM(90);
			mTime = mTime + 1.0;
		}
		mTime = 0.0;
	}
	else  
	{
		mLeftMotor->setPWM(left);
		mRightMotor->setPWM(right);
		//prev_lmotor = current_lmotor;
		//prev_rmotor = current_rmotor;
	}
*/

	//printf("BB\n");
	//mLeftMotor->setPWM(left);
	//mRightMotor->setPWM(right);
	


		if(mlCount == 200)
		{
			mLeftMotor->setPWM(setleft);
			printf("EMERGENCY!!\n");
		}
		else
		{
			mLeftMotor->setPWM(left);
		}

		if(mrCount == 200)
		{
			mRightMotor->setPWM(setright);
			printf("EMERGENCY!!\n");
		}
		else
		{
			mRightMotor->setPWM(right);
		}
		
	
	
	prev_lmotor = current_lmotor;
	prev_rmotor = current_rmotor;


		
	//mLeftMotor->setPWM(left);
	//mRightMotor->setPWM(right);

	//printf("left,,%d,,right,,%d\n", left,right);
}



