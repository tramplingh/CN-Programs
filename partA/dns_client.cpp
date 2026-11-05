#include <bits/stdc++.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;
int main()
{
 int s = socket(AF_INET, SOCK_DGRAM, 0);
 sockaddr_in a{AF_INET, htons(5300)};
 inet_pton(AF_INET, "127.0.0.1", &a.sin_addr);
 string q;
 char r[256];
 cout << "DNS CLIENT\nEnter domain name: ";
 cin >> q;
 sendto(s, q.c_str(), q.size(), 0, (sockaddr*)&a, sizeof a);
 int n = recvfrom(s, r, 255, 0, 0, 0);
 r[n] = 0;
 cout << "IP address: " << r << "\n";
}
