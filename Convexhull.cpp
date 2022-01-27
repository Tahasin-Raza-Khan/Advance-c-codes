#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

struct points {
    int x, y;
    bool operator <(points &p) {
        if (p.x == x) return y < p.y;
        else return x < p.x;
    }
    bool operator ==(points &p) {
        return (p.x == x && p.y == y);


    }
};

bool clock_wise(points a, points b, points c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0 ;
}
bool anti_clock_wise(points a, points b, points c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0 ;
}
bool collinear(points a, points b, points c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) == 0 ;
}

void convrx_hull(vector<points>&t) {
    if (t.size() <= 2) return;
    sort(t.begin(), t.end());
    points p1 = t[0];
    int n = t.size();
    points p2 = t[n - 1];
    vector<points> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < n; ++i) {
        //upper half
        if (!(anti_clock_wise(p1, t[i], p2) || i == n - 1)) {
            while (up.size() >= 2 && (anti_clock_wise(up[up.size() - 2], up[up.size() - 1], t[i]))) {
                up.pop_back();
            }
            up.push_back(t[i]);
        }

        if (!(clock_wise(p1, t[i], p2)) || i == n - 1) {
            while (down.size() >= 2 && (clock_wise(down[down.size() - 2], down[down.size() - 1], t[i]))) {
                down.pop_back();
            }
            down.push_back(t[i]);

        }
    }
    t.clear();
    for (int i = 0; i < up.size(); ++i) {
        t.push_back(up[i]);
    }
    for (int i = 0; i < down.size(); ++i) {
        t.push_back(down[i]);
    }
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());

}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);


    int no_of_points;
    cin >> no_of_points;
    vector<points> t(no_of_points);
    for (int i = 0; i < no_of_points; ++i) {
        cin >> t[i].x >> t[i].y;
    }

    convrx_hull(t);
    for (auto &a : t) {
        cout << a.x << " " << a.y << " ";
        cout << '\n';
    }
    cout << '\n';














    return 0;

}
