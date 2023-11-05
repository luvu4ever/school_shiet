#include<bits/stdc++.h>
#define f1(i,a) for(int i=1; i<=a; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX_N 100005

using namespace std;

int n, a[MAX_N], q;
int f[22][MAX_N];
long long sum = 0;

int get_min(int l, int r){
    int step = log2(r - l + 1);
    return min(f[step][l], f[step][r - (1<<step) + 1]);
}

main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    f1(i, n){
        cin >> a[i];
        f[0][i] = a[i];
    }
    for(int j = 1; (1<<j) <= n; ++j){
        for(int i = 1; i<=(n- (1 << j) + 1); ++i){
            f[j][i] = min(f[j-1][i], f[j-1][i + (1 << (j-1))]);
        }
    }
    cin >> q;
    while(q--){
        int x, y;
        cin>> x >> y;
        x++, y++;
        sum += get_min(x, y);
    }
    cout<< sum;
    return 0;
}