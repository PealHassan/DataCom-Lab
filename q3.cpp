#include<bits/stdc++.h>
#define ll long long int 
using namespace std;  
string CRC(string dataword, string divisor, ll mode) {
    string temp = dataword;
    if(mode) for(ll i = 0; i < divisor.size()-1; i++)  dataword += "0";
    ll start = 0;
    ll n = divisor.size();     
    while(start + n <= dataword.size()) {
        ll flag = start+n;   
        for(ll i = start, j = 0; j < n; j++,i++) {
            if(dataword[i] == divisor[j]) dataword[i] = '0';  
            else dataword[i] = '1';
            if(dataword[i] == '1' && flag == start+n) {
                flag = i; 
            }
        }
        start = flag;   
    }
    string res = "";  
    string pre = "";  
    for(ll i = start; i < dataword.size(); i++) res += dataword[i];  
        for(ll i = 0; i<(n-1-res.size()); i++) pre += "0";
        res = pre + res;  
        return temp + res; 
    
    

}
int main() {
    string dataword, divisor;
    cin >> dataword >> divisor;   
    string codeword = CRC(dataword,divisor,1);
    cout << codeword << endl;  
    cout << CRC(codeword,divisor,0) << endl;

}