# include <iostream>
# include <fstream>
# include <string>
# include <iomanip>
# include <vector>

using namespace std;
using namespace Eigen;

double value(double& rate, double& investment)
{
    return (1 + rate) * investment;
}

int main()
{
    
    std::ifstream file("data.txt");
    std::ofstream results("results.txt");

    if (!file || !results) {
        cout << "Error opening data.txt or results.txt" << endl; // if the file is not correctly opened 
    }

    double investment;
    double assets;
    VectorXd rate;

    file >> investment;
    file >> assets;
    while(file )
    return 0;
}

