#include <iostream>
using namespace std;

namespace CP {
    template <typename T>
    class stack {
    public :
        typedef T* iterator;
    protected :
        T *mData;
        size_t mCap;
        size_t mSize;

        void expand(size_t capacity) {
            T *arr = new T[capacity]();
            for (size_t i = 0; i < mSize; i++) {
                arr[i] = mData[i];
            }
            delete [] mData;
            mData = arr;
            mCap = capacity;
        }
        void ensureCapacity(size_t capacity) {
            if (capacity > mCap) {
                size_t s = (capacity > 2*mCap) ? capacity : 2 * mCap;
                expand(s);
            }
        }
    public:
        // Constructor & copy operator
        stack() {
            int cap = 1;
            mData = new T[cap]();
            mCap = cap;
            mSize = 0;
        }
        stack(size_t cap) {
            mData = new T[cap]();
            mCap = cap;
            mSize = cap;
        }
        ~stack() {
            delete [] mData;
        }
        stack(const stack<T> &a) {
            mData = new T[a.capacity()]();
            mCap = a.capacity();
            mSize = a.size();
            for (int i = 0; i < a.size(); i++) {
                mData[i] = a[i];
            }
        }
        stack<T>& operator=(stack<T> &other) {
            if (mData != other.mData) {
                delete [] mData;

                mData = new T[other.capacity()]();
                mCap = other.capacity();
                mSize = other.size();
                for (int i = 0; i < other.size(); i++) {
                    mData[i] = other[i];
                }
            }
        }
        // Capacity Function
        bool empty() const {
            return mSize == 0;
        }
        size_t size() const {
            return mSize;
        }
        // access
        const T& top() const {
            return mData[mSize-1];
        }
        // modifier
        void push(const T& element) {
            ensureCapacity(mSize+1);
            mData[mSize] = element;
        }
        void pop() {
            mSize--;
        }
    };
}
