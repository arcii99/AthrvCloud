//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000 // number of particles
#define G 6.67408*pow(10,-11) // gravitational constant
#define DT 0.1 // time step

typedef struct { // particle struct
    double mass, x, y, z, vx, vy, vz;
} Particle;

Particle particles[N]; // array of particles

double distance(double x1, double y1, double z1, double x2, double y2, double z2) { // calculate distance between particles
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

void update_particle(int index) { // update particle position and velocity
    int i;
    double acceleration_x = 0, acceleration_y = 0, acceleration_z = 0;

    for (i = 0; i < N; i++) {
        if (i != index) {
            double dist = distance(particles[index].x, particles[index].y, particles[index].z, particles[i].x, particles[i].y, particles[i].z);
            double force = G * particles[index].mass * particles[i].mass / pow(dist, 2);
            acceleration_x += force * (particles[i].x - particles[index].x) / dist;
            acceleration_y += force * (particles[i].y - particles[index].y) / dist;
            acceleration_z += force * (particles[i].z - particles[index].z) / dist;
        }
    }

    particles[index].vx += acceleration_x * DT;
    particles[index].vy += acceleration_y * DT;
    particles[index].vz += acceleration_z * DT;
    particles[index].x += particles[index].vx * DT;
    particles[index].y += particles[index].vy * DT;
    particles[index].z += particles[index].vz * DT;
}

int main() {
    int i;

    // initialize particles with random position, velocity, and mass
    for (i = 0; i < N; i++) {
        particles[i].mass = rand() % 1000 + 1;
        particles[i].x = rand() % 100 + 1;
        particles[i].y = rand() % 100 + 1;
        particles[i].z = rand() % 100 + 1;
        particles[i].vx = rand() % 10 + 1;
        particles[i].vy = rand() % 10 + 1;
        particles[i].vz = rand() % 10 + 1;
    }

    // simulate gravity
    for (i = 0; i < 1000; i++) { // simulate for 1000 time steps
        int j;
        for (j = 0; j < N; j++) {
            update_particle(j);
        }

        // print positions of first 10 particles for every 10 time steps
        if (i % 10 == 0) {
            printf("Time step %d:\n", i);
            for (j = 0; j < 10; j++) {
                printf("Particle %d: (%.2f, %.2f, %.2f)\n", j, particles[j].x, particles[j].y, particles[j].z);
            }
        }
    }

    return 0;
}