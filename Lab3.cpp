#include <iostream>
#include <cmath>

using namespace std;

// 7
void Area() {
    // y = 2 * sin(angle)
    const double PI = 3.14;
    double firstAngle, secondAngle, angle1, angle2;
    double area;
    cout << "enter first angle from 0 to 360:" << endl;
    cin >> angle1;
    cout << "enter second angle from 0 to 360:" << endl;
    cin >> angle2;
    firstAngle = (angle1 * PI) / 180;
    secondAngle = (angle2 * PI) / 180;
    area = 0.5 * ((cos(firstAngle) * cos(firstAngle)) - (cos(secondAngle) * cos(secondAngle)));
    cout << area;
}

void Lagranz() {
    int number;
    double t;
    cout << "enter t:" << endl;
    cin >> t;
    cout << "enter a number of points:" << endl;
    cin >> number;
    double matrix[2][number];
    for (int j = 0; j < number; j++) {
        for (int i = 0; i < 2; i++) {
            cout << "enter element of first matrix";
            cin >> matrix[i][j];
        }
    }
    double sum = 0, calc = 1;
    for (int j = 0; j < number; j++) {
        for (int i = 0; i < 2; i++) {
            if (i != j) {
                calc = calc * (t - matrix[0][i]) / (matrix[0][j] - matrix[0][i]);
            }
        }
        sum = sum + matrix[1][j] * calc;
    }
    cout << sum;
}

int main() {
    Area();
    Lagranz();
    return 0;
}

