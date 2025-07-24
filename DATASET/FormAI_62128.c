//FormAI DATASET v1.0 Category: Physics simulation ; Style: mind-bending
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    // Setting up the initial values
    double m = 1.0;          // Mass of the particle
    double x = 0.0;          // Initial position of the particle
    double v = 0.0;          // Initial velocity of the particle
    double k = 1.0;          // Spring constant of the system
    double t = 0.0;          // Initial time
    double dt = 0.01;        // Time step to use for the simulation

    // Creating a file to store the simulation data
    FILE *f = fopen("spring_simulation.txt", "w");

    // Running the simulation for 1000 time steps
    for(int i = 0; i < 1000; i++){

        // Calculating the force on the particle using Hooke's law
        double F = -k*x;

        // Updating the position of the particle using the Verlet integration algorithm
        double x_new = x + v*dt + 0.5*F*dt*dt/m;

        // Updating the velocity of the particle using the Verlet integration algorithm
        double F_new = -k*x_new;
        double v_new = v + 0.5*(F + F_new)*dt/m;

        // Updating the time and storing the simulation data in the file
        t += dt;
        fprintf(f, "%f %f %f\n", t, x, v);

        // Updating the position and velocity variables for the next time step
        x = x_new;
        v = v_new;
    }

    // Closing the file and exiting the program
    fclose(f);
    return 0;
}