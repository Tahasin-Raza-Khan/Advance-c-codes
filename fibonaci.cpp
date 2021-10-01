#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F0R(i,n) for(int i=0;i<n;++i)
#define FOR(i,n) for(int i=1;i<=n;++i)
ll MOD = 1e9;
ll k;
vector<ll> b, c;
 
vector<vector<ll>> multiply(vector<vector<ll>> a, vector<vector<ll>> b) {
 
    vector<vector<ll>> ans(k, vector<ll>(k));
    F0R(i, k) {
        F0R(j, k) {
            ans[i][j] = 0;
            F0R(l, k) {
                ans[i][j] = (ans[i][j]+a[i][l] * b[l][j]  % MOD) % MOD;
            }
        }
    }
    return ans;
 
}
 
 
 
vector<vector<ll>> power(vector<vector<ll>> m, ll p) {
    if (p == 1) {
        return m;
    }
    if (1 & p) {
        return multiply(m, power(m, p - 1));
    }
    vector<vector<ll>> t(k, vector<ll>(k));
    t = power(m, p / 2);
    return multiply(t, t);
 
}
ll compute(ll &n ) {
    if (n == 0) {
        return 0;
    }
    if (n <= k) {
        return b[n - 1];
 
    }
    vector<ll> f(k);
    F0R(i, k) {
        f[i] = b[i];
    }
    vector<vector<ll>> T(k, vector<ll>(k));
    F0R(i, k) {
        F0R(j, k) {
            if (i == k - 1) {
                T[i][j] = c[k - 1 - j];
            } else {
                if (j == i + 1) {
                    T[i][j] = 1;
                } else {
                    T[i][j] = 0;
                }
            }
        }
    }
 
    T = power(T, n - 1);
    ll ans = 0;
    F0R(i, k) {
        ans = (ans + T[0][i] * f[i]  % MOD) % MOD;
    }
 
    return ans;
 
}
 
 
 
 
 
 
 
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
 
    long long tt = 1;
    cin >> tt;
    while (tt--) {
 
        cin >> k;
 
        F0R(i, k) {
            ll x; cin >> x;
            b.emplace_back(x);
        }
 
        F0R(i, k) {
            ll x; cin >> x;
            c.emplace_back(x);
        }
        ll n;
        cin >> n;
        ll ans = compute(n);
        cout << ans << '\n';
        b.clear(); c.clear();
 
 
 
 
 
 
    }
 
    return 0;
 
} 