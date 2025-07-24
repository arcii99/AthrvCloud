//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.674e-11 
#define NUM_PLANETS 6 
#define TIMESTEP 60.0 

struct planet {
    char name[32];
    double mass;
    double x;
    double y;
    double vx;
    double vy;
    double ax;
    double ay;
};

int main() {
    srand(time(NULL));
    
    struct planet planets[NUM_PLANETS] = {
        {"Sun", 1.989e30, 0, 0, 0, 0, 0, 0},
        {"Mercury", 3.285e23, 5.791e10, 0, 0, 47600, 0, 0},
        {"Venus", 4.867e24, 1.082e11, 0, 0, 35000, 0, 0},
        {"Earth", 5.972e24, 1.496e11, 0, 0, 29780, 0, 0},
        {"Mars", 6.390e23, 2.279e11, 0, 0, 24140, 0, 0},
        {"Jupiter", 1.898e27, 7.785e11, 0, 0, 13070, 0, 0}
    };
    
    int i, j;
    double fx, fy, r, s, ax, ay;
    
    for (i = 0; i < NUM_PLANETS; i++) {
        printf("\nPlanet %s:\n", planets[i].name);
        printf("Mass: %e kg\n", planets[i].mass);
        printf("Position (x, y): (%e, %e) m\n", planets[i].x, planets[i].y);
        printf("Velocity (vx, vy): (%e, %e) m/s\n", planets[i].vx, planets[i].vy);
        printf("\n");
    }
    
    for (s = 0; s < 31536000; s += TIMESTEP) {
        for (i = 0; i < NUM_PLANETS; i++) {
            ax = 0;
            ay = 0;
            for (j = 0; j < NUM_PLANETS; j++) {
                if (i != j) {
                    r = sqrt(pow(planets[j].x - planets[i].x, 2) + pow(planets[j].y - planets[i].y, 2));
                    fx = G * planets[i].mass * planets[j].mass / pow(r, 2) * (planets[j].x - planets[i].x)/r;
                    fy = G * planets[i].mass * planets[j].mass / pow(r, 2) * (planets[j].y - planets[i].y)/r;
                    ax += fx / planets[i].mass;
                    ay += fy / planets[i].mass;
                }
            }
            planets[i].ax = ax;
            planets[i].ay = ay;
        }
        
        for (i = 0; i < NUM_PLANETS; i++) {
            planets[i].vx += planets[i].ax * TIMESTEP;
            planets[i].vy += planets[i].ay * TIMESTEP;
            planets[i].x += planets[i].vx * TIMESTEP;
            planets[i].y += planets[i].vy * TIMESTEP;
        }
    }
    
    printf("\n\nUpdated positions and velocities after 1 Earth year:\n");
    for (i = 0; i < NUM_PLANETS; i++) {
        printf("\nPlanet %s:\n", planets[i].name);
        printf("Position (x, y): (%e, %e) m\n", planets[i].x, planets[i].y);
        printf("Velocity (vx, vy): (%e, %e) m/s\n", planets[i].vx, planets[i].vy);
        printf("\n");
    }
    
    return 0;
}