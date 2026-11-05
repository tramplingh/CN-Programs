#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;
int main(int argc, char *argv[]) {
 int s = socket(AF_INET, SOCK_STREAM, 0);
 sockaddr_in a{AF_INET, htons(atoi(argv[2]))};
 inet_pton(AF_INET, argv[1], &a.sin_addr);
 connect(s, (sockaddr*)&a, sizeof(a));
 cout << "CLIENT online\n";
 char file[100], buf[1024] = {};
 cout << "Enter path with filename: ";
 cin >> file;
 send(s, file, strlen(file) + 1, 0);
 int n = recv(s, buf, sizeof(buf) - 1, 0);
 buf[n] = '\0';
 cout << "CLIENT: displaying from socket\n";
 cout << buf << endl;
 close(s);
}
