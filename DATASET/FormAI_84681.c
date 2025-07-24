//FormAI DATASET v1.0 Category: Physics simulation ; Style: imaginative
#include <stdio.h>
#include <math.h>

int main() {

    int time, i;

    float mass = 0.05; //kg
    float initial_velocity = 20; //m/s
    float gravitational_force = 9.81; //m/s^2
    float drag_coefficient = 0.15; //dimensionless
    float cross_sectional_area = 0.0001; //m^2

    float acceleration;
    float velocity;
    float displacement;
    float force;

    printf("Enter time interval (in seconds): ");
    scanf("%d", &time);

    velocity = initial_velocity;
    displacement = 0;

    for (i = 0; i <= time; i++) {

        force = (0.5 * drag_coefficient * cross_sectional_area * pow(velocity, 2));
        acceleration = (gravitational_force - force) / mass;
        displacement += velocity;
        velocity += acceleration;

        printf("t = %d, s = %f, v = %f, a = %f, f = %f\n", i, displacement, velocity, acceleration, force);
    }

    return 0;
}