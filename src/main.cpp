#include <iostream>
#include "json/json.h"

using namespace std;

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

}
