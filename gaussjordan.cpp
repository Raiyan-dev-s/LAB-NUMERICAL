#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    double a[20][21]; 

    cout << "Enter the augmented matrix (row by row):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
     
        double diag = a[i][i];
        if (diag == 0) {
            cout << "Mathematical error: Zero pivot element detected!\n";
            return 1;
        }
        for (int j = 0; j <= n; j++) {
            a[i][j] /= diag;
        }

       
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = a[k][i];
                for (int j = 0; j <= n; j++) {
                    a[k][j] -= factor * a[i][j];
                }
            }
        }
    }

  
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << a[i][n] << endl;
    }

    return 0;
}
