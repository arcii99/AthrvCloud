//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // universal gravitational constant
#define DELTA_T 100000 // time step
#define STEPS 2000 // number of steps
#define SCALE_FACTOR 5e-11 // scale factor for simulation display

// define a structure for the celestial bodies
typedef struct celestial_body {
    char name[50];
    double mass; // in kg
    double x, y; // position in m
    double vx, vy; // velocity in m/s
} celestial_body_t;

// define a function to compute the gravitational force between two celestial bodies
void compute_gravitational_force(celestial_body_t *a, celestial_body_t *b, double *fx, double *fy) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double r_squared = dx*dx + dy*dy;
    double r = sqrt(r_squared);

    double f = G * a->mass * b->mass / r_squared;

    *fx = f * dx / r;
    *fy = f * dy / r;
}

int main() {
    // define the celestial bodies
    celestial_body_t sun = {"Sun", 1.989e30, 0, 0, 0, 0};
    celestial_body_t earth = {"Earth", 5.972e24, 147e9, 0, 0, 30.3e3};

    // print the initial conditions
    printf("Initial conditions:\n");
    printf("%s mass: %e kg\n", sun.name, sun.mass);
    printf("%s mass: %e kg\n", earth.name, earth.mass);
    printf("%s position: (%e m, %e m)\n", sun.name, sun.x, sun.y);
    printf("%s velocity: (%e m/s, %e m/s)\n", earth.name, earth.vx, earth.vy);

    // simulate the motion of the celestial bodies
    for (int i = 0; i < STEPS; i++) {
        double fx, fy; // force variables

        compute_gravitational_force(&sun, &earth, &fx, &fy);

        // update the velocity and position of earth
        earth.vx += fx / earth.mass * DELTA_T;
        earth.vy += fy / earth.mass * DELTA_T;
        earth.x += earth.vx * DELTA_T;
        earth.y += earth.vy * DELTA_T;

        // print the updated position of earth every 100 steps
        if (i % 100 == 0) {
            printf("%s position at step %d: (%e m, %e m)\n", earth.name, i, earth.x, earth.y);
        }
    }

    // print the final position and velocity of earth
    printf("Final position of %s: (%e m, %e m)\n", earth.name, earth.x, earth.y);
    printf("Final velocity of %s: (%e m/s, %e m/s)\n", earth.name, earth.vx, earth.vy);
    
    // return 0 to indicate success
    return 0;
}