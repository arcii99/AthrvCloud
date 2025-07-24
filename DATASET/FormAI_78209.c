//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define G 6.67408e-11
#define DELTA_T 0.1

// define a structure for a planet
typedef struct Planet {
    double x;   // x-coordinate
    double y;   // y-coordinate
    double vx;  // velocity in x-direction
    double vy;  // velocity in y-direction
    double m;   // mass
} Planet;

// function to calculate the gravitational force between two planets
void calculate_force(Planet *p1, Planet *p2, double *fx, double *fy) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dist = sqrt(dx * dx + dy * dy);
    double f = G * p1->m * p2->m / (dist * dist);
    *fx = f * dx / dist;
    *fy = f * dy / dist;
}

// function to update the position and velocity of a planet
void update_planet(Planet *p, double fx, double fy) {
    p->vx += fx / p->m * DELTA_T;
    p->vy += fy / p->m * DELTA_T;
    p->x += p->vx * DELTA_T;
    p->y += p->vy * DELTA_T;
}

int main() {
    // declare and initialize planets
    Planet planets[] = {
        {1e11, 0, 0, 30e3, 5.97e24},
        {0, 0, 0, 0, 1.99e30},
        {0, 1.5e11, -30e3, 0, 5.97e24}
    };
    int num_planets = sizeof(planets) / sizeof(planets[0]);
    double forces_x[num_planets][num_planets];
    double forces_y[num_planets][num_planets];

    // calculate initial forces
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < num_planets; i++) {
        for (int j = 0; j < num_planets; j++) {
            if (i != j) {
                double fx, fy;
                calculate_force(&planets[i], &planets[j], &fx, &fy);
                forces_x[i][j] = fx;
                forces_y[i][j] = fy;
            } else {
                forces_x[i][j] = 0;
                forces_y[i][j] = 0;
            }
        }
    }

    // simulate motion of planets
    for (double t = 0; t < 365.25 * 24 * 60 * 60; t += DELTA_T) {
        // calculate forces
        #pragma omp parallel for collapse(2)
        for (int i = 0; i < num_planets; i++) {
            for (int j = 0; j < num_planets; j++) {
                if (i != j) {
                    double fx, fy;
                    calculate_force(&planets[i], &planets[j], &fx, &fy);
                    forces_x[i][j] = fx;
                    forces_y[i][j] = fy;
                } else {
                    forces_x[i][j] = 0;
                    forces_y[i][j] = 0;
                }
            }
        }

        // update positions and velocities
        #pragma omp parallel for
        for (int i = 0; i < num_planets; i++) {
            double fx_total = 0, fy_total = 0;
            for (int j = 0; j < num_planets; j++) {
                if (i != j) {
                    fx_total += forces_x[i][j];
                    fy_total += forces_y[i][j];
                }
            }
            update_planet(&planets[i], fx_total, fy_total);
        }

        // print positions and velocities of all planets
        printf("Time: %.2lf days\n", t / (24 * 60 * 60));
        for (int i = 0; i < num_planets; i++) {
            printf("Planet %d: x = %.2e m, y = %.2e m, vx = %.2e m/s, vy = %.2e m/s\n",
                   i + 1, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
        }
        printf("\n");
    }

    return 0;
}