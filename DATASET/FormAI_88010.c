//FormAI DATASET v1.0 Category: Physics simulation ; Style: unmistakable
#include <stdio.h>
#include <math.h>

int main()
{
    // Define initial conditions
    double t = 0; // Time
    double dt = 0.01; // Time step
    double x = 0; // Position of particle along x-axis
    double y = 0; // Position of particle along y-axis
    double vx = 10; // Velocity of particle along x-axis
    double vy = 20; // Velocity of particle along y-axis
    double ax = 0; // Acceleration of particle along x-axis
    double ay = 0; // Acceleration of particle along y-axis
    double m = 1; // Mass of particle
    double k = 10; // Spring constant
    double l0 = 5; // Equilibrium length of spring
    double l; // Length of spring
    
    // Set up file to store data
    FILE *outfile;
    outfile = fopen("spring_motion.txt", "w");
    fprintf(outfile, "t\tx\ty\n");
    
    // Simulate motion of particle under the influence of a spring force
    while (t <= 10)
    {
        // Calculate length of spring
        l = sqrt(pow(x, 2) + pow(y, 2)) - l0;
        
        // Calculate acceleration of particle
        ax = -k * l * x / sqrt(pow(x, 2) + pow(y, 2)) / m;
        ay = -k * l * y / sqrt(pow(x, 2) + pow(y, 2)) / m;
        
        // Update velocity of particle
        vx += ax * dt;
        vy += ay * dt;
        
        // Update position of particle
        x += vx * dt;
        y += vy * dt;
        
        // Write coordinates to file
        fprintf(outfile, "%g\t%g\t%g\n", t, x, y);
        
        // Update time
        t += dt;
    }

    // Close file
    fclose(outfile);
    
    // Inform user that simulation is complete
    printf("Simulation complete.\n");
    
    return 0;
}