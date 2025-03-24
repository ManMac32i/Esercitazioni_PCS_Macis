# include <iostream>
# include <fstream>
# include <string>
# include <iomanip> // for the scientific notation

using std::cout;
using std::endl;

double map_values(double & num)
{
    // values
    int a = -1;
    int b = 2;

    int c = 1;
    int d = 5;

    double scaled_value = a + (b - a) * (num - c) / (d - c);
    return scaled_value;
}

int main()
{
    std::ifstream file("data.txt");
    std::ofstream results("results.txt"); // opens a file where I can write in

    if (!file || !results) {
        cout << "Error opening data.txt or results.txt" << endl; // if the file is not correctly opened 
    }
    
    /*
    ofstream results("results.txt", ios::app); to append into an existing file
    */

    unsigned int index = 1;
    double value = 0.0; 
    double number;

    // std::vector<double> values;
    results << "# N Mean \n";

    while (file >> number){
        value += map_values(number);
        results << index << " " << std::scientific << std::setprecision(16) << value / index << "\n";
        index++;
    }

    file.close();
    results.close();

    return 0;
}