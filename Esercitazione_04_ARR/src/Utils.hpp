#pragma once

#include <fstream>

using namespace std;

double portfolio(double investment, double rate);
double value(double& initial_value, double& final_value);
int setup_output_file(ifstream& file, ofstream& results);
