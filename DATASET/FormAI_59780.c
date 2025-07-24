//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: decentralized
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant
#define SCALE_FACTOR 2000.0 // scales the distances to fit on screen

#define NUM_PLANETS 3 // number of planets in the system
#define NUM_STEPS 5000 // number of simulation steps
#define TIME_STEP 1000 // time step for simulation in seconds

struct planet {
    char name[20];
    double mass; // in kilograms
    double x; // x coordinate position in meters
    double y; // y coordinate position in meters
    double vx; // x component of velocity in m/s
    double vy; // y component of velocity in m/s
};

// function to calculate distance between two planets
double distance(struct planet p1, struct planet p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    struct planet planets[NUM_PLANETS] = {
        {"Sun", 1.989e30, 0, 0, 0, 0},
        {"Earth", 5.97e24, 1.496e11, 0, 0, 29783.0},
        {"Mars", 6.39e23, 2.279e11, 0, 0, 24007.0},
    };

    // simulation loop
    for (int step = 0; step < NUM_STEPS; step++) {
        // calculate net force on each planet
        for (int i = 0; i < NUM_PLANETS; i++) {
            double fnet_x = 0;
            double fnet_y = 0;
            for (int j = 0; j < NUM_PLANETS; j++) {
                if (i == j) continue;
                double d = distance(planets[i], planets[j]);
                double f = G * planets[i].mass * planets[j].mass / (d*d);
                double fx = f * (planets[j].x - planets[i].x) / d;
                double fy = f * (planets[j].y - planets[i].y) / d;
                fnet_x += fx;
                fnet_y += fy;
            }
            // update velocity and position using net force
            planets[i].vx += fnet_x / planets[i].mass * TIME_STEP;
            planets[i].vy += fnet_y / planets[i].mass * TIME_STEP;
            planets[i].x += planets[i].vx * TIME_STEP;
            planets[i].y += planets[i].vy * TIME_STEP;
        }
        // print out current positions of planets
        printf("Step %d:\n", step+1);
        for (int i = 0; i < NUM_PLANETS; i++) {
            printf("%s: x = %f, y = %f\n", planets[i].name, planets[i].x/SCALE_FACTOR, planets[i].y/SCALE_FACTOR);
        }
    }
    return 0;
}