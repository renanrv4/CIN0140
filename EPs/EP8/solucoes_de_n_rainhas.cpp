#include <iostream>
#include <vector>

using namespace std;

/*
Exercício Prático de Backtracking para descobrir a quantidade em que n rainhas podem ser colocadas em um
tabuleiro n x n sem que nenhuma rainha se ataque
*/


int qtd = 0;

bool valid(vector<vector<int>>& tabuleiro, int i, int j) {
    for(int ii = 0; ii < tabuleiro.size(); ii++) {
        if(tabuleiro[ii][j] == 1) {
            return false;
        }
    }
    int p1 = i; int p2 = j;
    while(p1 >= 0 && p2 >= 0) {
        if(tabuleiro[p1][p2] == 1) {
            return false;
        }
        p1--; p2--;
    }
    p1 = i; p2 = j;
    while(p1 >= 0 && p2 < tabuleiro.size()) {
        if(tabuleiro[p1][p2] == 1) {
            return false;
        }
        p1--; p2++;
    }
    return true;
}

void qns(int l, vector<vector<int>>& tabuleiro) {
    if(l == tabuleiro.size()) { qtd++; }
    else {
        for(int i = 0; i < tabuleiro.size(); i++) {
            if(valid(tabuleiro, l, i)) {
                tabuleiro[l][i] = 1;
                qns(l+1, tabuleiro);
                tabuleiro[l][i] = 0;
            }
        }
    }
}

int main() {
    int n; cin >> n;
    vector<vector<int>> tabuleiro(n, vector<int>(n, 0));
    qns(0, tabuleiro);
    cout << qtd << "\n";
    return 0;
}