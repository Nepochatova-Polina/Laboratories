#include <iostream>
#include "cmath"

void stringToGray();

void arrayMove();

using namespace std;

int main() {
    stringToGray();
    arrayMove();
    return 0;
}

void stringToGray() {
    int number;
    cout << "Enter number of elements in string:" << endl;
    cin >> number;
    int inputString[number];
    int outputString[number];
    for (int i = 0; i < number; i++) {
        inputString[i] = rand() % 2;
    }
    int count = 0;

    while (count < number) {
        if (((inputString[count] == 0 && (inputString[count] >> 1) == 0)) ||
            ((inputString[count] == 1 && (inputString[count] >> 1) == 1))) {
            outputString[count] = 0;
        } else {
            if ((((inputString[count] == 0 && (inputString[count] >> 1) == 1))) ||
                ((inputString[count] == 1 && (inputString[count] >> 1) == 0))) {
                outputString[count] = 1;
            }
        }
        count++;
    }
    for (int i = 0; i < number; i++) {
        cout << outputString[i];
    }
    cout << endl;
}

void arrayMove() {
    int number;
    cout << " Enter number of elements:" << endl;
    cin >> number;
    int firstArray[number];
    int secondArray[number];
    for (int i = 0; i < number; i++) {
        firstArray[i] = rand() % 100;
    }
    for (int i = 0; i < number; i++) {
        secondArray[i] = rand() % 100;
    }
    int numberOfSwap = 0;
    int temp = 0;

    for (int i = 0; i < number; i++) {
        for(int r = 0; r < number - i; r++) {
            if (firstArray[r] > firstArray[r + 1]) {
                temp = firstArray[r + 1];
                firstArray[r + 1] = firstArray[r];
                firstArray[r] = temp;
                numberOfSwap++;
            }
        }
    }
    int numberOfSwap2 = 0;
    for (int i = 0; i < number; i++) {
        for(int r = 0; r < number - i; r++) {
            if (secondArray[r] > secondArray[r + 1]) {
                temp = secondArray[r + 1];
                secondArray[r + 1] = secondArray[r];
                secondArray[r] = temp;
                numberOfSwap2++;
            }
        }
    }
    if (numberOfSwap == numberOfSwap2) {
        cout << numberOfSwap;
        for(int i = 0; i < number; i++){
            cout << firstArray[i];
        }
        cout << endl;
        for(int i = 0; i < number; i++){
            cout << secondArray[i];
        }
    } else {
        cout << "There are no such transposition";
    }
}
