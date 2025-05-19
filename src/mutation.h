#include <vector>
#include "schedule.h"
#include "json/json.h"
#include "fitness.h"
#include <random>


using namespace std;

vector<Schedule> Mutation(vector<Schedule> schedules); //mutates schedules
vector<double> prob_helper(vector<Schedule> schedules);
vector<Schedule> genetic_crossover(vector<Schedule> genome);
//void move_student(Student stndt);take a student from one schedule and put it in a different schedule. doesn't matter if the first schedule is altered or not, we are probably going to be deleting it anyway.
