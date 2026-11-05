#include <iostream>
using namespace std;
int main() {
 int n, cost[10][10], d[10][10], next[10][10];
 cout << "Enter the no of vertices: ";
 cin >> n;
 cout << "Enter the cost matrix\n";
 for (int i = 0; i < n; i++)
 for (int j = 0; j < n; j++)
 cin >> cost[i][j];
 // Initial distance vector
 for (int i = 0; i < n; i++)
 for (int j = 0; j < n; j++) {
 d[i][j] = cost[i][j];
 if (i != j && cost[i][j] != 99)
 next[i][j] = j;
 else
 next[i][j] = -1;
 }
 // Distance Vector algorithm
 for (int k = 0; k < n; k++)
 for (int i = 0; i < n; i++)
 for (int j = 0; j < n; j++)
 if (d[i][k] != 99 && d[k][j] != 99 &&
 d[i][k] + d[k][j] < d[i][j]) {
 d[i][j] = d[i][k] + d[k][j];
 next[i][j] = next[i][k];
 }
 // Display routing tables
 for (int i = 0; i < n; i++) {
 cout << "\nState value for router " << char('A' + i) << "\n";
 cout << "dest\tnextnode\tdistance\n";
 for (int j = 0; j < n; j++) {
 cout << char('A' + j) << "\t";
 if (i == j)
 cout << char('A' + j) << "\t\t0\n";
 else
 cout << char('A' + next[i][j]) << "\t\t"
 << d[i][j] << "\n";
 }
 }
 return 0;
}
