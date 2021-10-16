#include<iostream>
using namespace std;

class Queue{
    private:
        int size;
        int front;
        int rear;
        int *Q;

    public:
        Queue(){
            front = rear = -1;
            size = 10;
            Q = new int[size];
        }

        Queue(int size){
            front = rear = -1;
            this->size = size;
            Q = new int[size];
        }

        ~Queue(){delete[] Q;}

        bool isEmpty(){
            if(front == rear){
                front = rear = -1; // to avoid the condition when the queue is both, empty and full 
                return true;
            }
            else return false;
        }

        bool isFull(){
            if(rear == size-1) return true;
            else return false;
        }

        void enqueue(int elem){
            if(isFull()) cout<<"Queue Overflow\n";
            else{
                rear++;
                Q[rear] = elem;
            }
        }

        int dequeue(){
            int x = -1;
            if(isEmpty()) cout<<"Queue Underflow\n";
            else{
                front++;
                x = Q[front];
            }
            return x;
        }

        void display(){
            for(int i=front+1; i<=rear; i++){
                cout<<Q[i]<<"\t"<<flush;
            }
            cout<<endl;
        }
};

int main(){
    int A[] = {1, 3, 5, 7, 9};
    int size = sizeof(A)/sizeof(A[0]);
    Queue q(size);
 
    // Enqueue
    for (int i=0; i<size; i++){
        q.enqueue(A[i]);
        q.display();
    }
  
    // Overflow
    q.enqueue(10);
 
    // Dequeue
    for (int i=0; i<size; i++){
        q.dequeue();
        q.display();
    }
 
    // Underflow
    q.dequeue();
    return 0;
}