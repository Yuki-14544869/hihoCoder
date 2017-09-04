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

typedef struct node{
    int x, y, sum;
};
char maps[105][105];
int vis[105][105][1<<6];
int dis[4][2] = {-1,0,0,-1,1,0,0,1};
int n, m, k, sx, sy, ex, ey;
vector<pair<int, int>> keys;
bool check(int x, int y) {
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    if(maps[x][y]=='#')
        return false;

    return true;
}
int bfs() {
    mm(vis, 0);
    vis[sx][sy][0] = 0;
    queue <node> q;
    q.push((node){sx, sy, 0});

    while(!q.empty()) {
        node now = q.front();
        q.pop();
        if(now.x==ex && now.y==ey)
            return vis[now.x][now.y][now.sum];

        ff(i, 0, 4, 1) {
            int nx = now.x+dis[i][0];
            int ny = now.y+dis[i][1];
            if(!check(nx, ny))
                continue;
            if(maps[nx][ny]=='.' && vis[nx][ny][now.sum]==0) {
                vis[nx][ny][now.sum] = vis[now.x][now.y][now.sum]+1;
                q.push((node){nx, ny, now.sum});
            } else if(isdigit(maps[nx][ny])) {
                int sum = now.sum|(1<<(maps[nx][ny]-'0'));
                if(vis[nx][ny][sum])
                    continue;
                vis[nx][ny][sum] = vis[now.x][now.y][now.sum] + 1;
                q.push((node){nx, ny, sum});
            } else if(isupper(maps[nx][ny])) {
                if(now.sum&(1<<(maps[nx][ny]-'A')) && vis[nx][ny][now.sum]==0) {
                    vis[nx][ny][now.sum] = vis[now.x][now.y][now.sum]  + 1;
                    q.push((node){nx, ny, now.sum});
                }
            }
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m >> k >> sx >> sy >> ex >> ey;
    ff(i, 0, n, 1)
        ff(j, 0, m, 1)
            cin >> maps[i][j];

    ff(i, 0, k, 1) {
        int x, y;
        cin >> x >> y;
        keys.push_back({x, y});
        maps[x][y] = '0' + i;
    }
    cout << bfs() << endl;
    return 0;
}

