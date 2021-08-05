#include <iostream>
#include "priority_queue.h"
using namespace std;

int main() {
    CP::priority_queue<int> pq;
    pq.push(5);
    pq.push(10);
    cout << pq.top() << endl;
    pq.pop();
    pq.push(7);
    cout << pq.top() << endl;
    pq.pop();

    cout << pq.top() << endl;
    pq.pop();
}

