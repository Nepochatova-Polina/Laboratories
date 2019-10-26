#include <iostream>
#include <cmath>

using namespace std;

void Coordinates() {
    double firstRadius, secondRadius, firstCoordinateX, secondCoordinateX, firstCoordinateY, secondCoordinateY;
    cout << "Enter first radius:" << endl;
    cin >> firstRadius;
    cout << "Enter second radius:" << endl;
    cin >> secondRadius;

    cout << "Enter coordinates for first circle:" << endl;
    cin >> firstCoordinateX >> firstCoordinateY;

    cout << "Enter coordinates for second circle:" << endl;
    cin >> secondCoordinateX >> secondCoordinateY;

    double newX = (firstCoordinateX * firstRadius + secondCoordinateX * secondRadius) / (firstRadius + secondRadius);
    double newY = (firstCoordinateY * firstRadius + secondCoordinateY * secondRadius) / (firstRadius + secondRadius);
    printf("%lf\n, %lf\n", newX, newY);
}

void Traectory() {
    int radius, firstCoordinateX, lastCoordinateX, firstCoordinateY, lastCoordinateY, coordinateOfPointX, coordinateOfPointY, CoordinateX, CoordinateY, new_CoordinateY;
    cout << "Enter  radius:" << endl;
    cin >> radius;
    cout << "Enter first coordinates for line:" << endl;
    cin >> firstCoordinateX >> firstCoordinateY;
    cout << "Enter last coordinates for line:" << endl;
    cin >> lastCoordinateX >> lastCoordinateY;
    cout << "Enter coordinates of circle center :" << endl;
    cin >> CoordinateX >> CoordinateY;
    cout << "Enter coordinates of point:" << endl;
    cin >> coordinateOfPointX >> coordinateOfPointY;
    int length = ((CoordinateX * CoordinateX) - (coordinateOfPointX * coordinateOfPointX)) +
                 ((CoordinateY * CoordinateY) - (coordinateOfPointY * coordinateOfPointY));
    if (length < radius || length == radius) {
        int n = 1 / 2;
        for (int x = CoordinateX; x < lastCoordinateX; x += 2) {
            n += n;
            new_CoordinateY = length * n;
            printf("%d\n", new_CoordinateY);
        }
    }
} else {
    cout << "wrong type" << endl;
}

int main() {
    Coordinates();
    Traectory();
    return 0;
}
