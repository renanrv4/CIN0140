#include <vector>
#include <iostream>
#include <string>

using namespace std;

// Exercício Prático de Busca Binária
bool bs(vector<string>& vect, string w) {
    int l = 0; int r = vect.size()-1;
    while(l <= r) {
        int m = (l+r)/2;
        if(vect[m] == w) {
            return true;
        } else if(vect[m] < w) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int m; cin >> m;
    int res = 0;
    for(int j = 0; j < m; j++) {
        string word; cin >> word;
        if(bs(arr, word)) {
            res++;
        }
    }
    cout << res << "\n";

    return 0;
}