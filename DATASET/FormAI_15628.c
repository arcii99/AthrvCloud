//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: introspective
#include<stdio.h>
#include<math.h>
#define G 6.67e-11 //Gravitational Constant
#define M 5.97e24 //Mass of Earth
#define R 6.37e6 //Radius of Earth
#define dt 60 //Time Step
#define MAX_STEPS 100000 //Max Simulation Steps
struct vector{
    double x,y;
};
int main(){
    int i=0,j=0,steps;
    double F,G_F,r;
    struct vector pos[MAX_STEPS],v[MAX_STEPS],a;
    for(i=0;i<MAX_STEPS;i++){
        pos[i].x=pos[i].y=0;
        v[i].x=v[i].y=0;
    }
    pos[0].x=1.5e11; //Initial X Position of Planet
    v[0].y=3e4; //Initial Y Velocity of Planet
    steps=0;
    while(steps<MAX_STEPS){
        F=G*M/(pow(pos[steps].x,2)+pow(pos[steps].y,2)); //Calculate Gravitational Force
        G_F=G*F; //Calculate Acceleration
        r=sqrt(pow(pos[steps].x,2)+pow(pos[steps].y,2)); //Calculate Distance
        a.x=-G_F*pos[steps].x/(r*M); //Calculate X Acceleration
        a.y=-G_F*pos[steps].y/(r*M); //Calculate Y Acceleration
        pos[steps+1].x=pos[steps].x+v[steps].x*dt; //Calculate X Position
        pos[steps+1].y=pos[steps].y+v[steps].y*dt; //Calculate Y Position
        v[steps+1].x=v[steps].x+a.x*dt; //Calculate X Velocity
        v[steps+1].y=v[steps].y+a.y*dt; //Calculate Y Velocity
        steps++; //Increase Step Counter
    }
    return 0;
}