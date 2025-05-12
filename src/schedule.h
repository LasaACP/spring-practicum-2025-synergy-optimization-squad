#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student{
    string studentID; //"name" of student
    vector<string> wishList; // 0 - highest priority 
    int grade;
    struct Course schedule[8];
};

struct Course{
    int period;
    string name; //name of course
    vector<int> student; //list of students in the class (represented by ID number)
    bool ifCore; //True if core class
};

struct Period{
    vector<Course> listOfCourses; // list of courses in period
};

struct Period periods[8];
