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
        Node **Q;  
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

        Node* getRoot(){ return root; }

                
        int Height(Node *p) {
            int l = 0;
            int r = 0;
        
            if (p != nullptr){
                l = Height(p->lchild);
                r = Height(p->rchild);
                if (l > r){
                    return l + 1;
                } else {
                    return r + 1;
                }
            }
            return 0;
        }
        
        int Count(Node *p) {
            int x;
            int y;
            if (p != nullptr){
                x = Count(p->lchild);
                y = Count(p->rchild);
                return x + y + 1;
            }
            return 0;
        }
        
        int Sum(Node *p) {
            int x;
            int y;
            if (p != nullptr){
                x = Sum(p->lchild);
                y = Sum(p->rchild);
                return x + y + p->data;
            }
            return 0;
        }
        
        int deg2NodeCount(Node *p) {
            int x;
            int y;
            if (p != nullptr){
                x = deg2NodeCount(p->lchild);
                y = deg2NodeCount(p->rchild);
                if (p->lchild && p->rchild){
                    return x + y + 1;
                } else {
                    return x + y;
                }
            }
            return 0;
        }

};

int main(){
    Tree t;
    t.CreateTree();
 
    cout << "Height: " << t.Height(t.getRoot()) << endl;
    cout << "Count: " << t.Count(t.getRoot()) << endl;
    cout << "Sum: " << t.Sum(t.getRoot()) << endl;
    cout << "Count of degree 2 nodes: " << t.deg2NodeCount(t.getRoot()) << endl;
  
    
    return 0;
}