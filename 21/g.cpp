#include <cstdio>

void input(){
    int n;
    scanf("%d",&n);
    int cnt = 0;
    if(n == 1){
        printf("Nancy\n");
    }else{
        for(int i = 2;i <= n;i++){
            while(n % i == 0){
                n /= i;
                cnt++;
            }
        }
        if(cnt % 2 == 0){
            printf("Johnson\n");
        }else{
            printf("Nancy\n");
        }
    }
}

int main(){
    input();
    return 0;
}