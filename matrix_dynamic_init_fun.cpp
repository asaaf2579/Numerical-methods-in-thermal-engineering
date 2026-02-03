#include <iostream>
#include <vector> // for dynamic initialisation of matrix
using namespace std;

int matrix(){
    int rows,cols;
    cout<<"enter the no of rows and cols: \n";
    cin>>rows>>cols;
    //dynamically initialising the matrix A
    vector<vector<int>> A(rows,vector<int>(cols,0));
    //for A
    cout<<"enter the values in A: \n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>A[i][j];
        }
    } 
    // uncomment to display the matrix
    /*cout<<"the matrix A is: \n";
     for(int i=0;i<rows; i++){
        for(int j=0;j<cols; j++){
            cout<<A[i][j]<<" ";
        }cout<<endl;*/
    }
    return 0;
}
/*
int main(){
    int A=matrix();
    return 0;
}
*/
