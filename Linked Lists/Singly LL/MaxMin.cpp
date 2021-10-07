#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head;

void createList(int);
void display();
int max(struct Node *);
int recursive_max(struct Node *);
int min(struct Node *);
int recursive_min(struct Node *);

int main(){
    int n;
    cout<<"Enter the number of elements in the linked list: "<<endl;
    cin>>n;
    createList(n);cout<<endl;
    display();
    cout<<"\nResult of max function: "<<max(head)<<endl;
    cout<<"\nResult of recursive max function: "<<recursive_max(head)<<endl;
    cout<<"\nResult of min function: "<<min(head)<<endl;
    cout<<"\nResult of recursive min function: "<<recursive_min(head);
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
    struct Node *tmp;
    for(tmp = head; tmp!=NULL; tmp=tmp->next){
        cout<<tmp->data<<"\t";
    }
    cout<<endl;
}

int max(struct Node *p){
    int m = INT32_MIN;
    while(p!=NULL){
        if(p->data > m){
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

int recursive_max(struct Node *p){
    int m=0;
    if(p==NULL) return INT32_MIN;
    m = recursive_max(p->next);
    return m > p->data ? m : p->data;
}

int min(struct Node *p){
    int m = INT32_MAX;
    while(p!=NULL){
        if(p->data < m){
            m = p->data;
        }
        p = p->next;
    }
    return m;
}

int recursive_min(struct Node *p){
    int m=0;
    if(p==NULL) return INT32_MAX;
    m = recursive_min(p->next);
    return m < p->data ? m : p->data;
}