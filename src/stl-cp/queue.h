#include <iostream>
#include <vector>
using namespace std;

namespace CP {
    template <typename T>
    class queue {
        protected:
            T *mData;
            size_t mCap;
            size_t mSize;
            size_t mFront;
            void expand(size_t capacity) {
                T *arr = new T[capacity]();
                for (size_t i = 0; i < mSize; i++) {
                    arr[i] = mData[(mFront + i) % mCap];
                }
                delete [] mData;
                mData = arr;
                mCap = capacity;
                mFront = 0;
            }
            void ensureCapacity(size_t capacity) {
                if (capacity > mCap) {
                    size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
                    expand(s);
                }
            }
        public:
            // Initailization
            queue() : mData(new T[1]()), mCap(1), mSize(0), mFront(0) {}
            queue(const queue<T> &a) : mData(new T[a.mCap]()), mCap(a.mCap), mSize(a.mSize), mFront(a.mFront) {
                for (size_t i = 0; i < a.mCap; i++) {
                    mData[i] = a.mData[i];
                }
            }
            queue<T>& operator=(queue<T> other) {
                using std::swap;
                swap(mSize, other.mSize);
                swap(mCap, other.mCap);
                swap(mFront, other.mFront);
                swap(mData, other.mData);
                return *this;
            }
            ~queue() {
                delete [] mData;
            }
            // Capacity function
            bool empty() const { 
                return mSize == 0;
            }
            size_t size() const { 
                return mSize;
            }
            // Access
            const T& front() const { 
                return mData[mFront];
            }
            const T& back() const {
                return mData[(mFront + mSize -1) % mCap];
            }
            // Modifier
            void push(const T& element) { 
                ensureCapacity(mSize+1);
                mData[(mFront + mSize) % mCap] = element;
                mSize++;
            }
            void pop() {
                mFront = (mFront + 1) % mCap;
                mSize--;
            }
    };
}

