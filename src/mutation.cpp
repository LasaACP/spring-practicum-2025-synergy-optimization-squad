#include "mutation.h"
LinkedList<double> prob_helper(LinkedList<Schedule> genome)
{
    LinkedList<double> probs;
    LinkedList<int> costs;
    double total = 0;
    double c = 0;

    for(auto s = genome.begin(); !s.finished(); s.next())
    {
        c = calculate_fitness(s.get());
        costs.push_back(c);
        total += c;
    }

    for(auto i = costs.begin(); !i.finished(); i.next())
    {
        probs.push_back((double)i.get()/total);//returns percent of total cost value.
    }
    return probs;

}
/*alters individual students classes by replacing classes they are in with random classes 
they are not in. For core classes I will simply swap the core class' location in the 
schedule*/
LinkedList<Schedule> Mutation(LinkedList<Schedule> genome) //mutates schedules
{
    LinkedList<Schedule> mut_sch;// vector I will return that contains all the mutated schedules
    LinkedList<string> students;
    int pop = genome.size();//number of schedules
    double rand = 0;
    uniform_int_distribution<int> uid(0,7);//7 or however many periods we have - 1
    default_random_engine dre;
    for(auto s = genome.begin(); !s.finished(); s.next())
    {
        s.get().get_all_students(students);
        for(auto str = students.begin(); !s.finished(); s.next())
        {

        }
        mut_sch.push_back(s.get());
    }
    return mut_sch;
}
/*makes a new list of schedules by combing students from the genome based on the relative fitness of those genomes*/
LinkedList<Schedule> genetic_crossover(LinkedList<Schedule> genome)// this could potentially be moved to genetic.cpp
{
    LinkedList<double> probs = prob_helper(genome);
    LinkedList<Schedule> offspring;// vector I will return that contains all the mutated schedules
    int pop = genome.size();//number of schedules
    double sum = 0;
    int index = 0;
    uniform_real_distribution<double> urd(0,1);//distribution of real numbers from 0-1 
    default_random_engine dre;//this is how I am selecting a random number from urd
    LinkedList<string> students;
    if(genome.empty())
    {
        return offspring;
    }
    genome.at(0).get_all_students(students);// the idea is that when I am making my new schedule I just add entire students
    for(int i = 0; i < pop; i++)
    {
        Schedule temp_schedule;
        //still need to have a way to combine schedules such that the balance of # of students per class is maintained.
        for(auto s = students.begin(); !s.finished(); s.next())
        {
            double rand = urd(dre);//generates a random number
            for(auto d = probs.begin(); !d.finished(); d.next())
            {
                if(rand > sum)
                {
                    sum += d.get();
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