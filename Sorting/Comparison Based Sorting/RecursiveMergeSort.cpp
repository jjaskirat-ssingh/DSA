#include<iostream>
using namespace std; 

void MergeSingle(int A[],int l,int mid,int h){
    int i=l,j=mid+1,k=l; 
    int B[100]; 
    while(i<=mid && j<=h){ 
        if(A[i]<A[j]) 
            B[k++]=A[i++]; 
        else
            B[k++]=A[j++]; 
        } 
    for(;i<=mid;i++) 
        B[k++]=A[i]; 
    for(;j<=h;j++) 
        B[k++]=A[j]; 
    for(i=l;i<=h;i++) 
        A[i]=B[i]; 
    } 

void rMergeSort(int A[], int low, int high){
    if (low < high){
        // Calculate mid point
        int mid = low + (high-low)/2;
 
        // Sort sub-lists
        rMergeSort(A, low, mid);
        rMergeSort(A, mid+1, high);
 
        // Merge sorted sub-lists
        MergeSingle(A, low, mid, high);
    }
}

void display(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int A[]={11,5,14,2,6,3,1};
    int n = sizeof(A)/sizeof(A[0]); 
    cout<<"Before: ";
    display(A, n);
    cout<<endl;

    rMergeSort(A, 0, n-1); 
    cout<<"After: ";
    display(A, n); 
    
    return 0; 
} 