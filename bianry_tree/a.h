#include<stdio.h>
#include<iostream>

using namespace std;


class binaryTree {
    public:
    int value;
    binaryTree* left;
    binaryTree* right;
    binaryTree() = default;
    binaryTree(int v):value(v) {
        left = right = nullptr;
    }
    ~binaryTree() {
        delete this->left;
        delete this->right;
        left = left = nullptr;
    }
};


void printTree();
