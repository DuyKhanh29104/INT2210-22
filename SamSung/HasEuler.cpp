#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph {
    int V;
    vector<unordered_map<int, int>> adj;

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        for (auto& neighbor : adj[v])
            if (!visited[neighbor.first])
                DFS(neighbor.first, visited);
    }

    bool isConnected() {
        vector<bool> visited(V, false);
        int i;
        for (i = 0; i < V; i++)
            if (!adj[i].empty())
                break;

        if (i == V)
            return true;

        DFS(i, visited);

        for (i = 0; i < V; i++)
            if (!visited[i] && !adj[i].empty())
                return false;

        return true;
    }

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int v, int w) {
        adj[v][w]++;
        adj[w][v]++;
    }

    bool isEulerianCycle() {
        if (!isConnected())
            return false;

        for (int i = 0; i < V; i++)
            if (adj[i].size() % 2 != 0)
                return false;

        return true;
    }
};

int main() {
    int V, E;
    cout << "Nhập số lượng đỉnh (V): ";
    cin >> V;

    Graph g(V);

    cout << "Nhập số lượng cạnh (E): ";
    cin >> E;

    cout << "Nhập cạnh (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.isEulerianCycle())
        cout << "Đồ thị có chu trình Euler." << endl;
    else
        cout << "Đồ thị không có chu trình Euler." << endl;

    return 0;
}
