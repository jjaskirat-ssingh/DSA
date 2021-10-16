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
            char x = -1;
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

        int isOperand(char x){
            if(x == '+' || x == '-' || x == '*' || x == '/') return 0;
            else return 1;
        }        

        int precedence(char x){
            if(x == '+' || x == '-') return 1;
            else if(x == '*' || x == '/') return 2;
            else return 0;
        }

        char * InToPost(char * infix){
            int i=0, j=0;
            char *postfix;
            int len = strlen(infix);
            postfix = new char[len + 1];
            
            while(infix[i] != '\0'){
                if(isOperand(infix[i])){
                    postfix[j++] = infix[i++];
                }
                else{
                    if(precedence(infix[i]) > precedence(stackTop())){
                        push(infix[i++]);
                    }
                    else{
                        postfix[j++] = pop();
                    }
                }
            }
            while(top != -1){
                postfix[j++] = pop();
            }
            postfix[j] = '\0';
            return postfix;
        }

        int EvalPost(char *postfix){
            int x1, x2, r;
            for(int i=0; postfix[i]!='\0'; i++){
                if(isOperand(postfix[i]) == 1){
                    push(postfix[i] - '0');
                } 
                else{
                    x2 = pop();
                    x1 = pop();
                    switch(postfix[i]){
                        case '+':
                            r = x1 + x2;
                            break;
                        case '-':
                            r = x1 - x2;
                            break;
                        case '*':
                            r = x1 * x2;
                            break;
                        case '/':
                            r = x1 / x2;
                            break;
                        default:
                            break;
                    }
                    push(r); 
                }
            }
            return pop();
        }
};

int main(){
    char infix[] = "a+b*c-d/e";  
    int len = strlen(infix);
    Stack stk(len + 1);
    
    char *postfix = stk.InToPost(infix);
    cout<<postfix<<endl<<endl;

    char p[] = "235*+63/-";
    int result = stk.EvalPost(p);
    cout<<result;
    return 0;
}