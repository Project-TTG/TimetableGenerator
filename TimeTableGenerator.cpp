#include<iostream>
#include<cstdlib>
using namespace std;

//a timetable class to hold a timetable

class TimeTables
{
    public :
    int classTimeTable[6][7];

};

//inherited class Teachers for teacher timetables

class Teachers : public TimeTables
{

    //teacherIdentity is a unique identifier
    //teacherName Holds the name of the teacher
    //teacherIdentifierSetter is used to assign a unique integer to teacherIdentity
    static int teacherIdentifierSetter;

    protected :

    int teacherIdentity;
    char teacherName[30];

};


//inherited class ClassRooms for classroom timetables

class ClassRooms : public TimeTables
{

    //classIdentity is a unique identifier
    //classRoomName holds the name of the classRoom
    //classIdentifierSetter is used to assign a unique integer to classIdentity

    static int classIdentifierSetter;

    protected :

    int classIdentity;
    char classRoomName[10];

};

//Subjects is a class used to represent a subject

class Subjects : public Teachers,public ClassRooms
{

    //priority is the number of hours per week for a subject
    //subjectIdentity is a unique identifier for a subject
    //duration is the length of each class
    //subjectName holds the name of the subject
    //subjectIdentifierSetter is used to assign a unique integer to subjectIdentity

    static int subjectIdentifierSetter;

    protected :

    int priority,duration,subjectIdentity;
    char subjectName[50];
    int relativeClassRoom;

    //a method to allocate the created subject to a class

    void ClassRoomTimeTableAllocator(ClassRooms classRoom)
    {
        if(classRoom.classIdentity==relativeClassRoom)
        {

            int hoursPerDay,daysPerWeek;

            while(priority!=0)
            {

                for(daysPerWeek=0;daysPerWeek<6;daysPerWeek++)
                {

                    for(hoursPerDay=0;hoursPerDay<7;hoursPerDay++)
                    {

                            if(classRoom.classTimeTable[daysPerWeek][hoursPerDay]==NULL)
                            {
                                hoursPerDay+= rand()%4 ; //what does this line do?
                            }
                            else
                            {
                                while(classRoom.classTimeTable[daysPerWeek][hoursPerDay]!=NULL)
                                    hoursPerDay++;
                            }
                            classRoom.classTimeTable[daysPerWeek][hoursPerDay] = subjectIdentity;

                    }
                }
            }
        }
        else
        {
            cout<<"Irrelevant class room";
        }
    }
};

//temporary main function

int main()
{

return 0;

}
