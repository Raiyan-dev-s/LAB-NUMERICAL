#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;

    vector<vector<double>> a(n, vector<double>(n + 1));
    vector<double> x(n);

    cout << "Enter the augmented matrix (coefficients + constants):\n";
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
            swap(a[i], a[swapRow]);
        }

   
        for (int j = i + 1; j < n; j++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = i; k <= n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
        }
    }

    
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }

    
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x[i] << endl;
    }
    cout<<"Raiyan Hasan\n";
    cout<<"ID:2048\n";
    return 0;
}
