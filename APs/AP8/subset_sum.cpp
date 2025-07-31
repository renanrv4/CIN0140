#include <bits/stdc++.h>

using namespace std;

void print(vector<int>& set, vector<bool>& subset) {
    for(int i = 0; i < set.size(); i++) {
        if(subset[i]) {
            cout << set[i] << " ";
        }
    }
    cout << "\n";
}

bool subset_sum(vector<int>& set, vector<bool>& subset, int j, int sum, int s) {
    if(sum == s) {
        print(set, subset);
        return true;
    }
    for(int i = j; i < set.size(); i++) {
        sum += set[i];
        subset[i] = true;
        if(subset_sum(set, subset, i+1, sum, s)) { return true; }
        sum -= set[i];
        subset[i] = false;    
    }

    return false;
}

int main() {
    int n, s; cin >> n >> s;
    vector<int> set(n, 0);
    vector<bool> subset(n, false);
    for(int i = 0; i < n; i++) {
        cin >> set[i];
    }
    subset_sum(set, subset, 0, 0, s);
    return 0;
}