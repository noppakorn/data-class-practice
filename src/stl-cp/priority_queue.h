#include <iostream>
using std::size_t;

namespace CP {
  template <typename T, typename Comp = std::less<T> >
  class priority_queue {
    protected:
      T *mData;
      size_t mCap;
      size_t mSize;
      Comp mLess;
      void expand(size_t capacity) {
        T *arr = new T[capacity]();
        for (size_t i = 0; i < mSize; i++) {
          arr[i] = mData[i];
        }
        delete [] mData;
        mData = arr;
        mCap = capacity;
      }
      void fixUp(size_t idx) {
          T tmp = mData[idx];
          while (idx > 0) {
              size_t p = (idx - 1) / 2;
              if (mLess(mData[idx], mData[p])) break;
              mData[idx] = mData[p];
              idx = p;
          }
          mData[idx] = tmp;
      }
      void fixDown(size_t idx) {
          T tmp = mData[idx];
          size_t c;
          while ((c = 2 * idx + 1) < mSize) {
              if (c + 1 < mSize && mLess(mData[c], mData[c+1])) c++;
              mData[idx] = mData[c];
              idx = c;
          }
          mData[idx] = tmp;
      }
    public:
      // Initialization
      priority_queue(const Comp &c = Comp()) : mData(new T[1]), mCap(1), mSize(0), mLess(c) {}
      priority_queue(const priority_queue<T> &a) : mData(new T[a.mCap]), mCap(a.mCap), mSize(a.mSize), mLess(a.mLess) {
          for (size_t i = 0; i < a.mSize; i++) {
              mData[i] = a.mData[i];
          }
      }
      priority_queue<T>& operator=(priority_queue<T> other) {
          using std::swap;
          swap(mData, other.mData);
          swap(mCap, other.mCap);
          swap(mSize, other.mSize);
          swap(mLess, other.mLess);
          return *this;
      }
      ~priority_queue() {
          delete [] mData;
      }
      // Access
      T top() {
          return mData[0];
      }

      // Modification
      void push(const T& element) {
          if (mSize + 1 > mCap) expand(2 * mCap);
          mData[mSize++] = element;
          fixUp(mSize-1);
      }
      void pop() {
          mData[0] = mData[mSize-1];
          mSize--;
          fixDown(0);
      }
  };
}
