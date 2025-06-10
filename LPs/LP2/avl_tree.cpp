#include <iostream>

using namespace std;

// Implementando uma AVL Tree que possui o método de inserção, remoção, 
// e um find que retorna o índice representativo do elemento em uma lista

class AVL_Tree {
    private:
        struct BSTNode {
            BSTNode* left;
            int element;
            BSTNode* right;
            int height;
            int index;
            BSTNode(int e) { left = NULL; element = e; right = NULL; height = 0; index = 1; }
        };
        BSTNode* root;

        void clear(BSTNode* rt) {
            if (rt == nullptr) return;
            clear(rt->left);
            clear(rt->right);
            delete rt;
        }

        int node_index(BSTNode* rt) {
            if(rt != NULL) {
                return rt->index;
            }
            return 0;
        }

        int h(BSTNode* rt) {
            if(rt == NULL) { return -1; }
            return rt->height;
        }

        int getBalance(BSTNode* rt) {
            if(rt == NULL) { return 0; }
            return h(rt->left) - h(rt->right);
        }

        BSTNode* right_rotate(BSTNode* rt) {
            BSTNode* l = rt->left;
            BSTNode* lr = l->right;
            l->right = rt;
            rt->left = lr;
            rt->height = max(h(rt->left), h(rt->right)) + 1;
            rt->index = node_index(rt->left) + node_index(rt->right) + 1;
            l->height = max(h(l->left), h(l->right))+ 1;
            l->index = node_index(l->left) + node_index(l->right) + 1;
            return l;
        }

        BSTNode* left_rotate(BSTNode* rt) {
            BSTNode* r = rt->right;
            BSTNode* rl = r->left;
            r->left = rt;
            rt->right = rl;
            rt->height = max(h(rt->left), h(rt->right)) + 1;
            rt->index = node_index(rt->left) + node_index(rt->right) + 1;
            r->height = max(h(r->left), h(r->right)) + 1;
            r->index = node_index(r->left) + node_index(r->right) + 1;
            return r;
        }

        BSTNode* inserthelp(BSTNode* rt, int elem) {
            if(rt == NULL) { return new BSTNode(elem); }
            if(rt->element > elem) {
                rt->left = inserthelp(rt->left, elem);
            } else {
                rt->right = inserthelp(rt->right, elem);
            }

            // Rotações comparando o elemento (rotações da inserção em AVL)
            rt->height = 1 + max(h(rt->left), h(rt->right));
            rt->index = node_index(rt->left) + node_index(rt->right) + 1;
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

        int findhelp(BSTNode* rt, int elem) {
            if (rt == NULL) { return -1; }
            if (elem < rt->element) {
                return findhelp(rt->left, elem);
            } else if (elem > rt->element) {
                int right_result = findhelp(rt->right, elem);
                if (right_result == -1) { return -1; }
                return node_index(rt->left) + 1 + right_result;
            } else {
                return node_index(rt->left) + 1;
            }
        }

        // Para implementar uma remoção em um AVL Tree,
        // devemos primeiro implementar a lógica inicial da remoção de uma BST
        BSTNode* minValue(BSTNode* rt) {
            BSTNode* curr = rt;
            while(curr->left != NULL) {
                curr = curr->left;
            }
            return curr;
        }

        // Na remoção devemos usar o balance para decidir o tipo de rotação
        // Isso garante que a rotação não faça comparações com um valor que não existe mais
        BSTNode* removehelp(BSTNode* rt, int elem) {
            if(rt == NULL) { return rt; }
            if(rt->element > elem) {
                rt->left = removehelp(rt->left, elem);
            } else if(rt->element < elem) {
                rt->right = removehelp(rt->right, elem);
            } else {
                if(rt->left == NULL) {
                    BSTNode* temp = rt->right;
                    delete rt;
                    return temp;
                } else if(rt->right == NULL) {
                    BSTNode* temp = rt->left;
                    delete rt;
                    return temp;
                } else {
                    BSTNode* temp = minValue(rt->right);
                    rt->element = temp->element;
                    rt->right = removehelp(rt->right, temp->element);
                }
            }

            if(rt == NULL) { return rt; }

            // Rotações usando o balanceamento de cada nó
            rt->height = max(h(rt->left), h(rt->right)) + 1;
            int balance = getBalance(rt);
            if (balance > 1 && getBalance(rt->left) >= 0)
                return right_rotate(rt);

            if (balance > 1 && getBalance(rt->left) < 0) {
                rt->left = left_rotate(rt->left);
                return right_rotate(rt);
            }

            if (balance < -1 && getBalance(rt->right) <= 0)
                return left_rotate(rt);

            if (balance < -1 && getBalance(rt->right) > 0) {
                rt->right = right_rotate(rt->right);
                return left_rotate(rt);
            }
            return rt;
        }

        void preorder(BSTNode* rt) {
            if(rt == NULL) { return; }
            cout << rt->element << " ";
            preorder(rt->left);
            preorder(rt->right);
        }

        void inorder(BSTNode* rt) {
            if(rt == NULL) { return; }
            inorder(rt->left);
            cout << rt->element << " ";
            inorder(rt->right);
        }

        void postorder(BSTNode* rt) {
            if(rt == NULL) { return; }
            postorder(rt->left);
            postorder(rt->right);
            cout << rt->element << " ";
        }

    public:
        AVL_Tree() { root = NULL; }
        ~AVL_Tree() { clear(root); }

        void insert(int elem) {
            root = inserthelp(root, elem);
        }
        void find(int elem) {
            int index = findhelp(root, elem);
            if (index == -1) {
                cout << "Data tidak ada" << "\n";
            } else {
                cout << index << "\n";
            }
        }

        void remove(int elem) {
            root = removehelp(root, elem);
        }

        void pre() { preorder(root); cout << "\n"; }
        void in() { inorder(root); cout << "\n"; }
        void post() { postorder(root); cout << "\n"; }
};

int main() {
    int n; cin >> n;
    AVL_Tree avl_tree;
    for(int i = 0; i < n; i++) {
        int op, val; cin >> op >> val;
        if(op == 1) {
            avl_tree.insert(val);
        } else {
            avl_tree.find(val);
        }
    }
    cout << "Pre: "; avl_tree.pre();
    cout << "In: "; avl_tree.in();
    cout << "Post: "; avl_tree.post();

    avl_tree.remove(10);

    cout << "\n Removed \n";

    cout << "Pre: "; avl_tree.pre();
    cout << "In: "; avl_tree.in();
    cout << "Post: "; avl_tree.post();
}