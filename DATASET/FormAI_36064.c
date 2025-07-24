//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743 * pow(10, -11) // Gravitational Constant
#define TIME_STEP 3600 // 1 hour time step
#define NUM_PLANETS 3 // Number of Planets

struct Vector {
    double x, y, z;
};

struct Planet {
    char name[20];
    double mass;
    struct Vector pos;
    struct Vector vel;
    struct Vector acc;
};

struct Planet planets[NUM_PLANETS]; // Array of Planets

void calculateAcc(int i) {
    planets[i].acc.x = 0;
    planets[i].acc.y = 0;
    planets[i].acc.z = 0;
    for (int j = 0; j < NUM_PLANETS; j++) {
        if (i != j) {
            struct Vector r;
            r.x = planets[j].pos.x - planets[i].pos.x;
            r.y = planets[j].pos.y - planets[i].pos.y;
            r.z = planets[j].pos.z - planets[i].pos.z;
            double distance = sqrt(r.x * r.x + r.y * r.y + r.z * r.z);
            double force = G * planets[i].mass * planets[j].mass / (distance * distance);
            planets[i].acc.x += force * r.x / distance / planets[i].mass;
            planets[i].acc.y += force * r.y / distance / planets[i].mass;
            planets[i].acc.z += force * r.z / distance / planets[i].mass;
        }
    }
}

void calculateVel(int i) {
    planets[i].vel.x += planets[i].acc.x * TIME_STEP;
    planets[i].vel.y += planets[i].acc.y * TIME_STEP;
    planets[i].vel.z += planets[i].acc.z * TIME_STEP;
}

void calculatePos(int i) {
    planets[i].pos.x += planets[i].vel.x * TIME_STEP;
    planets[i].pos.y += planets[i].vel.y * TIME_STEP;
    planets[i].pos.z += planets[i].vel.z * TIME_STEP;
}

void printPlanets() {
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %s:\n", planets[i].name);
        printf("   Position: (%.2f, %.2f, %.2f)\n", planets[i].pos.x, planets[i].pos.y, planets[i].pos.z);
        printf("   Velocity: (%.2f, %.2f, %.2f)\n", planets[i].vel.x, planets[i].vel.y, planets[i].vel.z);
        printf("   Acceleration: (%.2f, %.2f, %.2f)\n", planets[i].acc.x, planets[i].acc.y, planets[i].acc.z);
    }
}

int main() {

    // Define Planets
    strcpy(planets[0].name, "Earth");
    planets[0].mass = 5.97 * pow(10, 24);
    planets[0].pos.x = 0;
    planets[0].pos.y = 0;
    planets[0].pos.z = 0;
    planets[0].vel.x = 0;
    planets[0].vel.y = 0;
    planets[0].vel.z = 0;

    strcpy(planets[1].name, "Mars");
    planets[1].mass = 6.39 * pow(10, 23);
    planets[1].pos.x = 1.5 * pow(10, 11);
    planets[1].pos.y = 0;
    planets[1].pos.z = 0;
    planets[1].vel.x = 0;
    planets[1].vel.y = 2.3 * pow(10, 4);
    planets[1].vel.z = 0;

    strcpy(planets[2].name, "Jupiter");
    planets[2].mass = 1.9 * pow(10, 27);
    planets[2].pos.x = 0;
    planets[2].pos.y = 7.78 * pow(10, 11);
    planets[2].pos.z = 0;
    planets[2].vel.x = 1.3 * pow(10, 4);
    planets[2].vel.y = 0;
    planets[2].vel.z = 0;

    double time = 0;

    while (time <= 3.15 * pow(10, 7)) { // 1 Earth year
        for (int i = 0; i < NUM_PLANETS; i++) {
            calculateAcc(i);
        }
        for (int i = 0; i < NUM_PLANETS; i++) {
            calculateVel(i);
        }
        for (int i = 0; i < NUM_PLANETS; i++) {
            calculatePos(i);
        }
        printPlanets();
        time += TIME_STEP;
    }

    return 0;
}