#include <iostream>
#include "vector.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    CP::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << endl;
    }
    CP::vector<int> ss;
    ss = v;
    ss.push_back(7);
    for (auto i : v) cout << i << endl;
    for (auto i : ss) cout << i << endl;
}
