#include <iostream>
#include <vector>
#include <algorithm>   
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100; // Maximum number of vertices
// int graph[MAX][MAX]; // Adjacency matrix representation of the graph

// void inputEdge(int &n)
// {
//     ifstream inFile("data.txt");
//     if (!inFile) 
//     {
//         cout << "Unable to open file input.txt";
//         exit(1); // terminate with error
//     }
//     // inFile >> n; // Read the number of vertices
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < n; j++)
//         {
//             inFile >> graph[i][j];
//         }
//     }
//     inFile.close();
// }

void prim(vector<bool> &check, int n, vector<vector<pair<int, int>>> &adj, int graph[6][6]){
    check[0] = true; // Start from the first vertex (0)
    int edges = 0, x, y, totalWeight = 0;
    while (edges < n - 1) 
    {
        x = -1; y = -1;
        int edMin = 100;
        for(int i = 0; i < n; i++)
        {
            // cout << "Lan lap thu " << i << endl;
            if(check[i]){
                for(int j = 0; j < n; j++){
                    if(!check[j] && graph[i][j] != 0){
                        if(graph[i][j] < edMin){
                            edMin = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        if (x != -1 && y != -1) {
                totalWeight += graph[x][y];
                adj[x].push_back(make_pair(y, graph[x][y]));
                adj[y].push_back(make_pair(x, graph[x][y])); // đồ thị vô hướng
                check[y] = true;
                edges++;
            } 
            else {
                break; // đồ thị không liên thông
            }
    }
    cout << "Tong trong so: " << totalWeight << endl;
}

int main() 
{
    int n = 6; // Set the number of vertices
    // inputEdge(n);
    int graph[6][6] = {
    {0, 33, 11, 0, 0, 0},
    {33, 0, 18, 20, 0, 0},
    {11, 18, 0, 16, 4, 0},
    {0, 20, 16, 0, 9, 8},
    {0, 0, 4, 9, 0, 14},
    {0, 0, 0, 8, 14, 0}
    };

    vector<bool> check(n, false);
    vector<vector<pair<int, int>>> adj(n);
    prim(check, n, adj, graph);

    // Print the adjacency list
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << i + 1 << ": ";
        for (const auto& neighbor : adj[i]) {
            cout << "(" << neighbor.first + 1 << ";  " << neighbor.second << ") ";
        }
        cout << endl;
}
// cout << "Do dai cay khung nho nhat: " << endl;
//     int totalWeight = 0;
//     for (int i = 0; i < 6; i++) {
//         for (const auto& neighbor : adj[i]) {
//             totalWeight += neighbor.second;
//         }
//     }
//     cout << "Tong trong so: " << totalWeight << endl;
    return 0; // Exit successfully
}