//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_BODIES 10
#define GRAV_CONST 6.6743E-11
#define MAX_WARP_SPEED 9.9

struct Body {
    char name[20];
    double mass;
    double x, y, z;
    double vx, vy, vz;
};

int main() {
    srand(time(NULL));

    // Initialize bodies
    struct Body bodies[MAX_BODIES];
    int num_bodies = 0;

    strcpy(bodies[num_bodies].name, "Earth");
    bodies[num_bodies].mass = 5.972E24;
    bodies[num_bodies].x = 0;
    bodies[num_bodies].y = 0;
    bodies[num_bodies].z = 0;
    bodies[num_bodies].vx = 0;
    bodies[num_bodies].vy = 0;
    bodies[num_bodies].vz = 0;
    num_bodies++;

    strcpy(bodies[num_bodies].name, "Moon");
    bodies[num_bodies].mass = 7.342E22;
    bodies[num_bodies].x = 384400000;
    bodies[num_bodies].y = 0;
    bodies[num_bodies].z = 0;
    bodies[num_bodies].vx = 0;
    bodies[num_bodies].vy = 1023.055;
    bodies[num_bodies].vz = 0;
    num_bodies++;

    // Add random bodies
    while (num_bodies < MAX_BODIES) {
        double r = ((double) rand() / RAND_MAX) * 1E11;
        double theta = ((double) rand() / RAND_MAX) * 2 * M_PI;
        double phi = ((double) rand() / RAND_MAX) * M_PI;

        strcpy(bodies[num_bodies].name, "");
        for (int i = 0; i < 5; i++) {
            bodies[num_bodies].name[i] = 65 + rand() % 26;
        }

        bodies[num_bodies].mass = ((double) rand() / RAND_MAX) * 1E28;
        bodies[num_bodies].x = r * sin(phi) * cos(theta);
        bodies[num_bodies].y = r * sin(phi) * sin(theta);
        bodies[num_bodies].z = r * cos(phi);
        bodies[num_bodies].vx = ((double) rand() / RAND_MAX) * MAX_WARP_SPEED * pow(rand() % 2 == 0 ? -1 : 1, rand());
        bodies[num_bodies].vy = ((double) rand() / RAND_MAX) * MAX_WARP_SPEED * pow(rand() % 2 == 0 ? -1 : 1, rand());
        bodies[num_bodies].vz = ((double) rand() / RAND_MAX) * MAX_WARP_SPEED * pow(rand() % 2 == 0 ? -1 : 1, rand());

        num_bodies++;
    }

    // Run simulation
    int num_steps = 10000;
    double dt = 1000;
    for (int step = 0; step < num_steps; step++) {
        for (int i = 0; i < num_bodies; i++) {
            double ax = 0;
            double ay = 0;
            double az = 0;

            for (int j = 0; j < num_bodies; j++) {
                if (i == j) continue;

                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double dz = bodies[j].z - bodies[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);
                double f = GRAV_CONST * bodies[i].mass * bodies[j].mass / (r * r);

                ax += f * dx / r / bodies[i].mass;
                ay += f * dy / r / bodies[i].mass;
                az += f * dz / r / bodies[i].mass;
            }

            bodies[i].vx += ax * dt;
            bodies[i].vy += ay * dt;
            bodies[i].vz += az * dt;
        }

        for (int i = 0; i < num_bodies; i++) {
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
            bodies[i].z += bodies[i].vz * dt;
        }
    }

    // Print results
    for (int i = 0; i < num_bodies; i++) {
        printf("%s: (%f, %f, %f)\n", bodies[i].name, bodies[i].x, bodies[i].y, bodies[i].z);
    }

    return 0;
}