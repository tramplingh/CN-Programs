#include <iostream>
using namespace std;
int main()
{
 int cap, rate, n, pk, store = 0, out;
 cout << "Enter bucket capacity, output rate and number of packets: ";
 cin >> cap >> rate >> n;
 for (int i = 1; i <= n; i++)
 {
 cout << "\nTime " << i << ": enter incoming packet size: ";
 cin >> pk;
 if (pk > cap - store) // not enough space: overflow
 cout << "Bucket overflow, packet of " << pk << " bytes dropped\n";
 else
 store += pk;
 out = min(store, rate); // leak at constant rate
 store -= out;
 cout << "Sent " << out << " bytes, remaining in bucket: " << store << "\n";
 }
 for (int t = n + 1; store > 0; t++) // drain what is left
 {
 out = min(store, rate);
 store -= out;
 cout << "\nTime " << t << ": sent " << out << " bytes, remaining in bucket: " << store << "\n";
 }
}
