#include <fstream>
#include <iostream>
#include <string>
#include "json/json.h"
#include "schedule.h"
#include "genetic.h"

using namespace std;

void read_input(Json::Value& root, const string& filename) {
    ifstream input_file(filename);
    if (input_file.is_open()) {
        input_file >> root;
    }
    input_file.close();
}

int main() {
    cout << "Synergy Scheduler 2025 Professional Edition" << endl;
    cout << "COPYRIGHT Synergy Systems LLC." << endl << endl;

    string in;
    cout << "Input filename [input.json]: ";
    getline(cin, in);
    string input_file = in;
    if (input_file.empty()) input_file = "input.json";

    cout << "Output filename [output.json]: ";
    getline(cin, in);
    string output_file = in;
    if (output_file.empty()) output_file = "output.json";

    Json::Value root;
    read_input(root, input_file);

    const Schedule schedule;
    generate_schedule(root, schedule);

    // TODO Output the schedule to JSON

    return 0;
}
