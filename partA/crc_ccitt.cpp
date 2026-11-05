#include <iostream>
#include <string>
using namespace std;
string divide(string s) {
 string p = "10001000000100001"; // CRC-CCITT
 for (int i = 0; i <= (int)s.length() - 17; i++)
 if (s[i] == '1')
 for (int j = 0; j < 17; j++)
 s[i+j] = (s[i+j] == p[j]) ? '0' : '1';
 return s.substr(s.length() - 16);
}
int main() {
 string data, frame, crc;
 cout << "AT SOURCE NODE\n\n";
 cout << "Enter the data to be sent: ";
 cin >> data;
 frame = data + "0000000000000000";
 crc = divide(frame);
 cout << "\nCRC is " << crc << "\n";
 cout << "\nData is: " << data << "\n";
 frame = data + crc;
 cout << "\nThe frame transmitted is: " << frame << "\n";
 cout << "\nSOURCE NODE TRANSMITTED THE FRAME ---->\n\n";
 cout << "AT DESTINATION NODE\n";
 cout << "\nEnter the received frame: ";
 cin >> frame;
 crc = divide(frame);
 cout << "\nCRC is " << crc << "\n";
 if (crc == "0000000000000000")
 cout << "\nReceived frame is error free\n";
 else
 cout << "\nReceived frame contains error\n";
 return 0;
}
