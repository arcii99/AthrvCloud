//FormAI DATASET v1.0 Category: Physics simulation ; Style: scientific
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846 // define constant value for PI
#define G 6.6743E-11 // define constant value for gravitational constant

int main() {
    double mass1, mass2, distance, force;
    printf("Enter the mass of object 1:\n");
    scanf("%lf", &mass1);
    printf("Enter the mass of object 2:\n");
    scanf("%lf", &mass2);
    printf("Enter the distance between the objects:\n");
    scanf("%lf", &distance);
    
    force = G * ((mass1 * mass2) / pow(distance, 2)); // calculate force using the formula
    printf("The gravitational force between the two objects is %lf N\n", force);
    
    double acceleration1, acceleration2, velocity1, velocity2;
    printf("Enter the initial velocity of object 1:\n");
    scanf("%lf", &velocity1);
    printf("Enter the initial velocity of object 2:\n");
    scanf("%lf", &velocity2);
    
    acceleration1 = (force / mass1); // calculate acceleration of object 1
    acceleration2 = (force / mass2); // calculate acceleration of object 2
    
    double time = 0, timestep = 0.1; // set initial values for time and timestep
    while (time < 10) {
        velocity1 += acceleration1 * timestep; // calculate velocity of object 1
        velocity2 += acceleration2 * timestep; // calculate velocity of object 2
        distance += (velocity1 - velocity2) * timestep; // calculate separation distance between objects
        force = G * ((mass1 * mass2) / pow(distance, 2)); // recalculate force using new distance
        acceleration1 = (force / mass1); // recalculate acceleration of object 1
        acceleration2 = (force / mass2); // recalculate acceleration of object 2
        printf("Time: %.1lf sec, Distance: %.1lf m, Velocity: %.1lf m/s\n", time, distance, velocity1);
        time += timestep; // increment time by timestep
    }
    return 0;
}