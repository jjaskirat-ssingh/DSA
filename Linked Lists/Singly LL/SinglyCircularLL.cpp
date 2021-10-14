#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head;

void createCircluarList(int n);
void display(struct Node *);
void recursive_display(struct Node *);
int Length(struct Node *);
void Insert(struct Node *,int , int);
int Delete(struct Node *,int);

int main(){
    int n;
    cout<<"Enter the number of elements in the singly circular linked list: "<<endl;
    cin>>n;
    createCircluarList(n);cout<<endl;
    cout<<endl<<endl;
    display(head);
    // recursive_display(head);
    cout<<endl<<endl;
    Insert(head, 3, 555);
    display(head);
    cout<<endl<<endl;
    Delete(head, 3);
    display(head);
    return 0;
}

void createCircluarList(int n){
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
        head->next = head;

        tmp = head;
        for(int i=2; i<=n; i++){
            newNode = new Node();
            
            cout<<"Enter the data of node "<<i<<": "<<endl;
            cin>>data;

            newNode->data = data;
            newNode->next = head;

            tmp->next = newNode;
            tmp = tmp->next;
        }
    }
}

void display(struct Node *p){
    do{
        cout<<p->data<<"\t";
        p = p->next;
    }while(p != head);
}

void recursive_display(struct Node *p){
    static int flag = 0;
    if(p != head || flag == 0){
        flag = 1;
        cout<<p->data<<"\t";
        recursive_display(p->next);
    }
    flag = 0; 
}

int Length(struct Node *p){
    int len = 0;
    do{
        len++;
        p = p->next;
    }while(p != head);
    return len;
}

void Insert(struct Node *p, int index, int elem){
    struct Node *t;
    if(index < 0 || index > Length(head)){
        return;
    }

    if(index == 0){
        t = new Node();
        t->data = elem;
        
        if(head == NULL){
            head = t;
            head->next = head;
        }
        else{
            while(p->next != NULL) p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else{
        for(int i=0; i<index-1; i++) p = p->next;
        t = new Node();
        t->data = elem;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index){
    struct Node *t;
    int x;
    if(index < 0 || index > Length(head)){
        return -1;
    }

    if(index==0){
        while(p->next != head) p = p->next;
        x = head->data;
        if(head == p){
            free(head);
            head = NULL;
        }
        else{
            p->next = head->next;
            free(head);
            head = NULL;
        }
   }
   else{
       for(int i=0; i<index-1; i++) p=p->next;
        t = p->next;
        p->next = t->next;
        x = t->data;
        delete t;
   }
   return x;
}