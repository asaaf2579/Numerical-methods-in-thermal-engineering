/* 
(30 points) A large industrial furnace, as shown in the figure below, is supported on a long column of fireclay brick.
During steady-state operation, installation is such that three surfaces of the column are maintained at 500 K while
the remaining surface is exposed to an airstream at a temperature of 300 K. Owing to the symmetry of the problem
the number of unknowns (temperature at the interior nodal locations) is reduced from 12 to 8. Using energy balance
the following equations are obtained in terms of the nodal temperatures:

Node 1: T2 + T3 + 1000 − 4T1 = 0
Node 3: T1 + T4 + T5 + 500 − 4T3 = 0
Node 5: T3 + T6 + T7 + 500 − 4T5 = 0
Node 2: 2T1 + T4 + 500 − 4T2 = 0
Node 4: T2 + 2T3 + T6 − 4T4 = 0
Node 6: T4 + 2T5 + T8 − 4T6 = 0
Node 7: 2T5 + T8 + 2000 − 9T7 = 0
Node 8: 2T6 + 2T7 + 1500 − 9T8 = 0.

Using the Gaussian elimination algorithm developed above, calculate and report the temperatures T1 through T8.
Also, plot the variation of temperature as a function of y at locations x = 0.25 and x = 0.5.
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
