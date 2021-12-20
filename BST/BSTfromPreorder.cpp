#include<iostream>
using namespace std;

class Node{
    public:
        Node* lchild;
        int data;
        Node* rchild;
};

class Stack{
    private:
        int size;
        int top;
        Node **s;

    public:
        Stack(int size){
            this->size = size;
            top = -1;
            s = new Node *[size];
        }

        ~Stack(){
            delete[] s;
        }

        void push(Node *x){
            if(isFull() == 1){
                cout<<"Stack overflow!\n";
            }
            else{
                top++;
                s[top] = x;
            }
        }

        Node * pop(){
            Node * x = nullptr;
            if(isEmptyStack() == 1){
                cout<<"Stack underflow!\n";
            }
            else{
                x = s[top];
                top--;
            }
            return x;
        }

        int isFull(){
            if(top == size-1) return 1;
            else return 0;
        }

        int isEmptyStack(){
            if(top == -1) return 1;
            else return 0;
        }

        void display(){
            for(int i=top; i>=0; i--){
                cout<<s[i]<<" | "<<flush; 
            }
            cout<<endl;
        }

        Node * stackTop(){
            if(isEmptyStack() == 1) return nullptr;
            else return s[top];
        }
};

class BST{
    private: 
        Node *root;
    public:
        BST(){ root = nullptr; }
        
        Node *getRoot(){ return root; }

        void iInsert(int key){
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

        Node * iSearch(int key){
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

        void Inorder(Node* p){
            if (p){
                Inorder(p->lchild);
                cout << p->data << " ";
                Inorder(p->rchild);
            }
        }

        Node * rInsert(Node *p, int key){
            Node *t;
            if (p == nullptr){
                t = new Node;
                t->data = key;
                t->lchild = t->rchild = nullptr;
                return t;
            }

            if (key < p->data){
                p->lchild = rInsert(p->lchild, key);
            }
            else if (key > p->data){
                p->rchild = rInsert(p->rchild, key);
            } 
            return p; // key == p->data
        }

        Node * rSearch(Node *p, int key){
            if (p == nullptr){
                return nullptr;
            }

            if(key == p->data){
                return p;
            }
            else if (key < p->data){
                return rSearch(p->lchild, key);
            }
            else{
                return rSearch(p->rchild, key);
            }
        }

        int Height(Node *p){
            int x, y;
            if (p == nullptr){
                return 0;
            }
            x = Height(p->lchild);
            y = Height(p->rchild);
            return x > y ? x+1 : y+1;
        }

        Node * InPre(Node *p){  // Right-most of left side or left subtree
            while(p && p->rchild != nullptr){
                p = p->rchild;
            }
            return p;
        }

        Node * InSucc(Node *p){ // Left-most of right side or right subtree
            while(p && p->lchild != nullptr){
                p = p->lchild;
            }
            return p;
        }

        Node * Delete(Node *p, int key){
            Node *q;

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
            }
            else if (key > p->data){
                p->rchild = Delete(p->rchild, key);
            }
            else{
                if(Height(p->lchild) > Height(p->rchild)){
                    q = InPre(p->lchild);
                    p->data = q->data;
                    p->lchild = Delete(p->lchild, q->data);
                }
                else{
                    q = InSucc(p->rchild);
                    p->data = q->data;
                    p->rchild = Delete(p->rchild, q->data);
                }
            }
            return p;
        }

        void createFromPreorder(int *pre, int n) {
        
            // Create root node
            int i = 0;
            root = new Node;
            root->data = pre[i++];
            root->lchild = nullptr;
            root->rchild = nullptr;
        
            // Iterative steps
            Node* t;
            Node* p = root;
            Stack stk(100);
        
            while (i < n){
                // Left child case
                if (pre[i] < p->data){
                    t = new Node;
                    t->data = pre[i++];
                    t->lchild = nullptr;
                    t->rchild = nullptr;
                    p->lchild = t;
                    stk.push(p);
                    p = t;
                } else {
                    // Right child cases
                    if (pre[i] > p->data && pre[i] < stk.isEmptyStack() ? 32767 : stk.stackTop()->data){
                        t = new Node;
                        t->data = pre[i++];
                        t->lchild = nullptr;
                        t->rchild = nullptr;
                        p->rchild = t;
                        p = t;
                    } else {
                        p = stk.stackTop();
                        stk.pop();
                    }
                }
            }
        }
};

int main(){
    cout << "BST from Preorder: " << flush;
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre)/sizeof(pre[0]);
 
    BST b;
    b.createFromPreorder(pre, n);
    b.Inorder(b.getRoot());
    cout << endl;
    
    return 0;
}