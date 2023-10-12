#include<bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    int c, d;
    cin >> a>>b;
    cin >> c >> d;
    int start1 = a;
    int start2 = c;
    int count = 0;
    while (start1 != 0 || start2 != 0){
        count++;
        start1 = (start1 + 1) % b;  
        start2 = (start2 + 1) % d;  
        if(count >= 5000)
            break;
    }
    if(start1 == start2 && start1 == 0){
        cout<<count;
        return 0;
    }
}