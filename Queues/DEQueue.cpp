#include<iostream>
using namespace std;

class DEQueue{
    private:
        int size;
        int front;
        int rear;
        int *Q;

    public:
        DEQueue(){
            front = rear = -1;
            size = 10;
            Q = new int[size];
        }

        DEQueue(int size){
            front = rear = -1;
            this->size = size;
            Q = new int[size];
        }

        ~DEQueue(){delete[] Q;}

        bool isEmpty(){
            if(front == rear){
                return true;
            }
            else return false;
        }

        bool isFull(){
            if(rear == size-1) return true;
            else return false;
        }

        void enqueueFront(int elem){
            if(front == -1) cout<<"DEQueue Overflow\n";
            else{
                Q[front] = elem;
                front--;
            }
        }

        void enqueueRear(int elem){
            if(isFull()) cout<<"DEQueue Overflow\n";
            else{
                rear++;
                Q[rear] = elem;
            }
        }

        int dequeueFront(){
            int x = -1;
            if(isEmpty()) cout<<"DEQueue Underflow\n";
            else{
                front++;
                x = Q[front];
            }
            return x;
        }

        int dequeueRear(){
            int x = -1;
            if(rear == -1) cout<<"DEQueue Underflow\n";
            else{
                x = Q[rear];
                rear--;
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
    int B[] = {2, 4, 6, 8};
    int size1 = sizeof(A)/sizeof(A[0]);
    int size2 = sizeof(B)/sizeof(B[0]);
    DEQueue deq(size1);
 
    for (int i=0; i<size1; i++){
        deq.enqueueRear(A[i]);
        deq.display();
    }
    deq.enqueueRear(11);
 
    for (int i=0; i<size1; i++){
        deq.dequeueFront();
        deq.display();
    }
    deq.dequeueFront();
 
    cout<<endl;
 
    for (int i=0; i<size2; i++){
        deq.enqueueFront(B[i]);
        deq.display();
    }
    deq.enqueueFront(10);
    deq.enqueueFront(12);
 
    for (int i=0; i<size2; i++){
        deq.dequeueRear();
        deq.display();
    }
    deq.dequeueRear();
    deq.dequeueRear();

    return 0;
}