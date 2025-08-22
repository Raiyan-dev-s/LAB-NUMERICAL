#include <bits/stdc++.h>
using namespace std;

// Change this to your function:
double f(double x) {
    return x*x*x - x - 2.0;  // Example: root near x ≈ 1.521
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --- Inputs (you can hardcode these if you want) ---
    double a = 1.0;          // left endpoint
    double b = 2.0;          // right endpoint
    double tol = 1e-6;       // tolerance for |b - a| or |f(mid)|
    int    maxIter = 100;    // safety cap

    // --- Preconditions check ---
    double fa = f(a), fb = f(b);
    if (fa * fb > 0) {
        cerr << "Error: f(a) and f(b) must have opposite signs.\n";
        return 1;
    }

    cout.setf(std::ios::fixed);
    cout << setprecision(8);
    cout << "Iter\t     a\t\t     b\t\t    mid\t\t   f(mid)\n";

    double mid = a;
    for (int it = 1; it <= maxIter; ++it) {
        mid = (a + b) / 2.0;
        double fm = f(mid);

        cout << it << "\t" << a << "\t" << b << "\t" << mid << "\t" << fm << "\n";

        // Stop if small enough
        if (fabs(fm) < tol || fabs(b - a) < tol) break;

        // Keep the subinterval where the sign changes
        if (fa * fm < 0) {
            b = mid;
            fb = fm;
        } else {
            a = mid;
            fa = fm;
        }
    }

    cout << "\nApproximate root = " << mid
         << "  with f(root) = " << f(mid) << "\n";
    return 0;
}
