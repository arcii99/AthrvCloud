//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant
#define TIME_STEP 3600 // Time step in seconds

// Structure to hold information about a planet
typedef struct planet {
    char name[20];
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

// Calculate distance between two planets
double distance(Planet p1, Planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Calculate gravitational force on a planet
void calculate_force(Planet *p1, Planet *p2) {
    double dist = distance(*p1, *p2);
    double force = G * p1->mass * p2->mass / (dist*dist);
    double fx = force * (p2->x - p1->x) / dist;
    double fy = force * (p2->y - p1->y) / dist;
    double fz = force * (p2->z - p1->z) / dist;
    p1->vx += fx * TIME_STEP / p1->mass;
    p1->vy += fy * TIME_STEP / p1->mass;
    p1->vz += fz * TIME_STEP / p1->mass;
}

// Update the position of a planet
void update_position(Planet *p) {
    p->x += p->vx * TIME_STEP;
    p->y += p->vy * TIME_STEP;
    p->z += p->vz * TIME_STEP;
}

int main() {
    // Define planets
    Planet earth = {"Earth", 5.97e24, 0, 0, 0, 0, 0, 0};
    Planet moon = {"Moon", 7.34e22, 384400000, 0, 0, 0, 1022, 0};

    // Simulation loop
    for (int i = 0; i < 24*365; i++) {
        // Calculate gravitational force on each planet
        calculate_force(&earth, &moon);
        calculate_force(&moon, &earth);

        // Update position of each planet
        update_position(&earth);
        update_position(&moon);

        // Print position of Moon every 30 days
        if (i % (30*24) == 0) {
            printf("Moon position after %d days: (%.0f, %.0f, %.0f)\n",
                i/24, moon.x, moon.y, moon.z);
        }
    }

    return 0;
}