// Faisal M S
//ME23B105
/*4. Let X and Y be thin matrices (size m × n, such that m > n) and z be a vector of size
m × 1. Compute XYTz as (a) X(YTz) and (b) (XYT)z. Compare the time it takes between
the two for (m, n) = (256, 8), (m, n) = (512, 8), (m, n) = (1024, 8), (m, n) = (2048, 8),
(m, n) = (4096, 8). Plot the time taken as a function of m. (40 points)*/

#include <iostream>
#include <vector> //vector
#include <cstdlib> //random numbers
#include <ctime> //clock
using namespace std;


int main(){

    int m, n=8, M[5]={256,512,1024,2048,4096}; // array for different values of m
    double time1[5]={0,0,0,0,0},time2[5]={0,0,0,0,0}; //for storing time
    //cout<<"enter the shape of the matrices: ";
    //cin>>m>>n;
    for(int l=0; l<5;l++){
        m=M[l];

    // vectors for X, Y , z ....
    vector <vector<long long>> X(m,vector<long long>(n,0)), Y(m,vector<long long>(n,0)), z(m,vector<long long>(1,0)),YT(n,vector<long long>(m,0)), YTz(n,vector<long long>(1,0)), X_YTz(m,vector<long long>(1,0)),XYT(m,vector<long long>(m,0)),XYT_z(m,vector<long long>(1,0));
    //initialising matrices with random numbers
    for(int i=0; i< m; i++){
        for(int j=0; j<n; j++){
            X[i][j]=rand();
            Y[i][j]=rand();
            z[i][0]=rand();
        }
    }
    //transpose of matrix Y
    for(int i=0;i<n; i++){                  
        for(int j=0;j<m; j++){              
                YT[i][j]=Y[j][i];
        }
    }
    //clock 
    clock_t start1 = clock(); 
    //YT times z
    for(int i=0;i<n; i++){                   
        for(int j=0;j<1; j++){               
            for(int k=0; k<m; k++){
                YTz[i][0]+=YT[i][k]*z[k][j];
            }
        }
    }
    // X times YTz
    for(int i=0;i<m; i++){                   
        for(int j=0;j<1; j++){               
            for(int k=0; k<n; k++){
                X_YTz[i][0]+=X[i][k]*YT[k][j];
            }
        }
    }
    // end clock
    clock_t end1 =clock();
    double elapsed1 = double(end1 - start1) / CLOCKS_PER_SEC;
    time1[l]=elapsed1;
    
    // start clock
    clock_t start2 = clock();
    
    // X times YT

    for(int i=0;i<m; i++){                   
        for(int j=0;j<m; j++){               
            for(int k=0; k<n; k++){
                XYT[i][j]+=X[i][k]*YT[k][j];
            }
        }
    }
    // XYT times z

    for(int i=0;i<m; i++){                   
        for(int j=0;j<1; j++){               
            for(int k=0; k<m; k++){
                XYT_z[i][0]+=XYT[i][k]*z[k][j];
            }
        }
    }
    // stop clock
    clock_t end2 =clock();
    double elapsed2 = double(end2 - start2) / CLOCKS_PER_SEC;
    time2[l]=elapsed2;
}
// print the output
for(int i=0;i<5;i++){
    cout<<"\n (m,n)=("<<M[i]<<",8) X(YTz) t="<<time1[i]<<" seconds,  (XYT)z t="<<time2[i]<<" seconds"; 
}
    return 0;
}

//output
/*
(m,n)=(256,8) X(YTz) t=7.6e-05 seconds,  (XYT)z t=0.006766 seconds
 (m,n)=(512,8) X(YTz) t=0.000136 seconds,  (XYT)z t=0.028177 seconds
 (m,n)=(1024,8) X(YTz) t=0.000178 seconds,  (XYT)z t=0.115125 seconds
 (m,n)=(2048,8) X(YTz) t=0.000524 seconds,  (XYT)z t=0.48112 seconds
 (m,n)=(4096,8) X(YTz) t=0.000711 seconds,  (XYT)z t=1.96293 seconds

*/
