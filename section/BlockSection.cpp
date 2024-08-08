#include "BlockSection.h"
#include "Section.h"
BlockSection::BlockSection()
{
    mSectionIdx=0;
    mLastIdx=0;
    now_position=-1;
}

bool BlockSection::run()
{   
    if(now_position==0)
    {
        return true;
    }
    if(now_position == -1)
    {
        if(set_flag==0)
        {
            extern int redblo;
            extern int blueblo1;
            extern int blueblo2;
            extern int pat;

            printf("redblo,,%d\n", redblo);
            printf("blueblo1,,%d\n", blueblo1);
            printf("blueblo2,,%d\n", blueblo2);
            printf("pat,,%d\n", pat);

            //red_position = 70;
            //blue_position1 = 40;
            //blue_position2 = 30;
            //pattern = 7;


            if(pat != 0)
            {
                red_position = redblo;
                blue_position1 = blueblo1;
                blue_position2 = blueblo2;
                pattern = pat;
            }
            
            
            printf("set_block\n");
            if(course_flag==1)
            {
                set(RIn_Block);
            }
            else
            {
                set(LIn_Block);
            }
            set_flag=1;
        }
        else
        {
            in_block();
            //printf("in_block\n");
        }
        
    }
    else
    {
        if(red_position == now_position || count == 15)
        {
            switch(set_flag)
            {
                case 0:
                    switch(goal_direction[pattern-1][count])
                    {
                        case left:
                            if(course_flag==1)
                            {
                                printf("Goal_left\n");
                                set(Goal_left);
                            }
                            else
                            {
                                printf("Goal_right\n");
                                set(Goal_right);
                            }
                            break;
                        case right:
                            if(course_flag==1)
                            {
                                printf("Goal_right\n");
                                set(Goal_right);
                            }
                            else
                            {
                                printf("Goal_left\n");
                                set(Goal_left);
                            }
                            break;
                        case front:
                            printf("Goal_front\n");
                            set(Goal_front);
                            break;
                        case behind:
                            if(course_flag==1)
                            {
                                printf("RGoal_behind\n");
                                set(RGoal_behind);
                            }
                            else
                            {
                                printf("LGoal_behind\n");
                                set(LGoal_behind);
                            }
                            break;
                        case first:
                            if(course_flag==1)
                            {
                                printf("RGoal_behind\n");
                                set(RGoal_13);
                            }
                            else
                            {
                                printf("LGoal_behind\n");
                                set(LGoal_13);
                            }
                            break;
                    }
                    set_flag=1;
                    break;
                case 1:
                    preparation_goal();
                    break;
                case 2:
                    if(course_flag*goal_turn_direction[pattern-1][count]==1)
                    {
                        set(Goal_turn_left);
                    }
                    else
                    {
                        set(Goal_turn_right);
                    }
                    set_flag=3;
                    break;
                case 3:
                    goal_turn();
                    break;
                case 4:
                    tmp = (now_position-1)/4;
                    if(goal_pattern[pattern-1][count]==1)
                    {
                        switch(tmp)
                        {
                            case 0:
                                if(course_flag==1)
                                {
                                    set(RGoal_row4_P1);
                                }
                                else
                                {
                                    set(LGoal_row4_P1);
                                }
                                
                                break;
                            case 1:
                                if(course_flag==1)
                                {
                                    set(RGoal_row3_P1);
                                }
                                else
                                {
                                    set(LGoal_row3_P1);
                                }
                                break;
                            case 2:
                                if(course_flag==1)
                                {
                                    set(RGoal_row2_P1);
                                }
                                else
                                {
                                    set(LGoal_row2_P1);
                                }
                                break;
                            case 3:
                                if(course_flag==1)
                                {
                                    set(RGoal_row1_P1);
                                }
                                else
                                {
                                    set(LGoal_row1_P1);
                                }
                                break;
                        }
                    }
                    else
                    {
                        switch(tmp)
                        {
                            case 0:
                                if(course_flag==1)
                                {
                                    set(RGoal_row4_P2);
                                }
                                else
                                {
                                    set(LGoal_row4_P2);
                                } 
                                break;
                            case 1:
                                if(course_flag==1)
                                {
                                    set(RGoal_row3_P2);
                                }
                                else
                                {
                                    set(LGoal_row3_P2);
                                }
                                break;
                            case 2:
                                if(course_flag==1)
                                {
                                    set(RGoal_row2_P2);
                                }
                                else
                                {
                                    set(LGoal_row2_P2);
                                }
                                break;
                            case 3:
                                if(course_flag==1)
                                {
                                    set(RGoal_row1_P2);
                                }
                                else
                                {
                                    set(LGoal_row1_P2);
                                }
                                break;
                        }
                    }
                    set_flag=5;
                    break;
                case 5:
                    goal();
                    break;
            }

        }
        else
        {
            if(blue_position1 == now_position || blue_position2 == now_position)
            {
                if(set_flag==0)
                {
                    switch(course_flag*move_pattern[pattern-1][count])
		            {
                        case 0:
                            set(Move_Block_Strate);
                            break;
                        case 1:
                            set(Move_Block_Left);
                            break;
                        
                        case -1:
                            set(Move_Block_Right);
                            break;
                    }
                    /*
                    switch(course_flag*position_angle[pattern-1][count])
                    {
                        case 0:
                            set(Avoid_Block_Strate);
                            break;
                        case 90:
                            set(Avoid_Block_Left);
                            break;
                        
                        case -90:
                            set(Avoid_Block_Right);
                            break;
                    }*/
                    
                    set_flag=1;
                }
                else
                {
                    move_block();
                    //avoid_block();
                }
            }
            else
            {
                if(set_flag==0)
                {
                    //printf("position_angle = %d\n",position_angle[pattern-1][count]);
                    switch(course_flag*position_angle[pattern-1][count])
                    {
                        case 0:
                            printf("set_strate\n");
                            set(strate);
                            break;
                        case 90:
                            printf("set_left_turn\n");
                            set(left_turn);
                            break;
                        case 180:
                            printf("set_behind\n");
                            if(course_flag==1)
                            {
                                set(Rbehind_turn);
                            }
                            else
                            {
                                set(Lbehind_turn);
                            }
                            break;
                        case -180:
                            printf("set_behind\n");
                            if(course_flag==1)
                            {
                                set(Rbehind_turn);
                            }
                            else
                            {
                                set(Lbehind_turn);
                            }
                            break;
                        case -90:
                            printf("set_right_turn\n");
                            set(right_turn);
                            break;
                    }
                    set_flag=1;
                }
                if(set_flag==1)
                {
                    turn();
                }
                if(set_flag==2)
                {
                    switch(position_color[pattern-1][count])
                    {
                        case RED:
                        printf("set_Red\n");
                            if(course_flag*position_edge[pattern-1][count]==-1)
                            {
                                set(Next_Red_Circle);
                            }
                            else
                            {
                                set(Next_Red_Circle_OPPOSITION);
                            }
                            break;
                        case BLUE:
                            printf("set_Blue\n");
                            if(course_flag*position_edge[pattern-1][count]==-1)
                            {
                                set(Next_Blue_Circle);
                            }
                            else
                            {
                                set(Next_Blue_Circle_OPPOSITION);
                            }
                            break;
                        case GREAN:
                            printf("set_Grean\n");
                            if(course_flag*position_edge[pattern-1][count]==-1)
                            {
                                set(Next_Grean_Circle);
                            }
                            else
                            {
                                set(Next_Grean_Circle_OPPOSITION);
                            }
                            break;
                        case YELLOW:
                            printf("set_Yellow\n");
                            if(course_flag*position_edge[pattern-1][count]==-1)
                            {
                                set(Next_Yellow_Circle);
                            }
                            else
                            {
                                set(Next_Yellow_Circle_OPPOSITION);
                            }
                            break;
                    }

                    printf("set_next_circle\n");
                    set_flag=3;
                }
                if(set_flag==3)
                {
                    //printf("next_circle\n");
                    next_circle();
                }
                
            }

        }
    }
    return false;
}

