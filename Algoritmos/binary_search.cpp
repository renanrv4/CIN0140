#include <bits/stdc++.h>
using namespace std;

bool b_search(int num, vector<int> arr) {
    int l = 0; int r = arr.size()-1;
    while(l <= r) {
        int m = floor((l+r)/2);
        if(arr[m] == num) {
            return true;
        } else if(arr[m] > num) {
            r = m-1;
        } else if(arr[m] < num) {
            l = m+1;
        }
    }
    return false;
}

int main() {
    // Para o funcionamento correto do algoritmo de busca binária, a lista deve ser ordenada
    vector<int> vect = {1, 2, 3, 5, 6, 7, 8, 9};
    int n = 1;
    if(b_search(n, vect)) {
        cout << "O número foi encontrado!!" << "\n";
    } else {
        cout << "O número não foi encontrado ¯\\_(ツ)_/¯" << "\n";
    }
}