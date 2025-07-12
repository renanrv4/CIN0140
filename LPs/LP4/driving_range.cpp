#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>

using namespace std;

#define ti tuple<int, int, int>

int prim(vector<vector<pair<int, int>>>& graph) {
    priority_queue<ti, vector<ti>, greater<ti>> heap;

    vector<int> distances(graph.size(), INT_MAX);
    vector<bool> marked(graph.size(), false);
    vector<int> parents(graph.size(), -1);

    int visited_count = 0, min_range = 0;

    heap.push(make_tuple(0, 0, 0)); distances[0] = 0;
    for(int i = 0; i < graph.size(); i++) {
        int p = -1, v = -1, range = -1; 
        do {
            if(heap.empty()) { return -1; }
            range = get<0>(heap.top());
            v = get<1>(heap.top());
            p = get<2>(heap.top());
            heap.pop();
        } while(marked[v]);

        marked[v] = true; parents[v] = p;
        visited_count++; min_range = max(min_range, range);

        for(auto [w, weight] : graph[v]) {
            if(marked[w] != true && distances[w] > weight) {
                distances[w] = weight;
                heap.push(make_tuple(weight, w, v));
            }
        }
    }

    if(visited_count < graph.size()) {
        return -1;
    } else {
        return min_range;
    }
}

int main() {
    while(true) {
        int n, m; cin >> n >> m;
        if(n == 0 && m == 0) { break; }
        
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for(int i = 0; i < m; i++) {
            int a, b, w; cin >> a >> b >> w;
            graph[a].emplace_back(b, w);
            graph[b].emplace_back(a, w);
        }

        int res = prim(graph);
        if (res == -1){
            cout << "IMPOSSIBLE" << "\n";
        } else {
            cout << res << "\n";
        }
    }
    return 0;
}
