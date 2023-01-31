// Shresth Sonkar
// 20214272
// Q1 a,b,c,d,e

#include <iostream>
#include <string>

using namespace std;

void q1a(string str) {
    cout << "DFA 1 : ";
    if (str.length() == 1 && str[0] == 'a') {
        cout << "Accepted\n" << endl;
    } else
        cout << "Rejected\n" << endl;
}

void q1b(string str) {
    cout << "DFA 2 : ";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a') {
            cout << "Accepted\n" << endl;
            return;
        }
    }
    cout << "Rejected\n" << endl;
}

void q1c(string str) {
    int a = 0;
    cout << "DFA 3 : ";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a') a++;
    }
    if (a <= 3)
        cout << "Accepted\n" << endl;
    else
        cout << "Rejected\n" << endl;
}

void q1d(string str) {
    int a = 0, b = 0;
    cout << "DFA 4 : ";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a') a++;
        else if (str[i] == 'b') b++;
    }
    if (a >= 1 && b == 2)
        cout << "Accepted\n" << endl;
    else
        cout << "Rejected\n" << endl;
}

void q1e(string str) {
    int a = 0, b = 0;
    cout << "DFA 5 : ";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a') a++;
        else if (str[i] == 'b') b++;
    }
    if (a == 2 && b > 2)
        cout << "Accepted\n" << endl;
    else
        cout << "Rejected\n" << endl;
}

int main() {
    string str;
    cout << "Enter a string : " << endl;
    cin >> str;

    q1a(str);
    q1b(str);
    q1c(str);
    q1d(str);
    q1e(str);

    return 0;
}
