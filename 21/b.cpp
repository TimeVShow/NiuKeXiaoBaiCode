#include <cstdio>
#include <stack>
using namespace std;

char map[103][103];
int n;
int w[13];
stack<int> s[3],temp;

void input(){
    scanf("%d",&n);
}

void output(int n){
    int x = n + 2;
    int y = 3 * (2 * n + 1) + 4;
    for(int i = 0;i < x;i++){
        for(int j = 0;j < y;j++){
            map[i][j] = '.';
        }
    }
    int now = n + 1;
    for(int i = 0;i < 3;i++){
        for(int j = 1;j < x;j++){
            map[j][now] = '|';
            while(s[i].size()){
                temp.push(s[i].top());
                s[i].pop();
            }
            int tot = n + 1;
            while(temp.size()){
                int x = temp.top();
                for(int l = now - x;l <= now + x;l++){
                    map[tot][l] = '*';
                }
                tot--;
                s[i].push(x);
                temp.pop();
            }
        }
        now += 2 * n + 1;
    }
    for(int i = 0;i < x;i++){
        for(int j = 0;j < y;j++){
            putchar(map[i][j]);
        }
        puts("");
    }
}

void split(){
    int y = 3 * (2 * n + 1) + 4;
    for(int i =  0;i < y;i++){
        printf("-");
    }
    puts("");
}

void work(){
    for(int i = n;i >= 1;i--){
        s[0].push(i);
        w[i] = 0;
    }
    output(n);
    int p = (1 << n) - 1; 
    for(int i = 1;i <= p;i++){
        split();
        int num;
        for(int j = 0;j < n;j++){
            if(i & (1 << j)){
                num = j;
                break;
            }
        }
        num++;
        for(int j = 1;j <=2 ;j++){
            if(!s[(w[num] + j) % 3].size() || s[(w[num] + j) % 3].top() > num){
                s[(w[num] + j) % 3].pop();
                w[num] = (w[num] + j) % 3;
                s[w[num]].push(num);
                break;
            }
        }
        output(n);
    }
}

int main(){
    input();
    work();
    return 0;
}
