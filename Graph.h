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
    vector<vector<int>> graph;

public:
    void connect(int i,int j){}

    void disconnect(int i, int j){}

    vector<int> bfs(int start);
    vector<int> dfs(int start);

    void printBfs();
    void printDfs();

    Graph(){}
    Graph(int v,int e){}
};

#endif

