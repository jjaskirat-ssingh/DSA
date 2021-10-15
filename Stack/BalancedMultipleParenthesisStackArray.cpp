#include<iostream>
#include <cstring>
using namespace std;

class Stack{
    private:
        int size;
        int top;
        char *s;

    public:
        Stack(int size){
            this->size = size;
            top = -1;
            s = new char[size];
        }

        ~Stack(){
            delete[] s;
        }

        void push(char x){
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
            char x = -1;
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

        bool isMultipleBalanced(char* exp){
        int x;
        Stack stk((int)strlen(exp));
    
        for (int i=0; exp[i]!='\0'; i++){
            if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
                stk.push(exp[i]);
            }
            else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
                if (stk.isEmpty()){
                    return false;
                }
                else{
                    x = stk.pop();
                    if(exp[i] == ')'){
                        if(x == '(') continue;
                        else return false;
                    }
                    else if(exp[i] == ']'){
                        if(x == '[') continue;
                        else return false;
                    }
                    else if(exp[i] == '}'){
                        if(x == '{') continue;
                        else return false;
                    }
                }
            }
        }
        if(stk.isEmpty() == 1) return true;
        else return false; 
    }
 
};

int main(){
    Stack stkk(15);
    
    char exp[] = "[(([])({)})]";
    if(stkk.isMultipleBalanced(exp)) cout<<"Balanced";
    else cout<<"Unbalanced";
    return 0;
}