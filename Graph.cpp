#include "Graph.h"

Graph::Graph(){
    numOfVertex = 0;
    numOfEdge = 0;
}

Graph::Graph(int v,int e){
    numOfVertex = v;
    numOfEdge = e;
    graph.resize(v);
    degree.resize(v);
    for(int i = 0; i < v; i++){
        graph[i].resize(0);
    }
}

void Graph::connect(int i,int j){
    graph[i].push_back(j);
    graph[j].push_back(i);

    degree[i]++;
    degree[j]++;
}

void Graph::setGraphDegree(){
    for(int i = 0; i < graph.size(); i++){
        graph[i].resize(degree[i]);
    }
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


void printColor(vector<string> color){
    for(string next : color){
        cout << next << ' ';
    }
    cout << '\n';
}

vector<int> Graph::bfs(int start){
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

                //
                cout << *it+1 << ": ";
                printColor(bfsColor);
                //
            }
        }
        bfsColor[current] = "Black";
    }

    return bfsTree;
}


vector<int> Graph::dfs(int start){
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
            //
            cout << current+1 << ": ";
            printColor(dfsColor);
            //
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

void Graph::printBfs(int start){
    vector<int> result = bfs(start);
    for(int next : result){
        cout << next+1 << ' ';
    }
    cout << '\n';
}

void Graph::printDfs(int start){
    vector<int> result = dfs(start);
    for(int next : result){
        cout << next+1 << ' ';
    }
    cout << '\n';
}

void Graph::printGraph(){
    for(int i = 0; i < graph.size(); i++){
        cout << i+1 << ": ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j]+1 << ' ';
        }
        cout << '\n';
    }
}

void Graph::printDegree(){
    for(int next: degree){
        cout << next << ' ';
    }
    cout << '\n';
}

void merge(vector<int>& vec, int p, int m, int r){
    int n1 = m - p + 1;
    int n2 = r - m;

    vector<int> L1(n1+1),L2(n2+1);
    int i,j;
    for(i = 0; i < n1; i++){
        L1[i] = vec[p+i];
    }
    for(j = 0; j < n2; j++){
        L2[j] = vec[m+1+j];
    }
    L1[i] = (((unsigned)-1) >> 1);
    L2[j] = L1[i];

    i=0;j=0;

    for(int k = p; k <= r; k++){
        if(L1[i] <= L2[j]){
            vec[k] = L1[i++];
        }else{
            vec[k] = L2[j++];
        }
    }
}

vector<int> mergeSort(vector<int>& vec,int p,int r){
    if(p < r){
        int m = (p+r)/2;
        mergeSort(vec,p,m);
        mergeSort(vec,m+1,r);
        merge(vec,p,m,r);
    }
    return vec;
}



int main(){
    int V,E,S;
    cin >> V >> E >> S;
    Graph graph(V,E);

    for(int i = 0; i < E; i++){
        int v,e;
        cin >> v >> e;
        graph.connect(v-1,e-1);
    }
    
    //graph.setGraphDegree();
    graph.printDegree();

    for(int i = 0; i < V; i++){
        mergeSort(graph.graph[i],0,graph.graph[i].size() - 1);
    }
    
    graph.printGraph();

    
    graph.printDfs(S-1);
    graph.printBfs(S-1);
}


