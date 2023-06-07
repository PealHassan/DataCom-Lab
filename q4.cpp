#include<bits/stdc++.h>  
#define ll long long int
#define bit_size 8
using namespace std;  
vector<int> input() {
    vector<int>temp;   
    for(ll i = 0; i < 5; i++) {
        ll x; 
        cin >> x;  
        temp.push_back(x);
    }
    temp.push_back(0);
    return temp ;  
}
ll checksum(vector<int>& data) {
    ll sum = 0; 
    for(ll i = 0; i<data.size(); i++) sum += data[i];
    bitset<bit_size+32>bit;  
    bit = sum;  
    ll x = 0, y = 0;   
    for(ll i = 0; i<bit_size; i++) {
        if(bit[i]) x += (1ll << i);
        if(bit[i+bit_size]) y += (1ll << i);
    }
    x += y;    
    bitset<bit_size>bit2;  
    bit2 = x;  
    for(ll i = 0; i<bit_size; i++) {
        bit2[i] = !bit2[i];
    }
    

    ll res = 0; 
    for(ll i = 0; i<bit_size; i++)
        if(bit2[i]) res += (1LL << i);  
    return res;   

    
}
int main() {
    vector<int> data = input();   
    ll res = checksum(data);  
    cout << res << endl;
    data[data.size()-1] = res;  
    cout << checksum(data) << endl;  
    // bitset<4> b,c;
    // b = 5;
    // c = 6;
    // cerr<<(b)<<endl;

}