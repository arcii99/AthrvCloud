//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define constants
#define G_CONST 6.674 * pow(10, -11)
#define TIME_STEP 0.001
#define NUM_STEPS 10000

// define struct for planets
typedef struct {
    double x;
    double y;
    double z;
    double mass;
    double velocity_x;
    double velocity_y;
    double velocity_z;
} planet;

// calculate distance between two planets
double distance(planet p1, planet p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// calculate force between two planets
double force(planet p1, planet p2) {
    double dist = distance(p1, p2);
    double force_mag = (G_CONST * p1.mass * p2.mass) / (dist * dist);
    return force_mag;
}

// simulate gravity
void simulate_gravity(int num_planets, planet *planets) {
    int i, j, step;
    double fx, fy, fz, ax, ay, az;

    // loop over time steps
    for (step = 0; step < NUM_STEPS; step++) {
        // loop over planets
        for (i = 0; i < num_planets; i++) {
            // calculate acceleration due to all other planets
            ax = 0.0;
            ay = 0.0;
            az = 0.0;
            for (j = 0; j < num_planets; j++) {
                if (i != j) {
                    fx = force(planets[i], planets[j]);
                    fy = force(planets[i], planets[j]);
                    fz = force(planets[i], planets[j]);
                    ax += fx / planets[i].mass;
                    ay += fy / planets[i].mass;
                    az += fz / planets[i].mass;
                }
            }

            // update velocity and position
            planets[i].velocity_x += ax * TIME_STEP;
            planets[i].velocity_y += ay * TIME_STEP;
            planets[i].velocity_z += az * TIME_STEP;
            planets[i].x += planets[i].velocity_x * TIME_STEP;
            planets[i].y += planets[i].velocity_y * TIME_STEP;
            planets[i].z += planets[i].velocity_z * TIME_STEP;
        }
    }
}

// main function
int main() {
    // initialize planets
    int num_planets = 3;
    planet *planets = malloc(num_planets * sizeof(planet));
    planets[0] = (planet){0.0, 0.0, 0.0, 5.97 * pow(10, 24), 0.0, 0.0, 0.0};
    planets[1] = (planet){0.0, 6371 * pow(10, 3), 0.0, 7.34 * pow(10, 22), 1020.0, 0.0, 0.0};
    planets[2] = (planet){0.0, -6371 * pow(10, 3), 0.0, 7.34 * pow(10, 22), -1020.0, 0.0, 0.0};

    // simulate gravity
    simulate_gravity(num_planets, planets);

    // print final positions
    printf("Final positions:\n");
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: x=%f, y=%f, z=%f\n", i+1, planets[i].x, planets[i].y, planets[i].z);
    }

    // free memory
    free(planets);

    return 0;
}