#include<iostream>
#include<vector>
using namespace std;

vector<int> countSort(vector<int>& vec, int N){
    vector<int> count(N,0);
    vector<int> sorted(vec.size());
    // 1 5 3 1 2 5
    for(int next : vec){
        count[next]++;
    }
    
    for (int i = 1; i < N; i++)
        count[i] += count[i - 1];

    for(int i = vec.size() -1; i >= 0; i--){
        sorted[--count[vec[i]]] = vec[i];
    }

    return sorted;
}

vector<int> countSort(vector<int>& vec, int N, int base){
    vector<int> count(N,0);
    vector<int> sorted(vec.size());
    // 1 5 3 1 2 5
    for(int next : vec){
        int digit = ((next /base) % 10 + 9)%19;   
        count[digit]++;
    }

    for (int i = 1; i < N; i++)
        count[i] += count[i - 1];

    
    for(int i = vec.size() -1; i >= 0; i--){
        int digit = ((vec[i] / base) % 10 + 9)%19;
        sorted[--count[digit]] = vec[i];
    }

    return sorted;
}

int digit(int n){
    if (n == 0) return 1;
    if(n < 0) n*=-1;

    int result = 0;
    
    while(n>0){
        n/=10;
        result++;
    }
    return result;
}

vector<int> radixSort(vector<int>& vec){
    int maxDigit = 0;
    for(int i = 0; i < vec.size(); i++){
        int digited = digit(vec[i]);
        if(maxDigit < digited){
            maxDigit = digited;
        }
    }
    int base = 1;
    for(int i = 0; i < maxDigit; i++){
        vec = countSort(vec,19,base);
        base *= 10;
    }
    return vec;
}

