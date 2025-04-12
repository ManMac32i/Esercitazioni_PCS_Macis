# include <fstream>
# include <iostream>
# include <vector>

using namespace std;

string cut_commas(unsigned int& pointer, string& s)
{
    unsigned int location = s.find(',');
    s = s.substr(pointer, location);
    pointer = location;
    return s.substr(pointer + 1, s.length());
}

int analyze_Cell0_data(ifstream& file)
{
    string line;
    vector<int> Id, Marker;
    vector<double> X,Y;
    unsigned int location = 0;

    getline(file, line);

    while(getline(file, line))
    {
        Id.push_back(stoi(cut_commas(location, line)));
        Marker.push_back(stoi(cut_commas(location, line)));
        X.push_back(stod(cut_commas(location, line)));
        Y.push_back(stod(line));

        location = 0;
    }

    return 0;
}

int analyze_Cell2_data(ifstream& file)
{
    string line;
    vector<int> Id, Marker, Numvertices, Vertices, NumEdges, Edges;
    unsigned int location = 0;

    getline(file, line);

    while(getline(file, line))
    {
        Id.push_back(stoi(cut_commas(location, line)));
        Marker.push_back(stoi(cut_commas(location, line)));
        Marker.push_back(stoi(cut_commas(location, line)));
        Marker.push_back(stoi(cut_commas(location, line)));
        Marker.push_back(stoi(cut_commas(location, line)));
        Marker.push_back(stoi(line));

        location = 0;
    }

    return 0;
}