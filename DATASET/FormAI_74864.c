//FormAI DATASET v1.0 Category: Physics simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Set up initial conditions
    double mass1 = 1.0;
    double mass2 = 2.0;
    double radius1 = 0.5;
    double radius2 = 1.0;
    double velocity1 = 0.0;
    double velocity2 = 0.0;
    double position1 = -1.0;
    double position2 = 1.0;
    double time = 0.0;
    double G = 6.6743e-11;

    // Set up simulation parameters
    double dt = 0.001;
    int nsteps = 10000;

    // Open output file
    FILE *outfile;
    outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        printf("Error opening output file.");
        exit(1);
    }

    // Simulate motion
    for (int i = 0; i < nsteps; i++) {
        // Calculate forces
        double separation = position2 - position1;
        double force = G * mass1 * mass2 / (separation * separation);
        double acceleration1 = force / mass1;
        double acceleration2 = -force / mass2;

        // Update velocities
        velocity1 += acceleration1 * dt;
        velocity2 += acceleration2 * dt;

        // Update positions
        position1 += velocity1 * dt;
        position2 += velocity2 * dt;

        // Write output to file
        fprintf(outfile, "%.6f,%.6f,%.6f\n", time, position1, position2);

        // Increment time
        time += dt;
    }

    // Close output file
    fclose(outfile);

    // Exit program
    return 0;
}