#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Matrix{
public:
    int m,n,k;
    vector<pair<int,pair<int,int>>> vec1; 
    int*** matrix;
    int*** distance;
    int count;

    void bfs(){
        int dx[6] = {-1,1,0,0,0,0};
        int dy[6] = {0,0,-1,1,0,0};
        int dz[6] = {0,0,0,0,-1,1};
        
        queue<pair<int,pair<int,int>>> q;
        for(auto next : vec1){
            q.push(next);
            distance[next.first][next.second.first][next.second.second] = 0;
        }
        while(!q.empty()){
            
            pair<int,pair<int,int>> current = q.front();
            int x = current.first;
            int y = current.second.first;
            int z = current.second.second;
            q.pop();

            if(matrix[x][y][z] == 1){
                for(int i = 0; i < 6; i++){
                    int x_dir = x+dx[i];
                    int y_dir = y+dy[i];
                    int z_dir = z+dz[i];
                    if(x_dir < 0 || x_dir >= m || y_dir < 0 || y_dir >= n || z_dir < 0 || z_dir >= k) continue;
                    if(matrix[x_dir][y_dir][z_dir] != 0) continue;
                    matrix[x_dir][y_dir][z_dir] = 1;
                    q.push({x_dir,{y_dir,z_dir}});
                    distance[x_dir][y_dir][z_dir] = distance[x][y][z] + 1;
                
                }
            }
        }
    }

    int findMax(){
        int max = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int p = 0; p < k; p++){
                    if(matrix[i][j][p] == 0) return -1;
                    if(max < distance[i][j][p]) max = distance[i][j][p];
                } 
            }
        }
        return max;
    }
    
    void printMatrix(){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int p = 0; p < k; p++){
                    cout << matrix[i][j][p] << ' ';
                }
                cout << '\n';
            }
            
        }
    }

    Matrix(int m,int n,int k):count(0),m(m),n(n),k(k){
        matrix = new int**[m];
        distance = new int**[m];

        for(int i = 0; i < m; i++){
            matrix[i] = new int*[n];
            for(int j = 0; j < n; j++){
                matrix[i][j] = new int[k];
            }
        }
        for(int i = 0; i < m; i++){
            distance[i] = new int*[n];
            for(int j = 0; j < n; j++){
                distance[i][j] = new int[k];
                for(int p = 0; p < k; p++){
                    distance[i][j][p] = -1;
                }
            }
        }
    }

};


int main(){
    //행렬 만들기
    int m,n,k;
    cin >> k >> n >> m;
    Matrix mat(m,n,k);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int p = 0; p < k; p++){
                int num;
                cin >> num;
                mat.matrix[i][j][p] = num;
                if(num == 1){
                    mat.vec1.push_back({i,{j,p}});
                }
            }
        }
    }
    //mat.printMatrix();
    mat.bfs();
    //mat.printMatrix();
    cout << mat.findMax() << '\n';
    //mat.printMatrix();
}