// https://www.hackerrank.com/challenges/bomber-man

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int r, c, n;
    cin >> r >> c >> n;
    
    vector<string> g(r);
    for (auto &s : g)
        cin >> s;
    
    if (n > 5)
        n = (n - 2) % 4 + 2;

    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 0) {
            for (int y = 0; y < r; ++y) {
                for (int x = 0; x < c; ++x) {
                    if (g[y][x] == 'O') g[y][x] = 'P';
                    if (g[y][x] == '.') g[y][x] = 'O';
                }
            }
        }
        else {
            vector<string> g2 = g;
            
            for (int y = 0; y < r; ++y) {
                for (int x = 0; x < c; ++x) {
                    if (g2[y][x] == 'P') {
                        g[y][x] = '.';
                        if (y > 0)     g[y - 1][x] = '.';
                        if (y < r - 1) g[y + 1][x] = '.';
                        if (x > 0)     g[y][x - 1] = '.';
                        if (x < c - 1) g[y][x + 1] = '.';
                    }
                }
            }
        }
    }

    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x) {
            if (g[y][x] == 'P') g[y][x] = 'O';
        }
    }

    for (auto &s : g)
        cout << s << endl;

    return 0;
}
