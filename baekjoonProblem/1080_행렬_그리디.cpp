#include<iostream>
using namespace std;

class Matrix{
public:
    int m,n;
    int** matrix;

    
    void printMatrix(){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void reverse3x3(int i,int j){
        for(int k = i; k < i+2; k++){
            for(int p = j; p < j+2; p++){
                matrix[k][p] = !matrix[k][p];
            }
        }
    }

    Matrix(int m,int n):m(m),n(n){
        matrix = new int*[m];

        for(int i = 0; i < m; i++){
            matrix[i] = new int[n];
        }
    }

    bool isSame(Matrix& compare){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] != compare.matrix[i][j]){
                    return false;
                }
            }
        }
        return true;
    }

};


int main(){
    int N,M;

    scanf("%d %d",&N,&M);
    Matrix A(N,M);
    Matrix B(N,M);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d",&A.matrix[i][j]);
        }
    }
    
    //A.printMatrix();
    

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%1d",&B.matrix[i][j]);
        }
    }
    
    B.printMatrix();

    int count = 0;
    int flag = 1;
    for(int i = 0; i < N-2 && flag; i++){
        for(int j = 0; j < M-2; j++){
            if(A.isSame(B)){
                flag = 0;
                break;
            }
            if(A.matrix[i][j] != B.matrix[i][j]){
                A.reverse3x3(i,j);
                count++;
            }
        }
    }
    if(flag == 0)
        cout << count;
    else
        cout << -1;
    
}