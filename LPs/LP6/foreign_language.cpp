#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m; long long a, b, c; cin >> n >> m >> a >> b >> c;
    cin.ignore();
    string ph; getline(cin, ph);
    string ph_strange; getline(cin, ph_strange);

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    for(int j = 0; j <= m; j++) {
        dp[0][j] = j * a;
    }
    for(int i = 0; i <= n; i++) {
        dp[i][0] = i * b;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            long long insert = dp[i][j-1] + a;
            long long remove = dp[i-1][j] + b;
            long long transform = dp[i-1][j-1];
            if(ph[i-1] != ph_strange[j-1]) {
                transform += c;
            }
            dp[i][j] = min({insert, remove, transform});
        }
    }

    cout << dp[n][m] << "\n";
    return 0;
}