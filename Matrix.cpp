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

    Matrix(int m,int n):m(m),n(n){
        matrix = new int*[m];

        for(int i = 0; i < m; i++){
            matrix[i] = new int[n];
        }
    }

};