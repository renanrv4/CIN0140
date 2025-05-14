#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

/*
Implemente o algoritmo mergesort para ordenar 
um array de inteiros de forma não-decrescente.
*/
void merge_method(vector<int>& vect, int l, int r) {
    vector<int> temp(vect.size());
    for(int n = l; n <= r; n++) { temp[n] = vect[n]; }
    int m = floor((l+r)/2);
    int i1 = l; int i2 = m+1;
    for(int curr = l; curr <= r; curr++) {
        if(i1 == m+1) {
            vect[curr] = temp[i2++];
        } else if(i2 > r) {
            vect[curr] = temp[i1++];
        } else if(temp[i1] <= temp[i2]) {
            vect[curr] = temp[i1++];
        } else {
            vect[curr] = temp[i2++];
        }
    } 
}

void merge_sort(vector<int>& vect, int l, int r) {
    if(l < r) {
        int m = floor((l+r)/2);
        merge_sort(vect, l, m);
        merge_sort(vect, m+1, r);
        merge_method(vect, l, r);
    }
}

int main() {
    int c; cin >> c;
    for(int i = 0; i < c; i++) {
        int qtd; cin >> qtd;
        vector<int> arr(qtd);
        for(int j = 0; j < qtd; j++) {
            cin >> arr[j];
        }
        merge_sort(arr, 0, arr.size()-1);
        for(int el : arr) {
            cout << el << " ";
        }
        cout << "\n";
    }
    return 0;
}