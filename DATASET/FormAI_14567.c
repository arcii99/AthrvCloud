//FormAI DATASET v1.0 Category: Physics simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double mass1, mass2, position1, position2, velocity1, velocity2, acceleration1, acceleration2, time = 0.0, dt = 0.1;
    double spring_constant = 10.0, damping_constant = 0.5;
    double force1, force2, displacement, previous_displacement;
    int steps = 1000;

    printf("Enter mass of first object: ");
    scanf("%lf", &mass1);
    printf("Enter initial position of first object: ");
    scanf("%lf", &position1);
    printf("Enter initial velocity of first object: ");
    scanf("%lf", &velocity1);

    printf("Enter mass of second object: ");
    scanf("%lf", &mass2);
    printf("Enter initial position of second object: ");
    scanf("%lf", &position2);
    printf("Enter initial velocity of second object: ");
    scanf("%lf", &velocity2);

    displacement = position1 - position2;
    previous_displacement = displacement;

    printf("Time  Position1  Position2  \n");

    for(int i = 0; i < steps; i++) {
        force1 = -spring_constant * displacement - damping_constant * (previous_displacement - displacement) / dt;
        force2 = -force1;
        acceleration1 = force1 / mass1;
        acceleration2 = force2 / mass2;
        position1 += velocity1 * dt + 0.5 * acceleration1 * dt * dt;
        position2 += velocity2 * dt + 0.5 * acceleration2 * dt * dt;
        velocity1 += acceleration1 * dt;
        velocity2 += acceleration2 * dt;
        displacement = position1 - position2;
        previous_displacement = displacement;

        printf("%f  %f  %f\n", time, position1, position2);
        time += dt;
    }

    return 0;
}