#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head;

void createList(int);
void display();
struct Node * LSearch(struct Node *, int); // Linear Search with MOVE TO HEAD
struct Node * RSearch(struct Node *, int);

int main(){
    int n, key;
    struct Node *tmp;
    cout<<"Enter the number of elements in the linked list: "<<endl;
    cin>>n;
    createList(n);cout<<endl;
    display();
    cout<<"\n\nEnter the key to be searched: "; 
    cin>>key;
    tmp = LSearch(head, key);
    // tmp = RSearch(head, key);
    cout<<tmp->data<<endl;
    display();
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

struct Node * LSearch(struct Node *p, int key){
    struct Node *q = NULL;
    while(p!=NULL){
        if(p->data == key){
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node * RSearch(struct Node *p, int key){
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    return RSearch(p->next, key);
}