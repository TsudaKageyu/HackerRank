// https://www.hackerrank.com/challenges/bonetrousle

#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k, b;
        cin >> n >> k >> b;
        
        long long p[b];
        for (int i = 0; i < b; ++i) 
            p[i] = i + 1;
        
        long long sum = b * (b + 1) / 2;
        
        if (sum < n) {
            for (long long i = b - 1; i >= 0; --i) {
                if (sum == n)
                    break;
                
                const long long r = min(n - sum + p[i], i + (k - b) + 1);
                sum -= p[i];
                p[i] = r;
                sum += p[i];
            }    
        }
        
        if (sum == n) {
            for (int i = 0; i < b; ++i) {
                cout << p[i];

                if (i < b - 1)
                    cout << " ";
                else
                    cout << endl;
            }
        }
        else {
            cout << -1 << endl; 
        }
    }
    
    return 0;
}
