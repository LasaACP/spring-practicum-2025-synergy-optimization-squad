#pragma once

#include <string>
#include <unordered_map>
#include <vector>

constexpr int NUM_PERIODS = 8;

using namespace std;


/**
 * Represents a single schedule, combining all student, course, and period information into one structure.
 */
class Schedule {
    struct Student;
    struct Period;

    /** Represents a class, which is a course that's associated with a single period. */
    struct Class {
        // The unique identifier of the class' course. The same course can have multiple classes at different periods,
        // so multiple classes can have the same name assuming they're all in different periods.
        string name;

        Period* period; // The period this class is held
        vector<Student*> students; // A list of students in this classes
        bool is_core; // Whether this class represents a core course
    };

    /** Represents an individual student. There is a one-to-one relationship between a student and an instance of Student. */
    struct Student {
        string student_id; // Student identifier or unique name
        vector<string> wish_list; // A list of names of the student's requested courses, with element 0 being the most requested
        Class* schedule[NUM_PERIODS]; // The student's schedule
    };

    /** Represents a period (time of day when classes are held). */
    struct Period {
        unordered_map<string, Class*> classes; // All classes that occur in the current period.
    };

    // A list of all periods representing a "master" schedule
    Period *periods[NUM_PERIODS];
    // A mapping of students by ID for easy access
    unordered_map<string, Student*> students;

public:
    Schedule();
    ~Schedule();

    /** Adds a class at a given period, its course being `course_name`, and `is_core` representing whether it's a core course. */
    void add_class(int period, const string &course_name, bool is_core) const;

    /** Adds a new student. */
    void add_student(const string &student_id);

    /** Adds a new wish for the student. Later calls of the function for the same student correspond to lower priority wishes. */
    void add_student_wish(const string &student_id, const string &course_name);

    /** Adds a student to a given class. */
    void add_student_to_class(int period, const string &course_name, const string &student_id);

    /** Inserts all student IDs into `student_list`. */
    void get_all_students(vector<string> &student_list);

    /** Returns the number of core classes that a student is enrolled in. */
    int get_number_of_student_cores(const string &student_id);

    /** Inserts all the student's prioritized wishes into `wishlist`. */
    void get_student_wishlist(const string &student_id, vector<string> &wishlist);

    /** Returns true if the student is in a given course and period (class). */
    bool is_student_in_class(int period, const string &course_name, const string &student_id);

    /** Returns true if the student is in any of the periods for a given course. */
    bool is_student_in_course(const string &course_name, const string &student_id);
};
