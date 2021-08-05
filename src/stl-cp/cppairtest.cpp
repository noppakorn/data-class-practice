#include <iostream>
#include <string>
#include "pair.h"

int main() {
    CP::pair<int,int> p1(1,4);
    std::cout << p1.first << ": " << p1.second << std::endl;
}
