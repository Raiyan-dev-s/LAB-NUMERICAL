#include <iostream>
#include <cmath>
using namespace std;


double f(double x) {
   
    return x * x * x - x - 2;
}

int main() {
    double x0, x1, x2, f0, f1, f2;
    double tolerance;
    int maxIterations;

    cout << "Enter first guess (x0): ";
    cin >> x0;
    cout << "Enter second guess (x1): ";
    cin >> x1;
    cout << "Enter tolerance: ";
    cin >> tolerance;
    cout << "Enter maximum number of iterations: ";
    cin >> maxIterations;

    cout << "\nIteration\t x0\t\t x1\t\t x2\t\t f(x2)\n";

    for (int i = 1; i <= maxIterations; i++) {
        f0 = f(x0);
        f1 = f(x1);

       
        if (f1 - f0 == 0) {
            cout << "Error: Division by zero in iteration " << i << endl;
            return -1;
        }

        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);

        cout << i << "\t\t" << x0 << "\t" << x1 << "\t" << x2 << "\t" << f2 << endl;

        if (fabs(f2) < tolerance) {
            cout << "\nRoot found at x = " << x2 << " after " << i << " iterations." << endl;
            return 0;
        }

       
        x0 = x1;
        x1 = x2;
    }

    cout << "\nThe method did not converge after " << maxIterations << " iterations." << endl;
    return 0;
}
