// https://www.hackerrank.com/challenges/chief-hopper

#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    for (auto &x : h)
        cin >> x;
    
    int e = 0;
    for (auto it = h.crbegin(); it != h.crend(); ++it)
        e = (*it + e + 1) / 2;
    
    cout << e << endl;
    
    return 0;
}
