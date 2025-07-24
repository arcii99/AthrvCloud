//FormAI DATASET v1.0 Category: Physics simulation ; Style: modular
#include <stdio.h>
#include <math.h> 

// Function to calculate the force between two charged particles
double calculateForce(double q1, double q2, double r) {
    double k = 9 * pow(10, 9); // Coulomb's constant
    double force = k * (q1 * q2 / pow(r, 2));
    return force;
}

// Function to calculate the electric field at a point due to a charged particle
double calculateElectricField(double q, double r) {
    double k = 9 * pow(10, 9);
    double field = k * (q / pow(r, 2));
    return field;
}

int main() {

    double q1 = 1.5 * pow(10, -6); // Charge on particle 1
    double q2 = -2.5 * pow(10, -6); // Charge on particle 2
    double r = 0.03; // Distance between the particles

    // Calculate the force between the particles
    double force = calculateForce(q1, q2, r);
    printf("The force between the particles is: %lf N\n", force);

    // Calculate the electric field at a point located at a distance of 10 cm from particle 1
    double r1 = 0.1; // Distance from particle 1
    double field = calculateElectricField(q1, r1);
    printf("The electric field at a point located at a distance of 10 cm from particle 1 is: %lf N/C\n", field);

    return 0;
}