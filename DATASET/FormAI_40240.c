//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11    // gravitational constant
#define DT 1.0        // time step
#define STEPS 100000  // number of time steps
#define N 3           // number of planets

struct planet {
    double mass;
    double x_pos;
    double y_pos;
    double x_vel;
    double y_vel;
};

int main() {

    struct planet planets[N];

    // initialize the planets
    planets[0].mass = 5.97e24;    // mass of earth
    planets[0].x_pos = 0.0;
    planets[0].y_pos = 0.0;
    planets[0].x_vel = 0.0;
    planets[0].y_vel = 0.0;

    planets[1].mass = 7.34e22;    // mass of moon
    planets[1].x_pos = 3.84e8;    // distance from earth
    planets[1].y_pos = 0.0;
    planets[1].x_vel = 0.0;
    planets[1].y_vel = 1022.0;    // orbital velocity

    planets[2].mass = 6.39e23;    // mass of mars
    planets[2].x_pos = 2.27e11;   // distance from earth
    planets[2].y_pos = 0.0;
    planets[2].x_vel = 0.0;
    planets[2].y_vel = 24000.0;   // orbital velocity

    int i, j, k;
    double r, f, fx, fy, ax, ay;
    for (k = 0; k < STEPS; k++) {
        for (i = 0; i < N; i++) {
            fx = fy = 0.0;
            for (j = 0; j < N; j++) {
                if (i != j) {
                    r = sqrt(pow(planets[i].x_pos - planets[j].x_pos, 2) 
                           + pow(planets[i].y_pos - planets[j].y_pos, 2));
                    f = G * planets[i].mass * planets[j].mass / pow(r, 2);
                    fx += f * (planets[j].x_pos - planets[i].x_pos) / r;
                    fy += f * (planets[j].y_pos - planets[i].y_pos) / r;
                }
            }
            ax = fx / planets[i].mass;
            ay = fy / planets[i].mass;
            planets[i].x_vel += ax * DT;
            planets[i].y_vel += ay * DT;
            planets[i].x_pos += planets[i].x_vel * DT;
            planets[i].y_pos += planets[i].y_vel * DT;
        }
    }

    // print the final positions and velocities of the planets
    printf("Final positions:\n");
    for (i = 0; i < N; i++) {
        printf("Planet %d: (%.2e, %.2e)\n", i, planets[i].x_pos, planets[i].y_pos);
    }
    printf("\nFinal velocities:\n");
    for (i = 0; i < N; i++) {
        printf("Planet %d: (%.2e, %.2e)\n", i, planets[i].x_vel, planets[i].y_vel);
    }

    return 0;
}