#include <iostream>
using std::size_t;

namespace CP {
    template <typename T>
    class deque {
        protected:
            T *mData;
            size_t mSize;
            size_t mCap;
            size_t mFront;
            void expand(size_t capacity) {
                T *arr = new T[capacity]();
                for (int i = 0; i < mSize; i++) {
                    arr[i] = mData[(mFront + i) % mCap];
                }
                delete [] mData;
                mData = arr;
                mCap = capacity;
                mFront = 0;
            }
            void ensureCapacity(size_t capacity) {
                if (capacity > mCap) {
                    size_t s = (capacity > 2 * mCap) ? capacity : 2 * capacity;
                    expand(s);
                }
            }
        public:
            deque() : mData(new T[1]()), mCap(1), mSize(0), mFront(0) {}
            deque(const deque<T> &a) : mData(new T[a.mCap]()), mCap(a.mCap), mSize(a.mSize), mFront(a.mFront) {
                for (int i = 0; i < mCap; i++) {
                    mData[i] = a.mData[i];
                }
            }
            deque<T>& operator=(deque<T> other) {
                using std::swap;
                swap(mSize, other.mSize);
                swap(mCap, other.mCap);
                swap(mFront, other.mFront);
                swap(mData, other.mData);
                return *this;
            }
            ~deque() {
                delete [] mData;
            }
            // Capacity Function
            bool empty() const {
                return mSize == 0;
            }
            bool size() const {
                return mSize;
            }
            // Access 
            const T& front() const {
                return mData[mFront];
            }
            const T& back() const {
                return mData[(mFront + mSize - 1) % mCap];
            }
            // Modifier
            void push_front(const T &element) {
                ensureCapacity(mSize+1);
                mFront = (mFront + mCap - 1) % mCap;
                mData[mFront] = element;
                mSize++;
            }
            void push_back(const T &element) {
                ensureCapacity(mSize+1);
                mData[(mFront + mSize) % mCap] = element;
                mSize++;
            }
            void pop_front() {
                mFront = (mFront + 1) % mCap;
                mSize--;
            }
            void pop_back() {
                mSize--;
            }
            
    };
}
