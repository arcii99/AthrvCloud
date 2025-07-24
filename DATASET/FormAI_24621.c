//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational Constant

struct planet {
    char name[20];
    double mass; // in kilograms
    double x; // position in x-axis
    double y; // position in y-axis
    double z; // position in z-axis
    double vx; // velocity in x-axis
    double vy; // velocity in y-axis
    double vz; // velocity in z-axis
    double ax; // acceleration in x-axis
    double ay; // acceleration in y-axis
    double az; // acceleration in z-axis
};

void calculate_acceleration(struct planet *p1, struct planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz); // distance between two planets
    double force = G * p1->mass * p2->mass / pow(distance, 2); // gravitational force between two planets
    p1->ax += force * dx / p1->mass;
    p1->ay += force * dy / p1->mass;
    p1->az += force * dz / p1->mass;
    p2->ax -= force * dx / p2->mass;
    p2->ay -= force * dy / p2->mass;
    p2->az -= force * dz / p2->mass;
}

void update_velocity(struct planet *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

void update_position(struct planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    struct planet planets[] = {
        {"Earth", 5.97e24, 0, 0, 0, 0, 0, 0},
        {"Mars", 6.39e23, 227.9e9, 0, 0, 0, 24.077 * 1000, 0}
    }; // initialize planets with some value
    int num_planets = sizeof(planets) / sizeof(struct planet);
    double dt = 3600; // time step of 1 hour
    int num_iterations = 8760; // simulate for 1 year
    for (int i = 0; i < num_iterations; i++) {
        // reset acceleration for each planet
        for (int j = 0; j < num_planets; j++) {
            planets[j].ax = 0;
            planets[j].ay = 0;
            planets[j].az = 0;
        }
        // calculate acceleration for each pair of planets
        for (int j = 0; j < num_planets; j++) {
            for (int k = j+1; k < num_planets; k++) {
                calculate_acceleration(&planets[j], &planets[k]);
            }
        }
        // update velocity and position for each planet
        for (int j = 0; j < num_planets; j++) {
            update_velocity(&planets[j], dt);
            update_position(&planets[j], dt);
        }
        // print out the position of each planet at the end of each year
        if ((i+1) % 8760 == 0) {
            printf("Year %d:\n", (i+1)/8760);
            for (int j = 0; j < num_planets; j++) {
                printf("%s: (%.2e, %.2e, %.2e) meters\n", planets[j].name, planets[j].x, planets[j].y, planets[j].z);
            }
        }
    }
    return 0;
}