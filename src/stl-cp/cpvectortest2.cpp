#include <iostream>
#include "stl-cp/vector2.h"
using namespace std;

int main() {
    CP::vector<int> v;
    cout << v.size() << endl;
    v.push_back(10);
    v.push_back(20);
    cout << v.size() << endl;
    for (auto i : v) {
        cout << i << endl;
    }
    v.clear();
}

