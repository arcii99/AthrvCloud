//FormAI DATASET v1.0 Category: Physics simulation ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

#define G 6.67384e-11 // Gravitational constant

struct Vector {
    double x, y, z;
};

struct Body {
    struct Vector pos; // Position
    struct Vector vel; // Velocity
    struct Vector acc; // Acceleration
    double mass;
};

struct Body bodies[] = {
    {
        {0, 0, 0}, // Position
        {0, 0, 0}, // Velocity
        {0, 0, 0}, // Acceleration
        5.9736e24 // Mass of the Earth
    },
    {
        {384400000, 0, 0}, // Position (distance from Earth to Moon)
        {0, 1022, 0}, // Velocity
        {0, 0, 0}, // Acceleration
        7.342e22 // Mass of the Moon
    }
};

int numBodies = sizeof(bodies) / sizeof(struct Body);

void calculateAcc(int i, int j) {
    struct Vector dir = {bodies[j].pos.x - bodies[i].pos.x, bodies[j].pos.y - bodies[i].pos.y, bodies[j].pos.z - bodies[i].pos.z};
    double dist = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    double acc = G * bodies[j].mass / dist / dist; // Newton's law of gravitation
    bodies[i].acc.x += acc * dir.x / dist;
    bodies[i].acc.y += acc * dir.y / dist;
    bodies[i].acc.z += acc * dir.z / dist;
}

void updateVelocity(int i, double dt) {
    bodies[i].vel.x += bodies[i].acc.x * dt;
    bodies[i].vel.y += bodies[i].acc.y * dt;
    bodies[i].vel.z += bodies[i].acc.z * dt;
}

void updatePosition(int i, double dt) {
    bodies[i].pos.x += bodies[i].vel.x * dt;
    bodies[i].pos.y += bodies[i].vel.y * dt;
    bodies[i].pos.z += bodies[i].vel.z * dt;
}

void step(double dt) {
    // Calculate acceleration for each body
    for (int i = 0; i < numBodies; i++) {
        for (int j = 0; j < numBodies; j++) {
            if (i != j) {
                calculateAcc(i, j);
            }
        }
    }
    
    // Update velocity and position for each body
    for (int i = 0; i < numBodies; i++) {
        updateVelocity(i, dt);
        updatePosition(i, dt);
        
        // Reset acceleration for next step
        bodies[i].acc.x = 0;
        bodies[i].acc.y = 0;
        bodies[i].acc.z = 0;
    }
}

int main() {
    double dt = 86400; // Time step (in seconds)
    int numSteps = 30; // Number of steps
    for (int i = 0; i < numSteps; i++) {
        printf("Step %d\n", i + 1);
        for (int j = 0; j < numBodies; j++) {
            printf("Body %d Position: (%e, %e, %e)\n", j + 1, bodies[j].pos.x, bodies[j].pos.y, bodies[j].pos.z);
        }
        step(dt);
    }
    return 0;
}