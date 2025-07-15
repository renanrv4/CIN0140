#include <vector>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

// Implementando o algoritmo de Kruskal para gerar MSTs

class DSU {
    private:
        vector<int> parents;
        vector<int> sizes;
    public:
        DSU(int size) {
            parents.resize(size); sizes.resize(size, 1);
            for(int i = 0; i < size; ++i) {
                parents[i] = i;
            }
        }

        int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

        void unite(int x, int y) {
            int x_root = find(x);
            int y_root = find(y);
            if(x_root == y_root) { return; }

            if(sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
            sizes[x_root] += sizes[y_root];
		    parents[y_root] = x_root;
        }

        bool connected(int x, int y) { return find(x) == find(y); }
};

void kruskal(vector<vector<pair<int, int>>>& graph) {
    DSU dsu(graph.size());
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    vector<vector<bool>> added(graph.size(), vector<bool>(graph.size(), false));
    
    for(int i = 0; i < graph.size(); i++) {
        for(auto [v, w] : graph[i]) {
            if(!added[i][v]) {
                heap.push(make_tuple(w, i, v));
                added[i][v] = added[v][i] = true;
            }
        }
    }

    vector<tuple<int, int, int>> ds;
    int numMST = graph.size();
    while(!heap.empty() && numMST > 1) {
        int weight = get<0>(heap.top());
        int a = get<1>(heap.top());
        int b = get<2>(heap.top()); heap.pop();

        if(!dsu.connected(a, b)) {
            dsu.unite(a, b);
            ds.emplace_back(weight, a, b);
            numMST--;
        }
    }

    cout << "Arestas da Árvore Geradora Mínima:\n";
    for (auto [w, u, v] : ds) {
        cout << u << " - " << v << " (peso " << w << ")\n";
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    for(int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }
    kruskal(graph);
    return 0;
}