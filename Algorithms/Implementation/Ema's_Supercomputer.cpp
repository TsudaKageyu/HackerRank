// https://www.hackerrank.com/challenges/two-pluses

#include <iostream>
#include <algorithm>

using namespace std;

struct Cross{
    int y;
    int x;
    int l;
};

int area(const Cross &c) {
    return c.l * 4 - 3;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    string g[n];
    for (auto &s : g)
        cin >> s;
    
    vector<Cross> c;
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < m; ++x) {
            if (g[y][x] == 'B')
                continue;
            
            int l;
            for (l = 1; ; ++l) {
                if (y - l < 0     || g[y - l][x] == 'B') break;
                if (y + l > n - 1 || g[y + l][x] == 'B') break;
                if (x - l < 0     || g[y][x - l] == 'B') break;
                if (x + l > m - 1 || g[y][x + l] == 'B') break;
            }
            
            if (l > 1) {
                for (int ll = 2; ll <= l; ++ll) {
                    c.emplace_back();
                    c.back().y = y;
                    c.back().x = x;
                    c.back().l = ll;
                }
            }
        }
    }
    
    int ans = 1;
    for (int i = 0; i < c.size(); ++i)
        ans = max(ans, area(c[i]));
    
    for (int i = 0; i < static_cast<int>(c.size()) - 1; ++i) {
        for (int l = 1; l < c[i].l; ++l) {
            g[c[i].y - l][c[i].x] = 'X';
            g[c[i].y + l][c[i].x] = 'X';
            g[c[i].y][c[i].x - l] = 'X';
            g[c[i].y][c[i].x + l] = 'X';
        }

        for (int j = i + 1; j < c.size(); ++j) {
            int l;
            for (l = 0; l < c[j].l; ++l) {
                if (g[c[j].y - l][c[j].x] == 'X') break;
                if (g[c[j].y + l][c[j].x] == 'X') break;
                if (g[c[j].y][c[j].x - l] == 'X') break;
                if (g[c[j].y][c[j].x + l] == 'X') break;
            }
            
            if (l == c[j].l)
                ans = max(ans, area(c[i]) * area(c[j]));
        }

        for (int l = 1; l < c[i].l; ++l) {
            g[c[i].y - l][c[i].x] = 'G';
            g[c[i].y + l][c[i].x] = 'G';
            g[c[i].y][c[i].x - l] = 'G';
            g[c[i].y][c[i].x + l] = 'G';
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
