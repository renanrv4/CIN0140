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
uma matriz de adjacências.
*/

// Graph Abstract Data Type (ADT)
class Graph {
    private:
        vector<vector<int>> matrix;
        int numEdge;
        vector<int> mark;

    public:
        Graph(int n) {
            matrix = vector<vector<int>>(n, vector<int>(n, 0));
            numEdge = 0;
            mark = vector<int>(n, 0);
        }

        // Retorna a quantidade de vértices
        int n(){
            return matrix.size();
        }

        // Cria uma conexão entre vértices
        int e(){
            return numEdge;
        }

        // Retorna o primeiro vértice que se conecta com o vértice v
        int first(int v) {
            for(int i = 0; i < n(); i++) {
                if(matrix[v][i] != 0) {
                    return i;
                }
            }
            return n();
        }

        // Retorna o próximo vértice que v se conecta após w
        int next(int v, int w) {
            for(int i = w + 1; i < n(); i++) {
                if(matrix[v][i] != 0) {
                    return i;
                }
            }
            return n();
        }

        // Cria uma conexão entre vértices
        void setEdge(int i, int j, int wt) {
            if(wt == 0) { cout << "Erro" << "\n"; return; }
            if(matrix[i][j] == 0) { numEdge++; }
            matrix[i][j] = wt;
        }

        // Remove uma conexão entre vértices
        void delEdge(int i, int j) {
            if(matrix[i][j] != 0) { numEdge--; }
            matrix[i][j] = 0;
        }

        // Checa se existe uma conexão entre vértices
        bool isEdge(int i, int j) {
            return matrix[i][j] != 0;
        }

        // O grafo que eu usei de exemplo não é ponderado, no caso de um grafo ponderado 
        // eu teria que usar um pair<int, int> para indicar o vértice e o peso da conexão
        int weight(int i, int j) {
            return matrix[i][j];
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
    int w = g.first(v);
    while(w < g.n()) {
        if(g.getMark(w) == UNVISITED) {
            DFS(g, w);
        }
        w = g.next(v, w);
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
        int w = g.first(v);
        while(w < g.n()) {
            if(g.getMark(w) == UNVISITED) {
                g.setMark(w, VISITED);
                Q.push(w);
            }
            w = g.next(v, w);
        }
    }
}

void graphTraverse(Graph& g) {
    for(int i = 0; i < g.n(); i++) {
        g.setMark(i, UNVISITED);
    }
    for(int j = 0; j < g.n(); j++) {
        if(g.getMark(j) == UNVISITED) {
            BFS(g, j);
            // DFS (g, j);
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