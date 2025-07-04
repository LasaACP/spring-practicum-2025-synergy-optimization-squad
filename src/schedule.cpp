#include "schedule.h"
#include <algorithm>
#include <stdexcept>

using namespace std;

Schedule::Schedule() {
    for (auto & i : periods) {
        i = new Period();
    }
}

Schedule::~Schedule() {
    // TODO: Figure out why deallocation causes segfaults. MEMORY LEAKS!
    // for (const auto current_period : periods) {
    //     for (const auto&[fst, snd] : current_period->classes) {
    //         delete snd;
    //     }
    //     delete current_period;
    // }
    //
    // for (const auto&[fst, snd] : students) {
    //     delete snd;
    // }
}

void Schedule::add_class(const int period, const string &course_name, const bool is_core) const {
    Period* course_period = periods[period];
    auto* new_course = new Class{.name = course_name, .period = course_period, .is_core = is_core};
    course_period->classes.set(course_name, new_course);
}

void Schedule::add_student(const string& student_id) {
    auto* new_student = new Student{.student_id = student_id};
    students.set(student_id, new_student);
}

void Schedule::add_student_wish(const string& student_id, const string& course_name) {
    const auto student = students.get(student_id);
    student->wish_list.push_back(course_name);
}

void Schedule::add_student_to_class(const int period, const string& course_name, const string& student_id) {
    const auto student = students.get(student_id);
    const auto course = periods[period]->classes.get(course_name);
    course->students.push_back(student);
    student->schedule[period] = course;
}

void Schedule::get_all_students(LinkedList<string>& student_list) {
    for (auto i = students.begin(); !i.finished(); i.next()) {
        student_list.push_back(i.get()->key);
    }
}

int Schedule::get_number_of_student_cores(const string& student_id) {
    const auto student = students.get(student_id);

    int core_count = 0;
    for (const auto class_period : student->schedule) {
        if (class_period->is_core) ++core_count;
    }

    return core_count;
}

void Schedule::get_student_wishlist(const string &student_id, LinkedList<string>& wishlist) {
    auto new_wishes = students.get(student_id)->wish_list;
    wishlist.insert(new_wishes);
}

bool Schedule::is_student_in_class(const int period, const string& course_name, const string& student_id) {
    auto students_in_course = periods[period]->classes.get(course_name)->students;
    const auto student = students.get(student_id);
    return students_in_course.contains(student);
}

bool Schedule::is_student_in_course(const string& course_name, const string& student_id) {
    for (int i = 0; i < NUM_PERIODS; ++i) {
        if (is_student_in_class(i, course_name, student_id)) {
            return true;
        }
    }
    return false;
}
