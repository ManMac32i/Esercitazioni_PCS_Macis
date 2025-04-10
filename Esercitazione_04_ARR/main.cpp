# include <fstream>
# include "src/Utils.hpp"

using namespace std;

int main()
{
    ifstream file("data.txt");
    ofstream results("results.txt");
    setup_output_file(file,results);

    return 0;
}