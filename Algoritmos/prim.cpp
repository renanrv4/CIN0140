#include <bits/stdc++.h>

using namespace std;

#define ti tuple<int, int, int>

// Implementando o algoritmo de Prim para gerar MSTs

void prim(vector<vector<pair<int, int>>>& graph) {
    priority_queue<ti, vector<ti>, greater<ti>> heap;
    vector<int> distances(graph.size(), INT_MAX);
    vector<bool> marked(graph.size(), false);
    vector<int> vertices(graph.size(), -1);
    vector<int> ord;
    heap.push(make_tuple(0, 0, 0)); distances[0] = 0;
    for(int i = 0; i < graph.size(); i++) {
        int p = -1, v = -1;
        do {
            if(heap.empty()) { return; }
            v = get<1>(heap.top());
            p = get<2>(heap.top());
            heap.pop();
        } while(marked[v]);
        
        marked[v] = true; vertices[v] = p;
        ord.push_back(v);
        for(auto [w, weight] : graph[v]) {
            if(marked[w] != true && distances[w] > weight) {
                distances[w] = weight;
                heap.push(make_tuple(distances[w], w, v));
            }
        } 
    }
    for(int pp : ord) {
        cout << pp << " ";
    }
    cout << "\n";
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }
    prim(graph);
    return 0;
}