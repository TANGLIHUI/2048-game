#include "RandomSet.h"

RandomSet::RandomSet() {
    srand(time(0));
}

bool RandomSet::insert(unsigned k) {
    if (dict.count(k)) return false;
    dict[k] = nums.size();
    nums.push_back(k);
    return true;
}
bool RandomSet::remove(unsigned k) {
    if (!dict.count(k)) return false;
    nums[dict[k]] = nums.back();
    dict[nums.back()] = dict[k];
    dict.erase(k);
    nums.pop_back();
    return true;
}
unsigned RandomSet::getRandom() {
    return nums[rand() % nums.size()];
}
bool RandomSet::empty() {
    return nums.empty();
}
