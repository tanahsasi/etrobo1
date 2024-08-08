#ifndef _BLOCK_SECTION_H_
#define _BLOCK_SECTION_H_
#include "SectionManager.h"
#include "HackEv3.h"

class BlockSection : public SectionManager  
{  
    public:

        BlockSection();
        bool run();
        void course(int direct);
        void next_circle();
        void goal();
        void goal_turn();
        void move_block();
        void avoid_block();
        void in_block();
        void turn();
        void preparation_goal();

    protected:
        

#if defined(MAKE_RIGHT)
    const int _EDGE = LineTracer::LEFTEDGE;
    const int _OPPOSITION_EDGE = LineTracer::RIGHTEDGE;
#else
    const int _EDGE = LineTracer::RIGHTEDGE;
    const int _OPPOSITION_EDGE = LineTracer::LEFTEDGE;
#endif


    private:
        int now_position = -1;
        int red_position = 15;
        int blue_position1 = 9;
        int blue_position2 = 5;
        int course_flag;
        int set_flag=0;
        int count=0;
        int pattern=2;
        int tmp=0;
        int cm = 3;
        int num1=0;
        int CP=45;

        double tw = 60;
        double tp = 10;
        double ti = 20;
        double td = 2.5;

        enum color{
            RED,
            GREAN,
            BLUE,
            YELLOW
        };
        enum direction{
            front,
            behind,
            left,
            right,
            first
        };

