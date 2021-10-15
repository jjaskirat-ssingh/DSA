#include<iostream>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        int *s;

    public:
        Stack(int size){
            this->size = size;
            top = -1;
            s = new int[size];
        }

        ~Stack(){
            delete[] s;
        }

        void push(int x){
            if(isFull() == 1){
                cout<<"Stack overflow!\n";
            }
            else{
                top++;
                s[top] = x;
            }
        }

        int pop(){
            int x = -1;
            if(isEmpty() == 1){
                cout<<"Stack underflow!\n";
            }
            else{
                x = s[top];
                top--;
            }
            return x;
        }

        int peek(int pos){
            int x = -1;
            if((top-pos+1) <= 0 || (top-pos+1) > size){
                cout<<"Invalid position!\n";
            }
            else{
                x = s[top-pos+1];
            }
            return x;
        }

        int isFull(){
            if(top == size-1) return 1;
            else return 0;
        }

        int isEmpty(){
            if(top == -1) return 1;
            else return 0;
        }

        void display(){
            for(int i=top; i>=0; i--){
                cout<<s[i]<<" | "<<flush; 
            }
            cout<<endl;
        }

        int stackTop(){
            if(isEmpty() == 1) return -1;
            else return s[top];
        }
};

int main(){
    int A[] = {1, 3, 5, 7, 9};
    Stack stk(sizeof(A)/sizeof(A[0]));
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        stk.push(A[i]);
    }
    stk.push(11);
 
    cout << "Stack full: " << stk.isFull() << endl;
 
    cout << "Stack: " << flush;
    stk.display();
 
    cout << "Peek at 1st: " << stk.peek(1) << endl;
    cout << "Peek at 3rd: " << stk.peek(3) << endl;
    cout << "Peek at 10th: " << stk.peek(10) << endl;
 
    cout << "Top element: " << stk.stackTop() << endl;
 
    cout << "Popped out elements: " << flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout << stk.pop() << ", " << flush;
    }
    cout << endl;
    stk.pop();
 
    cout << "Stack empty: " << stk.isEmpty() << endl;
 
    return 0;
}