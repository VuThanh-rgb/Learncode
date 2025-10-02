#include <iostream>
#include <vector>
#include <algorithm>   
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100; // Maximum number of vertices
int graph[MAX][MAX]; // Adjacency matrix representation of the graph    

struct Edge {
    int src, dest, weight;
    bool operator<(const Edge& e) const {
        return weight < e.weight;
    }
};

void inputEdge(int &n, vector<Edge> &edges, int graph[MAX][MAX])
{    
    ifstream inFile("data.txt");
    if (!inFile)
    {
        cout << "Unable to open file input.txt";
        exit(1); // terminate with error
    }
    // inFile >> n; // Read the number of vertices
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            inFile >> graph[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(graph[i][j] != 0 && i < j)  // To avoid adding two edges for undirected graph
            {
                edges.push_back({i, j, graph[i][j]}); // Add edge to the list
            }
        }
    }
    inFile.close();
    sort(edges.begin(), edges.end()); // Sort edges by weight
    // for(Edge x : edges)
    // {
    //     cout << "(" << x.src + 1 << ", " << x.dest + 1 << ") - " << x.weight << endl;
    // }
}

struct DSU
{
    int parent[v];
    int rank[v];
    void makeSet(int v)
    {
        for (int i = 0; i < v; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find (int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void unionSets(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
    
};
    
void kruskal(int n, vector<vector<pair<int, int>>> &adj, vector<Edge> &edges)
{
    // Tìm cây khung nhỏ nhất sử dụng thuật toán Kruskal
    // Sử dụng cấu trúc dữ liệu Union-Find để kiểm tra chu trình
    // Chèn các cạnh vào cây khung nhỏ nhất nếu không tạo thành chu trình
    vector<Edge> mst; // Minimum Spanning Tree
    while(mst.size() < n - 1 && !edges.empty()) 
    {
        Edge edge = edges.front();
        edges.erase(edges.begin());
        // Kiểm tra chu trình và thêm vào MST nếu không tạo thành chu trình

        // adj[edge.src].push_back(make_pair(edge.dest, edge.weight));
        // adj[edge.dest].push_back(make_pair(edge.src, edge.weight)); // vì đồ thị vô hướng
        mst.push_back(edge);
    }
    cout << "Cay khung nho nhat (Kruskal):" << endl;
    for (const auto& edge : mst) {
        cout << "(" << edge.src + 1 << ", " << edge.dest + 1 << ") - " << edge.weight << endl;
    }
}

int main()
{
    int n = 6;
    vector<vector<pair<int, int>>> adj(n); // Adjacency list representation of the MST
    vector<Edge> edges;
    inputEdge(n, edges, graph);
    // for (const auto& edge : edges) {
    // kruskal(n, adj, edges);
    return 0; // Exit successfully
}


