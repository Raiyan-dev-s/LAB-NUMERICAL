#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double f(double x) {
    return x * x * x - x - 2; 
}

int main() {
    double a, b, c, fa, fb, fc;
    int maxIter;
    double tolerance;

    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter tolerance: ";
    cin >> tolerance;
    cout << "Enter maximum iterations: ";
    cin >> maxIter;

    fa = f(a);
    fb = f(b);

 
    if (fa * fb > 0) {
        cout << "Invalid interval! f(a) and f(b) should have opposite signs.\n";
        return 1;
    }

    cout << fixed << setprecision(6);
    cout << "\nIteration\t a\t\t b\t\t c\t\t f(c)\n";

    for (int i = 1; i <= maxIter; i++) {
      
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);

        cout << i << "\t\t " << a << "\t " << b << "\t " << c << "\t " << fc << "\n";

     
        if (fabs(fc) < tolerance) {
            cout << "\nRoot found: " << c << " after " << i << " iterations.\n";
            return 0;
        }

      
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    cout << "\nRoot after " << maxIter << " iterations is approximately: " << c << "\n";
    return 0;
}
