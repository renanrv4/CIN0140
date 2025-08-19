#include <vector>
#include <iostream>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

// Exercício Prático sobre MST

void prim(vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    vector<int> distances(n, INT_MAX);
    vector<bool> marked(n, false);
    vector<int> parents(n, -1);
    vector<int> ord;

    heap.push(make_tuple(0, 0, 0)); distances[0] = 0;
    for(int i = 0; i < n; i++) {
        int p = -1, v = -1;
        do {
            if(heap.empty()) { return; }
            v = get<1>(heap.top());
            p = get<2>(heap.top());
            heap.pop();
        } while(marked[v]);

        marked[v] = true; parents[v] = p;
        ord.push_back(v);
        for(auto [w, weight] : graph[v]) {
            if(marked[w] != true && distances[w] > weight) {
                distances[w] = weight;
                heap.push(make_tuple(distances[w], w, v));
            }
        }
    }
    int sum = 0;
    for(int pp : ord) {
        sum += distances[pp];
    }

    cout << sum << "\n";
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