#include<iostream>
using namespace std;

//a timetable class to hold a timetable

class TimeTables
{

    int classTimeTable[7][6];

};

//inherited class Teachers for teacher timetables

class Teachers : public TimeTables
{

    //teacherIdentity is a unique identifier
    //teacherName Holds the name of the teacher

    static int teacherIdentity;
    char teacherName[30];

};


//inherited class ClassRooms for classroom timetables

class ClassRooms : public TimeTables
{

    //classIdentity is a unique identifier
    //classRoomName holds the name of the classRoom

    static int classIdentity;
    char classRoomName[10];

    void ClassRoomTimeTableAllocator()
    {

    }

};

//Subjects is a class used to represent a subject

class Subjects
{

    //priority is the number of hours per week for a subject
    //subjectIdentity is a unique identifier for a subject
    //duration is the length of each class
    //subjectName holds the name of the subject
    static int subjectIdentity;
    int priority,duration;
    char subjectName[50];

};

void main()
{



}
