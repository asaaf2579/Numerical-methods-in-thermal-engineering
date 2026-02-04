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
    /* 
        Struggling with how to visualise matrix multiplication, here is how I tackled it:
    lets say we have two matrices A(m*n) and B(n*p), we multiply both A and B to get C(m*p)
    let i varies from 1 to m
    j varies from 1 to p
    k varies from 1 to n
    C=Cij, A=Aik, B=Bkj
    Cij = ai1*b1j + ai2*b2j + ........+ aik*bkj +..................+ ain*bnj
    draw matrices with aik and bkj vectors only and multiply them u get the above equation, for better visualisation
    so Cij = Sigma(k=1 to n) {aik*bkj}
    Now i and j vary from 1 to m and 1 to p, respectively
    For programming, see the code below on how it is done.
    Make sure to initialise C with zero to avoid garbage values
    Still facing a problem, take a pen and paper, do the above steps :)
    */
    
    
    // lets do the product AB and BA
    for(int i=0;i<rows; i++){                   
        for(int j=0;j<cols; j++){                                              
            for(int k=0; k<cols; k++){
                AB[i][j]+=A[i][k]*B[k][j];
                BA[i][j]+=B[i][k]*A[k][j];
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

