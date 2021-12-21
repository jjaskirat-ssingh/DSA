#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
} 

void SelectionSort(int A[], int n){
    for(int i=0; i<n-1; i++){
        int j, k;
        for(j=k=i; j<n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

void display(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);
    
    cout<<"Before: ";
    display(A, n);
    cout<<endl;
 
    SelectionSort(A, n);
    cout<<"After: ";
    display(A, n);

    return 0;
}