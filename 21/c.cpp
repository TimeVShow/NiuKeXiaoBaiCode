#include <cstdio>
long long t1;
long long t2;

void work(){
    long long  ans;
    long long int res1 = t2 % 60;
    if(res1 > 50){
        res1 = 50;
    }
    t2 = t2 / 60;
    long long int res2 = t1 % 60;
    t1 = t1 / 60 + 1;
    if(t2 < t1){
        ans = res1 - res2 + 1;
    }
    else{
        if(res2 > 50){
            res2 = 0;
        }else{
            res2 = 50 - res2 + 1;
        }
        ans = (t2 - t1) * 50 + res2 + res1;
    }
    printf("%lld\n",ans);
}

void input(){
    while(scanf("%lld%lld",&t1,&t2) != EOF){
        work();
    }
}

int main(){
    input();
    return 0;
}
