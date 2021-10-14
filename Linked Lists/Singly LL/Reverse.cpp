#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head;

void createList(int);
void display();
int count(struct Node *);
void Reverse(struct Node *);
void ReverseLinks(struct Node *);
void RecursiveReverse(struct Node *, struct Node *);

int main(){
    int n;
    cout<<"Enter the number of elements in the linked list: "<<endl;
    cin>>n;
    createList(n);cout<<endl;
    display();
    Reverse(head);
    // ReverseLinks(head);
    // RecursiveReverse(NULL, head);
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

int count(struct Node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

// This function does not reverse the links, it swaps elements (or reverses elements)
void Reverse(struct Node *p){ 
    int *A, i=0;
    struct Node *q = p;
    A = new int(count(p));
    while(q != NULL){
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while(q != NULL){
        q->data = A[i];
        q = q->next;
        i--;
    }
}

// Reverses links using sliding pointers
void ReverseLinks(struct Node *p){
    struct Node *q = NULL, *r = NULL;
    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void RecursiveReverse(struct Node *q, struct Node *p){
    if(p){
        RecursiveReverse(p, p->next);
        p->next = q;
    }
    else{
        head = q;
    }
}