#ifndef _BST_
#define _BST_

#include <iostream>

using namespace std;

// Implementando uma Binary Tree
class BST {
    private:
        struct BSTNode {
            BSTNode* left;
            int element;
            BSTNode* right;
            BSTNode(int e) { left = NULL; element = e; right = NULL; }
        };
        BSTNode* root;
    public:
        BST() { root = NULL; }
};

#endif