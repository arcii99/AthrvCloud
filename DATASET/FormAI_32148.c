//FormAI DATASET v1.0 Category: Physics simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 1000 // Number of particles
#define L 10.0 // Length of the simulation box
#define T 1.0 // Temperature

double x[N], y[N], vx[N], vy[N], fx[N], fy[N]; // Position, velocity and force arrays
double dt = 0.01; // Time step
double m = 1.0; // Particle mass
double kb = 1.0; // Boltzmann constant

void initialize() {
    // Initialize position and velocity arrays randomly
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        x[i] = L * (double)rand() / RAND_MAX;
        y[i] = L * (double)rand() / RAND_MAX;
        vx[i] = rand() % 2 == 0 ? -sqrt(kb * T / m) : sqrt(kb * T / m);
        vy[i] = rand() % 2 == 0 ? -sqrt(kb * T / m) : sqrt(kb * T / m);
    }
}

void compute_force() {
    // Compute pairwise forces between particles using Lennard-Jones potential
    for (int i = 0; i < N; i++) {
        fx[i] = 0.0;
        fy[i] = 0.0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                double dx = x[i] - x[j];
                double dy = y[i] - y[j];
                double r2 = dx*dx + dy*dy;
                double r6 = r2*r2*r2;
                double coef = 24.0 * (2.0 / r6 - 1.0) / r6;
                fx[i] += coef * dx;
                fy[i] += coef * dy;
            }
        }
    }
}

void update_positions() {
    // Update particle positions using Verlet algorithm
    for (int i = 0; i < N; i++) {
        x[i] += vx[i] * dt + 0.5 * fx[i] * dt*dt / m;
        y[i] += vy[i] * dt + 0.5 * fy[i] * dt*dt / m;
        if (x[i] > L) x[i] -= L;
        if (x[i] < 0) x[i] += L;
        if (y[i] > L) y[i] -= L;
        if (y[i] < 0) y[i] += L;
    }
}

void update_velocities() {
    // Update particle velocities using Verlet algorithm
    for (int i = 0; i < N; i++) {
        vx[i] += 0.5 * dt * (fx[i] + fx[i+N]) / m;
        vy[i] += 0.5 * dt * (fy[i] + fy[i+N]) / m;
    }
}

void compute_momentum(double *px, double *py) {
    // Compute total momentum of the system
    *px = 0.0;
    *py = 0.0;
    for (int i = 0; i < N; i++) {
        *px += vx[i];
        *py += vy[i];
    }
}

int main() {
    initialize();

    double t = 0.0, px, py;
    while (t < 100.0) {
        compute_force();
        update_positions();
        compute_force();
        update_velocities();
        compute_momentum(&px, &py);
        printf("%.5f %.5f\n", t, sqrt(px*px + py*py));
        t += dt;
    }

    return 0;
}