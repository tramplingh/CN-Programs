#include <iostream>
using namespace std;
int main() {
 int h[22] = {}, data[17], r = 5, n = 21;
 cout << "Enter 16 data bits: ";
 for (int i = 1, j = 1; i <= n; i++) {
 if ((i & (i - 1)) == 0)
 continue;
 cin >> h[i];
 }
 // Generate parity bits
 for (int p = 1; p <= n; p <<= 1) {
 int x = 0;
 for (int i = 1; i <= n; i++)
 if (i & p) x ^= h[i];
 h[p] = x;
 }
 cout << "Transmitted code: ";
 for (int i = 1; i <= n; i++)
 cout << h[i];

 char ch;
 cout << "\nDo you want to introduce an error? (y/n): ";
 cin >> ch;
 if (ch == 'y') {
 int pos;
 cout << "Enter error position (1-21): ";
 cin >> pos;
 h[pos] ^= 1;
 }
 // Find error position
 int error = 0;
 for (int p = 1; p <= n; p <<= 1) {
 int x = 0;
 for (int i = 1; i <= n; i++)
 if (i & p) x ^= h[i];
 if (x) error += p;
 }
 cout << "Codeword with error: ";
 for (int i = 1; i <= n; i++) cout << h[i];
 if (error) {
 cout << "\nError at position " << error << ", correcting...\n";
 h[error] ^= 1;
 } else
 cout << "\nNo error detected\n";
 cout << "Corrected codeword: ";
 for (int i = 1; i <= n; i++)
 cout << h[i];
 return 0;
}
