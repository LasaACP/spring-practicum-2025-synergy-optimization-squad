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
    for (int i = 0; i < cores; i++) {
        file << "\"Core" << i + 1 << "\", ";
    }
    file << "]," << endl;
    // deciding electives
    file << "{" << endl << "    \"electives\": [";
    std::cout << "how many Electives? (default 6)" << endl;
    int electives;
    std::cin >> electives;
    if (!electives) {
        electives = 6;
    }
    for (int i = 0; i < electives; i++) {
        file << "\"Core" << i + 1 << "\", ";
    }
    file << "]," << endl;
    // deciding students
    file << "{" << endl << "    \"students\": [";
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
        if (i == 0) file << "       {\"id\":   " << i + 1 << ", \"courses\": [";
        else file << "," << endl << "       {\"id\":   " << i + 1 << ", \"courses\": [";
        int* electiveList; // array to electives
        for (int j = 0; j < electives_per_student; j++) {
            // creates elective values for each student
            int randNum = rand() % electives + 1; // generates a random number within random elective bounds
            for (int k = 0; k < j - 1; k++) {
                // iterates through all already-generated indicies
                if (randNum == *(electiveList + k)) {
                    // checks the indicies to make sure the same elective isn't generated twice
                    j--;
                    continue; // if it is generated twice, repeat the generation
                }
            }
            file << "\"Elective" << randNum << "\"";
            *(electiveList + j) = randNum;
        }
        delete electiveList;
        file << "]}";
    }

    file << "   ]" << endl << "}";
}
