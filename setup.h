#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student{
    string studentID; //"name" of student
    vector<string> wishList[4]; // 0 - highest priority 
    int grade;
};

struct Course{
    string name; //name of course
    vector<int> student; //list of students in the class (represented by ID number)
    bool ifCore; //True if core class
};

struct Period{
    vector<Course> listOfCourses; // list of courses in period
};

struct Period periods[8];
struct Student student[20];
