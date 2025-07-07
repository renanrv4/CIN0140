#include <vector>
#include <iostream>

using namespace std;

/*Usando DFS com estratégia do toposort para descobrir se o grafo dirigido 
possui ou não possui arestas bidirecionais (quebrando a lógica do toposort)*/

bool visit = false;

void toposort(vector<vector<int>>& adj, vector<int>& mark, int v) {
    mark[v] = 1;
    for(int i : adj[v]) {
        if(mark[i] == 0) {
            toposort(adj, mark, i);
        } else if(mark[i] == 1) {
            visit = true;
            return;
        }
    }
    mark[v] = 2;
}

void graphTraverse(vector<vector<int>>& adj) {
    vector<int> mark(adj.size(), 0);
    for(int i = 0; i < adj.size(); i++) {
        if(mark[i] == 0) {
            toposort(adj, mark, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        int n, k; cin >> n >> k;
        vector<vector<int>> adj_list(n);
        int last_val = 0;
        int pl = 0; 
        for(int j = 0; j < k; j++) {
            for(int u = 0; u < n; u++) {
                cin >> pl; pl--;
                if(u > 1) {
                    adj_list[last_val].push_back(pl);
                }
                last_val = pl;
            }
        }

        for(int m = 0; m < k; m++) {
            graphTraverse(adj_list);
        }
        if(visit == true) {
            visit = false;
            cout << "no" << "\n";
        } else {
            cout << "yes" << "\n";
        }
    }
}