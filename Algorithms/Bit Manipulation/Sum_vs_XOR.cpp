// https://www.hackerrank.com/challenges/sum-vs-xor

#include <iostream>

using namespace std;

int main(){
    unsigned long long n;
    cin >> n;
    
    if (n == 0) {
        cout << 1 << endl;
    }
    else {
        const int zeros = 64 - __builtin_clzll(n) - __builtin_popcountll(n);
        cout << (1ULL << zeros) << endl;
    }
    
    return 0;
}
