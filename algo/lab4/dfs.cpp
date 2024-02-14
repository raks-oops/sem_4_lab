#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int numNodes;
    vector<vector<int>> adjList;

public:
    Graph(int n) : numNodes(n), adjList(n) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(int startNode) {
        vector<bool> visited(numNodes, false);
        stack<int> nodeStack;

        visited[startNode] = true;
        nodeStack.push(startNode);

        while (!nodeStack.empty()) {
            int currentNode = nodeStack.top();
            nodeStack.pop();

            cout << currentNode << " ";

            for (int neighbor : adjList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    nodeStack.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(10);

    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(1, 9);
    g.addEdge(2, 5);
    g.addEdge(7, 4);
    g.addEdge(9, 3);
    g.addEdge(9, 4);
    g.addEdge(9, 8);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(5, 6);

    cout << "DFS traversal starting from node 9: ";
    g.dfs(9);

    return 0;
}