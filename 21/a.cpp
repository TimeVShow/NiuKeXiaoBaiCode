#include <cstdio>
double x[3];
double y[3];
void input(){
    for(int i = 0;i < 3;i++){
        scanf("%lf%lf",&x[i],&y[i]);
    }
}
void work(){
    double a1 = 2*(x[1] - x[0]);
    double b1 = 2*(y[1] - y[0]);
    double c1 = x[1] * x[1] + y[1] * y[1] - x[0] * x[0] - y[0] * y[0];
    double a2 = 2*(x[2] - x[1]);
    double b2 = 2*(y[2] - y[1]);
    double c2 = x[2] * x[2] + y[2] * y[2] - x[1] * x[1] - y[1] * y[1];
    double resx = (c1 * b2 - c2 * b1)*1.0 / (a1 * b2 - a2 * b1);
    double resy = (a1 * c2 -a2 * c1)*1.0 / (a1 * b2 - a2 * b1);
    printf("%.3lf %.3lf",resx,resy);
}

int main(){
    input();
    work();
    return 0;
}