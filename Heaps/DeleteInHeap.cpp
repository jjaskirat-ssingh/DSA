// Deleting in Heap and Heap Sort (Ascending order)

#include <iostream>
using namespace std;

void InsertA(int A[], int n){ // O(log(n) base 2)
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2]){
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    A[i] = temp;
}

int Delete(int A[],int n){
    int i, j, x, temp, val; 
    val = A[1]; 
    x = A[n]; 

    A[1] = A[n]; 
    
    A[n] = val; 
    i = 1; j = i*2; 
    while(j <= n-1){ 
        if(j<n-1 && A[j+1]>A[j]) 
            j = j+1; 
        if(A[i]<A[j]){ 
            temp = A[i]; 
            A[i] = A[j]; 
            A[j] = temp; 
            i = j; 
            j = 2*j; 
        } 
        else
            break; 
    } 
    return val; 
}

int main() { 
    int H[]={15,10,20,30,25,5,40,35}; 
    int i; 
    for(i=2;i<=8;i++) 
        InsertA(H,i); 
    
    for(i=8;i>1;i--) { 
        Delete(H,i); 
    } 
    for(i=1;i<=8;i++) 
        printf("%d ",H[i]); 
    
    printf("\n"); 
    return 0; 
}