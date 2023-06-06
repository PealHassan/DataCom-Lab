#include<bits/stdc++.h>
#define ll long long int 
using namespace std;  
void CRC(string dataword, string divisor) {
    string temp = dataword;
    for(ll i = 0; i < dataword.size()-1; i++)  dataword += "0";
    ll start = 0;
    ll n = dataword.size();     
    while(start + n <= dataword.size()) {
        ll flag = 0;   
        for(ll i = start, j = 0; j < n; j++,i++) {
            if(dataword[i] == temp[j]) dataword[i] = '0';  
            else dataword[i] = '1';
            if(dataword[i] == '1' && flag == 0) {
                flag = 1;  
                start = i;
            }
        }
    }
    string res = "";  
    for(ll i = start; i < dataword.size(); i++) res += dataword[i];  
    cout << res << endl;  
}
int main() {
    string dataword, divisor;
    cin >> dataword >> divisor;   
    CRC(dataword,divisor);

}