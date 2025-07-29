#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> coins(n, 0);
    vector<int> qtd_coins(k+1, INT_MAX);
    qtd_coins[0] = 0;
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    for(int j = 1; j <= k; j++) {
        int temp = INT_MAX;
        for(int l = 0; l < n; l++) {
            if(j >= coins[l] && qtd_coins[j - coins[l]] != INT_MAX) {
                temp = min(qtd_coins[j - coins[l]], temp);
            }
        }
        if(temp != INT_MAX) { qtd_coins[j] = temp+1; }
    }
    if(qtd_coins[k] == INT_MAX) {
        cout << -1 << "\n";
    } else {
        cout << qtd_coins[k] << "\n";
    }
    return 0;
}