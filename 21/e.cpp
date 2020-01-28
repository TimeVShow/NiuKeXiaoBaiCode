#include <cstdio>
int n;
double course[64][10];
void input(){
   scanf("%d",&n);
   for(int i = 0;i < n;i++){
       for(int j = 0;j < 8;j++){
           scanf("%lf",&course[i][j]);
       }
   }
}

void work(){
    double sum = 0;
    double p;
    double qz;
    double qm;
    double grade[103];
    for(int i = 0;i < n;i++){
        int sumg = 0;
        if(course[i][0] == 2){
            continue;
        }else{
           sum += course[i][1];
           p = course[i][2] * course[i][3];
           qz = course[i][4] * course[i][5];
           qm = course[i][6] * course[i][7] ;
           sumg = p + qz + qm + 0.5;
           grade[i] = sumg * course[i][1];
        }
    }
    double grades = 0;
    for(int i = 0;i < n;i++){
        grades += grade[i] / sum;
    }
    printf("%.2lf\n",grades);
}

int main(){
    input();
    work();
    return 0;
}
