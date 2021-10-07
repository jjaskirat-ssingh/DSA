#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head;

void createList(int);
void display();
void recursive_display(struct Node *);

int main(){
    int n;
    cout<<"Enter the initial number of elements in the linked list: "<<endl;
    cin>>n;
    createList(n);
    cout<<"\nYour present linked list: "<<endl;
    display();
    cout<<"\nUsing Recursive function: "<<endl;
    recursive_display(head);
    return 0;
}

void createList(int n){
    struct Node *newNode, *tmp;
    int data;
    
    head = new Node();

    if(head==NULL){
        cout<<"Head is NULL.\n";
        exit(0);
    }
    else{
        cout<<"Enter the data of node 1: "<<endl;
        cin>>data;
        head->data = data;
        head->next = NULL;

        tmp = head;
        for(int i=2; i<=n; i++){
            newNode = new Node();
            if (newNode==NULL){
                cout<<"NULL pointer"<<endl;
                break;
            }
            
            cout<<"Enter the data of node "<<i<<": "<<endl;
            cin>>data;

            newNode->data = data;
            newNode->next = NULL;

            tmp->next = newNode;
            tmp = tmp->next;
        }
    }
}

void display(){
    if(head==NULL){
        cout<<"List is empty."<<endl;
        return;
    }
    struct Node *tmp = head;
    for(tmp = head; tmp!=NULL; tmp=tmp->next){
        cout<<tmp->data<<"\t";
    }
    cout<<endl;
}

void recursive_display(struct Node *p){
    if(p!=NULL){
        cout<<p->data<<"\t";
        recursive_display(p->next);
    }
}