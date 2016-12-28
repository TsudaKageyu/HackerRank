// https://www.hackerrank.com/challenges/counter-game

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        unsigned long long n;
        cin >> n;
        
        int turns = 0;
        while (n > 1) {
            if (__builtin_popcountll(n) == 1) {
                turns += __builtin_ctzll(n);
                n = 1;
            }
            else {
                turns++;
                n -= (1ULL << (63 - __builtin_clzll(n)));;
            }
        }
        
        const char *players[] = { "Richard", "Louise" };
        cout << players[turns & 1] << endl;
        
    }
    
    return 0;
}
