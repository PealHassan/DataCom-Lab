#include<bits/stdc++.h>
#define ll long long int  
using namespace std;  
pair<string,ll> generate(string dataword) {
    ll cnt = 0;  
    for(ll i = 0; i < dataword.size(); i++) {
        if(dataword[i] == '1') cnt++;  
    }
    ll parity = 0;   
    if(cnt%2) {
        dataword += "1";
        parity = 1;  
    }
    else dataword += "0";
    return {dataword,parity};  
}
bool checker(string codeword) {
    ll cnt = 0;   
    for(ll i = 0; i < codeword.size(); i++) {
        if(codeword[i] == '1') cnt++;  
    }
    if(cnt%2) return false;  
    return true;  
}
int main() {
    string dataword, getcodeword;  
    cin >> dataword >> getcodeword;   
    pair<string,ll> codeword = generate(dataword);
    cout << "#Generator" << endl;  
    cout << "Codeword : " << codeword.first << endl;  
    cout << "Parity Added : " << codeword.second << endl;
    cout << endl << endl << endl;  
    cout << "#Checker" << endl;
    if(checker(getcodeword)) cout << "Codeword is valid" << endl;  
    else cout << "Codeword is corrupted" << endl;  

}