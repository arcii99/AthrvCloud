//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 8 //number of planets in the simulation
#define G_CONST 6.67430e-11 //gravitational constant

//structure to store planet data
typedef struct planet {
    char name[25];
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

//function to calculate gravitational force between two planets
void calculate_force(Planet *p1, Planet *p2, double *fx, double *fy, double *fz) {
    double dx, dy, dz, r, f;
    dx = p2->x - p1->x;
    dy = p2->y - p1->y;
    dz = p2->z - p1->z;
    r = sqrt(dx*dx + dy*dy + dz*dz);
    f = G_CONST * p1->mass * p2->mass / (r*r);
    *fx = f*dx / r;
    *fy = f*dy / r;
    *fz = f*dz / r;
}

int main() {
    Planet planets[NUM_PLANETS];
    double fx, fy, fz;
    int i, j, t;
    double dt = 86400.0; //time step (1 day)
    
    //define planet data
    strcpy(planets[0].name, "Sun");
    planets[0].mass = 1.989e30;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;
    
    strcpy(planets[1].name, "Mercury");
    planets[1].mass = 0.33e24;
    planets[1].x = 0;
    planets[1].y = 5.79e10;
    planets[1].z = 0;
    planets[1].vx = 4.74e4;
    planets[1].vy = 0;
    planets[1].vz = 0;
    
    strcpy(planets[2].name, "Venus");
    planets[2].mass = 4.87e24;
    planets[2].x = 0;
    planets[2].y = 1.08e11;
    planets[2].z = 0;
    planets[2].vx = 3.50e4;
    planets[2].vy = 0;
    planets[2].vz = 0;
    
    strcpy(planets[3].name, "Earth");
    planets[3].mass = 5.97e24;
    planets[3].x = 0;
    planets[3].y = 1.50e11;
    planets[3].z = 0;
    planets[3].vx = 2.98e4;
    planets[3].vy = 0;
    planets[3].vz = 0;
    
    strcpy(planets[4].name, "Mars");
    planets[4].mass = 0.64e24;
    planets[4].x = 0;
    planets[4].y = 2.28e11;
    planets[4].z = 0;
    planets[4].vx = 2.41e4;
    planets[4].vy = 0;
    planets[4].vz = 0;
    
    strcpy(planets[5].name, "Jupiter");
    planets[5].mass = 1.90e27;
    planets[5].x = 0;
    planets[5].y = 7.78e11;
    planets[5].z = 0;
    planets[5].vx = 1.31e4;
    planets[5].vy = 0;
    planets[5].vz = 0;
    
    strcpy(planets[6].name, "Saturn");
    planets[6].mass = 5.68e26;
    planets[6].x = 0;
    planets[6].y = 1.43e12;
    planets[6].z = 0;
    planets[6].vx = 9.69e3;
    planets[6].vy = 0;
    planets[6].vz = 0;
    
    strcpy(planets[7].name, "Uranus");
    planets[7].mass = 8.68e25;
    planets[7].x = 0;
    planets[7].y = 2.87e12;
    planets[7].z = 0;
    planets[7].vx = 6.80e3;
    planets[7].vy = 0;
    planets[7].vz = 0;
    
    //simulation loop
    for (t=0; t<365*10; t++) { //simulate for 10 years
        //calculate forces between all pairs of planets
        for (i=0; i<NUM_PLANETS; i++) {
            for (j=i+1; j<NUM_PLANETS; j++) {
                calculate_force(&planets[i], &planets[j], &fx, &fy, &fz);
                planets[i].vx += fx / planets[i].mass * dt;
                planets[i].vy += fy / planets[i].mass * dt;
                planets[i].vz += fz / planets[i].mass * dt;
                planets[j].vx -= fx / planets[j].mass * dt;
                planets[j].vy -= fy / planets[j].mass * dt;
                planets[j].vz -= fz / planets[j].mass * dt;
            }
        }
        //update positions of all planets
        for (i=0; i<NUM_PLANETS; i++) {
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
            planets[i].z += planets[i].vz * dt;
        }
    }
    //print final positions of planets
    for (i=0; i<NUM_PLANETS; i++) {
        printf("%s: (%.2f, %.2f, %.2f)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }
    return 0;
}