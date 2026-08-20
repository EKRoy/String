#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int p = 137, mod = 1e9 + 7, N = 1e5 + 9;
ll pw[N];
void prec()
{
    pw[0] = 1;
    for (int i = 1; i < N; i++)
    {
        pw[i] = 1ll * p * pw[i - 1] % mod;
    }
}
int get_hash(string s)
{
    int n = s.size();
    ll hs = 0;
    for (int i = 0; i < n; i++)
    {
        hs += 1ll * s[i] * pw[i] % mod;
        hs %= mod;
    }
    return hs;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    prec();
    string a, b;
    cin >> a >> b;
    cout << get_hash(a) << " " << get_hash(b) << '\n';
    return 0;
}