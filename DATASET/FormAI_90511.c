//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: innovative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define GRAV 0.0000000000667 //gravitational constant
#define step 86400 //time step in seconds, 1 day
#define sim_time 31536000 // simulation time in seconds, 1 year

//Defining a structure of the planet
typedef struct{
    char name[20];
    double mass;
    double x, y, z; 
    double vx, vy, vz; 
} Planet;

//Defining a function to calculate the distance between two planets
double distance(Planet p1, Planet p2){
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)+pow(p1.z-p2.z,2));
}

int main(){
    int n;
    printf("Enter the number of planets in the solar system: ");
    scanf("%d",&n);
    Planet p[n];
    double fx[n], fy[n], fz[n];
    //Taking input of planet properties
    for(int i=0; i<n; i++){
        printf("Enter the name of planet %d: ",i+1);
        scanf("%s",p[i].name);
        printf("Enter the mass of planet %d (in kg): ",i+1);
        scanf("%lf",&p[i].mass);
        printf("Enter the initial position of planet %d (in m): ",i+1);
        scanf("%lf %lf %lf",&p[i].x,&p[i].y,&p[i].z);
        printf("Enter the initial velocity of planet %d (in m/s): ",i+1);
        scanf("%lf %lf %lf",&p[i].vx,&p[i].vy,&p[i].vz);
    }
    //Simulation loop
    for(double t=0; t<sim_time; t+=step){
        //Resetting the forces to 0
        for(int i=0; i<n; i++){
            fx[i]=fy[i]=fz[i]=0;
        }
        //Calculating forces between each pair of planets
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double dist = distance(p[i],p[j]);
                double force = GRAV*p[i].mass*p[j].mass/pow(dist,2);
                fx[i]+=(force/dist)*(p[j].x-p[i].x);
                fy[i]+=(force/dist)*(p[j].y-p[i].y);
                fz[i]+=(force/dist)*(p[j].z-p[i].z);
                fx[j]+=(force/dist)*(p[i].x-p[j].x);
                fy[j]+=(force/dist)*(p[i].y-p[j].y);
                fz[j]+=(force/dist)*(p[i].z-p[j].z);
            }
        }
        //Updating the positions and velocities of planets
        for(int i=0; i<n; i++){
            p[i].x += p[i].vx*step + 0.5*fx[i]/p[i].mass*pow(step,2);
            p[i].y += p[i].vy*step + 0.5*fy[i]/p[i].mass*pow(step,2);
            p[i].z += p[i].vz*step + 0.5*fz[i]/p[i].mass*pow(step,2);
            p[i].vx += fx[i]/p[i].mass*step;
            p[i].vy += fy[i]/p[i].mass*step;
            p[i].vz += fz[i]/p[i].mass*step;
        }
    }
    //Printing final positions
    for(int i=0; i<n; i++){
        printf("Final position of planet %s: %lf, %lf, %lf\n",p[i].name,p[i].x,p[i].y,p[i].z);
    }
    return 0;
}