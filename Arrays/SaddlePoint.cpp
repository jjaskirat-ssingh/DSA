/*  Write a program to find a saddle point in a two-dimensional array. A saddle point in a 
    numerical array is a number that is larger than or equal to every number in its column, 
    and smaller than or equal to every number in its row. */

#include<iostream>
using namespace std;
#define m 3 // rows
#define n 3 // columns

void get_values(int arr[][n]);
void display(int arr[][n]);
void SaddlePoint(int arr[][n]);

int main(){
    int arr[m][n];
    get_values(arr);
    display(arr);
    SaddlePoint(arr);
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

void SaddlePoint(int arr[][n]){
    int sadd, i;
    for(i=0; i<m; i++){
        sadd = arr[i][0];
        int max_row, min_col;

        for(int j=0; j<n; j++){
            if(sadd >= arr[i][j]){
                sadd = arr[i][j];
                max_row = i;
                min_col = j;
            }
        }

        for(int k=0; k<m; k++){
            if(sadd < arr[k][min_col]){
                max_row = k;
            }
        }

        if(sadd == arr[max_row][min_col]){
            cout<<"Saddle Point: "<<sadd<<endl;
            break;
        }
    }
    if(i==m) cout<<"No saddle point."<<endl;
}

 