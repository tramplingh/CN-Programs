#include <bits/stdc++.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;
int main()
{
 int s = socket(AF_INET, SOCK_DGRAM, 0), n;
 sockaddr_in a{AF_INET, htons(8080), INADDR_ANY};
 char buf[1024];
 socklen_t len = sizeof a;
 bind(s, (sockaddr*)&a, sizeof a);
 cout << "SERVER online\n";
 n = recvfrom(s, buf, 100, 0, (sockaddr*)&a, &len); // file name
 buf[n] = 0;
 ofstream file(buf, ios::binary);
 cout << "Receiving file: " << buf << "\nContents:\n";
 while ((n = recvfrom(s, buf, sizeof buf, 0, (sockaddr*)&a, &len)) > 0)
 {
 if (n == 3 && !strncmp(buf, "END", 3)) break;
 file.write(buf, n);
 cout.write(buf, n);
 sendto(s, "ACK", 3, 0, (sockaddr*)&a, len);
 }
 cout << "\nFile received successfully\n";
 close(s);
}
