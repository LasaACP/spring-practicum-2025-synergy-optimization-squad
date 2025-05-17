#include "mutation.h"
// in reality function is doing both the mutation and the natural selection for the program
vector<double> prob_helper(vector<Schedule> genome)
{
    vector<double> probs;
    vector<int> costs;
    int total;
    int c;

    for(Schedule s: genome)
    {
        c = calculate_fitness(s);//to be implemented in costs.cpp
        costs.push_back(c);
        total += c;
    }
    for(int i: costs)
    {
        probs.push_back(i/total);//returns percent of total cost value.
    }
    return probs;

}
/*alters individual students classes by replacing classes they are in with random classes they are not in*/
vector<Schedule> Mutation(vector<Schedule> genome) //mutates schedules
{
    vector<Schedule> mut_sch;// vector I will return that contains all the mutated schedules
    int pop = genome.size();//number of schedules
    Schedule temp_sch;
    double rand;
    
    return mut_sch;
}
/*makes a new list of schedules by combing students from the genome based on the relative fitness of those genomes*/
vector<Schedule> genetic_crossover(vector<Schedule> genome)
{
    vector<double> probs = prob_helper(genome);
    vector<Schedule> offspring;// vector I will return that contains all the mutated schedules
    int pop = genome.size();//number of schedules
    double sum = 0;
    int index = 0;
    Schedule temp_sch;
    double rand;
    uniform_real_distribution<double> urd(0,1);//distribution of real numbers from 0-1 
    default_random_engine dre;//this is how I am selecting a random number from urd
    vector<string> students;
    genome[0].get_all_students(students);
    for(int i = 0; i < pop; i++)
    {
        for(string s: students)
        {
            rand = urd(dre);//generates a random number
            for(double d: probs)
            {
                if(rand > sum)
                {
                    sum += d;
                    index++;
                }
                else
                {
                   break; 
                }
            }
            //offspring[i].move_student(genome[index], s) to be implemented takes a schedule and a student id and places that student in the new offspring.
            index = 0;
        }
    }
    return offspring;
}