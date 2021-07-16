#include <iostream>
using std::size_t;

namespace CP {
    template <typename T>
    class vector {
        public:
            typedef T* iterator;
        protected:
            T *mData;
            size_t mCap;
            size_t mSize;
            void rangeCheck(int n) {
                if (n < 0 || (size_t) n >= mSize) throw std::out_of_range("index out of range");
            }
            void expand(size_t capacity) {
                T *arr = new T[capacity]();
                for (int i = 0; i < mSize; i++) {
                    arr[i] = mData[i];
                }
                delete [] mData;
                mData = arr;
                mCap = capacity;
            }
            void ensureCapacity(size_t capacity) {
                if (capacity > mCap) {
                    size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
                    expand(s);
                }
            }
        public:
            vector() : mData(new T[1]()), mCap(1), mSize(0) {}
            vector(size_t cap) : mData(new T[cap]()), mCap(cap), mSize(cap) {}
            vector(const vector<T> &a) : mData(new T[a.mCap]()), mCap(a.mCap), mSize(a.mSize) {
                for (int i = 0; i < mSize; i++) {
                    mData[i] = a.mData[i];
                }
            }
            vector<T>& operator=(vector<T> other) {
                using std::swap;
                swap(mCap, other.mCap);
                swap(mSize, other.mSize);
                swap(mData, other.mData);
                return *this;
            }
            ~vector() {
                delete [] mData;
            }
            // Capacity
            bool empty() const {
                return mSize == 0;
            }
            size_t size() const {
                return mSize;
            }
            size_t capacity() const {
                return mCap;
            }
            void resize(size_t n) {
                if (n > mCap) expand(n);
                if (n > mSize) {
                    T init = T();
                    for (int i = mSize; i < n; i++) {
                        mData[i] = init;
                    }
                }
                mSize = n;
            }
            // Iterator
            iterator begin() {
                return &mData[0];
            }
            iterator end() {
                return begin()+mSize;
            }
            // Access
            T at(int n) {
                rangeCheck(n);
                return mData[n];
            }
            T at(int n) const {
                rangeCheck(n);
                return mData[n];
            }
            T operator[](int n) {
                return mData[n];
            }
            T operator[](int n) const {
                return mData[n];
            }
            // Modifier
            void push_back(const T &element) {
                insert(end(),element);
            }
            void pop_back() {
                mSize--;
            }
            iterator insert(iterator it, const T &element) {
                int pos = it - begin();
                ensureCapacity(mSize+1);
                for (int i = mSize; i > pos; i--) {
                    mData[i] = mData[i-1];
                }
                mData[pos] = element;
                mSize++;
                return it;
            }
            iterator erase(iterator it) {
                while (it+1 != end()) {
                    *it = *it+1;
                    it++;
                }
                mSize--;
            }
            void clear() {
                mSize = 0;
            }
    };
}

