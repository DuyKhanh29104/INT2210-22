#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Edge {
    int u;
    int v;

    Edge(int u, int v) : u(u), v(v) {}

    bool operator==(const Edge& other) const {
        return (u == other.u && v == other.v) || (u == other.v && v == other.u);
    }
};

struct EdgeHash {
    size_t operator()(const Edge& edge) const {
        return hash<int>()(edge.u) ^ hash<int>()(edge.v);
    }
};

int countParallelEdges(vector<Edge>& edges) {
    unordered_map<Edge, int, EdgeHash> edgeCount;
    for (auto& edge : edges) {
        edgeCount[edge]++;
    }

    int parallelEdges = 0;
    for (auto& count : edgeCount) {
        if (count.second > 1)
            parallelEdges += count.second - 1;
    }
    return parallelEdges;
}

int main() {
    int n;
    cout << "Nhập số lượng cạnh: ";
    cin >> n;

    vector<Edge> edges;
    cout << "Nhập cạnh (u v):" << endl;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    int parallelEdgeCount = countParallelEdges(edges);
    cout << "Số cạnh song song trong đồ thị: " << parallelEdgeCount << endl;
    return 0;
}
