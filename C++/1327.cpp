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

string input;
int cnt[26] = {0};

bool check(int x) {
    ff(i, 0, 26, 1)
        if(cnt[i]>(x-1)/2+1)
            return false;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> input;
    int len = input.size();
    //cout << len << endl;
    ff(i, 0, len, 1)
        cnt[input[i]-'a']++;
    if(!check(len)) {
        cout << "INVALID" << endl;
        return 0;
    }
/*
    int pre = -1;
    ff(i, 0, len, 1) {
        ff(j, 0, 26, 1) {
            if(cnt[j]>0 && j!=pre) {
                cnt[j]--;
                if(check(len-1)) {
                    putchar('a'+j);
                    pre = j;
                    len--;
                    break;
                } else cnt[j]++;
            }
        }
    }
*/

    int pre = -1;
    ff(i, 0, input.size(), 1) {
        ff(j, 0, 26, 1) {
            if(cnt[j] && j!=pre) {
                cnt[j]--;
                if(check(len-1)) {
                    putchar('a'+j);
                    pre=j;
                    len--;
                    break;
                }
                else cnt[j]++;
            }
        }
    }
    cout << endl;
    return 0;
}

