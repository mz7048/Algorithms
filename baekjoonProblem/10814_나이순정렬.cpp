#include<iostream>
#include<map>
#include<vector>
using namespace std;


int main(){
    int N;
    cin >> N;
    map<int,vector<string>> result;
    for(int i = 0; i < N; i++){
        int n;
        string s;
        cin >> n >> s;
        result[n].push_back(s);
    }
    for(auto it = result.begin(); it != result.end(); it++){
        for(auto i : it->second){
            cout << it->first << ' ' << i << '\n';
        }
    }
}