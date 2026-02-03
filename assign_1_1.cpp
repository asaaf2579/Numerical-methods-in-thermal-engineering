//Faisal M S 
//ME23B105

/* (1) Consider random matrices A and B of size N × N (user input). 
Convince yourself computationally that matrix product is not commutative: i.e. AB ̸= BA. (10 points)*/

#include <iostream>
#include <vector> // for dynamic initialisation of matrix
using namespace std;

int main(){
    int rows,cols;
    cout<<"enter the no of rows and cols: \n";
    cin>>rows>>cols;
    //dynamically initialising the matrix A, B and its product AB and BA with zeros
    vector<vector<int>> A(rows,vector<int>(cols,0)), B(rows,vector<int>(cols,0)), AB(rows,vector<int>(cols,0)), BA(rows,vector<int>(cols,0));
    //asking user to input values of A and B
    //for A
    cout<<"enter the values in A: \n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>A[i][j];
        }
    } 
    //for B
    cout<<"enter the values in B: \n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cin>>B[i][j];
        }
    } 
    // lets do the product AB and BA
    for(int i=0;i<rows; i++){                   //3 loops to do the matrix multiplication
        for(int j=0;j<cols; j++){               //k is a dummy variable so that when j gets updated it doesnt change 
                                                //the column of resulting matrix
            for(int k=0; k<cols; k++){
                AB[i][j]+=A[i][j]*B[j][i];
                BA[i][j]+=B[i][j]*A[j][i];
            }
        }
    }
    cout<<"the product AB = \n";  // loop for displaying the products
    for(int i=0;i<rows; i++){
        for(int j=0;j<cols; j++){
            cout<<AB[i][j]<<" ";
        }cout<<endl;
    }
    cout<<"the product BA = \n";
    for(int i=0;i<rows; i++){
        for(int j=0;j<cols; j++){
            cout<<BA[i][j]<<" ";
        }cout<<endl;
    }

    // finally by seeing the products one can verify that AB is not necessarily be equal to BA
    return 0;

}
