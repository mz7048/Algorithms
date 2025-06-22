#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Matrix{
public:
    int m,n;
    vector<pair<int,int>> vec1; 
    int** matrix;
    int** distance;
    int count;

    void bfs(){
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        
        queue<pair<int,int>> q;
        for(auto next : vec1){
            q.push(next);
            distance[next.first][next.second] = 0;
        }
        while(!q.empty()){
            
            pair<int,int> current = q.front();
            int x = current.first;
            int y = current.second;
            q.pop();
            if(matrix[x][y] == 1){
                for(int i = 0; i < 4; i++){
                    int x_dir = x+dx[i];
                    int y_dir = y+dy[i];
                    if(x_dir < 0 || x_dir >= m || y_dir < 0 || y_dir >= n) continue;
                    if(matrix[x_dir][y_dir] != 0) continue;
                    matrix[x_dir][y_dir] = 1;
                    q.push({x_dir,y_dir});
                    distance[x_dir][y_dir] = distance[x][y] + 1;
                
                }
            }
        }
    }

    int findMax(){
        int max = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0) return -1;
                if(max < distance[i][j]) max = distance[i][j];
            }
        }
        return max;
    }
    
    void printMatrix(){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << matrix[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    Matrix(int m,int n):count(0),m(m),n(n){
        matrix = new int*[m];
        distance = new int*[m];

        for(int i = 0; i < m; i++){
            matrix[i] = new int[n];
        }
        for(int i = 0; i < m; i++){
            distance[i] = new int[n];
            for(int j = 0; j < n; j++){
                distance[i][j] = -1;
            }
        }
    }

};


int main(){
    //행렬 만들기
    int m,n;
    cin >> n >> m;
    Matrix mat(m,n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            mat.matrix[i][j] = num;
            if(num == 1){
                mat.vec1.push_back({i,j});
            }
        }
    }
    //mat.printMatrix();
    mat.bfs();
    //mat.printMatrix();
    cout << mat.findMax() << '\n';
    //mat.printMatrix();
}