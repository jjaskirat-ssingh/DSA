#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head;

void createList(int);
void display();
void RemoveDuplicates(struct Node *);

int main(){
    int n;
    cout<<"Enter the number of elements in the sorted linked list: "<<endl;
    cin>>n;
    createList(n);cout<<endl;
    display();
    RemoveDuplicates(head);
    cout<<endl<<endl;
    display();
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

void RemoveDuplicates(struct Node *p){
    struct Node *q = p->next;
    while(q!=NULL){
        if(p->data != q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}