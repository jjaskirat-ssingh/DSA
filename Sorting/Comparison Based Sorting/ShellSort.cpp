#include<iostream>
using namespace std;

// Can be understood as Insertion sort with gaps 
void ShellSort(int A[], int n){
    for (int gap=n/2; gap>=1; gap=gap/2){
        for(int j=gap; j<n; j++){
            int temp = A[j];
            int i = j - gap;
            while (i>=0 && A[i]>temp){
                A[i+gap] = A[i];
                i = i-gap;
            }
            A[i+gap] = temp;
        }
    }
}

void display(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<"Before: ";
    display(A, n);
    cout<<endl;

    ShellSort(A, n);

    cout<<"After: ";
    display(A, n);
    
    return 0;
}