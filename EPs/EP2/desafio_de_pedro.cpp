#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Exercício prático de Busca Binária
int bs(vector<int>& vect, int num) {
    int l = 0; int r = vect.size()-1;
    int menor_comp;
    while(l <= r) {
        int m = (l+r)/2;
        if(vect[m] == num) {
            menor_comp = vect[m];
            return menor_comp;
        } else if(vect[m] < num) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if(l == r) {
        int diff1 = abs(vect[l] - num);
        int diff2 = abs(vect[r+1] - num);
        if(diff1 > diff2) {
            menor_comp = vect[r+1];
        } else {
            menor_comp = vect[l];
        }
    } else {
        int diff1 = abs(vect[l] - num);
        int diff2 = abs(vect[r] - num);
        if(diff1 >= diff2) {
            menor_comp = vect[r];
        } else {
            menor_comp = vect[l];
        }
    }

    return menor_comp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int m; cin >> m;
    for(int j = 0; j < m; j++) {
        int q; cin >> q;
        cout << bs(arr, q) << "\n";
    }
    return 0;
}