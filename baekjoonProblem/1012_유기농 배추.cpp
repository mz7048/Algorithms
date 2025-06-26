#include<iostream>
#include<vector>
using namespace std;

class Matrix{
public: 
    int m,n,k;
    int** matrix;
    Matrix(int m,int n,int k):m(m),n(n),k(k){
        matrix = new int*[m];
        for(int i = 0; i < m; i++){
            matrix[i] = new int[n];
            for(int j = 0; j < n; j++){
                matrix[i][j] = 0;
            }
        }
    }
    ~Matrix() {
    for (int i = 0; i < m; i++) delete[] matrix[i];
    delete[] matrix;
}
};

class Graph{
   
public:
    static int numOfGraph;
    vector<vector<int>> graph;
    Matrix& matrix;

    void travel(){
        for(int i = 0; !graph.empty(); i++){
            int x = graph.front()[0];
            int y = graph.front()[1];
            
            if(matrix.matrix[x][y] == 0){
                graph.erase(graph.begin());
                continue;
            }    
            matrix.matrix[x][y] = 0;
            numOfGraph++;
            if(x+1 < matrix.m)
                travel(x+1,y);
            if(y+1 < matrix.n)
                travel(x,y+1);
            if(x-1 >= 0)
                travel(x-1,y);
            if(y-1 >= 0)
                travel(x,y-1);
            graph.erase(graph.begin());
        }
    }

    void travel(int x, int y){
        if(matrix.matrix[x][y] == 0)
            return;
        matrix.matrix[x][y] = 0;
        if(x+1 < matrix.m)
            travel(x+1,y);
        if(y+1 < matrix.n)
            travel(x,y+1);
        if(x-1 >= 0)
                travel(x-1,y);
        if(y-1 >= 0)
            travel(x,y-1);
    }


    Graph(Matrix& matrix):matrix(matrix){
    }
};
//스태틱은 전역에서 무조건 한번 초기화 해줘야됨
int Graph::numOfGraph = 0;

int main(){
    int T;
    int m,n,k;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> m >> n >> k;
        //일단 행렬 만듬
        Matrix matrix(m,n,k);
        Graph graph(matrix);
        
        for(int i = 0; i < k; i++){
            int x,y;
            cin >> x >> y;
            matrix.matrix[x][y] = 1;
            graph.graph.push_back({x,y});
        }

        graph.travel();

        cout << Graph::numOfGraph << '\n';
        Graph::numOfGraph = 0;
    }
    
    //오른쪽 -> 아래 가 1이면 그래프에 추가 -> 스태틱으로 그래프 갯수 세기, 방문시 0으로 바꾸기
    //시간 복잡도는 MN
}