#include "fitness.h"
#include "schedule.h"

using namespace std;

int calculate_fitness(Schedule& sched) {
    int fitness_score = 0;
    vector<string> students;
    sched.get_all_students(students);

    for (const string& student : students) {
        if (const int number_of_cores = sched.get_number_of_student_cores(student); number_of_cores < 4) {
            fitness_score -= 1000;
        }

        int i = 0;
        vector<string> wishlist;
        sched.get_student_wishlist(student, wishlist);
        for (const auto& wish : wishlist) {
            if (sched.is_student_in_course(wish, student)) {
                fitness_score += 100 - i * 10;
            }
            ++i;
        }
    }

    return fitness_score;
}
