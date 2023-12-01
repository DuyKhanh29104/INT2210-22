#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *graph;

    void DFS(int v, vector<bool> &visited) const {
        visited[v] = true;
        for (int i : graph[v])
            if (!visited[i])
                DFS(i, visited);
    }

    bool isHamiltonCycleUtil(vector<int>& path, int pos) {
        if (pos == V) {
            if (find(graph[path[pos - 1]].begin(), graph[path[pos - 1]].end(), path[0]) != graph[path[pos - 1]].end())
                return true;
            else
                return false;
        }

        for (int v = 0; v < V; v++) {
            if (isSafe(v, path, pos)) {
                path[pos] = v;
                if (isHamiltonCycleUtil(path, pos + 1))
                    return true;
                path[pos] = -1;
            }
        }
        return false;
    }

    bool isSafe(int v, vector<int>& path, int pos) const {
        if (find(graph[path[pos - 1]].begin(), graph[path[pos - 1]].end(), v) == graph[path[pos - 1]].end())
            return false;

        for (int i = 0; i < pos; i++)
            if (path[i] == v)
                return false;

        return true;
    }

public:
    Graph(int V) : V(V) {
        graph = new list<int>[V];
    }

    ~Graph() {
        delete[] graph;
    }

    void addEdge(int v, int w) {
        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    bool isConnected() const {
        vector<bool> visited(V, false);
        int i;
        for (i = 0; i < V; i++)
            if (!graph[i].empty())
                break;
        if (i == V) return true;
        DFS(i, visited);
        for (i = 0; i < V; i++)
            if (!visited[i] && !graph[i].empty())
                return false;

        return true;
    }

    bool isEulerCycle() const {
        if (!isConnected()) return false;
        for (int i = 0; i < V; i++)
            if (graph[i].size() % 2 != 0)
                return false;
        return true;
    }

    bool isHamiltonCycle() {
        vector<int> path(V, -1);
        path[0] = 0;
        return isHamiltonCycleUtil(path, 1);
    }
};

int main() {
    int n;
    cout << "Nhập số lượng đồ thị: ";
    cin >> n;
    vector<bool> eulerResults(n), hamiltonResults(n);

    for (int i = 0; i < n; ++i) {
        int V, E;
        cout << "Nhập số đỉnh và số cạnh của đồ thị " << i + 1 << ": ";
        cin >> V >> E;
        Graph g(V);
        cout << "Nhập các cạnh: " << endl;
        for (int j = 0; j < E; ++j) {
            int u, v;
            cin >> u >> v;
            g.addEdge(u, v);
        }
        eulerResults[i] = g.isEulerCycle();
        hamiltonResults[i] = g.isHamiltonCycle();
    }

    cout << "Kết quả kiểm tra chu trình Euler và Hamilton."  << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Đồ thị " << i + 1 << ":" << endl;
        if(eulerResults[i])
            cout << "- Có chu trình Euler" << endl;
        else
            cout << "- Không có chu trình Euler" << endl;
        if(hamiltonResults[i])
            cout << "- Có chu trình Hamilton" << endl;
        else
            cout << "- Không có chu trình Hamilton" << endl;
    }

    return 0;
}
