//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITATIONAL_CONSTANT 6.674e-11
#define TIME_STEP 1000.0
#define NUMBER_OF_PLANETS 8

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass;
} planet;

planet planets[NUMBER_OF_PLANETS];

void initialize_planets() {
    srand(time(NULL));
    for(int i=0; i<NUMBER_OF_PLANETS; i++) {
        planets[i].mass = rand() % 50 + 1; // random mass between 1 and 50 kg
        planets[i].x = rand() % 100000000 + 1; // random x between 1 and 100 million km
        planets[i].y = rand() % 100000000 + 1; // random y between 1 and 100 million km
        planets[i].z = rand() % 100000000 + 1; // random z between 1 and 100 million km
        planets[i].vx = rand() % 10000 + 1; // random vx between 1 and 10,000 m/s
        planets[i].vy = rand() % 10000 + 1; // random vy between 1 and 10,000 m/s
        planets[i].vz = rand() % 10000 + 1; // random vz between 1 and 10,000 m/s
    }
}

void simulate() {
    double fx, fy, fz, distance, force;
    double ax, ay, az;
    for(int i=0; i<NUMBER_OF_PLANETS; i++) {
        fx = fy = fz = 0.0;
        for(int j=0; j<NUMBER_OF_PLANETS; j++) {
            if(i == j) continue;
            distance = sqrt(pow(planets[i].x - planets[j].x, 2) + pow(planets[i].y - planets[j].y, 2) + pow(planets[i].z - planets[j].z, 2));
            force = GRAVITATIONAL_CONSTANT * planets[i].mass * planets[j].mass / pow(distance, 2);
            fx += force * (planets[j].x - planets[i].x) / distance;
            fy += force * (planets[j].y - planets[i].y) / distance;
            fz += force * (planets[j].z - planets[i].z) / distance;
        }
        ax = fx / planets[i].mass;
        ay = fy / planets[i].mass;
        az = fz / planets[i].mass;
        planets[i].vx += ax * TIME_STEP;
        planets[i].vy += ay * TIME_STEP;
        planets[i].vz += az * TIME_STEP;
        planets[i].x += planets[i].vx * TIME_STEP;
        planets[i].y += planets[i].vy * TIME_STEP;
        planets[i].z += planets[i].vz * TIME_STEP;
    }
}

int main() {
    initialize_planets();
    for(int i=0; i<100; i++) {
        simulate();
        printf("t=%ds: ", i+1);
        for(int j=0; j<NUMBER_OF_PLANETS; j++) {
            printf("p%d(%.2f,%.2f,%.2f) ", j+1, planets[j].x, planets[j].y, planets[j].z);
        }
        printf("\n");
    }
    return 0;
}