#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
  int vertices;
  bool directed;
  vector<vector<int>> graph;

public:
  Graph(int vertices, bool directed = false) {
    this->vertices = vertices;
    this->directed = directed;
    graph = vector<vector<int>>(vertices, vector<int>(vertices, 0));
  }

  void addEdge(int u, int v) {
    graph[u][v] = 1;
    if (!directed) {
      graph[v][u] = 1;
    }
  }

  void bfs(int source) {
    vector<bool> visited(vertices, false);
    queue<int> q;

    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      cout << "Visiting vertex: " << current << endl;

      for (int neighbor : adjacentVertices(current)) {
        if (!visited[neighbor]) {
          q.push(neighbor);
          visited[neighbor] = true;
        }
      }
    }
  }

private:
  vector<int> adjacentVertices(int vertex) {
    vector<int> adjacentVertices;
    for (int i = 0; i < vertices; i++) {
      if (graph[vertex][i] == 1) {
        adjacentVertices.push_back(i);
      }
    }
    return adjacentVertices;
  }
};

int main() {
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 4);

  g.bfs(0);

  return 0;
}
