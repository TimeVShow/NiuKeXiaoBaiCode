#include <cstdio>
#include <cstring>
const int n = 7e5 + 7;
const int base = 20010905;
char s[n] = {0};
long long int num[10];
void input(){
    scanf("%s",s);
}

void work(){
    int len = strlen(s);
    for(int i = 0;i < len;i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i] - 'A' + 'a';
        }
        if(s[i] == 'i'){
            num[0] = num[0] + 1;
        }
        if(s[i] == 'l'){
            num[1] += num[0];
        }
        if(s[i] == 'o'){
            num[2] += num[1];
            num[6] += num[5];
        }
        if(s[i] == 'v'){
            num[3] += num[2];
        }
        if(s[i] == 'e'){
            num[4] += num[3];
        }
        if(s[i] == 'y'){
            num[5] += num[4];
        }
        if(s[i] == 'u'){
            num[7] += num[6];
        }
        for(int i = 0;i < 8;i++){
            num[i] %= base;
        }
    }
    printf("%d\n",num[7]);
}

int main(){
    input();
    work();
    return 0;
}