//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: invasive
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67430e-11 //Universal gravitational constant
#define numPlanets 8 //Number of planets in the solar system

struct planet{
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double mass;
};

void initializePlanets(struct planet *p){
    int i;
    //Sun
    p[0].x = 0;
    p[0].y = 0;
    p[0].z = 0;
    p[0].vx = 0;
    p[0].vy = 0;
    p[0].vz = 0;
    p[0].mass = 1.989e30;
    //Mercury
    p[1].x = 0.3871e11;
    p[1].y = 0;
    p[1].z = 0;
    p[1].vx = 0;
    p[1].vy = 4.79e4;
    p[1].vz = 0;
    p[1].mass = 0.33e24;
    //Venus
    p[2].x = 0;
    p[2].y = 0.7233e11;
    p[2].z = 0;
    p[2].vx = 3.502e4;
    p[2].vy = 0;
    p[2].vz = 0;
    p[2].mass = 4.87e24;
    //Earth
    p[3].x = 1.496e11;
    p[3].y = 0;
    p[3].z = 0;
    p[3].vx = 0;
    p[3].vy = 2.9783e4;
    p[3].vz = 0;
    p[3].mass = 5.97e24;
    //Mars
    p[4].x = 0;
    p[4].y = 0;
    p[4].z = 1.524e11;
    p[4].vx = 2.41e4;
    p[4].vy = 0;
    p[4].vz = 0;
    p[4].mass = 0.642e24;
    //Jupiter
    p[5].x = 0;
    p[5].y = 0;
    p[5].z = 5.203e11;
    p[5].vx = 13.07e3;
    p[5].vy = 0;
    p[5].vz = 0;
    p[5].mass = 1898e24;
    //Saturn
    p[6].x = 0;
    p[6].y = 0;
    p[6].z = 9.54e11;
    p[6].vx = 9.68e3;
    p[6].vy = 0;
    p[6].vz = 0;
    p[6].mass = 568e24;
    //Uranus
    p[7].x = 0;
    p[7].y = 0;
    p[7].z = 19.19e11;
    p[7].vx = 6.80e3;
    p[7].vy = 0;
    p[7].vz = 0;
    p[7].mass = 86.8e24;
}

void updatePosition(struct planet *p, double dt){
    int i, j;
    double fx, fy, fz, r, F;
    for(i=0; i<numPlanets; i++){
        fx = fy = fz = 0;
        for(j=0; j<numPlanets; j++){
            if(i!=j){
                r = sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)+(p[i].z-p[j].z)*(p[i].z-p[j].z));
                F = G*((p[i].mass*p[j].mass)/(r*r));
                fx += F*(p[j].x-p[i].x)/r;
                fy += F*(p[j].y-p[i].y)/r;
                fz += F*(p[j].z-p[i].z)/r;
            }
        }
        p[i].vx += fx*dt/p[i].mass;
        p[i].vy += fy*dt/p[i].mass;
        p[i].vz += fz*dt/p[i].mass;
        p[i].x += p[i].vx*dt;
        p[i].y += p[i].vy*dt;
        p[i].z += p[i].vz*dt;
    }
}

int main(){
    int i, j;
    double dt = 86400; //Timestep in seconds (1 day)
    double t = 0; //Elapsed time in seconds
    struct planet planets[numPlanets];
    initializePlanets(planets);
    printf("Starting simulation...\n");
    while(t<31536000*10){ //10 years
        updatePosition(planets, dt);
        t += dt;
    }
    printf("Simulation complete.\n");
    return 0;
}