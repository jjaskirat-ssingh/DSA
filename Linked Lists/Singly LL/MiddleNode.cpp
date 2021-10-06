
#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head;

void display(){
    if(head == NULL){
        printf("List is empty.");
        return;
    }
    struct Node *tmp = head;
    for(tmp = head; tmp!=NULL; tmp=tmp->next){
        cout<<tmp->data<<"\t";
    }
    cout<<endl;
}

void createList(int n){
    struct Node *newNode, *tmp;
    int data;
    
    head = new Node();

    if(head==NULL){
        cout<<"Head is NULL."<<endl;
        exit(0);
    }
    else{
        cout<<"Enter the first element: "<<endl;
        scanf("%d", &data);
        head->data = data;
        head->next=NULL;

        tmp = head;
        for(int i=2; i<=n; i++){
            newNode = new Node();
            if (newNode==NULL){
                cout<<"NULL pointer"<<endl;
                break;
            }
            
            cout<<"Enter the data of node "<<i<<": "<<endl;
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;

            tmp->next = newNode;
            tmp = tmp->next;
        }
    }
}

void middleNode(){
    struct Node *tmp, *ptr;
    if(head == NULL){
        cout<<"List empty."<<endl;
    }
    else{
        int count=0;
        tmp = head;
        while(tmp!=NULL){
            tmp = tmp->next;
            count++;
        }
        cout<<"Total number of nodes: "<<count<<endl;
        ptr=head;
        for(int i=0; i<(count/2); i++){
            ptr = ptr->next;
        }
        cout<<"The data of node in the middle of linked list: "<<ptr->data<<endl;
    }
}

int main(){
    int n, key;
    cout<<"Create a linked list. "<<endl;
    cout<<"Enter the initial number of elements in the linked list: "<<endl;
    cin>>n;
    createList(n);
    cout<<endl<<"Your present linked list: "<<endl;
    display();
    cout<<endl;
    middleNode();
    return 0;
}