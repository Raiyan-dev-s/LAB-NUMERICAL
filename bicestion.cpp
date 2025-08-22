#include <bits/stdc++.h>
using namespace std;


double f(double x) {
    return x*x*x - x - 2.0;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

   
    double a = 1.0;          
    double b = 2.0;          
    double tol = 1e-6;       
    int    maxIter = 100;    

   
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

       
        if (fabs(fm) < tol || fabs(b - a) < tol) break;

        
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
         cout<<"Raiyan Hasan\n";
    cout<<"ID:2048\n";
    return 0;
}
