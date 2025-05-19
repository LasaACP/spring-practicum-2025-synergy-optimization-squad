#include "mutation.h"
vector<double> prob_helper(vector<Schedule> genome)
{
    vector<double> probs;
    vector<int> costs;
    double total = 0;
    double c = 0;

    for(Schedule s: genome)
    {
        c = calculate_fitness(s);
        costs.push_back(c);
        total += c;
    }
    for(int i: costs)
    {
        probs.push_back((double)i/total);//returns percent of total cost value.
    }
    return probs;

}
/*alters individual students classes by replacing classes they are in with random classes 
they are not in. For core classes I will simply swap the core class' location in the 
schedule*/
vector<Schedule> Mutation(vector<Schedule> genome) //mutates schedules
{
    vector<Schedule> mut_sch;// vector I will return that contains all the mutated schedules
    vector<string> students;
    int pop = genome.size();//number of schedules
    double rand = 0;
    uniform_int_distribution<int> uid(0,7);//7 or however many periods we have - 1
    default_random_engine dre;
    for(Schedule s: genome)
    {
        s.get_all_students(students);
        for(string str: students)
        {

        }
        mut_sch.push_back(s);
    }
    return mut_sch;
}
/*makes a new list of schedules by combing students from the genome based on the relative fitness of those genomes*/
vector<Schedule> genetic_crossover(vector<Schedule> genome)// this could potentially be moved to genetic.cpp
{
    vector<double> probs = prob_helper(genome);
    vector<Schedule> offspring;// vector I will return that contains all the mutated schedules
    int pop = genome.size();//number of schedules
    double sum = 0;
    int index = 0;
    uniform_real_distribution<double> urd(0,1);//distribution of real numbers from 0-1 
    default_random_engine dre;//this is how I am selecting a random number from urd
    vector<string> students;
    if(genome.empty())
    {
        return offspring;
    }
    genome[0].get_all_students(students);// the idea is that when I am making my new schedule I just add entire students
    for(int i = 0; i < pop; i++)
    {
        Schedule temp_schedule;
        //still need to have a way to combine schedules such that the balance of # of students per class is maintained.
        for(const string& s: students)
        {
            double rand = urd(dre);//generates a random number
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
            /*the way i structured this assumes that the students are already in order 
            in the schedules that make up the genome. all I need to do here is add the students
            one at a time to my temp_schedule. I think I have all the add functions I need, but 
            I also need get functions to retrieve all the relevant information from the parent
            schedule*/
            sum = 0;
            index = 0;
        }
        offspring.push_back(temp_schedule);
    }
    //for(Schedule sched: genome)//clear up space genome was taking up
    //{
    //    delete sched; //incomplete type. need to fix. maybe just needs to be implemented in schedule.cpp?
    //}
    //genome.clear();
    return offspring;
}