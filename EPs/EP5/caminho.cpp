#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

bool BFS(vector<vector<int>>& adj, vector<bool>& mark, int v, int v2) {
    queue<int> queue_visit;
    vector<int> predecessors(adj.size(), -1);
    queue_visit.push(v);
    mark[v] = true;
    int vbegin = v;
    stack<int> path;
    while(queue_visit.size() > 0) {
        v = queue_visit.front(); queue_visit.pop();
        for(int i : adj[v]) {
            if(mark[i] == false) {
                mark[i] = true;
                queue_visit.push(i);
                predecessors[i] = v;
            }
            if(i == v2) {
                path.push(v2);
                while(v2 != vbegin) {
                    path.push(predecessors[v2]);
                    v2 = predecessors[v2];
                }
                while(path.size() > 0) {
                    if(path.size() == 1) {
                        cout << path.top() << "\n";
                    } else {
                        cout << path.top() << " ";
                    }
                    path.pop();
                }
                return true;
            }
        }
    }
    return false;
}

void graphTraverse(vector<vector<int>>& adj, int v, int v2) {
    vector<bool> mark(adj.size(), false);
    bool found = false;
    found = BFS(adj, mark, v, v2);
    if(!found) {
        cout << -1 << "\n";
    }
}

int main() {
    int c; cin >> c;
    for(int i = 0; i < c; i++) {
        cout << "Caso " << i+1 << "\n";
        int v, a; cin >> v >> a;
        vector<vector<int>> adj_list(v);
        for(int j = 0; j < a; j++) {
            int u, p; cin >> u >> p;
            adj_list[u].push_back(p);
            adj_list[p].push_back(u);
        }
        for(auto& links : adj_list) {
            sort(links.begin(), links.end());
        }
        int qtd; cin >> qtd;
        for(int l = 0; l < qtd; l++) {
            int vp, vf; cin >> vp >> vf;
            graphTraverse(adj_list, vp, vf);
        }
    }
}