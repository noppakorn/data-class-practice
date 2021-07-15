#include "stl-cp/stackbyvector.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    CP::stack<int> s;
    s.push(2);
    cout << s.top() << endl;
}
