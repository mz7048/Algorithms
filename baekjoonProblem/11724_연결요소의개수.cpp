#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

class Graph{
    //중복간선을 허용하지 않는 방향그래프
private:
    int numOfVertex;
    int numOfEdge;
    


public:
    static int numOfGraph;
    vector<int> degree;
    vector<vector<int>> graph;
    
    void connect(int i,int j){
        graph[i].push_back(j);
        graph[j].push_back(i);

        degree[i]++;
        degree[j]++;
    }

    void disconnect(int i, int j){
        numOfEdge--;
        for(auto it = graph[i].begin(); it != graph[i].end(); it++){
            if(*it == j){
                graph[i].erase(it);
                return;
            }
        }
    }

    vector<int> bfs(int start){
        vector<int> bfsTree;
        vector<string> bfsColor(numOfVertex,"White");
        queue<int> q;

        q.push(start);
        bfsTree.push_back(start);
        bfsColor[start] = "Gray";

        while(!q.empty()){
            int current = q.front();
            q.pop();
        
            for(auto it = graph[current].begin(); it != graph[current].end(); it++){
                if(bfsColor[*it] == "White"){
                    
                    q.push(*it);
                    bfsColor[*it] = "Gray";
                    bfsTree.push_back(*it);
                }
            }
            bfsColor[current] = "Black";
        }

        return bfsTree;
    }

    vector<int> dfs(int start){
        vector<int> dfsTree;
        vector<string> dfsColor(numOfVertex,"White");
        stack<int> st;

        st.push(start);

        while(!st.empty()){
            int current = st.top();
            st.pop();
            if(dfsColor[current] == "White"){
                dfsTree.push_back(current);
                dfsColor[current] = "Gray";
                for(auto it = graph[current].rbegin(); it != graph[current].rend(); it++){
                    if(dfsColor[*it] == "White"){
                        st.push(*it);
                        
                    }
                }
                dfsColor[current] = "Black";

            }    
        }

        return dfsTree;
    }

    void printBfs(int start){
            vector<int> result = bfs(start);
            for(int next : result){
                cout << next+1 << ' ';
            }
            cout << '\n';
        }

    void printDfs(int start){
        vector<int> result = dfs(start);
        for(int next : result){
            cout << next+1 << ' ';
        }
        cout << '\n';
    }

    void printGraph(){
        for(int i = 0; i < graph.size(); i++){
            cout << i+1 << ": ";
            for(int j = 0; j < graph[i].size(); j++){
                cout << graph[i][j]+1 << ' ';
            }
            cout << '\n';
        }
    }

    void printDegree(){
        for(int next: degree){
            cout << next << ' ';
        }
        cout << '\n';
    }

    Graph(){
        numOfVertex = 0;
        numOfEdge = 0;
    }
    Graph(int v,int e){
        
        numOfVertex = v;
        numOfEdge = e;
        graph.resize(v);
        degree.resize(v);
        for(int i = 0; i < v; i++){
            graph[i].resize(0);
        }
    }
};

int Graph::numOfGraph = 0;

int main(){
    int N,M;
    cin >> N >> M;

    Graph g(N,M);
    int arr[10001] = {};
    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;
        g.connect(u-1,v-1);
    }
    for(int i = 0; i < N; i++){
        if(arr[i] == 1) continue;
        Graph::numOfGraph++;
        vector<int> bfsTree = g.bfs(i);
        for(int j : bfsTree){
            arr[j] = 1;
        }
    }
    cout << Graph::numOfGraph;
    
}