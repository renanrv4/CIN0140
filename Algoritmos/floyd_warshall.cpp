#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floydWarshall(vector<vector<int>>& graph) {
    vector<vector<int>> distances(graph.size(), vector<int>(graph.size(), INT_MAX));
    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph.size(); j++) {
            if(i == j) { distances[i][j] = 0; }
            else if (graph[i][j] != 0) { distances[i][j] = graph[i][j]; }
            else { distances[i][j] = INT_MAX; }
        }
    }

    for(int k = 0; k < graph.size(); k++) {
        for(int ii = 0; ii < graph.size(); ii++) {
            for(int jj = 0; jj < graph.size(); jj++) {
                if(distances[ii][k] != INT_MAX 
                   && distances[k][jj] != INT_MAX 
                   && distances[ii][jj] > distances[ii][k] + distances[k][jj]) {
                    distances[ii][jj] = distances[ii][k] + distances[k][jj];
                }
            }
        }
    }

    cout << "Matriz de distâncias mínimas:\n";
    for (int iii = 0; iii < graph.size(); iii++) {
        for (int jjj = 0; jjj < graph.size(); jjj++) {
            if (distances[iii][jjj] == INT_MAX)
                cout << "NNN ";
            else
                cout << distances[iii][jjj] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> G = {
        {0, 4, 0, 5, 0},
        {0, 0, 1, 0, 6},
        {2, 0, 0, 3, 0},
        {0, 0, 1, 0, 2},
        {1, 0, 0, 4, 0}
    };

    floydWarshall(G);
    return 0;
}