#include <bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int> v) {
    for(int i = 0; i < v.size()-1; i++) {
        for(int j = 0; j < v.size()-1-i; j++) {
            if(v[j+1] < v[j]) {
                swap(v[j], v[j+1]);
            }
        }
    }
    for(int num : v) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {89, 45, 68, 90, 29, 34, 17};
    bubble_sort(arr);
    return 0;
}