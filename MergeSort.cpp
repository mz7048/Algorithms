#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& vec, int p, int m, int r){
    int n1 = m - p + 1;
    int n2 = r - m;

    vector<int> L1(n1+1),L2(n2+1);
    int i,j;
    for(i = 0; i < n1; i++){
        L1[i] = vec[p+i];
    }
    for(j = 0; j < n2; j++){
        L2[j] = vec[m+1+i];
    }
    L1[i] = (((unsigned)-1) >> 1);
    L2[j] = L1[i];

    i=0;j=0;

    for(int k = p; k <= r; k++){//k<=r 주의!!
        if(L1[i] >= L2[j]){
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
