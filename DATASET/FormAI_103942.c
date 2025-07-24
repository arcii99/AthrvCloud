//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 9 // Number of celestial bodies in simulation, including the sun
#define G_CONSTANT 6.674 * pow(10, -11) // Gravitational constant

struct Vector3d {
    double x, y, z;
};

struct CelestialBody {
    char name[20];
    double mass;
    struct Vector3d position;
    struct Vector3d velocity;
};

void updateAcceleration(struct CelestialBody *bodies) {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        double x_acc = 0, y_acc = 0, z_acc = 0;

        for (j = 0; j < SIZE; j++) {
            if (i != j) {
                double distance = sqrt(pow((bodies[j].position.x - bodies[i].position.x), 2) + 
                                       pow((bodies[j].position.y - bodies[i].position.y), 2) + 
                                       pow((bodies[j].position.z - bodies[i].position.z), 2));
                double force = G_CONSTANT * bodies[i].mass * bodies[j].mass / pow(distance, 2);

                x_acc += force * (bodies[j].position.x - bodies[i].position.x) / distance;
                y_acc += force * (bodies[j].position.y - bodies[i].position.y) / distance;
                z_acc += force * (bodies[j].position.z - bodies[i].position.z) / distance;
            }
        }

        bodies[i].velocity.x += x_acc;
        bodies[i].velocity.y += y_acc;
        bodies[i].velocity.z += z_acc;
    }
}

void updatePosition(struct CelestialBody *bodies, double time_step) {
    int i;

    for (i = 0; i < SIZE; i++) {
        bodies[i].position.x += bodies[i].velocity.x * time_step;
        bodies[i].position.y += bodies[i].velocity.y * time_step;
        bodies[i].position.z += bodies[i].velocity.z * time_step;
    }
}

void printState(struct CelestialBody *bodies) {
    int i;

    for (i = 0; i < SIZE; i++) {
        printf("%s position: (%.2e, %.2e, %.2e), velocity: (%.2e, %.2e, %.2e)\n", bodies[i].name,
                bodies[i].position.x, bodies[i].position.y, bodies[i].position.z, bodies[i].velocity.x,
                bodies[i].velocity.y, bodies[i].velocity.z);
    }
}

int main() {
    struct CelestialBody bodies[SIZE] = {
        {"Sun", 2 * pow(10, 30), {0, 0, 0}, {0, 0, 0}},
        {"Mercury", 3.3 * pow(10, 23), {-5.7 * pow(10, 10), 0, 0}, {0, 4.8 * pow(10, 4), 0}},
        {"Venus", 4.9 * pow(10, 24), {0, 1.1 * pow(10, 11), 0}, {-3.5 * pow(10, 4), 0, 0}},
        {"Earth", 6.0 * pow(10, 24), {1.5 * pow(10, 11), 0, 0}, {0, 3.0 * pow(10, 4), 0}},
        {"Mars", 6.4 * pow(10, 23), {0, -2.3 * pow(10, 11), 0}, {2.4 * pow(10, 4), 0, 0}},
        {"Jupiter", 1.9 * pow(10, 27), {0, 7.7 * pow(10, 11), 0}, {-1.3 * pow(10, 4), 0, 0}},
        {"Saturn", 5.7 * pow(10, 26), {0, -1.4 * pow(10, 12), 0}, {9.7 * pow(10, 3), 0, 0}},
        {"Uranus", 8.7 * pow(10, 25), {2.9 * pow(10, 12), 0, 0}, {0, 6.8 * pow(10, 3), 0}},
        {"Neptune", 1.0 * pow(10, 26), {0, 4.5 * pow(10, 12), 0}, {-5.4 * pow(10, 3), 0, 0}}
    };

    int i;
    double time_step = 86400; // 1 day in seconds

    for (i = 0; i < 365; i++) {
        updateAcceleration(bodies);
        updatePosition(bodies, time_step);
        printState(bodies);
        printf("\n");
    }

    return 0;
}