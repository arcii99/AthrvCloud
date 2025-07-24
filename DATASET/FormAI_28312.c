//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: portable
#include <stdio.h>
#include <math.h>
#define G 6.67408e-11 // Gravitational constant

// Structure for celestial bodies
struct Body {
    char name[20];
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};

// Function to calculate distance between two bodies
double distance(struct Body b1, struct Body b2) {
    return sqrt(pow(b1.x - b2.x, 2) + pow(b1.y - b2.y, 2) + pow(b1.z - b2.z, 2));
}

// Function to calculate the gravitational force between two bodies
double gravitationalForce(struct Body b1, struct Body b2) {
    double dist = distance(b1, b2);
    return G * b1.mass * b2.mass / pow(dist, 2);
}

// Function to calculate the gravitational acceleration experienced by a body
double gravitationalAcceleration(struct Body b, struct Body bodies[], int n) {
    double acceleration = 0.0;
    for (int i = 0; i < n; i++) {
        if (bodies[i].mass != b.mass) {
            acceleration += gravitationalForce(b, bodies[i]) / b.mass;
        }
    }
    return acceleration;
}

// Function to update the velocity and position of a body
void updatePosition(struct Body *b, struct Body bodies[], int n, double dt) {
    double ax = gravitationalAcceleration(*b, bodies, n) * cos(atan2(b->y, b->x));
    double ay = gravitationalAcceleration(*b, bodies, n) * sin(atan2(b->y, b->x));
    double az = 0.0; // Assume the z-axis is perpendicular to the plane of the solar system
    b->vx += ax * dt;
    b->vy += ay * dt;
    b->vz += az * dt;
    b->x += b->vx * dt;
    b->y += b->vy * dt;
    b->z += b->vz * dt;
}

int main() {
    // Initialize the celestial bodies
    struct Body sun = {"Sun", 1.989e30, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    struct Body earth = {"Earth", 5.97e24, 1.496e11, 0.0, 0.0, 0.0, 29783.0, 0.0};
    struct Body moon = {"Moon", 7.342e22, 1.496e11 + 3.844e8, 0.0, 0.0, 0.0, 29783.0 + 1023.0, 0.0};
    int n = 3;

    // Simulation parameters
    double dt = 86400.0; // 1 day
    int steps = 365; // number of steps per year

    // Start simulation
    printf("Starting simulation...\n");
    for (int i = 0; i <= steps; i++) {
        printf("Step %d:\n", i);
        printf("  %s: (%f, %f, %f) v=(%f, %f, %f)\n", sun.name, sun.x, sun.y, sun.z, sun.vx, sun.vy, sun.vz);
        printf("  %s: (%f, %f, %f) v=(%f, %f, %f)\n", earth.name, earth.x, earth.y, earth.z, earth.vx, earth.vy, earth.vz);
        printf("  %s: (%f, %f, %f) v=(%f, %f, %f)\n", moon.name, moon.x, moon.y, moon.z, moon.vx, moon.vy, moon.vz);
        updatePosition(&sun, &earth, n, dt);
        updatePosition(&earth, &sun, n, dt);
        updatePosition(&moon, &earth, n, dt);
    }

    return 0;
}