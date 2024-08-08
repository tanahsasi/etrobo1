#ifndef _SPEED_SECTION_MANAGER_H_
#define _SPEED_SECTION_MANAGER_H_
#include "SectionManager.h"
#include "HackEv3.h"

class SpeedSectionManager : public SectionManager {
    public:

        SpeedSectionManager();
        void course(int direct);

        
    protected:
#if defined(MAKE_RIGHT)
    const int _EDGE = LineTracer::LEFTEDGE;
#else
    const int _EDGE = LineTracer::RIGHTEDGE;
#endif

    


    private:
        double tw = 60;
        double tp = 10;
        double ti = 20;
        double td = 2.5;

//こっちが実行されている
#if SP == 1
        SecParam Lcourse12[30] = {
            /*
            {Section::VIRSLINE,{60, 30, 0, 28, 2.5 ,1.2,1},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 40, 0, 25, 2.5 ,2.0,1},Section::BRIGHTNESS,{-0.25, Section::FLNONE}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 50, 0, 28, 2.5 ,1.2,1},Section::LENGTH,{5, Section::RESETLEN}, Section::EMNONE,{}},
            */
            {Section::TRACER,{90, 0, 9.9, 28, 4.6 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{288, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 13, 30, 4.5 ,17 , 0, 'LEFTEDGE'},Section::LENGTH,{323, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{90, 0, 9.9, 28, 4.6 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{503, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 14, 30, 4.5 ,17, 0, 'LEFTEDGE'},Section::LENGTH,{538, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 28, 4.6 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{550, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 9.9, 28, 4.6 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{650,Section::FLNONE}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, -20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{50, 0.05, 43, 4.5, 6.0 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{100,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{50, 0.05, 43, 4.5, 6.0 ,0 , 0, 'LEFTEDGE'},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, 70, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{10000, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, -55, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{40, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, 50, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{40, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
            
        SecParam Rcourse12[60] = {
            {Section::TRACER,{90, 0, 9.9, 28, 4.7 , 0, 0, _EDGE},Section::LENGTH,{288, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 13, 30, 4.5 ,-17 , 0, _EDGE},Section::LENGTH,{323, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{90, 0, 9.9, 28, 4.6 ,0 , 0, _EDGE},Section::LENGTH,{503, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 14, 30, 4.6 ,-17 , 0, _EDGE},Section::LENGTH,{530, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,-17 , 0, _EDGE},Section::LENGTH,{550, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{100, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{40,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60,-70, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{200, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65, 5, 28, 2.5 ,1.2},Section::TURNANGLE,{60, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{400, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60,-25, 0, 3.0,1},Section::TURNANGLE,{-60, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-5, 0, 2 ,1},Section::TURNANGLE,{-30, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-15, 0, 2 ,1},Section::TURNANGLE,{-60, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-15, 0, 2 ,1},Section::LENGTH,{-60, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-20, 0, 2 ,1},Section::LENGTH,{-100, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{70, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{40,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{70, Section::RESETLEN}, Section::EMNONE,{}},
            /*
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,-4 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{24, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{90,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, -70, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60,  55,  0, 28, 2.5 ,5.0,1},Section::LENGTH,{35, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, -50, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, -60, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, -50, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{25, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, -50, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{15, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, -20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{30,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60, -30, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{13, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{30,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{30,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{90,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{352,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, 60, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{15, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{50, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{10,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{352,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, 90, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{90,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, -90, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{10,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{50, -90, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{10, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            */
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Lcourse1[30] = {
            {Section::TWALKER,{-70,0,0,0},Section::TIME,{60, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::TWALKER,{-tw,tp,ti,td},Section::LENGTH,{40, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{50, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Rcourse1[30] = {
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{85, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{40,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60,-70, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{250, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{-tw,0,0,0},Section::TURNANGLE,{60, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60,-20, 0, 3.0,1},Section::TURNANGLE,{-9, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{70,0,0,0},Section::TURNANGLE,{-75, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{5000, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{-70,0,0,0},Section::TURNANGLE,{65, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{3, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-15, 0, 2 ,1},Section::TURNANGLE,{-30, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{3, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-15, 0, 2 ,1},Section::LENGTH,{70,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{40, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-15, 0, 2 ,1},Section::LENGTH,{70,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{40, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{40,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{70, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Lcourse2[30] = {
            {Section::VIRCLINE,{60,-60, 0,   2.0,    1},Section::LENGTH,{100, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{70, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Rcourse2[30] = {
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{85, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{40,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60,-70, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{250, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{-tw,0,0,0},Section::TURNANGLE,{60, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60,-20, 0, 3.0,1},Section::TURNANGLE,{-30, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{70,0,0,0},Section::TURNANGLE,{-60, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{5000, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{-70,0,0,0},Section::TURNANGLE,{50, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{3, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-16, 0, 2 ,1},Section::TURNANGLE,{-30, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{3, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-15, 0, 2 ,1},Section::LENGTH,{70,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{40, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-15, 0, 2 ,1},Section::LENGTH,{70,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{40, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{40,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{70, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Lcourse3[30] = {
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Rcourse3[30] = {
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{85, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{40,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{60,-70, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{250, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{-tw,0,0,0},Section::TURNANGLE,{60, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{60,-20, 0, 3.0,1},Section::TURNANGLE,{-60, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{70,0,0,0},Section::TURNANGLE,{-60, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{5000, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TWALKER,{-70,0,0,0},Section::TURNANGLE,{50, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{3, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-16, 0, 2 ,1},Section::TURNANGLE,{-30, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{3, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-15, 0, 2 ,1},Section::LENGTH,{70,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{40, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRCLINE,{65,-15, 0, 2 ,1},Section::LENGTH,{70,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{40, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{40,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{60, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{70, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Lcourse4[30] = {
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Rcourse4[30] = {
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{90,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Lcourse5[30] = {
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Rcourse5[30] = {
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{90,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Lcourse6[30] = {
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Rcourse6[30] = {
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{90,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Lcourse7[30] = {
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Rcourse7[30] = {
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{90,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Lcourse8[30] = {
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Rcourse8[30] = {
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{90,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Lcourse9[30] = {
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        
        SecParam Rcourse9[30] = {
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{90,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Lcourse10[30] = {
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Rcourse10[30] = {
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{90,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Lcourse11[30] = {
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        
        SecParam Rcourse11[30] = {
            {Section::TRACER,{80, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{80, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{70, 20, 0, 28, 2.5 ,5.0,1},Section::LENGTH,{20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::LENGTH,{90,Section::RESETLEN}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0.05, 43, 4.5, 6.0 ,0 , 0, _EDGE},Section::COLOR,{210,0.20, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        #endif

#if SP == 2
        SecParam Lcourse[30] = {
            {Section::TRACER,{70, 0, 9.9, 27, 4.55 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{288, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0, 13, 30, 4.5 ,17 , 0, 'LEFTEDGE'},Section::LENGTH,{323, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 9.9, 27, 4.5 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{503, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0, 14, 30, 4.5 ,17, 0, 'LEFTEDGE'},Section::LENGTH,{538, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 9.9, 27, 4.5 ,0 , 0, 'LEFTEDGE'},Section::LENGTH,{550, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0, 9.9, 27, 4.5 ,0 , 0, 'LEFTEDGE'},Section::COLOR,{210,0.08, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{50, 0.05, 43, 4.5, 6.0 ,0 , 0, 'LEFTEDGE'},Section::TIME,{2, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 25, 2.5 ,2.0,1},Section::BRIGHTNESS,{30, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{50, 0.05, 43, 4.5, 6.0 ,0 , 0, 'LEFTEDGE'},Section::COLOR,{210,0.08, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 25, 2.5 ,2.0,1},Section::BRIGHTNESS,{30, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};

        SecParam Rcourse[30] = {
            {Section::TRACER,{70, 0, 9.9, 27, 4.55 , 0, 0, _EDGE},Section::LENGTH,{288, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0, 13, 30, 4.6 ,-17 , 0, _EDGE},Section::LENGTH,{323, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{503, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{65, 0, 14, 30, 4.6 ,-17 , 0, _EDGE},Section::LENGTH,{538, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{70, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::LENGTH,{550, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{55, 0, 9.9, 27, 4.5 ,0 , 0, _EDGE},Section::COLOR,{210,0.08, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::VIRSLINE,{45, 0, 0, 25, 2.5 ,2.0,1},Section::BRIGHTNESS,{30, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,0},Section::TIME,{1, Section::RESETLEN}, Section::EMNONE,{}},
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};
        #endif
};

#endif
