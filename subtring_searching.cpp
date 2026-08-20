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
    ll hs = 0;
    pre.push_back(0);
    for (int i = 0; i < n; i++)
    {
        hs = ((hs * p) % mod + s[i]) % mod;
        hs %= mod;
        pre.push_back(hs);
    }
}
ll get_hash2(string s)
{
    ll n = s.size();
    ll hs = 0;
    for (ll i = 0; i < n; i++)
    {
        hs = ((hs * p) % mod + s[i]) % mod;
        hs %= mod;
    }
    return hs;
}
ll get_subhash(ll l, ll r)
{
    ll val = (pre[r] - pre[l - 1] * pw[r - l + 1] % mod + mod) % mod;

    return val;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    prec();
    string a;
    cin >> a;
    string b;
    cin >> b;
    ll l = 1, r = b.size();
    get_hash(a);
    ll x = get_hash2(b);
    bool ok = false;
    for (ll i = r; i <= a.size(); i++)
    {
        ll k = get_subhash(l, i);
        l++;
        if (x==k)
        {
            ok = true;
            break;
        }
    }
    if (ok)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}