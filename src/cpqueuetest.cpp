#include "stl-cp/queue.h"
#include <iostream>
using namespace std;

int main() {
    CP::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
}


