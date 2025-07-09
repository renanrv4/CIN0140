#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

// Primeira questão da lista prática usando dijkstra para encontrar o caminho mínimo até um vértice

int dijkstra(vector<vector<pair<int, int>>>& graph, int s, int t) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    int n_size = graph.size();

    vector<bool> marked(n_size, false);
    vector<int> distances(n_size, INT_MAX);
    vector<int> parents(n_size, -1);

    heap.push(make_tuple(0, s, s)); distances[s] = 0;
    while(!heap.empty()) {
        int v = get<1>(heap.top());
        int p = get<2>(heap.top());
        heap.pop();

        if(marked[v]) { continue; }

        marked[v] = true; parents[v] = p;
        for(auto [w, weight] : graph[v]) {
            if(!marked[w] && distances[w] > distances[v] + weight) {
                distances[w] = distances[v] + weight;
                heap.push(make_tuple(distances[w], w, v));
            }
        }
    }
    if(distances[t] == INT_MAX) {
        return -1;
    } else {
        return distances[t];
    }
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int nn, m, s, t; cin >> nn >> m >> s >> t;
        vector<vector<pair<int, int>>> graph(nn);
        for(int j = 0; j < m; j++) {
            int u, v, w; cin >> u >> v >> w;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        int res = dijkstra(graph, s, t);
        if(res == -1) {
            cout << "Case #" << i+1 << ": unreachable" << "\n"; 
        } else {
            cout << "Case #" << i+1 << ": " << res << "\n";
        }
    }
    return 0;
}