#include <fstream>
#include <iostream>

using namespace std;

int get_number(const int default_value) {
    string input;
    getline(cin, input);
    if (input.empty()) {
        return default_value;
    }
    return stoi(input);
}

int main() {
    ofstream file("input.json");

    // Core classes
    file << "{" << endl << "    \"cores\": [";
    cout << "how many cores? (default 4) ";
    int cores = get_number(4);

    for (int i = 0; i < cores-1; i++) {
        file << "\"Core" << i + 1 << "\", ";
    }
    file << "\"Core" << cores << "\"";
    file << "]," << endl;

    // Electives
    file << "\n    \"electives\": [";
    std::cout << "how many Electives? (default 6) ";
    int electives = get_number(6);

    for (int i = 0; i < electives-1; i++) {
        file << "\"Elective" << i + 1 << "\", ";
    }
    file << "\"Elective" << electives << "\"";
    file << "]," << endl;

    // Students
    file << "\n    \"students\": [";
    std::cout << "how many Students? (default 20) ";
    int students = get_number(20);

    std::cout << "how many desired electives per student? (default 4, be less than # of electives) ";
    int electives_per_student = get_number(4);

    for (int i = 0; i < students; i++) {
        if (i == 0) file << "\n        {\"id\":   " << i + 1 << ", \"courses\": [";
        else        file << ",\n        {\"id\":   " << i + 1 << ", \"courses\": [";
        int* electiveList =(int*)malloc(sizeof(int) * electives_per_student); // Array to electives
        for (int j = 0; j < electives_per_student; j++) {
            // Creates elective values for each student
            int randNum = rand() % electives + 1; // Generates a random number within random elective bounds
            bool alreadyThere = false;
            for (int k = 0; k < j; k++) {
                // Iterates through all already-generated indices
                if (randNum == *(electiveList + k)) {
                    // Checks the indices to make sure the same elective isn't generated twice
                    j--;
                    alreadyThere = true; // If the same number generated twice, repeat the generation
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

    file.close();
    return 0;
}
