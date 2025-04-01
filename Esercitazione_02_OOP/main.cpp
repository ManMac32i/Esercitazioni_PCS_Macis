#include <iostream>
#include "complex.hpp"
using namespace std;


int main() {
    using comp = complex_number<double>;

    double value1 = 3.5;
    double value2 = -2.7;
    double value3 = 1.3;
    double value4 = 0.6;
    comp cn1(value1, value2);
    comp cn2(value3, value4);

    cout << "The First complex number is: " << cn1 << endl;
    cout << "The Second complex number is: " << cn2 << endl;
    cout << "The sum is: " << cn1 + cn2 << endl;
    cout << "The prodoct is: " << cn1 * cn2 << endl;

    comp cn3(0, value2);
    cn3 *= value1;
    cout << cn3 << endl;

    double value5 = 2.8;
    cout << value5 + cn3 << endl; 

    return 0;
}
