#ifndef RANDOMSET_H
#define RANDOMSET_H
#include <vector>
#include <ctime>
#include <unordered_map>
using namespace std;
class RandomSet {
    unordered_map<unsigned, unsigned> dict;
    vector<unsigned> nums;
public:
    RandomSet();
    bool insert(unsigned k);
    bool remove(unsigned k);
    bool empty();
    unsigned getRandom();
};

#endif // RANDOMSET_H
