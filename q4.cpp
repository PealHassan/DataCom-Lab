#include<bits/stdc++.h>  
#define ll long long int 
using namespace std;  
vector<int> input() {
    vector<int>temp;   
    for(ll i = 0; i < 5; i++) {
        ll x; 
        cin >> x;  
        temp.push_back(x);
    }
    return temp ;  
}
ll checksum(vector<int>& data) {
    ll sum = 0; 
    for(ll i = 0; i<data.size(); i++) sum += data[i];
    bitset<32>bit;  
    bit = sum;  
    for(ll i = 0; i<8; i++) 
        bit[i] = !(bit[i] ^ bit[i+8]);
    ll res = 0; 
    for(ll i = 0; i<8; i++)
        if(bit[i]) res += (1LL << i);  
    return res;   
    
}
int main() {
    vector<int> data = input();   
    ll res = checksum(data);  
    cout << res << endl;  
}