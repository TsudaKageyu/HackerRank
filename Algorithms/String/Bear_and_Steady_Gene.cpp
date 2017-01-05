// https://www.hackerrank.com/challenges/bear-and-steady-gene

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    for (char &c : s) {
        if (c == 'A')
            c = 0;
        else if (c == 'C')
            c = 1;
        else if (c == 'T')
            c = 2;
        else
            c = 3;
    }
    
    int count[4] = {};
    
    for (char i : s) 
        count[i]++;

    int min_ans = 0;
    for (int &c : count) {
        c -= n / 4;

        if (c > 0)
            min_ans += c;
    }
    
    int l = 0;
    int r = 0;
    int ans = 500000;
    
    int sub[4] = {};
    sub[s[0]] = 1;

    do {
        bool enough = true;
        for (int i = 0; i < 4; ++i) {
            if (sub[i] < count[i]) {
                enough = false;
                break;
            }
        }
        
        if (enough) {
            ans = min(ans, r - l + 1);
            if (ans == min_ans)
                break;
            
            sub[s[l]]--;
            l++;
        }
        else {
            r++;
            sub[s[r]]++;
        }
    }
    while (r < s.size());
    
    cout << ans << endl;

    return 0;
}
