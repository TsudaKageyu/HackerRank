// https://www.hackerrank.com/challenges/lilys-homework

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int getSwapCount(vector<int> a, vector<int> b) {
    const int n = a.size();
    
    map<int, int> m;
    for (int i = 0; i < n; ++i)
        m[a[i]] = i;
    
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            count ++;
            const int j = m[a[i]];
            const int k = m[b[i]];
            swap(m[a[j]], m[a[k]]);
            swap(a[j], a[k]);
        }
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    
    vector<int> b = a;
    sort(b.begin(), b.end());
    const int count1 = getSwapCount(a, b);

    reverse(b.begin(), b.end());
    const int count2 = getSwapCount(a, b);
    
    cout << min(count1, count2) << endl;
    
    return 0;
}
