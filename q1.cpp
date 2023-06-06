#include<bits/stdc++.h>
#define ll long long int 
using namespace std;  
vector<string> input() {
    vector<string>data;  
    ll n; 
    cout<<"Number of Strings:"<<endl;
    cin >> n;  
    for(ll i = 0; i < n; i++) {
        string x;
        cout<<"Enter String"<<i+1<<":"<<endl;  
        cin >> x;  
        data.push_back(x);
    }
    return data;  
}
ll HammingDistance(string x, string y) {
    ll n = x.size();
    ll m = y.size();
    int p = abs(n-m);  
    ll cnt = 0;  
    for(ll i = n-1, j=m-1; i>=0 && j>=0; i--, j--) {
        if(x[i] != y[j]) cnt++;  
    }
    
    if(n>m) for(int i=0; i<p; i++) if(x[i]=='1') cnt++;
    else if(m>n) for(int i=0; i<p; i++) if(y[i] =='1') cnt++;
    return cnt; 
}
ll findMinHammingDistance(vector<string>& data) {
    ll n = data.size();  
    ll ans = INT_MAX;  
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