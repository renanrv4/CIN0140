#include <bits/stdc++.h>

using namespace std;

void merge_method(vector<int>& v, int l, int r) {
    vector<int> temp(v.size());
    for(int i = l; i <= r; i++) { temp[i] = v[i]; }
    int m = floor((l+r)/2);
    int i1 = l; int i2 = m + 1;
    for(int curr = l; curr <= r; curr++) {
        if(i1 == m+1) { v[curr] = temp[i2++]; }
        else if(i2 > r) { v[curr] = temp[i1++]; }
        else if (temp[i1] <= temp[i2]) {
            v[curr] = temp[i1++];
        } else {
            v[curr] = temp[i2++];
        }
    }
}

void merge_sort(vector<int>& v, int l, int r) {
    if(l < r) {
        int m = floor((l+r)/2);
        merge_sort(v, l, m);
        merge_sort(v, m+1, r);
        merge_method(v, l, r);
    }
}

int main() {
    vector<int> arr = {89, 45, 68, 90, 29, 34, 17};
    merge_sort(arr, 0, arr.size()-1);
    for(int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
    return 0;
}