#include "fitnessFunction.h"
#include <iostream>

using namespace std;

bool contains(Course courses[], const string& target)
{
  for(int i=0; i<NUM_COURSES; i++)
    {
      if(courses[i].name == target)
        {
          return true;
        }
    }
  return false;
}

int fitnessFunction(Period schedule[])
{
  int fitnessScore= 0;
  Period firstPeriodCourseList= schedule[0];
  int numCourses= firstPeriodCourseList.size();
  
  for(int course=0; course<numCourses; course++)
    {
      Course course= firstPeriodCourseList[i];
      int numStudents= course.students.size();

      for(int student=0; student<numStudents; student++)
        {
          Student student= course.students[student];
          int numberOfCores=0;
          
          for(int i=0; i<8; i++)
            {
              if(student.schedule[i].is_core)
              {
                numberOfCores++;
              }
            }

          if(numberOfCores<4)
          {
            fitnessScore-=1000;
          }

          for(int i=0; i<student.wish_list.size(); i++)
            {
              if(contains(student.schedule, student.wish_list[i].name))
              {
                fitnessScore+=100-i*10;
              }
            }
        }  
    }
  
  return fitnessScore;
}