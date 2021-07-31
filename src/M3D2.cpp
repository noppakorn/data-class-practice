#include <bits/stdc++.h>

using namespace std;

string printM3D2(int v, map<int,int> &m){
    string out;
    while (m[v] != -1){
        if (m[v] * 3 == v) {
            out = "*3" + out;
        }
        else {
            out = "/2" + out;
        }
        v = m[v];
    }
    return "1" + out;
}

int main() {
    ios::sync_with_stdio(0);

    int target;
    cin >> target;

    map<int,int> m;
    queue<int> q;
    int v;
    m[1] = -1;
    q.push(1);
    int v2,v3;
    while(!q.empty()){
        v = q.front(); q.pop();
        if (v == target) {
            break;
        }
        v2 = v / 2;
        v3 = v * 3;
        if (m[v2] == 0) {
            q.push(v2);
            m[v2] = v;
        }
        if (m[v3] == 0) {
            q.push(v3);
            m[v3] = v;
        }
    }

    cout << printM3D2(target,m) << endl;
}