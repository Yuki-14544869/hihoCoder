/*
    Author: Yuki
    GitHub: https://github.com/Yuki-14544869/
    Blog:   https://yuki-14544869.github.io/
*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int INF = 0x3f3f3f3f;
LL HilbertNumber(int n, int x, int y) {
    if(n==0)
        return 1;
    int m = 1<<(n-1);

    if(x<=m) {
        if(y<=m)
            return HilbertNumber(n-1, y, x);
        else
            return 1LL*m*m + HilbertNumber(n-1, x, y-m);
    } else {
        if(y>m)
            return 2LL*m*m + HilbertNumber(n-1, x-m, y-m);
        else
            return 3LL*m*m + HilbertNumber(n-1, m+1-y, 2*m+1-x);
    }
}
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    cout << HilbertNumber(n, x, y) << endl;
    return 0;
}