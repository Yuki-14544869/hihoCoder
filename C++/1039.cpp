/*
    Author: Yuki
    GitHub: https://github.com/Yuki-14544869/
    Blog:   https://yuki-14544869.github.io/
*/
#include <bits/stdc++.h>

using namespace std;
const int INF=0x3f3f3f3f;

int cal(string p) {
    int len = p.size();
    if(p.empty())
        return 0;
    string t = "";
    int l = 0;
    p += "*";
    for(int i=1; p[i]; i++) {
        if(p[i] != p[i-1]) {
            if(l == i-1) {
                t += p[i-1];
            }
            l = i;
        }
    }
    if(t.size() == len)
        return 0;
    return len-t.size()+cal(t);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while(t--) {
        string s;
        string insert[3] = {"A","B","C"};
        cin >> s;
        int ans=0;
        for(int i=0; s[i]; i++) {
            for(int j=0; j<3; ++j) {
                string tmp = s;
                tmp.insert(i, insert[j]);
                ans = max(ans, cal(tmp));
            }
        }
        cout << ans << endl;
    }
    return 0;
}