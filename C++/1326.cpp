/*
    Author: Yuki
    GitHub: https://github.com/Yuki-14544869/
    Blog:   https://yuki-14544869.github.io/
*/
#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int len = s.length();
        int ans = INF;
        int cnt0, cnt1;
        for(int i=0; i<=len; ++i) {
            cnt0 = cnt1 = 0;
            for(int j=i-1; j>=0; --j)
                cnt0 += s[j]=='0' ? 0:1;
            for(int j=i; s[j]; ++j)
                cnt1 += s[j]=='1' ? 0:1;
            ans = min(ans, cnt0+cnt1);
        }
        cout << ans << endl;
    }
    return 0;
}