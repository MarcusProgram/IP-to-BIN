#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convertToBinary(int decimal) {
    string binary;
    if (decimal == 0) {
        binary = "00000000";
    } else {
        while (decimal > 0) {
            binary = to_string(decimal % 2) + binary;
            decimal /= 2;
        }
        while (binary.length() < 8) {
            binary = "0" + binary;
        }
    }
    return binary;
}

vector<string> splitIP(const string& ip) {
    vector<string> parts;
    string part;

    for (char c : ip) {
        if (c == '.') {
            parts.push_back(part);
            part.clear();
        } else {
            part += c;
        }
    }
    parts.push_back(part);

    return parts;
}

int main() {
    string ip;
    cout << "Введите IP: ";
    cin >> ip;
    vector<string> ipParts = splitIP(ip);
    for (size_t i = 0; i < ipParts.size(); ++i) {
        int decimal = stoi(ipParts[i]);
        string binary = convertToBinary(decimal);
        cout << binary;
        if (i != ipParts.size() - 1) {
            cout << ".";
        }
    }
  cout << endl;
  for (size_t i = 0; i < ipParts.size(); ++i) {
        int decimal = stoi(ipParts[i]);
        string binary = convertToBinary(decimal);
        cout << binary;
        if (i != ipParts.size() - 1) {
            cout << " ";
        }
    }
  cout << endl;
  for (size_t i = 0; i < ipParts.size(); ++i) {
        int decimal = stoi(ipParts[i]);
        string binary = convertToBinary(decimal);
        cout << binary;
    }
    cout << endl;
    return 0;
}
