#ifndef mutation.h
#define mutation.h

#include <vector>
#include "schedule.h"
#include "json.h"
#include "cost.h"


using namespace std;

vector<Schedule> Mutation(vector<Schedule> schedules); //mutates schedules
vector<double> prob_helper(vector<Schedule> schedules);

#endif