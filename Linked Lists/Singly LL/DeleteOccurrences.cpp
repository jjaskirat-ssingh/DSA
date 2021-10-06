// Write a program to count the number of occurrences of a given key in a singly linked 
// list and then delete all the occurrences. For example, if given linked list is 1->2->1-
// >2->1->3->1 and given key is 1, then output should be 4. After deletion of all the 
// occurrences of 1, the linked list is 2->2->3.

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
        cin>>data;
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
            cin>>data;

            newNode->data = data;
            newNode->next = NULL;

            tmp->next = newNode;
            tmp = tmp->next;
        }
    }
}

void countOccurrences(int key){
    int count=0;
    if(head == NULL){
        printf("List is empty.");
        return;
    }
    struct Node *tmp = head;
    for(tmp = head; tmp!=NULL; tmp=tmp->next){
        if(tmp->data == key) count++;
    }
    cout<<"\n"<<key<<" occured "<<count<<" times.\n";
}

void deleteOccurrences(int key){
    if(head == NULL){
        printf("List is empty.");
        return;
    }

    while(head!=NULL && head->data==key)    // if key matches the data of first node
        head=head->next;
  
    struct Node *tmp = head;
    struct Node *ptr = NULL;
    while(tmp->next != NULL){
        if(tmp->next->data == key){
            Node *ptr = tmp->next;
            tmp->next=tmp->next->next;
            delete ptr;
        }
        else{
            tmp=tmp->next;
        }
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
    cout<<"Enter the key: "<<endl;
    cin>>key;
    countOccurrences(key);
    deleteOccurrences(key);
    cout<<"\nNew List after deletion of all occurrences: \n";
    display();
    return 0;
}