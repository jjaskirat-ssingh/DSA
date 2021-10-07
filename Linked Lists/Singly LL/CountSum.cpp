#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head;

void createList(int);
void display();
void recursive_display(struct Node *);
int count(struct Node *);
int recursive_count(struct Node *);
int sum(struct Node *);
int recursive_sum(struct Node *);

int main(){
    int n;
    cout<<"Enter the number of elements in the linked list: "<<endl;
    cin>>n;
    createList(n);cout<<endl;
    display();
    cout<<"\nResult of count function: "<<count(head)<<endl;
    cout<<"\nResult of recursive count function: "<<recursive_count(head)<<endl;
    cout<<"\nResult of sum function: "<<sum(head)<<endl;
    cout<<"\nResult of recursive sum function: "<<recursive_sum(head)<<endl;    
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

int count(struct Node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

int recursive_count(struct Node *p){
    if(p!=NULL)
        return recursive_count(p->next)+1;
    else return 0;
}

int sum(struct Node *p){
   int s=0;
    while(p!=NULL){
        s+=p->data;
        p=p->next;
    }
    return s;
}

int recursive_sum(struct Node *p){
    if(p!=NULL){
        return recursive_sum(p->next)+p->data;
        p=p->next;
    }
    else return 0;
}
