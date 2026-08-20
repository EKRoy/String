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
unordered_map<ll, ll> mp;
void get_hash(string s)
{
    int n = s.size();
    ll hs = 0;
    for (int i = 0; i < n; i++)
    {
        hs = ((hs * p) % mod + s[i]) % mod;
        hs %= mod;
    }
    mp[hs]++;
}
ll get_hash2(string s)
{
    int n = s.size();
    ll hs = 0;
    for (int i = 0; i < n; i++)
    {
        hs = ((hs * p) % mod + s[i]) % mod;
        hs %= mod;
    }
    return hs;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    prec();
    ll n;
    cin >> n;
    vector<string> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        get_hash(v[i]);
    }
    ll q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        bool ok = false;
        if (mp.count(get_hash2(s)))
        {
            ok = true;
        }
        if (ok)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}