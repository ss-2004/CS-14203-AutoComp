// Shresth Sonkar
// 20214272
// Q2 a,b,c

#include <iostream>
#include <string>

using namespace std;

void q2a(string str) {
    cout << "DFA 1 : ";
    if (str[0] == 'a' && str[1] == 'b')
        cout << "Accepted" << endl;
    else
        cout << "Rejected" << endl;
}

void q2b(string str) {
    cout << "DFA 2 : ";
    if (str[0] == 'b' && str[1] == 'a')
        cout << "Accepted" << endl;
    else
        cout << "Rejected" << endl;
}

void q2c(string str) {
    cout << "DFA 3 : ";
    if (str[0] == 'b' && str[1] == 'b')
        cout << "Accepted" << endl;
    else
        cout << "Rejected" << endl;
}

int main() {
    string str;
    cout << "Enter a string : " << endl;
    cin >> str;

    q2a(str);
    q2b(str);
    q2c(str);

    return 0;
}

