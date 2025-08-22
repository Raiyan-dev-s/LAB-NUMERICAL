#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x*x*x - x - 2; 
}


double f_prime(double x) {
    return 3*x*x - 1;  
}

int main() {
    double x0, tolerance;
    int maxIter;

    cout << "Enter initial guess: ";
    cin >> x0;

    cout << "Enter tolerance (e.g., 0.0001): ";
    cin >> tolerance;

    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    double x = x0;
    int iteration = 0;

    while (iteration < maxIter) {
        double fx = f(x);
        double fpx = f_prime(x);

        if (fabs(fpx) < 1e-10) {
            cout << "Derivative too small. Method failed." << endl;
            return 1;
        }

        double x_next = x - (fx / fpx);

        cout << "Iteration " << iteration + 1 
             << ": x = " << x_next 
             << ", f(x) = " << f(x_next) << endl;

        if (fabs(x_next - x) < tolerance) {
            cout << "\nRoot found: " << x_next << endl;
            return 0;
        }

        x = x_next;
        iteration++;
    }

    cout << "\nDid not converge within " << maxIter << " iterations." << endl;
    return 0;
}
