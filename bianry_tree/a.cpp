#include "a.h"
#include<stack>

binaryTree* buildTree() {
    binaryTree* d = new binaryTree(1);
        //       1
        //    2     3
        // 4   5  6  7
    d->left = new binaryTree(2);
    d->right = new binaryTree(3);

    d->left->left = new binaryTree(4);
    d->left->right = new binaryTree(5);

    d->right->left = new binaryTree(6);
    d->right->right = new binaryTree(7);
    return d;
}

void pre_order(const binaryTree* b) {
    if(b == nullptr) {
        return;
    }
    cout << b->value << " ";;
    pre_order(b->left);
    pre_order(b->right);
}

void in_order(const binaryTree* b) {
    if(b == nullptr) {
        return;
    }
    in_order(b->left);
    cout << b->value << " ";;
    in_order(b->right);
}

void post_order(const binaryTree* b) {
    if(b == nullptr) {
        return;
    }
    post_order(b->left);
    post_order(b->right);
    cout << b->value << " ";;
}

void printTree() {
    binaryTree* b = buildTree();
    cout << "pre_order:" << endl;
    pre_order(b);
    cout << endl;

    cout << "in_order:" << endl;
    in_order(b);
    cout << endl;

    cout << "post_order:" << endl;
    post_order(b);
    cout << endl;
    return;
}

