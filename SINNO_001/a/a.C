#include<stdio.h>

int main(){
    int n;
    long long k;
    scanf("%d %lld",&n,&k);
    long long num=0,c=10;
    int count=0;
    for (int i=1; i<=n; i++){
        if(i-c >= 0) c*=10;
        num=(num*c+i);
        num%=k;
        if (num==0) count++;
    }
    printf("%d",count);
    return 0;
}