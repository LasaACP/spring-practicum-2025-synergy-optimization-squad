#pragma once

#include <string>
#include <vector>

constexpr int NUM_COURSES= 8;

bool contains(Course courses[], const std::string& target);

int fitnessFunction(Period schedule[]);