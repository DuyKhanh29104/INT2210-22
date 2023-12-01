#include <iostream>
using namespace std;

// Hàm tính số lượng đồ thị vô hướng
unsigned long long countGraphs(int V, int E) {
    int maxEdges = V * (V - 1) / 2;
    if (E > maxEdges) return 0;

    unsigned long long result = 1;
    for (int i = 0; i < E; ++i) {
        result *= (maxEdges - i);
        result /= (i + 1);
    }
    return result;
}

int main() {
    int V, E;
    cout << "Nhập số đỉnh (V): ";
    cin >> V;
    cout << "Nhập số cạnh (E): ";
    cin >> E;

    unsigned long long numberOfGraphs = countGraphs(V, E);
    cout << "Số lượng đồ thị vô hướng khác nhau có " << V << " đỉnh và " << E << " cạnh là: " << numberOfGraphs << endl;

    return 0;
}
