#include<iostream>
using namespace std;

int Max(int A[], int n){
    int max = INT32_MIN;
    for (int i=0; i<n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}

void CountSort(int A[], int n){
    int max = Max(A, n);

    // Create count array
    int *count = new int[max+1];

    // Initialize count array with 0
    for (int i=0; i<max+1; i++){
        count[i] = 0;
    }

    // Update count array values based on A values
    for (int i=0; i<n; i++){
        count[A[i]]++;
    }
    
    // Update A with sorted elements
    int i = 0;
    int j = 0;
    while (j < max+1){
        if (count[j] > 0){
            A[i++] = j;
            count[j]--;
        } else {
            j++;
        }
    }
 
    // Delete heap memory
    delete []count;
}

void display(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<"Before: ";
    display(A, n);
    cout<<endl;

    CountSort(A, n);

    cout<<"After: ";
    display(A, n);
    
    return 0;
}