#include<iostream>
using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low;
    int j = high;
 
    do {
        // Increment i while elements are smaller or equal to pivot
        do {i++;} while (A[i] <= pivot);
 
        // Decrement j while elements are larger than pivot 
        do {j--;} while (A[j] > pivot);
 
        if (i < j){
            swap(&A[i], &A[j]);
        }
    } while (i < j);
    // Swap pivot and element at index j
    swap(&A[low], &A[j]);
    return j;
}
 
void QuickSort(int A[], int low, int high){
    if (low < high){
        int j = partition(A, low, high); 
        QuickSort(A, low, j);      // pivot acts as INT32_MAX for LHS so we take till j instead of j-1
        QuickSort(A, j+1, high);
    }
}

void display(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT32_MAX};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"Before: ";
    display(A, n-1);
    cout<<endl;

    QuickSort(A, 0, n-1);

    cout<<"After: ";
    display(A, n-1);

    return 0;
}