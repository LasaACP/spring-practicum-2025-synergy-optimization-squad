#include "mutation.h"

vector<double> prob_helper(vector<Schedule> genome)
{
    vector<double> probs;
    vector<int> costs;
    int total;
    int c;

    for(Schedule s: genome)
    {
        //c = cost(s);//to be implemented in costs.cpp
        costs.push_back(c);
        total += c;
    }
    for(int i: costs)
    {
        probs.push_back(i/total);//returns percent of total cost value.
    }
    return probs;

}
vector<Schedule> Mutation(vector<Schedule> genome) //mutates schedules
{
    vector<double> probs;
    vector<Schedule> mutated_schedules;
}
