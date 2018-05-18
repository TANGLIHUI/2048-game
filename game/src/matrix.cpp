#include <iomanip>
#include <algorithm>
#include <iostream>
#include "matrix.h"
static unsigned len(unsigned n) {
    unsigned ans = 0;
    while (n) {
        ++ans;
        n /= 10;
    }
    return ans;
}
matrix::matrix(unsigned n): _n(n), bit(1), score(0) {
    arr = vector<vector<unsigned>>(n, vector<unsigned>(n, 0));
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j < n; ++j) {
            emptySet.insert(i * n + j);
        }
    }
    cout << help << endl;
    cout.fill(' ');
    fill();
    fill();
    print();
}
bool matrix::fill() {
    if (emptySet.empty()) return false;
    unsigned num = emptySet.getRandom();
    emptySet.remove(num);
    arr[num / _n][num % _n] = 2 * (rand() % 2 ? 2 : 1);
    return true;
}
bool matrix::handle(char order) {
    order = tolower(order);
    switch (order) {
    case 'u':
        upDown(true);
        break;
    case 'd':
        upDown(false);
        break;
    case 'l':
        leftRight(true);
        break;
    case 'r':
        leftRight(false);
        break;
    case 'h':
        cout << help << endl;
        return true;
    default:
        cout << warning << endl;
        cout << help << endl;
        return true;
    }
    if(!fill()) return false;
    print();
    return true;
}

void matrix::leftRight(bool left) {
    for (unsigned j = 0; j < _n; ++j) {
        vector<unsigned> num;
        for (unsigned i = 0; i < _n; ++i) {
            if (arr[j][i]) {
                num.push_back(arr[j][i]);
            }
        }
        if (!left) reverse(num.begin(), num.end());
        for (unsigned i = 1; i < num.size(); ++i) {
            if (num[i] == num[i - 1]) {
                num[i - 1] *= 2;
                bit = max(bit, len(num[i - 1]));
                score += num[i - 1];
                num[i] = 0;
            }
        }
        unsigned id = 0;
        for (unsigned i = 0; i < num.size(); ++i) {
            if (num[i]) {
                arr[j][left ? id : _n - id - 1] = num[i];
                emptySet.remove(j * _n + (left ? id : _n - id - 1));
                ++id;
            }
        }
        for (unsigned i = id; i < _n; ++i) {
            arr[j][left ? i : _n - i - 1] = 0;
            emptySet.insert(j * _n + (left ? i : _n - i - 1));
        }
    }
}
void matrix::upDown(bool up) {
    for (unsigned j = 0; j < _n; ++j) {
        vector<unsigned> num;
        for (unsigned i = _n; i > 0; --i) {
            if (arr[i - 1][j]) {
                num.push_back(arr[i - 1][j]);
            }
        }
        if (up) reverse(num.begin(), num.end());
        for (unsigned i = 1; i < num.size(); ++i) {
            if (num[i] == num[i - 1]) {
                num[i - 1] *= 2;
                bit = max(bit, len(num[i - 1]));
                score += num[i - 1];
                num[i] = 0;
            }
        }
        unsigned id = 0;
        for (unsigned i = 0; i < num.size(); ++i) {
            if (num[i]) {
                arr[up ? id : _n - id - 1][j] = num[i];
                emptySet.remove((up ? id : _n - id - 1) * _n + j);
                ++id;
            }
        }
        for (unsigned i = id; i < _n; ++i) {
            arr[up ? i : _n - i - 1][j] = 0;
            emptySet.insert(_n * (up ? i : _n - i - 1) + j);
        }
    }
}
void matrix::print() {
    for (unsigned i = 0; i < 3 * _n + 1 + _n * bit; ++i) cout << '-';
    cout << endl;
    for (unsigned i = 0; i < _n; ++i) {
        cout << "| ";
        for (unsigned j = 0; j < _n; ++j) {
            if (arr[i][j])
                cout << setw(bit) << arr[i][j];
            else {
                for (unsigned k = 0; k < bit; ++k) cout << ' ';
            }
            cout << " | ";
        }
        cout << endl;
        for (unsigned j = 0; j < 3 * _n + 1 + _n * bit; ++j) cout << '-';
        cout << endl;
    }
    cout << "score: " << score << endl;
}
unsigned matrix::getScore() {
    return score;
}
char matrix::warning[] = "Input error!!!!";
char matrix::help[] = "Please input one of these command:\n"
                      "\th(H): for help.\n"
                      "\tl(L): go left.\n"
                      "\tr(R): go right.\n"
                      "\tu(U): go up.\n"
                      "\td(D): do down.\n";
