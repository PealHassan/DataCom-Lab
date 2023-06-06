#include<bits/stdc++.h>
#define ll long long int 
using namespace std;  
vector<string> input() {
    vector<string>data;  
    ll n; 
    cin >> n;  
    for(ll i = 0; i < n; i++) {
        string x;  
        cin >> x;  
        data.push_back(x);
    }
    return data;  
}
ll HammingDistance(string x, string y) {
    ll n = x.size();  
    ll cnt = 0;  
    for(ll i = 0; i<n; i++) {
        if(x[i] != y[i]) cnt++;  
    }
    return cnt; 
}
ll findMinHammingDistance(vector<string>& data) {
    ll n = data.size();  
    ll ans = n+10;  
    for(ll i = 0; i<n ; i++) {
        for(ll j = i + 1; j<n ; j++) {
            ans = min(ans,HammingDistance(data[i],data[j]));
        }
    }
    return ans;  
}
int main() {

    vector<string> data = input();   
    ll res = findMinHammingDistance(data);   
    cout << res << endl;  
}