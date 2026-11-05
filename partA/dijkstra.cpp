#include <iostream>
using namespace std;
int main() {
 int n, src;
 cout << "Enter the number of vertices\n";
 cin >> n;
 int cost[10][10], dist[10], vis[10] = {}, par[10];
 cout << "Enter the cost adjacency matrix\n";
 for (int i = 0; i < n; i++)
 for (int j = 0; j < n; j++)
 cin >> cost[i][j];
 cout << "enter the source\n";
 cin >> src;
 for (int i = 0; i < n; i++) {
 dist[i] = cost[src][i];
 par[i] = src;
 }
 dist[src] = 0;
 par[src] = -1;
 for (int k = 0; k < n - 1; k++) {
 int u = -1, mn = 9999;
 for (int i = 0; i < n; i++)
 if (!vis[i] && dist[i] < mn)
 mn = dist[i], u = i;
 if (u == -1) break;
 vis[u] = 1;
 for (int v = 0; v < n; v++)
 if (!vis[v] && cost[u][v] != 99 &&
 dist[u] + cost[u][v] < dist[v])
 dist[v] = dist[u] + cost[u][v], par[v] = u;
 }
 for (int v = 0; v < n; v++) {
 if (v == src) continue;
 cout << "The shortest path from " << src << " to " << v << " is\n";
 int path[10], k = 0, x = v;
 while (x != -1) {
 path[k++] = x;
 x = par[x];
 }
 for (int i = 0; i < k; i++) {
 cout << path[i];
 if (i < k - 1) cout << "<-";
 }
 cout << "\nand the distance is " << dist[v] << "\n";
 }
 return 0;
}
