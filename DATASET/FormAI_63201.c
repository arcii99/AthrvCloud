//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67430e-11 /* Gravitational constant */
#define AU 1.495978707e11 /* Astronomical unit in meters */
#define M_SUN 1.98847e30 /* Mass of the Sun in kilograms */
#define M_EARTH 5.9722e24 /* Mass of the Earth in kilograms */
#define M_MARS 6.4171e23 /* Mass of Mars in kilograms */

/* A structure to hold information about a celestial body */
typedef struct {
    char name[20];
    double mass; /* in kilograms */
    double x, y; /* position in meters */
    double vx, vy; /* velocity in meters per second */
} Body;

/* Function to calculate the distance between two points */
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    srand(time(NULL)); /* Seed the random number generator */
    
    /* Define some constants for the simulation */
    double timestep = 3600*24; /* Step size in seconds */
    int nsteps = 365; /* Number of steps to simulate */
    int nplanets = 3; /* Number of planets in the simulation */
    
    /* Create an array of Body structs for the planets */
    Body planets[3];
    strcpy(planets[0].name, "Sun");
    planets[0].mass = M_SUN;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    strcpy(planets[1].name, "Earth");
    planets[1].mass = M_EARTH;
    planets[1].x = AU;
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = 30e3;
    strcpy(planets[2].name, "Mars");
    planets[2].mass = M_MARS;
    planets[2].x = -1.52*AU;
    planets[2].y = 0;
    planets[2].vx = 0;
    planets[2].vy = -24.077e3;

    /* Loop over the simulation steps */
    for (int step = 0; step < nsteps; step++) {
        /* Print the positions of each planet */
        printf("Step %d:\n", step);
        for (int i = 0; i < nplanets; i++) {
            printf("%s: (%.2f, %.2f)\n", planets[i].name, planets[i].x/AU, planets[i].y/AU);
        }
        printf("\n");
        
        /* Loop over all pairs of planets in the simulation */
        for (int i = 0; i < nplanets; i++) {
            for (int j = i+1; j < nplanets; j++) {
                /* Calculate the distance between the two planets */
                double r = distance(planets[i].x, planets[i].y, planets[j].x, planets[j].y);
                
                /* Calculate the magnitude of the gravitational force between the two planets */
                double f = G*planets[i].mass*planets[j].mass/(r*r);
                
                /* Calculate the x and y components of the gravitational force */
                double fx = f*(planets[j].x - planets[i].x)/r;
                double fy = f*(planets[j].y - planets[i].y)/r;
                
                /* Add the x and y components of the force to the velocity of each planet */
                planets[i].vx += fx/planets[i].mass*timestep;
                planets[i].vy += fy/planets[i].mass*timestep;
                planets[j].vx -= fx/planets[j].mass*timestep;
                planets[j].vy -= fy/planets[j].mass*timestep;
            }
        }
        
        /* Update the positions of each planet based on their new velocities */
        for (int i = 0; i < nplanets; i++) {
            planets[i].x += planets[i].vx*timestep;
            planets[i].y += planets[i].vy*timestep;
        }
    }
    
    return 0;
}