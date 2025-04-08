#include <iostream>
#include <Eigen/Dense>
#include <iomanip>

using namespace std;
using namespace Eigen;


double err_rel(Vector2d& sol_found, Vector2d& sol_expec)
{
    double error = (sol_found - sol_expec).norm() / (sol_found).norm();
    return error;
}

Vector2d sol_Palu(const Matrix2d& A, const Vector2d& b)
{
    Vector2d sol_PALU = A.partialPivLu().solve(b);
    return sol_PALU;
}

Vector2d sol_QR(const Matrix2d& A, const Vector2d& b)
{
    Vector2d sol_QR = A.householderQr().solve(b);
    return sol_QR;
}

int main()
{
    double epsilon = 10e-15;
    Vector2d x(-1.0e+0,-1.0e+00);


    Matrix2d A1 {
		{5.547001962252291e-01, -3.770900990025203e-02},
		{8.320502943378437e-01, -9.992887623566787e-01},
	};
    Vector2d b1(-5.169911863249772e-01, 1.672384680188350e-01);

    if (abs(A1.determinant()) < epsilon) {
        cout << "Matrix A1 is singular" << endl;
    } else 
    {
        Vector2d res_PALU = sol_Palu(A1, b1);
        Vector2d res_QR = sol_QR(A1, b1);
        cout << "The solution of the first system with PALU is \n" << res_PALU << endl;
        cout << "The solution of the first system with QR is \n" << res_QR << endl;
        cout << "The relative error of QR is \n" << err_rel(res_QR, x) << endl;
        cout << "The relative error of PALU is \n" << err_rel(res_PALU, x) << endl;
    }

	Matrix2d A2 {
		{5.547001962252291e-01, -5.540607316466765e-01},
		{8.320502943378437e-01, -8.324762492991313e-01},
	};
	Vector2d b2(-6.394645785530173e-04, 4.259549612877223e-04);


    if (abs(A2.determinant()) < epsilon) {
        cout << "Matrix A2 is singular" << endl;
    } else 
    {
        Vector2d res_PALU = sol_Palu(A2, b2);
        Vector2d res_QR = sol_QR(A2, b2);
        cout << "The solution of the second system with PALU is \n" << res_PALU << endl;
        cout << "The solution of the second system with QR is \n" << res_QR << endl;
        cout << "The relative error of QR is \n" << err_rel(res_QR, x) << endl;
        cout << "The relative error of PALU is \n" << err_rel(res_PALU, x) << endl;
    }

	Matrix2d A3 {
		{5.547001962252291e-01, -5.547001955851905e-01},
		{8.320502943378437e-01, -8.320502947645361e-01},
	};
	Vector2d b3(-6.400391328043042e-10, 4.266924591433963e-10);


    if (abs(A3.determinant()) < epsilon) {
        cout << "Matrix A1 is singular" << endl;
    } else 
    {
        Vector2d res_PALU = sol_Palu(A3, b3);
        Vector2d res_QR = sol_QR(A3, b3);
        cout << "The solution of the third system with PALU is \n" << res_PALU << endl;
        cout << "The solution of the third system with QR is \n" << res_QR << endl;
        cout << "The relative error of QR is \n" << err_rel(res_QR, x) << endl;
        cout << "The relative error of PALU is\n" << err_rel(res_PALU, x) << endl;
    }
    return 0;
}
