#include <iostream>
using namespace std;
 
void swap(int A[], int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
 
void Heapify(int A[], int n){
    // # of leaf elements: (n+1)/2, index of last leaf element's parent = (n/2)-1
    for (int i=(n/2)-1; i>=0; i--){
 
        int j = 2 * i + 1;  // Left child for current i
 
        while(j < n-1){
            // Compare left and right children of current i
            if (A[j] < A[j+1]){
                j = j+1;
            }
 
            // Compare parent and largest child
            if (A[i] < A[j]){
                swap(A, i, j);
                i = j;
                j = 2 * i + 1;
            } else {
                break;
            }
        }
    }
}


void display(int A[], int n){
    for (int i=0; i<n; i++){
        cout<<A[i]<<" ";
     }
}
 
int main() {
 
    int A[] = {5, 10, 30, 20, 35, 40, 15};

    Heapify(A, sizeof(A)/sizeof(A[0]));
    display(A, sizeof(A)/sizeof(A[0]));

    cout<<endl;
 
    int B[] = {5, 10, 30, 20};
    
    Heapify(B, sizeof(B)/sizeof(B[0]));
    display(B, sizeof(B)/sizeof(B[0]));
 
    return 0;
}