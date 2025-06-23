#include <iostream>
#include <vector>
#include <queue>

#define UNVISITED 0
#define VISITED 1

using namespace std;

/* 
Implementando o tipo abstrato de 
dados para representar um grafo e 
seus métodos de travessia usando 
uma lista de adjacências.
*/

// Graph Abstract Data Type (ADT)
class Graph {
    private:
        vector<vector<int>> adj_list;
        int numEdge;
        vector<int> mark;

    public:
        Graph(int n) {
            adj_list = vector<vector<int>>(n); // Não preenche com zeros, diferentemente da matriz de adjacências
            numEdge = 0;
            mark = vector<int>(n, 0);
        }

        // Retorna a quantidade de vértices
        int n(){
            return adj_list.size();
        }

        // Retorna a quantidade de conexões entre vértices
        int e(){
            return numEdge;
        }

        // Retorna o vetor com as adjacências de um vértice
        vector<int>& getConnections(int v) {
            return adj_list[v];
        }

        // Cria uma conexão entre vértices
        void setEdge(int i, int j, int wt) {
            adj_list[i].push_back(j);
            numEdge++;
        }

        // Remove uma conexão entre vértices
        void delEdge(int i, int j) {
            for (auto it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
                if (*it == j) {
                    adj_list[i].erase(it);
                    numEdge--;
                    break;
                }
            }
        }

        // Checa se existe uma conexão entre vértices
        bool isEdge(int i, int j) {
            for(int w : adj_list[i]) {
                if(w == j) {
                    return true;
                }
            }
            return false;
        }

        // O grafo que eu usei de exemplo não é ponderado, no caso de um grafo ponderado 
        // eu teria que usar um pair<int, int> para indicar o vértice e o peso da conexão
        int weight(int i, int j) {
            return isEdge(i, j) ? 1 : 0;
        }

        // Set e get mark verificam e alteram o estado de visitação de cada vértice
        void setMark(int v, int val) {
            mark[v] = val;
        }

        int getMark(int v) {
            return mark[v];
        }
};

// TRAVESSIA DE UM GRAFO EM PROFUNDIDADE
void DFS(Graph& g, int v) {
    cout << "Visitando: " << v << endl;
    g.setMark(v, VISITED);
    for(int w : g.getConnections(v)) {
        if(g.getMark(w) == UNVISITED) {
            DFS(g, w);
        }
    }
}

// TRAVESSIA DE UM GRAFO EM LARGURA
void BFS(Graph& g, int start) {
    queue<int> Q;
    Q.push(start);
    g.setMark(start, VISITED);
    while(Q.size() > 0) {
        int v = Q.front(); Q.pop();
        cout << "Visitando: " << v << endl;
        for(int w : g.getConnections(v)) {
            if(g.getMark(w) == UNVISITED) {
                g.setMark(w, VISITED);
                Q.push(w);
            }
        }
    }
}

void graphTraverse(Graph& g) {
    for(int i = 0; i < g.n(); i++) {
        g.setMark(i, UNVISITED);
    }
    for(int j = 0; j < g.n(); j++) {
        if(g.getMark(j) == UNVISITED) {
            // BFS(g, j);
            DFS (g, j);
        }
    }
}

int main() {
    Graph g(6);

    g.setEdge(0, 2, 1); g.setEdge(2, 0, 1);
    g.setEdge(0, 4, 1); g.setEdge(4, 0, 1);
    g.setEdge(1, 2, 1); g.setEdge(2, 1, 1);
    g.setEdge(1, 5, 1); g.setEdge(5, 1, 1);
    g.setEdge(2, 3, 1); g.setEdge(3, 2, 1);
    g.setEdge(2, 5, 1); g.setEdge(5, 2, 1);
    g.setEdge(3, 5, 1); g.setEdge(5, 3, 1);
    g.setEdge(4, 5, 1); g.setEdge(5, 4, 1);

    graphTraverse(g);
    return 0;
}