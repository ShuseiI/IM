nclude <stdio.h>
#include <stdlib.h>
#include <math.h>
struct robo{
        double x,y;
        double v,vx,vy,dx,dy;
        double th;
        double w;
        double sx,sy;
}
main(){
        short n,i,k;
        k=5;
        n=2;
        struct robo drone[n];
        double t,tmax,dt,pi,ram1,ram2,dram;
        srand(100);
        ram2=0;
        tmax=1;
        t=0.0;
        dt=0.1;
        pi=3.1415;
        drone[0].dx=0.0;
        drone[0].dy=0.0;
        drone[0].v=5;
        drone[0].th=0.0;
        drone[0].w=pi/2.0;
        drone[1].dx=-3.0;
        drone[1].dy=0.0;
        drone[1].v=10;
        drone[1].th=0;
        drone[1].w=0;
        printf("%lf %lf %lf %lf\n",drone[0].dx,drone[0].dy,drone[1].dx,drone[1].dy);
        drone[0].th=drone[0].th+(drone[0].w+(rand()/(double)RAND_MAX)*5)*dt;
        drone[0].vx=drone[0].v*sin(drone[0].th);
        drone[0].vy=drone[0].v*cos(drone[0].th);
        drone[0].x=drone[0].x+drone[0].vx;
        drone[0].y=drone[0].y+drone[0].vy;
        for(i=1;i<=10;i++){
                drone[1].vx=drone[0].x-drone[1].dx;
                drone[1].vy=drone[0].y-drone[1].dy;
                ram1=atan2(drone[1].vy,drone[1].vx);
                drone[0].th=drone[0].th+(drone[0].w+(rand()/(double)RAND_MAX)*5)*dt;
                drone[0].vx=drone[0].v*sin(drone[0].th);
                drone[0].vy=drone[0].v*cos(drone[0].th);
                drone[1].vx=drone[0].x-drone[1].dx;
                drone[1].vy=drone[0].y-drone[1].dy;
                ram1=atan2(drone[1].vy,drone[1].vx);
                drone[0].x=drone[0].x+drone[0].vx;
                drone[0].y=drone[0].y+drone[0].vy;
                drone[1].sx=drone[0].x-drone[1].dx;
                drone[1].sy=drone[0].y-drone[1].dy;
                ram2=atan2(drone[1].sy,drone[1].sx);
                printf("%lf %lf %lf %lf ",drone[0].x,drone[0].y,drone[1].dx,drone[1].dy);
                dram=(ram2-ram1)/dt;
                drone[1].w=k*dram;
                drone[1].th=drone[1].w*dt;
                drone[1].dx=drone[1].dx+drone[1].v*cos(drone[1].th);
                drone[1].dy=drone[1].dy+drone[1].v*sin(drone[1].th);
                drone[1].th=drone[1].th/6.2831*360;
                printf("%lf",drone[1].th);
                printf("\n");
                }
        }




