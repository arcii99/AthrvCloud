//FormAI DATASET v1.0 Category: Arithmetic ; Style: energetic
#include <stdio.h>

int main() {
    /* This program is all about energy and calculations! */
    printf("Are you ready to calculate some kinetic energy?\n");
    
    double mass, velocity, energy;
    // We need the mass and velocity to calculate energy
    printf("Enter the mass in kilograms: ");
    scanf("%lf", &mass);
    printf("Enter the velocity in meters per second: ");
    scanf("%lf", &velocity);
    
    // The formula for kinetic energy is E = 0.5 * m * v^2
    energy = 0.5 * mass * velocity * velocity;
    printf("The kinetic energy of an object with mass %lf kg and velocity %lf m/s is %lf J.\n", mass, velocity, energy);
    
    // Let's calculate some potential energy as well
    double height, gravity, potential_energy;
    printf("Now let's find the potential energy of an object.\n");
    printf("Enter the height in meters: ");
    scanf("%lf", &height);
    printf("Enter the gravity in meters per second squared: ");
    scanf("%lf", &gravity);
    
    // The formula for potential energy is P = mgh
    potential_energy = mass * gravity * height;
    printf("The potential energy of an object with mass %lf kg, height %lf m, and gravity %lf m/s^2 is %lf J.\n", mass, height, gravity, potential_energy);
    
    // Now let's compare the two energies and see which one is bigger
    if (energy > potential_energy) {
        printf("The kinetic energy is greater than the potential energy!\n");
    } else if (energy < potential_energy) {
        printf("The potential energy is greater than the kinetic energy!\n");
    } else {
        printf("The kinetic and potential energies are equal!\n");
    }
    
    // Let's celebrate the power of energy!
    printf("Woo hoo, energy is awesome!\n");
    
    return 0;
}