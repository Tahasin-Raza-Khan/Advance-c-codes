#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F0R(i, n) for (int i = 0; i < n; ++i)
ll k;
vector<ll> b, c;
ll m, n, mod;

vector<vector<ll>> multiply(vector<vector<ll>> a, vector<vector<ll>> b)
{
    vector<vector<ll>> pro(k + 1, vector<ll>(k + 1));
    F0R(i, k + 1)
    {
        F0R(j, k + 1)
        {
            pro[i][j] = 0;
            F0R(l, k + 1)
            {
                pro[i][j] = (pro[i][j] + a[i][l] * b[l][j] % mod) % mod;
            }
        }
    }
    return pro;
}

vector<vector<ll>> compute(vector<vector<ll>> M, ll p)
{
    if (p == 1)
    {
        return M;
    }
    vector<vector<ll>> ans(k + 1, vector<ll>(k + 1));
    if (1 & p)
    {
        return multiply(M, compute(M, p - 1));
    }
    ans = compute(M, p / 2);
    return multiply(ans, ans);
}

ll add(ll t, ll &sum)
{
    ll ans = 0;
    if (t <= k)
    {
        for (int i = 0; i < t; ++i)
        {
            ans = (ans + b[i]) % mod;
        }
        return ans;
    }
    vector<ll> f(k + 1);
    f[0] = sum;
    for (int i = 0; i < k; ++i)
    {
        f[i + 1] = b[i];
    }
    vector<vector<ll>> T(k + 1, vector<ll>(k + 1));
    F0R(i, k + 1)
    {
        F0R(j, k + 1)
        {
            if (i == 0)
            {
                if (j == 0)
                    T[i][i] = 1;
                else
                    T[i][j] = c[k - j];
            }
            else
            {
                if (i == k)
                {
                    if (j == 0)
                        T[i][j] = 0;
                    else
                        T[i][j] = c[k - j];
                }
                else
                {
                    if (j == i + 1)
                    {
                        T[i][j] = 1;
                    }
                    else
                    {
                        T[i][j] = 0;
                    }
                }
            }
        }
    }
    T = compute(T, t - k);
    for (int i = 0; i <= k; ++i)
    {
        ans = (ans + T[0][i] * f[i] % mod) % mod;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> k;
        ll sum = 0;
        for (int i = 0; i < k; ++i)
        {
            ll x;
            cin >> x;
            b.emplace_back(x);
            sum += x;
        }

        for (int i = 0; i < k; ++i)
        {
            ll x;
            cin >> x;
            c.emplace_back(x);
        }
        cin >> m >> n >> mod;

        ll temp = add(n, sum);
        ll temp2 = add(m - 1, sum);
        ll ans = (temp - temp2) % mod;
        if (ans < 0)
            ans += mod;
        cout << ans << '\n';
        b.clear();
        c.clear();
    }

    return 0;
}
