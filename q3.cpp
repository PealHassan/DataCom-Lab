#include <iostream>
#include <string>
using namespace std;


string crcEncode(string& dataword, string& divisor) {
string codeword = dataword;
string temp = dataword;

    // Append zeros to the dataword
    for (int i = 0; i < divisor.length() - 1; i++)
        codeword += "0";


    // Perform modulo-2 division
    for (int i = 0; i <= codeword.length() - divisor.length();) {
        for (int j = 0; j < divisor.length(); j++) 
            codeword[i + j] = codeword[i + j] == divisor[j] ? '0' : '1';

        for (; i < codeword.length() && codeword[i] != '1'; i++);
    }


    for(int i=codeword.length()-divisor.length()+1; i<codeword.length(); i++)
        temp+= codeword[i];

    return temp;
}

bool crcCheck(string& receivedCodeword, string& divisor) {
string codeword = receivedCodeword;

    // Perform modulo-2 division
    for (int i = 0; i <= codeword.length() - divisor.length();) {
        for (int j = 0; j < divisor.length(); j++)
            codeword[i + j] = codeword[i + j] == divisor[j] ? '0' : '1';

        for (; i < codeword.length() && codeword[i] != '1'; i++);
    }

    // If remainder is zero, codeword is not corrupted
    for (char c : codeword)
        if (c == '1') return true;

    return false;
}

int main() {
string dataword = "110101";  // Example dataword
string divisor = "1011";     // Example divisor

string codeword = crcEncode(dataword, divisor);
cout << "CRC codeword: " << codeword <<endl;

    // Simulating corruption of codeword
    // codeword[2] = '1';

    bool isCorrupted = crcCheck(codeword, divisor);
cout << "Codeword is corrupted: " << (isCorrupted ? "Yes" : "No") <<endl;

    return 0;
}
