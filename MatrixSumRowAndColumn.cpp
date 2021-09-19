// Write a program to find sum of every row and every column in a two-dimensional array.

#include<iostream>
using namespace std;
#define m 3 // rows
#define n 4 // columns

void get_values(int arr[][n]);
void display(int arr[][n]);
void rows_sum(int arr[][n]);
void columns_sum(int arr[][n]);

int main(){
    int arr[m][n];
    get_values(arr);
    display(arr);
    rows_sum(arr);
    columns_sum(arr); 
    return 0;
}

void get_values(int arr[][n]){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"Enter value at "<<i<<" x "<<j<<": ";
            cin>>arr[i][j];
        }
    }
}

void display(int arr[][n]){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void rows_sum(int arr[][n]){
    for(int i=0; i<m; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            sum = sum + arr[i][j];
        }
        cout<<endl;
        cout<<"The sum of row "<<i+1<<" is: "<<sum<<endl;
    }
}

void columns_sum(int arr[][n]){
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<m; j++){
            sum = sum + arr[j][i];
        }
        cout<<endl;
        cout<<"The sum of column "<<i+1<<" is: "<<sum<<endl;
    }
}
