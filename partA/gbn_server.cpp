#include <bits/stdc++.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;
int main()
{
 int s = socket(AF_INET, SOCK_STREAM, 0), c, n, w, lost, base = 1, ack = 0;
 bool done = 0;
 sockaddr_in a{AF_INET, htons(8000), INADDR_ANY};
 bind(s, (sockaddr*)&a, sizeof a);
 listen(s, 5);
 cout << "SERVER online, waiting for client...\n";
 c = accept(s, 0, 0);
 cout << "Enter number of frames: "; cin >> n;
 cout << "Enter window size: "; cin >> w;
 cout << "Enter frame to lose (-1 for none): "; cin >> lost;
 while (base <= n)
 {
 int end = min(base + w - 1, n), sent = 0;
 cout << "\nWindow: " << base << " to " << end << "\n";
 for (int i = base; i <= end; i++)
 {
 if (i == lost && !done) // lose this frame only once
 {
 cout << "Frame " << i << " LOST\n";
 done = 1;
 continue;
 }
 write(c, &i, sizeof i);
 cout << "Sent frame " << i << "\n";
 sent++;
 }
 while (sent--) // one ACK per frame sent
 {
 read(c, &ack, sizeof ack);
 cout << "Received ACK " << ack << "\n";
 }
 if (ack < end)
 cout << "Go-Back-N: resending from frame " << ack + 1 << "\n";
 base = ack + 1; // slide window after last in-order frame
 }
 cout << "\nAll frames sent\n";
}
