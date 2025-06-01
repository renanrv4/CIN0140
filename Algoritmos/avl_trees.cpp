#include <bits/stdc++.h>

using namespace std;

// Implementando uma árvore AVL (self balancing)
class AVL_Tree {
    private:
        struct BSTNode {
            BSTNode* left;
            int element;
            BSTNode* right;
            int height;
            BSTNode(int e) { left = NULL; element = e; right = NULL; height = 0; }
        };
        BSTNode* root;

        // Métodos Auxiliares
        int h(BSTNode* rt) {
            if(rt == NULL) { return -1; }
            return rt->height;
        }

        int getBalance(BSTNode* rt) {
            if(rt == NULL) { return 0; }
            return h(rt->left) - h(rt->right);
        }

        // Métodos de rotação da árvore AVL
        BSTNode* right_rotate(BSTNode* rt) {
            BSTNode* l = rt->left;
            BSTNode* lr = l->right;
            l->right = rt;
            rt->left = lr;
            rt->height = max(h(rt->left), h(rt->right)) + 1;
            l->height = max(h(l->left), h(l->right))+ 1;
            return l;
        }

        BSTNode* left_rotate(BSTNode* rt) {
            BSTNode* r = rt->right;
            BSTNode* rl = r->left;
            r->left = rt;
            rt->right = rl;
            rt->height = max(h(rt->left), h(rt->right)) + 1;
            r->height = max(h(r->left), h(r->right)) + 1;
            return r;
        }

        BSTNode* inserthelp(BSTNode* rt, int elem) {
            if(rt == NULL) { return new BSTNode(elem); }
            if(rt->element > elem) {
                rt->left = inserthelp(rt->left, elem);
            } else {
                rt->right = inserthelp(rt->right, elem);
            }
            rt->height = 1 + max(h(rt->left), h(rt->right));
            int balance = getBalance(rt);
            if(balance < -1 && elem >= rt->right->element) {
                return left_rotate(rt);
            }
            if(balance > 1 && elem < rt->left->element) {
                return right_rotate(rt);
            }
            if(balance > 1 && elem >= rt->left->element) {
                rt->left = left_rotate(rt->left);
                return right_rotate(rt);
            }
            if(balance < -1 && elem < rt->right->element) {
                rt->right = right_rotate(rt->right);
                return left_rotate(rt);
            }
            return rt;
        }

        void preorder(BSTNode* node) {
            if(node == NULL) { return; }
            cout << node->element << " ";
            preorder(node->left);
            preorder(node->right);
        }
        
        void inorder(BSTNode* node) {
            if(node == NULL) { return; }
            inorder(node->left);
            cout << node->element << " ";
            inorder(node->right);
        }

        void postorder(BSTNode* node) {
            if(node == NULL) { return; }
            postorder(node->left);
            postorder(node->right);
            cout << node->element << " ";
        }

    public:
        AVL_Tree() { root = NULL; }

        void insert(int elem) {
            root = inserthelp(root, elem);
        }

        void preorder() { preorder(root); cout << '\n'; }
        void inorder() { inorder(root); cout << '\n'; }
        void postorder() { postorder(root); cout << '\n'; }
};

int main() {
    AVL_Tree avl_tree;
    int n; cin >> n;
    string cmd;
    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        if (cmd == "insert") {
            int x; cin >> x;
            avl_tree.insert(x);
        } else if (cmd == "pre") {
            avl_tree.preorder();
        } else if (cmd == "in") {
            avl_tree.inorder();
        } else if (cmd == "post") {
            avl_tree.postorder();
        }
    }
    return 0;
}