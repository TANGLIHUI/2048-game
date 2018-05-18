#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "matrix.h"
using namespace std;

int main() {
    unsigned n = 1;
    char c = 'y';
    cout << "Welcome to 2048 game, enjoy it!!!  ^_^" << endl;
    while (c == 'y') {
        string s;
        c = ' ';
        while (n <= 1) {
            cout << "Please input the size of gird( > 1): " << endl;
            cin >> s;
            n=atoi(s.c_str());
        }getchar();
        matrix m(n);
        n = 1;
        bool g = true;
        while (g && cin >> s) {
            g = m.handle(s[0]);
        }
        cout << "Game over!!!\nFinal score: " << m.getScore() << endl;
        while (c != 'n' && c != 'y') {
            cout << "You want play it again ? (y / n)" << endl;
            cin >> s;
            c = tolower(s[0]);
        }
    }
    return 0;
}
