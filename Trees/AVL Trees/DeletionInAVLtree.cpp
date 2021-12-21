#include <iostream>
using namespace std;
 
class Node{
    public:
        Node* lchild;
        int data;
        Node* rchild;
        int height;
};
 
class AVL{
    public:
        Node* root;
    
        AVL(){ root = nullptr; }
    
        int NodeHeight(Node *p){
            int hl;
            int hr;
        
            hl = (p && p->lchild) ? p->lchild->height : 0;
            hr = (p && p->rchild) ? p->rchild->height : 0;
        
            return hl > hr ? hl + 1 : hr + 1;
        }

        int BalanceFactor(Node *p){
            int hl;
            int hr;
        
            hl = (p && p->lchild) ? p->lchild->height : 0;
            hr = (p && p->rchild) ? p->rchild->height : 0;
        
            return hl - hr;
        }

        Node* LLRotation(Node *p){
            Node* pl = p->lchild;
            Node* plr = pl->rchild;
        
            pl->rchild = p;
            p->lchild = plr;
        
            // Update height
            p->height = NodeHeight(p);
            pl->height = NodeHeight(pl);
        
            // Update root
            if (root == p){
                root = pl;
            }
            return pl;
        }

        Node* RRRotation(Node *p){
            Node* pr = p->rchild;
            Node* prl = pr->lchild;
        
            pr->lchild = p;
            p->rchild = prl;
        
            p->height = NodeHeight(p);
            pr->height = NodeHeight(pr);
        
            if (root == p){
                root = pr;
            }
            return pr;
        }
 
        Node* LRRotation(Node *p){
            Node* pl = p->lchild;
            Node* plr = pl->rchild;
        
            pl->rchild = plr->lchild;
            p->lchild = plr->rchild;
        
            plr->lchild = pl;
            plr->rchild = p;
        
            pl->height = NodeHeight(pl);
            p->height = NodeHeight(p);
            plr->height = NodeHeight(plr);
        
            if (root == p){
                root = plr;
            }
            return plr;
        }

        Node* RLRotation(Node *p){
            Node* pr = p->rchild;
            Node* prl = pr->lchild;
        
            pr->lchild = prl->rchild;
            p->rchild = prl->lchild;
        
            prl->rchild = pr;
            prl->lchild = p;
        
            pr->height = NodeHeight(pr);
            p->height = NodeHeight(p);
            prl->height = NodeHeight(prl);
        
            if (root == p){
                root = prl;
            }
            return prl;
        }

        Node* InPre(Node *p){
            while (p && p->rchild != nullptr){
                p = p->rchild;
            }
            return p;
        }
 
        Node* InSucc(Node *p){
            while (p && p->lchild != nullptr){
                p = p->lchild;
            }
            return p;
        }
    
        // Insert
        Node* rInsert(Node *p, int key){
            Node* t;
            if (p == nullptr){
                t = new Node;
                t->data = key;
                t->lchild = nullptr;
                t->rchild = nullptr;
                t->height = 1;  // Starting height from 1 onwards instead of 0
                return t;
            }
        
            if (key < p->data){
                p->lchild = rInsert(p->lchild, key);
            } else if (key > p->data){
                p->rchild = rInsert(p->rchild, key);
            }
        
            // Update height
            p->height = NodeHeight(p);
        
            // Balance Factor and Rotation
            if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
                return LLRotation(p);
            } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
                return LRRotation(p);
            } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
                return RRRotation(p);
            } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
                return RLRotation(p);
            }
        
            return p;
        }
    
        // Traversal
        void Inorder(Node *p) {
            if (p){
                Inorder(p->lchild);
                cout << p->data << " ";
                Inorder(p->rchild);
            }
        }
        
        Node* getRoot(){ return root; }
    
        // Delete
        Node* Delete(Node *p, int key) {
            if (p == nullptr){
                return nullptr;
            }
        
            if (p->lchild == nullptr && p->rchild == nullptr){
                if (p == root){
                    root = nullptr;
                }
                delete p;
                return nullptr;
            }
        
            if (key < p->data){
                p->lchild = Delete(p->lchild, key);
            } else if (key > p->data){
                p->rchild = Delete(p->rchild, key);
            } else {
                Node* q;
                if (NodeHeight(p->lchild) > NodeHeight(p->rchild)){
                    q = InPre(p->lchild);
                    p->data = q->data;
                    p->lchild = Delete(p->lchild, q->data);
                } else {
                    q = InSucc(p->rchild);
                    p->data = q->data;
                    p->rchild = Delete(p->rchild, q->data);
                }
            }
        
            // Update height
            p->height = NodeHeight(p);
        
            // Balance Factor and Rotation
            if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {  // L1 Rotation
                return LLRotation(p);
            }
            else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){  // L-1 Rotation
                return LRRotation(p);
            }
            else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){  // R-1 Rotation
                return RRRotation(p);
            }
            else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){  // R1 Rotation
                return RLRotation(p);
            }
            else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 0){  // L0 Rotation
                return LLRotation(p);
            }
            else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 0){  // R0 Rotation
                return RRRotation(p);
            }
        
            return p;
        }
};
 
int main() {
 
    AVL tree;
 
    int A[] = {10, 20, 30, 25, 28, 27, 5};
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        tree.root = tree.rInsert(tree.root, A[i]);
    }
 
    tree.Inorder(tree.root);
    cout<<endl;
 
    tree.Delete(tree.root, 28);
   
    tree.Inorder(tree.root);
    cout<<endl;
 
    return 0;
}