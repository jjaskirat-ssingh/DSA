#include<iostream>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class BST{
    private: 
        Node *root;
    public:
        BST(){ root = nullptr; }
        
        Node *getRoot(){ return root; }

    void Insert(int key){
        Node *t = root;
        Node *p;
        Node *r;

        // If no root exists
        if(root == nullptr){
            p = new Node;
            p->data = key;
            p->lchild = p->rchild = nullptr;
            root = p;
            return;
        }

        while(t!=nullptr){
            r = t;
            if (key < t->data){
                t = t->lchild;
            }
            else if (key > t->data){
                t = t->rchild;
            }
            else return;
        }

        // t is pointing at NULL and r is pointing at insertion location
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = nullptr;

        if (key < r->data) r->lchild = p;
        else r->rchild = p;
    }

    void Inorder(Node* p){
        if (p){
            Inorder(p->lchild);
            cout << p->data << " ";
            Inorder(p->rchild);
        }
    }

    Node * Search(int key){
        Node *t = root;
        while (t!=nullptr){
            if (key == t->data){
                return t;
            }
            else if (key < t->data){
                t = t->lchild;
            }
            else{
                t = t->rchild;
            }
        }
        return nullptr;
    }

};

int main(){
    BST bst;
 
    // Insert
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);
 
    // Inorder traversal
    bst.Inorder(bst.getRoot());
    cout << endl;
 
    // Search
    Node* temp = bst.Search(2);
    if (temp != nullptr){
        cout<<temp->data<<" found! "<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;
}