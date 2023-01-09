#include <iostream>
#include <cmath>

using namespace std;

void clear(int** a, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] a[i];
    }
    delete[] a;
}

int det(int** a, int rows) {
    if (rows == 1)
        return a[0][0];
    else if (rows == 2)
        return a[0][0] * a[1][1] - a[0][1] * a[1][0];
    else {
        int d = 0;
        for (int k = 0; k < rows; k++) {
            int** m = new int* [rows - 1];
            for (int i = 0; i < rows - 1; i++) {
                m[i] = new int[rows - 1];
            }
            for (int i = 1; i < rows; i++) {
                int t = 0;
                for (int j = 0; j < rows; j++) {
                    if (j == k)
                        continue;
                    m[i - 1][t] = a[i][j];
                    t++;
                }
            }
            d += pow(-1, k) * a[0][k] * det(m, rows - 1);
            clear(m, rows - 1);
        }
        return d;
    }
}

void main() {
    int rows = 0;
    while (rows < 1)
    {
        cout << "Enter the size of the square matrix:\n";
        cin >> rows;
    }

    int** a = new int* [rows];
    for (int i = 0; i < rows; i++) {
        a[i] = new int[rows];
    }

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            cin >> a[i][j];
        }
    }

    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) 
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n" << "Found determinant: " << det(a, rows) << endl;

    clear(a, rows);
}