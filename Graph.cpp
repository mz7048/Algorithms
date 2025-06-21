#include "Graph.h"

Graph::Graph(){
    numOfVertex = 0;
    numOfEdge = 0;
}

Graph::Graph(int v,int e){
    numOfVertex = v;
    numOfEdge = e;
    graph.resize(v);
}

void Graph::connect(int i,int j){
    numOfEdge++;
    graph[i].push_back(j);
}

void Graph::disconnect(int i, int j){
    numOfEdge--;
    for(auto it = graph[i].begin(); it != graph[i].end(); it++){
        if(*it == j){
            graph[i].erase(it);
            return;
        }
    }
}

vector<int> Graph::bfs(int start){
    vector<int> bfsTree;
    vector<string> bfsColor;
    queue<int> q;

    bfsColor.resize(numOfVertex);

    for(int i = 0; i < numOfVertex; i++){
        bfsColor[i] = "White";
    }
    q.push(start);
    bfsTree.push_back(start);

    while(!q.empty()){
        int current = q.front();
        q.pop();
        bfsColor[current] = "Gray";
        for(auto it = graph[current].begin(); it != graph[current].end(); it++){
            int neighbor = *it;
            if(bfsColor[neighbor] == "White"){
                q.push(neighbor);
                bfsTree.push_back(neighbor);
            }
        }
        bfsColor[current] = "Black";
    }
    
    return bfsTree;
}

vector<int> Graph::dfs(int start){
    vector<int> dfsTree;
    vector<string> dfsColor(numOfVertex,"White");
    stack<int> q;

    q.push(start);

    while(!q.empty()){
        int current = q.top();
        q.pop();
        if(dfsColor[current] == "White"){
            dfsColor[current] = "Gray";
            dfsTree.push_back(current);
        }
        for(auto it = graph[current].rbegin(); it != graph[current].rend(); it++){
            int neighbor = *it;
            if(dfsColor[neighbor] == "White"){
                q.push(neighbor);
            }
        }
        dfsColor[current] = "Black";
    }
    return dfsTree;
}
