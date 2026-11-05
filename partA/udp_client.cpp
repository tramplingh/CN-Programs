#include <bits/stdc++.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;
int main()
{
 int s = socket(AF_INET, SOCK_DGRAM, 0);
 sockaddr_in a{AF_INET, htons(8080)};
 char buf[1024], ack[10], name[100];
 socklen_t len = sizeof a;
 inet_pton(AF_INET, "127.0.0.1", &a.sin_addr);
 cout << "CLIENT online\nEnter filename: ";
 cin.getline(name, 100);
 ifstream file(name, ios::binary);
 sendto(s, name, strlen(name), 0, (sockaddr*)&a, len);
 cout << "Sending file...\n";
 while (file.read(buf, sizeof buf) || file.gcount())
 {
 sendto(s, buf, file.gcount(), 0, (sockaddr*)&a, len);
 recvfrom(s, ack, sizeof ack, 0, (sockaddr*)&a, &len); // wait for ACK
 cout << "ACK received\n";
 }
 sendto(s, "END", 3, 0, (sockaddr*)&a, len);
 cout << "File sent successfully\n";
}
