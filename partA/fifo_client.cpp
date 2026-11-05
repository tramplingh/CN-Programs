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
 cout << "CLIENT online\nEnter the path of the file: ";
 cin >> p;
 fd1 = open("fifo1", O_WRONLY); // send file path to server
 write(fd1, p, strlen(p));
 close(fd1);
 fd2 = open("fifo2", O_RDONLY); // read reply
 cout << "File received! Displaying the contents:\n";
 while ((n = read(fd2, buf, sizeof buf)) > 0)
 cout.write(buf, n);
}
