#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& graph, int s, vector<int>& distances, vector<int>& parents) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    vector<bool> marked(graph.size(), false);

    heap.push(make_tuple(0, s, s)); distances[s] = 0;
    for(int i = 0; i < graph.size(); i++) {
        int p = -1, v = -1;
        do {
            if(heap.empty()) { return; }
            v = get<1>(heap.top());
            p = get<2>(heap.top());
            heap.pop();
        } while(marked[v]);

        marked[v] = true; parents[v] = p;

        for(auto [w, weight] : graph[v]) {
            if(marked[w] != true && distances[w] > distances[v] + weight) {
                distances[w] = distances[v] + weight;
                heap.push(make_tuple(distances[w], w, v));
            }
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    vector<int> distances(graph.size(), INT_MAX);
    vector<int> parents(graph.size(), -1);
    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a-1].emplace_back(b-1, w);
        if(a != b) {
            graph[b-1].emplace_back(a-1, w);
        }
    }
    dijkstra(graph, 0, distances, parents);
    if(distances[n-1] == INT_MAX) {
        cout << -1;
    } else {
        vector<int> res;
        res.push_back(n);
        int pind = parents[n-1];
        res.push_back(pind+1);
        while(pind != 0) {
            pind = parents[pind];
            res.push_back(pind+1);
        }
        for(auto it = res.rbegin(); it != res.rend(); it++) {
            cout << *it << " ";
        }
    }
    return 0;
}