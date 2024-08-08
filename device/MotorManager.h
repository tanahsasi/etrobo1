#ifndef MOTORMANAGER_
#define MOTORMANAGER_

#include <math.h>
#include "util.h"

#include "Motor.h"
#include "Odometry.h"

class MotorManager
{
    public:
		MotorManager(Motor *left,
			Motor *right);

	void setPwm(int left,int right);
	void init();

	private:
		Motor *mLeftMotor;
		Motor *mRightMotor;

		int32_t current_lmotor;
		int32_t current_rmotor;
	
		int32_t prev_lmotor = 0;
		int32_t prev_rmotor = 0;

		double mlCount = 0;
		double mrCount = 0;

};

#endif
