/*
1. (30 points) Write a program that performs Gaussian elimination for a square system of size n × n. Consider writing
it as a modular program with separate functions or subroutines that perform forward-elimination and backward-
substitution. To test the program, solve the system Ax = b of order n, with A = [aij ] defined by
aij = max(i, j).
Also define b = [1, 1, ..., 1]T. Solve the system to obtain the solution vector x, for n = 32, 128, 512, 1024. 
*/


#include <iostream>
#include <vector>
using namespace std;

void forw_elm(vector<vector<double>> &A,vector<double> &b){
    int N=A.size();
    for (int k=0; k<N-1; k++){
        for (int i=k+1; i<N; i++){
            double p=(A[i][k]/A[k][k]);
            for (int j=k; j<N; j++){
                A[i][j]=A[i][j]-p*A[k][j];
            }
        b[i]=b[i]-p*b[k];    
        }
    }
}

vector<double> back_sub(vector<vector<double>> &A, vector<double> &b){
    int N=A.size();
    vector<double> x(N);
    x[N-1]=b[N-1]/A[N-1][N-1];
    for (int i=N-2; i>=0;i--){
        double s=b[i];
        for (int j=i+1; j<N; j++){
            s=s-A[i][j]*x[j];           
        }
        x[i]=s/A[i][i];
    }
    return x;
}
double invx2(vector<double> x){
    int N=x.size();
    double s=0;
    for (int i=0; i<N; i++){
        s+=(x[i]*x[i]);
    }
    return 1/s;
}
int main(){
    int l[4]={32,128,512,1024};
    for (int m=0; m<4;m++){
    int N = l[m];
    vector<vector<double>> A(N,vector<double>(N));
    vector<double> b(N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if (i+1>j+1){
                A[i][j]=i+1;
            }
            else{
                A[i][j]=j+1;
            }
            
        }
        b[i]=1;
    }
    
    
    vector<double> x(N);
    forw_elm(A,b);
    x=back_sub(A,b);
    
    /*
    for (int i=0; i<N; i++){
        cout<<x[i]<<endl;
    }
    */
    cout<<"n="<<l[m]<<" 1/Sig(xi^2)= "<< invx2(x)<< endl;
    }
    return 0;
    
}
/*
n=32 1/Sig(xi^2)= 1024
n=128 1/Sig(xi^2)= 16384
n=512 1/Sig(xi^2)= 262144
n=1024 1/Sig(xi^2)= 1.04858e+06
*/

