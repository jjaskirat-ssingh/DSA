#include<iostream>
using namespace std;

class Node{
    public:
        Node *lchild;
        int data;
        Node *rchild;
        Node(){}
        Node(int data) {
            lchild = nullptr;
            this->data = data;
            rchild = nullptr;
        }
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

        void Preorder(Node *p){
            if(p){
                cout<<p->data<<" ";
                Preorder(p->lchild);
                Preorder(p->rchild);
            }
        }

        Node* getRoot(){ return root; }

        int searchInorder(int inArray[], int inStart, int inEnd, int data){
            for (int i=inStart; i<=inEnd; i++){
                if (inArray[i] == data){
                    return i;
                }
            }
            return -1;
        }

        Node* generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd){
            static int preIndex = 0;
            
            if(inStart > inEnd){
                return nullptr;
            }

            Node * node = new Node(preorder[preIndex]);
            preIndex = preIndex + 1;

            if (inStart == inEnd){
                return node;
            }            

            int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
            node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
            node->rchild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);
        
            return node;
        }
        
};

int main(){
    Tree bt;
 
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
 

    Node* T = bt.generateFromTraversal(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0])-1);
    bt.Preorder(T);
    
    return 0;
}