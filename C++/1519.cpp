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
namespace BFS {
    int n, m;
    char maps[505][505];
    bool vis[505][505] = {false};
    int ans[505][505] = {0};
    int sx, sy, ex, ey;
    int dis[4][2] = {-1,0,0,-1,1,0,0,1};//0左1上2右3下
    struct node {
        int x, y;
        int cnt;
        node(int _x, int _y, int _cnt):x(_x),y(_y),cnt(_cnt){}
    };
    bool check(int x, int y) {
        if(x<0 || x>=n || y<0 || y>=m)
            return false;
        return maps[x][y] != '#';
    }
    void init() {
        cin >> n >> m;
        ff(i, 0, n, 1)
            ff(j, 0, m, 1) {
                cin >> maps[i][j];
                if(maps[i][j]=='S')
                    sx=i, sy=j;
                else if(maps[i][j]=='T')
                    ex=i, ey=j;
            }
    }
    int bfs() {
        vis[sx][sy] = true;
        queue<node> q;
        q.push({sx, sy, 0});

        while(!q.empty()) {
            node now = q.front();
            q.pop();

            ff(i, 0, 4, 1) {
                //cout << now.x << " " << now.y << endl;
                int x = now.x + dis[i][0];
                int y = now.y + dis[i][1];
                //cout << x << " " << y << endl;
                if(!check(x, y))
                    continue;
                if(maps[x][y] == 'T')
                    return now.cnt;
                while(check(x+dis[i][0], y+dis[i][1])) {
                    x += dis[i][0];
                    y += dis[i][1];

                    if(x==ex && y==ey)
                        return now.cnt;
                }
                if(!vis[x][y]) {
                    int cnt = now.cnt + 1;
                    q.push((node){x, y, cnt});
                    vis[x][y] = true;
                }
            }
        }
        return -1;
    }
}
using namespace BFS;
void intxt() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
}
int main() {
    intxt();
    init();
//    cout << n << " " << m << endl;
//    ff(i, 0, n, 1) {
//        ff(j, 0, m, 1)cout << maps[i][j];
//        cout << endl;
//    }
//    cout << sx << " " << sy << endl
//         << ex << " " << ey << endl;
    cout << bfs() << endl;
    return 0;
}

