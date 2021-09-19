#include <iostream>
using namespace std;
int* Diagonal(int); // n
int* TriDiagonal(int); // 3n-2
int* LowerTrianglular(int); // n(n+1)/2
int* UpperTrianglular(int); // n(n+1)/2
int* Symmetric(int); // n(n+1)/2

int main(){
    char ch;
    int choice, n;
    int *matrix;

    do{
        cout<<"-- MENU --"<<endl;

        cout<<" 1 - Diagonal"<<endl;
        cout<<" 2 - Tri-diagonal"<<endl;
        cout<<" 3 - LowerTrianglular"<<endl;
        cout<<" 4 - UpperTrianglular"<<endl;
        cout<<" 5 - Symmetric"<<endl;
        cout<<"\nEnter your choice: "; cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter size of matrix(n x n): "<<endl;
                cin>>n;
                matrix = Diagonal(n);
                break;
            
            case 2:
                cout<<"Enter size of matrix(n x n): "<<endl;
                cin>>n;
                matrix = TriDiagonal(n);
                break;
            
            case 3:
                cout<<"Enter size of matrix(n x n): "<<endl;
                cin>>n;
                matrix = LowerTrianglular(n);
                break;

            case 4:
                cout<<"Enter size of matrix(n x n): "<<endl;
                cin>>n;
                matrix = UpperTrianglular(n);
                break;

            case 5:
                cout<<"Enter size of matrix(n x n): "<<endl;
                cin>>n;
                matrix = Symmetric(n);
                break;

            default:
                cout<<"Enter a correct choice (1 - 5). Try again."<<endl;
            
            }

        cout<<"\nDo u wish to continue? (y/N)"<<endl;
        cin>>ch;
    }while(ch!='N');

    return 0;
}

int *Diagonal(int n){
    int *m = new int[n];
    for(int i=0; i<n; i++){
        cout<<"Enter value at "<<i<<" x "<<i<<": ";
        cin>>m[i];
    }
    cout<<"The matrix that you've entered: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) cout<<m[i]<<"\t";
            else cout<<"0\t";
        }
        cout<<endl;
    }
    return m;
}

int *TriDiagonal(int n){
    int *m = new int[((3*n) - 2)];
    int pos=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(abs(i-j)<=1){
                cout<<"Enter value at "<<i<<" x "<<j<<": ";
                cin>>m[pos];
                pos++;
            }
        }
    }
    pos=0;
    cout<<"The matrix that you've entered: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(abs(i-j)<=1){
                cout<<m[pos]<<"\t";
                pos++;
            }
            else{
                cout<<"0\t";
            }
        }
        cout<<endl;
    }
    return m;
}

int *LowerTrianglular(int n){
    int *m = new int[(((n+1)*(n))/2)];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j<=i){
                cout<<"Enter value at "<<i<<" x "<<j<<": ";
                cin>>m[j + i + (i - 1)*i/2];
            }
        }
    }

    cout<<"The matrix that you've entered: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j<=i){
                cout<<m[j + i + (i - 1)*i/2]<<"\t";
            }
            else{
                cout<<"0\t";
            }
        }
        cout<<endl;
    }
    return m;
}

int *UpperTrianglular(int n){
    int *m = new int[(((n+1)*(n))/2)];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j>=i){
                cout<<"Enter value at "<<i<<" x "<<j<<": ";
                cin>>m[j + i*(n - 1) - (i - 1)*i/2];
            }
        }
    }

    cout<<"The matrix that you've entered: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j>=i){
                cout<<m[j + i*(n - 1) - (i - 1)*i/2]<<"\t";
            }
            else{
                cout<<"0\t";
            }
        }
        cout<<endl;
    }
    return m;
}

int *Symmetric(int n){
    int *m = new int[(((n+1)*(n))/2)];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j>=i){
                cout<<"Enter value at "<<i<<" x "<<j<<": ";
                cin>>m[j + i*(n - 1) - (i - 1)*i/2];
            }
        }
    }

    cout<<"The matrix that you've entered: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j>=i){
                cout<<m[j + i*(n - 1) - (i - 1)*i/2]<<"\t";
            }
            else{
                cout<<m[i + j * (n - 1) - (j - 1)*j/2]<<"\t";
            }
        }
        cout<<endl;
    }
    return m;
}