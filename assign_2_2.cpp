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
int main(){
    int N=8;
    vector<vector<double>> A={{-4,1,1,0,0,0,0,0},{0,1,2,-4,0,1,0,0},{0,0,1,0,-4,1,1,0},{2,-4,0,1,0,0,0,0},{1,0,-4,1,1,0,0,0},{0,0,0,1,2,-4,0,1},{0,0,0,0,2,0,-9,1},{0,0,0,0,0,2,2,-9}};
    vector<double> b={-1000,0,-500,-500,-500,0,-2000,-1500};
    
    vector<double> x(N);
    forw_elm(A,b);
    x=back_sub(A,b);
    for (int i=0; i<N; i++){
        cout<<"T_"<<i+1<<" = "<<x[i]<<endl;
    }
    return 0;
}

/*
T_1 = 489.305
T_2 = 485.154
T_3 = 472.065
T_4 = 462.006
T_5 = 436.95
T_6 = 418.739
T_7 = 356.995
T_8 = 339.052
*/