#include "vector.h"
namespace CP {
    template <typename T>
    class stack {
    protected:
        vector<T> v;
    public:
        stack() : v() {}

        // capacity
        bool empty() const {
            return v.empty();
        }
        size_t size() const {
            return v.size();
        }

        // access
        const T& top() const {
            return v[v.size()-1];
        }
        // modifier
        void push(const T& element) {
            v.push_back(element);
        }
        void pop() {
            v.pop_back();
        }
    };

}
