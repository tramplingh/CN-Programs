#include <bits/stdc++.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;
int main()
{
 int s = socket(AF_INET, SOCK_STREAM, 0), f;
 sockaddr_in a{AF_INET, htons(8000)};
 inet_pton(AF_INET, "127.0.0.1", &a.sin_addr);
 connect(s, (sockaddr*)&a, sizeof a);
 cout << "CLIENT online\n";
 while (read(s, &f, sizeof f) > 0) // accept every frame, ACK it individually
 {
 cout << "Received frame " << f << "\n";
 write(s, &f, sizeof f);
 cout << "Sent ACK " << f << "\n";
 }
 close(s);
}
