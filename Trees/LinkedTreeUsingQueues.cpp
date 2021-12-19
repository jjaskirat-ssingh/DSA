#include<iostream>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class Queue{
        int front;
        int rear;
        int size;
        Node **Q;   // Pointer to (Pointer to Node)
    public:
        Queue(){
            front = rear = -1;
            size = 10;
            Q = new Node *[size];
        }

        Queue(int size){
            front = rear = -1;
            this->size = size;
            Q = new Node *[size];
        }

        ~Queue(){
            delete []Q;
        }

        bool isEmpty(){
            if (front == rear) return true;
            else return 0;
        }

        bool isFull(){
            if (rear == size-1) return true;
            else return 0;
        }

        void enqueue(Node *x){
            if(isFull()){
                cout<<"Queue Overflow"<<endl;
            }
            else{
                rear++;
                Q[rear] = x;
            }
        }

        Node * dequeue(){
            Node * x = nullptr;
            if(isEmpty()){
                cout<<"Queue Underflow"<<endl;
            }
            else{
                front++;
                x = Q[front];
            }
            return x;
        }
};

class Tree{
        Node *root;
    public:
        Tree(){root = nullptr;}
        void CreateTree(){
            Node *p;
            Node *t;
            int x;

            Queue q(25);
            root = new Node;
            cout<<"\nEnter root value: ";
            cin>>x;
            root->data = x;
            root->lchild = nullptr;
            root->rchild = nullptr;
            q.enqueue(root);

            while (!q.isEmpty()){
                p = q.dequeue();
        
                cout<<"Enter left child value of "<<p->data<<": ";
                cin>>x;
                if (x != -1){
                    t = new Node;
                    t->data = x;
                    t->lchild = nullptr;
                    t->rchild = nullptr;
                    p->lchild = t;
                    q.enqueue(t);
                }
        
                cout<<"Enter right child value of "<<p->data<<": ";
                cin>>x;
                if (x != -1){
                    t = new Node;
                    t->data = x;
                    t->lchild = nullptr;
                    t->rchild = nullptr;
                    p->rchild = t;
                    q.enqueue(t);
                }
            }
        }

        void Preorder(Node *p){
            if(p){
                cout<<p->data<<", ";
                Preorder(p->lchild);
                Preorder(p->rchild);
            }
        }

        void Inorder(Node *p){
            if(p){
                Inorder(p->lchild);
                cout<<p->data<<", ";
                Inorder(p->rchild);
            }
        }

        void Postorder(Node *p){
            if(p){
                Postorder(p->lchild);
                Postorder(p->rchild);
                cout<<p->data<<", ";
            }
        }

        Node* getRoot(){ return root; }


};

int main(){
    Tree t;
    t.CreateTree();

    cout<<"\nPreOrder: ";
    t.Preorder(t.getRoot());
    cout<<"\nInOrder: ";
    t.Inorder(t.getRoot());
    cout<<"\nPostOrder: ";
    t.Postorder(t.getRoot());
    return 0;
}