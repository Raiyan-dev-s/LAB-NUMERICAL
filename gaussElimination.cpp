#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of variables: ";
    cin >> n;

    double a[20][21];

    cout << "Enter augmented matrix (coefficients + constant):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
       
        if (a[i][i] == 0) {
            int swapRow = i + 1;
            while (swapRow < n && a[swapRow][i] == 0) swapRow++;
            if (swapRow == n) {
                cout << "No unique solution exists.\n";
                return 0;
            }
            for (int k = 0; k <= n; k++) {
                swap(a[i][k], a[swapRow][k]);
            }
        }

     
        double pivot = a[i][i];
        for (int k = 0; k <= n; k++) {
            a[i][k] /= pivot;
        }

    
        for (int j = i + 1; j < n; j++) {
            double factor = a[j][i];
            for (int k = 0; k <= n; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

  
    double x[20];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i]; 
    }

    cout << "\nSolution:\n";
    
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << "\n";
    }
    cout<<"Raiyan Hasan\n";
    cout<<"ID:2048\n";
    return 0;
}
