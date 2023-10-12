#include<bits/stdc++.h>

using namespace std;

stack<long long> s;
string c[10005];
int num;

void PostOrder(int n){
    for(int i = n-1; i>=0; i--){
        if(c[i][0] == '+' || c[i][0] == '*' || c[i][0] == '/' || (c[i][0] == '-' && c[i][1] == '\0')){
            long long num1 = s.top();
            s.pop();
            long long num2 = s.top();
            s.pop();
            if(c[i][0] == '+')
                s.push(num1+ num2);
            else if(c[i][0] == '-')
                s.push(num1- num2);
            else if(c[i][0] == '*')
                s.push(num1* num2);
            else if(c[i][0] == '/')
                s.push(num1/ num2);
            continue;
        }
        int num = 0;
        for(int j = 0; j<c[i].size(); j++){
            if(c[i][0] == '-' && j == 0)
                continue;
            num = num* 10 + (c[i][j] - '0');
        }
        if(c[i][0] == '-')
            num = -num;
        s.push(num);
    }
    cout<<s.top()<<'\n';
    s.pop();
}

void Solve(){
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin>> c[i];
    }
    if(c[1][0] == '+' || c[1][0] == '*' || c[1][0] == '/' || (c[1][0] == '-' && c[1][1] == '\0')){
        PostOrder(n);
        return;
    }
    for(int i = 1; i<=n; i++){
        if(c[i][0] == '+' || c[i][0] == '*' || c[i][0] == '/' || (c[i][0] == '-' && c[i][1] == '\0')){
            long long num1 = s.top();
            s.pop();
            long long num2 = s.top();
            s.pop();
            if(c[i][0] == '+')
                s.push(num2+ num1);
            else if(c[i][0] == '-')
                s.push(num2- num1);
            else if(c[i][0] == '*')
                s.push(num2* num1);
            else if(c[i][0] == '/')
                s.push(num2/ num1);
            continue;
        }
        int num = 0;
        for(int j = 0; j<c[i].size(); j++){
            if(c[i][0] == '-' && j == 0)
                continue;
            num = num* 10 + (c[i][j] - '0');
        }
        if(c[i][0] == '-')
            num = -num;
        s.push(num);
    }
    cout<<s.top()<<'\n';
    s.pop();
}

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test;
    cin>>test;
    for(int t= 1; t<=test; t++){
        Solve();
    }
    return 0;
}