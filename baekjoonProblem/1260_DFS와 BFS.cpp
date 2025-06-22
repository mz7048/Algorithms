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
    
    
    vector<vector<int>> graph;
    
    void connect(int i,int j){
        graph[i].push_back(j);
        graph[j].push_back(i);
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

                    /*
                    cout << *it << ": ";
                    printColor(bfsColor);
                    */
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
                        /*
                        cout << *it << ": ";
                        printColor(dfsColor);
                        */
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


    Graph(){
        numOfVertex = 0;
        numOfEdge = 0;
    }
    Graph(int v,int e){
        numOfVertex = v;
        numOfEdge = e;
        graph.resize(v);
    }
};


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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V,E,S;
    cin >> V >> E >> S;
    Graph graph(V,E);//O(V)

    //O(E)
    for(int i = 0; i < E; i++){
        int v,e;
        cin >> v >> e;
        graph.connect(v-1,e-1);
    }
    
    //O(VELogE) -> ELogV라네요 어캐 증명하지
    for(int i = 0; i < V; i++){
        mergeSort(graph.graph[i],0,graph.graph[i].size() - 1);
    }
    
    //graph.printGraph();

    //V+E
    graph.printDfs(S-1);
    graph.printBfs(S-1);
}

