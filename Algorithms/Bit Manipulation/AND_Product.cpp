// https://www.hackerrank.com/challenges/and-product

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        unsigned int a, b;
        cin >> a >> b;
        
        if (__builtin_clz(a) > __builtin_clz(b)) {
            cout << 0 << endl;
        }
        else {
            for (int i = 0; i < 32; ++i) {
                unsigned int mask = 1U << i;
                if (!(a & mask))
                    continue;
                
                unsigned long long d = (2ULL << i);
                if (b >= ((a + d - 1) / d * d)) 
                    a &= ~mask;
            }
            
            cout << a << endl;
        }
    }
    return 0;
}
