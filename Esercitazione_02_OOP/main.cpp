#include <iostream>
#include "complex.hpp"
using namespace std;


int main() {
    using comp_d = complex_number<double>;
    using comp_f = complex_number<float>;

    /*DOUBLE*/

    double value1 = 3.5;
    double value2 = -2.7;
    double value3 = 1.3;
    double value4 = 0.6;
    comp_d cn1(value1, value2);
    comp_d cn2(value3, value4);

    cout << "The First complex number is: " << cn1 << endl;
    cout << "The Second complex number is: " << cn2 << endl;
    cout << "The sum is: " << cn1 + cn2 << endl;
    cout << "The prodoct is: " << cn1 * cn2 << endl;

    comp_d cn3(0, value2);
    cn3 *= value1;
    cout << cn3 << endl;

    double value5 = 2.8;
    cout << value5 + cn3 << endl; 

    /*FLOAT*/

    float num1 = 9.6;
    float num2 = -1.8;
    float num3 = 3.3;
    float num4 = 0.9;
    comp_f cn4(num1, num2);
    comp_f cn5(num3, num4);

    cout << "The First complex number is: " << cn4 << endl;
    cout << "The Second complex number is: " << cn5 << endl;
    cout << "The sum is: " << cn4 + cn5 << endl;
    cout << "The prodoct is: " << cn4 * cn5 << endl;

    comp_f cn6(0, num2);
    cn6 *= num3;
    cout << cn3 << endl;

    float num5 = 2.8;
    cout << num5 + cn6 << endl; 

    return 0;
}
