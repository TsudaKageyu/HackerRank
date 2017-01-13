// https://www.hackerrank.com/challenges/ctci-ice-cream-parlor

#include <bits/stdc++.h>

using namespace std;

class IceCream {
public: 
    int flavor; 
    int index;

    IceCream(int flavor, int index) : flavor(flavor), index(index) {
    }
};
    
int binarySearch(int first, int last, vector<IceCream> arr, int search) {
    if (last - first > 5) {
        const int i = (first + last) / 2;
        if (arr[i].flavor == search) 
            return arr[i].index;
        else if (arr[i].flavor > search && first < i)
            return binarySearch(first, i, arr, search);
        else if (arr[i].flavor < search && i + 1 <= last)
            return binarySearch(i + 1, last, arr, search);
        else
            return -1;
    }
    else {
        for (int i = first; i <= last; ++i) {
            if (arr[i].flavor == search) 
                return arr[i].index;
        }
        
        return -1;
    }
}

bool compare(const IceCream &a, const IceCream &b) {
    return a.flavor < b.flavor;
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {       
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n); 

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        sort(arr.begin(), arr.end(), compare);
        int firstIndex = 100000, secondIndex = 100000;
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].flavor;
            if(search >= arr[i].flavor) {
                int index = binarySearch( i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;

                }
            }
        }

    }

}

