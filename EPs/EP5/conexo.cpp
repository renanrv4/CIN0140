#include <vector>
#include <iostream>

using namespace std;

void DFS(vector<vector<int>>& adj, vector<bool>& mark, int v) {
    mark[v] = true;
    for(int i : adj[v]) {
        if(mark[i] == false) {
            DFS(adj, mark, i);
        }
    }
}

int graphTraverse(vector<vector<int>>& adj) {
    vector<bool> mark(adj.size(), false);
    int sub = 0;
    for(int i = 0; i < adj.size(); i++) {
        if(mark[i] == false) {
            DFS(adj, mark, i);
            sub++;
        }
    }
    return sub;
}

int main() {
    int c; cin >> c;
    for(int i = 0; i < c; i++) {
        int v, a; cin >> v >> a; 
        vector<vector<int>> adj_list(v);
        for(int j = 0; j < a; j++) {
            int v1, v2; cin >> v1 >> v2;
            adj_list[v1].push_back(v2);
            adj_list[v2].push_back(v1);
        }
        cout << graphTraverse(adj_list) << "\n";
    }
    return 0;
}