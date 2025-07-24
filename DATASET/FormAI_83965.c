//FormAI DATASET v1.0 Category: Physics simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main() {
    int N = 1000; // Number of particles
    double L = 10.0; // Box size
    double dt = 0.01; // Time step
    double t = 0.0; // Time
    double E = 1000.0; // Total energy
    double m = 1.0; // Mass
    double k = 1.0; // Spring constant
    double gamma = 0.5; // Damping coefficient
    double sigma = 0.1; // Standard deviation of Gaussian noise
    double X[N], V[N], F[N], eta[N]; // Position, velocity, force, and noise arrays

    // Initialize position and velocity arrays
    for (int i = 0; i < N; i++) {
        X[i] = L * rand() / (double) RAND_MAX;
        V[i] = 0.0;
        F[i] = 0.0;
        eta[i] = sigma * sqrt(dt) * (2.0 * rand() / (double) RAND_MAX - 1.0);
    }
    
    // Run simulation
    for (int i = 0; i < 10000; i++) {
        // Calculate forces
        for (int j = 0; j < N; j++) {
            F[j] = -k * X[j];
        }

        // Add damping and noise
        for (int j = 0; j < N; j++) {
            V[j] = V[j] + (F[j] - gamma * V[j]) / m * dt + eta[j];
            X[j] = X[j] + V[j] * dt;
        }

        // Apply periodic boundary conditions
        for (int j = 0; j < N; j++) {
            if (X[j] < 0) {
                X[j] += L;
            } else if (X[j] >= L) {
                X[j] -= L;
            }
        }

        // Calculate energy
        E = 0.0;
        for (int j = 0; j < N; j++) {
            E += 0.5 * m * V[j] * V[j] + 0.5 * k * X[j] * X[j];
        }

        // Print output
        if (i % 100 == 0) {
            printf("Time: %.2f, Energy: %.2f\n", t, E);
        }
        t += dt;
    }

    return 0;
}