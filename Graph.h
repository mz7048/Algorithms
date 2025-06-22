#ifndef GRAPH_H
#define GRAPH_H

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
    vector<int> degree;
    vector<vector<int>> graph;
    
    void connect(int i,int j);

    void disconnect(int i, int j);

    vector<int> bfs(int start);
    vector<int> dfs(int start);

    void printBfs(int start);
    void printDfs(int start);
    void printGraph();
    void setGraphDegree();
    void printDegree();
    Graph();
    Graph(int v,int e);
};

#endif

