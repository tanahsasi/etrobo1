#ifndef _SECTION_MANAGER_H_
#define _SECTION_MANAGER_H_

#include "Section.h"

class SectionManager {
    public:


        typedef struct SecParam_
        {
            enum Section::WALKER_NO walker_no;
            double secList[100];

            enum Section::JUDGE_NO judge_no;
            double judList[100];

            enum Section::EMGJUDGE_NO emgjudge_no;
            double emgList[100];

        }SecParam;


        SectionManager();
        ~SectionManager();
        void set(SecParam* array);
        bool run();
        void addSection(Section *);
        void reset();
    
        

    protected:
#if defined(MAKE_RIGHT)
    const int _EDGE = LineTracer::LEFTEDGE;
#else
    const int _EDGE = LineTracer::RIGHTEDGE;
#endif

        Section *mSection[100];
        int mSectionIdx;
        int mLastIdx;  //�Ō�

        
        /*sample
        SecParam sample[10] = {
            //{Section::TRACER,{80, 0 ,  40, 1.5, 0.1 ,0 , 0, _EDGE},Section::LENGTH,{50, Section::FLNONE}, Section::EMNONE,{}},
            {Section::WALKER,{0,30},Section::TURNANGLE,{-70, Section::RESETANG}, Section::EMNONE,{}},
            {Section::WALKER,{0,-30},Section::TURNANGLE,{70, Section::RESETANG}, Section::EMNONE,{}},
            {Section::TRACER,{50, 0 ,  30, 0.3, 0.1 ,0 , 0, _EDGE},Section::LENGTH,{30, Section::RESETLEN}, Section::EMNONE,{}},
            //{Section::WALKER,{10,10},Section::TURNANGLE,{30}, Section::EMNONE,{},Section::FLNONE},
        
            {Section::WALKER,{0,0},Section::TURNANGLE,{10, Section::FLNONE}, Section::EMNONE,{}},
            {Section::TRACER,{50, 0 ,  30, 0.3, 0.1 ,0 , 0, _EDGE},Section::LENGTH,{100.0}, Section::EMNONE,{},Section::FLNONE},
            {Section::TRACER,{40, 0 ,  30, 0.3, 0.1 ,0 , 0, _EDGE},Section::LENGTH,{1000.0}, Section::EMNONE,{},Section::FLNONE},
            {Section::WALKER,{0,0},Section::LENGTH,{100,0}, Section::EMNONE,{},Section::FLNONE},

       
            {Section::WANONE,{},Section::JUNONE,{}, Section::EMNONE,{}}};


            //h , s �ԐF 353,0.74 �F�@210,0.83 �΁@137,0.55 ���F�@0~60,0.05
            //����̉E�����̒l
            */

    private:


};

#endif
