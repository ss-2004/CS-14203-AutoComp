// Q5 31-01-23

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void modifyWrite(string str) {
    ofstream file;
    file.open("out.txt", ios::app);
    if (!file) cout << "FILE NOT FOUND!\n";
    else {
        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if (97 <= ch && ch <= 122)
                str[i] -= 32;
        }
        file << str;
    }
    file.close();
}

void reader() {
    string str;
    ifstream file("in.txt");
    while (getline(file, str)) {
        modifyWrite(str);
        modifyWrite("\n");
    }
    file.close();
}


int main() {
    reader();
    cout << "\nCompleted\n";
}