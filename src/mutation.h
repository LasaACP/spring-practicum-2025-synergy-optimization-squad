#ifndef mutation.h
#define mutation.h

#include <vector>
#include "schedule.h"
#include "json.h"
#include "fitness.h"
#include <random>


using namespace std;

vector<Schedule> Mutation(vector<Schedule> schedules); //mutates schedules
vector<double> prob_helper(vector<Schedule> schedules);
vector<Schedule> genetic_crossover(vector<Schedule> genome);
//void move_student(Student stndt);

#endif