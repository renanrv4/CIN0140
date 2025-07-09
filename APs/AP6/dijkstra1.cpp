#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#include <tuple>

using namespace std;

// Usando o algoritmo de dijkstra para encontrar o menor caminho de um vértice v para todos os outros vértices do grafo

void dijkstra(vector<vector<pair<int, int>>>& graph ,int s) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    
    vector<bool> marked(graph.size(), false);
    vector<int> distances(graph.size(), INT_MAX);
    vector<int> parents(graph.size(), -1);

    heap.push(make_tuple(0, s, s)); distances[s] = 0;
    for(int i = 0; i < graph.size(); i++) {
        if(heap.empty()) { break; }
        int p = -1, v = -1;
        do {
            p = get<2>(heap.top());
            v = get<1>(heap.top()); heap.pop();
            if(!marked[v]) { break; }
        } while(!heap.empty());
        
        if(v == -1) { break; }
        marked[v] = true; parents[v] = p;

        for(auto [w, weight] : graph[v]) {
            if(marked[w] != true && distances[w] > distances[v] + weight) {
                distances[w] = distances[v] + weight;
                heap.push(make_tuple(distances[w], w, v));
            }
        }
    }
    for(int num = 0; num < distances.size(); num++) {
        if(num > 0) { cout << " "; }
        if(distances[num] == INT_MAX) {
            cout << "-1"; 
        } else {
            cout << distances[num];
        }
    }
    cout << "\n";
}

int main() {
    int n, m, v; cin >> n >> m >> v;
    vector<vector<pair<int, int>>> graph(n);
    for(int i = 0; i < m; i++) {
        int u, p, w; cin >> u >> p >> w;
        graph[u].emplace_back(p, w);
        graph[p].emplace_back(u, w);
    }
    dijkstra(graph, v);
    return 0;
}