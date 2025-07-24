//FormAI DATASET v1.0 Category: Physics simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the distance between two points in 3D space
float distance(float x1, float y1, float z1, float x2, float y2, float z2) {
    float dist = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2) + pow(z2-z1, 2));
    return dist;
}

// Function to calculate the force between two particles using the gravitational force equation
float force(float mass1, float mass2, float distance) {
    float G = 6.67408e-11; // Gravitational constant
    float f = (G * mass1 * mass2) / pow(distance, 2);
    return f;
}

int main() {
    srand((unsigned) time(NULL)); // Seed the random number generator
    int particles = 10;
    float positions[3][particles]; // Array to store the x, y, and z positions of each particle
    float masses[particles]; // Array to store the mass of each particle
    float velocities[3][particles]; // Array to store the x, y, and z velocities of each particle
    
    // Initialize positions, masses, and velocities of each particle randomly
    for (int i = 0; i < particles; i++) {
        positions[0][i] = (float) rand() / (float) RAND_MAX; // Random x position between 0 and 1
        positions[1][i] = (float) rand() / (float) RAND_MAX; // Random y position between 0 and 1
        positions[2][i] = (float) rand() / (float) RAND_MAX; // Random z position between 0 and 1
        masses[i] = (float) rand() / (float) RAND_MAX; // Random mass between 0 and 1
        velocities[0][i] = (float) rand() / (float) RAND_MAX; // Random x velocity between 0 and 1
        velocities[1][i] = (float) rand() / (float) RAND_MAX; // Random y velocity between 0 and 1
        velocities[2][i] = (float) rand() / (float) RAND_MAX; // Random z velocity between 0 and 1
    }
    
    // Iterate through each pair of particles and calculate the distance and force between them
    for (int i = 0; i < particles; i++) {
        for (int j = i+1; j < particles; j++) {
            float d = distance(positions[0][i], positions[1][i], positions[2][i], positions[0][j], positions[1][j], positions[2][j]);
            float f = force(masses[i], masses[j], d);
            
            // Calculate the components of the force along each axis
            float fx = f * (positions[0][j] - positions[0][i]) / d;
            float fy = f * (positions[1][j] - positions[1][i]) / d;
            float fz = f * (positions[2][j] - positions[2][i]) / d;
            
            // Add the force to the velocity of each particle
            velocities[0][i] += fx / masses[i];
            velocities[1][i] += fy / masses[i];
            velocities[2][i] += fz / masses[i];
            velocities[0][j] -= fx / masses[j];
            velocities[1][j] -= fy / masses[j];
            velocities[2][j] -= fz / masses[j];
        }
    }
    
    // Update the positions of each particle based on the new velocities
    for (int i = 0; i < particles; i++) {
        positions[0][i] += velocities[0][i];
        positions[1][i] += velocities[1][i];
        positions[2][i] += velocities[2][i];
    }
    
    // Print the positions, masses, and velocities of each particle
    for (int i = 0; i < particles; i++) {
        printf("Particle %d: Position (%f, %f, %f), Mass %f, Velocity (%f, %f, %f)\n", i+1, positions[0][i], positions[1][i], positions[2][i], masses[i], velocities[0][i], velocities[1][i], velocities[2][i]);
    }
    
    return 0;
}