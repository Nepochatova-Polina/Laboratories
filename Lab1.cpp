#include <iostream>
#include "cmath"

using namespace std;


void ArmstrongNumber() {
    int number, sum, new_num, digits;
    int current[100];
    printf("N:");
    scanf("%d", &number);
    int precalcullated[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    if (number < 10) {
        for (int i = 0; i <= number; i++) {
            printf("%d\n", precalcullated[i]);
        }
    } else {
        if (number < 153) {
            for (int i = 0; i < 10; i++) {
                printf("%d\n", precalcullated[i]);
            }
        } else {
            for (int i = 0; i < 10; i++) {
                printf("%d\n", precalcullated[i]);
            }
            for (int i = 153; i < number; i++) {
                digits = 0;
                new_num = i;
                do {
                    current[++digits] = new_num % 10;
                    new_num /= 10;
                } while (new_num > 0);
                sum = 0;
                for (int j = 1; j <= digits; j++) {
                    sum += pow(current[j], digits);
                }
                if (sum == i) {
                    printf("%d\n", i);
                }
            }
        }
    }
}

void LongMultiplication() {
    int firstArrayIndex = 0, secondArrayIndex = 0, sum = 0;
    int firstNumber, secondNumber;
    printf("Enter first number:");
    scanf("%d", &firstNumber);
    printf("Enter second number:");
    scanf("%d", &secondNumber);
    int firstNumberArray[50];
    int secondNumberArray[50];
    do {
        firstNumberArray[firstArrayIndex++] = firstNumber % 10;
        firstNumber /= 10;
    } while (firstNumber > 0);
    do {
        secondNumberArray[secondArrayIndex++] = secondNumber % 10;
        secondNumber /= 10;
    } while (secondNumber > 0);
    for (int j = 0; j < secondArrayIndex; j++) {
        for (int i = 0; i < firstArrayIndex; i++) {
            int res = secondNumberArray[j] * firstNumberArray[i];
            int result = res * pow(10, i) * pow(10, j);
            sum += result;
        }
    }
    printf("%d\n", sum);
}

int main() {
    ArmstrongNumber();
    LongMultiplication();
    return 0;
}
