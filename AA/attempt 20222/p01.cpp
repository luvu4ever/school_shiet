#include<bits/stdc++.h>
#define f1(i,a) for(int i=1; i<=a; ++i)
#define f0(i,a) for(int i=0; i<a; ++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX_N 100005
#define el cout<<'\n'
#define oo 1000000009

using namespace std;

typedef struct Information{
    string code, birth, father, mother, is_alive, region;
} in4;

bool in4cmp(in4 x, in4 y){
    return x.birth<=y.birth;
}

bool cmp(string x, string y){
    return x<=y;
}

in4 a[MAX_N];
string bird[MAX_N];
map<string, int> number;
int dis[MAX_N], alive[MAX_N];
int vis[MAX_N];
vector<int> g[MAX_N];
int cnt;

int n = 1;

void Input(){
    int i = 1;
    cin >> a[i].code;
    while(a[i].code[0] != '*'){
        cin>> a[i].birth >> a[i].father >> a[i].mother >> a[i].is_alive >> a[i].region;
        bird[i] = a[i].birth;
        n++;
        cin>>a[++i].code;
    }
    n--;
    // f1(i, n){
    //     cout<< a[i].code,el;
    // }
}

void BFSalive(int s){
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:g[u]){
            if(dis[u]+1 < dis[v] && alive[v]){
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
    return;
}

void BFS(int s){
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v:g[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return;
}

void Prepare(){
    f1(i, n){
        number[a[i].code] = i;
        if(a[i].is_alive == "Y")
            alive[i] = 1;
        else
            alive[i] = 0;
        dis[i] = oo;
    }
    //alive prepare
    f1(i, n){
        if(!alive[number[a[i].father]])
            g[number[a[i].father]].pb(i);
        if(!alive[number[a[i].mother]])
            g[number[a[i].mother]].pb(i);
    }
    f1(i, n){
        if(!alive[number[a[i].mother]] && !alive[number[a[i].father]]){
            BFSalive(i);
        }
    }
}

void Querry(){
    string order;
    cin>> order;
    string o1 = "NUMBER_PEOPLE";
    string o2 = "NUMBER_PEOPLE_BORN_AT";
    string o3 = "MOST_ALIVE_ANCESTOR";
    string o4 = "NUMBER_PEOPLE_BORN_BETWEEN";
    string o5 = "MAX_UNRELATED_PEOPLE";
    while(order[0] != '*'){
        if(o1 == order){
            cout<<n, el;
            cin>>order;
            continue;
        }
        if(o2 == order){
            string date;
            cin>>date;
            int lower = lower_bound(bird+1, bird+n+1, date) - bird;
            int upper = upper_bound(bird+1, bird+n+1, date) - bird-1;
            //int upper = upper_bound(a+1, a+n+1, date, cmp) - a - 1;
            cout<< upper-lower+1, el;
            cin>>order;
            continue;
        }
        if(o3 == order){
            string code;
            cin>> code;
            // cout<<number[code], el;
            cout<<dis[number[code]], el;
            cin>>order;
            continue;
        }
        if(o4 == order){
            string date;
            cin>>date;
            int lower = lower_bound(bird+1, bird+n+1, date) - bird;
            cin>>date;
            int upper = upper_bound(bird+1, bird+n+1, date) - bird-1;
            cout<< upper-lower+1, el;
            cin>>order;
            continue;
        }
        if(o5 == order){
            cout<<cnt,el;
            cin>> order;
            continue;
        }
    }
}

main()
{
    Input();
    sort(a+1, a+n+1, in4cmp);
    sort(bird+1, bird+n+1, cmp);
    // f1(i, n){
    //     cout<< a[i].code,el;
    // }
    Prepare();
    Querry();
    return 0;
}