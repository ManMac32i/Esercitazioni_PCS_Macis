# pragma once

# include <fstream>
# include <iostream>
# include <vector>

using namespace std;

string cut_commas(unsigned int& pointer, string& s);

int analyze_Cell01_data(ifstream& file);

int analyze_Cell2_data(ifstream& file);
