#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second
#define MAX_INT 1000000009

using namespace std;

int cal_x[5] = {0, 1, -1, 0 ,0};
int cal_y[5] = {0, 0, 0, 1, -1};

queue<pair<int, pair<int,int>>> q;

main(){
    int n, t;
    cin>> n>> t;
    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            for(int step = 0; step <=4; step++){
                f[i][j][step] = MAX_INT;
            }
        }
    }
    q.push(mp(0,mp(1,1)));
    while(q.size()){
        int step = q.back().fi;
        int x = q.back().se.fi;
        int y = q.back().se.se;

        q.pop();
        for(int i = 1; i<=4; i++){
            int newx = x + cal_x[i];
            int newy = y + cal_y[i];
            if(newx <= 0 || newy<=0 || newx > n || newy > n)
                continue;
            if(f[newx][newy][step+1] < f[x][y][step] + t && step != 2){
                
            }
        }
    }
}