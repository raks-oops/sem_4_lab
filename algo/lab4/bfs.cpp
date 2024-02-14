#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

const int MAX_NODES = 9;

void bfs(const int graph[MAX_NODES][MAX_NODES], int start, int nodes) {
    queue<int> q;
    unordered_set<int> visited(nodes);

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << ' ';

        for (int i = 0; i < nodes; ++i) {
            int neighbor = graph[node][i];
            if (neighbor != 0 && visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

int main() {
    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    int graph[MAX_NODES][MAX_NODES] = {};

    for (int i = 0; i < nodes; ++i) {
        int neighbors;
        cout << "Enter the number of neighbors for node " << i + 1 << ": ";
        cin >> neighbors;

        cout << "Enter the neighbors for node " << i + 1 << ": ";
        for (int j = 0; j < neighbors; ++j) {
            int neighbor;
            cin >> neighbor;
            graph[i][j] = neighbor;
        }
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "BFS starting from node " << startNode << ": ";
    bfs(graph, startNode, nodes);

    return 0;
}
