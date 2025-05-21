#include "schedule.h"
#include "json/json.h"

void generate_schedule(Json::Value& root, Schedule schedule) {
    int periodNumber = 0;
    //Put all the classes into the schedule
    for (const auto& core : root["cores"]) {
        schedule.add_class(periodNumber, core.asString(), true);
        periodNumber = (periodNumber + 1) % NUM_PERIODS;
    }

    for (const auto& elec : root["electives"]) {
        schedule.add_class(periodNumber, elec.asString(), false);
        periodNumber = (periodNumber + 1) % NUM_PERIODS;
    }
    //Add the students to the schedule
    for (const auto& student : root["students"]) {
        string studentId = student["id"].asString();
        schedule.add_student(studentId);

   
        for (auto& wish : student["courses"]) {
            schedule.add_student_wish(studentId, wish.asString());
        }
    }
    //Puts students in classes
    for (int periodIndex = 0; periodIndex < NUM_PERIODS; periodIndex++) {
        LinkedList<string> studentList;
        schedule.get_all_students(studentList);

        for (auto studentId = studentList.begin(); !studentId.finished(); studentId.next()) {
            string id = studentId.get();
            LinkedList<string> wishlist;
            schedule.get_student_wishlist(id, wishlist);

            bool assigned = false;

            // Put students in first available class from wishlist
            for (auto wish = wishlist.begin(); !wish.finished(); wish.next()) {
                string course = wish.get();  
                if (!schedule.is_student_in_course(course, id)) {
                    schedule.add_student_to_class(periodIndex, course, id);
                    assigned = true; 
                    break;  
                }
            }
        }
    }
}
