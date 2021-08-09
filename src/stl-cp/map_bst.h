#include <iostream>
using namespace std;

namespace CP {
  template <typename KeyT,
            typename MappedT,
            typename CompareT = std::less<KeyT> >
  class map_bst {
    protected:
      typedef std::pair<KeyT,MappedT> ValueT;
      class node {
        friend class map_bst;
        protected:
          ValueT data;
          node *left;
          node *right;
          node *parent;
      
          node() :
            data( ValueT() ), left( NULL ), right( NULL ), parent( NULL ) {}
          
          node(const ValueT &data, node* left, node* right, node* parent) :
            data( ValueT() ), left( left ), right( right ), parent( parent ) {}
      
      };
      class tree_iterator {
        protected:
          node* ptr;
        public:
          tree_iterator() {}
          tree_iterator() {}
          tree_iterator operator++() {
            if (ptr->right == NULL) {
              node* parent = ptr->parent;
              while (parent != NULL && parent->right == ptr) {
                ptr = parent;
                parent = ptr->parent;
              }
              ptr = parent;
            }
            else {
              ptr = ptr->right;
              while (ptr->left != NULL) {
                ptr = ptr->left;
              }
            }
            return (*this);
          }
          tree_iterator operator--() {
            if (ptr->left == NULL) {
              node* parent = ptr->parent;
              while (parent != NULL && parent->left == ptr) {
                ptr = parent;
                parent = ptr->parent;
              }
              ptr = parent;
            }
            else {
              ptr = ptr->left;
              while (ptr->right != NULL) {
                ptr = ptr->right;
              }
            }
            return (*this);
          }
          tree_iterator operator++(int) {
            tree_iterator tmp(*this);
            operator++();
            return tmp;
          }
          tree_iterator operator--(int) {
            tree_iterator tmp(*this);
            operator--();
            return tmp;
          }
          ValueT &operator*() { return ptr->data; }
          ValueT* operator->() { return &(ptr->data); }
          bool operator==(const tree_iterator &other) {
            return other.ptr == ptr;
          }
          bool operator!=(const tree_iterator &other) {
            return other.ptr != ptr;
          }
      };
      node* mRoot; CompareT mLess;
      size_t mSize;

      int compare(const KeyT &k1, const KeyT &k2) {
        if (mLess(k1, k2)) return -1;
        if (mLess(k2, k1)) return 1;
        return 0;
      }
      
      node* find_node(const KeyT &k, node* r, node* &parent) {
        node *ptr = r;
        while (ptr != NULL) {
          int cmp = compare(k, ptr->data.first);
          if (cmp == 0) return ptr;
          parent = ptr;
          ptr = cmp < 0 ? ptr->left : ptr->right;
        }
        return NULL;
      }

      node* find_min_node(node* r) {
        // r must not be NULL
        if (r->left == NULL) return r;
        return find_min_node(r->left);
      }

      node* find_max_node(node* r) {
        // r must not be NULL
        if (r->right == NULL) return r;
        return find_max_node(r->left);
      }

      node* &child_link(node* parent, const KeyT &k) {
        if (parent == NULL) return mRoot;
        return mLess(k, parent->data.first) ? parent->left : parent->right;
      }
    public:
      typedef tree_iterator iterator;
      map_bst(const map_bst<KeyT,MappedT,CompareT> &other) : mLess(other.mLess), mSize(other.mSize) {
        mRoot = copy(other.mRoot, NULL);
      }

      map_bst(const CompareT &c = CompareT()) : mRoot(NULL), mLess(c), mSize (0) {}

      map_bst<KeyT,MappedT,CompareT> &operator=(map_bst<KeyT,MappedT,CompareT> other) {
        using std::swap;
        swap(this->mRoot,other.mRoot);
        swap(this->mLess,other.mLess);
        swap(this->mSize,other.mSize);
        return this;
      }

      ~map_bst() {
        clear();
      }

      iterator find(const KeyT &key) {
        node* parent;
        node* ptr = find_node(key,mRoot,parent);
        return ptr == NULL ? end() : iterator(ptr);
      }

      std::pair<iterator,bool> insert(const ValueT &val) {
        node* parent = NULL;
        node* ptr = find_node(val.first,mRoot,parent);
        bool not_found = (ptr==NULL);
        if (not_found) {
          ptr = new node(val, NULL, NULL, parent);
          child_link(parent, val.first) = ptr;
          mSize++;
        }
        return std::make_pair(iterator(ptr), not_found);
      }

      size_t erase(const KeyT &key) {
        if (mRoot == NULL) return 0;
        node* parent = NULL;
        node* ptr = find_node(key,mRoot,parent);
        if (ptr == NULL) return 0;
        if (ptr->left  != NULL && ptr->right != NULL) {
          // have two children
          node* min = find_min_node(ptr->right);
          node* &link = child_link(min->parent, min->data.first);
          link = (min->left == NULL) ? min->right : min->left;
          if (link != NULL) link->parent = min->parent;
          std::swap(ptr->data.first, min->data.first);
          std::swap(ptr->data.second, min->data.second);
          ptr = min;
        }
        else {
          node* &link = child_link(ptr->parent, key);
          link = (ptr->left == NULL) ? ptr->right : ptr->left;
          if (link != NULL) link->parent = ptr->parent;
        }
        delete ptr;
        mSize--;
        return 1;
      }

      MappedT &operator[](const KeyT &key)  {
        node* parent = NULL;
        node* ptr = find_node(key,mRoot,parent);
        if (ptr == NULL) {
          ptr = new node(std::make_pair(key,MappedT()), NULL, NULL, parent);
          child_link(parent, key) = ptr;
          mSize++;
        }
        return ptr->data.second;
      }
}










