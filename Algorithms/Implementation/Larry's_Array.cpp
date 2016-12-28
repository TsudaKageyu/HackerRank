// https://www.hackerrank.com/challenges/larrys-array

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        // Read the array from STDIN.
        
        vector<int> arr(n);
        for (auto &x : arr)
            cin >> x;
        
        // Count the inversions.
        
        int inversions = 0;
        for (auto it = arr.cbegin(); it != --arr.cend(); ++it) 
            inversions += count_if(it + 1, arr.cend(), [&it](int x) { return (x < *it); });
        
        // Check if we have even inversions.
        
        const char *answers[] = { "YES", "NO" };
        cout << answers[inversions & 1] << endl;
    }
    
    return 0;
}
