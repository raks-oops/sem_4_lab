#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int n, m;
vector<string> floorPlan;
vector<vector<bool>> visited;

// Possible directions: up, down, left, right
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (isValid(nx, ny) && !visited[nx][ny] && floorPlan[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    floorPlan.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        cin >> floorPlan[i];
    }

    int roomCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j] && floorPlan[i][j] == '.') {
                ++roomCount;
                dfs(i, j);
            }
        }
    }

    cout << roomCount << endl;
    return 0;
}
