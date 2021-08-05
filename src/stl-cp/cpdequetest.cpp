#include <iostream>
#include "stl-cp/deque.h"

using namespace std;

void printLine() {
    cout << "-----" << endl;
}

int main() {
    CP::deque<int> q;
    cout << "Push back 1,2" << endl;
    q.push_back(1);
    q.push_back(2);
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop_front();
    }

    printLine();

    cout << "Push back 1,2 Push front 0, Push Back 200,201" << endl;
    q.push_back(1);
    q.push_back(2);
    q.push_front(0);
    q.push_back(200);
    q.push_back(201);
    q.pop_front();
    cout << "After pop 1: " << q.back() << endl;
    q.pop_back();
    cout << "After pop 2: " << q.back() << endl;
    q.pop_back();
    cout << "After pop 3: " << q.back() << endl;
    while (!q.empty()) {
        cout << q.front() << "--" << q.back() << endl;
        q.pop_front();
    }

    printLine();

    cout << "Push front starting from 10 to 1" << endl;
    for (int i = 10; i > 0; i--) {
        q.push_front(i);
    }
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop_front();
    }
}
