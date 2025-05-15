#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void merge(vector<int>& vect, int l, int r) {
    vector<int> temp_vect(vect.size());
    for(int i = 0; i < vect.size(); i++) {
        temp_vect[i] = vect[i];
    }
    int m = floor((l+r)/2);
    int i1 = l; int i2 = m+1;
    for(int curr = l; curr <= r; curr++) {
        if(i1 == m+1) {
            vect[curr] = temp_vect[i2++];
        } else if (i2 > r) {
            vect[curr] = temp_vect[i1++];
        } else if(temp_vect[i1] <= temp_vect[i2]) {
            vect[curr] = temp_vect[i1++];
        } else {
            vect[curr] = temp_vect[i2++];
        }
    }
}

void merge_sort(vector<int>& vect, int l, int r) {
    if(l < r) {
        int m = floor((l+r)/2);
        merge_sort(vect, l, m);
        merge_sort(vect, m+1, r);
        merge(vect, l, r);
    }
}

int main() {
    int testes; cin >> testes;
    for(int i = 0; i < testes; i++) {
        int n; cin >> n;
        vector<int> arr(2*n);
        for(int j = 0; j < 2*n; j++) {
            cin >> arr[j];
        }
        merge_sort(arr, 0, arr.size()-1);
        int x, y;
        int max_sum = 0;
        while(arr.size() != 0) {
            x = arr.size()-2; y = arr.size()-1;
            max_sum += min(arr[x], arr[y]);
            arr.pop_back(); arr.pop_back();
        }
        cout << max_sum << "\n";
    }
    return 0;
}