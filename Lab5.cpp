#include <iostream>
#include <stack>
#include <string>
#include "cmath"

using namespace std;

int main() {
    string exersice;
    stack<int> stackOfNumbers;
    stack<char> stackOfOperations;
    cout << "Enter your exersice" << endl;
    cin >> exersice;
    int a, b;
    char c;
    int priority = 1;
    char symb[exersice.length()+1];
    exersice.copy(symb, exersice.size() + 1);
    symb[exersice.length()] = '\0';
    int i = 0;
    do {
        if (isdigit(symb[i]) ) {
            int ia = symb[i] - '0';
            stackOfNumbers.push(ia);

        } else {
            if ((symb[i] == '+' && priority == 1) || (symb[i] == '-' && priority == 1)) {
                stackOfOperations.push(symb[i]);
                priority = 1;
            } else {
                if ((symb[i] == '*' && priority == 1) || (symb[i] == '/' && priority == 1)) {
                    stackOfOperations.push(symb[i]);
                    priority = 2;
                } else {
                    if ((symb[i] == '+' && priority == 2) || (symb[i] == '-' && priority == 2)) {
                        c = stackOfOperations.top();
                        stackOfOperations.pop();
                        b =( stackOfNumbers.top());
                        stackOfNumbers.pop();
                        a = (stackOfNumbers.top());
                        stackOfNumbers.pop();
                        switch (c) {
                            case '+':
                                a += b;
                                break;
                            case '-':
                                a -= b;
                                break;
                            case '*':
                                a *= b;
                                break;
                            case '/':
                                a /= b;
                                break;
                            case '^':
                                a = pow(a,b);
                                break;
                            default:
                                break;
                        }
                        stackOfNumbers.push(a);
                        stackOfOperations.push(symb[i]);
                    }
                }
            }
        }
        i++;
    } while (i < exersice.length());
    do{
        c = stackOfOperations.top();
        stackOfOperations.pop();
        b = stackOfNumbers.top();
        stackOfNumbers.pop();
        a = stackOfNumbers.top();
        stackOfNumbers.pop();
        switch (c) {
            case '+':
                a += b;
                break;
            case '-':
                a -= b;
                break;
            case '*':
                a *= b;
                break;
            case '/':
                a /= b;
                break;
            case '^':
                a = pow(a,b);
                break;
            default:
                break;
        }
        stackOfNumbers.push(a);
    }while(!stackOfOperations.empty());
    cout << "result =" << a;
}