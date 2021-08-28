#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <map>
#include "map_avl.h"
#include "map_bst.h"

int main() {
    int num_count = 10000000;
    std::vector<int> v(num_count);
    for (int i = 0; i < v.size(); i += 1) {
        v[i] = 2*i;
    }
    std::reverse(v.begin(), v.end());
    // std::random_shuffle(v.begin(),v.end());

    CP::map_avl<int,int> m;
    // CP::map_bst<int,int> m;
    // std::map<int,int> m;
    auto start = std::chrono::high_resolution_clock::now();
    for (auto &i : v) {
        m[i] = i + 1;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Insert: " << (std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()) / 1e9 << "\n";

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < num_count; i++) {
        m.find(i + 1);
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Find: " << (std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()) / 1e9 << "\n";


    start = std::chrono::high_resolution_clock::now();
    std::random_shuffle(v.begin(), v.end());
    for (auto &i :v) {
        m.erase(i);
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Erase: " <<  (std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()) / 1e9 << "\n";
    // std::cout  << m.size() << "\n";
}
