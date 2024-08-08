mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
	util.o \
	Measure.o \
	Brightness.o \
	MyColorSensor.o \
	Polling.o \
	Length.o \
	TurnAngle.o \
	Odometry.o \
	HsvHue.o \
	HsvSatu.o \
	PID.o \
	SimpleWalker.o \
	SpeedControl.o \
	Walker.o \
	LineTracer.o \
	LowPassFilter.o \
	Scene.o \
	Section.o \
	SectionManager.o \
	SpeedSectionManager.o \
	MotorManager.o \
	Judge.o \
	JudgeLength.o \
	JudgeColor.o \
	JudgeTime.o \
	JudgeBrightness.o \
	JudgeTurnAngle.o \
	JudgeReception.o \
	XPosition.o \
	YPosition.o \
	TurnWalker.o \
	VirCurveLine.o \
	VirStraightLine.o \
	DoubleSection.o \
	BlockSection.o \
	Process.o \
	FileWalker.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += $(mkfile_path)app $(mkfile_path)unit $(mkfile_path)device $(mkfile_path)walker $(mkfile_path)section $(mkfile_path)judge $(mkfile_path)measure $(mkfile_path)communication
INCLUDES += \
	-I$(mkfile_path)app \
	-I$(mkfile_path)device \
	-I$(mkfile_path)walker \
	-I$(mkfile_path)section \
	-I$(mkfile_path)judge \
	-I$(mkfile_path)measure \
	-I$(mkfile_path)communication
	

# COPTS += -fno-use-cxa-atexit
COPTS += -std=c++11
