#include<bits/stdc++.h>

using namespace std;

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int ans = 0;
    int n;
    long long k;
    cin>>n>>k;
    long long cur = 0;
    long long modul = 1;
    for(int i = 1; i<=n; i++){
        if(i < 1000000) modul = 1000000;
        if(i < 100000) modul = 100000;
        if(i < 10000) modul = 10000;
        if(i < 1000) modul = 1000;
        if(i < 100) modul = 100;
        if(i < 10) modul = 10;
        cur = cur*modul + i;
        cur %= k;
        if(cur == 0)
            ans++;
    }
    cout<<ans;
}