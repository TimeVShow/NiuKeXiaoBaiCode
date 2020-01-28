#include <cstdio>
#include <queue>
using namespace std;
const int base = 20010905;
int n,m;
int res[100006] = {0};
int num[100006] = {0};

queue<int> ma[100007],q;

void input(){
    scanf("%d%d",&n,&m);
    int a,b,c;
    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&a,&b,&c);
        ma[a].push(b);
        num[b]++;
    }
}

void work(){
    q.push(1);
    res[1] = 1;
    while(q.size()){
        int x = q.front();
        q.pop();
        while(ma[x].size()){
            int y = ma[x].front();
            ma[x].pop();
            num[y]--;
            res[y] = (res[y] % base + res[x] % base) % base;
            if(!num[y]){
                q.push(y);
            }
        }
    }
}

void output(){
    printf("%d\n",res[n]);
}

int main(){
    input();
    work();
    output();
    return 0;
}
