// https://www.hackerrank.com/challenges/cipher

#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    string d(n, '*');
    d[0] = s[0];
    int x = d[0] - '0';
    
    for (int i = 1; i < k - 1; ++i) {
        d[i] = static_cast<char>(x ^ (s[i] - '0') + '0');
        x ^= d[i] - '0';
    }
    for (int i = k - 1; i < n; ++i) {
        d[i] = static_cast<char>(x ^ (s[i] - '0') + '0');
        x ^= d[i] - '0';
        x ^= d[i - k + 1] - '0';
    }
    
    cout << d << endl;
    
    return 0;
}
