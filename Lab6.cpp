#include <iostream>
#include <fstream>
#include <utility>

using namespace std;

void currentStr(const string &basicString);

double SumOfNumbers(int array[]);

int main() {
    FILE *note1;
    string str, s;
    ifstream f("note1.txt");

    if (!f.is_open())
        perror("error while opening file");
    while (!f.eof()) {
        getline(f, s);
        str += s;
    }
    currentStr(str);

    f.close();

    int array[40];
    for (int &i : array) {
        i = rand() % 21 + (-10);
    }

    double result = SumOfNumbers(array);
    cout << "average =" << result;
    return 0;
}

void currentStr(const string &basicString) {
    string curStr = basicString;
    unsigned long curLength;
    string words[100];
    int count[100];
    string word;
    int uniqueWords = 0;
    bool exists;
    int pos;
    do {
        pos = curStr.find(' ');
        word = curStr.substr(0, pos);
        exists = false;
        for (int i = 0; i < uniqueWords; i++) {
            if (word == words[i]) {
                count[i]++;
                exists = true;
                break;
            }
        }
        if (!exists) {
            words[uniqueWords] = word;
            count[uniqueWords] = 1;
            uniqueWords++;
        }
        curLength = curStr.length() - pos;
        curStr = curStr.substr(pos + 1, curLength);
    } while (pos != -1);

    for (int i = 0; i < uniqueWords; i++) {
        if (count[i] > 1) {
            cout << words[i] << endl;
        }
    }
}


double SumOfNumbers(int array[]) {
    ofstream outstrm("note2.bin", ios::binary);
    if (!outstrm.is_open()) {
        perror("error while opening file");
    }
    for (int i = 0; i < 40; i++) {
        outstrm.write((char *) &array[i], sizeof(int));
    }
    outstrm.close();

    int result;
    int sum = 0, count = 0;
    int t[40];
    ifstream instrm("note2.bin", std::ios::binary);
    while (!instrm.eof()) {
        instrm.read((char *) t, sizeof(t));
    }
    instrm.close();

    for (int i : t) {
        if (i > 0) {
            sum += i;
            count++;
        }
    }
    result = sum / count;
    return result;
}
