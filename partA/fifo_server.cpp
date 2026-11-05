#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
using namespace std;
int main()
{
 char p[100], buf[100];
 int n, fd1, fd2;
 mkfifo("fifo1", 0666);
 mkfifo("fifo2", 0666);
 cout << "SERVER online, waiting for client request\n";
 fd1 = open("fifo1", O_RDONLY); // request pipe
 n = read(fd1, p, 99);
 p[n] = 0;
 FILE *fp = fopen(p, "r");
 fd2 = open("fifo2", O_WRONLY); // reply pipe
 cout << "Server: sending " << p << "\n";
 while ((n = fread(buf, 1, sizeof buf, fp)) > 0)
 write(fd2, buf, n);
 cout << "Server: transfer completed\n";
 unlink("fifo1");
 unlink("fifo2");
}
