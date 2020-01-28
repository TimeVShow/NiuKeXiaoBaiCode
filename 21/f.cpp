#include <cstdio>
int s[2097];
int main(){
    int old;
    int now;
    while(1){
        old = now;
        char c = getchar();
        if(c == '\n'){
            if(old % 2 == 0){
                printf("1");
            }else{
                printf("-1");
            }
            break;
        }
        now = c - '0';
    }
    return 0;
}
