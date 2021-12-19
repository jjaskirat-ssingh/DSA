#include<iostream>
using namespace std;

class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
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

        void iterativePreorder(Node *p) {
            Stack stk(100);
            while(p || !stk.isEmptyStack()){
                if(p){
                    cout<<p->data<<" ";
                    stk.push(p);
                    p = p->lchild;
                }
                else{
                    p = stk.pop();
                    p = p->rchild;
                }
            }
        }

        void iterativeInorder(Node *p) {
            Stack stk(100);
            while(p || !stk.isEmptyStack()){
                if(p){
                    stk.push(p);
                    p = p->lchild;
                }
                else{
                    p = stk.pop();
                    cout<<p->data<<" ";
                    p = p->rchild;
                }
            }
        }
};

int main(){
    Tree t;
    t.CreateTree();

    cout<<"\nPreOrder: ";
    t.iterativePreorder(t.getRoot());
    cout<<"\nInOrder: ";
    t.iterativeInorder(t.getRoot());
    return 0;
}

