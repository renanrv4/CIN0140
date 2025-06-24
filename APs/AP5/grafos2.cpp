#include <vector>
#include <iostream>
#include <stack>

#define UNVISITED 0
#define VISITED 1

using namespace std;

class Graph {
    private:
        vector<vector<int>> adj_list;
        int numEdge;
        vector<int> mark;
    public:
        stack<int> topo_sort;
        Graph(int n) {
            adj_list = vector<vector<int>>(n);
            numEdge = 0;
            mark = vector<int>(n, 0);
        }

        int n(){
            return adj_list.size();
        }

        int e(){
            return numEdge;
        }

        vector<int>& getConnections(int v) {
            return adj_list[v];
        }

        void setEdge(int i, int j, int wt) {
            adj_list[i].push_back(j);
            numEdge++;
        }

        void delEdge(int i, int j) {
            for (auto it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
                if (*it == j) {
                    adj_list[i].erase(it);
                    numEdge--;
                    break;
                }
            }
        }

        bool isEdge(int i, int j) {
            for(int w : adj_list[i]) {
                if(w == j) {
                    return true;
                }
            }
            return false;
        }

        int weight(int i, int j) {
            return isEdge(i, j) ? 1 : 0;
        }

        void setMark(int v, int val) {
            mark[v] = val;
        }

        int getMark(int v) {
            return mark[v];
        }
};

void toposort(Graph& g, int v) {
    g.setMark(v, VISITED);
    for(int w : g.getConnections(v)) {
        if(g.getMark(w) == UNVISITED) {
            toposort(g, w);
        }
    }
    g.topo_sort.push(v);
}

void graphTraverse(Graph& g) {
    for(int i = 0; i < g.n(); i++) {
        g.setMark(i, UNVISITED);
    }
    for(int j = 0; j < g.n(); j++) {
        if(g.getMark(j) == UNVISITED) {
            toposort(g, j);
        }
    }
    while(g.topo_sort.size() > 0) {
        cout << g.topo_sort.top() << " ";
        g.topo_sort.pop();
    }
}


int main() {
    int n, m; cin >> n >> m;
    Graph graph(n);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        graph.setEdge(u, v, 1);
    }
    graphTraverse(graph); cout << "\n";   
    return 0;
}