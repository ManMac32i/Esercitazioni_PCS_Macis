# include <fstream>
# include <string>
# include <iomanip>
# include <vector>
# include "Utils.hpp"

using namespace std;

double portfolio(double investment, double rate)
{
    return (1 + rate) * investment;
}

double value(double& initial_value, double& final_value)
{
    return (final_value - initial_value)/initial_value;
}

int setup_output_file(ifstream& file, ofstream& results) 
{
    unsigned int location;
    double investment;
    unsigned int assets;
    double V = 0;
    string line;
    
    // Read and set investement
    getline(file, line);
    location = line.find(';');
    investment = stod(line.substr(location + 1, line.length()));
    // Read and set number of assets
    getline(file, line);
    location = line.find(';');
    assets = stod(line.substr(location + 1, line.length()));
    // skip unnecessary line
    getline(file, line);
    
    vector<double> rate(assets);
    vector<double> fraction(assets);
    double r;
    double w;
    unsigned int i = 0;

    while(getline(file, line))
    {
        location = line.find(';');
        w = stod(line.substr(0, location));
        r = stod(line.substr(location + 1, line.length()));
        rate[i] = r;
        fraction[i] = w;
        V += portfolio(w * investment, r);
        i ++;
    }

    results << "S  = " << fixed << setprecision(2) << investment;
    results << ", n = " << setprecision(0) << assets << endl;
    results << "w = [ ";
    for (double d : rate) 
    {
        results << setprecision(2) << d << " ";
    }
    results << "] \n";

    results << "r = [ ";
    for (double d : fraction) 
    {
        results << setprecision(2) << d << " ";
    }
    results << "] \n";

    results << "Rate of return of the portfolio: " << setprecision(4) << value(investment, V) << endl;
    results << "V: " << fixed << setprecision(2) << V << endl;
    return 0;
}