#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int p = 137, mod = 1e9 + 7, N = 1e5 + 9;
ll pw[N];
// O(N)
void prec()
{
    pw[0] = 1;
    for (int i = 1; i < N; i++)
    {
        pw[i] = 1ll * p * pw[i - 1] % mod;
    }
}
vector<ll> pre;
void get_hash(string s)
{
    int n = s.size();
    pre.push_back(0);
    ll hs = 0;
    for (int i = 0; i < n; i++)
    {
        hs = ((hs * p) % mod + s[i]) % mod;
        hs %= mod;
        pre.push_back(hs);
    }
}
vector<ll>suf;
void get_hash2(string s){
    ll n=s.size();
    suf.assign(n+1,0);
    ll hs=0;
    for(ll i=n-1;i>=0;i--){
        suf[i]=((suf[i+1]*p)%mod+s[i])%mod;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    prec();
    string a;
    cin >> a;
    get_hash(a);
    cout<<'\n';
    get_hash2(a);
    ll n=a.size();
    if(n%2==1){
        if(pre[n/2]==suf[n/2+1]){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';
    }
    else{
        if(pre[n/2]==suf[n/2]){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<'\n';
    }
    return 0;
}