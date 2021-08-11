//#include "/home/noppakorn/CP-2021-S1/data-class/stl-cp/map_bst.h"
#include "map_bst.h"

int main() {
    CP::map_bst<int,int> m;
    m[0] = 1;
    m[1] = 2;
    m[2] = 3;
    for (auto it = m.begin(); it != m.end(); it++) {
        std::cout << it->first << ": " << it->second << "\n";
    }
}

