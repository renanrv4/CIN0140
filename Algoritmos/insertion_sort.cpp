#include <bits/stdc++.h>

using namespace std;

/*
Insere elementos nas suas posições corretas
Realizando um shift right para realocar elementos no vetor, e
garantir que o elemento esteja na posição correta
*/ 
void insertion_sort(vector<int> v) {
    for(int i = 1; i < v.size(); i++) {
        int val = v[i];
        int j = i-1;
        while(j >= 0 && v[j] > val) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = val;
    }
    for(int num : v) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {89, 45, 68, 90, 29, 34, 17};
    insertion_sort(arr);
    return 0;
}