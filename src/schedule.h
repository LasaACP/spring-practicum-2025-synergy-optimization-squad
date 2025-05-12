#pragma once

#include <string>
#include <vector>

using namespace std;

struct Course {
    int period;
    string name; //name of course
    vector<int> students; //list of students in the class (represented by ID number)
    bool is_core; //True if core class
};

struct Student {
    string student_id; //"name" of student
    vector<string> wish_list; // 0 - highest priority
    int grade;
    Course schedule[8];
};

struct Period {
    vector<Course> courses; // list of courses in period
};
