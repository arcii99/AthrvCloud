//FormAI DATASET v1.0 Category: Physics simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TEMPERATURE 273.15     // Standard temperature in K
#define BOLTZMANN_CONSTANT 1.38 // Boltzmann constant in 10^-23 J/K

int main()
{
    srand(time(NULL)); // Seed random number generator with current time
    
    int n = 1000;            // Number of particles
    double box_size = 5.0;   // Size of the simulation box in meters
    double particle_mass = 1.0;   // Mass of each particle in kg

    // Calculate the dimensions of the simulation box in meters
    double box_width = box_size;
    double box_length = box_size;
    double box_height = box_size;
    
    // Calculate the volume of the simulation box in cubic meters
    double box_volume = box_width * box_length * box_height;
    
    // Calculate the density of the gas in kg/m^3 using the ideal gas law
    double pressure = 1e5; // Pressure in Pascal (1 atm)
    double gas_constant = 8.31; // Ideal gas constant in J/(mol*K)
    double molar_mass = 28.97; // Molar mass of dry air in g/mol
    double gas_density = (pressure * molar_mass) / (gas_constant * TEMPERATURE);
    
    // Calculate the initial velocity of the particles in m/s using the Maxwell-Boltzmann distribution
    double velocity_average = 0.0;
    double velocity_magnitude = 0.0;
    double velocity_variance = 0.0;
    double random_number = 0.0;
    
    for (int i = 0; i < n; i++)
    {
        // Generate a random number between 0 and 1
        random_number = (double)rand() / RAND_MAX;
        
        // Calculate the velocity magnitude according to the Maxwell-Boltzmann distribution
        velocity_magnitude = sqrt((-2.0 * log(random_number)) * BOLTZMANN_CONSTANT * TEMPERATURE / particle_mass);
        velocity_average += velocity_magnitude;
        velocity_variance += velocity_magnitude * velocity_magnitude;
        
        // Generate the x, y, and z components of the velocity vector
        random_number = (double)rand() / RAND_MAX;
        double vx = velocity_magnitude * sqrt(-log(random_number)) * (rand() % 2 == 0 ? 1.0 : -1.0);
        
        random_number = (double)rand() / RAND_MAX;
        double vy = velocity_magnitude * sqrt(-log(random_number)) * (rand() % 2 == 0 ? 1.0 : -1.0);
        
        random_number = (double)rand() / RAND_MAX;
        double vz = velocity_magnitude * sqrt(-log(random_number)) * (rand() % 2 == 0 ? 1.0 : -1.0);
        
        // Output the initial velocity of the particle
        printf("Particle %d Initial Velocity: (%g, %g, %g) m/s\n", i, vx, vy, vz);
    }
    
    // Calculate the average velocity of the particles
    velocity_average /= n;
    
    // Calculate the mean square velocity of the particles
    velocity_variance /= n;
    velocity_variance -= velocity_average * velocity_average;
    
    // Output the results
    printf("\nSimulation Results\n\n");
    printf("Box Dimensions: %g x %g x %g m\n", box_width, box_length, box_height);
    printf("Number of Particles: %d\n", n);
    printf("Particle Mass: %g kg\n", particle_mass);
    printf("Gas Density: %g kg/m^3\n", gas_density);
    printf("Average Velocity: %g m/s\n", velocity_average);
    printf("Mean Square Velocity: %g m^2/s^2\n", velocity_variance);
    
    return 0;
}