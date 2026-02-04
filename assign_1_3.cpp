// Faisal M S
// ME23B105
/*
(3) Adapt the function to multiply two matrices to perform a matrix (N × N) vector (N × 1)
product. Plot the time taken as a function of N for N = 256, N = 512, N = 1024, N = 2048,
and N = 4096. (40 points)
*/
#include <iostream>
#include <vector> // vectors of size N
#include <ctime> // clock 
#include <cstdlib> // random numbers
using namespace std;

int main(){
    int X[5]={256,512,1024,2048,4096};  // for different values of N
    int N; // size of the matrix(N*N) and array(N*1)
    double Y[5]={0,0,0,0,0}; // for storing the values of time for each operation first initialised to zero
    // loop for putting each value of N
    for(int l=0;l<5;l++){                                         
        N=X[l]; 
        vector<vector<int>> A(N,vector<int>(N,0)); // initialising matrix A(N*N) with zeros using vector
                                                            
        // substituting the values of elements in A using rand()
        // change the code by removing rand() and put cin for user input
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                A[i][j]=rand();
            }
        } 

                                                            
        vector<vector<int>> B(N,vector<int>(1,0)); // initialising matrix B(N*1) with zeros using vector
        // substituting the values of elements in B using rand()
        // change the code by removing rand() and put cin for user input
        for(int i=0;i<N;i++){
            for(int j=0;j<1;j++){
                B[i][j]=rand();
            }
        } 
        // initialising matrix AB(N*N) with zeros using vector
        vector<vector<int>> AB(N,vector<int>(1,0));
        
        // time for matrix multiplication

        clock_t start = clock();; // get the start time

        // matrix multiplication

        for(int i=0;i<N; i++){                  
            for(int j=0;j<1; j++){               //i varies from 1 to rowsA, j varies from 1 to colsB, k varies from 1 to colsA or rowsB
                for(int k=0; k<N; k++){
                    AB[i][j]+=A[i][k]*B[k][j];
                }
            }
        }

        clock_t end = clock(); // get the end time
        double elapsed = double(end - start) / CLOCKS_PER_SEC; // time for the matrix multiplication by taking diff of start and end time
        
        Y[l]=elapsed; // substituting elapsed in the Y array 


        // uncomment for printing the product of A and B

        /*cout<<"The product matrix is: \n";
        for(int i=0;i<N; i++){                   // printing the product
            for(int j=0;j<1; j++){
            cout<<AB[i][j]<<" ";
            }cout<<endl;
        }*/
        
        }
    // printing  N vs t 
    for(int i=0; i<5; i++){
        cout<<"\nN = "<<X[i]<<"  t = "<<Y[i]<<" seconds";
    }
    return 0;
} 

/* output
N = 256  t = 0.000725 seconds
N = 512  t = 0.003452 seconds
N = 1024  t = 0.013678 seconds
N = 2048  t = 0.050595 seconds
N = 4096  t = 0.283954 seconds
*/