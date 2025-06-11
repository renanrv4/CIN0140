#include <iostream>

using namespace std;

// Exercício prático sobre AVL Tree

class AVL {
    private:
        struct BSTNode {
            BSTNode* left;
            int elem;
            int height;
            BSTNode* right;
            BSTNode(int e) { left = NULL; elem = e; height = 0; right = NULL; }
        };
        int count, comp;
        BSTNode* root;
        bool rotate;
        int h(BSTNode* rt) {
            if(rt == NULL) { return -1; }
            return rt->height;
        }

        int getBalance(BSTNode* rt) {
            if(rt == NULL) { return 0; }
            return h(rt->left) - h(rt->right);
        }

        BSTNode* leftrot(BSTNode* rt) {
            BSTNode* r = rt->right;
            BSTNode* rl = r->left;
            r->left = rt;
            rt->right = rl;
            rt->height = max(h(rt->left), h(rt->right)) + 1;
            r->height = max(h(r->left), h(r->right)) + 1;
            return r;
        }

        BSTNode* rightrot(BSTNode* rt) {
            BSTNode* l = rt->left;
            BSTNode* lr = l->right;
            l->right = rt;
            rt->left = lr;
            rt->height = max(h(rt->left), h(rt->right)) + 1;
            l->height = max(h(l->left), h(l->right)) + 1;
            return l;
        }

        BSTNode* inserthelp(BSTNode* rt, int elem) {
            if(rt == NULL) { count++; return new BSTNode(elem); }
            if(rt->elem > elem) {
                rt->left = inserthelp(rt->left, elem);
            } else {
                rt->right = inserthelp(rt->right, elem);
            }

            rt->height = max(h(rt->left), h(rt->right)) + 1;
            int balance = getBalance(rt);
            if(balance < -1 && elem >= rt->right->elem) {
                cout << "insert " << elem << ": " << rt->elem << " is unbalanced, L-rotation!\n";
                rotate = true;
                return leftrot(rt);
            }
            if(balance > 1 && elem < rt->left->elem) {
                cout << "insert " << elem << ": " << rt->elem << " is unbalanced, R-rotation!\n";
                rotate = true;
                return rightrot(rt);
            }

            if(balance > 1 && elem >= rt->left->elem) {
                cout << "insert " << elem << ": " << rt->elem << " is unbalanced, LR-rotation!\n";
                rotate = true;
                rt->left = leftrot(rt->left);
                return rightrot(rt);
            }
            if(balance < -1 && elem < rt->right->elem) {
                cout << "insert " << elem << ": " << rt->elem << " is unbalanced, RL-rotation!\n";
                rotate = true;
                rt->right = rightrot(rt->right);
                return leftrot(rt);
            }
            return rt;
        }

        void preorder(BSTNode* rt) {
            if(rt == NULL) { return; }
            comp++;
            if(comp < count) {
                cout << rt->elem << " ";
            } else {
                cout << rt->elem;
            }
            preorder(rt->left);
            preorder(rt->right);
        }

        void inorder(BSTNode* rt) {
            if(rt == NULL) { return; }
            inorder(rt->left);
            comp++;
            if(comp < count) {
                cout << rt->elem << " ";
            } else {
                cout << rt->elem;
            }
            inorder(rt->right);
        }

        void postorder(BSTNode* rt) {
            if(rt == NULL) { return; }
            postorder(rt->left);
            postorder(rt->right);
            comp++;
            if(comp < count) {
                cout << rt->elem << " ";
            } else {
                cout << rt->elem;
            }
        }
    public:
        AVL() { root = NULL; count = 0; rotate = false; }

        void insert(int elem) {
            rotate = false;
            root = inserthelp(root, elem);
            if(!rotate) {
                cout << "insert " << elem << ":" << " no rotation!\n";
            }
        }

        void pre() {
            comp = 0;
            cout << "preorder: "; preorder(root); cout << "\n";
        }
        void in() {
            comp = 0;
            cout << "inorder: "; inorder(root); cout << "\n";
        }
        void post() {
            comp = 0;
            cout << "postorder: "; postorder(root); cout << "\n";
        }

};

int main() {
    int n; cin >> n;
    AVL avl_tree;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        avl_tree.insert(num);
    }
    avl_tree.pre();
    avl_tree.in();
    avl_tree.post();
    return 0;
}