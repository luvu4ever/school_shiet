#include<bits/stdc++.h>
#define f1(i,a) for(int i=1; i<=a; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mp make_pair
#define MAX_N 1005


using namespace std;

int n, m, r, c;
int dx[5] = {0, 1,-1, 0 ,0};
int dy[5] = {0, 0, 0, 1, -1};
int visited[MAX_N][MAX_N], a[MAX_N][MAX_N];

main()
{
    cin >> n >> m >> r >>c;
    f1(i, n){
        f1(j, m){
            cin >> a[i][j];
            visited[i][j] = 0;
        }
    }
    queue<pii> q;
    visited[r][c] = 1;
    q.push(mp(r,c));
    while(!q.empty()){
        int curx = q.front().fi;
        int cury = q.front().se;
        q.pop();
        f1(i, 4){
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            if(visited[newx][newy] || a[newx][newy]) continue;
            //cout << newx <<" "<< newy << '\n';
            if(newx == 1 || newy == 1 || newx == n || newy == m){
                cout<<visited[curx][cury] + 1;
                return 0;
            }
            q.push(mp(newx, newy));
            visited[newx][newy] = visited[curx][cury] + 1;
        }
    }
    cout<< -1;
    return 0;
}