// Creating Max Heap

#include <iostream>
using namespace std;

void InsertA(int A[], int n){ // (O(log(n) base 2)
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2]){ // use "<" for Min Heap
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    A[i] = temp;
}

void createHeap(int A[], int n){ // O(nlogn)
    for (int i=0; i<n; i++){
        InsertA(A, i);
    }
}

int main(){
    int b[] = {10, 20, 30, 25, 5, 40, 35};
    createHeap(b, sizeof(b)/sizeof(b[0]));

    for(int i=0; i<sizeof(b)/sizeof(b[0]); i++){
        cout<<b[i]<<" ";
    }

}
 