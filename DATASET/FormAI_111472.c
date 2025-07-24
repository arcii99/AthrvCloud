//FormAI DATASET v1.0 Category: Physics simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the gravitational force between two objects
double gravitational_force(double mass1, double mass2, double distance) {
   double gravitational_constant = 6.6743e-11;
   return gravitational_constant * mass1 * mass2 / pow(distance, 2);
}

// Function to calculate the acceleration of an object due to the gravitational force
double acceleration(double force, double mass) {
   return force / mass;
}

int main() {
   double mass1, mass2, distance;
   printf("Enter the mass of the first object (in kg): ");
   scanf("%lf", &mass1);
   printf("Enter the mass of the second object (in kg): ");
   scanf("%lf", &mass2);
   printf("Enter the distance between the two objects (in meters): ");
   scanf("%lf", &distance);
   
   // Calculate the gravitational force and the acceleration of each object
   double force = gravitational_force(mass1, mass2, distance);
   double acceleration1 = acceleration(force, mass1);
   double acceleration2 = acceleration(force, mass2);
   
    // Print the results
   printf("The gravitational force between the two objects is %.2f N\n", force);
   printf("The acceleration of the first object is %.2f m/s^2\n", acceleration1);
   printf("The acceleration of the second object is %.2f m/s^2\n", acceleration2);
   return 0;
}