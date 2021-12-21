#include <iostream>
using namespace std;
 
void Merge(int x[], int y[], int z[], int m, int n){
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n){
        if (x[i] < y[j]){
            z[k++] = x[i++];
        }
        else{
            z[k++] = y[j++];
        }
    }
    while (i < m){
        z[k++] = x[i++];
    }
    while (j < n){
        z[k++] = x[j++];
    }
}
 
void MergeSingle(int A[], int low, int mid, int high){
    int i = low;
    int j = mid+1;
    int k = low;
    int B[high+1];
    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    while (i <= mid){
        B[k++] = A[i++];
    }
    while (j <= high){
        B[k++] = A[j++];
    }
    for (int i=low; i<=high; i++){
        A[i] = B[i];
    }
}

void display(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}
 
int main() { 
    int A[] = {2, 10, 18, 20, 23};
    int m = sizeof(A)/sizeof(A[0]);
    cout<<"Array 1: ";
    display(A, m);
    cout<<endl;
 
    int B[] = {4, 9, 19, 25};
    int n = sizeof(B)/sizeof(B[0]);
    cout<<"Array 2: ";
    display(B, n);
    cout<<endl;
 
    int r = m+n;
    int C[r];
    Merge(A, B, C, m, n);
 
    cout<<"Merged Array: ";
    display(C, r);
    cout<<endl<<endl;;
    cout << endl;
 
    int D[] = {2, 5, 8, 12, 3, 6, 7, 10};
    display(D, sizeof(D)/sizeof(D[0]));
    cout<<endl;
    MergeSingle(D, 0, 3, 7);
    display(D, sizeof(D)/sizeof(D[0]));
    cout<<endl; 
 
    return 0;
}