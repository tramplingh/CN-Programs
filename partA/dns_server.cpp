#include <bits/stdc++.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;
int main()
{
 // DNS resource-record table: domain name -> IP address
 map<string, string> t = {
 {"localhost", "127.0.0.1"},
 {"www.example.com", "93.184.216.34"},
 {"dns.google", "8.8.8.8"},
 {"one.one.one.one", "1.1.1.1"},
 {"mail.test.local", "192.168.1.10"}};
 int s = socket(AF_INET, SOCK_DGRAM, 0);
 sockaddr_in a{AF_INET, htons(5300), INADDR_ANY}, c;
 socklen_t l = sizeof c;
 char q[256];
 bind(s, (sockaddr*)&a, sizeof a);
 cout << "DNS SERVER online\n";
 while (1)
 {
 int n = recvfrom(s, q, 255, 0, (sockaddr*)&c, &l);
 q[n] = 0;
 string r = t[q]; // look up the name
 cout << "Query: " << q << " -> " << r << "\n";
 sendto(s, r.c_str(), r.size(), 0, (sockaddr*)&c, l);
 }
}
