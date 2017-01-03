#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k, b;
        cin >> n >> k >> b;
        
        long long p[b];
        long long sum = 0;
        for (int i = 0; i < b; ++i) {
            p[i] = i + 1;
            sum += i + 1;
        }
        
        if (sum > n) {
            cout << -1 << endl;
        }
        else {
            long long i;
            for (i = b - 1; i >= 0; --i) {
                if (sum == n)
                    break;
                
                const long long l = i + 2;
                const long long r = i + (k - b) + 1;
                const long long next = n - sum + p[i];
                sum -= p[i];
                if (l <= next && next <= r) {
                    p[i] = next;
                    sum += next;
                    break;
                }
                else {
                    p[i] = r;
                    sum += r;
                }
            }    
        
            if (sum < n) {
                cout << -1 << endl; 
            }
            else {
                for (int i = 0; i < b; ++i) {
                    cout << p[i];
                    
                    if (i < b - 1)
                        cout << " ";
                    else
                        cout << endl;
                }
            }
        }
    }
    
    return 0;
}
