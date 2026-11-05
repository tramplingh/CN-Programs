#include <bits/stdc++.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;
int main()
{
 int s = socket(AF_INET, SOCK_STREAM, 0), f, ack, expected = 1;
 sockaddr_in a{AF_INET, htons(8000)};
 inet_pton(AF_INET, "127.0.0.1", &a.sin_addr);
 connect(s, (sockaddr*)&a, sizeof a);
 cout << "CLIENT online\n";
 while (read(s, &f, sizeof f) > 0)
 {
 if (f == expected) // accept only the expected frame
 {
 cout << "Received frame " << f << "\n";
 expected++;
 }
 else // out of order: discard
 cout << "Discarded frame " << f << " (expected " << expected << ")\n";
 ack = expected - 1; // ACK = last in-order frame
 write(s, &ack, sizeof ack);
 cout << "Sent ACK " << ack << "\n";
 }
 close(s);
}
