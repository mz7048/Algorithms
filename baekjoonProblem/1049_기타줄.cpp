#include<iostream>
using namespace std;


int min(int& i, int& j){
    return (i-j<=0 ? i:j);
}

int main(){
    int N,M,money=0;
    int minSet = 1001,minOne = 1001;
    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        int set,one;
        cin >> set >> one;
        if(minSet > set) minSet = set;
        if(minOne > one) minOne = one;
    }
    int val = 1;

    val = min(minSet,minOne * 6);
    money = (N/6) * val + min(minSet,minOne * (N%6));
//cout << N << '\n';

    cout << money << '\n';
}
