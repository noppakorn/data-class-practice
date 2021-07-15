#include <iostream>
#include <string>

namespace CP {
    template <typename T1,typename T2>
    class pair {
    public:
        T1 first;
        T2 second;
        pair() {}
        pair(T1 a, T2 b) : first(a), second(b) {}
        bool operator==(const CP::pair<T1,T2> &other) const { return (first == other.first && second == other.second); }
        bool operator<(const CP::pair<T1,T2> &other) const {
            return (first < other.first || (first == other.first && second < other.second));
        }
        bool operator>(const CP::pair<T1,T2> &other) const {
            return !operator<(other) && !operator==(other);
        }
    };
}

int main() {
    CP::pair<int,int> p1(1,4);
    std::cout << p1.first << ": " << p1.second << std::endl;
}
