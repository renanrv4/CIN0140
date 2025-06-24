#include <vector>
#include <iostream>
#include <queue>

#define UNVISITED 0
#define VISITED 1

using namespace std;

/* QUESTÃO 1 -
Implemente um grafo não-dirigido e não-ponderado utilizando uma matriz de adjacências.

ENTRADA

A primeira linha da entrada contém os inteiros n (1 ≤ n ≤ 500) e q (1 ≤ q ≤ 105), a quantidade de 
vértices do grafo e o número de operações que devem ser realizadas sobre o grafo. Cada uma das 
próximas q linhas contém um comando que pode ser de três tipos:

add u v -- insira uma aresta entre os vértices u e v (0 ≤ u, v < n). Lembre que o grafo não é dirigido.

BSF v -- percorra o grafo em largura, iniciando a busca no vértice v (0 ≤ v < n). 
Dado um vértice arbitrário u, lembre de considerar os vértices alcançáveis a partir de u em ordem numérica crescente.

DFS v - percorra o grafo em profundidade, iniciando a busca no vértice v (0 ≤ v < n). 
Dado um vértice arbitrário u, lembre de considerar os vértices alcançáveis a partir de u em ordem numérica crescente.
*/

class Graph {
    private:
        vector<vector<int>> matrix;
        int numEdges;
        vector<int> mark;
    public:
        Graph(int n) {
            matrix = vector<vector<int>>(n, vector<int>(n, 0));
            numEdges = n;
            mark = vector<int>(n, UNVISITED);
        }

        int n() {
            return matrix.size();
        }
        int e() {
            return numEdges;
        }

        int first(int v) {
            for(int i = 0; i < n(); i++) {
                if(matrix[v][i] != 0) {
                    return i;
                }
            }
            return n();
        }

        int next(int v, int w) {
            for(int i = w+1; i < n(); i++) {
                if(matrix[v][i] != 0) {
                    return i;
                }
            }
            return n();
        }

        void setEdge(int i, int j, int wt) {
            if(wt == 0) { return; }
            if(matrix[i][j] == 0) { numEdges++; }
            matrix[i][j] = wt;
            matrix[j][i] = wt;
        }

        void delEdge(int i, int j) {
            if(matrix[i][j] != 0) { numEdges--; }
            matrix[i][j] = 0;
        }

        bool isEdge(int i, int j) {
            return matrix[i][j] != 0;
        }

        int weight(int i, int j) {
            return matrix[i][j];
        }

        void setMark(int v, int val) {
            mark[v] = val;
        }

        int getMark(int v) {
            return mark[v];
        }
};

void DFS(Graph& g, int v) {
    cout << v << " ";
    g.setMark(v, VISITED);
    int w = g.first(v);
    while(w < g.n()) {
        if(g.getMark(w) == UNVISITED) {
            DFS(g, w);
        }
        w = g.next(v, w);
    }
}

void BFS(Graph& g, int start) {
    queue<int> queue_visit;
    queue_visit.push(start);
    g.setMark(start, VISITED);
    while(queue_visit.size() > 0) {
        int v = queue_visit.front(); queue_visit.pop();
        cout << v << " ";
        int w = g.first(v);
        while(w < g.n()) {
            if(g.getMark(w) == UNVISITED) {
                g.setMark(w, VISITED);
                queue_visit.push(w);
            }
            w = g.next(v, w);
        }
    }
}

void DFSgraphTraverse(Graph& g, int v) {
    for(int i = 0; i < g.n(); i++) {
        g.setMark(i, UNVISITED);
    }
    for(int j = v; j < g.n(); j++) {
        if(g.getMark(j) == UNVISITED) {
            DFS(g, j);
        }
    }
}

void BFSgraphTraverse(Graph& g, int v) {
    for(int i = 0; i < g.n(); i++) {
        g.setMark(i, UNVISITED);
    }
    for(int j = v; j < g.n(); j++) {
        if(g.getMark(j) == UNVISITED) {
            BFS(g, j);
        }
    }
}

int main() {
    int qtd_n, q; cin >> qtd_n >> q;
    Graph graph(qtd_n);
    for(int i = 0; i < q; i++) {
        string command; cin >> command;
        if(command == "add") {
            int u, v; cin >> u >> v;
            graph.setEdge(u, v, 1);
        } else if(command == "DFS") {
            int v; cin >> v;
            DFSgraphTraverse(graph, v); cout << "\n";
        } else if(command == "BFS") {
            int v; cin >> v;
            BFSgraphTraverse(graph, v); cout << "\n";
        }
    }
    return 0;
}