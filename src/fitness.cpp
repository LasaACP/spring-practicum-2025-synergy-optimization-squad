#include "fitness.h"
#include "schedule.h"

using namespace std;

int calculate_fitness(Schedule& sched) {
    int fitness_score = 0;
    LinkedList<string> students;
    sched.get_all_students(students);

    for (auto student = students.begin(); !student.finished(); student.next()) {
        if (const int number_of_cores = sched.get_number_of_student_cores(student.get()); number_of_cores < 4) {
            fitness_score -= 1000;
        }

        int i = 0;
        LinkedList<string> wishlist;
        sched.get_student_wishlist(student.get(), wishlist);
        for (auto wish = wishlist.begin(); !wish.finished(); wish.next()) {
            if (sched.is_student_in_course(wish.get(), student.get())) {
                fitness_score += 100 - i * 10;
            }
            ++i;
        }
    }

    return fitness_score;
}
