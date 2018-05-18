#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include "RandomSet.h"
using namespace std;
class matrix {
    static char warning[];
    static char help[];
    unsigned _n;
    unsigned bit;
    unsigned score;
    RandomSet emptySet;
    void upDown(bool up);
    void leftRight(bool left);
    vector<vector<unsigned>> arr;
    bool fill();
public:
    matrix(unsigned);
    void print();
    bool handle(char order);
    unsigned getScore();
};

#endif // MATRIX_H
