#include <iostream>
#include "stl-cp/list.h"
using namespace std;

int main() {
    CP::list<int> l;
    l.push_back(10);
    l.push_back(11);
    l.push_back(12);
    l.push_back(13);
    l.push_back(14);
    l.push_back(15);
    l.push_back(16);
    l.push_back(17);
    l.push_back(18);
    cout << l.front() << endl;
    l.erase(l.begin());
    cout << l.front() << endl;
    cout << l.back() << endl;
}
