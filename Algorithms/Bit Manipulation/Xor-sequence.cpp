// https://www.hackerrank.com/challenges/xor-se

#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int Q;
    cin >> Q;
    
    while (Q--) {
        long long L;
        long long R;
        cin >> L >> R;

        const long long l = L / 8 * 8;
        long long xor1[8] = { l, 1, l + 3, 0, l + 4, 1, l + 7, 0 };
        fill(&xor1[0], &xor1[L - l], 0);

        const long long r = R / 8 * 8;
        long long xor2[8] = { r, 1, r + 3, 0, r + 4, 1, r + 7, 0 };

        if (r == l) {
            fill(&xor1[R - r + 1], &xor1[8], 0);
            fill(&xor2[0], &xor2[8], 0);
        }
        else {
            fill(&xor2[R - r + 1], &xor2[8], 0);
        }
        
        long long ans = 0;
        for (auto x : xor1)
            ans ^= x;
        for (auto x : xor2)
            ans ^= x;
        
        cout << ans << endl;
    }
    return 0;
}
