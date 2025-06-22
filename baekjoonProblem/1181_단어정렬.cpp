#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<set<string>> str(51);

    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        str[s.size()].insert(s);
    }

    for(auto i : str){
        for(auto j : i){
            cout << j << '\n';
        }
    }
}