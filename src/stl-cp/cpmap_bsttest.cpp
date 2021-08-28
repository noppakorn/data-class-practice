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

