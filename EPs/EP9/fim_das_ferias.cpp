#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Exercício Prático sobre DP

struct Brinquedo {
    string nome;
    int peso;
    int felicidade;
};

int main() {
    int n, W;
    cin >> n >> W;

    vector<Brinquedo> brinquedos(n);
    for (int i = 0; i < n; ++i) {
        cin >> brinquedos[i].nome >> brinquedos[i].peso >> brinquedos[i].felicidade;
    }
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int peso = brinquedos[i - 1].peso;
        int felicidade = brinquedos[i - 1].felicidade;

        for (int w = 0; w <= W; ++w) {
            if (peso <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - peso] + felicidade);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int w = W;
    vector<string> escolhidos;
    for (int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            escolhidos.push_back(brinquedos[i - 1].nome);
            w -= brinquedos[i - 1].peso;
        }
    }

    reverse(escolhidos.begin(), escolhidos.end());

    cout << dp[n][W] << ": ";

    bool primeiro = true;
    for (const Brinquedo &b : brinquedos) {
        if (find(escolhidos.begin(), escolhidos.end(), b.nome) != escolhidos.end()) {
            if (!primeiro) cout << ", ";
            cout << b.nome;
            primeiro = false;
        }
    }

    cout << endl;
    return 0;
}
