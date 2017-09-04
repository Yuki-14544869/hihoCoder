/*
    Author: Yuki
    GitHub: https://github.com/Yuki-14544869/
    Blog:   https://yuki-14544869.github.io/
*/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int min = 0x3f3f3f3f;
#define ff(a, b, c, d) for(int a=b; a<c; a+=d)
#define mm(a, b)       memset(a, b, sizeof(a))


int N;
map<int, int> cnt;
typedef pair<int, int> p;
set<p, greater<p> > s;


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> N;
    int x;
    ff(i, 0, N, 1) {
        cin >> x;
        cnt[x]++;
    }

    for(auto& x : cnt) {
        s.insert({x.second, -x.first});
    }

//    for(auto&x : cnt) {
//        cout << x.first << " " << x.second << endl;
//    }

    if(s.begin()->first > (N-1)/2+1) {
        cout << "-1" << endl;
        return 0;
    }
    //cout << "out : " << N << endl;
    for(int res, pre=0; N--; pre=res) {
        //cout << N << endl;
        int temp = s.begin()->first;
        if(temp > (N-1)/2+1) {
            auto it = s.begin();
            if(it->second == pre)
                it++;
            res = -it->second;
            if(it->first==1)
                cnt.erase(res);
            else {
                s.insert({it->first-1, it->second});
                cnt[res]--;
            }
            s.erase(it);
        } else {
            auto it = cnt.begin();
            if(it->first==pre)
                it++;
            res = it->first;
            s.erase({it->second, -res});
            if(it->second==1)
                cnt.erase(it);
            else {
                it->second--;
                s.insert({it->second, -res});
            }
        }
        cout << res << ' ';
    }
    cout << endl;
    return 0;
}

