#include <bits/stdc++.h>
using namespace std;
string mulitply(string a, string b) {
    if (a == "0" || b == "0") return "0";
    vector<int> ans(a.length() + b.length(), 0);
    for (int i = a.length() - 1; i >= 0; i--) {
        for (int j = b.length() - 1; j >= 0; j--) {
            ans[i + j + 1] += ((a[i] - '0') * (b[j] - '0'));
            ans[i + j] += ans[i + j + 1] / 10;
            ans[i + j + 1] %= 10;
        }
    }
    string s = "";
    int flag = 0;
    while (ans[flag] == 0) flag++;
    while (flag < ans.size()) {
        s += ans[flag++] + '0';
    }
    return s;
}

string add(string a, string b) {
    int l = min(a.length(), b.length());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    vector<int> ans;
    for (int i = 0; i < l; ++i) {
        int sum = a[i] - '0' + b[i] - '0' + carry;
        ans.emplace_back(sum % 10);
        carry = sum / 10;
    }
    if (a.length() > l) {
        for (int i = l; i < a.length(); ++i) {
            int sum = a[i] - '0' + carry;
            ans.emplace_back(sum % 10);
            carry = sum / 10;
        }
    }

    if (b.length() > l) {
        for (int i = l; i < b.length(); ++i) {
            int sum = b[i] - '0' + carry;
            ans.emplace_back(sum % 10);
            carry = sum / 10;
        }
    }
    while (carry > 0) {
        ans.emplace_back(carry % 10);
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    string s = "";
    for (int i = 0; i < ans.size(); ++i) {
        s += ans[i] + '0';
    }
    return s;
}


string subtraction(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int l = b.length();
    vector<int> ans;
    for (int i = 0; i < l; ++i) {
        if ((a[i] - '0') < (b[i] - '0')) {
            ans.emplace_back((a[i] - '0') + 10 - (b[i] - '0'));
            a[i + 1]--;
        } else {
            ans.emplace_back((a[i] - '0') - (b[i] - '0'));
        }
    }
    if (a.length() > l) {
        for (int i = l; i < a.length(); ++i) {
            if ((a[i] - '0') < 0) {
                ans.emplace_back((a[i] - '0') + 10);
                a[i + 1]--;
            } else {
                ans.emplace_back((a[i] - '0'));
            }
        }
    }
    reverse(ans.begin(), ans.end());
    int flag = 0;
    while (ans[flag] == 0) flag++;
    string s = "";
    while (flag < ans.size()) s += ans[flag++] + '0';
    return s;
}

string coumpute_power(string x, int y) {
    if (y == 1) return x;
    string ans = "";
    if (1 & y) {
        return mulitply(x, coumpute_power(x, y - 1));
    }
    ans = coumpute_power(x, y / 2);
    return mulitply(ans, ans);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string a;
    cin >> a;
    string ans = coumpute_power(a, 8);
    cout << ans << '\n';














    return 0;

}