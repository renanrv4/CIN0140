#include <bits/stdc++.h>

using namespace std;

// Usando BFS para encontrar um possível caminho mínimo até um objetivo e traçando o caminho percorrido

vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

bool isInBounds(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

bool isGuard(char c) {
    return c == '>' || c == '<' || c == '^' || c == 'v';
}

void BFS(vector<vector<char>>& grid, vector<vector<bool>>& watched, vector<vector<bool>>& visited, vector<vector<pair<int, int>>>& parent, int n, int m) {
    visited.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));
    
    queue<pair<int, int>> q;
    if (grid[0][0] != '.' || watched[0][0]) { return; }

    visited[0][0] = true;
    q.push({0, 0});
    
    while(!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();
        int x = curr.first;
        int y = curr.second;
        for (int d = 0; d < 4; d++) {
            int nx = x + dirs[d].first;
            int ny = y + dirs[d].second;
            if (isInBounds(nx, ny, n, m)) {
                if (!visited[nx][ny] && grid[nx][ny] == '.' && !watched[nx][ny]) {
                    visited[nx][ny] = true;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }
}

void reconstructPath(vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<vector<pair<int, int>>>& parent, int n, int m) {
    int x = n - 1;
    int y = m - 1;
    if (!visited[x][y]) {
        cout << -1 << '\n';
        return;
    }

    while (!(x == 0 && y == 0)) {
        grid[x][y] = 'X';
        pair<int, int> p = parent[x][y];
        x = p.first;
        y = p.second;
    }
    grid[0][0] = 'X';

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> grid;
    vector<vector<bool>> watched, visited;
    vector<vector<pair<int, int>>> parent;
    grid.resize(n, vector<char>(m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    watched.assign(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c = grid[i][j];
            if (!isGuard(c)) { continue; }
            watched[i][j] = true;

            int dx = 0, dy = 0;
            if(c == '>') { dy = 1; }
            if(c == '<') { dy = -1; }
            if(c == '^') { dx = -1; }
            if(c == 'v') { dx = 1; }

            int x = i + dx;
            int y = j + dy;
            while (isInBounds(x, y, n, m) && grid[x][y] == '.') {
                watched[x][y] = true;
                x += dx;
                y += dy;
            }
        }
    }

    BFS(grid, watched, visited, parent, n, m);
    reconstructPath(grid, visited, parent, n, m);
    return 0;
}