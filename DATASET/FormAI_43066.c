//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main() {

    double G = 6.674e-11; // gravitational constant
    double m1, m2, r, F; // variables to store the masses, distance, and force

    // prompt the user for input
    printf("Enter the mass of the first planet (in kg): ");
    scanf("%lf", &m1);

    printf("Enter the mass of the second planet (in kg): ");
    scanf("%lf", &m2);

    printf("Enter the distance between the two planets (in meters): ");
    scanf("%lf", &r);

    // calculate the force of gravity between the two planets using the formula F = G * m1 * m2 / r^2
    F = G * m1 * m2 / pow(r, 2);

    // output the results to the user
    printf("The gravitational force between the two planets is %.2lf Newtons.\n", F);

    return 0;
}