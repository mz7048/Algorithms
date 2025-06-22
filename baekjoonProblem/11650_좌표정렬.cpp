#include<iostream>
#include<vector>
using namespace std;
//이 문제는 digit 계산 또는 카운트 소트 계산시에 음수를 생각안했어서 까다로웠다
vector<vector<int>> countSort(vector<vector<int>>& vec, int base,int mode){
    int count[19] = {};
    vector<vector<int>> sorted(vec.size());

    for(vector<int> next : vec){
        int digit = ((next[mode] / base) % 10 + 9) % 19;
        count[digit]++;
    }

    for(int i = 1; i < 19; i++){
        count[i] += count[i-1];
    }

    for(int i = vec.size()-1; i >= 0; i--){
        int digit = ((vec[i][mode] / base) % 10 + 9) % 19; 
        sorted[--count[digit]] = vec[i];
    }
    return sorted;
}

int digit(int n){
    if (n == 0) return 1;
    else if(n<0) n*=-1;

    int result = 0;
    while(n>0){
        result++;
        n/=10;
    }
    return result;
}

vector<vector<int>> radixSort(vector<vector<int>>& vec,int mode){
    int maxDigit = 0;
    for(vector<int> next : vec){//N
        int digited = digit(next[mode]);
        if(digited > maxDigit) maxDigit = digited;
    }
    int base = 1;
    for(int i = 0; i < maxDigit; i++){
        vec = countSort(vec,base,mode);
        base *= 10;
    }
    return vec;
}

void printVec(vector<vector<int>> vec){
    for(vector<int> i : vec){
        cout << i[0] << ' ' << i[1] << '\n';
    }
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> coords(N);
    for(int i = 0; i < N; i++){
        int x,y;
        cin >> x >> y;
        coords[i].push_back(x);
        coords[i].push_back(y);
    }
    coords = radixSort(coords,1);
    coords = radixSort(coords,0);

    printVec(coords);
    //
}