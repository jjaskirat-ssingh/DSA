#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Queue{
    private:
        Node *front;
        Node *rear;
    
    public:
        Queue(){
            front = nullptr;
            rear = nullptr;
        }

        ~Queue(){
            Node *p = front;
            while(front){
                front = front->next;
                delete p;
                p = front;
            }
        }

        bool isEmpty(){
            if(front == nullptr) return true;
            else return false;
        }
        
        void enqueue(int elem){
            Node *t = new Node;
            if(t == nullptr) cout<<"Queue Overflow (Heap is full!)\n";
            else{
                t->data = elem;
                t->next = nullptr;
                if(front == nullptr){
                    front = t;
                    rear = t; 
                }
                else{
                    rear->next = t;
                    rear = t;
                }
            }
        }

        int dequeue(){
            int x = -1;
            Node *p;
            if(isEmpty()) cout<<"Queue Underflow\n";
            else{
                p = front;
                front = front->next;
                x = p->data;
                delete p;
            }
            return x;
        }

        void display(){
            Node *p = front;
            while(p){
                cout<<p->data<<"\t"<<flush;
                p = p->next;
            }
            cout<<endl;
        }
};

int main(){
    int A[] = {1, 3, 5, 7, 9};
    int size = sizeof(A)/sizeof(A[0]);
    Queue q;
    for (int i=0; i<size; i++){
        q.enqueue(A[i]);
        q.display();
    }
 
    for (int i=0; i<size; i++){
        q.dequeue();
        q.display();
    }

    q.dequeue();
    
    return 0;
}