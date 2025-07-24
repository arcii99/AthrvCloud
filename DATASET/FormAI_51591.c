//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11  // gravitational constant
#define DT 3600      // time step in seconds

// Define the struct for a planet
typedef struct {
    double mass;  // mass in kg
    double x;     // x-coordinate in meters
    double y;     // y-coordinate in meters
    double vx;    // x-velocity in m/s
    double vy;    // y-velocity in m/s
} Planet;

// Function to calculate the distance between two planets
double distance(Planet p1, Planet p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to calculate the gravitational force between two planets
double force(Planet p1, Planet p2) {
    return (G * p1.mass * p2.mass) / pow(distance(p1, p2), 2);
}

// Function to update the velocity and position of a planet
void update(Planet *p, Planet *other, int n) {
    double fx = 0, fy = 0;
    for (int i = 0; i < n; i++) {
        if (p != &other[i]) {
            double f = force(*p, other[i]);
            double theta = atan2(other[i].y - p->y, other[i].x - p->x);
            fx += f * cos(theta);
            fy += f * sin(theta);
        }
    }
    p->vx += fx / p->mass * DT;
    p->vy += fy / p->mass * DT;
    p->x += p->vx * DT;
    p->y += p->vy * DT;
}

int main() {
    // create two planets
    Planet earth = {5.97e24, 0, 6.371e6, 0, 0};
    Planet moon = {7.34e22, 3.844e8, 0, 0, 1022};

    // simulate their motion for one day
    for (int i = 0; i < 86400; i += DT) {
        update(&earth, &moon, 1);
        update(&moon, &earth, 1);
    }

    // print the final positions of the planets
    printf("Earth: (%.2f, %.2f)\n", earth.x, earth.y);
    printf("Moon: (%.2f, %.2f)\n", moon.x, moon.y);

    return 0;
}