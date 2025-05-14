#include "schedule.h"
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
    course_period->classes[course_name] = new_course;
}

void Schedule::add_student(const string& student_id) {
    auto* new_student = new Student{.student_id = student_id};
    students[student_id] = new_student;
}

void Schedule::add_student_wish(const string& student_id, const string& course_name) {
    const auto student = students[student_id];
    student->wish_list.push_back(course_name);
}

void Schedule::add_student_to_class(const int period, const string& course_name, const string& student_id) {
    const auto student = students[student_id];
    const auto course = periods[period]->classes[course_name];
    course->students.push_back(student);
    student->schedule[period] = course;
}
