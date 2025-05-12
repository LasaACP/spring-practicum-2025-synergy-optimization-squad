#pragma once

#include <string>
#include <vector>

using namespace std;

struct Student {
    string studentID; // Unique identifier
    vector<string> wishList; // 0 - Highest priority
    int grade;
};

struct Course {
    string name; // Name of course
    vector<int> student; // List of students in the class (represented by ID number)
    bool is_core; // True if core class
};

struct Period {
    vector<Course> listOfCourses; // List of courses in period
};
