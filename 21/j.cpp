#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int map[103][103][103] = {{{0}}};
int dx[6]={0,0,-1,1,0,0};
int dy[6]={0,0,0,0,1,-1};
int dz[6]={1,-1,0,0,0,0};
int dis[103][103][103] = {{{0}}};

typedef struct{
    int x;
    int y;
    int z;
}node;

void input(){
    scanf("%d",&n);
    getchar();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < n;k++){
                char c = getchar();
                if(c == '*'){
                    map[i][j][k] = 0;
                }else{
                    map[i][j][k] = 1;
                }
                dis[i][j][k] = 0xfffffff;
            }
            getchar();
        }
    }
    dis[0][0][0] = 1;
}

void bfs(int x,int y,int z){
    int index = 0;
    node queue[6];
    for(register int i = 0;i < 6;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        int tz = z + dz[i];
        if(tx >= 0 && tx < n && ty >= 0 && ty < n && tz >= 0 && tz < n){
            if(map[tx][ty][tz] && dis[tx][ty][tz] > dis[x][y][z] + 1){
                dis[tx][ty][tz] = dis[x][y][z] + 1;
                queue[index].x = tx;
                queue[index].y = ty;
                queue[index].z = tz;
                index++;
            }
        }
    }
    for(register int i = 0;i < index;i++){
        int tx = queue[i].x;
        int ty = queue[i].y;
        int tz = queue[i].z;
        bfs(tx,ty,tz);
    }
}

void output(){
    int t = dis[n-1][n-1][n-1];
    if(t != 0x3fff)
        printf("%d\n",t);
    else
        printf("-1\n");
}

int main(){
    input();
    bfs(0,0,0);
    output();
    return 0;
}
