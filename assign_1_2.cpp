//Faisal M S 
//ME23B105

// assignment 1

/* (2) Consider a random matrix A of size N × N (user input). Convince yourself computationally
that (A + AT) is symmetric. (10 points)*/


#include <iostream>
#include <vector> // for dynamic initialisation of matrix
using namespace std;

int main(){
    int rows,cols;     // rows and cols of matrix
    cout<<"enter the no of rows and cols: \n";
    cin>>rows>>cols;
    //dynamically initialising the matrices A and AT with zeros
    vector<vector<int>> A(rows,vector<int>(cols,0)),AT(rows,vector<int>(cols,0));
    //taking the values in matrix A from user
    cout<<"enter the values in A: \n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>A[i][j];
        }
    } 
    // compute A Transpose
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            AT[i][j]=A[j][i];
            }
    } 
    // printing matrix A
    cout<<"the matrix A: \n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<A[i][j]<<" ";
            }cout<<endl;
    } 

    // printing matrix AT
    cout<<"the matrix AT: \n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<AT[i][j]<<" ";
            }cout<<endl;
    } 
    // the sum (A+AT)
    cout<<"the sum (A+AT): \n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<AT[i][j]+A[i][j]<<" ";
            }cout<<endl;
    } 
    // the sum is a symmetric matrix by inspectionS
    return 0;
}