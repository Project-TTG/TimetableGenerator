#include<iostream>
using namespace std;

//a timetable class to hold a timetable

class TimeTables
{
    protected :
    int classTimeTable[6][7];

};

//inherited class Teachers for teacher timetables

class Teachers : public TimeTables
{

    //teacherIdentity is a unique identifier
    //teacherName Holds the name of the teacher

    protected :
    int teacherIdentity;
    char teacherName[30];

};


//inherited class ClassRooms for classroom timetables

class ClassRooms : public TimeTables
{

    //classIdentity is a unique identifier
    //classRoomName holds the name of the classRoom
    protected :
    static int classIdentity;
    char classRoomName[10];

};

//Subjects is a class used to represent a subject

class Subjects : public Teachers,public ClassRooms
{

    //priority is the number of hours per week for a subject
    //subjectIdentity is a unique identifier for a subject
    //duration is the length of each class
    //subjectName holds the name of the subject

    protected :
    static int subjectIdentity;
    int priority,duration;
    char subjectName[50];

    void ClassRoomTimeTableAllocator()
    {

        int hoursPerDay,daysPerWeek;

        while(priority!=0)
        {
            for(daysPerWeek=0;daysPerWeek<6;daysPerWeek++)
            {

                for(hoursPerDay=0;hoursPerDay<7;hoursPerDay++)
                {
                        if(classTimeTable[daysPerWeek][hoursPerDay]==NULL)
                        {
                            hoursPerDay+=3;
                            classTimeTable[daysPerWeek][hoursPerDay] = subjectIdentity;
                        }
                        else
                        {
                            hoursPerDay++;
                        }
                }
            }
        }
    }
};

int main()
{

return 0;

}