void BlockSection::course(int direct)
{
    if(direct == 0)
    {
        //printf("left\n");
        course_flag = -1;
    }
    else
    {
        //printf("right\n");
        course_flag = 1;
    }
}

void BlockSection::next_circle()
{
    

    if(SectionManager::run())
    {
        count++;
        now_position=position[pattern-1][count];
        set_flag=0;
        
    }
}


void BlockSection::goal()
{

    if(SectionManager::run())
    {
        set_flag=0;
    }
}

void BlockSection::move_block()
{
    if(SectionManager::run())
    {
        if(blue_position1 == now_position)
        {
            blue_position1=-2;
        }
        else
        {
            blue_position2=-2;
        }
        set_flag=0;
    }
}

void BlockSection::avoid_block()
{
    if(SectionManager::run())
    {
        if(blue_position1 == now_position)
        {
            blue_position1=-2;
        }
        else
        {
            blue_position2=-2;
        }
        set_flag=0;
        count++;
    }
}

void BlockSection::in_block()
{
    if(SectionManager::run())
    {
        set_flag=0;
        now_position=13;
    }
}

void BlockSection::turn()
{
    if(SectionManager::run())
    {
        set_flag=2;
    }
}

void BlockSection::preparation_goal()
{

    if(SectionManager::run())
    {
        set_flag=2;
    }
}

void BlockSection::goal_turn()
{

    if(SectionManager::run())
    {
        set_flag=4;
    }
}

