#include<iostream>
using namespace std;

class CircularQueue{
    private:
        int size;
        int front;
        int rear;
        int *Q;

    public:
        CircularQueue(){
            front = rear = 0;
            size = 10;
            Q = new int[size];
        }

        CircularQueue(int size){
            front = rear = 0;
            this->size = size;
            Q = new int[size];
        }

        ~CircularQueue(){delete[] Q;}

        bool isEmpty(){
            if(front == rear){
                return true;
            }
            else return false;
        }

        bool isFull(){
            if(((rear + 1) % size) == front) return true;
            else return false;
        }

        void enqueue(int elem){
            if(isFull()) cout<<"Queue Overflow\n";
            else{
                rear = (rear + 1) % size;
                Q[rear] = elem;
            }
        }

        int dequeue(){
            int x = -1;
            if(isEmpty()) cout<<"Queue Underflow\n";
            else{
                front = (front + 1) % size;
                x = Q[front];
            }
            return x;
        }

        void display(){
            int i = front + 1;
            do{
                cout<<Q[i]<<"\t"<<flush;
                i = (i + 1) % size;
            }while(i != ((rear + 1) % size));
            cout<<endl;
        }
};

int main(){
    int A[] = {1, 3, 5, 7, 9};
    int size = sizeof(A)/sizeof(A[0]) + 1; // +1 because front and rear point at index 0 in circular queue initially. 
    CircularQueue q(size);

    for (int i=0; i<size-1; i++){
        q.enqueue(A[i]);
        q.display();
    }
    
    return 0;
}