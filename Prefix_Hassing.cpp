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
vector<ll>pre;
int get_hash(string s)
{
    pre.push_back(0);
    int n = s.size();
    ll hs = 0;
    for (int i = 0; i < n; i++)
    {
        hs = ((hs * p) % mod + s[i]) % mod;
        hs %= mod;
        pre.push_back(hs);
    }
    return hs;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    prec();
    string a;
    cin >> a;
    cout << get_hash(a) << '\n';
    for(ll x:pre){
        cout<<x<<" ";
    }
    return 0;
}