//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.81
#define MAX_PLANETS 10
#define MAX_TIME 30
#define TIME_STEP 0.5

struct planet {
    double mass;
    double position[3];
    double velocity[3];
};

typedef struct planet Planet;

int num_planets;
Planet planets[MAX_PLANETS];

void addPlanet(double mass, double x, double y, double z, double vx, double vy, double vz) {
    if (num_planets >= MAX_PLANETS) {
        printf("Maximum number of planets reached.");
        return;
    }

    planets[num_planets].mass = mass;
    planets[num_planets].position[0] = x;
    planets[num_planets].position[1] = y;
    planets[num_planets].position[2] = z;
    planets[num_planets].velocity[0] = vx;
    planets[num_planets].velocity[1] = vy;
    planets[num_planets].velocity[2] = vz;

    num_planets++;
}

void updatePositions() {
    for (int i = 0; i < num_planets; i++) {
        for (int j = 0; j < 3; j++) {
            planets[i].position[j] += planets[i].velocity[j] * TIME_STEP;
        }
    }
}

void updateVelocities() {
    for (int i = 0; i < num_planets; i++) {
        double total_fx = 0, total_fy = 0, total_fz = 0;

        for (int j = 0; j < num_planets; j++) {
            if (i != j) {
                double dx = planets[j].position[0] - planets[i].position[0];
                double dy = planets[j].position[1] - planets[i].position[1];
                double dz = planets[j].position[2] - planets[i].position[2];

                double distance = sqrt(dx*dx + dy*dy + dz*dz);
                double force = G * planets[j].mass * planets[i].mass / (distance*distance);

                total_fx += force * dx / distance;
                total_fy += force * dy / distance;
                total_fz += force * dz / distance;
            }
        }

        double ax = total_fx / planets[i].mass;
        double ay = total_fy / planets[i].mass;
        double az = total_fz / planets[i].mass;

        planets[i].velocity[0] += ax * TIME_STEP;
        planets[i].velocity[1] += ay * TIME_STEP;
        planets[i].velocity[2] += az * TIME_STEP;
    }
}

void printPositions(int time_step) {
    printf("\n\nPositions at time step %d\n", time_step);
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: x=%.2f y=%.2f z=%.2f\n", i+1, planets[i].position[0], planets[i].position[1], planets[i].position[2]);
    }
}

int main() {
    addPlanet(100, 0, 0, 0, 0, 0, 0);
    addPlanet(10, 0, 100, 0, 10, 0, 0);

    for (int t = 0; t <= MAX_TIME; t += TIME_STEP) {
        updatePositions();
        updateVelocities();
        printPositions(t);
    }

    return 0;
}