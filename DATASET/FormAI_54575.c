//FormAI DATASET v1.0 Category: Physics simulation ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant

// Function to compute the force between two masses
double computeForce(double mass1, double mass2, double distance) {
    return G * mass1 * mass2 / pow(distance, 2);
}

int main() {
    double mass1, mass2, distance, force;
    
    // Input mass1, mass2, and distance from user
    printf("Enter mass of object 1 (kg): ");
    scanf("%lf", &mass1);
    printf("Enter mass of object 2 (kg): ");
    scanf("%lf", &mass2);
    printf("Enter distance between objects (m): ");
    scanf("%lf", &distance);
    
    // Compute the force between the two masses
    force = computeForce(mass1, mass2, distance);
    
    // Print the force
    printf("The force between the two objects is %.2e N\n", force);
    
    return 0;
}