#include <vector>
#include <iostream>

using namespace std;

bool escaped = false;

void move(vector<vector<char>>& maze, int n, int m, int i, int j, vector<vector<vector<vector<bool>>>>& visited, bool found, int qtd_traps) {
    if(qtd_traps < 0) { return; }
    if(visited[i][j][qtd_traps][found]) { return; }
    visited[i][j][qtd_traps][found] = true;

    if(maze[i][j] == 's') { qtd_traps--; }
    if(maze[i][j] == 'x') { found = true; }
    if(found && maze[i][j] == '@') {
        escaped = true;
        return;
    }

    if(i+1 < n && !escaped && maze[i+1][j] != '#') {
        move(maze, n, m, i+1, j, visited, found, qtd_traps);
    }
    if(i-1 >= 0 && !escaped && maze[i-1][j] != '#') {
        move(maze, n, m, i-1, j, visited, found, qtd_traps);
    }
    if(j+1 < m && !escaped && maze[i][j+1] != '#') {
        move(maze, n, m, i, j+1, visited, found, qtd_traps);
    }
    if(j-1 >= 0 && !escaped && maze[i][j-1] != '#') {
        move(maze, n, m, i, j-1, visited, found, qtd_traps);
    }

}

void explore_maze(vector<vector<char>>& maze, int n, int m, int qtd_traps) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maze[i][j] == '@') {
                vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(qtd_traps + 1, vector<bool>(2, false))));
                move(maze, n, m, i, j, visited, false, qtd_traps);
                if(escaped) { return; }
            }
        }
    }    
}

int main() {
    int n, m, j; cin >> n >> m >> j;
    vector<vector<char>> maze(n, vector<char>(m, '.'));
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < m; k++) {
            cin >> maze[i][k];
        }
    }
    explore_maze(maze, n, m, j);
    if(escaped) { cout << "SUCCESS" << "\n"; }
    else { cout << "IMPOSSIBLE" << "\n"; }

    return 0;
}