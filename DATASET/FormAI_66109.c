//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant
#define DELTA_TIME 1.0 // time interval for simulation
#define SIMULATION_TIME 600.0 // duration of simulation

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double mass; // mass of the planet
} Planet;

// calculates the force between two planets
void calculate_force(Planet *p1, Planet *p2, double *fx, double *fy) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double distance = sqrt(dx*dx + dy*dy); // distance between the planets
    double force = (G * p1->mass * p2->mass) / (distance*distance); // magnitude of the force
    *fx = force * (dx / distance); // x-component of the force
    *fy = force * (dy / distance); // y-component of the force
}

// performs one simulation step
void simulate_step(Planet *planets, int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        double fx = 0.0, fy = 0.0;
        for (int j = 0; j < num_planets; j++) {
            if (i != j) {
                double fx_ij, fy_ij;
                calculate_force(&planets[i], &planets[j], &fx_ij, &fy_ij);
                fx += fx_ij;
                fy += fy_ij;
            }
        }
        double ax = fx / planets[i].mass; // acceleration
        double ay = fy / planets[i].mass;
        planets[i].vx += ax * DELTA_TIME; // update velocity
        planets[i].vy += ay * DELTA_TIME;
        planets[i].x += planets[i].vx * DELTA_TIME; // update position
        planets[i].y += planets[i].vy * DELTA_TIME;
    }
}

int main() {
    Planet planets[] = {
        { .x = 0.0, .y = 0.0, .vx = 0.0, .vy = 0.0, .mass = 5.97e24 }, // earth
        { .x = 0.0, .y = 384400000.0, .vx = 1022.0, .vy = 0.0, .mass = 7.34e22 } // moon
    };
    int num_planets = 2;
    double time = 0.0;
    while (time < SIMULATION_TIME) {
        printf("Time: %.1f seconds\n", time);
        for (int i = 0; i < num_planets; i++) {
            printf("Planet %d: x=%f, y=%f\n", i, planets[i].x, planets[i].y);
        }
        simulate_step(planets, num_planets);
        time += DELTA_TIME;
    }
    return 0;
}