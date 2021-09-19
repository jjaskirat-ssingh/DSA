#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class LinkedList{
    private:
        Node *first;

    public:
        LinkedList(){first = NULL;}

        LinkedList(int A[], int n){
            Node *last, *tmp;
            int i=0;
            first = new Node;
            first->data = A[0];
            first->next = NULL;
            last = first;
            for(i=1; i<n; i++){
                tmp = new Node;
                tmp->data = A[i];
                tmp->next = NULL;
                last->next = tmp;
                last = tmp;
            }
        }

        ~LinkedList(){
            Node *p = first;
            while(first != NULL){
                first = first->next;
                delete p;
                p=first;
            }
        }

        void display(){
            if(first == NULL){
                cout<<"List is empty.\n";
                return;
            }
            Node *p;
            for(p = first; p!=NULL; p=p->next){
                cout<<p->data<<"\t";
            }
            cout<<endl;
        }

        int getLength(){
            if(first == NULL){
                cout<<"List is empty.\n";
                return 0;
            }
            int length = 0;
            Node *p;
            for(p = first; p!=NULL; p=p->next){
                length++;
            }
            return length;
        }

        int getPosition(int el){
            int pos = 0;
            Node *p;
            for(p = first; p->data!=el; p=p->next){
                pos++;
            }
            return pos; // it retruns the index value to be precise
        }
        
        void insertBeginning(int data){
            Node *tmp;
            tmp = new Node;
            tmp->data = data;
            tmp->next = NULL;
            if (first == NULL){  //if list is empty, then set it as first node
                first = tmp;
                first->next = NULL;
            }
            else{ //else place this node before first
                tmp->next = first;
                first = tmp; //new first 
            }
        }

        void insertEnd(int data){
            Node *tmp, *cur; 
            tmp = new Node();
            tmp->data = data;
            tmp->next = NULL;
            cur = first;
            if (cur == NULL){ // when no first node exists, set tmp as first
                first = tmp;
            }
            else{
                while(cur->next!=NULL){
                    cur = cur->next;
                } // reached end (last node before insertion) 
            cur->next = tmp;
            }
        }

        void insert(int index, int data){
            Node *tmp,*p=first;
            if(index<0 || index>getLength()) return;
            
            tmp=new Node;
            tmp->data = data;
            tmp->next = NULL;
            
            if(index==0){ // special case: for insertion at beginning
                tmp->next = first;
                first = tmp; // new first
            }
            else{
                for(int i=0; i<index-1; i++){
                    p=p->next;
                }
            tmp->next=p->next;
            p->next=tmp;
            }
        }

        void deleteBeginning(){
            Node *tmp;
            if (first == NULL){
                cout<<"List does not exist.\n";
            }
            tmp = first;
            first = first->next;
            delete tmp;
        }

        void deleteEnd(){
            Node *tmp = NULL;
            Node *cur = first;
            if(first == NULL){
                cout<<"List does not exist.\n";
            }
            while(cur->next!=NULL){
                tmp = cur;
                cur = cur->next;
            } 
            tmp->next = NULL; 
            delete cur; 
        }

        void deleteInBetween(int index){
            Node *p,*q=NULL;

            if(index<0 || index>getLength()) return;
            if(index==0){
                p = first;
                first = first->next;
                delete p;
            }
            else{
                p=first;
                for(int i=0; i<=index-1; i++){
                    q=p;
                    p=p->next;
                }
                q->next = p->next;
                delete p;
            }
        }
};

int main(){
    int A[] = {1,2,3,4,5,6,7};
    LinkedList LL(A, 7);
    cout<<endl<<"Your present linked list: \n";
    LL.display();

    char ch;
    int choice;
    do{
        cout<<"\n## MENU ##"<<endl;
        cout<<"1: Insertion at beginning "<<endl;
        cout<<"2: Insertion at end "<<endl;
        cout<<"3: Insertion in between(given the position) "<<endl;
        cout<<"4: Deletion at beginning "<<endl;
        cout<<"5: Deletion at end "<<endl;
        cout<<"6: Deletion of a specific node(given the position) "<<endl;
        cout<<"7: Search a node and display it's position "<<endl;
        cout<<"8: Display all node values: "<<endl;
        cout<<"9: Length of LL: "<<endl;
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                int data1;
                cout<<"Enter data for insertion at beginning of LL: "<<endl; cin>>data1;
                LL.insertBeginning(data1);
                LL.display();
                break;
            
            case 2:
                int data2;
                cout<<"Enter data for insertion at end of LL: "<<endl; cin>>data2;
                LL.insertEnd(data2);
                LL.display();
                break;
            
            case 3:
                int p, data3;
                cout<<"Enter the postion (index+1) value for insertion: "<<endl; cin>>p;
                cout<<"Enter data to be inserted at that position: "<<endl; cin>>data3;
                LL.insert(p-1, data3);
                LL.display();
                break;

            case 4:
                LL.deleteBeginning();
                LL.display();
                break;

            case 5:
                LL.deleteEnd();
                LL.display();
                break;

            case 6:
                int pos;
                cout<<"\nEnter the postion (index+1) of the element you want to delete: "; cin>>pos;
                LL.deleteInBetween(pos-1);
                LL.display();
                break;

            case 7:
                int element, position;
                cout<<"\nEnter data/element to be searched: "; cin>>element;
                position = LL.getPosition(element) + 1;
                cout<<"The element "<<element<<" was found at position (taking position of first node as 1): "<<position<<".\n";
                break;

            case 8:
                cout<<"\nHere is your list :)"<<endl;
                LL.display();
                break;

            case 9:
                int length;
                length = LL.getLength();
                cout<<"Length of LL is "<<length<<endl;
                break;

            default:
            cout<<"Default case!\n"<<endl;
        }

        cout<<"\nDo u wish to continue? (y/N)"<<endl;
        cin>>ch;
    }while(ch!='N');

    return 0;
}

// position = index + 1
// LIST :      1,2,3,4,5,6,7
//             | | | | | | |
// POSITION :  1,2,3,4,5,6,7
//             | | | | | | | 
// INDEX :     0,1,2,3,4,5,6