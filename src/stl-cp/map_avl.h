#include <iostream>
// using namespace std;

namespace CP {
template <typename KeyT, typename MappedT, typename CompareT = std::less<KeyT>>
class map_avl {
  protected:
    typedef std::pair<KeyT, MappedT> ValueT;
    class node {
        friend class map_avl;

      protected:
        ValueT data;
        node *left;
        node *right;
        node *parent;
        int height;

        node()
            : data(ValueT()), left(NULL), right(NULL), parent(NULL), height(0) {
        }

        node(const ValueT &data, node *left, node *right, node *parent)
            : data(data), left(left), right(right), parent(parent) {
            set_height();
        }

        int get_height(node *n) { return (n == NULL ? -1 : n->height); }
        void set_height() {
            int hL = get_height(this->left);
            int hR = get_height(this->right);
            height = 1 + (hL > hR ? hL : hR);
        }
        int balance_value() {
            return get_height(this->right) - get_height(this->left);
        }

        void set_left(node *n) {
            this->left = n;
            if (n != NULL)
                this->left->parent = this;
        }
        void set_right(node *n) {
            this->right = n;
            if (n != NULL)
                this->right->parent = this;
        }
    };
    class tree_iterator {
      protected:
        node *ptr;

      public:
        tree_iterator() : ptr(NULL) {}

        tree_iterator(node *a) : ptr(a) {}

        tree_iterator operator++() {
            if (ptr->right == NULL) {
                node *parent = ptr->parent;
                while (parent != NULL && parent->right == ptr) {
                    ptr = parent;
                    parent = ptr->parent;
                }
                ptr = parent;
            } else {
                ptr = ptr->right;
                while (ptr->left != NULL) {
                    ptr = ptr->left;
                }
            }
            return (*this);
        }
        tree_iterator operator--() {
            if (ptr->left == NULL) {
                node *parent = ptr->parent;
                while (parent != NULL && parent->left == ptr) {
                    ptr = parent;
                    parent = ptr->parent;
                }
                ptr = parent;
            } else {
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
        ValueT *operator->() { return &(ptr->data); }
        bool operator==(const tree_iterator &other) { return other.ptr == ptr; }
        bool operator!=(const tree_iterator &other) { return other.ptr != ptr; }
    };
    node *mRoot;
    CompareT mLess;
    size_t mSize;

    int compare(const KeyT &k1, const KeyT &k2) {
        if (mLess(k1, k2))
            return -1;
        if (mLess(k2, k1))
            return +1;
        return 0;
    }

    node *find_node(const KeyT &k, node *r, node *&parent) {
        node *ptr = r;
        while (ptr != NULL) {
            int cmp = compare(k, ptr->data.first);
            if (cmp == 0)
                return ptr;
            parent = ptr;
            ptr = cmp < 0 ? ptr->left : ptr->right;
        }
        return NULL;
    }

    node *find_min_node(node *r) {
        // r must not be NULL
        if (r->left == NULL)
            return r;
        return find_min_node(r->left);
    }

    node *find_max_node(node *r) {
        // r must not be NULL
        if (r->right == NULL)
            return r;
        return find_max_node(r->left);
    }

    node *&child_link(node *parent, const KeyT &k) {
        if (parent == NULL)
            return mRoot;
        return mLess(k, parent->data.first) ? parent->left : parent->right;
    }

    void delete_all_nodes(node *r) {
        if (r == NULL)
            return;
        delete_all_nodes(r->left);
        delete_all_nodes(r->right);
        delete r;
    }

    node *rotate_left_child(node *r) {
        node *new_root = r->left;
        r->set_left(new_root->right);
        new_root->set_right(r);

        new_root->right->set_height();
        new_root->set_height();
        return new_root;
    }

    node *rotate_right_child(node *r) {
        node *new_root = r->right;
        r->set_right(new_root->left);
        new_root->set_left(r);

        new_root->left->set_height();
        new_root->set_height();
        return new_root;
    }

    node *rebalance(node *r) {
        if (r == NULL) {
            return r;
        }
        int balance = r->balance_value();
        if (balance == -2) {
            if (r->left->balance_value() == 1) {
                r->set_left(rotate_right_child(r->left));
            }
            r = rotate_left_child(r);
        } else if (balance == 2) {
            if (r->right->balance_value() == -1) {
                r->set_right(rotate_left_child(r->right));
            }
            r = rotate_right_child(r);
        }
        r->set_height();
        return r;
    }

    node *insert(const ValueT &val, node *r, node *&ptr) {
        if (r == NULL) {
            mSize++;
            ptr = r = new node(val, NULL, NULL, NULL);
        } else {
            int cmp = compare(val.first, r->data.first);
            if (cmp == 0) {
                ptr = r;
            } else if (cmp < 0) {
                r->set_left(insert(val, r->left, ptr));
            } else {
                r->set_right(insert(val, r->right, ptr));
            }
        }
        r = rebalance(r);
        return r;
    }

  public:
    typedef tree_iterator iterator;
    map_avl(const map_avl<KeyT, MappedT, CompareT> &other)
        : mLess(other.mLess), mSize(other.mSize) {
        mRoot = copy(other.mRoot, NULL);
    }

    map_avl(const CompareT &c = CompareT()) : mRoot(NULL), mLess(c), mSize(0) {}

    map_avl<KeyT, MappedT, CompareT> &
    operator=(map_avl<KeyT, MappedT, CompareT> other) {
        using std::swap;
        swap(this->mRoot, other.mRoot);
        swap(this->mLess, other.mLess);
        swap(this->mSize, other.mSize);
        return this;
    }

    ~map_avl() { clear(); }

    std::size_t size() { return mSize; }

    bool empty() { return mSize == 0; }

    void clear() {
        delete_all_nodes(mRoot);
        mRoot = NULL;
        mSize = 0;
    }

    iterator begin() {
        return iterator(mRoot == NULL ? NULL : find_min_node(mRoot));
    }

    iterator end() { return iterator(NULL); }

    iterator find(const KeyT &key) {
        node *parent;
        node *ptr = find_node(key, mRoot, parent);
        return ptr == NULL ? end() : iterator(ptr);
    }

    std::pair<iterator, bool> insert(const ValueT &val) {
        node *ptr = NULL;
        size_t s = mSize;
        mRoot = insert(val, mRoot, ptr);
        mRoot->parent = NULL;
        return std::make_pair(iterator(ptr), mSize > s);
    }

    size_t erase(const KeyT &key) {
        if (mRoot == NULL)
            return 0;
        node *parent = NULL;
        node *ptr = find_node(key, mRoot, parent);
        if (ptr == NULL)
            return 0;
        if (ptr->left != NULL && ptr->right != NULL) {
            // have two children
            node *min = find_min_node(ptr->right);
            node *&link = child_link(min->parent, min->data.first);
            link = (min->left == NULL) ? min->right : min->left;
            if (link != NULL)
                link->parent = min->parent;
            std::swap(ptr->data.first, min->data.first);
            std::swap(ptr->data.second, min->data.second);
            ptr = min;
        } else {
            node *&link = child_link(ptr->parent, key);
            link = (ptr->left == NULL) ? ptr->right : ptr->left;
            if (link != NULL)
                link->parent = ptr->parent;
        }
        delete ptr;
        mSize--;
        return 1;
    }

    MappedT &operator[](const KeyT &key) {
        std::pair<iterator, bool> result =
            insert(std::make_pair(key, MappedT()));
        return result.first->second;
    }
};
} // namespace CP
