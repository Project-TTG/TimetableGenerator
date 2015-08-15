#include<iostream>
#include<cstdlib>
using namespace std;

//a timetable class to hold a timetable

class TimeTables
{
    public :
    int classTimeTable[6][7] ={{0}};

};

//inherited class Teachers for teacher timetables
// Teacher class for the purpose of "generating Teacher Schedules"

class Teachers : public TimeTables
{

    //teacherIdentity is a unique identifier "to identify the teacher"
    //teacherName Holds the name of the teacher
    //teacherIdentifierSetter is used to assign a unique integer to teacherIdentity
    
    static int teacherIdentifierSetter;            

    protected :

    // int teacherIdentity;
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

    // int classIdentity;
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
    //relativeClassRoom holds the indexes of the classes for which this subject is available
    //classRoomLoopVariable is a loop Variable use to access the relativeClassRooms

    static int subjectIdentifierSetter;

    protected :

    int priority,duration;
    // int subjectIdentity;
    char subjectName[50];
    int relativeClassRooms[10],classRoomLoopVariable;

    //a method to allocate the created subject to a class

    void ClassRoomTimeTableAllocator(ClassRooms classRoom)
    {
        //traversing trough the various Relevant Class rooms
        for(classRoomLoopVariable=0;relativeClassRooms[classRoomLoopVariable]!='\0';classRoomLoopVariable++)
        {
            //a safety measure to ensure that irrelevant classes don't get mixed up

            if(classIdentity==relativeClassRooms[classRoomLoopVariable])
            {

                int hoursPerDay,daysPerWeek;

                //to ensure that all classes have been filled with this subject

                while(priority!=0)
                {
                    //traversing through the array

                    for(daysPerWeek=0;daysPerWeek<6;daysPerWeek++)
                    {

                        for(hoursPerDay=0;hoursPerDay<7;hoursPerDay++)
                        {
                                //checking if there are free periods

                                if(classRoom.classTimeTable[daysPerWeek][hoursPerDay]==0)
                                {
                                    hoursPerDay+= rand()%7 ;    //picks a random hour from a day
                                }
                                else
                                {
                                    while(classRoom.classTimeTable[daysPerWeek][hoursPerDay]!=0)
                                        hoursPerDay++;  //in case the hour is not free
                                }
                                if(hoursPerDay<7)   //in case hoursPerDay ends up greater than 7 from the previous stateent
                                    classRoom.classTimeTable[daysPerWeek][hoursPerDay] = subjectIdentity;

                        }
                    }
                }
            }
            else
            {
                cout<<"Irrelevant class room";  //an error message to see what went wrong
            }
        }
    }
};

//temporary main function

int main()
{

return 0;

}
