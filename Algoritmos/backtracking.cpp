#include <bits/stdc++.h>

using namespace std;

void all_subsets(vector<bool>& set, int p) {
    cout << "{ ";
    for(int i = 0; i < set.size(); i++) {
        if(i == set.size()-1) {
            cout << set[i] << " }\n";
        } else {
            cout << set[i] << ", ";
        }
    }
    for(int j = p; j < set.size(); j++) {
        set[j] = true;
        all_subsets(set, j+1);
        set[j] = false;
    }
}

int main() {
    int n; cin >> n;
    vector<bool> set(n, false);
    all_subsets(set, 0);
    return 0;
}