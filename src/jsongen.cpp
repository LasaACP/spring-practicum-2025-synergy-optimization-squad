#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ofstream file("input.json");
    // deciding cores
    file << "{" << endl << "    \"cores\": [";
    std::cout << "how many cores? (default 4)" << endl;
    int cores;
    std::cin >> cores;
    if (!cores) {
        cores = 4;
    }
    for (int i = 0; i < cores-1; i++) {
        file << "\"Core" << i + 1 << "\", ";
    }
    file << "\"Core" << cores << "\"";
    file << "]," << endl;
    // deciding electives
    file << "\n    \"electives\": [";
    std::cout << "how many Electives? (default 6)" << endl;
    int electives;
    std::cin >> electives;
    if (!electives) {
        electives = 6;
    }
    for (int i = 0; i < electives-1; i++) {
        file << "\"Elective" << i + 1 << "\", ";
    }
    file << "\"Elective" << electives << "\"";
    file << "]," << endl;
    // deciding students
    file << "\n    \"students\": [";
    int students;
    std::cout << endl << "how many Students? (default 20)" << endl;
    std::cin >> students;
    if (!students) {
        students = 20;
    }
    int electives_per_student;
    std::cout << endl << "how many desired electives per student? (default 4, be less than # of electives)" << endl;
    std::cin >> electives_per_student;
    if (!electives_per_student) {
        electives_per_student = 4;
    }
    for (int i = 0; i < students; i++) {
        if (i == 0) file << "\n        {\"id\":   " << i + 1 << ", \"courses\": [";
        else        file << ",\n        {\"id\":   " << i + 1 << ", \"courses\": [";
        int* electiveList =(int*)malloc(sizeof(int) * electives_per_student); // array to electives
        for (int j = 0; j < electives_per_student; j++) {
            // creates elective values for each student
            int randNum = rand() % electives + 1; // generates a random number within random elective bounds
            bool alreadyThere = false;
            for (int k = 0; k < j; k++) {
                // iterates through all already-generated indicies
                if (randNum == *(electiveList + k)) {
                    // checks the indicies to make sure the same elective isn't generated twice
                    j--;
                    alreadyThere = true; // if it is generated twice, repeat the generation
                }
            }
            if (alreadyThere) continue;
            if (j == electives_per_student-1) file << "\"Elective" << randNum << "\"";
            else file << "\"Elective" << randNum << "\", ";
            *(electiveList + j) = randNum;
        }
        delete electiveList;
        file << "]}";
    }

    file << "\n   ]\n}";
}