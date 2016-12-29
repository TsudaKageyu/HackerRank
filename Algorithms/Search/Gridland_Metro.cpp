// https://www.hackerrank.com/challenges/gridland-metro

#include <vector>
#include <iostream>

using namespace std;

struct Track {
    Track(int r, int s, int e) : r(r), s(s), e(e) {}

    int r;
    int s;
    int e;
};

int main() {
    long long n, m;
    int k;
    cin >> n >> m >> k;
    
    vector<Track> tracks;
    tracks.reserve(k);
    for (int i = 0; i < k; ++i) {
        int r, s, e;
        cin >> r >> s >> e;
        tracks.emplace_back(r, s, e);
    }
    
    for (int i = 0; i < k - 1; ++i) {
        if (tracks[i].r == 0)
            continue;
        
        for (int j = i + 1; j < k; ++j) {
            if (tracks[i].r != tracks[j].r)
                continue;
            
            if ((tracks[i].s <= tracks[j].s && tracks[i].e >= tracks[j].s)
                || (tracks[i].s > tracks[j].s && tracks[j].e >= tracks[i].s)) 
            {
                tracks[i].s = min(tracks[i].s, tracks[j].s);
                tracks[i].e = max(tracks[i].e, tracks[j].e);
                tracks[j].r = 0;
            }
        }
    }

    long long count = n * m;
    for (const auto &t : tracks) {
        if (t.r != 0)
            count -= (t.e - t.s + 1);
    }
    
    cout << count << endl;
    
    return 0;
}
