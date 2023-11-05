#include<bits/stdc++.h>

using namespace std;

int n, m, r, c;
int a[1005][1005];
int dist[1005][1005];
queue<pair<int,int>> q;

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0 , 1, -1};

main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> r >> c;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin>> a[i][j];
            dist[i][j] = 0;
        }
    }
    dist[r][c] = 1;
    q.push(make_pair(r,c));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 1; i<=4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(dist[newx][newy] || a[newx][newy])
                continue;
            if(newx == 1 || newy == 1 || newx == n || newy == m){
                cout<<dist[x][y] + 1;
                return 0;
            }
            dist[newx][newy] = dist[x][y] + 1;
            q.push(make_pair(newx, newy));
        }
    }
    cout<< -1;
    return 0;
}