#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> all_sols;

bool valid(vector<vector<int>>& tabuleiro, int l, int i) {
    for(int j = 0; j < l; j++) {
        if(tabuleiro[j][i] == 1) {
            return false;
        }
    }
    // 1º Diagonal
    int ll = l; int ii = i;
    while(ll >= 0 && ii >= 0) {
        if(tabuleiro[ll][ii] == 1) {
            return false;
        }
        ll--; ii--;
    }
    // 2º Diagonal
    ll = l; ii = i;
    while(ll >= 0 && ii < tabuleiro.size()) {
        if(tabuleiro[ll][ii] == 1) {
            return false;
        }
        ll--; ii++;
    }
    return true;
}

void qns(int n, vector<vector<int>>& tabuleiro) {
    if(n == tabuleiro.size()) { all_sols.push_back(tabuleiro); return; }
    else {
        for(int i = 0; i < tabuleiro.size(); i++) {
            if(valid(tabuleiro, n, i)) {
                tabuleiro[n][i] = 1;
                qns(n+1, tabuleiro);
                tabuleiro[n][i] = 0;
            }
        }
    }
}

void print(const vector<vector<int>>& sol, int num) {
    cout << "Sol. " << num << ":\n";
    for(int i = 0; i < sol.size(); i++) {
        for(int j = 0; j < sol.size(); j++) {
            cout << sol[i][j] << " "; 
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int n; cin >> n;
    vector<vector<int>> tabuleiro(n, vector<int>(n, 0));
    qns(0, tabuleiro);
    cout << all_sols.size() << "\n" << "\n";
    int count = 1;
    for(const auto& v : all_sols) {
        print(v, count++);
    }
    return 0;
}