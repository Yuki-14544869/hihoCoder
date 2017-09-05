/*
    Author: Yuki
    GitHub: https://github.com/Yuki-14544869/
    Blog:   https://yuki-14544869.github.io/
*/
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")     //手动扩栈
typedef long long LL;
#define INF = 0x3f3f3f3f;
#define eps 1e-10
#define ff(a, b, c, d) for(int a=b; a<c; a+=d)
#define fff(a, b, c, d) for(int a=b; a>=c; a-=d)
#define mm(a, b)       memset(a, b, sizeof(a))
const double PIE = acos(-1.0);
void init() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
}


const int N = 100000+50;
int n;
int a[N] = {0};

int main() {
    init();
    cin >> n;
    ff(i,0,n,1)
        cin >> a[i];
    int MAX = n;
    fff(i,n-1,0,1)
        if(a[i] == MAX)
            MAX--;
    cout << MAX << endl;
    return 0;
}