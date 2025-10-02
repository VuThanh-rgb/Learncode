#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
using namespace std;

const int MAX = 100; // Maximum number of vertices
int graph[MAX][MAX]; // Adjacency matrix representation of the graph

void inputEdge(int &n){
    ifstream inFile("data.txt");
    if (!inFile) {
        cout << "Unable to open file data.txt";
        exit(1); // terminate with error
    }
    inFile >> n; // Read the number of vertices
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            inFile >> graph[i][j];
        }
    }
    inFile.close();
}

void prim(int n, vector<vector<pair<int, int>>> &adj){
    vector<bool> check(n, false);
    check[0] = true; // Start from the first vertex (0)
    int edges = 0;

    while (edges < n - 1) {
        int minWeight = INT_MAX;
        int x = -1, y = -1;

        // tìm cạnh nhỏ nhất nối từ tập đã chọn sang tập chưa chọn
        for(int i = 0; i < n; i++){
            if(check[i]){
                for(int j = 0; j < n; j++){
                    if(!check[j] && graph[i][j] != 0){
                        if(graph[i][j] < minWeight){
                            minWeight = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        if (x != -1 && y != -1) {
            adj[x].push_back(make_pair(y, minWeight));
            adj[y].push_back(make_pair(x, minWeight)); // vì đồ thị vô hướng
            check[y] = true;
            edges++;
            cout << "Chon canh (" << x << ", " << y << ") voi trong so " << minWeight << endl;
        } else {
            break; // đồ thị không liên thông
        }
    }
}

int main() {
    int n;
    inputEdge(n);

    vector<vector<pair<int, int>>> adj(n);
    prim(n, adj);

    cout << "\nAdjacency List of MST:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (const auto& neighbor : adj[i]) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
    return 0;
}
