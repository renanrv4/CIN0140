#include <bits/stdc++.h>

using namespace std;

// Implementando Knapsack com DP

// Bottom-up

int dp(int n, int W, vector<int>& w, vector<int>& v, vector<vector<int>>& F) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            if(i == 0 || j == 0) {
                F[i][j] = 0;
            } else if(w[i] <= j) {
                F[i][j] = max(F[i-1][j], v[i] + F[i-1][j-w[i]]);
            } else {
                F[i][j] = F[i-1][j];
            }
        }
    }
    return F[n][W];
}

// Top-down

int dp_top(int i, int j, vector<int>& w, vector<int>& v, vector<vector<int>>& F) {
    if (i == 0 || j == 0) return 0;
    if(F[i][j] < 0) {
        int value;
        if(j < w[i]) {
            value = dp_top(i-1, j, w, v, F);
        } else {
            value = max(dp_top(i-1, j, w, v, F), v[i] + dp_top(i-1, j-w[i], w, v, F));
        }
        F[i][j] = value;
    }
    return F[i][j];
}

int main() {
    int i, w; cin >> i >> w;
    vector<int> weights(i+1, 0);
    vector<int> itens(i+1, 0);
    vector<vector<int>> f(i+1, vector<int>(w+1, -1));
    vector<vector<int>> f2(i+1, vector<int>(w+1, -1));
    for(int ii = 1; ii < i+1; ii++) {
        cin >> weights[ii] >> itens[ii];
    }
    
    dp(i, w, weights, itens, f);
    dp_top(i, w, weights, itens, f2);

    cout << "Bottom-up" << "\n\n";
    for (int i = 0; i < f.size(); i++) {
        for (int j = 0; j < f[i].size(); j++) {
            cout << setw(3) << f[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    cout << "Top-down" << "\n\n";
    for (int i = 0; i < f2.size(); i++) {
        for (int j = 0; j < f2[i].size(); j++) {
            cout << setw(3) << f2[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}