#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
using namespace std;
int main(int argc, char *argv[]) {
 int s = socket(AF_INET, SOCK_STREAM, 0);
 sockaddr_in a{AF_INET, htons(atoi(argv[1])), INADDR_ANY};
 bind(s, (sockaddr*)&a, sizeof(a));
 listen(s, 1);
 cout << "SERVER online\n";
 int c = accept(s, 0, 0);
 char file[100], buf[1024] = {};
 recv(c, file, sizeof(file), 0);
 cout << "Transfer the contents of " << file << "...\n";
 ifstream f(file);
 if (!f) {
 send(c, "File not found", 14, 0);
 } else {
 string x((istreambuf_iterator<char>(f)), {});
 send(c, x.c_str(), x.size(), 0);
 cout << "SERVER: Sending the contents...\n";
 }
 close(c);
 close(s);
}
