#include<iostream>
using namespace std;

class Node{
    public: 
        Node *lchild;
        int data;
        Node *rchild;
        int height;
};

class AVL{
    public:
        Node *root;

        AVL(){ root = nullptr; }

        Node *getRoot(){ return root; }
        
        int NodeHeight(Node *p){
            int hl, hr;

            hl = (p && p->lchild) ? p->lchild->height : 0;
            hr = (p && p->rchild) ? p->rchild->height : 0;

            return hl > hr ? hl+1 : hr+1;
        }

        int BalanceFactor(Node *p){
            int hl, hr;

            hl = (p && p->lchild) ? p->lchild->height : 0;
            hr = (p && p->rchild) ? p->rchild->height : 0;

            return hl - hr;
        }

        Node * LLRotation(Node *p){
            Node *pl = p->lchild;
            Node *plr = pl->rchild;

            pl->rchild = p;
            pl->lchild = plr;

            // Update height
            p->height = NodeHeight(p);
            pl->height = NodeHeight(pl); 
            // height of plr remains same

            // Update root
            if (root == p) root = pl;
            
            return pl;
        }

        Node * RRRotation(Node *p){
            Node* pr = p->rchild;
            Node* prl = pr->lchild;
        
            pr->lchild = p;
            p->rchild = prl;
        
            p->height = NodeHeight(p);
            pr->height = NodeHeight(pr);
        
            if (root == p) root = pr;
            
            return pr;
        }

        Node * LRRotation(Node *p){
            Node *pl = p->lchild;
            Node *plr = pl->rchild;

            pl->rchild = plr->lchild;
            p->lchild = plr->rchild;

            plr->lchild = pl;
            plr->rchild = p;

            pl->height = NodeHeight(pl);
            p->height = NodeHeight(p);
            plr->height = NodeHeight(plr);

            if (root == p) root = plr;
            
            return plr;
        }

        Node * RLRotation(Node *p){
            Node* pr = p->rchild;
            Node* prl = pr->lchild;
        
            pr->lchild = prl->rchild;
            p->rchild = prl->lchild;
        
            prl->rchild = pr;
            prl->lchild = p;
        
            pr->height = NodeHeight(pr);
            p->height = NodeHeight(p);
            prl->height = NodeHeight(prl);
  
            if (root == p) root = prl;
            
            return prl;
        }

        Node * rInsert(Node *p, int key){
            Node *t;

            if (p == nullptr){
                t = new Node;
                t->data = key;
                t->lchild = t->rchild = nullptr;
                t->height = 1;      // Starting height from 1 instead of 0
                return t;
            }

            if (key < p->data){
                p->lchild = rInsert(p->lchild, key);
            }
            else if (key > p->data){
                p->rchild = rInsert(p->rchild, key);
            }

            // Update height
            p->height = NodeHeight(p);

            // Balance Factor and Rotation
            if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
                return LLRotation(p);
            }
            else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
                return LRRotation(p);
            }
            else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
                return RRRotation(p);
            }
            else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
                return RLRotation(p);
            }
            return p;
        }

        void Inorder(Node *p) {
            if (p){
                Inorder(p->lchild);
                cout<<p->data<<" ";
                Inorder(p->rchild);
            }
        }
};

int main(){
    // LR Rotation
    AVL tlr;
    tlr.root = tlr.rInsert(tlr.root, 50);
    tlr.root = tlr.rInsert(tlr.root, 10);
    tlr.root = tlr.rInsert(tlr.root, 20);
 
 
    tlr.Inorder(tlr.root);
    cout << endl;
    cout << tlr.root->data << endl;
 
    // RL Rotation
    AVL trl;
    trl.root = trl.rInsert(trl.root, 20);
    trl.root = trl.rInsert(trl.root, 50);
    trl.root = trl.rInsert(trl.root, 30);
 
 
    trl.Inorder(trl.root);
    cout << endl;
    cout << trl.root->data << endl;
 
    return 0;
}