#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){
        top = NULL;                   
    }

    ~Stack(){
        Node *p = top;
        while(top != NULL){
            top = top->next;
            delete p;
            p =top;
        }
    }

    void push(int x){
        Node *t = new Node;
        if(t == NULL){
            cout<<"Stack Overflow!\n";
        }
        else{
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    int pop(){
        Node *p;
        int x = -1;
        if(top == NULL){
            cout<<"Stack Underflow!\n";
        }
        else{
            p = top;
            x = p->data;
            top = top->next;
            delete p; 
        }
        return x;
    }

    int peek(int pos){
        if (isEmpty() == 1){
            return -1;
        } 
        else{
            Node* p = top;
    
            for (int i=0; p != NULL && i<pos-1; i++){
                p = p->next;
            }
    
            if (p != NULL){
                return p->data;
            }
            else{
                return -1;
            }
        }
    }

    int isEmpty(){
        if(top == NULL) return 1;
        else return 0;
    }

    int isFull(){
        Node *t = new Node;
        int r;
        if(t != NULL) r = 1;
        else r = 0;
        delete t;
        return r;
    }

    int stackTop(){
        if(top != NULL) return top->data;
        return -1;
    }
};

int main(){
    int A[] = {1, 3, 5, 7, 9};
    Stack stk;
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        stk.push(A[i]);
    }
 
    cout<<"Stack peek at 3rd: "<<stk.peek(3)<<endl;
    cout<<"Stack peek at 10th: "<<stk.peek(10)<<endl;
    cout<<"Stack top: "<<stk.stackTop()<<endl;
    cout<<"Stack full: "<<stk.isFull()<<endl;
    cout<<"Stack empty: "<<stk.isEmpty()<<endl;
 
    cout<<"Popped: " <<flush;
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cout<<stk.pop()<<", "<<flush;
    }
    cout<<endl;
 
    cout<<stk.pop()<<endl;
 
    return 0;
}