#include <iostream>
using std::cout;
using std::endl;

class node {
    public:
        int data;
        node *left, *right;
        node() : data(0),left(NULL),right(NULL) {};
        node(int data, node *left, node *right) :
            data(data), left(left), right(right) {};
};

int get_size(node *n) {
    if (n == NULL) return 0;
    return 1 + get_size(n->left) + get_size(n->right);
}

int get_height(node *n) {
    if (n == NULL) return 0;
    return 1 + std::max(get_height(n->left),get_height(n->right));
}

node* copy(node *n) {
    if (n == NULL) return NULL;
    node *lc = copy(n->left);
    node *rc = copy(n->right);
    node *result = new node(n->data,lc,rc);
    return result;
}

void preorder(node *n) {
    if (n == NULL) return;
    std::cout << n->data << " ";
    preorder(n->left);
    preorder(n->right);
}

void inorder(node *n) {
    if (n == NULL) return;
    inorder(n->left);
    std::cout << n->data << " ";
    inorder(n->right);
}

void postorder(node *n) {
    if (n == NULL) return;
    postorder(n->left);
    postorder(n->right);
    std::cout << n->data << " ";
}
int main() {
    node *n;
    n = new node();
    n->data = 0;
    int count = 0;
    n->right = new node();
    n->right->data = 4;
    n->left = new node();
    n->left->data = 1;
    n->left->right = new node(10,NULL,NULL);
    n->left->left = new node();
    n->left->left->data = 2;
    n->left->left->left = new node();
    n->left->left->left->data = 3;
    preorder(n);
    std::cout << "\n";
    inorder(n);
    std::cout << "\n";
    postorder(n);
    std::cout << "\n";
    /*
    std::cout << n->data << "\n";
    std::cout << n->left->data << "\n";
    std::cout << "Size: " << get_size(n) << "\n"; 
    std::cout << "Height: " << get_height(n) << "\n";
    */
}

