//FormAI DATASET v1.0 Category: Physics simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100 //number of particles

//Particle data structure
typedef struct {
    double x, y; //position
    double vx, vy; //velocity
    double ax, ay; //acceleration
    double m; //mass
} Particle;

//Function to compute distance between two particles
double distance(Particle p1, Particle p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    //Seed random number generator
    srand(time(NULL));

    //Create particles
    Particle particles[N];
    for (int i = 0; i < N; i++) {
        particles[i].x = (double) rand() / RAND_MAX;
        particles[i].y = (double) rand() / RAND_MAX;
        particles[i].vx = 0;
        particles[i].vy = 0;
        particles[i].ax = 0;
        particles[i].ay = 0;
        particles[i].m = 1;
    }

    //Simulate particles
    double dt = 0.01; //time step
    double G = 6.674e-11; //gravitational constant
    for (double t = 0; t < 10; t += dt) {
        //Compute acceleration for each particle
        for (int i = 0; i < N; i++) {
            particles[i].ax = 0;
            particles[i].ay = 0;
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    double r = distance(particles[i], particles[j]);
                    double a = G * particles[j].m / pow(r, 2);
                    particles[i].ax += a * (particles[j].x - particles[i].x) / r;
                    particles[i].ay += a * (particles[j].y - particles[i].y) / r;
                }
            }
        }

        //Update velocity and position for each particle
        for (int i = 0; i < N; i++) {
            particles[i].vx += particles[i].ax * dt;
            particles[i].vy += particles[i].ay * dt;
            particles[i].x += particles[i].vx * dt;
            particles[i].y += particles[i].vy * dt;
        }

        //Print position of first particle
        printf("%f %f\n", particles[0].x, particles[0].y);
    }

    return 0;
}