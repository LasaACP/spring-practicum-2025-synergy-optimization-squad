#include <vector>
#include "schedule.h"
#include "json/json.h"
#include "fitness.h"
#include <random>


using namespace std;

vector<Schedule> Mutation(vector<Schedule> schedules); //mutates schedules
vector<double> prob_helper(vector<Schedule> schedules);//returns vector of doubles that I can use as my probability distribution
vector<Schedule> genetic_crossover(vector<Schedule> genome);