        int position[7][16] =
                            {
                             {13,9,5,1,2,3,4,8,12,16,15,14,10,6,7,11},
                             {13,14,15,16,12,8,4,3,2,1,5,9,10,11,7,6},
                             {13,9,5,1,2,6,10,14,15,11,7,3,4,8,12,16},
                             {13,14,15,16,12,11,10,9,5,6,7,8,4,3,2,1},
                             {13,9,5,1,2,6,7,3,4,8,12,11,10,14,15,16},
                             {13,14,15,16,12,8,4,3,7,6,2,1,5,9,10,11},
                             {13,9,10,14,15,11,7,6,5,1,2,3,4,8,12,16}
                            };
        int position_edge[7][16] = 
                            {
                             {1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                             {-1,-1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                             {1,1,1,1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,-1},
                             {-1,-1,-1,1,1,1,1,-1,1,1,1,1,1,1,1,1},
                             {1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,1},
                             {-1,-1,-1,1,1,1,1,1,1,1,-1,-1,-1,1,1,1},
                             {1,-1,-1,1,1,1,1,1,-1,1,1,1,-1,-1,-1,-1}
                            };
        int position_angle[7][16] =
                            {
                             {-90,0,0,-90,0,0,-90,0,0,-90,0,-90,0,-90,-90,0},
                             {180,0,0,90,0,0,90,0,0,90,0,90,0,90,90,0},
                             {-90,0,0,-90,-90,0,0,90,90,0,0,-90,-90,0,0,0},
                             {180,0,0,90,90,0,0,-90,-90,0,0,90,90,0,0,0},
                             {-90,0,0,-90,-90,90,90,-90,-90,0,-90,0,90,90,0,0},
                             {180,0,0,90,0,0,90,90,-90,-90,90,90,0,90,0,0},
                             {-90,-90,-90,90,90,0,90,0,-90,-90,0,0,-90,0,0,0}
                            };

        direction goal_direction[7][16] =//最初のターン
                            {
                             {first,right,right,right,front,behind,behind,right,right,right,front,front,right,right,behind,right},
                             {first,front,behind,behind,left,left,left,front,front,behind,left,left,front,behind,left,front},
                             {first,right,right,right,front,right,right,right,behind,left,left,left,behind,right,right,right},
                             {first,front,behind,behind,left,front,front,behind,right,front,behind,behind,left,front,front,behind},
                             {first,right,right,right,front,right,behind,left,behind,right,right,front,front,left,behind,behind},
                             {first,front,behind,behind,left,left,left,front,right,front,right,behind,left,left,left,behind},
                             {first,right,front,left,behind,left,left,behind,behind,right,front,behind,behind,right,right,right}
                            };
        
        int goal_turn_direction[7][16] = //1 left   -1 right
                            {
                             {1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1},
                             {1,1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,-1},
                             {-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1},
                             {1,1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,-1,-1,1},
                             {1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1},
                             {1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,-1},
                             {1,1,1,1,-1,-1,-1,1,1,1,1,-1,-1,-1,-1,-1}
                            };
        int goal_pattern[7][16] = //1 pattern1   -1 pattern2
                            {
                             {1,1,1,1,1,1,-1,-1,-1,-1,1,1,1,1,1,1},
                             {1,1,1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1},
                             {1,1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1},
                             {1,1,1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,1,1},
                             {1,1,1,1,1,1,1,1,-1,-1,-1,-1,1,1,1,-1},
                             {1,1,1,-1,-1,-1,-1,1,1,1,1,1,1,1,1,1},
                             {1,1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1}
                            };
        color position_color[7][15]=
                            {
                             {BLUE,GREAN,GREAN,GREAN,YELLOW,YELLOW,YELLOW,RED,RED,RED,BLUE,BLUE,GREAN,YELLOW,RED},
                             {BLUE,RED,RED,RED,YELLOW,YELLOW,YELLOW,GREAN,GREAN,GREAN,BLUE,BLUE,RED,YELLOW,GREAN},
                             {BLUE,GREAN,GREAN,GREAN,GREAN,BLUE,BLUE,RED,RED,YELLOW,YELLOW,YELLOW,YELLOW,RED,RED},
                             {BLUE,RED,RED,RED,RED,BLUE,BLUE,GREAN,GREAN,YELLOW,YELLOW,YELLOW,YELLOW,GREAN,GREAN},
                             {BLUE,GREAN,GREAN,GREAN,GREAN,YELLOW,YELLOW,YELLOW,YELLOW,RED,RED,BLUE,BLUE,RED,RED},
                             {BLUE,RED,RED,RED,YELLOW,YELLOW,YELLOW,YELLOW,GREAN,GREAN,GREAN,GREAN,BLUE,BLUE,RED},
                             {BLUE,BLUE,BLUE,RED,RED,YELLOW,GREAN,GREAN,GREAN,GREAN,YELLOW,YELLOW,YELLOW,RED,RED}
                            };


        int move_pattern[7][16] = //1 left   -1 right    0 ketu
                            {
                             {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                             {1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
                             {1,1,1,1,1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1},
                             {1,1,-1,-1,-1,-1,1,1,1,1,-1,-1,-1,-1,1,1},
                             {1,1,1,1,1,-1,-1,0,1,1,1,-1,-1,-1,-1,-1},
                             {1,-1,-1,-1,-1,-1,-1,-1,1,1,0,-1,-1,-1,-1,-1,},
                             {1,1,1,-1,-1,1,0,1,1,1,-1,-1,1,1,1,1}
                            };

        SecParam RIn_Block[15] = {
            {Section::TWALKER,{-tw,tp,ti,td},Section::TURNANGLE,{55, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{10, Section::FLNONE}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 28, 2.5 ,1.2,1},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 25, 2.5 ,2.0,1},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 28, 2.5 ,1.2,1},Section::LENGTH,{5, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{-tw+10,tp,ti,td},Section::TURNANGLE,{105, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{38, 0.0, 50, 5, 4 ,0 , 0, _OPPOSITION_EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 28, 2.5 ,1.2,1},Section::LENGTH,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam LIn_Block[15] = {
            {Section::TWALKER,{tw,tp,ti,td},Section::TURNANGLE,{-55, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{10, Section::FLNONE}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 28, 2.5 ,1.2,1},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 25, 2.5 ,2.0,1},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 28, 2.5 ,1.2,1},Section::LENGTH,{5, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{tw+10,tp,ti,td},Section::TURNANGLE,{-105, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{38, 0.0, 50, 5, 4 ,0 , 0, _EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 28, 2.5 ,1.2,1},Section::LENGTH,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Move_Block_Left[10]={
            {Section::VIRSLINE,{-50, 0, 0, 28, 2.5 ,5,1},Section::LENGTH,{-0.5, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{-80,tp,ti,td},Section::TURNANGLE,{370,Section::RESETANG},Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 28, 4.5 ,5,1},Section::LENGTH,{4, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

	    SecParam Move_Block_Right[10]={
            {Section::VIRSLINE,{-50, 0, 0, 28, 2.5 ,5,1},Section::LENGTH,{-0.5, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{80,tp,ti,td},Section::TURNANGLE,{-373,Section::RESETANG},Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 28, 4.5 ,5,1},Section::LENGTH,{4, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Move_Block_Strate[10]={
            {Section::VIRSLINE,{45, 0, 0, 48, 2.5 ,5,1},Section::LENGTH,{15, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{-45, 0, 0, 48, 2.5 ,5,1},Section::LENGTH,{-15, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};


        SecParam Next_Blue_Circle[15]={
            //{Section::VIRSLINE,{40, 0, 0, 28, 2.5 ,1.2},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::TRACER,{40, 0.05, 48, 2.5, 5.0 ,0 , 0, _EDGE},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{CP, 0.05, 70, 28, 8.0 ,0 , 0, _EDGE},Section::LENGTH,{16, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{40, 0, 0, 48, 2.5 ,5.0,1},Section::COLOR,{204,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Next_Blue_Circle_OPPOSITION[15]={
            //{Section::VIRSLINE,{40, 0, 0, 28, 2.5 ,1.2},Section::LENGTH,{5, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::TRACER,{40, 0.05, 48, 2.5, 5.0 ,0 , 0, _EDGE},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{CP, 0.05, 70, 28, 8.0 ,0 , 0, _OPPOSITION_EDGE},Section::LENGTH,{17, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{40, 0, 0, 48, 2.5 ,5.0,1},Section::COLOR,{204,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Next_Red_Circle[15]={
            //{Section::VIRSLINE,{40, 0, 0, 28, 2.5 ,1.2},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{CP, 0.05, 70, 28, 8.0 ,0 , 0, _EDGE},Section::LENGTH,{17, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{40, 0, 0, 48, 2.5 ,5.0,1},Section::COLOR,{340,0.04, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Next_Red_Circle_OPPOSITION[15]={
            //{Section::VIRSLINE,{40, 0, 0, 28, 2.5 ,1.2},Section::LENGTH,{5, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{CP, 0.05, 70, 28, 8.0 ,0 , 0, _OPPOSITION_EDGE},Section::LENGTH,{17, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{40, 0, 0, 48, 2.5 ,5.0,1},Section::COLOR,{352,0.04, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Next_Grean_Circle[15]={
            //{Section::VIRSLINE,{40, 0, 0, 28, 2.5 ,1.2},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{CP, 0.05, 70, 28, 8.0 ,0 , 0, _EDGE},Section::LENGTH,{17, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{40, 0, 0, 48, 2.5 ,5.0,1},Section::COLOR,{141,0.18, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Next_Grean_Circle_OPPOSITION[15]={
            //{Section::VIRSLINE,{40, 0, 0, 28, 2.5 ,1.2},Section::LENGTH,{5, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{CP, 0.05, 70, 28, 8.0 ,0 , 0, _OPPOSITION_EDGE},Section::LENGTH,{17, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{40, 0, 0, 48, 2.5 ,5.0,1},Section::COLOR,{141,0.18, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Next_Yellow_Circle[15]={
            //{Section::VIRSLINE,{40, 0, 0, 28, 2.5 ,1.2},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{CP, 0.05, 70, 28, 8.0 ,0 , 0, _EDGE},Section::LENGTH,{17, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{40, 0, 0, 48, 2.5 ,5.0,1},Section::COLOR,{48,0.16, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Next_Yellow_Circle_OPPOSITION[15]={
            //{Section::VIRSLINE,{40, 0, 0, 28, 2.5 ,1.2},Section::LENGTH,{5, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{CP, 0.05, 70, 28, 8.0 ,0 , 0, _OPPOSITION_EDGE},Section::LENGTH,{17, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{40, 0, 0, 48, 2.5 ,5.0,1},Section::COLOR,{48,0.16, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam strate[5]={
            {Section::VIRSLINE,{45, 0, 0, 28, 2.5 ,1.2,1},Section::LENGTH,{8, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam right_turn[5]={
            {Section::VIRSLINE,{45, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{6.2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{55},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{3.8, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam left_turn[5]={
            {Section::VIRSLINE,{45, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{6.2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{-55},Section::TURNANGLE,{83, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{3.8, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Rbehind_turn[5]={
            {Section::TWALKER,{60,tp,ti,td},Section::TURNANGLE,{-165, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{37, 0, 48, 2.5 ,5,0 , 0, _EDGE},Section::LENGTH,{5, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{-37, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{-6, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Lbehind_turn[5]={
            {Section::TWALKER,{-60,tp,ti,td},Section::TURNANGLE,{165, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{40, 0, 48, 2.5 ,5,0 , 0, _OPPOSITION_EDGE},Section::LENGTH,{5, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{-37, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{-6, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Goal_left[5]={
            {Section::VIRSLINE,{70, 0, 0, 58, 2.5 ,3.2,1},Section::LENGTH,{4, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{70, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, 0, 0, 58, 2.5 ,3.2,1},Section::LENGTH,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Goal_right[10]={
            {Section::VIRSLINE,{70, 0, 0, 58, 2.5 ,3.2,1},Section::LENGTH,{4, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{55, -5, 28, 2.5 ,1.2},Section::TURNANGLE,{-80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, 0, 0, 58, 2.5 ,3.2,1},Section::LENGTH,{2, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::VIRSLINE,{55, 85, 0, 28, 2.5 ,1.2,0},Section::TURNANGLE,{85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Goal_front[5]={
            {Section::VIRSLINE,{70, 0, 0, 58, 2.5 ,3.2,1},Section::LENGTH,{12, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::VIRCLINE,{40, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam RGoal_behind[56]={
            {Section::VIRSLINE,{70, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65, -5, 28, 2.5 ,1.2},Section::TURNANGLE,{-180, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, 0, 0, 58, 2.5 , 5.2,1},Section::LENGTH,{6, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::VIRCLINE,{40, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam RGoal_13[56]={
            {Section::VIRSLINE,{70, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{3, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65, -5, 28, 2.5 ,1.2},Section::TURNANGLE,{-180, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{6, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::VIRCLINE,{40, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam LGoal_behind[6]={
            {Section::VIRSLINE,{70, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{180, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{6, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::VIRCLINE,{40, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam LGoal_13[6]={
            {Section::VIRSLINE,{70, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{3, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{180, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{6, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::VIRCLINE,{40, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Goal_turn_left[5]={
            {Section::VIRCLINE,{70, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{85, Section::RESETANG}, Section::EMNONE,{}},
            //{Section::VIRCLINE,{40, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Goal_turn_right[5]={
            {Section::VIRCLINE,{70, -5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            //{Section::VIRCLINE,{40, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
            //130,90,50,20
        SecParam RGoal_row1_P1[10]={
            {Section::VIRSLINE,{60, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{130, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,1},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,60},Section::TURNANGLE,{80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _OPPOSITION_EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam RGoal_row2_P1[10]={
            {Section::VIRSLINE,{65, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{90, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,1},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,60},Section::TURNANGLE,{-80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _OPPOSITION_EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam RGoal_row3_P1[7]={
            {Section::VIRSLINE,{65, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{50, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,1},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,60},Section::TURNANGLE,{-80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _OPPOSITION_EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam RGoal_row4_P1[7]={
            {Section::VIRSLINE,{65, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,1},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,60},Section::TURNANGLE,{-80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _OPPOSITION_EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam LGoal_row1_P1[10]={
            {Section::VIRSLINE,{65, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{130, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, -90, 0, 48, 2.5 ,5.0,0},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,-60},Section::TURNANGLE,{80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam LGoal_row2_P1[7]={
            {Section::VIRSLINE,{65, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{90, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,0},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,-60},Section::TURNANGLE,{80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam LGoal_row3_P1[7]={
            {Section::VIRSLINE,{65, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{50, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,0},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,-60},Section::TURNANGLE,{80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam LGoal_row4_P1[7]={
            {Section::VIRSLINE,{65, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,0},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,-60},Section::TURNANGLE,{80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam RGoal_row1_P2[15]={
            {Section::VIRSLINE,{60, -90, 0, 48, 2.5 ,5.0,0},Section::LENGTH,{110, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, -5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, -85, 0, 48, 2.5 ,5.0,0},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,60},Section::TURNANGLE,{-80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _OPPOSITION_EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam RGoal_row2_P2[15]={
            {Section::VIRSLINE,{60, -90, 0, 48, 2.5 ,5.0,0},Section::LENGTH,{70, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, -5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, -85, 0, 48, 2.5 ,5.0,0},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,60},Section::TURNANGLE,{-80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _OPPOSITION_EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam RGoal_row3_P2[15]={
            {Section::VIRSLINE,{60, -90, 0, 48, 2.5 ,5.0,0},Section::LENGTH,{40, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, -5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, -85, 0, 48, 2.5 ,5.0,0},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,60},Section::TURNANGLE,{-80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _OPPOSITION_EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam RGoal_row4_P2[15]={
            {Section::VIRSLINE,{60, -90, 0, 48, 2.5 ,5.0,0},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, -5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, -85, 0, 48, 2.5 ,5.0,0},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,60},Section::TURNANGLE,{-80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _OPPOSITION_EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam LGoal_row1_P2[15]={
            {Section::VIRSLINE,{60, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{115, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, -5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 85, 0, 48, 2.5 ,5.0,0},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,-60},Section::TURNANGLE,{80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam LGoal_row2_P2[15]={
            {Section::VIRSLINE,{65, 0, 0, 58, 2.5 ,5,1},Section::LENGTH,{80, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, -5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 85, 0, 48, 2.5 ,5.0,0},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,-60},Section::TURNANGLE,{80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam LGoal_row3_P2[15]={
            {Section::VIRSLINE,{65, 0, 0, 58, 2.5 ,5,1},Section::LENGTH,{40, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, -5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 48, 2.5 ,5.0,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 85, 0, 48, 2.5 ,5.0,0},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,-60},Section::TURNANGLE,{80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam LGoal_row4_P2[15]={
            {Section::VIRSLINE,{65, 0, 0, 58, 2.5 ,5.2,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, -5, 28, 2.5 ,1.2},Section::TURNANGLE,{-85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 0, 0, 58, 2.5 ,5.0,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{85, Section::RESETANG}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, 85, 0, 48, 2.5 ,5.0,0},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{10,-60},Section::TURNANGLE,{80, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0.0, 65, 8.5, 10.0 ,0 , 0, _EDGE},Section::COLOR,{203,0.08, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{100000, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
};
#endif
