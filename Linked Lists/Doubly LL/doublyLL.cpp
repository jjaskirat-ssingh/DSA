#include<iostream>
using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first;

void CreateDoublyLL(int);
void Display(struct Node *);
int Length(struct Node *);
void Insert(struct Node *, int , int);
void Delete(struct Node *, int);
void Reverse(struct Node *);

int main(){
    int n;
    cout<<"Enter the total number of nodes: "; cin>>n;
    CreateDoublyLL(n);
    Display(first);
    Insert(first, 3, 444);
    Display(first);
    Delete(first, 3);
    Display(first);
    Reverse(first);
    Display(first);
    return 0;
}

void CreateDoublyLL(int n){
    int data;
    struct Node *newNode, *last;
    first = new Node;

    cout<<"Enter the data of node 1: "<<endl;
    cin>>data;
    first->data = data;
    first->next = NULL;
    first->prev = NULL;
    last = first;

    for(int i=2; i<=n; i++){
        newNode = new Node();
        cout<<"Enter the data of node "<<i<<": "<<endl;
        cin>>data;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;
        last->next = newNode;
        last = last->next;
    }
}

void Display(struct Node *p){
    while(p != NULL){
        cout<<p->data<<"\t";
        p = p->next;
    }
    cout<<endl;
}

int Length(struct Node *p){
    int len = 0;
    while(p != NULL){
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p, int index, int elem){
    struct Node *t;
    if(index<0 || index>Length(first)){
        return;
    }
    else{
        if(index==0){
            t = new Node;
            t->data = elem;    
            t->prev = NULL;
            t->next = first;
            first->prev = t;
            first = t;
        }
        else{
            for(int i=1; i<index; i++){
                p = p->next;
            }
            t = new Node;
            t->data = elem;
            t->prev = p;
            t->next = p->next;
            if(p->next != NULL){
                p->next->prev = t;
            }
            p->next = t;
        }
    }
}

void Delete(struct Node *p, int index){
    struct Node *t;
    if(index<0 || index>Length(first)){
        return;
    }
    else{
        if(index == 0){
            first = first->next;
            if(first != NULL){
                first->prev = NULL;
            }
            delete p;
        }
        else{
            for(int i=0; i<index; i++){
                p = p->next;
            }
            p->prev->next = p->next;
            if(p->next != NULL){
                p->next->prev = p->prev;
            }
            delete p;
        }
    }
}

void Reverse(struct Node *p){
    struct Node *tmp;
    while(p != NULL){
        tmp = p->next;
        p->next = p->prev;
        p->prev = tmp;
        p = p->prev;
        if(p != NULL && p->next == NULL){
            first = p;
        }
    }
}